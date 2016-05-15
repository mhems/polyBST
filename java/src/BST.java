package BST;

import java.util.List;
import java.util.ArrayList;
import java.util.Comparator;

public class BST<T> {
    private T node;
    private BST<T> left, right;
    private Comparator<T> comparator;

    public BST(Comparator<T> comparator) {
        this.comparator = comparator;
    }

    public int size() {
        int sum = 0;
        if (node != null) {
            ++sum;
            if (left != null) {
                sum += left.size();
            }
            if (right != null) {
                sum += right.size();
            }
        }
        return sum;
    }

    public boolean add(T elem) {
        if (node == null) {
            node = elem;
            return true;
        }
        int result = comparator.compare(node, elem);
        if (result != 0) {
            if (result < 0) {
                if (left == null) {
                    left = new BST<>(comparator);
                }
                return left.add(elem);
            } else {
                if (right == null) {
                    right = new BST<>(comparator);
                }
                return right.add(elem);
            }
        } else {
            return false;
        }
    }

    public boolean contains(T elem) {
        if (node == null) {
            return false;
        }
        int result = comparator.compare(node, elem);
        if (result == 0) {
            return true;
        } else if (result < 0) {
            return left != null && left.contains(elem);
        } else {
            return right != null && right.contains(elem);
        }
    }

    public List<T> toList() {
        List<T> list = new ArrayList<>();
        if (left != null) {
            list.addAll(left.toList());
        }
        list.add(node);
        if (right != null) {
            list.addAll(right.toList());
        }
        return list;
    }
}
