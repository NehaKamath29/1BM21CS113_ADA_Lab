#include<stdio.h>
#include<stdlib.h>

int s[100], j, res[100]; 
void AdjacencyMatrix(int a[][100], int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    return;
}
void dfs(int u, int n, int a[][100]) 
{ 
    int v;
    s[u] = 1;
    for (v = 0; v < n ; v++) {
        if (a[u][v] == 1 && s[v] == 0) {
            dfs(v, n, a);
        }
    }
    j += 1;
    res[j] = u; // Store every dead node in the array
}
void topological_order(int n, int a[][100]) 
{ 
    int i, u;
    for (i = 0; i < n; i++) {
        s[i] = 0;
    }
    j = 0;
    for (u = 0; u < n; u++) {
        if (s[u] == 0) {
            dfs(u, n, a);
        }
    }

}
int main() {
    int a[100][100], n, i, j;

    printf("Enter number of vertices:\n"); /* READ NUMBER OF VERTICES */
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    AdjacencyMatrix(a, n);
    topological_order(n, a);
    printf("The topological sort order is:\n");
    for (i = n; i >=1; i--) /*Inside the array 'res', we are adding the nodes that become dead from first to last.
                              But topological sort is the reverse order.So we are printing the array backwards.*/ 
    {
        printf("%d ", res[i]);
    }
    return 0;
}