#include <iostream>

#include <ncurses.h>
#include "examples/example0_simple_menu.h"

int main() {
    // setup
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    refresh();

    // create main window for the menus
    WINDOW *main_window = create_newwin(LINES, COLS, 0, 0);

    int main_choice;

    { // MAIN MENU
        std::vector<std::string> main_menu_config;
        main_menu_config.emplace_back("Simple Menu");
        main_menu_config.emplace_back("Menu with Input");
        main_menu_config.emplace_back("Exit Program");
        Menu main_menu = Menu(main_window, main_menu_config, 0, " Choose Example ");
        main_menu.refresh_all();
        main_menu.loop();
        main_choice = main_menu.evaluate_choice();

        main_menu.erase();
        main_menu.refresh_all();
    }

    if (main_choice == 0) {
        run_example0(main_window);
    } else if (main_choice != 2) {
        endwin();
        std::cout << "This example does not exist yet! :/" << std::endl;
    }

    endwin();

    return 0;
}