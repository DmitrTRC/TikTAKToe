#include <vector>
#include <cstdlib>
#include <time.h>
#include <ncurses.h>
#include "helper.h"
#include "rendering.h"
#include "processing.h"


// Let a human make a turn
int human_turn() {

    bool is_done = false;

    do {
        ch = 0;

        while (ch != 10 && ch != ' ') {
            ch = getch();

            if (ch == 113) // q
            {
                return 1;
            }

            switch (ch) {
                case KEY_DOWN:
                    y_index++;
                    break;
                case KEY_UP:
                    y_index--;
                    break;
                case KEY_LEFT:
                    x_index--;
                    break;
                case KEY_RIGHT:
                    x_index++;
                    break;

                default:
                    break;
            }

            for (int i = 0; i < grid.size(); i++) {
                for (int j = 0; j < grid[i].size(); j++) {
                    set_grid_sel(i, j, false);
                }
            }

            if (y_index < 0)
                y_index = 0;
            if (y_index > grid.size() - 1)
                y_index = grid.size() - 1;
            if (x_index < 0)
                x_index = 0;
            if (x_index > grid[0].size() - 1)
                x_index = grid[0].size() - 1;


            set_grid_sel(y_index, x_index, true);
            grid[y_index][x_index].print_details(max_y - 4, 2);

            render_grid();
        }

        if (get_grid_val(y_index, x_index) == 0) {
            set_grid_val(y_index, x_index, current_player);
            is_done = true;
        } else {

            is_done = false;
        }
        render_grid();

    } while (!is_done);

    return 0;
}


// Check if a player has won
int detect_win() {

    int x_parse = 0, y_parse = 0;
    int player_checked;
    bool vert_won = false, hor_won = false, dia_right_won = false, dia_left_won = false;

    while (y_parse < grid_size_y && x_parse < grid_size_x) {

        while (get_grid_val(y_parse, x_parse) == 0) {
            if (y_parse == grid_size_y - 1 && x_parse == grid_size_x - 1)
                break;
            if (x_parse == grid_size_x - 1) {
                x_parse = 0;
                y_parse++;
            } else {
                x_parse++;
            }
        }

        player_checked = get_grid_val(y_parse, x_parse);
        int ref_pixel_y = y_parse, ref_pixel_x = x_parse;

        vert_won = true;

        for (int i = 0; i < pixels_needed; i++) {

            if (ref_pixel_y <= grid_size_y - pixels_needed) {

                if (get_grid_val(ref_pixel_y + i, ref_pixel_x) != player_checked) {
                    vert_won = false;
                    break;
                }

            } else {
                vert_won = false;
            }
        }

        if (vert_won)
            return player_checked;


        hor_won = true;

        for (int i = 0; i < pixels_needed; i++) {
            if (ref_pixel_x <= grid_size_x - pixels_needed) {
                if (get_grid_val(ref_pixel_y, ref_pixel_x + i) != player_checked) {
                    hor_won = false;
                    break;
                }

            } else
                hor_won = false;
        }

        if (hor_won)
            return player_checked;

        dia_right_won = true;
        for (int i = 0; i < pixels_needed; i++) {
            if (ref_pixel_x <= grid_size_x - pixels_needed && ref_pixel_y <= grid_size_y - pixels_needed) {
                if (get_grid_val(ref_pixel_y + i, ref_pixel_x + i) != player_checked) {
                    dia_right_won = false;
                    break;
                }
            } else
                dia_right_won = false;

        }

        if (dia_right_won)
            return player_checked;


        dia_left_won = true;
        for (int i = 0; i < pixels_needed; i++) {
            if (ref_pixel_x <= grid_size_x + pixels_needed && ref_pixel_y <= grid_size_y - pixels_needed) {
                if (get_grid_val(ref_pixel_y + i, ref_pixel_x - i) != player_checked) {
                    dia_left_won = false;
                    break;
                }
            } else
                dia_left_won = false;

        }

        if (dia_left_won) {
            return player_checked;
        }

        if (x_parse >= grid_size_x - 1) {
            x_parse = 0;
            y_parse++;
        } else {
            x_parse++;
        }

    }

    x_parse = 0, y_parse = 0;
    while (true) {

        if (y_parse == grid_size_y)
            return -1;

        if (get_grid_val(y_parse, x_parse) == 0)
            break;

        if (x_parse == grid_size_x - 1) {
            x_parse = 0;
            y_parse++;
        } else
            x_parse++;
    }

    // Return 0 if no one has won
    if (vert_won == false && hor_won == false && dia_right_won == false &&
        dia_left_won == false) {//Fixme : Infinite loop
        return 0;
    }
    return 1;
}


