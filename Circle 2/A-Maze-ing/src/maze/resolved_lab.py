from collections import deque
from maze.maze_class import MyLaby
from typing import Optional, Any


def resolve_lab(my_lab: MyLaby, colour: Optional[list[int]] = None,
                i: Optional[int] = None) -> list[tuple[Any, Any]]:
    ex = my_lab.entry_x
    ey = my_lab.entry_y
    if colour is None:
        colour = [97, 96, 33, 31, 92]
    queue = deque[tuple[int, int]]()
    queue.append((ex, ey))
    visited = {(my_lab.entry_x, my_lab.entry_y)}
    parent = {}
    while queue:
        x, y = queue.popleft()
        if (x, y) == (my_lab.exit_x, my_lab.exit_y):
            break
        for dir, nx, ny in my_lab.neighbor(x, y, "resolve_lab"):
            if (nx, ny) not in visited:
                queue.append((nx, ny))
                visited.add((nx, ny))
                parent[(nx, ny)] = (x, y)

    path = []
    current = (my_lab.exit_x, my_lab.exit_y)
    while current != (my_lab.entry_x, my_lab.entry_y):
        x, y = current
        path.append(current)
        current = parent[current]

    path.append((my_lab.entry_x, my_lab.entry_y))
    path.reverse()
    return path
