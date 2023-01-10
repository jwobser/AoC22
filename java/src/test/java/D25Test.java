import com.jimwobser.D25;
import com.jimwobser.D25Kt;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;


public class D25Test {
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
