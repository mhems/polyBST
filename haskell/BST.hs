module BST where

type Compare a = a -> a -> Ordering
data BST a = Empty (Compare a) | Node a (BST a) (BST a) (Compare a)

size :: BST a -> Int
size (Empty _) = 0
size (Node _ l r _) = 1 + (size l) + (size r)

add :: (Ord a) => BST a -> a -> BST a
add (Empty c) item = Node item (Empty c) (Empty c) c
add b@(Node a l r c) item
  | result == EQ = b
  | result == LT = Node a (add l item) r c
  | otherwise = Node a l (add r item) c
    where result = c item a

contains :: (Ord a) => BST a -> a -> Bool
contains (Empty _) _ = False
contains (Node a l r c) item
  | result == EQ = True
  | result == LT = contains l item
  | otherwise = contains r item
    where result = c item a

list :: BST a -> [a]
list (Empty _) = []
list (Node a l r _) = (list l) ++ [a] ++ (list r)
