from maze.config import MyBaseConfig
from typing import Optional, Any
from abc import ABC, abstractmethod


class Cellule():
    def __init__(self) -> None:
        self.north = True
        self.south = True
        self.east = True
        self.west = True
        self.visited = False
        self.ft = False
        self.current = False
        self.resolved = False


class MyLaby(ABC):
    #  initialisation des donnees selon le fichier config.txt
    def __init__(self, config: MyBaseConfig) -> None:
        self.width = config.WIDTH
        self.height = config.HEIGHT
        self.entry_x, self.entry_y = config.ENTRY
        self.exit_x, self.exit_y = config.EXIT
        self.output_file = config.OUTPUT_FILE
        self.perfect = config.PERFECT
        self.seed = config.SEED
        self.grid = [[Cellule() for x in range(self.width)]
                     for y in range(self.height)]

# *****************************************************************************
# *****************************************************************************
    # recherche des voisins disponibles
    def neighbor(self, current_x: int, current_y: int, func: str
                 ) -> list[tuple[str, int, int]]:
        neighb = [
            ("north", current_x, current_y-1),
            ("south", current_x, current_y+1),
            ("east", current_x+1, current_y),
            ("west", current_x-1, current_y)
        ]
        neighbors = []
        # retourne les voisins non visites
        if func == "create":
            for dir, nx, ny in neighb:
                if 0 <= nx < self.width and 0 <= ny < self.height and\
                   not self.grid[ny][nx].ft:
                    self.grid[ny][nx].current = False
                    if not self.grid[ny][nx].visited:
                        neighbors.append((dir, nx, ny))
        # retourne les voisins visites
        elif func == "hunt":
            for dir, nx, ny in neighb:
                if 0 <= nx < self.width and 0 <= ny < self.height:
                    self.grid[ny][nx].current = False
                    if self.grid[ny][nx].visited:
                        neighbors.append((dir, nx, ny))
        # retourne des voisins
        elif func == "imperfect":
            for dir, nx, ny in neighb:
                value = 0
                if 0 <= nx < self.width and 0 <= ny < self.height:
                    cellule = self.grid[ny][nx]
                    cellule.current = False
                    if cellule.north:
                        value += 0b0001
                    if cellule.east:
                        value += 0b0010
                    if cellule.south:
                        value += 0b0100
                    if cellule.west:
                        value += 0b1000
                if value in [0b1011, 0b0111, 0b1101, 0b1110]:
                    neighbors.append((dir, nx, ny))
        # retourne les voisins non-accessibles
        elif func == "resolve_lab":
            for dir, nx, ny in neighb:
                if 0 <= nx < self.width and 0 <= ny < self.height:
                    if (dir == "north" and not
                            self.grid[current_y][current_x].north):
                        neighbors.append((dir, nx, ny))
                    elif (dir == "south" and not
                            self.grid[current_y][current_x].south):
                        neighbors.append((dir, nx, ny))
                    elif (dir == "east" and not
                            self.grid[current_y][current_x].east):
                        neighbors.append((dir, nx, ny))
                    elif (dir == "west" and not
                            self.grid[current_y][current_x].west):
                        neighbors.append((dir, nx, ny))
        return neighbors

# *****************************************************************************
# *****************************************************************************
    # ouverture des murs concordants current_case = voisin
    def open_wall(self, x: int, y: int, direction: str, nx: int,
                  ny: int) -> None:
        opposed = {"north": "south", "south": "north", "east": "west",
                   "west": "east"}
        if not self.grid[y][x].ft and not self.grid[ny][nx].ft:
            setattr(self.grid[y][x], direction, False)
            setattr(self.grid[ny][nx], opposed[direction], False)

# *****************************************************************************
# *****************************************************************************
    # marquage des cases pour ecrire 42
    def case_ft(self) -> None:
        if self.width >= 9 and self.height >= 9:
            start_x = (self.width - 7) // 2
            start_y = ((self.height - 6) // 2) + 1

            for y in range(7):
                for x in range(7):
                    target_y = start_y + y
                    target_x = start_x + x
                    if 0 <= target_x < self.width and\
                       0 <= target_y < self.height:
                        if (target_y == start_y and target_x in
                                (start_x + nb for nb in [0, 4, 5, 6])):
                            self.grid[target_y][target_x].ft = True
                        elif (target_y == start_y + 1 and target_x in
                                (start_x + nb for nb in [0, 2, 6])):
                            self.grid[target_y][target_x].ft = True
                        elif (target_y == start_y + 2 and target_x in
                                (start_x + nb for nb in [0, 1, 2, 4, 5, 6])):
                            self.grid[target_y][target_x].ft = True
                        elif (target_y == start_y + 3 and target_x in
                                (start_x + nb for nb in [2, 4])):
                            self.grid[target_y][target_x].ft = True
                        elif (target_y == start_y + 4 and target_x in
                                (start_x + nb for nb in [2, 4, 5, 6])):
                            self.grid[target_y][target_x].ft = True

# *****************************************************************************
# *****************************************************************************
    # fichier de sortie du labyrinthe en hexadecimale
    def output_maze(self, path: Optional[list[tuple[Any, Any]]] = None
                    ) -> None:
        with open(self.output_file, "w") as f:
            for y in range(self.height):
                for x in range(self.width):
                    cellule = self.grid[y][x]
                    value = 0
                    if cellule.north:
                        value += 0b0001
                    if cellule.east:
                        value += 0b0010
                    if cellule.south:
                        value += 0b0100
                    if cellule.west:
                        value += 0b1000
                    f.write(hex(value)[2::])
                f.write("\n")
            f.write(f"\n{self.entry_x},{self.entry_y}")
            f.write(f"\n{self.exit_x},{self.exit_y}\n")
            if path is not None:
                directions = []
                cx, cy = self.entry_x, self.entry_y
                dir = ""
                for x, y in path:
                    if x == cx - 1:
                        dir = "W"
                    elif x == cx + 1:
                        dir = "E"
                    if y == cy - 1:
                        dir = "N"
                    elif y == cy + 1:
                        dir = "S"
                    cx, cy = x, y
                    if dir in ["N", "S", "E", "W"]:
                        directions.append(dir)
                for d in directions:
                    f.write(d)

    # algorithme de creation du labyrinthe
    @abstractmethod
    def maze_creator(self) -> None:
        pass
