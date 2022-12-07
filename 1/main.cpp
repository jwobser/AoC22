#include <fstream>
#include <iostream>
#include <string>
#include <queue>
#include <vector>

std::ifstream input;
std::string buf;

int main(int argc, char** argv){
    (void)argc; // Unused
    (void)argv; // Unused

    std::priority_queue<int, std::vector<int>, std::greater<int>> calories;
    // Fill up top 3 with zeroes
    calories.push(0);
    calories.push(0);
    calories.push(0);
    
    input.open("input");
    int working_sum {0};

    getline(input, buf);
    while (!(input.eof())){
        if (buf == ""){
            std::cout << "Elf has: " << working_sum << " calories\n";
            calories.push(working_sum);
            calories.pop();
            working_sum = 0;
        } else {
            working_sum += stoi(buf);
        }
    getline(input, buf);
    }

    std::cout << "There are " << calories.size() << " elves\n";
    int top_three{0};
    for(int i {0}; i < 3; ++i){
        std::cout << calories.top() << '\n';
        top_three += calories.top();
        calories.pop();
    }

    std::cout << "In total, the top three elves are carrying: " << top_three << " calories\n";
}