int rand_y, rand_x;

int place_y, place_x;

int origin_y, origin_x;

int expansion, prev_expansion;

std::vector<std::vector<int> > weak_pixels;


void print_weak_pixels(int y_pos, int x_pos) {

    for (int i = 0; i < 8; i++) {
        mvprintw(y_pos + i, x_pos, "\n");
    }

    for (int i = 0; i < weak_pixels.size(); i++) {
        mvprintw(y_pos + i, x_pos, "Entry %d: Y: %d, X: %d", i, weak_pixels[i][0], weak_pixels[i][1]);
    }
}


void push_to_weak(int y_val, int x_val) {

    if (get_grid_val(y_val, x_val) == 0) {

        weak_pixels.emplace_back();
        weak_pixels[weak_pixels.size() - 1].push_back(y_val);
        weak_pixels[weak_pixels.size() - 1].push_back(x_val);
    }
}


void get_start_spot() {

    srand(time(0));
    do {
        if (pixels_needed < grid.size())
            rand_y = rand() % (grid.size() - pixels_needed) + 1;
        else
            rand_y = rand() % (grid.size());

        if (pixels_needed < grid[0].size())
            rand_x = rand() % (grid[0].size() - pixels_needed) + 1;
        else
            rand_x = rand() % (grid[0].size());
    } while (get_grid_val(rand_y, rand_x) != 0);

    place_y = rand_y, place_x = rand_x;
    origin_y = rand_y, origin_x = rand_x;

    set_grid_val(place_y, place_x, 2);
}

