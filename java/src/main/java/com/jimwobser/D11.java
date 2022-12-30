package com.jimwobser;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Stack;
import java.util.Vector;
import java.util.regex.*;

import static java.lang.System.*;

public class D11 {
    private static java.util.Vector<Monkey> monkeys = new Vector<>();
    public static void main(String[] args) throws IOException {
        var input = new BufferedReader(new FileReader("d11.input"), 10_000);
        String inline = input.readLine();
        out.println(inline);
        out.println(Integer.parseInt(inline.split(" ")[1].replace(':', ' ').strip()));
        var items = input.readLine().strip().split(" ");
        Stack<Long> itemlist = new Stack<>();
        out.print("Items: ");
        for(int i = 2; i < items.length; i++){
            Long itemval = Long.parseLong(items[i].replace(',', ' ').strip());
            itemlist.push(itemval);
            out.printf("%d, ", itemval);
        }
        out.println(' ');
        inline = input.readLine();
        var regP = Pattern.compile("= old ([+*]) ([0-9]+|old)", Pattern.DOTALL);
        var matches = regP.matcher(inline);
        out.println(inline);
        out.printf("Matches found: %b", matches.matches());
        var operator = matches.group(0).charAt(0);

        Monkey.Operation op;
        switch(operator){
            case '*':
                if(matches.group(1) == "old"){
                    op = Monkey.Operation.Square;
                } else {
                    op = Monkey.Operation.Multiply;
                }
                break;
            case '+':
                op = Monkey.Operation.Add;
                break;
            default:
                throw new RuntimeException("Bad operator");
        }


//            Integer num = Integer.getInteger(inline.replace(':',' ').strip().split(" ")[1]);
//            out.printf("Monkey number: %d\n", num);
    }
}

class Monkey{
    enum Operation {Multiply, Add, Square};
    java.util.Deque<Long> items;
    Operation op;
    Integer number, destinationFalse, destinationTrue;
    Integer testDivisor;

    public Monkey(int n, java.util.Stack<Long> itemlist, Operation op, int testD, int destF, int destT){
        number = n;
        this.op = op;
        testDivisor = testD;
        destinationFalse = destF;
        destinationTrue = destT;
        for(var i : itemlist){
            items.push(i);
        }

    }
}
