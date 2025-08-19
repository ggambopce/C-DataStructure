#include <stdio.h>

void hanoi(int n, char a, char b, char c);

int main(void)
{
    int disc = 3;

    printf("Hanoi Tower problem\n");
    hanoi(disc, 'A', 'B', 'C');

    return 0;
}

void hanoi(int n, char a, char b, char c)
{
    if (n > 0)
    {
        hanoi(n - 1, a, c, b);
        printf("원판%d : 탑%c에서 탑%c로 이동\n", n, a, c);
        hanoi(n - 1, b, a, c);
    }
}