%option noyywrap
%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int flag_float = 0;
// Judging whether the constant is float or not
// To decide whether there is a fractional part or not

double value(int yyleng, char *yytext)
{
    int decleng = 0, expleng = 0;
    //store the length of the string in the real and exponential parts
    char dec[100], exp[100];
    //store the string in the real and exponential parts
    int flag = 1;
    //indicate whether the current position is real or exponential parts
    for (int i = 0; i <= yyleng - 1; i++)
    {
        if (yytext[i] != 'E' && yytext[i] != 'e')
        {
            if (flag == 1)
            {
                dec[i] = yytext[i];
                decleng++;
            }
            else
            {
                exp[i - decleng - 1] = yytext[i];
                expleng++;
            }
        }
        else
        {
            flag_float = 1;
            flag = 0;
        }
    }

    double dec_value = 0, tmp = 1;
    //dec_value is the value of decimal
    for (int i = decleng - 1; i >= 0; i--)
    {
        if (dec[i] == '.')
        {
            flag_float = 1;
            dec_value /= tmp;
            tmp = 1;
        }
        else
        {
            dec_value = dec_value + tmp * (dec[i] - '0');
            //dec_value added from dec[i], with weight as tmp
            tmp *= 10;
        }
    }

    double exp_value = 0;
    tmp = 1;
    if (expleng > 0)
    {   //exp_value is the value of exponential
        for (int i = expleng - 1; i > 0; i--)
        {
            exp_value = exp_value + tmp * (exp[i] - '0');
            //exp_value added from exp[i], with weight as tmp
            tmp *= 10;
        }
        if (exp[0] == '-')
            exp_value = -exp_value;
        else
            if(exp[0] == '+')
                exp_value = exp_value;
            else
                exp_value = exp_value + tmp * (exp[0] - '0');
    }

    double result = dec_value;
    if (exp_value > 0)
        for (int i = 0; i < exp_value; i++)
            result *= 10;
    if (exp_value < 0)
        for (int i = 0; i > exp_value; i--)
            result /= 10;
    return result;
}

void display(double n_value)
{
    char s[50];
    for(int j=49; j >= 0; j--)
        s[j] = '0';
    // to solve the width of n_value for formatted output
    int flag = 49;
    sprintf(s, "%lf", n_value);
    for(int j=49; j >= 0; j--)
        if(s[j]=='0' || s[j]=='\0')
            flag--;
        else
        {
            if(s[j]=='.')
            {
                if(flag_float == 1)
                    flag++;
                else
                    flag--;
                break;
            }
            else
                break;
        }
    for(int j=0; j<=flag; j++)
        printf("%c", s[j]);
}
%}

dec             (([0-9]+)("."?)([0-9]*))|(([0-9]*)("."?)([0-9]+))
                //Consider the case that: double constant in Python can be abbreviated
exp             {dec}(E|e)(("-"|"+")?)([0-9]+)
fml             ((("+"|"-")?)({dec}|{exp}))((("+"|"-")({dec}|{exp}))*)

%%

{fml} {
    flag_float = 0;
    char n[100];
    double n_value = 0;
    int nleng = 0;
    int add = 1, i = 0;
    if (yytext[0] == '-')
    {
        add = 0;
        i = 1;
    }
    for (; i <= yyleng - 1; i++)
    {
        if (yytext[i] != '+' && yytext[i] != '-')
        {
            n[nleng] = yytext[i];
            nleng++;
        }
        else
        {
            if (((yytext[i] == '-') || (yytext[i] == '+')) && ((yytext[i - 1] == 'e') || (yytext[i - 1] == 'E')))
            {
                n[nleng] = yytext[i];
                nleng++;
                continue;
            }
            else
            {
                if (add)
                    n_value += value(nleng, n);
                else
                    n_value -= value(nleng, n);
                if (yytext[i] == '+')
                    add = 1;
                else
                    add = 0;
                nleng = 0;
            }
        }
    }
    if (add)
        n_value += value(nleng, n);
    else
        n_value -= value(nleng, n);
    display(n_value);
}
                     
%%

void main(void)
{
    yylex();
}
