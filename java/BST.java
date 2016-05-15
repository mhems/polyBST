package BST;

import java.util.List;
import java.util.ArrayList;
import java.util.Comparator;

/**
 * Class representing a Binary Search Tree
 */

public class BST<T> {
    private T node;
    private BST<T> left, right;
    private Comparator<T> comparator;

    /**
     * Construct BST object with comparator
     * @param comparator the Comparator object to compare elements with
     */
    public BST(Comparator<T> comparator) {
        this.comparator = comparator;
    }

    /**
     * Determine size of this BST
     * @return number of elements in this BST
     */
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

    /**
     * Add element to this BST
     * @param elem the element to add
     * @return true iff element was added to this BST
     */
    public boolean add(T elem) {
        if (node == null) {
            node = elem;
            return true;
        }
        int result = comparator.compare(node, elem);
        if (result != 0) {
            if (result > 0) {
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

    /**
     * Determines if this BST contains an element
     * @param elem the element to determine membership for
     * @return true iff this BST contains elem
     */
    public boolean contains(T elem) {
        if (node == null) {
            return false;
        }
        int result = comparator.compare(node, elem);
        if (result == 0) {
            return true;
        } else if (result > 0) {
            return left != null && left.contains(elem);
        } else {
            return right != null && right.contains(elem);
        }
    }

    /**
     * Computes in-order list of this BST's elements
     * @return list of this BST's elements, in-order
     */
    public List<T> list() {
        List<T> list = new ArrayList<>();
        if (left != null) {
            list.addAll(left.list());
        }
        list.add(node);
        if (right != null) {
            list.addAll(right.list());
        }
        return list;
    }
}
