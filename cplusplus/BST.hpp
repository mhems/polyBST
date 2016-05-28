#ifndef BST_H
#define BST_H

#include <functional>
#include <vector>

namespace BST {

    template <typename T, typename Compare=std::less<T>>
    class BST {
        struct Node {
            T value;
            Node() = delete;
            Node(const Node&) = delete;
            Node& operator=(const Node&) = delete;
            explicit Node(T val) : value(val) { }
        };

        Node *root = nullptr;
        BST<T> *left = nullptr, *right = nullptr;

    public:
        BST() = default;
        BST(const BST&) = delete;
        BST(BST&&) = delete;
        BST& operator=(const BST&) = delete;
        BST& operator=(BST&&) = delete;

        std::size_t size() const {
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

        bool add(const T elem) {
            Compare comp;
            if (root == nullptr) {
                this->root = new Node(elem);
                return true;
            }
            if (root->value != elem) {
                if (comp(elem, root->value)) {
                    if (left == nullptr) {
                        left = new BST<T, Compare>();
                    }
                    return left->add(elem);
                } else {
                    if (right == nullptr) {
                        right = new BST<T, Compare>();
                    }
                    return right->add(elem);
                }
            } else {
                return false;
            }
        }

        bool contains(const T elem) const {
            Compare comp;
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

        std::vector<T> list() const {
            std::vector<T> list;
            if (left != nullptr) {
                std::vector<T> ret = left->list();
                list.insert(list.end(), ret.cbegin(), ret.cend());
            }
            if (root != nullptr) {
                list.push_back(root->value);
            }
            if (right != nullptr) {
                std::vector<T> ret = right->list();
                list.insert(list.end(), ret.cbegin(), ret.cend());
            }
            return list;
        }

        ~BST() {
            delete root;
            delete left;
            delete right;
        }
    };

}

#endif /* BST_H */
