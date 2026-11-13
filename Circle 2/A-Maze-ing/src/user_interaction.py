from maze.display import display, clear_screen
from maze.config import config_method
from maze.maze_class import MyLaby
from maze.dfs import DfsLab
from maze.hunt_kill import HuntKill
from maze.imperfect import imperfect_maze
from typing import Optional


class UserMenu():
    def __init__(self) -> None:
        self.config, self.critical_error = config_method()

    def generate_maze(self, colour: Optional[list[int]], algo: Optional[int]
                      ) -> MyLaby:
        algo_str = ""
        lab: MyLaby
        # algo dfs utilise
        if algo == 0:
            lab = DfsLab(self.config)
            lab.case_ft()
            algo_str += "DFS"

        # algo hunt&kill utilise
        elif algo == 1:
            lab = HuntKill(self.config)
            lab.case_ft()
            algo_str += "Hunt&Kill"

        # labyrinthe imparfait
        lab.maze_creator()
        display(lab, colour)
        if not self.config.PERFECT:
            imperfect_maze(lab)
            algo_str += " Imperfect"
        clear_screen()
        display(lab, colour)
        print(f"\033[1;36m{algo_str}\033[0m")

        # creation du fichier output
        lab.output_maze()
        return lab

    def display_menu(self) -> None:
        if self.config._warning:
            print("\033[1;31m[NOTE] The configuration has be automaticaly "
                  "upgrade :\033[0m")
            for warn in self.config._warning:
                print(f"{warn}")
        print("\n=== A-Maze-ing Menu ===")
        print("1. Re-generate a new maze")
        print("2. Show/Hide path from entry to exit")
        print("3. Change maze wall colours")
        print("4. Change algorithm")
        print("5. Play mode")
        print("6. Quit")

    def re_generate(self, colour: list[int] | None, algo: int) -> MyLaby:
        clear_screen()
        lab = self.generate_maze(colour, algo)
        lab.output_maze()
        return lab

    def show_hide(self, lab: MyLaby, colour: list[int] | None,
                  path: list[tuple[int, int]]) -> None:
        import time
        for x, y in path:
            lab.grid[y][x].resolved = True
            clear_screen()
            display(lab, colour)
            time.sleep(0.05)
        for x, y in path:
            lab.grid[y][x].resolved = False
            clear_screen()
            display(lab, colour)
            time.sleep(0.05)

    def colour_change(self, lab: MyLaby, colour_list: dict[str, list[int]],
                      c: int) -> list[int] | None:
        colour_choice = ["normal", "darker", "purple", "blue", "red"]
        colour = colour_list.get(colour_choice[c])
        clear_screen()
        display(lab, colour)
        return colour

    def algo_change(self, algo: int, colour: list[int] | None) -> int:
        algo += 1
        if algo == 2:
            algo = 0
        if algo == 0:
            clear_screen()
            self.generate_maze(colour, algo)
            print("\nChanged algorithm to DFS")
        elif algo == 1:
            clear_screen()
            self.generate_maze(colour, algo)
            print("\nChanged algorithm to Hunt&Kill")
        return algo
