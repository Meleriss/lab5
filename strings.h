#ifndef STRINGS_H
#define STRINGS_S

int slen(char *str);

char *stok(char *str,const char *delim); 

int sspn(const char *str, const char *symb);

int scmp(const char *str1, const char *str2);

char *scpy(char *des, const char *src);

int sstr(const char *str1, const char *str2);

#endif
