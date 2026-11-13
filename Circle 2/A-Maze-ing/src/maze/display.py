from maze.maze_class import MyLaby
from typing import Optional
import os


def clear_screen() -> None:
    os.system('clear')


# affichage
def display(my_lab: MyLaby, colour: Optional[list[int]] = None) -> None:
    if colour is None:
        colour = [97, 96, 33, 31, 92]
    grid_to_display = my_lab.grid
    for y in range(my_lab.height):
        north_line = ""
        for x in range(my_lab.width):
            north_line += f"\033[1;{colour[0]}m+\033[0m"
            if (grid_to_display[y][x].north or
                    grid_to_display[y][x].ft or
                    grid_to_display[y - 1][x].ft):
                north_line += f"\033[1;{colour[0]}m===\033[0m"
            else:
                north_line += "   "
        north_line += f"\033[1;{colour[0]}m+\033[0m"
        print(north_line)

        middle_line = ""
        for x in range(my_lab.width):
            if (grid_to_display[y][x].west or
                    grid_to_display[y][x].ft or
                    grid_to_display[y][x - 1].ft):
                middle_line += f"\033[1;{colour[0]}m|\033[0m"
            else:
                middle_line += " "
            # case 42
            if grid_to_display[y][x].ft:
                middle_line += f"\033[1;5;{colour[1]}m O \033[0m"
            # chemin de resolution
            elif grid_to_display[y][x].resolved:
                if x == my_lab.entry_x and y == my_lab.entry_y:
                    middle_line += f"\033[1;{colour[2]}m W \033[0m"
                elif x == my_lab.exit_x and y == my_lab.exit_y:
                    middle_line += f"\033[1;{colour[3]}m W \033[0m"
                else:
                    middle_line += f"\033[1;{colour[4]}m W \033[0m"
            # point de depart
            elif x == my_lab.entry_x and y == my_lab.entry_y:
                middle_line += f"\033[1;{colour[2]}m E \033[0m"
            # point d'arrive
            elif x == my_lab.exit_x and y == my_lab.exit_y:
                middle_line += f"\033[1;{colour[3]}m S \033[0m"
            # point de presence
            elif grid_to_display[y][x].current:
                middle_line += "\033[1;35m A \033[0m"
                grid_to_display[y][x].current = False
            # le reste
            else:
                middle_line += "   "
        if grid_to_display[y][my_lab.width-1].east:
            middle_line += f"\033[1;{colour[0]}m|\033[0m"
        else:
            middle_line += " "
        print(middle_line)
    south_line = ""
    for x in range(my_lab.width):
        south_line += f"\033[1;{colour[0]}m+\033[0m"
        if grid_to_display[my_lab.height-1][x].south:
            south_line += f"\033[1;{colour[0]}m===\033[0m"
        else:
            south_line += "   "
    south_line += f"\033[1;{colour[0]}m+\033[0m"
    print(south_line)
