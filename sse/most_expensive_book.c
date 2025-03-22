#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    char* p;
    int point;
    printf("input start point:\n");
    scanf("%d",&point);
    printf("input a string:\n");
    scanf("%s",s);
    while(point--)
        p--;
    printf("%s",p);
}