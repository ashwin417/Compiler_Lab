### Algorithm 
      Start
      Declare a global variable flag and initialize it to 0.
      Define Lex rules:
      Recognize email addresses with the pattern [a-z . 0-9]+@[a-z]+".com"|".in".
      If the pattern matches, set flag to 1.
      In the main function:
      Open the file "file.txt" for reading.
      If the file cannot be opened, print an error message and exit.
      Set yyin (input file for lexer) to the opened file.
      Call yylex to start scanning the file.
      Check the value of flag:
      If flag is 1, print "email Accepted."
      If flag is 0, print "email Not Accepted."
      Define the yywrap function to indicate the end of the input.
      End
