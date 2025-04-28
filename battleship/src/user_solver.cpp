#include <iostream>
#include "../include/user_solver.h"
#include <cstdlib>
#include <ctime>
#include "../include/types.h"

void UserSolver::solve(Board &board) {
 
   {
        srand((int)time(0));  // Seed randomness

        size_t boardX = board.getX();
        size_t boardY = board.getY();
        int hits = 0;
        int guessCount = 0;
        const int maxGuesses = 100;
        const int maxHits = 17;  

        while (true) {
            // 1. Make random guess
            size_t i = rand() % boardX;
            size_t j = rand() % boardY;
            ReturnType currentGuess = guess(i, j, board);
            guessCount++;
            std::cout << "Guessing (" << i << ", " << j << "): " << currentGuess << std::endl;

            // 2. If hit, try moving right along x-axis
            if (currentGuess == hit) {
                hits++;
                std::cout << "First hit at (" << i << ", " << j << ")\n";
                size_t nextI = i + 1;

                while (nextI < boardX) {
                    ReturnType nextGuess = guess(nextI, j, board);
                    guessCount++;
                    std::cout << "Chaining hit check at (" << nextI << ", " << j << "): " << nextGuess
                              << std::endl;

                    if (nextGuess != hit) {
                        break;  // Stop chain
                    }
                    hits++;
                    nextI++;
                }
            }

            // You can implement a break condition when all ships are sunk
            // For now, you can run this a few times then return
            // Example: break after 100 guesses or use a counter
            if (hits >= maxHits || guessCount >= maxGuesses) {
                std::cout << "All ships sunk or max guesses reached!" << std::endl;
                break;  // Stop searching
            }
        }
   }
}
    //for (int i = 0; i < board.getX(); i++) 
    //{
    //    for (int j = 0; j < board.getY(); j++) 
    //        //get rid of these for loops?????
    //        //use them latel instead of starting w them
    //        //use forloops after evaluating an initial guess
    //    {
    //        ReturnType currentGuess = guess(i, j, board);

    //        if (currentGuess == hit)
    //        {
    //            //ex youll keep wanting to add +1 to an x if ur still getting hits until ur not anymore
    //            i++;
    //          
    //        else if 
    //                i++ = near_miss 
    //            {
    //                    i--;
    //            }
    //            else if 
    //                i++ = miss
    //            {
    //                    //loop around make random guess;
    //                }

    //                
    //        }
    //        
    //    }
    //}  
   // void UserSolver::solve(Board &board) 