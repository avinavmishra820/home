#include<stdio.h>
#include<time.h>

void dfs(int arr[10][10] , int n , int source , int visited[10]){


visited[source] = 1;

for(int v = 0 ; v<n ; v++){
if(arr[source][v]  && !visited[v]){

        printf("%d --> %d " , source+1 , v+1);

        dfs(arr, n, v , visited);


}

}
}

int main()
{
    int a[10][10], n, s, visited[10] = {0};
    clock_t starttime, endtime;

    printf("\nDEPTH FIRST SEARCH\n");
    
    // Get number of lands (vertices)
    printf("\nEnter number of Lands to be surveyed: ");
    scanf("%d", &n);

    // Get the adjacency matrix
    printf("\nEnter the adjacency matrix:\n");
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    // Get the starting land (vertex)
    printf("\nEnter the starting Land number: ");
    scanf("%d", &s);

    printf("\nVertices reached from the given vertex are...\n");

    starttime = clock();
    dfs(a, n, s - 1, visited);  // Start DFS traversal from the specified source
    endtime = clock();

    printf("\nRuntime: %f seconds\n", (double)(endtime - starttime) / CLOCKS_PER_SEC);

    return 0;
}
