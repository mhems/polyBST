import Control.Monad
import BST

comp :: (Ord a) => a -> a -> Ordering
comp a b
  | a < b = LT
  | a == b = EQ
  | otherwise = GT

verify :: (Eq a, Show a) => a -> a -> IO Bool
verify a b = if a /= b
               then do
                 putStr "expected "
                 putStr $ show a
                 putStr ", received "
                 putStr $ show b
                 putStrLn ""
                 return (False)
               else do return (True)

main :: IO()
main = do
         let a = Empty comp
         _ <- verify 0 $ size a
         verify 0 $ length $ list a
         let b = add a 5
         _ <- verify 1 $ size b
         _ <- verify True $ contains b 5
         _ <- verify [5] $ list b
         let c = foldr (flip add) b [0..10]
         _ <- verify 11 $ size c
         _ <- verify [0..10] $ list c
         _ <- forM [0..10] (\i -> verify True (contains c i))
         _ <- verify False $ contains c 11
         return ()
