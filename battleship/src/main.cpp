#include <stdexcept>

#include "../include/board.h"
#include "../include/example_solver.h"
#include "../include/user_solver.h"


int main() {
    Board b = Board(1000, 1000, 5);

    UserSolver us;
    us.solve(b);
}
