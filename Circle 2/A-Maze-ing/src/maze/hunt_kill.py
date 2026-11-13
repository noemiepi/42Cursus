import random
from maze.maze_class import MyLaby
from maze.display import display, clear_screen
import time


class HuntKill(MyLaby):

    def maze_creator(self) -> None:
        if self.seed:
            random.seed(self.seed)
        i = 1
        current_x, current_y = self.entry_x, self.entry_y
        self.grid[current_y][current_x].visited = True
        while True:
            self.grid[current_y][current_x].current = True
            clear_screen()
            display(self)
            time.sleep(0.05)
            free_neigbhors = self.neighbor(current_x, current_y, "create")
            if free_neigbhors:
                random.shuffle(free_neigbhors)
                for direction, nx, ny in free_neigbhors:
                    if not self.grid[ny][nx].ft:
                        self.grid[ny][nx].visited = True
                        self.open_wall(current_x, current_y, direction, nx, ny)
                        current_x, current_y = nx, ny
                        i += 1
                        break
            else:
                found = False
                for y in range(self.height):
                    for x in range(self.width):
                        if not self.grid[y][x].visited and\
                           not self.grid[y][x].ft:
                            vn = self.neighbor(x, y, "hunt")
                            if vn:
                                direction, vx, vy = vn[0]
                                self.open_wall(x, y, direction, vx, vy)
                                self.grid[y][x].visited = True
                                current_x, current_y = x, y
                                found = True
                                break
                    if found:
                        break
                if not found:
                    return
