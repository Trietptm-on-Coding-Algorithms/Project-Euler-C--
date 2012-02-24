#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MAXN 100

using namespace std;

void printarr(int n, long a[][MAXN]) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j <= i; j++)
            printf("%ld ", a[i][j]);
        printf("\n");
    }
}

long solve (int n, int a[][MAXN]) {
    long retval = -1;
    int i = 0,
        j = 0;
    long b[MAXN + 1][MAXN];
    memset(b, -1, (MAXN + 1) * (MAXN) * sizeof(long));
    b[1][1] = a[0][0];
    for (i = 2; i <= n; i++)
        for (j = 1; j <= i; j++) {
            if (b[i-1][j] == -1)
                b[i][j] = a[i-1][j-1] + b[i-1][j-1];
            else if (b[i-1][j-1] == -1)
                b[i][j] = a[i-1][j-1] + b[i-1][j];
            else
                b[i][j] = max(a[i-1][j-1] + b[i-1][j], a[i-1][j-1] + b[i-1][j-1]);
        }
    for (j = 1; j <= n; j++)
        retval = max(retval, b[n][j]);
    //printarr(n+1,b);
    return retval;
}

int main (void) {
    int n, i, j;
    int a[MAXN][MAXN];
    printf("Number of rows = ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        for (j = 0; j <= i; j++)
            scanf("%d", &a[i][j]);
    }
    printf("\nans = %ld\n", solve(n, a));
    return 0;
}
