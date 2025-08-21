#include <conio.h>

int main(void)
{
    int ch;

    while (1)
    {
        ch = getch();
        if (ch == '\r')
            break;
        else
            putch(ch + 1);
    }

    return 0;
}