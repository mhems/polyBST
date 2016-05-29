#!/usr/bin/env python3

import sys
import bst

def verify(expected, actual):
    if expected != actual:
        print("expected %s, received %s" % (expected, actual))
        return False
    return True

if __name__ == '__main__':
    status = True
    b = bst.BST(lambda i, j : i - j)
    status |= verify(0, len(b));
    status |= verify([], b.list())
    b.add(5)
    status |= verify(True, 5 in b)
    status |= verify(1, len(b))
    status |= verify([5], b.list())
    for i in range(10, -1, -1):
        b.add(i)
    status |= verify(11, len(b))
    status |= verify(list(range(0, 11)), b.list())
    for i in range(0, 11):
        status |= verify(True, i in b)
    status |= verify(False, 11 in b)
    sys.exit(not status)
