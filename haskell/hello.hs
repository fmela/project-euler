main = do
    putStrLn "Hello, what's your name?"
    name <- getLine
    putStrLn ("Hello, " ++ name ++ ". You rock!")
