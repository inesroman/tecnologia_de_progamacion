import SVG(savesvg)
import Tplot
import LSystems


main = do
    savesvg "cuadrado" (tplot (1, 90, (0,0), 90) ">+>+>+>+")
    savesvg "triángulo" (tplot (1, 120, (0,0), 0) ">+>+>+")
    savesvg "círculo"  (tplot (1, 1, (0,0), 0) ">+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+>+")
    savesvg "Curva de Koch" (tplot (1, 60, (0,0), 300) (lsystem rulesKoch "F" 4)) -- bien
    savesvg "Curva de Koch cuadrada" (tplot (1, 90, (0,0), 270) (lsystem rulesKochSquare "F" 4)) -- bien
    savesvg "Koch Snowflake" (tplot (1, 60, (0,0), 0) (lsystem rulesKochSnowflake "F++F++F" 5)) -- bien
    savesvg "Koch Anti-Snowflake" (tplot (1, 60, (0,0), 180) (lsystem rulesKochAntiSnowflake "F++F++F" 5)) -- bien
    savesvg "Isla de Minkowski" (tplot (1, 90, (0,0), 0) (lsystem rulesMinkowski "F+F+F+F" 5)) -- bien
    savesvg "Triángulo de Sierpinsky" (tplot (1, 120, (0,0), 180) (lsystem rulesSierpinsky "F-G-G" 5)) -- bien
    savesvg "Sierpinsky Arrowhead" (tplot(1,60,(0,0),0) (lsystem rulesSierpinskyArrowhead "F" 8)) -- bien
    savesvg "Curva de Hilbert" (tplot (1, 90, (0,0), 180) (lsystem rulesHilbert "f" 5)) -- bien
    savesvg "Curva de Gosper" (tplot (1, 60, (0,0), 0) (lsystem rulesGosper "F" 4))