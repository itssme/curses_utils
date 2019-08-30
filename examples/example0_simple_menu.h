/*
 * author: Joel Klimont
 * filename: example0_simple_menu.h
 * date: 30/08/19
*/

#ifndef CURSES_UTILS_EXAMPLE0_SIMPLE_MENU_H
#define CURSES_UTILS_EXAMPLE0_SIMPLE_MENU_H

#include "../curses_utils.h"

void run_example0(WINDOW* main_window) {
    int main_choice{0};
    int pizza_choice{-1};
    int fast_food_choice{-1};

    std::vector<std::string> main_menu_config;
    main_menu_config.emplace_back("Pizza");
    main_menu_config.emplace_back("Fast Food");
    main_menu_config.emplace_back("Exit Program");

    std::vector<std::string> pizza_menu_config;
    pizza_menu_config.emplace_back("Margarita");
    pizza_menu_config.emplace_back("Hawaii");
    pizza_menu_config.emplace_back("Sausage");
    pizza_menu_config.emplace_back("Pepperoni");
    pizza_menu_config.emplace_back("go back");

    std::vector<std::string> fast_food_menu_config;
    fast_food_menu_config.emplace_back("Burger");
    fast_food_menu_config.emplace_back("Fried Chicken");
    fast_food_menu_config.emplace_back("Sandwiches");
    fast_food_menu_config.emplace_back("go back");

    while (main_choice != 2) {
        { // FOOD MENU
            Menu main_menu = Menu(main_window, main_menu_config, 0, " Choose Food ");
            main_menu.refresh_all();
            main_menu.loop();
            main_choice = main_menu.evaluate_choice();

            main_menu.erase();
            main_menu.refresh_all();
        }

        if (main_choice == 0) {
            { // PIZZA MENU
                Menu main_menu = Menu(main_window, pizza_menu_config, 0, " Pizza ");
                main_menu.refresh_all();
                main_menu.loop();
                pizza_choice = main_menu.evaluate_choice();

                main_menu.erase();
                main_menu.refresh_all();

                if (pizza_choice == 4) {
                    main_choice = 0;
                } else {
                    endwin();
                    std::cout << "You choose: " << pizza_menu_config.at(pizza_choice) << std::endl;
                    main_choice = 2;
                }
            }
        } else if (main_choice == 1) {
            { // FAST FOOD MENU
                Menu main_menu = Menu(main_window, fast_food_menu_config, 0, " Fast Food ");
                main_menu.refresh_all();
                main_menu.loop();
                fast_food_choice = main_menu.evaluate_choice();

                main_menu.erase();
                main_menu.refresh_all();

                if (fast_food_choice == 3) {
                    main_choice = 0;
                } else {
                    endwin();
                    std::cout << "You choose: " << fast_food_menu_config.at(fast_food_choice) << std::endl;
                    main_choice = 2;
                }
            }
        }
    }
}

#endif //CURSES_UTILS_EXAMPLE0_SIMPLE_MENU_H
