#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 构建next数组（前缀表）
void getNext(char *pattern, int *next)
{
    int len = strlen(pattern);
    next[0] = -1; // 初始条件
    int i = 0, j = -1;
    while (i < len - 1)
    { // 注意循环终止条件
        if (j == -1 || pattern[i] == pattern[j])
        {
            i++;
            j++;
            next[i] = j; // 当前字符匹配，记录跳转位置
        }
        else
        {
            j = next[j]; // 不匹配时回溯
        }
    }
}

// KMP搜索算法
int kmpSearch(char *text, char *pattern)
{
    int tLen = strlen(text);
    int pLen = strlen(pattern);
    if (pLen == 0)
        return 0; // 处理空模式串的情况

    int *next = (int *)malloc(pLen * sizeof(int));
    getNext(pattern, next);

    int i = 0, j = 0; // i主串指针，j模式串指针
    while (i < tLen && j < pLen)
    {
        // j==-1表示需要从模式串头部重新匹配
        if (j == -1 || text[i] == pattern[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j]; // 根据next数组跳转
        }
    }

    free(next);
    return (j == pLen) ? (i - j) : -1;
}
