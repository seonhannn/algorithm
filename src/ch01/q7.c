#include <stdio.h>

void q7()
{
    int num;
    int sum = 0;

    printf("정수를 입력하세요. ");
    scanf("%d", &num);

    for (int i = 1; i <= num; i++)
    {
        printf("%d", i);
        if (i != num)
            printf(" + ");

        sum += i;
    }

    printf(" = %d", sum);
}