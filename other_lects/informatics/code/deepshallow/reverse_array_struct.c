#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

struct Test {
    long long ll;
    double d;
    char c;
};

void reverse(void *arr, int size, int n)
{
  // TODO: write your code here
}

int main()
{
    int res, len, i;
    struct Test *arr = NULL;

    res = scanf("%d", &len);
    assert(res == 1);

    if (len > 0) {
        arr = (struct Test *) calloc(len, sizeof(struct Test));
        assert(arr && "Not enough memory");
    }

    for (i = 0; i < len; ++i) {
        res = scanf("%lld %lf %c", &arr[i].ll, &arr[i].d, &arr[i].c);
        assert(res == 3);
    }

    reverse(arr, sizeof(struct Test), len);

    for (i = 0; i < len; ++i)
        printf("%lld %.6g %c\n", arr[i].ll, arr[i].d, arr[i].c);

    free(arr);
    return 0;
}