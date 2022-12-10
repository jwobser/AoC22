#include <fstream>
#include <iostream>
#include <string>

std::ifstream input;
std::string buf;

int main(int argc, char** argv){
    (void)argc; // Unused
    (void)argv; // Unused
    input.open("input");
    char opponent;
    char player;
    unsigned int score {0};
    input >> opponent;
    input >> player;
    const char* const str_win = "Win";
    const char* const str_loss = "Lose";
    const char* const str_tie = "Tie";

    const char* outcome;
    while(!input.eof()){
        // Resolve outcome
        switch(opponent){
            case 'A':       // Rock
                if (player == 'Y'){score += 6; outcome = str_win;} // Win
                if (player == 'X'){score += 3; outcome = str_tie;} else {outcome = str_loss;}
                break;
            case 'B':       // Paper
                if (player == 'Z'){score += 6; outcome = str_win;} // Win
                if (player == 'Y'){score += 3; outcome = str_tie;} else {outcome = str_loss;}
                break;
            case 'C':       // Scissors
                if (player == 'X'){score += 6; outcome = str_win;} // Win
                if (player == 'Z'){score += 3; outcome = str_tie;} else {outcome = str_loss;}
                break;
        }

        // Score Player selection
        switch(player){
            case 'X':           // Rock
                score += 1;
                break;
            case 'Y':           // Paper
                score += 2;
                break;
            case 'Z':           // Scissors
                score += 3;
                break;
        }
        // std::cout << "First line of input:\n";
        printf("%c %c %s\n", opponent, player, outcome);
        input >> opponent;
        input >> player;
    }
    printf("Total score: %d\n", score);
    // sprintf
    // std::cout << opponent << std::endl;
}
