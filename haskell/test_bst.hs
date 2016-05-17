import BST

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
         let a = Empty
         verify 0 $ size a
         -- verify [] $ list a
         let b = add a 5
         verify 1 $ size b
         verify True $ contains b 5
         verify [5] $ list b
         -- let c = foldr add b [0..10]
         -- verify 11 $ size c
         -- verify [0..10] $ list c
         -- verify False $ contains c 11
         return ()
