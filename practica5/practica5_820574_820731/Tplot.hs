------------------------------------------------------
-- File: Tplot.hs
-- Autoras: Inés Román Gracia Y Alicia Lázaro Huerta
-- Fecha: 21/04/2023
------------------------------------------------------
module Tplot where

import Turtle

tplot :: Turtle -> String -> [Position]
tplot _ [] = []
tplot turtle@(_, _, pos, _) (c:cs) = case c of
       '>' -> pos : tplot (moveTurtle turtle Forward) cs
       '+' -> pos : tplot (moveTurtle turtle TurnRight) cs
       '-' -> pos : tplot (moveTurtle turtle TurnLeft) cs
       c | elem c ['A'..'Z'] -> pos : tplot (moveTurtle turtle Forward) cs
       _ -> tplot turtle cs


