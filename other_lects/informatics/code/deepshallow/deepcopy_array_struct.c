#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct namednum {
    char *name;
    int number;
};

void namednumcpy(struct namednum *dst, const struct namednum *src,
                 int srclen) {
  // TODO: write your code here
}

int main()
{
    int res, len, i;
    struct namednum *arr = NULL, *cparr = NULL;

    res = scanf("%d", &len);
    assert(res == 1);

    assert(len > 0);
    arr = (struct namednum *) calloc(len, sizeof(struct namednum));
    assert(arr);
    cparr = (struct namednum *) calloc(len, sizeof(struct namednum));
    assert(cparr);

    for (i = 0; i < len; ++i) {
        arr[i].name = calloc(21, sizeof(char));
        assert(arr[i].name && "Not enough memory");
        res = scanf("%20s %d", arr[i].name, &arr[i].number);
        assert(res == 2);
    }

    namednumcpy(cparr, arr, len);

    // zeroing string in old array to break shallow copies
    for (i = 0; i < len; ++i)
        arr[i].name[0] = '\0';

    for (i = 0; i < len; ++i)
        printf("%s %d\n", cparr[i].name, cparr[i].number);

    for (i = 0; i < len; ++i) {
      free(arr[i].name);
      free(cparr[i].name);
    }

    free(arr);
    free(cparr);
    return 0;
}