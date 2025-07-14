#include <stdio.h>

// 정수 입력받고 자릿수 출력
void q11()
{
    int num = 0;
    int i = 1;

    printf("정수를 입력하세요. ");
    scanf("%d", &num);

    while (num / 10 > 0)
    {
        num /= 10;
        i++;
    }

    printf("그 수는 %d자리입니다.", i);
}