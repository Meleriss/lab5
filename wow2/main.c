#include "strings.h"
#include <stdio.h>
#include <malloc.h>

int main()
{
    char data[MAX_PATH], delim;
    if(input(data) == -1) return -1;    //Чтение файла
    char dir[20] = "/home/stud";

    printf("\tdelim:");
    scanf("%c", &delim);
    printf("\tpaths: ");
    int err = 0;    //Номер элемента в строке, где ошибка
    for(int i = 0; i < slen(data); i++){    //Проверка paths
        if(check(data, i) == -2){           //проверка на диапазон
            printf("Error boundary of the array data\n");
            return -1;
        }else 
        if(sspn(data, i, &err) == -1){         //проверка на допустимые знаки
            printf(" Error string data in %d. \n", err);
            return -1;
        }
    }
     //for(int i = 0; i < slen(data); i++)
       //  printf("%c", data[i]);
    printf("%s", data);
    printf("\n\tdir: %s\n", dir);
    process(data, delim, dir);  
    return 0;
}

int check(char *data, int i) 
{
    if (i == 0 && (slen(data) > MAX_PATH)) {
        return -2;
    } else if (data[i] == '+' || i == 0) {
        for (int j = i; data[j] != '+' && j < slen(data); j++) {
            if ((j-i) > MAX_PATH) {
                return -2;
            }    
        }
    }
    return 0;
}

int input(char *str) //Ввод
{
    FILE *in_file;
    if ((in_file = fopen("text.txt", "r")) == NULL) {
        printf("\nFile in is not open.\n");
        return -1;
    }
    fgets(str, MAX_PATH, in_file);
    fclose(in_file);
    return 0;
}

int process(char *in_str, char delim, char *dir)
{
    int i, j, k = 0;
    char str[MAX_PATH]; // new paths
    char out_str[MAX_PATH];     // Поделенный на токены
    stok(in_str, delim, out_str);
    for(i = 0; i < slen(in_str); i++){
       if(out_str[i-1] == '\0' || i == 0){ //Перескок по подстрокам
            if(scmp(out_str, i)){ //Строки равны
                for(j = 0; j < 10; j++){     //Записываем home/stud
                    str[k] = dir[j];
                    k++;
                }
                i = i+1; // пропустить тильду
            }
       }
        if(out_str[i] == '\0'){ // заменяет /0 на +
              str[k] = '+';
              k++;

         }else{
            str[k] = out_str[i];
            k++;
        }
    }
    str[k] = '\0';
    output(str);
    return 0;
}

void output(char *str){
    printf("\tnew paths: %s\n", str);
   // for(int i = 0; i < slen(str); i++)
     //   printf("%c", str[i]);
    //printf("\n");
}