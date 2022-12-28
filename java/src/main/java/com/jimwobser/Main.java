package com.jimwobser;

import java.io.IOException;
import java.io.RandomAccessFile;
import java.math.BigInteger;
import java.util.Queue;
import java.util.Stack;

public class Main {
    static Integer[] checkcyles = {20, 60, 100, 140, 180, 220};
    public static void main(String[] args) throws IOException {
        Stack<Integer> priorities = new Stack<Integer>();
        Integer registerX = 1;
        Integer progCounter = 1;
        Integer nextAdd = 0;
        try(RandomAccessFile input = new RandomAccessFile("input", "r")){
            while(progCounter <= 221){
                String in = input.readLine();
                if(in != null){
                    var commands = in.split(" ");
                    if(commands.length == 2){
                        nextAdd = Integer.parseInt(commands[1]);
                    }
                }
                progCounter++;
                if(java.util.Arrays.binarySearch(checkcyles, progCounter) >= 0){
                    System.out.printf("Cycle: %d\tSignal Strength: %d\n", progCounter, progCounter * registerX);
                    priorities.push(progCounter * registerX);
                }
                registerX += nextAdd;
                nextAdd = 0;
            }
        }
        System.out.printf("Sum: %d", priorities.stream().reduce(0, (a,b) -> a+b));
    }

}