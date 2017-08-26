// A C program to match wild card characters
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
// The main function that checks if two given strings
// match. The first string may contain wildcard characters
bool match(char *first, char * second)
{
	// If we reach at the end of both strings, we are done
	if (*first == '\0' && *second == '\0')
		return true;

	// Make sure that the characters after '*' are present
	// in second string. This function assumes that the first
	// string will not contain two consecutive '*'
	if (*first == '*' && *(first+1) != '\0' && *second == '\0')
		return false;

	// If the first string contains '?', or current characters
	// of both strings match
	if (*first == '?' || *first == *second)
		return match(first+1, second+1);

	// If there is *, then there are two possibilities
	// a) We consider current character of second string
	// b) We ignore current character of second string.
	if (*first == '*')
		return match(first+1, second) || match(first, second+1);
	return false;
}

bool fn(string txt, string pat, int i, int j, int m, int n)
{
    if(i>=m && j>=n)
        return true;
    if(pat[j] == '*' && j<n-1 && i==m-1)
        return false;
    if(pat[j] == '?' || pat[j] == txt[i])
        return fn(txt, pat, i+1, j+1, m, n);
    if(pat[j] == '*')
    {
        return fn(txt, pat, i, j+1, m,n) || fn(txt, pat, i+1, j, m, n);
    }
}

bool match1(string txt, string pat)
{
    int m = txt.length();
    int n = pat.length();
    int i=0,j=0;
    return fn(txt, pat, i,j,m,n);
}

// A function to run test cases
void test(string first,  string second)
{ match1(second,first )? puts("Yes"): puts("No"); }

// Driver program to test above functions
int main()
{
	test( "g*ks", "geeks"); // Yes
	test("ge?ks*", "geeksforgeeks"); // Yes
	test("g*k", "gee"); // No because 'k' is not in second
	test("*pqrs", "pqrst"); // No because 't' is not in first
	test("abc*bcd", "abcdhghgbcd"); // Yes
	test("abc*c?d", "abcd"); // No because second must have 2
							// instances of 'c'
	test("*c*d", "abcd"); // Yes
	test("*?c*d", "abcd"); // Yes
	return 0;
}

