package com.jimwobser;

import java.io.IOException;
import java.io.RandomAccessFile;
import java.util.Stack;
import static java.lang.System.out;


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
            System.out.print(instruction.type.toString());
            System.out.print(" ");
            System.out.println(instruction.value);
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
            System.out.printf("%4d -- X: %3d\n", progCounter, registerX);
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
        if(useExample){
            try {
                assert (priorities.elementAt(0) == 420);
                assert (priorities.elementAt(1) == 1140);
                assert (priorities.elementAt(2) == 1800);
                assert (priorities.elementAt(3) == 2940);
                assert (priorities.elementAt(4) == 2880);
                assert (priorities.elementAt(5) == 3960);
                assert (sum == 13140);
            }
            catch (AssertionError e){
                System.out.println("Test Cases Incorrect");
            }
        }
        try{ assert(sum > 12800);}
        catch (AssertionError e){ System.out.println("Sum too low");};
        try{assert(sum < 17280);}
        catch (AssertionError e){ System.out.printf("Sum [%d] too high\n", sum);};
        priorities.forEach(priority -> System.out.println(priority));
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