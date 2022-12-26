[![CMake](https://github.com/jwobser/AoC22/actions/workflows/cmake.yml/badge.svg)](https://github.com/jwobser/AoC22/actions/workflows/cmake.yml)

# AoC22
Advent of Code 2022

<hr>

### Building
Each day has a subfolder. Each subfolder has a makefile which will compile the executeable, at least on Linux and MacOS.
`make main`

From Day 3 onward I have switched to CMake. From the root folder:
```bash
mkdir build
cd build
cmake ../
cmake --build . --target dXpX
cd ../X
./../build/Debug/dXpX
```

### Running
`./build/main.a`

### Getting Input File
The programs expect the input file to named `input` with no extension. You can right click and save the files directly from AoC, but I have also included my input files just to demonstrate how the program would work.

<hr>

## Day 1
### Part 1
I learned about the priority queue doing AoC last year, so it seemed like a good tool to reach for here. Using the std::greater comparison so that the smallest value always ends up at the top, then popping it off to make sure that I have the three larget values remaining. 

### Part 2
I had no idea grabbing the top three was going to be the next part, but since I used a priority queue in part one it was trivial to add a quick sum loop to add together the top three most calorie laden elves. There may be a way to use the stl algorithms to do the sum in a single line, but I will have to do some more research.


## Day 2
### Part 1
This one wasn't too bad, just grabbing the two inputs and determining if it was a win, tie or loss.

### Part 2
This was a bigger tear up than I was hoping, had to add a player selection variable and some nested `switch-case` statements to basically build a state machine. Had a couple missteps where I forgot to `break` the out switch statement, which was causing fallthrough and messing the scoring up.

## Day 3
Take the left half of the string and push each character into a set.
The for the right side, if the character is not already in the set, we know it is not a duplicate.

If it is a duplicate, take the letter and score it.

## Day 4
Used a regex to get the cleaning assignment start and end points.
Then checked to see if there was complete between the 2. If there was, increase the overlap counter.

### Part 2
Just had to tweak the overlap checking function so that it returns true for partial overlaps.

## Day 5


## Day 6
For this one I just push the characters into a double ended queue, and also maintain an array of character counts. If any character count is greater than one, I know that there are duplicates, so I can pop off front of the queue, subtract the count of that letter, then add then next one from input.

For part 2, I just had to increase the queue length to 14 from 4.

## Day 8
This one was a doozy, and I wrote a bunch of functions to perform the logic of checking each tree.
This makes the main executable a short 25 lines of code, however, as it just needs to iterator over the tree matrix and track the max score which is returned.

## Day 9
### Part 1
Using a `std::set` to track the points visited by the tail seemed like an obvious solution. Then I simply have to output the size of the set to get the number of unique points visited. A little `Point` struct was used, along with the [default `C++20` spaceship (three way compare) operator.](https://en.cppreference.com/w/cpp/language/default_comparisons)

### Part 2
My plan for part to is just to add a vector of tails, then with each step of the head iterate over the vector and have the tails follow their neighbor. Might rewrite the helper function to take a pair of point references, rather than individual coordinates.
