import random
from maze.maze_class import MyLaby
from maze.display import display, clear_screen
import time


class DfsLab(MyLaby):

    # algorithme de creation du labyrinthe
    def maze_creator(self) -> None:
        if self.seed:
            random.seed(self.seed)
        stack = [(self.entry_x, self.entry_y)]
        self.grid[self.entry_y][self.entry_x].visited = True
        while stack:
            current_x, current_y = stack[-1]
            self.grid[current_y][current_x].current = True
            clear_screen()
            display(self)
            time.sleep(0.05)
            free_neighbors = self.neighbor(current_x, current_y, "create")
            if free_neighbors:
                random.shuffle(free_neighbors)
                direction, nx, ny = free_neighbors[0]
                self.grid[ny][nx].visited = True
                if not self.grid[current_y][current_x].ft and\
                   not self.grid[ny][nx].ft:
                    self.open_wall(current_x, current_y, direction, nx, ny)
                    stack.append((nx, ny))
            else:
                stack.pop()
