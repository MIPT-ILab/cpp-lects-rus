#include <stdio.h>

int main(void)
{
    char c[4] = { 'A', 'B', 'C', 'D' };
    char d[4] = { 'W', 'X', 'Y', 'Z' };

    printf("c[0] is '%c'\n", c[0]);

    d[4] = 'Z'; /* Overflow that overwrites c[0] */

    printf("c[0] is '%c'\n", c[0]);

    return 0;
}
