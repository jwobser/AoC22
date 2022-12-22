#include <fstream>
#include <iostream>
#include <string>
#include <deque>
#include <array>
#include <regex>
#include <ios>
#include <limits>

const unsigned short STACK_COUNT {9};
const unsigned short MAX_HEIGHT {8};

std::ifstream input;
std::string buf;

std::array<std::deque<char>, STACK_COUNT> stacks;
const std::regex lineparse("move (\\d+) from (\\d+) to (\\d+)", std::regex::optimize);

struct moveop{
    int src, dest, count;
};

moveop parseline(std::string s){
    std::smatch results;
    std::regex_match(s, results, lineparse);
    int src = stoi(results[2].str());
    int dest = stoi(results[3].str());
    int count = stoi(results[1].str());
    return {src, dest, count};
}


void moveletters(int src, int dest, int count){
    // Compensate indexes
    src -= 1;
    dest -= 1;

    for(int i {0}; i < count; i++){
        stacks[dest].push_back(stacks[src].back());
        stacks[src].pop_back();
    }
}

void moveletters(moveop op){
    moveletters(op.src, op.dest, op.count);
}

std::ostream& operator<<(std::ostream& out, const std::deque<char>& dq){
    for(const char& c : dq){
        out << c << ' ';
    }
    return out;
}

void printstack(void){
    for(const auto& dq : stacks){
        std::cout << dq;
        std::cout << '\n';
    }
    std::cout << '\n';
}

int main(int argc, char** argv) {
    (void) argc; // Unused
    (void) argv; // Unused
    input.open("input");
    for (int i{0}; i < MAX_HEIGHT; i++) {
        std::getline(input, buf);
        for (int j{0}; j < STACK_COUNT; j++) {
            int letterpos = 1 + (4 * j);
            if (buf[letterpos] != ' ') {
                stacks[j].push_front(buf[letterpos]);
            }
        }
    }
    printstack();

	// std::cout << "Long Max: " << std::numeric_limits<long>::max() << '\n';
    input.ignore(std::numeric_limits<long>::max(), '\n');
    input.ignore(std::numeric_limits<long>::max(), '\n');
    std::getline(input, buf);

    int movecount{0};
    while (!input.eof()) {
        auto op = parseline(buf);
        moveletters(op);
        movecount++;
        std::getline(input, buf);
    }

    printstack();

    std::cout << "move count: " << movecount << '\n';

    for (const auto& dq: stacks) {
        std::cout << dq.back();
    }
    std::cout << '\n';
}
