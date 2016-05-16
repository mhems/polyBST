#!/usr/bin/env python3

import bst

def verify(expected, actual):
    if expected != actual:
        print("expected %s, received %s" % (expected, actual))
        return False
    return True

if __name__ == '__main__':
    b = bst.BST(lambda i, j : i - j)
    verify(0, len(b));
    verify([], b.list())
    b.add(5)
    verify(True, 5 in b)
    verify(1, len(b))
    verify([5], b.list())
    for i in range(10, -1, -1):
        b.add(i)
    verify(11, len(b))
    verify(list(range(0, 11)), b.list())
    for i in range(0, 11):
        verify(True, i in b)
    verify(False, 11 in b)
