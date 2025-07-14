#include <stdio.h>

// 입력받은 정수의 음수, 0, 양수 판단하여 출력
void sign()
{
    int num;

    printf("정수를 입력해주세요. ");
    scanf("%d", &num);

    if (num < 0)
        printf("입력하신 정수 %d(은)는 음수입니다.", num);
    else if (num > 0)
        printf("입력하신 정수 %d(은)는 양수입니다.", num);
    else
        printf("입력하신 정수 %d(은)는 0입니다.", num);
}

void sign2()
{
    int num;

    printf("정수를 입력해주세요. ");
    scanf("%d", &num);

    const char *sign = (num > 0) ? "양수" : (num < 0) ? "음수"
                                                      : "0";

    printf("입력하신 정수 %d(은)는 %s입니다.\n", num, sign);
}