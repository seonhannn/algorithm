// 세개의 정수 중 중앙값 반환
int med3(int n1, int n2, int n3)
{
    int med = n1;

    if (med < n2 && med < n3) // n1이 최솟값인 경우
    {
        if (n2 < n3)
        {
            med = n2;
        }
        else
        {
            med = n3;
        }
    }
    else if (med > n2 && med > n3) // n1이 최댓값인 경우
    {
        if (n2 < n3)
        {
            med = n3;
        }
        else
        {
            med = n2;
        }
    }

    return med;
}