#include <ncurses.h>
#include "helper.h"


int gamemode = 0; // Gamemode: 0: Singleplayer; 1: Multiplayer;
int starting_player;

int current_player;

char empty_pixel = ' ', unknown_pixel = '?', player_one_pixel = 'X', player_two_pixel = 'O';

int player_one_color = 1, player_two_color = 2;

int max_y, max_x;

int grid_size_y = 3, grid_size_x = 3, pixels_needed = 3;

int y_index = 0, x_index = 0;

void Pixel::print_details(int row, int col) {

    mvprintw(row, col, "Value: %d, Selected: %d, Pos_y: %d, Pos_x: %d", value, selected, pos_y, pos_x);
}

void Pixel::set_value(int my_value) {

    value = my_value;
}

int Pixel::get_value() {

    return value;
}

void Pixel::set_selected(bool my_selected) {

    selected = my_selected;
}

bool Pixel::get_selected() {

    return selected;
}


std::vector<std::vector<Pixel> > grid;


int get_grid_val(int pos_y, int pos_x) {

    if (pos_y < grid_size_y && pos_x < grid_size_x && pos_y >= 0 && pos_x >= 0)
        return grid[pos_y][pos_x].get_value();
    else {
        return 0;
    }
}

void set_grid_val(int pos_y, int pos_x, int val) {

    if (pos_y < grid_size_y && pos_x < grid_size_x && pos_y >= 0 && pos_x >= 0) {
        grid[pos_y][pos_x].set_value(val);
    }
}

int get_grid_sel(int pos_y, int pos_x) {

    if (pos_y < grid_size_y && pos_x < grid_size_x && pos_y >= 0 && pos_x >= 0)
        return grid[pos_y][pos_x].get_selected();
    else return 0;

}

void set_grid_sel(int pos_y, int pos_x, bool selected) {

    if (pos_y < grid_size_y && pos_x < grid_size_x && pos_y >= 0 && pos_x >= 0)
        grid[pos_y][pos_x].set_selected(selected);

}

int turn = 0;

int ch;
