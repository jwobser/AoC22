package com.jimwobser;

import java.io.IOException;
import java.io.RandomAccessFile;
import java.util.Stack;

public class D10 {
    private static int MAXCYCLES = 200;
    private static Stack<Integer> priorities = new Stack<Integer>();
    static Integer[] checkcyles = {20, 60, 100, 140, 180, 220};
    static RandomAccessFile input;
    public static void main(String[] args) throws IOException {
        var infilename = "d10.input";
        Boolean useExample = false;
        if(args.length == 1){
            infilename = args[0];
            useExample = true;
        }
        Integer registerX = 1;
        Integer progCounter = 1;
        Integer progressindex = 0;
        input = new RandomAccessFile(infilename, "r");

        var instruction = getop(input);
        while(instruction.type != Intstruction.Type.EOF) {
            switch (instruction.type) {
                case addX:
                    if (checkcyles[progressindex] - progCounter < 2) {
                        var cycle = checkcyles[progressindex++];
                        var priority = cycle * registerX;
                        priorities.push(priority);
                    }
                    registerX += instruction.value;
                    progCounter += 2;
                    break;
                case EOF:
                case noop:
                default:
                    progCounter++;
            }
            if(progressindex >= checkcyles.length){
                break;
            }
            if (progCounter == checkcyles[progressindex]) {
                priorities.push(registerX * progCounter);
                progressindex++;
            }
            instruction = getop(input);
        }
        var sum = priorities.stream().reduce(0, (a,b) -> a+b);

        System.out.printf("Sum: %d", priorities.stream().reduce(0, (a,b) -> a+b));
    }

    private static Intstruction getop(RandomAccessFile input) throws IOException{
        String in = input.readLine();
        if(in == null){
            return new Intstruction(Intstruction.Type.EOF, 0);
        }
        var commands = in.split(" ");
        if(commands.length == 2){
            return new Intstruction(Intstruction.Type.addX, Integer.parseInt(commands[1]));
        } else {
            return new Intstruction(Intstruction.Type.noop, 0);
        }
    }
}

class Intstruction {
    Type type;
    int value;
    enum Type {EOF, noop, addX};
    public Intstruction(Type type, int value){
        this.value = value;
        this.type = type;
    }
}