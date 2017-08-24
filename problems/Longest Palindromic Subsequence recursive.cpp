
#include<bits/stdc++.h>
#include<string.h>
using namespace std;
// A utility function to get max of two integers
int max (int x, int y) { return (x > y)? x : y; }

// Returns the length of the longest palindromic subsequence in seq
int lps(char *seq, int i, int j)
{
// Base Case 1: If there is only 1 character
if (i == j)
	return 1;

// Base Case 2: If there are only 2 characters and both are same
if (seq[i] == seq[j] && i + 1 == j)
	return 2;

// If the first and last characters match
if (seq[i] == seq[j])
	return lps (seq, i+1, j-1) + 2;

// If the first and last characters do not match
return max( lps(seq, i, j-1), lps(seq, i+1, j) );
}

void fn(char *seq, int i, int j, int &res, int len)
{
    if(i>j)
        return;
    if(i==j)
    {
        len++;
        res = max(res, len);
        return;
    }
    if(seq[i] == seq[j])
    {
        len+=2;
        res = max(res, len);
        fn(seq, i+1, j-1, res, len);
    }
    else
    {
        fn(seq, i+1, j, res, len);
        fn(seq, i, j-1, res, len);
    }
}

int lps1(char *seq, int i,int j)
{
    int res = 0,len =0;
    fn(seq, i,j, res,len);
    return res;
}

/* Driver program to test above functions */
int main()
{
	char seq[] = "BBABCBCAB";
	int n = strlen(seq);
	cout<<lps(seq, 0, n-1)<<endl;
	printf ("The length of the LPS is %d", lps1(seq, 0, n-1));
	getchar();
	return 0;
}
