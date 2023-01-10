import com.jimwobser.D25;
import com.jimwobser.D25Kt;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;


public class D25Test {
    /*
    @Test
    public void parseLineExample(){
        Integer result = D25Kt.parseLine("1=-0-2");
        assertEquals(result, 1747);
        result = D25Kt.parseLine("12111");
        assertEquals(result, 906);
        result = D25Kt.parseLine("2=0=");
        assertEquals(result, 198);
        result = D25Kt.parseLine("1=-1=");
        assertEquals(result, 353);
    }

    @Test
    public void convertToBaseFive(){
        var result = D25Kt.convertToBaseFive(Integer.valueOf(30));
        var listexpected = List.of(0,1,1,0);
        var expected = new ArrayList<Integer>(listexpected);
        assertEquals(expected, result);
        result = D25Kt.convertToBaseFive(Integer.valueOf(26));
        expected = new ArrayList<Integer>(List.of(0,1,0,1));
        assertEquals(expected, result);
        result = D25Kt.convertToBaseFive(Integer.valueOf(31));
        expected = new ArrayList<Integer>(List.of(0,1,1,1));
        assertEquals(expected, result);
        result = D25Kt.convertToBaseFive(Integer.valueOf(125));
        expected = new ArrayList<Integer>(List.of(0,1,0,0,0));
        assertEquals(expected, result);
        result = D25Kt.convertToBaseFive(Integer.valueOf(3124));
        expected = new ArrayList<Integer>(List.of(0,4,4,4,4,4));
        assertEquals(expected, result);
        result = D25Kt.convertToBaseFive(Integer.valueOf(80));
        expected = new ArrayList<Integer>(List.of(0,3,1,0));
        assertEquals(expected, result);
    }

    @Test
    public void changeOffset(){
        var result = D25Kt.offsetBaseFive(new ArrayList<Integer>(List.of(0,3,1,0)));
        var expected = new ArrayList<Integer>(List.of(1,-2,1,0));
        assertEquals(expected, result);
    }

    @Test
    public void changeOffset2(){
//        System.out.println(D25Kt.convertToBaseFive(Integer.valueOf(353)).toString());
        var result = D25Kt.offsetBaseFive(new ArrayList<>(List.of(0,2,4,0,3)));
        var expected = new ArrayList<>(List.of(1,-2,-1,1,-2));
        assertEquals(expected, result);
        result = D25Kt.offsetBaseFive(D25Kt.convertToBaseFive(Integer.valueOf(1747)));
        expected = new ArrayList<>(List.of(1,-2,-1,0,-1, 2));
        assertEquals(expected, result);
//        System.out.println(result);
    }

    */

    @Test
    public void addArrays(){
        var expected = new ArrayList<>(List.of(0,1,1,10));
        var a = new ArrayList<>(List.of(0,1,1,1));
        var b = new ArrayList<>(List.of(0,0,0,9));
        assertEquals(expected, D25Kt.addIntArray(a,b));

        expected = new ArrayList<>(List.of(0,10,10,10,9));
        a = new ArrayList<>(List.of(0,1,1,1));
        b = new ArrayList<>(List.of(0,9,9,9,9));
        assertEquals(expected, D25Kt.addIntArray(a,b));
    }

}
