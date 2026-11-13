from typing import Any, List

import arcade
from arcade.types import PathOrTexture

ANIM_SPEED = 5


class Character(arcade.Sprite):
    def __init__(self, path: PathOrTexture, scale: float,
                 character_animation: List[arcade.Texture]) -> None:
        super().__init__(path, scale)

        self.curr_texture = 0
        self.animation = character_animation
        self.timer = 0.0

    def update_animation(self, delta_time: float = 1 / 60,
                         *args: Any, **kwargs: Any) -> None:

        self.timer += delta_time

        if self.timer > (1 / ANIM_SPEED):
            self.curr_texture = (self.curr_texture + 1) % len(self.animation)
            self.texture = self.animation[self.curr_texture]

            self.timer = 0.0


class Wall(arcade.Sprite):
    def __init__(self, path: PathOrTexture, scale: float) -> None:
        super().__init__(path, scale)
