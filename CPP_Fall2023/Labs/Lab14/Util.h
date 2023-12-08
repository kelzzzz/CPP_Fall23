#pragma once
#include <random>

const int MAT_SIZE = 4;

enum CELL_TRAIT {
	TREASURE_GAIN_20, TREASURE_GAIN_30, TREASURE_LOSE,
	SHIP_DESTROYED, SECRET_TUNNEL, EMPTY_CELL
};
struct cell {
	CELL_TRAIT trait;
};
struct ship {
	int treasure = 0;
    int visits = 0;
	bool destroyed = false;
    int visited_cells[MAT_SIZE][MAT_SIZE];
};

bool has_visited(ship ship, int row, int col) {
    return ship.visited_cells[row][col] == 1;
}

void clear_visited_cells(ship &ship) {
    for (int i = 0; i < MAT_SIZE; i++) {
        for (int j = 0; j < MAT_SIZE; j++) {
            ship.visited_cells[i][i] = 0;
        }
    }
}

bool random_should_fill_cell_with_trait() {
    int flip = rand() % 100;
    return (flip >= 90);
}

CELL_TRAIT get_random_cell_trait() {
    return CELL_TRAIT(rand() % 6);
}

cell create_cell() {
    cell created{};
    if (random_should_fill_cell_with_trait) {
        created.trait = get_random_cell_trait();
    }
    else {
        created.trait = EMPTY_CELL;
    }
    return created;
}

void set_matrix(cell matrix[MAT_SIZE][MAT_SIZE]) {
    int tunnelPresent = 0;
    for (int i = 0; i < MAT_SIZE; i++) {
        for (int j = 0; j < MAT_SIZE; j++) {
            matrix[i][j] = create_cell();
            if (matrix[i][j].trait == SECRET_TUNNEL) {
                tunnelPresent++;
            }
            if (tunnelPresent > 1) {
                while(tunnelPresent > 1) {
                    matrix[i][j].trait = get_random_cell_trait();
                    if (matrix[i][j].trait != SECRET_TUNNEL) {
                        tunnelPresent--;
                    }
                }
            }
        }
    }
    if (tunnelPresent != 1) {
        matrix[rand() % MAT_SIZE][rand() % MAT_SIZE].trait = get_random_cell_trait();
    }
}