#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void сalculating_value () {
    FILE* input = fopen ("postfix_notation.txt", "r");
    FILE* output = fopen ("rez.dat", "w+");

    int length = lenFile(input);
    char* str = (char*) calloc (length, sizeof(char));
    int pop_value = 0;
    int result = 0;
    int x = 0;
    int y = 0;
    char resultstr[10] = {};

    fread(str, sizeof (char), length, input);
    for (int i = 0; i < length; i++) {
        if (str[i] == '\n' ) {
            result = pop_int (&top);

            intoa(result, resultstr);
            strcat (resultstr, "\n");

            fprintf(output, resultstr);
            strcpy(resultstr, "\0");
            continue;
        }

        if (str[i] != '\n') {
            if (str[i] - '0' >= 0) {
                push_int(&top, str[i] - '0');
            } else if (str[i] == '^') {
                x = pop_int (&top);
                y = pop_int (&top);
                push_int (&top, y^x);
            } else if (str[i] == '*') {
                x = pop_int (&top);
                y = pop_int (&top);
                push_int (&top, y*x);
            } else if (str[i] == '/') {
                x = pop_int (&top);
                y = pop_int (&top);
                push_int (&top, y/x);
            } else if (str[i] == '+') {
                x = pop_int (&top);
                y = pop_int (&top);
                push_int (&top, y+x);
            } else if (str[i] == '-') {
                x = pop_int (&top);
                y = pop_int (&top);
                push_int (&top, y-x);
            } else {
                printf ("SPANKING\n");
            }
        }
    }
    fclose (input);
    fclose (output);
}

int lenFile(FILE *text)
{
    fseek(text, 0, SEEK_END);
    int length =  ftell(text);
    fseek(text, 0, SEEK_SET);

    return length;    
}

void itoa (int n, char s[])
{
    int i, sign;
 
    if ((sign = n) < 0)  /* записываем знак */
        n = -n;          /* делаем n положительным числом */
    i = 0;
    do {       /* генерируем цифры в обратном порядке */
        s[i++] = n % 10 + '0';   /* берем следующую цифру */
    } while ((n /= 10) > 0);     /* удаляем */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

void reverse (char s[])
{
    int i, j;
    char c;

    for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
