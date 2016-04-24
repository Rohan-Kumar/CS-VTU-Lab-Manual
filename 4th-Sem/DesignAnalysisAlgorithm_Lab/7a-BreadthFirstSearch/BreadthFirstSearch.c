/*
Algorithm 7a - Breadth First Search

Print all the nodes reachable from a given starting node in a digraph using BFS method.
*/

#include <stdio.h>
#include <conio.h>

int breadthFirstSearch(int a[10][10], int n, int source, int s[10]);

int main() {
	int a[10][10], n, source, s[10], i, j;

	printf("Enter the number of nodes: ");
	scanf("%d", &n);

	printf("Enter the adjacency matrix:\n");
	for (i = 1; i <= n; i++)
		for (j = 1;  j <= n; j++)
			scanf("%d", &a[i][j]);

	for (i = 1; i <= n; i++)
		s[i] = 0;

	printf("Enter the source node: ");
	scanf("%d", &source);

	breadthFirstSearch(a, n, source, s);

	return 0;
}

int breadthFirstSearch(int a[10][10], int n, int source, int s[10]) {
	int f = 1, r = 1, q[10], i;

	q[r++] = source;
	s[source] = 1;

	while (f < r) {
		source = q[f++];

		for (i = 1; i <= n; i++) {
			if ( s[i] == 0 && a[source][i] == 1 ) {
				q[r++] = i;
				s[i] = 1;
			}
		}
	}

	printf("The elements according to Breadth First Search are:\n");
	for (i = 1; i <= n; i++)
		printf(" %d ", q[i]);

	return 0;
}