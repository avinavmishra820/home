#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int max(int x, int y) {
    return (x > y) ? x : y;
}

void knap(int n, int w[], int value[], int m, int v[10][10]) {
    int i, j;
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= m; j++) {
            if (i == 0 || j == 0)
                v[i][j] = 0;
            else if (j < w[i])
                v[i][j] = v[i - 1][j];
            else
                v[i][j] = max(v[i - 1][j], value[i] + v[i - 1][j - w[i]]);
        }
    }
    
    printf("Knapsack table:\n");
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= m; j++) {
            printf("%d\t", v[i][j]);
        }
        printf("\n");
    }
}

int main() {
    double clk;
    clock_t starttime, endtime;
    int v[10][10], n, i, j, w[10], value[10], m;
    
    printf("Enter the number of items:\n");
    scanf("%d", &n);
    
    printf("Enter the weights of %d items:\n", n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
    }
    
    printf("Enter the values of %d items:\n", n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &value[i]);
    }
    
    printf("Enter the capacity of the basket:\n");
    scanf("%d", &m);
    
    starttime = clock();
    knap(n, w, value, m, v);
    endtime = clock();
    
    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;
    
    printf("Optimal solution for the knapsack problem is %d\n", v[n][m]);
    printf("The runtime is %f seconds\n", clk);
    
    return 0;
}

