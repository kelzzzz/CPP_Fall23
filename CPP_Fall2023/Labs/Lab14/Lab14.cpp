#include <iostream>
#include <random>
#include "Util.h"

void print_matrix(cell matrix[MAT_SIZE][MAT_SIZE]);
void traverse_matrix(ship& ship, cell matrix[MAT_SIZE][MAT_SIZE]);

int main()
{
    srand(time(NULL));
    cell cellMatrix[MAT_SIZE][MAT_SIZE];
    set_matrix(cellMatrix);
    ship ship{};

    print_matrix(cellMatrix);
    while (!ship.destroyed) {
        traverse_matrix(ship, cellMatrix);
    }
    std::cout << "Total treasure: " << ship.treasure << "\n";
    std::cout << "Total visits: " << ship.visits << "\n";

}

void print_matrix(cell matrix[MAT_SIZE][MAT_SIZE]) {
    for (int i = 0; i < MAT_SIZE; i++) {
        for (int j = 0; j < MAT_SIZE; j++) {
            std::cout << "{ " << i << ", " << j << " }";
            if (matrix[i][j].trait != EMPTY_CELL) {
                std::cout << "*";
            }
        }
        std::cout << "\n";
    }
}
void traverse_matrix(ship& ship, cell matrix[MAT_SIZE][MAT_SIZE]) {
    int randRow = rand() % MAT_SIZE;
    int randCol = rand() % MAT_SIZE;
    if (!has_visited(ship, randRow, randCol)) {
        ship.visits++;
        std::cout << "Visiting cell " << randRow << ", " << randCol << "\n";
        ship.visited_cells[randRow][randCol] = 1;
        switch (matrix[randRow][randCol].trait) {
            case(TREASURE_GAIN_20):
                std::cout << "Treasure + 20\n";
                ship.treasure += 20;
                break;
            case(TREASURE_GAIN_30):
                std::cout << "Treasure + 30\n";
                ship.treasure += 30;
                break;
            case(TREASURE_LOSE):
                std::cout << "Treasure - 10\n";
                ship.treasure -= 10;
                break;
            case(SHIP_DESTROYED):
                std::cout << "Ship destroyed :(\n";
                ship.destroyed = true;
                break;
            case(SECRET_TUNNEL):
                set_matrix(matrix);
                clear_visited_cells(ship);
                std::cout << "Secret tunnel found; advancing to a new level.\n";
                print_matrix(matrix);
                break;
            case(EMPTY_CELL):
                break;
        }
    }
    if (!ship.destroyed) {
        traverse_matrix(ship, matrix);
    }
    else {
        return;
    }
}
