module LSystems where
    
    -- Curva de Koch
    rulesKoch :: Char -> String
    rulesKoch 'F' = "F+F--F+F"
    rulesKoch '+' = "+"
    rulesKoch '-' = "-"
    rulesKoch _ = ""

    -- Curva de Koch cuadrada
    rulesKochSquare :: Char -> String
    rulesKochSquare 'F' = "F+F-F-F+F"
    rulesKochSquare '+' = "+"
    rulesKochSquare '-' = "-"
    rulesKochSquare _ = ""

    -- Koch Snowflake
    rulesKochSnowflake :: Char -> String
    rulesKochSnowflake 'F' = "F-F++F-F"
    rulesKochSnowflake '+' = "+"
    rulesKochSnowflake '-' = "-"
    rulesKochSnowflake _ = ""

    -- Koch Anti-Snowflake
    rulesKochAntiSnowflake :: Char -> String
    rulesKochAntiSnowflake 'F' = "F+F--F+F"
    rulesKochAntiSnowflake '+' = "+"
    rulesKochAntiSnowflake '-' = "-"
    rulesKochAntiSnowflake _ = ""

    -- Isla de Minkowski
    rulesMinkowski :: Char -> String
    rulesMinkowski 'F' = "F+F-F-FF+F+F-F"
    rulesMinkowski '+' = "+"
    rulesMinkowski '-' = "-"
    rulesMinkowski _ = ""

    -- Triántulo de Sierpinsky
    rulesSierpinsky :: Char -> String
    rulesSierpinsky 'F' = "F-G+F+G-F"
    rulesSierpinsky 'G' = "GG"
    rulesSierpinsky '+' = "+"
    rulesSierpinsky '-' = "-"
    rulesSierpinsky _ = ""

    -- Sierpinsky Arrowhead 
    rulesSierpinskyArrowhead :: Char -> String
    rulesSierpinskyArrowhead 'F' = "G-F-G"
    rulesSierpinskyArrowhead 'G' = "F+G+F"
    rulesSierpinskyArrowhead '+' = "+"
    rulesSierpinskyArrowhead '-' = "-"
    rulesSierpinskyArrowhead _ = ""

    -- Curva de Hilbert
    rulesHilbert :: Char -> String
    rulesHilbert 'f' = "-g>+f>f+>g-"
    rulesHilbert 'g' = "+f>-g>g->f+"
    rulesHilbert '+' = "+"
    rulesHilbert '-' = "-"
    rulesHilbert '>' = ">"
    rulesHilbert _ = ""

    -- Curva de Gosper
    rulesGosper :: Char -> String
    rulesGosper 'F' = "F-G--G+F++FF+G-"
    rulesGosper 'G' = "+F-GG--G-F++F+G"
    rulesGosper '+' = "+"
    rulesGosper '-' = "-"
    rulesGosper _ = ""
    

    lsystem :: (Char -> String) -> String -> Int -> String
    lsystem reglas f 0 = f
    lsystem reglas "F" n = lsystem reglas "G-F-G" (n - 1)
    lsystem reglas "G" n = lsystem reglas "F-G-F" (n - 1)
    lsystem reglas f n = lsystem reglas (concat (map reglas f)) (n - 1)
