package BST;

import java.util.Comparator;
import java.util.Arrays;

public class TestBST {
    public static boolean verify(Object expected, Object actual) {
        if (expected == null) {
            if (actual != null) {
                System.out.println("expected " + "null" + ", received " + actual.toString());
                return false;
            }
            return true;
        }
        if (!expected.equals(actual)) {
            System.out.println("expected " + expected.toString() + ", received " + actual.toString());
            return false;
        }
        return true;
    }

    public static void main(String[] args) {
        BST<Integer> b = new BST<>(Comparator.comparingInt(i -> i));
        verify(0, b.size());
        b.add(5);
        verify(1, b.size());
        verify(Arrays.asList(5), b.list());
        for (int i = 10; i >= 0; --i) {
            b.add(new Integer(i));
        }
        verify(11, b.size());
        verify(Arrays.asList(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10), b.list());
        for (int i = 0; i < 11; ++i) {
            verify(true, b.contains(new Integer(i)));
        }
        verify(false, b.contains(new Integer(11)));
    }
}
