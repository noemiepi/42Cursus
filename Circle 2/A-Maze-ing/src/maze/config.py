from typing_extensions import Annotated, Self
from pydantic import BaseModel, model_validator, field_validator, Field, \
                     ValidationError, PrivateAttr
import re
from typing import Optional, Any


# implementation de la config suivant config.txt
class MyBaseConfig(BaseModel):
    WIDTH: int
    HEIGHT: int
    ENTRY: Annotated[list[int], Field(min_length=2, max_length=2)]
    EXIT: Annotated[list[int], Field(min_length=2, max_length=2)]
    OUTPUT_FILE: Annotated[str, Field(min_length=7, max_length=25)]
    PERFECT: Annotated[bool, Field(True)]
    SEED: Annotated[Optional[int], Field(None)]
    _warning: list[str] = PrivateAttr(default_factory=list)

    @field_validator('OUTPUT_FILE', mode='before')
    @classmethod
    def output_file_is_available(cls, value: str) -> str:
        if value is None or not isinstance(value, str) and not value.strip():
            return "output.txt"
        value = value.strip()
        if not value.endswith(".txt"):
            value += ".txt"
        return value

    @model_validator(mode='after')
    def limits_are_allowed(self) -> Self:
        if self.WIDTH <= 2:
            widther = self.WIDTH
            self.WIDTH = 3
            self._warning.append(f"WIDTH min = 3, \033[1;5;31m{widther}"
                                 f"\033[0m has be converted in 3")
        if self.WIDTH > 52:
            widther = self.WIDTH
            self.WIDTH = 52
            self._warning.append(f"WIDTH max = 52, \033[1;5;31m{widther}"
                                 f"\033[0m has be converted in 52")
        if self.HEIGHT <= 2:
            higher = self.HEIGHT
            self.HEIGHT = 3
            self._warning.append(f"HEIGHT min = 3, \033[1;5;31m{higher}"
                                 f"\033[0m has be converted in 3")
        if self.HEIGHT > 27:
            higher = self.HEIGHT
            self.HEIGHT = 27
            self._warning.append(f"HEIGHT max = 27, \033[1;5;31m{higher}"
                                 f"\033[0m has be converted in 27")
        width = self.WIDTH - 1
        height = self.HEIGHT - 1

        ex, ey = self.ENTRY
        new_ex = max(0, min(int(ex), width))
        new_ey = max(0, min(int(ey), height))
        self.ENTRY = [new_ex, new_ey]
        if [new_ex, new_ey] != [ex, ey]:
            self._warning.append(f"\033[1;5;31mENTRY ({ex},{ey})\033[0m is not"
                                 f" valid, has be converted in ({new_ex},"
                                 f"{new_ey})")

        sx, sy = self.EXIT
        new_sx = max(0, min(int(sx), width))
        new_sy = max(0, min(int(sy), height))
        self.EXIT = [new_sx, new_sy]
        if [new_sx, new_sy] != [sx, sy]:
            self._warning.append(f"\033[1;5;31mEXIT ({sx},{sy})\033[0m is not "
                                 f"valid, has be converted in ({new_sx},"
                                 f"{new_sy})")

        if self.ENTRY == self.EXIT:
            self.ENTRY = [0, 0]
            self.EXIT = [(width), (height)]
            self._warning.append(f"\033[1;5;31mENTRY and EXIT\033[0m must be "
                                 f"different, ENTRY is (0,0) EXIT is ({width},"
                                 f" {height})")

        if self.WIDTH >= 9 and self.HEIGHT >= 9:
            start_x = (self.WIDTH - 7) // 2
            start_y = ((self.HEIGHT - 6) // 2) + 1
            ex, ey = self.ENTRY
            sx, sy = self.EXIT
            y_list = []
            x_list = []
            for y in range(7):
                for x in range(7):
                    target_y = start_y + y
                    target_x = start_x + x
                    if 0 <= target_x < self.WIDTH and\
                       0 <= target_y < self.HEIGHT:
                        if (target_y == start_y and target_x in
                                (start_x + nb for nb in [0, 4, 5, 6])):
                            y_list.append(target_y)
                            x_list.append(target_x)
                        elif (target_y == start_y + 1 and target_x in
                                (start_x + nb for nb in [0, 2, 6])):
                            y_list.append(target_y)
                            x_list.append(target_x)
                        elif (target_y == start_y + 2 and target_x in
                                (start_x + nb for nb in [0, 1, 2, 4, 5, 6])):
                            y_list.append(target_y)
                            x_list.append(target_x)
                        elif (target_y == start_y + 3 and target_x in
                                (start_x + nb for nb in [2, 4])):
                            y_list.append(target_y)
                            x_list.append(target_x)
                        elif (target_y == start_y + 4 and target_x in
                                (start_x + nb for nb in [2, 4, 5, 6])):
                            y_list.append(target_y)
                            x_list.append(target_x)
            if ex in x_list and ey in y_list:
                self.ENTRY = [0, 0]
                self._warning.append("\033[1;5;31mENTRY\033[0m can't be on 42"
                                     "'s cellule, ENTRY is (0,0)")
            if sx in x_list and sy in y_list:
                self.EXIT = [width, height]
                self._warning.append(f"\033[1;5;31mEXIT\033[0m can't be on 42"
                                     f"'s cellule, EXIT is ({width},{height})")
        return self


def config_method() -> tuple[Any, Any]:
    try:
        with open("config.txt", "r") as c:
            base_config = ["WIDTH", "HEIGHT", "ENTRY", "EXIT",
                           "PERFECT", "OUTPUT_FILE"]
            config: dict[str, Any] = {}
            error_conf: dict[str, Any] = {}
            file = c.read()
            error = False
            for line in file.split("\n"):
                if not line.startswith("#") and "=" in line:
                    key, value = line.split("=", 1)
                    key = key.strip()
                    value = value.strip()
                    if "=" in value:
                        value = value.rsplit("=", 1)[1]
                        error = True
                    if key in ["ENTRY", "EXIT"]:
                        value_lst = []
                        values = re.split(r"[,;.]+", value)
                        for v in values:
                            value_lst.append(v)
                        config[key] = value_lst
                    elif key in base_config or key == "SEED":
                        config[key] = value
                    else:
                        error_conf[key] = value
            try:
                all(k in base_config for k in config.keys())
            except KeyError as e:
                print(f"ERROR: {e}")
    except FileNotFoundError:
        return (None, None)
    try:
        my_scope = MyBaseConfig(**config)
        if error_conf:
            my_scope._warning.append("\033[1;5;31m'config.txt'\033[0m "
                                     "contains too many arguments KEY=VALUE")
        if config["OUTPUT_FILE"] != my_scope.OUTPUT_FILE:
            my_scope._warning.append(f"\033[1;5;31m{config['OUTPUT_FILE']}"
                                     f"\033[0m has been upgrade in "
                                     f"{my_scope.OUTPUT_FILE}")
        if error:
            my_scope._warning.append("\033[1;5;31m'config.txt'\033[0m "
                                     "contains too many '=' characters")
        return (my_scope, None)
    except ValidationError as e:
        return (None, e)
