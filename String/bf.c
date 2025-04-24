#include <string.h>
#include <stdio.h>
int Index_BF(char *S, char *T, int pos)
{
    int i = pos; // S的起始位置
    int j = 0;   // T的起始位置
    while (i < strlen(S) && j < strlen(T))
    {
        if (S[i] == T[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 1; // S的起始位置后移
            j = 0;         // T的起始位置归零
        }
    }
    if (j == strlen(T))
        return i - strlen(T); // 返回匹配成功的位置
    else
        return -1; // 匹配失败
}