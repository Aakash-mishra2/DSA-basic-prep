// C program to illustrate fgets()
#include <stdio.h>
#define MAX 15
#include <string.h>
bool stringComparision(char *s1, char *s2)
{
    int i = 0;
    while (s1[i] != '\0' and s2[i] != '\0')
    {
        if (s1[i] != s2[i])
        {
            return false;
            break;
        }
        i++;
    }
    return true;
}
int stringLength(char *st1, int i = 0, int len = 0)
{
    while (st1[i] != '\0')
    {
        len++;
        i++;
    }
    return len + 1;
}
int main()
{
    // defining buffer
    char buf[MAX];
    char buf2[MAX];
    // using fgets to take input from stdin
    fgets(buf, MAX, stdin);
    fgets(buf2, MAX, stdin);
    printf("string is: %s\n", buf);
    printf("second string is %s\n", buf2);
    // strcat(buf, buf2);
    printf("%d", stringComparision(buf, buf2));
    printf("\n %d", stringLength(buf2));
    return 0;
}