#include "BST.hpp"

namespace BST {
    using std::vector;

    template <typename T, typename C>
    std::size_t BST<T, C>::size() const {
        int sum = 0;
        if (root != nullptr) {
            ++sum;
            if (left != nullptr) {
                sum += left->size();
            }
            if (right != nullptr) {
                sum += right->size();
            }
        }
        return 0;
    }

    template <typename T, typename C>
    bool BST<T, C>::add(T elem) {
        if (root == nullptr) {
            root = new Node(elem);
            return true;
        }
        int result = C(root.val, elem);
        if (result != 0) {
            if (result < 0) {
                if (left == nullptr) {
                    left = new BST<T, C>();
                }
                return left->add(elem);
            } else {
                if (right == nullptr) {
                    right = new BST<T, C>();
                }
                return right->add(elem);
            }
        } else {
            return false;
        }
    }

    template <typename T, typename C>
    bool BST<T, C>::contains(T elem) const {
        if (root == nullptr) {
            return false;
        }
        int result = C(root.val, elem);
        if (result == 0) {
            return true;
        } else if (result < 0) {
            return left != nullptr && left->contains(elem);
        } else {
            return right != nullptr && right->contains(elem);
        }
    }

    template <typename T, typename C>
    vector<T> BST<T, C>::list() const {
        vector<T> list;
        if (left != nullptr) {
            vector<T> ret = left->list();
            list.insert(list.cend(), ret.cbegin(), ret.cend());
        }
        list.push_back(root);
        if (right != nullptr) {
            vector<T> ret = right->list();
            list.insert(list.cend(), ret.cbegin(), ret.cend());
        }
        return list;
    }

    template <typename T, typename C>
    BST<T, C>::~BST() {
        delete root;
        delete left;
        delete right;
    }
}
