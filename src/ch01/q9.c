#include <stdio.h>

// 정수 num1, num2를 포함하여 그 사의 모든 정수의 합을 구하고 출력
void q9(int num1, int num2)
{
    int sum = 0;
    sum = (num1 + num2) + ((num1 + num2) / 2);
    int max = num1 > num2 ? num1 : num2;
    int min = num1 < num2 ? num1 : num2;
    printf("%d, %d 사이의 합은 %d입니다.", min, max, sum);
}