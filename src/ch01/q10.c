#include <stdio.h>

void q10()
{
    int a = 0;
    int b = 0;

    printf("a의 값: ");
    scanf("%d", &a);

    do
    {
        printf("b의 값: ");
        scanf("%d", &b);
        if (b <= a)
            printf("a보다 큰 값을 입력하세요!\n");
    } while (b <= a); // b > a이면 탈출

    printf("b의 값: %d\n", b);
    printf("b - a는 %d입니다.", b - a);
}