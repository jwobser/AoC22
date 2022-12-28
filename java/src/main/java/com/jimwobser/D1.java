package com.jimwobser;

import java.io.IOException;
import java.io.RandomAccessFile;
import java.util.PriorityQueue;

public class D1 {
    public static void main(String[] args) throws IOException {
        try(RandomAccessFile input = new RandomAccessFile("d1.input", "r")){
            PriorityQueue<Integer> calories =  new PriorityQueue<Integer>();
            int elfcalories = 0;
            while(true){
                String line = input.readLine();
                if(line == null){
                    break;
                } else if(line.compareTo("") == 0){
                    calories.add(elfcalories);
                    elfcalories = 0;
                } else {
                    elfcalories += Integer.parseInt(line);
                }
                if(calories.size() > 3){
                    calories.poll();
                }
            }
            System.out.println("Top 3:");
            calories.forEach((Integer i) -> {System.out.println(i);});
            System.out.print("Total: ");
            System.out.println(calories.stream().reduce(0, (a, b) -> a + b));
        }
        catch (IOException e){
            System.out.println("Failed to open file");
        }
    }
}