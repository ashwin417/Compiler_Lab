%{
    int flag = 0;
%}

%%
[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,} { 
    printf("Email accepted: %s\n", yytext); 
    flag = 1;
}
[^\n]+ { 
    flag = 0; 
    if (!flag) {
        printf("Email not accepted: %s\n", yytext);
        flag = 0; 
    }
}

%%

int main(int argc, char **argv) {
    FILE *file;
    file = fopen("file.txt", "r");
    if (!file) {
        printf("Could not open the file\n");
        exit(0);
    }

    yyin = file;
    yylex();
   
    fclose(file);
    printf("\n");
    return (0);
}

int yywrap() {
    return (1);
}
