// 4개의 정수 중 최솟값 반환
int min4(int a, int b, int c, int d)
{
    int min = a;

    if (b < min)
        min = b;

    if (c < min)
        min = c;

    if (d < min)
        min = d;

    return min;
}