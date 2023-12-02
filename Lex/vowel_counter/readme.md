### Algorithm 
    Start
    Declare global variables vow_count and const_count and initialize them to 0.
    Define Lex rules:
    Recognize vowels ([aeiouAEIOU]) and increment vow_count.
    Recognize any alphabetic character ([a-zA-Z]) and increment const_count.
    In the main function:
    Open the file "file.txt" for reading.
    If the file cannot be opened, print an error message and exit.
    Set yyin (input file for lexer) to the opened file.
    Call yylex to start scanning the file.
    Print the counts of vowels and consonants.
    Define the yywrap function to indicate the end of the input.
    End
