package Boxes;

import org.example.Boxes.Box;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class BoxTest {

    @Test
    void TestEmptyConstuctorHasZeroValues(){
        Box b = new Box();
        assertEquals(0, b.getWidth());
        assertEquals(0, b.getHeight());
        assertEquals(0, b.getDepth());
    }
}