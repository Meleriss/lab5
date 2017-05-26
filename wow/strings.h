#ifndef STRINGS_H
#define STRINGS_H

#define MAX_PATH 260

int slen(char *str); // Длина строки
int sspn(char *str, int begin, int *err_bond);  // Допустимость символов
int scmp(char *s1, int index); // Сравнение строк
int scpy(char *in, char *out);    // Копирование строк 
int stok(char *in, char delim, char *out);   // Разделяет 

int check(char *data, int i);	//Проверка
int input(char *str);		//Ввод
void output(char *str);		//Вывод
int process(char *in_str, char delim, char *out_str, char *dir); //Преобразование

#endif
