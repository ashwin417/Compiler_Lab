#include <stdio.h>
#include <ctype.h>
#include <string.h>

char input[100];
int i;

int E();
int EP(int val);
int T();
int TP(int val);
int F();

void main()
{
    printf("\nRecursive descent parsing for the following grammar\n");
    printf("\nE->TE'\nE'->+TE'/@\nT->FT'\nT'->*FT'/@\nF->(E)/ID\n");
    printf("\nEnter the string to be checked:");
    scanf("%s", input);
    i = 0;
    int result = E();
    if (result != -1 && input[i] == '\0')
        printf("\nString is accepted\nResult=%d", result);
    else
        printf("\nString is not accepted");
}

int E()
{
    int val = T();
    if (val != -1)
    {
        return EP(val);
    }
    else
    {
        return -1;
    }
}

int EP(int val)
{
    if (input[i] == '+')
    {
        i++;
        int t_val = T();
        if (t_val != -1)
        {
            return EP(val + t_val);
        }
        else
        {
            return -1;
        }
    }
    else
    {
        return val;
    }
}

int T()
{
    int val = F();
    if (val != -1)
    {
        return TP(val);
    }
    else
    {
        return -1;
    }
}

int TP(int val)
{
    if (input[i] == '*')
    {
        i++;
        int f_val = F();
        if (f_val != -1)
        {
            return TP(val * f_val);
        }
        else
        {
            return -1;
        }
    }
    else
    {
        return val;
    }
}

int F()
{
    if (input[i] == '(')
    {
        i++;
        int e_val = E();
        if (e_val != -1 && input[i] == ')')
        {
            i++;
            return e_val;
        }
        else
        {
            return -1;
        }
    }
    else if (isdigit(input[i]))
    {
        int val = 0;
        while (isdigit(input[i]))
        {
            val = val * 10 + (input[i] - '0');
            i++;
        }
        return val;
    }
    else
    {
        return -1;
    }
}
