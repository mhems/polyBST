#include <iostream>

#include "BST.hpp"

    using std::vector;
    using std::cout;
    using std::endl;

namespace BST {
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
        return sum;
    }

    template <typename T, typename C>
    bool BST<T, C>::add(T elem) {
        C comp;
        if (root == nullptr) {
            this->root = new Node(elem);
            return true;
        }
        if (root->value != elem) {
            if (comp(elem, root->value)) {
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
        C comp;
        if (root == nullptr) {
            return false;
        }
        if (root->value == elem) {
            return true;
        } else if (comp(elem, root->value)) {
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
            list.insert(list.end(), ret.cbegin(), ret.cend());
        }
        if (root != nullptr) {
            list.push_back(root->value);
        }
        if (right != nullptr) {
            vector<T> ret = right->list();
            list.insert(list.end(), ret.cbegin(), ret.cend());
        }
        return list;
    }

    template <typename T, typename C>
    BST<T, C>::~BST() {
        delete root;
        delete left;
        delete right;
    }

    template class BST<int>;
}
