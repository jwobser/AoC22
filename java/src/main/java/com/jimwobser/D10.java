package com.jimwobser;

import java.io.IOException;
import java.io.RandomAccessFile;
import java.util.Stack;

public class D10 {
    /** Simulated 'X' register */
    private static Integer registerX = 1;
    /** Simulated program counter */
    private static Integer progCounter = 1;
    /** Tracks the next cycle which needs to be reported */
    private static Integer progressindex = 0;
    private static Integer[] pixels = new Integer[240];
    private static int MAXCYCLES = 240;
    private static Stack<Integer> priorities = new Stack<Integer>();
    private static Integer[] checkcyles = {20, 60, 100, 140, 180, 220, 10_000_000};
    private static RandomAccessFile input;

    public static void main(String[] args) throws IOException {
        var infilename = "d10.input";
        input = new RandomAccessFile(infilename, "r");

        var instruction = getop(input);
        while(progCounter <= MAXCYCLES) {
            switch (instruction.type) {
                case addX:
                    if (checkcyles[progressindex] - progCounter < 2) {
                        var cycle = checkcyles[progressindex++];
                        var priority = cycle * registerX;
                        priorities.push(priority);
                    }
                    draw();
                    progCounter++;
                    draw();
                    progCounter++;
                    registerX += instruction.value;
                    break;
                case EOF:
                case noop:
                default:
                    draw();
                    progCounter++;
            }
            if(progressindex < checkcyles.length) {
                if (progCounter == checkcyles[progressindex]) {
                    priorities.push(registerX * progCounter);
                    progressindex++;
                }
            }
            instruction = getop(input);
        }


        var sum = priorities.stream().reduce(0, (a,b) -> a+b);
        System.out.printf("Sum: %d\n", priorities.stream().reduce(0, (a,b) -> a+b));

        for(int i = 0; i < 240; ++i){
            if(i % 40 == 0){System.out.println();}
            if(pixels[i] == null) {System.out.print("  ");} else {System.out.print("\u2588\u2588");}
        }
    }

    /** Update pixel array based on sprite position */
    private static void draw() {
        Integer column = (progCounter % 40) - 1 ;
        if(Math.abs(registerX - column) <= 1){
            pixels[progCounter - 1] = 1;
        }
    }

    /** Read input and parse into a processor instruction.
     *
     * @param input - the input file to read
     * @return The parsed {@code Instruction}
     * @throws IOException
     */
    private static Instruction getop(RandomAccessFile input) throws IOException{
        String in = input.readLine();
        if(in == null){
            return new Instruction(Instruction.Type.EOF, 0);
        }
        var commands = in.split(" ");
        if(commands.length == 2){
            return new Instruction(Instruction.Type.addX, Integer.parseInt(commands[1]));
        } else {
            return new Instruction(Instruction.Type.noop, 0);
        }
    }
}

class Instruction {
    Type type;
    int value;
    enum Type {EOF, noop, addX};
    public Instruction(Type type, int value){
        this.value = value;
        this.type = type;
    }
}