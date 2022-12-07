# AoC22
Advent of Code 2022

<hr>

### Building
Each day has a subfolder. Each subfolder has a makefile which will compile the executeable, at least on Linux and MacOS.

`make main`
### Running
`./build/main.a`

### Getting Input File
The programs expect the input file to named `input` with no extension. You can right click and save the files directly from AoC, but I have also included my input files just to demonstrate how the program would work.

<hr>

## Day 1
### Part 1
I learned about the priority queue doing AoC last year, so it seemed like a good tool to reach for here. Using the std::greater comparison so that the smallest value always ends up at the top, then popping it off to make sure that I have the three larget values remaining. 

### Part 2
I had know idea grabbing the top three was going to be the next part, but since I used a priority queue in part one it was trivial to add a quick sum loop to add together the top three most calorie laden elves. There may be a way to use the stl algorithms to do the sum in a single line, but I will have to do some more research.