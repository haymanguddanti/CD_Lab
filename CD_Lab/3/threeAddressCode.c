#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int n, addr = 100;
    char str[10];
    while (1)
    {
        printf("Enter your choice:\n");
        printf("1.Assignment\n2.Arithematic\n3.Conditional\n4.Exit\n");
        scanf("%d", &n);
        if (n == 1)
        {
            printf("Enter the expression with assignment operator:");
            scanf("%s", str);
            printf("temp=%c\n", str[2]);
            printf("%c=temp\n", str[0]);
        }
        else if (n == 2)
        {
            printf("Enter the expression with arithmetic operator:");
            scanf("%s", str);
            printf("temp=%c%c%c\n", str[2], str[3], str[4]);
            printf("%c=temp\n", str[0]);
        }
        else if (n == 3)
        {
            printf("Enter the expression with relational operator:");
            scanf("%s", str);
            printf("%d if %s goto %d\n", addr, str, addr + 3);
            addr++;
            printf("%d T:=0\n", addr);
            addr++;
            printf("%d goto %d\n", addr, addr + 2);
            addr++;
            printf("%d T:=1\n", addr);
        }
        else if (n == 4)
            exit(0);
        else
            printf("Enter valid choice");
    }
}
