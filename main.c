#include <stdio.h>
#include "strings.h"
#include <string.h>

void input(char *paths, char *delim, char *dir)
{
    //printf("delim: ");
    //scanf("%s", delim);
    //printf("user name: ");
    //scanf("%s", name);
    printf("path: ");
    scanf("%s", paths);
    printf("dir: ");
    scanf("%s", dir);
}

int check_dir(char *dir) 
{
    char *home = "/home/";
    if(strstr(dir, home) == 0) 
		return -1;
     else {
        char *symb = "!@#?.,^$&~%%*()[]{}\"\'\\:;><` \0";
        while(dir) {
            if(sspn(dir, symb) == 0)
                return 0;
            else
                return -1;
        }
    }
}

int check_paths(char *paths) 
{
    char *symb = "!@#?.,^$&~%%*()[]{}\"\'\\:;><` \0";
        while(dir) {
            if(sspn(dir, symb) == 0)
                return 0;
            else
                return -1;
}

/*void process(char *paths, char *delim, char *dir)
{
    char *path = stok(paths, delim);
    int i = 0;
    while(path) {
        if(path[i] == '~' && path[i+1] == '/')
           
        path = stok(NULL, delim);
}*/

int main()
{    
    char delim[10];
    char dir[50];
    char paths[350];

    input(paths, delim, dir);

    if(check_dir(dir) == -1)
        printf("Incorrect dir\n");
    if(check_dir(dir) == 0)
        printf("Right\n");
    if(check_paths(paths) == -1)
        printf("Incorrect paths\n");
    if(check_paths(paths) == 0)
        printf("Right\n");

    return 0;
}
