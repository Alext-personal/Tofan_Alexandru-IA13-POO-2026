
#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE* file;
    file = fopen("ini.txt", "r");
    int sum = 0;
    char i[100];
    while (fgets(i, sizeof(i), file))
        sum+=atoi(i);
    printf("%d",sum);   
    fclose(file);
}