#include "strings.h"
#include <stdlib.h>

int slen(char *str)
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        count++;
    }
    return count;
}

char *str_stok = NULL;
char *stok(char *str, const char *delim) //разбиение на токены
{
    if (str != NULL)
        str_stok = str;

    if (str_stok == NULL)
        return NULL;

    for (int i = 0; str_stok[i] != 0; i++) {
        for (int j = 0; delim[j] != 0; j++) {
            if (str_stok[i] == delim[j]) {
                str_stok[i] = 0;
                char *result = str_stok;
                str_stok = str_stok + i + 1;
                return result;
            }
        }
    }
    if (str_stok != NULL) {
        char *result = str_stok;
        str_stok = NULL;
        return result;
    } else {
        return NULL;
    }
}

int sspn(const char *str, const char *symb) //принадлежность заданному множеству
{
    int count = 0;
    for (int i = 0; str[i] != 0; i++) {
        for (int j = 0; symb[j] != 0; j++) {
            if (str[i] == symb[j]) {
                count++;
            }
        }
    }
    return count;
}

int scmp(const char *str1, const char *str2) //сравнение строк
{
    while (*str1 && *str2 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    if (*str1 > *str2)
        return 1;
    if (*str1 < *str2)
        return -1;
    return 0;
}

char *scpy(char *des, const char *src) //копирование строк
{
    int i;
    for (i = 0; src[i] != 0; i++) {
        des[i] = src[i];
    }
    des[i] = 0;
    return des; 
}

int sstr(const char *str1,const char *str2)
{
    int i, j = 0, k;
    for(i = 0; str1[i] != '\0'; i++)
    {
        for(i = j, k = 0; str2[k] != '\0' && str1[j] == str2[k]; j++, k++);
            if(k > 0 && str2[k] == '\0')
                return -1;
    }
    return 0;
}
