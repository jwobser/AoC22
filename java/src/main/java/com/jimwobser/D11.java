package com.jimwobser;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Deque;
import java.util.Stack;
import java.util.Vector;
import java.util.regex.*;
import java.util.ArrayDeque;

import static java.lang.System.*;

public class D11 {
    private static java.util.Vector<Monkey> monkeys = new Vector<>();
    public static void main(String[] args) throws IOException {
        var input = new BufferedReader(new FileReader("d11.input"), 10_000);
        String inline = input.readLine();
        var items = input.readLine().strip().split(" ");
        Stack<Long> itemlist = new Stack<>();
        for(int i = 2; i < items.length; i++){
            Long itemval = Long.parseLong(items[i].replace(',', ' ').strip());
            itemlist.push(itemval);
        }
        inline = input.readLine();
        var regP = Pattern.compile("= old ([+*]) ([0-9]+|old)");
        var matches = regP.matcher(inline);
        matches.find();
        var operator = matches.group(1).charAt(0);

        Monkey.Operation op;
        int opval = 0;
        switch(operator){
            case '*':
                if(matches.group(2) == "old"){
                    op = Monkey.Operation.Square;
                } else {
                    op = Monkey.Operation.Multiply;
                    opval = Integer.parseInt(matches.group(2));
                }
                break;
            case '+':
                op = Monkey.Operation.Add;
                break;
            default:
                throw new RuntimeException("Bad operator");
        }

        inline = input.readLine();
        regP = Pattern.compile("(\\d+)");
        matches = regP.matcher(inline);
        out.println(matches.find());

        int testval = Integer.parseInt(matches.group(1));

        inline = input.readLine();
        matches = regP.matcher(inline);
        matches.find();

        int destTrue = Integer.parseInt(matches.group(1));


        inline = input.readLine();
        matches = regP.matcher(inline);
        matches.find();

        int destFalse = Integer.parseInt(matches.group(1));

        out.printf("Test Val: %d\tTrue Destination: %d\tFalse Destination: %d\n", testval, destTrue, destFalse);
        Monkey m = new Monkey(0, itemlist, op, testval, destTrue, destFalse);
        m.print();


//            Integer num = Integer.getInteger(inline.replace(':',' ').strip().split(" ")[1]);
//            out.printf("Monkey number: %d\n", num);
    }
}

class Monkey{
    enum Operation {Multiply, Add, Square};
    java.util.ArrayDeque<Long> items;
    Operation op;
    Integer number, destinationFalse, destinationTrue;
    Integer testDivisor;

    public Monkey(int n, java.util.Stack<Long> itemlist, Operation op, int testD, int destF, int destT){
        items = new ArrayDeque<Long>();
        number = n;
        this.op = op;
        testDivisor = testD;
        destinationFalse = destF;
        destinationTrue = destT;
        for(var i : itemlist){
            items.push(i);
        }

    }

    public void print(){
        out.printf("n: %d\n%s\nmod: %d  T->%d, F->%d", number, op.toString(), testDivisor, destinationTrue, destinationFalse);
    }
}
