#include <stdio.h>
typedef struct data
{
    int m;
    char n;
    float g;
} data;
typedef struct meta
{
    int m : 5;
    int n : 4;
    int y;
} meta;

int main(int argc, char *argv[])
{
    printf("Size of int %lu \n Size of data %lu \n Size of meta %lu \n", sizeof(int), sizeof(data), sizeof(meta));
    printf(" arr = %lu \n &arr = %lu \n", argv, &argv);
    while (argc--)
    {
        printf("You entered %s \n", argv[argc]);
    }
    int arr[100] = {};
    printf("arr = %lu \n &arr = %lu \n", arr, &arr);
}