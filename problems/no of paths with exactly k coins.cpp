// A Naive Recursive C++ program to count paths with exactly
// 'k' coins
#include <bits/stdc++.h>
#define R 3
#define C 3
using namespace std;

// Recursive function to count paths with sum k from
// (0, 0) to (m, n)
int pathCountRec(int mat[][C], int m, int n, int k)
{
	// Base cases
	if (m < 0 || n < 0) return 0;
	if (m==0 && n==0) return (k == mat[m][n]);

	// (m, n) can be reached either through (m-1, n) or
	// through (m, n-1)
	return pathCountRec(mat, m-1, n, k-mat[m][n]) +
		pathCountRec(mat, m, n-1, k-mat[m][n]);
}

void pathCountRec1(int mat[][C], int i, int j, int k, int &res)
{
    if( i == 0 && j == 0)
    {   if(k-mat[i][j] == 0)
            res++;
        return;
    }
    if(k<0)
    {
        return;
    }
    if(i<0 || j<0)
    {
        return;
    }
    pathCountRec1(mat, i-1, j, k-mat[i][j], res);
    pathCountRec1(mat, i, j-1, k-mat[i][j], res);

}


// A wrapper over pathCountRec()
int pathCount(int mat[][C], int k)
{
	//return pathCountRec(mat, R-1, C-1, k);
	int res = 0;
    pathCountRec1(mat, R-1, C-1, k, res);
    return res;
}



// Driver program
int main()
{
	int k = 12;
	int mat[R][C] = { {1, 2, 3},
					{4, 6, 5},
					{3, 2, 1}
				};
	cout << pathCount(mat, k);
	return 0;
}

