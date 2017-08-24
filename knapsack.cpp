// A Dynamic Programming based solution for 0-1 Knapsack problem
#include<stdio.h>

// A utility function that returns maximum of two integers
int max(int a, int b) { return (a > b)? a : b; }

// Returns the maximum value that can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n)
{
int i, w,j;
int K[n+1][W+1];
int k1[W+1][n+1];
// Build table K[][] in bottom up manner
for (w = 0; w <= W; w++)
{
	for (j = 0; j <= n; j++)
	{
		if (j==0 || w==0)
			K[w][j] = 0;
		else if (wt[j-1] <= w)
				K[w][j] = max(val[j-1] + K[w-wt[j-1]][j-1], K[w][j-1]);
		else
				K[w][j] =K[w][j-1];
	}
}

return K[W][n];
}

int main()
{
	int val[] = {60, 100, 120};
	int wt[] = {10, 20, 30};
	int W = 50;
	int n = sizeof(val)/sizeof(val[0]);
	printf("%d", knapSack(W, wt, val, n));
	return 0;
}
