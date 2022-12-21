#include <fstream>
#include <iostream>
#include <string>
#include <exception>

std::ifstream input;
std::string buf;

int main(int argc, char** argv){
    (void)argc; // Unused
    (void)argv; // Unused
    char opponent;
    char player;
    char playersel;
    unsigned int score {0};
    const char* const str_win = "Win";
    const char* const str_loss = "Lose";
    const char* const str_tie = "Tie";

    const char* outcome;

    input.open("input");
    if(!input){
        throw std::runtime_error("Failed to open input");
    }
    input >> opponent;
    input >> player;
    while(!input.eof()){

        // Score outcome
        switch(player){
            case 'Z':
                score += 6;
                outcome = str_win;
                break;
            case 'Y':
                score += 3;
                outcome = str_tie;
                break;
            default:
                outcome = str_loss;
                break;
        }

        // Determine Player selection
        switch(opponent){
            case 'A':       // Rock
                switch(player){
                    case 'Z': // win
                        playersel = 'P';
                        break;
                    case 'Y': // tie
                        playersel = 'R';
                        break;
                    case 'X': // lose
                        playersel = 'S';
                        break;
                }
                break; 
            case 'B':       // Paper
                 switch(player){
                    case 'Z': // win
                        playersel = 'S';
                        break;
                    case 'Y': // tie
                        playersel = 'P';
                        break;
                    case 'X': // lose
                        playersel = 'R';
                        break;
                }
                break;
           case 'C':       // Scissors
                  switch(player){
                    case 'Z': // win
                        playersel = 'R';
                        break;
                    case 'Y': // tie
                        playersel = 'S';
                        break;
                    case 'X': // lose
                        playersel = 'P';
                        break;
                }
      }

        // Score Player selection
        switch(playersel){
            case 'R':           // Rock
                score += 1;
                break;
            case 'P':           // Paper
                score += 2;
                break;
            case 'S':           // Scissors
                score += 3;
                break;
        }
        // std::cout << "First line of input:\n";
        printf("%c %c %s - Running score: %d\n", opponent, player, outcome, score);
        input >> opponent;
        input >> player;
    }
    printf("Total score: %d\n", score);
    // sprintf
    // std::cout << opponent << std::endl;
}
