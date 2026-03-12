#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int num(int i)
{
    int count = 0;
    int x = i;
    while (x != 0)
    {
        int y = x % 10;
        if (y == 2)
            count++;
        x /= 10;
    }

    return count;
}

int main() {
    int a, b;
    int ret = 0;
    scanf("%d %d", &a, &b);
    for (int i = a; i <= b; i++)
    {
        ret += num(i);
    }
    printf("%d", ret);
    return 0;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")