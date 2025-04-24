#include <stdio.h>
#include <stdlib.h>
#include "bf.c"
#include "kmp.c"

int main()
{
    char *S = "abcdefghijklmnopqrstuvwxyz";
    char *T = "def";
    int pos = 0;
    int res = Index_BF(S, T, pos);
    printf("模式串在主串中的起始位置%d\n", res);
    char text[] = "ABABABAC";
    char pattern[] = "ABABAC";
    int pos2 = kmpSearch(text, pattern);
    if (pos2 != -1)
    {
        printf("模式串在主串中的起始位置：%d\n", pos);
    }
    else
    {
        printf("未找到匹配\n");
    }
    return 0;
}
