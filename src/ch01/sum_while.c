#include <stdio.h>

// 1부터 num까지의 합을 구하고 출력
void sum_while()
{
    int i = 1;
    int sum = 0;
    int num;

    printf("정수를 입력해주세요. ");
    scanf("%d", &num);

    while (i <= num)
    {
        sum += i;
        i++;
    }

    printf("1부터 %d까지 합은 %d입니다.", num, sum);
    return;
}

void sum_for()
{
    int num;
    int sum = 0;

    printf("정수를 입력해주세요. ");
    scanf("%d", &num);

    for (int i = 1; i <= num; i++)
    {
        sum += i;
    }

    printf("1부터 %d까지의 합은 %d입니다.", num, sum);
    return;
}