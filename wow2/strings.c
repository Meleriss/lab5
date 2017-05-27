#include "strings.h"
#include <stdio.h>



int slen(char *str) // Длина строки +++
{
    int i;
    for(i = 0; str[i] != '\0'; i++);
    return i;
}

int sspn(char *str, int begin, int *err_bond)  // Допустимость символов
{
    for (int i = begin; (str[i] != '+' && str[i] != '\0'); i++){
        if (str[i] == '\\' || str[i] == '*' || str[i] == '?' 
        || str[i] == '\"' || str[i] == '<' || str[i] == '>' || str[i] == '|'){
            *err_bond = i;
            return -1;
        } 
    }
    return 0;
}

int scmp(char *s1, int index) // Сравнение строк
{
    if(s1[index] == '~' && s1[index+1] == '/')
        return 1;
    return 0;
}

int scpy(char *in, char *out)    // Копирование строк +
{
    if (slen(in) > slen(out)) 
        return 0;
    int i;
    for(i = 0; in[i] != '\0'; i++)
        out[i] = in[i];
    out[i] = '\0';
    return 1;
}

int stok(char *in, char delim, char *out)   // Разделяет 
{
    int i;
    for (i = 0; i < slen(in); i++) {
        if (in[i] != delim) {
            out[i] = in[i];
        } else {
            out[i] = '\0';
        }
    }
    out[i] = '\0';
    return 0;
}