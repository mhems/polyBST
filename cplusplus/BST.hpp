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
            explicit Node(T val) : value(val) { }
        };

        Node *root = nullptr;
        BST<T> *left = nullptr, *right = nullptr;

    public:
        BST() { }
        BST(const BST&) = delete;
        BST(BST&&) = delete;
        BST& operator=(const BST&) = delete;
        BST& operator=(BST&&) = delete;
        std::size_t size() const;
        bool add(T elem);
        bool contains(T elem) const;
        std::vector<T> list() const;
        ~BST();
    };
}

#endif /* BST_H */
