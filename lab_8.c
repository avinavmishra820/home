#include <stdio.h>
#include <string.h>
#include <time.h>
#define MAX 500

int t[MAX];

void shifttable(char p[]) {
    int i, j, m;
    m = strlen(p);
    for (i = 0; i < MAX; i++)
        t[i] = m;
    for (j = 0; j < m - 1; j++)
        t[(unsigned char)p[j]] = m - 1 - j;
}

int horspool(char src[], char p[]) {
    int i, j, k, m, n;
    n = strlen(src);
    m = strlen(p);
    printf("\nLength of text = %d", n);
    printf("\nLength of pattern = %d", m);
    i = m - 1;
    while (i < n) {
        k = 0;
        while ((k < m) && (p[m - 1 - k] == src[i - k]))
            k++;
        if (k == m)
            return i - m + 1;
        else
            i += t[(unsigned char)src[i]];
    }
    return -1;
}

int main() {
    double clk;
    clock_t starttime, endtime;
    char src[100], p[100];
    int pos;
    printf("Enter the text in which pattern is to be searched:\n");
    if (fgets(src, sizeof(src), stdin) != NULL) {
        size_t len = strlen(src);
        if (len > 0 && src[len - 1] == '\n') {
            src[len - 1] = '\0';
        }
    }
    printf("Enter the pattern to be searched:\n");
    if (fgets(p, sizeof(p), stdin) != NULL) {
        size_t len = strlen(p);
        if (len > 0 && p[len - 1] == '\n') {
            p[len - 1] = '\0';
        }
    }
    starttime = clock();
    shifttable(p);
    pos = horspool(src, p);
    endtime = clock();
    if (pos >= 0)
        printf("\nThe desired pattern was found starting from position %d", pos + 1);
    else
        printf("\nThe pattern was not found in the given text");
    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f seconds\n", clk);
    return 0;
}

