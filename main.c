#include <stdio.h>
#include "strings.h"

void input(char *paths, char *delim, char *dir)
{
    //printf("delim: ");
    //scanf("%s", delim);
    //printf("user name: ");
    //scanf("%s", name);
    //printf("path: ");
    //scanf("%s", paths);
    printf("dir: ");
    scanf("%s", dir);
}

int check_dir(char *dir) 
{
    //char *home = "/home/";
    //    if(sstr(dir, home) == 0) 
	//	    return -1;

    char *symb = "!@#?.,^$&~%%*()[]{}\"\'\\:;><` \0";
    char *path = stok(dir, "/");
    while(path) {
        if(!(sspn(path, symb) == slen(path)))
            return 0;
        path = stok(NULL, "/");
    }
    return -1;
}

//int check_paths(char *paths) 
//{

//}

void process(char *paths, char *delim, char *dir)
{
    char *path = stok(paths, delim);
    int i = 0;
    while(path) {
        if(path[i] == '~' && path[i+1] == '/')
           
        path = stok(NULL, delim);
}

int main()
{    
    char delim[10];
    char dir[50];
    char paths[350];

    input(paths, delim, dir);

    if(check_dir(dir) == -1)
        printf("Incorrect dir\n");
    if(check_dir(dir) == 0)
        printf("EEEEE\n");
 //   if(check_paths(paths) == -1)
 //       printf("Incorrect paths\n");

    return 0;
}
