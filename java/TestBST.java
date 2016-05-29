package BST;

import java.util.Arrays;
import java.util.List;
import java.util.ArrayList;
import java.util.Comparator;

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
        boolean status = true;
        Comparator<Integer> comp = Comparator.comparingInt(i -> i);
        BST<Integer> b = new BST<>(comp);
        List<Integer> exp = new ArrayList<>();
        status |= verify(0, b.size());
        status |= verify(Arrays.asList(), b.list());
        b.add(5);
        exp.add(5);
        status |= verify(true, b.contains(5));
        status |= verify(1, b.size());
        status |= verify(exp, b.list());
        for (int i = 10; i >= 0; --i) {
            Integer I = new Integer(i);
            b.add(I);
            if (!exp.contains(I)) {
                exp.add(I);
            }
        }
        status |= verify(11, b.size());
        exp.sort(comp);
        status |= verify(exp, b.list());
        for (int i = 0; i < 11; ++i) {
            status |= verify(true, b.contains(new Integer(i)));
        }
        status |= verify(false, b.contains(new Integer(11)));
        System.exit(status ? 0 : 1);
    }
}
