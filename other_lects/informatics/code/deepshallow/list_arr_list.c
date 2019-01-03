#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *next;
    int n;
};

struct node *mergelists(struct node **arr, int arrlen)
{
  // TODO: write your code here
}

int main()
{
    int res, len, i;
    struct node **arr;
    struct node *top;

    res = scanf("%d", &len);
    assert(res == 1);
    assert(len > 0);

    arr = calloc(len, sizeof(struct node *));

    for (i = 0; i < len; ++i) {
        int lstlen, j;
        struct node *tmp;

        res = scanf("%d", &lstlen);
        assert(res == 1);
        if (lstlen == 0)
            continue;

        arr[i] = calloc(1, sizeof(struct node));
        tmp = arr[i];

        for (j = 0; j < lstlen; ++j) {
            int newelem;
            res = scanf("%d", &newelem);
            assert((res == 1) && (newelem >= 0));
            tmp->n = newelem;
            if (j != lstlen - 1) {
                tmp->next = calloc(1, sizeof(struct node));
                tmp = tmp->next;
            }
        }
    }

    top = mergelists(arr, len);

    while (top != NULL) {
        struct node *old = top;
        printf("%d\n", top->n);
        top = top->next;
        free(old);
    }

    free(arr);
    return 0;
}