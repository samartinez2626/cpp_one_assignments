#include "../include/example_solver.h"

void ExampleSolver::solve(Board &board) {
    for (int i = 0; i < board.getX(); i++) {
        for (int j = 0; j < board.getY(); j++) {
            guess(i, j, board);
        }
    }
}
