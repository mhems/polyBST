#!/usr/bin/env bash

ghc --make BST.hs test_bst.hs -o test
./test
