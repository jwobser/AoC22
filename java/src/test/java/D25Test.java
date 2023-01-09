import com.jimwobser.D25Kt;
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;


public class D25Test {
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

}
