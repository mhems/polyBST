import System.Exit
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
         r1 <- sequence [verify 0 $ size a,
                         verify 0 $ length $ list a]
         let b = add a 5
         r2 <- sequence [verify 1 $ size b,
                         verify True $ contains b 5,
                         verify [5] $ list b]
         let c = foldr (flip add) b [0..10]
         r3 <- sequence [verify 11 $ size c,
                         verify [0..10] $ list c]
         r4 <- sequence $ map (\i -> verify True (contains c i)) [0..10]
         r5 <- verify False $ contains c 11
         let status = all id $ r5 : concat [r1, r2, r3, r4]
         exitWith $ if status then ExitSuccess else ExitFailure 1
         return ()
