#!/usr/bin/env python3

class BST:
    """Binary Search Tree container"""

    def __init__(self, comp):
        """Initialize empty BST"""
        self.comp = comp
        self.node = None
        self.left = None
        self.right = None

    def __len__(self):
        """Return number of elements in BST"""
        sum = 0
        if self.node is not None:
            sum += 1
            if self.left is not None:
                sum += len(self.left)
            if self.right is not None:
                sum += len(self.right)
        return sum

    def add(self, elem):
        """Add elem to BST"""
        if self.node is None:
            self.node = elem
            return True
        result = self.comp(elem, self.node)
        if result != 0:
            if result < 0:
                if self.left is None:
                    self.left = BST(self.comp)
                return self.left.add(elem)
            else:
                if self.right is None:
                    self.right = BST(self.comp)
                return self.right.add(elem)
        else:
            return False

    def __contains__(self, elem):
        """Return True iff elem in BST"""
        if self.node is None:
            return False
        result = self.comp(elem, self.node)
        if result == 0:
            return True
        elif result < 0:
            return self.left is not None and elem in self.left
        else:
            return self.right is not None and elem in self.right

    def list(self):
        """Return contents of BST in-order as list"""
        list = []
        if self.left is not None:
            list.extend(self.left.list())
        if self.node is not None:
            list.append(self.node)
        if self.right is not None:
            list.extend(self.right.list())
        return list
