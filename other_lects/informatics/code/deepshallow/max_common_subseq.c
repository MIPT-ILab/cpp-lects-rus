#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int maxlen(int *s1, int len1, int *s2, int len2)
{
  // TODO: write your code here
}

int main()
{
    int res, i;
    int fstlen, sndlen;
    int *fstarr = NULL, *sndarr = NULL;

    res = scanf("%d %d", &fstlen, &sndlen);
    assert(res == 2);

    if (fstlen > 0) {
        fstarr = (int *) calloc(fstlen, sizeof(int));
        assert(fstarr && "Not enough memory");
    }
    if (sndlen > 0) {
        sndarr = (int *) calloc(sndlen, sizeof(int));
        assert(sndarr && "Not enough memory");
    }

    for (i = 0; i < fstlen; ++i) {
        res = scanf("%d", &fstarr[i]);
        assert(res == 1);
    }

    for (i = 0; i < sndlen; ++i) {
        res = scanf("%d", &sndarr[i]);
        assert(res == 1);
    }

    res = maxlen(fstarr, fstlen, sndarr, sndlen);

    printf("%d\n", res);

    free(fstarr);
    free(sndarr);

    return 0;
}