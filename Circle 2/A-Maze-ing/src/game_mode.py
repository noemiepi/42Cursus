import os
import random
import time
import arcade
from maze.maze_class import MyLaby
from sprite import Character, Wall


WINDOW_WIDTH = 1920
WINDOW_HEIGHT = 1080
WINDOW_TITLE = "A-Maze-ing"

PATH = "src/asset/"
SPRITE_SIZE = 24
CHARACTER_SIZE = 1
CHARACTER_SPEED = 2

OFFSET_X = 2 * SPRITE_SIZE
OFFSET_Y = 2 * SPRITE_SIZE


class WindowRenderer(arcade.Window):
    def __init__(self, maze: MyLaby) -> None:
        super().__init__(width=WINDOW_WIDTH, height=WINDOW_HEIGHT,
                         title=WINDOW_TITLE, resizable=True,
                         center_window=True, antialiasing=True)
        self.total_time = 0.0

        self.maze = maze
        self.player_list: arcade.SpriteList[arcade.Sprite] = \
            arcade.SpriteList()
        self.wall_list: arcade.SpriteList[arcade.Sprite] = arcade.SpriteList()
        self.easter_egg: arcade.SpriteList[arcade.Sprite] = arcade.SpriteList()
        self.exit: arcade.SpriteList[arcade.Sprite] = arcade.SpriteList()

        self.camera: arcade.camera.Camera2D = arcade.camera.Camera2D()

        self.crush = False
        self.easter = False

        self._display_maze()
        self._load_sprite()
        self.physic_engine = arcade.PhysicsEngineSimple(self.player,
                                                        self.wall_list)
        self.timer_text = arcade.Text(text="00:00", x=70,
                                      y=self.height - 50,
                                      color=arcade.color.WHITE, font_size=30,
                                      anchor_x="center")
        self.time_elapsed = 0.0

    def on_draw(self) -> None:
        self.clear()

        self.default_camera.use()
        arcade.draw_texture_rect(self.background, arcade.LBWH(0, 0, self.width,
                                                              self.height))

        self.camera.use()
        self.wall_list.draw()
        self.exit.draw()
        self.player_list.draw()
        if self.easter:
            arcade.play_sound(self.scream)
            self.easter_egg.draw()
        self.default_camera.use()
        self.timer_text.draw()

    def on_update(self, delta_time: float) -> None:
        self.wall_list.update()
        self.player.update_animation(delta_time, None, None)
        self.physic_engine.update()
        self.total_time += delta_time
        exit_hit_list = arcade.check_for_collision_with_list(self.player,
                                                             self.exit)
        self.time_elapsed += delta_time
        minutes = int(self.time_elapsed // 60)
        seconds = int(self.time_elapsed % 60)
        self.timer_text.text = f"{minutes:02d}:{seconds:02d}"

        if exit_hit_list:
            arcade.play_sound(self.applause)
            time.sleep(3)
            arcade.close_window()

    def on_key_press(self, symbol: int, modifiers: int) -> None:
        if symbol == arcade.key.ESCAPE:
            arcade.close_window()

        elif symbol == arcade.key.SPACE:
            if self.player.visible:
                self.player.visible = False
            else:
                self.player.visible = True

        elif symbol == arcade.key.LSHIFT or symbol == arcade.key.RSHIFT:
            if not self.crush:
                self.player.scale_y = CHARACTER_SIZE * 0.5
                self.player.change_y -= 0.5
                self.crush = True
                arcade.play_sound(self.elevator)
            else:
                self.player.scale_y = CHARACTER_SIZE
                self.player.change_y += 0.5
                self.crush = False
                arcade.play_sound(self.elevator)

        elif symbol == arcade.key.UP or symbol == arcade.key.W:
            if random.random() < 0.01:
                self.easter = True
            self.player.change_y += CHARACTER_SPEED
        elif symbol == arcade.key.DOWN or symbol == arcade.key.S:
            self.player.change_y -= CHARACTER_SPEED
            self.easter = False
        elif symbol == arcade.key.LEFT or symbol == arcade.key.A:
            self.player.change_x -= CHARACTER_SPEED
            self.player.scale_x = (-1 * CHARACTER_SIZE)
            self.easter = False
        elif symbol == arcade.key.RIGHT or symbol == arcade.key.D:
            self.player.change_x += CHARACTER_SPEED
            self.player.scale_x = CHARACTER_SIZE
            self.easter = False

    def on_key_release(self, symbol: int, modifiers: int) -> None:
        if symbol == arcade.key.UP or symbol == arcade.key.W:
            self.player.change_y = 0
        elif symbol == arcade.key.DOWN or symbol == arcade.key.S:
            self.player.change_y = 0
        elif symbol == arcade.key.LEFT or symbol == arcade.key.A:
            self.player.change_x = 0
        elif symbol == arcade.key.RIGHT or symbol == arcade.key.D:
            self.player.change_x = 0

    def _display_maze(self) -> None:
        grid = self.maze.grid
        maze_width = 0
        maze_height = 0

        for row in range(self.maze.height):
            for col in range(self.maze.width):

                screen_x = col * 2
                screen_y = row * 2

                if maze_width < screen_x:
                    maze_width = screen_x
                if maze_height < screen_y:
                    maze_height = screen_y

                if grid[row][col].north:
                    self._create_wall(screen_x, screen_y - 1)
                if grid[row][col].south:
                    self._create_wall(screen_x, screen_y + 1)
                if grid[row][col].west:
                    self._create_wall(screen_x - 1, screen_y)
                if grid[row][col].east:
                    self._create_wall(screen_x + 1, screen_y)
                self._create_wall(screen_x - 1, screen_y - 1)
                self._create_wall(screen_x - 1, screen_y + 1)
                self._create_wall(screen_x + 1, screen_y + 1)
                self._create_wall(screen_x + 1, screen_y - 1)

        maze_width_pxl = (maze_width * SPRITE_SIZE) + OFFSET_X + SPRITE_SIZE
        maze_height_pxl = (maze_height * SPRITE_SIZE) + OFFSET_Y + SPRITE_SIZE

        zoom_value = min((WINDOW_WIDTH / maze_width_pxl),
                         (WINDOW_HEIGHT / maze_height_pxl))

        center_maze_x = ((maze_width * SPRITE_SIZE / 2) + OFFSET_X +
                         (SPRITE_SIZE / 2))
        center_maze_y = (((WINDOW_HEIGHT - 100) -
                         maze_height * (SPRITE_SIZE / 2)) +
                         (OFFSET_Y - (SPRITE_SIZE / 2)))

        self.camera.position = (center_maze_x, center_maze_y)
        self.camera.zoom = zoom_value - 0.055

    def _create_wall(self, x: float, y: float) -> None:
        try:
            wall = Wall(f"{PATH}wall.png", 1)
        except FileNotFoundError:
            raise ValueError("\033[1;91mError: wall asset not found\033[0m")
        wall.center_x = x * SPRITE_SIZE + (SPRITE_SIZE / 2) + OFFSET_X
        wall.center_y = ((WINDOW_HEIGHT - 100) - (y * SPRITE_SIZE) -
                         (SPRITE_SIZE / 2) + OFFSET_Y)
        self.wall_list.append(wall)

    def _load_sprite(self) -> None:
        try:
            if not os.path.exists("src/asset/"):
                raise ValueError

            self.background = arcade.load_texture(f"{PATH}background.png")

            character_animation = [
                arcade.load_texture(f"{PATH}character1.png"),
                arcade.load_texture(f"{PATH}character2.png"),
                arcade.load_texture(f"{PATH}character3.png"),
                arcade.load_texture(f"{PATH}character4.png"),
            ]

            wolf = Character(f"{PATH}wolf.jpg", 0.8, [])
            wolf.center_x = WINDOW_WIDTH / 2
            wolf.center_y = WINDOW_HEIGHT / 2
            self.easter_egg.append(wolf)

            exit_sprite = Wall(f"{PATH}exit.png", 1)
            exit_sprite.center_x = ((self.maze.exit_x * 2) * SPRITE_SIZE +
                                    (SPRITE_SIZE / 2) + OFFSET_X)
            exit_sprite.center_y = ((WINDOW_HEIGHT - 100) -
                                    ((self.maze.exit_y * 2) * SPRITE_SIZE) -
                                    (SPRITE_SIZE / 2) + OFFSET_Y)
            self.exit.append(exit_sprite)

            self.elevator = arcade.load_sound(f"{PATH}elevator.mp3")
            self.applause = arcade.load_sound(f"{PATH}applause.mp3")
            self.scream = arcade.load_sound(f"{PATH}scream.mp3")

            self.player = Character(f"{PATH}character1.png", CHARACTER_SIZE,
                                    character_animation)
            self.player.center_x = (((self.maze.entry_x * SPRITE_SIZE) +
                                    (SPRITE_SIZE / 2)) + OFFSET_X)
            self.player.center_y = (((WINDOW_HEIGHT - 100) -
                                    (self.maze.entry_y * SPRITE_SIZE) -
                                    (SPRITE_SIZE / 2)) + OFFSET_Y)
            self.player_list.append(self.player)

        except FileNotFoundError:
            raise ValueError("\033[1;91mError: player asset not found\033[0m")
