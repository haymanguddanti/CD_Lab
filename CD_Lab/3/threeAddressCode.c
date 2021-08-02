#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void pm();
void plus();
void div1();
int i, ch, j, l, addr = 100;
char ex[10], exp1[10], exp12[10], exp3[10], id1[5], op[5], id2[5];
int main()
{
    while (1)
    {
        printf("\n1.assignment\n2.arithmetic\n3.relational\n4.Exit\nEnter the choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the expression with assignment operator:");
            scanf("%s", exp1);
            l = strlen(exp1);
            exp3[0] = '\0';
            i = 0;
            while (exp1[i] != '=')
            {
                i++;
            }
            strncat(exp3, exp1, i);
            strrev(exp1);
            exp12[0] = '\0';
            strncat(exp12, exp1, l - (i + 1));
            strrev(exp12);
            printf("Three address code:\ntemp=%s\n%s=temp\n", exp12, exp3);
            break;
        case 2:
            printf("\nEnter the expression with arithmetic operator:");
            scanf("%s", ex);
            strcpy(exp1, ex);
            l = strlen(exp1);
            exp12[0] = '\0';
            for (i = 0; i < l; i++)
            {
                if (exp1[i] == '+' || exp1[i] == '-')
                {
                    if (exp1[i + 2] == '/' || exp1[i + 2] == '*')
                    {
                        pm();
                        break;
                    }
                    else
                    {
                        plus();
                        break;
                    }
                }
                else if (exp1[i] == '/' || exp1[i] == '*')
                {
                    div1();
                    break;
                }
            }
            break;
        case 3:
            printf("Enter the expression with relational operator");
            scanf("%s%s%s", id1, op, id2);
            if (((strcmp(op, "<") == 0) || (strcmp(op, ">") == 0) || (strcmp(op, "<=") == 0) || (strcmp(op, ">=") == 0) || (strcmp(op, "==") == 0) || (strcmp(op, "!=") == 0)) == 0)
                printf("Expression is error");
            else
            {
                printf("\n%d\tif %s%s%s goto %d", addr, id1, op, id2, addr + 3);
                addr++;
                printf("\n%d\t T:=0", addr);
                addr++;
                printf("\n%d\t goto %d", addr, addr + 2);
                addr++;
                printf("\n%d\t T:=1", addr);
            }
            break;
        case 4:
            exit(0);
        }
    }
}
void pm()
{
    strrev(exp1);
    j = l - i - 1;
    strncat(exp12, exp1, j);
    strrev(exp12);
    printf("Three address code:\ntemp=%s\ntemp1=%c%ctemp\n", exp12, exp1[j + 1], exp1[j]);
}
void div1()
{
    strncat(exp12, exp1, i + 2);
    printf("Three address code:\ntemp=%s\ntemp1=temp%c%c\n", exp12, exp1[i + 2], exp1[i + 3]);
}
void plus()
{
    strncat(exp12, exp1, i + 2);
    printf("Three address code:\ntemp=%s\ntemp1=temp%c%c\n", exp12, exp1[i + 2], exp1[i + 3]);
}
