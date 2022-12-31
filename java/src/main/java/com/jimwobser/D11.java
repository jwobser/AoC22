package com.jimwobser;

import javax.management.monitor.MonitorSettingException;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.math.BigInteger;
import java.util.*;
import java.util.regex.*;

import static java.lang.System.*;

public class D11 {
    private static java.util.ArrayList<Monkey> monkeys = new ArrayList<>();
    public static BufferedReader input;

    public static void main(String[] args) throws IOException {
        Monkey.setMonkeylist(monkeys);
        input = new BufferedReader(new FileReader("d11.input"), 10_000);
        int gcd = 1;

        var parser = new InputParser(input);
        for (int i = 0; i < 8; i++) {
            var monkeynum = parser.getMonkey();
            var itemlist = parser.getItems();
            var inspectionop = parser.getOp();
            var inspectMagnitude = parser.opval;
            var testdivisor = parser.getTest();
            gcd *= testdivisor;
            var trueDest = parser.getTrueDest();
            var falseDest = parser.getFalseDest();
            input.readLine();
            monkeys.add(new Monkey(monkeynum, itemlist, inspectionop, inspectMagnitude, testdivisor, falseDest, trueDest));
        }
        /*
        for(var m : monkeys){
            m.print();
        }

         */
        for(int i = 0; i < 10_000; i++){
            for(var m : monkeys){
                m.inspectItems(gcd);
            }
        }

        for(var m : monkeys){
            m.print();
        }
        var maxmonk = monkeys.stream().max((Monkey m1, Monkey m2) -> {return m1.inspections - m2.inspections;});
        monkeys.sort((m1, m2) -> {return m2.inspections - m1.inspections;});
        for(int i = 0; i < 2; i++){
            out.println(monkeys.get(i).inspections);
        }
        BigInteger monkeyBusiness;
        monkeyBusiness = BigInteger.valueOf(monkeys.get(0).inspections);
        monkeyBusiness = monkeyBusiness.multiply(BigInteger.valueOf(monkeys.get(1).inspections));
        out.println(monkeyBusiness);
//        out.println(monkeyBusiness.toString());
//        maxmonk.ifPresent(m -> out.println(m.inspections));
    }

}

class InputParser{
    protected static BufferedReader input;
    protected static java.util.regex.Pattern digitPattern = java.util.regex.Pattern.compile("(\\d+)");
    public int opval;
    public InputParser(BufferedReader input){
        InputParser.input =  input;
        opval = 0;
    }

    public int getMonkey() throws IOException{
        String inline = input.readLine();
        var matcher = digitPattern.matcher(inline);
        assert(matcher.find());
        return Integer.parseInt(matcher.group().strip());
    }

    public Stack<Long> getItems() throws IOException{
        var retval = new Stack<Long>();
        String inline = input.readLine();
        var matches = digitPattern.matcher(inline);
        while(matches.find()){
            retval.push(Long.parseLong(matches.group()));
        }
        return retval;
    }

    public Monkey.Operation getOp() throws IOException{
        String inline = input.readLine();
        var regP = Pattern.compile("= old ([+*]) ([0-9]+|old)");
        var matches = regP.matcher(inline);
        matches.find();
        var operator = matches.group(1).charAt(0);

        Monkey.Operation op;
        switch(operator){
            case '*':
                if(matches.group(2).compareTo("old") == 0){
                    op = Monkey.Operation.Square;
                } else {
                    op = Monkey.Operation.Multiply;
                    opval = Integer.parseInt(matches.group(2));
                }
                break;
            case '+':
                op = Monkey.Operation.Add;
                opval = Integer.parseInt(matches.group(2));
                break;
            default:
                throw new RuntimeException("Bad operator");
        }
        return op;
    }

    public int getTest() throws IOException{
        String inline = input.readLine();
        var matcher = digitPattern.matcher(inline);
        assert(matcher.find());
        return Integer.parseInt(matcher.group());
    }

    public int getTrueDest() throws IOException{
        String inline = input.readLine();
        var matcher = digitPattern.matcher(inline);
        assert(matcher.find());
        int retval =  Integer.parseInt(matcher.group());
        assert(retval >= 0 && retval <= 7);
        return retval;
    }

    public int getFalseDest() throws IOException{
        String inline = input.readLine();
        var matcher = digitPattern.matcher(inline);
        assert(matcher.find());
        int retval =  Integer.parseInt(matcher.group());
        assert(retval >= 0 && retval <= 7);
        return retval;
    }
}


class Monkey{
    enum Operation {Multiply, Add, Square};
    java.util.ArrayDeque<Long> items;
    Operation op;
    Integer number, destinationFalse, destinationTrue, inspectMagnitude;
    Integer testDivisor;
    Integer inspections;
    public static ArrayList<Monkey> monkeylist;

    public static void setMonkeylist(ArrayList<Monkey> mlist){
        monkeylist = mlist;
    }

    public void additem(Long item){
        items.add(item);
    }

    public void inspectItems(int gcd) {
        for(Long i : items){
            inspections++;
            switch(op){
                case Square -> i = i * i;
                case Add -> i += inspectMagnitude;
                case Multiply -> i *= inspectMagnitude;
            }
//            i = i / 3;
            i = i % gcd;
            Boolean divtest = (i % testDivisor) == 0;
            int target;
            if(divtest){
                target = destinationTrue;
            } else {
                target = destinationFalse;
            }
            monkeylist.get(target).additem(i);
        }
        items.clear();
    }

    public Monkey(int n, java.util.Stack<Long> itemlist, Operation op, int magntiude, int testD, int destF, int destT){
        items = new ArrayDeque<Long>();
        number = n;
        this.op = op;
        testDivisor = testD;
        destinationFalse = destF;
        destinationTrue = destT;
        inspections = 0;
        inspectMagnitude = magntiude;
        for(var i : itemlist){
            items.add(i);
//            items.push(i); // change to LIFO stack instead
        }

    }

    public void print(){
        out.printf("No. %d\t", number);
        out.print(op.toString() + '\t');
        out.print(inspectMagnitude.toString() + '\t');
        out.printf("Inspection count: %d\n", inspections);
        out.print("Items: ");
        out.println(items.toString());
        out.printf("Mod div: %d\t", testDivisor);
        out.printf("true->: %d\t", destinationTrue);
        out.printf("false->: %d\n", destinationFalse);
    }
}
