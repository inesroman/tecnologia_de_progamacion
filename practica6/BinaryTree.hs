------------------------------------------------------
-- File: BinaryTree.hs
-- Autoras: Inés Román Gracia Y Alicia Lázaro Huerta
-- Fecha: 13/05/2023
------------------------------------------------------
module BinaryTree where

import Data.List (sort)

data BinaryTree a = Vacio | Nodo a (BinaryTree a) (BinaryTree a)

empty :: BinaryTree a 
empty = Vacio

leaf :: a -> BinaryTree a
leaf x = Nodo x Vacio Vacio

tree :: a -> BinaryTree a -> BinaryTree a -> BinaryTree a
tree x lc rc = Nodo x lc rc

size :: BinaryTree a -> Int
size Vacio = 0
size (Nodo _ lc rc) = 1 + size lc + size rc

tab :: Integer -> String
tab 0 = ""
tab x = ("  ") ++ tab (x - 1)

auxShow :: (Show a) => BinaryTree a -> Integer -> String
auxShow Vacio x = "<>"
auxShow (Nodo a Vacio Vacio) x = show a
auxShow (Nodo a lc rc) x = show a ++ ['\n'] ++ (tab x) ++ ("|-") ++ auxShow lc (x + 1) ++ ['\n'] ++ (tab x) ++ ("|-") ++ auxShow rc (x + 1)

instance (Show a) => Show (BinaryTree a) where
  show a = auxShow a 0

add :: Ord a => BinaryTree a -> a -> BinaryTree a
add Vacio x = Nodo x Vacio Vacio
add (Nodo a lc rc) x
  | x < a = Nodo a (add lc x) rc
  | otherwise = Nodo a lc (add rc x)


build :: Ord a => [a] -> BinaryTree a
build xs = foldl add empty xs
  where
    add t x = case t of
      Vacio -> leaf x
      Nodo y lc rc -> if x < y then Nodo y (add lc x) rc
      else Nodo y lc (add rc x)

buildBalanced :: Ord a => [a] -> BinaryTree a
buildBalanced [] = Vacio
buildBalanced [x] = leaf x
buildBalanced xs = Nodo medio (buildBalanced lc) (buildBalanced rc)
  where
    medio = head (drop (length xs `div` 2) (sort xs))
    (lc, m:rc) = splitAt (length xs `div` 2) (sort xs)

preorder :: BinaryTree a -> [a]
preorder Vacio = []
preorder (Nodo x lc rc) = x : (preorder lc ++ preorder rc)

postorder :: BinaryTree a -> [a]
postorder Vacio = []
postorder (Nodo x lc rc) = postorder lc ++ postorder rc ++ [x]

inorder :: BinaryTree a -> [a]
inorder Vacio = []
inorder (Nodo x lc rc) = inorder lc ++ [x] ++ inorder rc

balance :: Ord a => BinaryTree a -> BinaryTree a
balance Vacio = Vacio
balance t = buildBalanced (inorder t)
  where
    inorder Vacio = []
    inorder (Nodo x lc rc) = inorder lc ++ [x] ++ inorder rc

between :: Ord a => BinaryTree a -> a -> a -> [a]
between Vacio _ _ = []
between (Nodo x lc rc) xmin xmax
  | x < xmin = between rc xmin xmax
  | x > xmax = between lc xmin xmax
  | otherwise = x : (between lc xmin xmax ++ between rc xmin xmax)
