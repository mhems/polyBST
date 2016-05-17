module BST where

data BST a = Empty | Node a (BST a) (BST a) deriving (Show)

size :: BST a -> Int
size Empty = 0
size (Node _ l r) = 1 + (size l) + (size r)

add :: (Ord a) => BST a -> a -> BST a
add Empty item = Node item Empty Empty
add b@(Node a l r) item
  | a == item = b
  | item < a = Node a (add l item) r
  | otherwise = Node a l (add r item)

contains :: (Ord a) => BST a -> a -> Bool
contains Empty _ = False
contains (Node a l r) item
  | a == item = True
  | item < a  = contains l item
  | otherwise = contains r item

list :: BST a -> [a]
list Empty = []
list (Node a l r) = (list l) ++ [a] ++ (list r)
