/*
Algorithm 7a - Breadth First Search
Print all the nodes reachable from a given starting node in a digraph using BFS method.
*/

#include <stdio.h>
#include <conio.h>

void breadthFirstSearch(int a[10][10], int n, int source, int s[100]);

int main() {
    int a[10][10], n, i, j, source, s[10];

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);

    printf("Enter the source node: ");
    scanf("%d", &source);

    for (i = 1; i <= n; i++)
        s[i] = 0;

    printf("The Breadth First Search Traversed is:\n");

    breadthFirstSearch(a, n, source, s);

    return 0;
}

void breadthFirstSearch(int a[10][10], int n, int source, int s[100]) {
    int f = 1, r = 1, q[10], i;

    q[r] = source;
    printf(" %d ", source);

    r++;

    s[source] = 1;

    while (f <= r) {
        source = q[f];
        f++;

        for (i = 1; i <= n; i++) {
            if (s[i] == 0 && a[source][i] == 1) {
                q[r++] = i;
                s[i] = 1;
                printf(" %d ", i);
            }
        }
    }
}

/*
OUTPUT:
Enter the number of nodes: 6
Enter the cost adjacency matrix:
0 1 1 0 0 0
1 0 0 1 0 0
1 0 0 0 1 0
0 1 0 0 0 1
0 0 1 0 0 1
0 0 0 1 1 0
Enter the source node: 5
The Breadth First Search Traversed is:
 5  3  6  1  4  2
*/
