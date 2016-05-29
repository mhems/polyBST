#include <algorithm>
#include <iostream>
#include <vector>

#include "BST.hpp"

using std::find;
using std::sort;
using std::size_t;
using std::cout;
using std::endl;
using std::vector;

template <typename T>
static std::ostream& operator<<(std::ostream &out, const vector<T>& v) {
    out << "[";
    auto itr = v.cbegin();
    const auto &end = v.cend();
    if (itr != end) {
        out << *itr++;
    }
    while (itr != end) {
        out << ", " << *itr++;
    }
    out << "]";
    return out;
}

template <typename U , typename V>
static bool verify(U expected, V actual) {
    if (expected != actual) {
        cout << "expected " << expected << ", received " << actual << endl;
        return false;
    }
    return true;
}

static bool verify(int expected, size_t actual) {
    return verify(static_cast<size_t>(expected), actual);
}

int main(int, char **) {
    bool status = true;
    BST::BST<int> b;
    vector<int> exp;
    status |= verify(0, b.size());
    status |= verify(exp, b.list());
    b.add(5);
    exp.push_back(5);
    status |= verify(true, b.contains(5));
    status |= verify(1, b.size());
    status |= verify(exp, b.list());
    for (int i = 10; i >= 0; --i) {
        b.add(i);
        if (find(exp.cbegin(), exp.cend(), i) == exp.cend()) {
            exp.push_back(i);
        }
    }
    status |= verify(11, b.size());
    sort(exp.begin(), exp.end());
    status |= verify(exp, b.list());
    for (int i = 0; i < 11; ++i) {
        status |= verify(true, b.contains(i));
    }
    status |= verify(false, b.contains(11));
    return !status;
}