void computer_turn() {

    if (turn == 0) {
        get_start_spot();
        return;
    }

    prev_expansion = expansion;
    expansion = 0;

    int iteration = 0;

    while (expansion == 0) {

        int parse_x = origin_x, parse_y = origin_y;

        bool move_on = false;
        int loop = 0;
        for (loop = 0; loop < pixels_needed; loop++) {

            if (parse_y < grid.size() && parse_x < grid[0].size()) {

                if (get_grid_val(parse_y, parse_x) == 1) {
                    move_on = true;
                }
            }

            // Check expansions based on the current iteration
            switch (iteration) {
                case 0:
                    parse_x++;
                    break;
                case 1:
                    parse_x--;
                    break;
                case 2:
                    parse_y++;
                    break;
                case 3:
                    parse_y--;
                    break;
                case 4:
                    parse_x++;
                    parse_y++;
                    break;
                case 5:
                    parse_x--;
                    parse_y++;
                    break;
                default:
                    break;
            }
        }

        // If move_on is still false, this expansion will be successful
        if (!move_on) {
            // Set expansion to the corresponding iteration value
            switch (iteration) {
                case 0:
                    expansion = 1;
                    break;
                case 1:
                    expansion = -1;
                    break;
                case 2:
                    expansion = 2;
                    break;
                case 3:
                    expansion = -2;
                    break;
                case 4:
                    expansion = 3;
                    break;
                case 5:
                    expansion = -3;
                    break;
                default:
                    break;
            }
        }

        iteration++;

        if (iteration > 5) {

            refresh();
            get_start_spot();
            break;
        }
    }

    weak_pixels.clear();
    int y_parse = 0, x_parse = 0;
    while (y_parse < grid_size_y && x_parse < grid_size_x) {

        while (get_grid_val(y_parse, x_parse) != 1) {
            if (y_parse == grid_size_y - 1 && x_parse == grid_size_x - 1)
                break;
            if (x_parse == grid_size_x - 1) {
                x_parse = 0;
                y_parse++;
            } else
                x_parse++;
        }

        for (int i = 0; i < 4; i++) {
            int iter = 0;
            while (true) {

                int op_y{}, op_x{};
                switch (i) {

                    case 0:
                        op_y = y_parse + iter, op_x = x_parse;
                        break;
                        // Horizontal Check
                    case 1:
                        op_y = y_parse, op_x = x_parse + iter;
                        break;
                        // Diagonal right
                    case 2:
                        op_y = y_parse + iter, op_x = x_parse + iter;
                        break;
                        // Diagonal left
                    case 3:
                        op_y = y_parse + iter, op_x = x_parse - iter;
                        break;
                    default:
                        break;
                }


                if (op_y >= grid_size_y || op_x >= grid_size_x) {

                    if (iter == pixels_needed - 1) {
                        int neg_y = y_parse, neg_x = x_parse;
                        switch (i) {
                            case 0:
                                neg_y--;
                                break;
                            case 1:
                                neg_x--;
                                break;
                            case 2:
                                neg_y--, neg_x--;
                                break;
                            case 3:
                                neg_y--, neg_x++;
                                break;
                            default:
                                break;
                        }
                        push_to_weak(neg_y, neg_x);
                    }
                    break;
                }

                if (get_grid_val(op_y, op_x) != 1) {

                    if (iter == pixels_needed - 1) {
                        push_to_weak(op_y, op_x);
                        int neg_y = y_parse, neg_x = x_parse;

                        switch (i) {
                            case 0:
                                neg_y--;
                                break;
                            case 1:
                                neg_x--;
                                break;
                            case 2:
                                neg_y--, neg_x--;
                                break;
                            case 3:
                                neg_y--, neg_x++;
                                break;
                            default:
                                break;
                        }
                        push_to_weak(neg_y, neg_x);
                    }
                    break;
                }

                iter++;
            }
        }


        if (x_parse >= grid_size_x - 1) {
            x_parse = 0;
            y_parse++;
        } else {
            x_parse++;
        }
    }


    if (weak_pixels.size() == 0) {

        if (expansion == prev_expansion) {
            switch (expansion) {
                case 1:
                    place_y = place_y, place_x++;
                    break;
                case -1:
                    place_y = place_y, place_x--;
                    break;
                case 2:
                    place_y++, place_x = place_x;
                    break;
                case -2:
                    place_y--, place_x = place_x;
                    break;

                case 3:
                    place_y++, place_x++;
                    break;
                case -3:
                    place_y++, place_x--;
                    break;

                default:
                    get_start_spot();
                    return;

            }
        }

        else {
            switch (expansion) {
                case 1:
                    place_y = origin_y, place_x = origin_x + 1;
                    break;
                case -1:
                    place_y = origin_y, place_x = origin_x - 1;
                    break;
                case 2:
                    place_y = origin_y + 1, place_x = origin_x;
                    break;
                case -2:
                    place_y = origin_y - 1, place_x = origin_x;
                    break;
                case 3:
                    place_y = origin_y + 1, place_x = origin_x + 1;
                    break;
                case -3:
                    place_y = origin_y + 1, place_x = origin_x - 1;
                    break;
                default:
                    get_start_spot();
                    return;

            }
        }
    } else {

        place_y = weak_pixels[0][0], place_x = weak_pixels[0][1];
    }

    if (place_y < grid.size() && place_x < grid[0].size()) {
        if (get_grid_val(place_y, place_x) == 0)
            set_grid_val(place_y, place_x, 2);
        else
            get_start_spot();
    } else
        get_start_spot();
}
