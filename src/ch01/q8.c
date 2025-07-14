#include <stdio.h>

// 가우스 덧셈 이용하여 정수 합 구하고 출력 - n(n+1)/2
void q8()
{
    int num = 0;
    int sum = 0;

    printf("정수를 입력하세요. ");
    scanf("%d", &num);

    if (num != 1)
    {
        sum = num * (num + 1) / 2;
    }
    else
    {
        sum = 1;
    }

    printf("1부터 %d까지의 합은 %d입니다.", num, sum);
}