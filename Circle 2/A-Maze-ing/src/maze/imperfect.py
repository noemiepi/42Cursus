from maze.maze_class import MyLaby
import random


def imperfect_maze(my_lab: MyLaby) -> None:
    for y in range(my_lab.height):
        for x in range(my_lab.width):
            free_neighbors = my_lab.neighbor(x, y, "imperfect")
            random.shuffle(free_neighbors)
            for direction, nx, ny in free_neighbors:
                if not my_lab.grid[y][x].ft:
                    my_lab.grid[y][x].visited = False
                    my_lab.open_wall(x, y, direction, nx, ny)
