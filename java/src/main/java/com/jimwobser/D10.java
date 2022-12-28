package com.jimwobser;

import java.io.IOException;
import java.io.RandomAccessFile;
import java.sql.Array;
import java.util.Stack;

public class D10 {
    static Integer registerX = 1;
    static Integer progCounter = 1;
    static Integer progressindex = 0;
    static Integer[] pixels = new Integer[240];
    private static int MAXCYCLES = 200;
    private static Stack<Integer> priorities = new Stack<Integer>();
    static Integer[] checkcyles = {20, 60, 100, 140, 180, 220, 10_000_000};
    static RandomAccessFile input;
    public static void main(String[] args) throws IOException {
        System.out.printf("Pixel Array Size: %d\n", pixels.length);
        var infilename = "d10.input";
        Boolean useExample = false;
        if(args.length == 1){
            infilename = args[0];
            useExample = true;
        }
        input = new RandomAccessFile(infilename, "r");

        var instruction = getop(input);
        while(progCounter <= 240) {
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
        pixels[150] = 9;

        System.out.printf("Sum: %d\n", priorities.stream().reduce(0, (a,b) -> a+b));
        for(int i = 0; i < 240; ++i){
            if(i % 40 == 0){System.out.println();}
            if(pixels[i] == null) {System.out.print("  ");} else {System.out.print("\u2588\u2588");}
        }
    }

    private static void draw() {
        Integer column = (progCounter % 40) - 1 ;
        if(Math.abs(registerX - column) <= 1){
            pixels[progCounter - 1] = 1;
        }
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