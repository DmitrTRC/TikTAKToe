#include <ncurses.h>
#include "helper.h"
#include "rendering.h"
#include "processing.h"

int main() {

    initscr();

    noecho();
    keypad(stdscr, TRUE);

    if (has_colors() == FALSE) {
        endwin();
        printf("Your terminal does not support color\n");
        exit(1);
    }

    start_color();
    curs_set(0);


    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    init_pair(66, COLOR_WHITE, COLOR_RED);

    // Get the initial screen size
    max_x = getmaxx(stdscr);
    max_y = getmaxy(stdscr);

    if (start_menu() == 1) {
        endwin();
        return 0;
    }

    bool restart = true;
    while (restart)
    {
        ch = 0;
        current_player = starting_player;
        turn = 0;

        max_x = getmaxx(stdscr);
        max_y = getmaxy(stdscr);
        grid.clear();

        for (int y = 0; y < grid_size_y; y++) {
            grid.emplace_back();
            for (int x = 0; x < grid_size_x; x++) {
                Pixel pixel;
                pixel.pos_y = y;
                pixel.pos_x = x;
                grid[y].push_back(pixel);
            }
        }

        set_grid_sel(0, 0, true);
        y_index = 0, x_index = 0;

        render_grid();

        while (true) {
            if (max_y > grid_size_y * 2 + 13)
                help_text(max_y - 8, 2);

            if (current_player == 1 || gamemode == 1) {
                if (human_turn() == 1) {
                    endwin();
                    return 0;
                }

                if (gamemode == 1) {
                    if (current_player == 1)
                        current_player = 2;
                    else if (current_player == 2)
                        current_player = 1;
                    if (current_player == starting_player)
                        turn++;
                } else
                    current_player = 2;
            }

            int win = detect_win();
            if (win == 0) {
                    mvprintw(max_y - 8, 2, "No player has won");
            } else if (win == -1) {
                    mvprintw(max_y - 8, 2, "The field is full! The game has finished with a tie!");
                current_player = -1;
                break;
            } else {
                    mvprintw(max_y - 8, 2, "Player %d has won!", win);
                current_player = win;
                break;
            }

            if (gamemode == 0 && current_player == 2)
            {
                computer_turn();
                win = detect_win();
                current_player = 1; // Set current player to the real one again
                turn++;
                if (win == 2) {
                        mvprintw(max_y - 8, 2, "The computer has won!"); // Debug
                    current_player = win;
                    break;
                } else if (win == -1) {
                        mvprintw(max_y - 8, 2, "The field is full! The game has finished with a tie!");
                    current_player = -1;
                    break;
                }
            }

            render_grid();
        }

        render_grid();
        int win_menu_state = win_menu();
        if (win_menu_state == 0) {
            restart = false;
        }
    }
    endwin();
    return 0;
}
