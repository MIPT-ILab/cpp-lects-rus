#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct namednum {
    char *name;
    int number;
};

void fixupstrings(struct namednum *arr, int arrlen)
{
  // TODO: write your code here
}

int main()
{
    int res, records, len, i;
    struct namednum *arr;

    res = scanf("%d %d", &records, &len);
    assert((res == 2) && (records > 0) && (len > 0));
    arr = (struct namednum *) calloc(len, sizeof(struct namednum));
    assert(arr && "Not enough memory");

    for (i = 0; i < len; ++i)
        arr[i].number = i;

    for (i = 0; i < records; ++i) {
        int nrecs, j;
        char *name = (char *) calloc(21, sizeof(char));
        assert(name && "Not enough memory");
        res = scanf("%d %20s", &nrecs, name);
        assert((res == 2) && (nrecs > 0));
        for (j = 0; j < nrecs; ++j) {
            int nxt;
            res = scanf("%d", &nxt);
            assert(res == 1);
            arr[nxt].name = name;
        }
    }

    fixupstrings(arr, len);

    // break data on printout to make shallow copies inconsistent
    // skip null pointers on printout
    for (i = 0; i < len; ++i)
        if (arr[i].name) {
            printf("%d %s\n", arr[i].number, arr[i].name);
            arr[i].name[0] = '\0';
        }

    for (i = 0; i < len; ++i)
        free(arr[i].name);
    free(arr);
}