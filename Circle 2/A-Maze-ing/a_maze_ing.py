#!/usr/bin/env python3.10

from maze.check_dependencies import check_dependencies
import time

if check_dependencies():

    from maze.display import display, clear_screen
    from game_mode import WindowRenderer
    from user_interaction import UserMenu
    from maze.resolved_lab import resolve_lab
    import arcade
    print("It's ready for A-Maze-ing project")
    i = 0
    c = 1
    algo = 0
    colour_list = {"normal": [97, 96, 33, 31, 92],
                   "darker": [37, 36, 33, 31, 32],
                   "purple": [95, 96, 33, 91, 92],
                   "blue": [94, 95, 33, 91, 92],
                   "red": [91, 96, 93, 97, 92]}
    colour = colour_list.get("normal")
    lab = None
    path = None

    while True:
        algo_str = "DFS" if algo == 0 else "Hunt&Kill"
        menu = UserMenu()
        clear_screen()
        if not menu.config:
            if not menu.critical_error:
                print("\033[1;31mconfig.txt not found\033[0m")
                break
            for warn in menu.critical_error.errors():
                loc = warn['loc'] if warn['loc'] else "Global Error"
                print(f"\033[5;35m{loc}\033[0m")
                print(f" \033[1;31m{warn['msg']}\033[0m")
            while not menu.config:
                time.sleep(2)
                menu = UserMenu()

        else:
            if lab is None:
                lab = menu.generate_maze(colour, algo)
                path = resolve_lab(lab)
            else:
                path = resolve_lab(lab)
                display(lab, colour)
                print(f"\033[1;36m{algo_str}\033[0m")
            lab.output_maze(path)
            menu.display_menu()
            try:
                choice = int(input("Choice? (1-6): "))
                if not 1 <= choice <= 6:
                    clear_screen()
                    display(lab, colour)
                    print("\nInvalid choice! Please select a number between "
                          "1 and 6")
                elif choice == 1:
                    lab = menu.re_generate(colour, algo)
                elif choice == 2:
                    menu.show_hide(lab, colour, path)
                elif choice == 3:
                    colour = menu.colour_change(lab, colour_list, c)
                    c += 1
                    if c == 5:
                        c = 0
                elif choice == 4:
                    algo = menu.algo_change(algo, colour)
                elif choice == 5:
                    WindowRenderer(lab)
                    arcade.run()
                    break
                elif choice == 6:
                    print("\033[1;94m\nExiting the program...\033[0m")
                    print("\033[1;92mGoodbye! :D\033[0m")
                    break
            except ValueError:
                clear_screen()
                display(lab, colour)
                print("\nYou didn't enter an int")
            except Exception as e:
                clear_screen()
                display(lab, colour)
                print(f"\n{e}")
