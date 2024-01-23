module Tplot where
    import Turtle

    tplot :: Turtle -> String -> [Position]
    tplot _ [] = []
    tplot t@(_,_,pos,_) (a:as) = case a of
        '>' -> pos : tplot (moveTurtle t Forward) as
        '+' -> pos : tplot (moveTurtle t TurnRight) as
        '-' -> pos : tplot (moveTurtle t TurnLeft) as
        l | elem l ['A'..'Z'] -> pos : tplot (moveTurtle t Forward) as
        _ -> tplot t as