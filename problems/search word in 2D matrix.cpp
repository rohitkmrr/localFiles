// C++ programs to search a word in a 2D grid
#include<bits/stdc++.h>
using namespace std;

// Rows and columns in given grid
#define R 3
#define C 14

// For searching in all 8 direction
int x[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int y[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

// This function searches in all 8-direction from point
// (row, col) in grid[][]
bool search2D(char grid[R][C], int row, int col, string word)
{
	// If first character of word doesn't match with
	// given starting point in grid.
	if (grid[row][col] != word[0])
        return false;

	int len = word.length();

	// Search word in all 8 directions starting from (row,col)
	for (int dir = 0; dir < 8; dir++)
	{
		// Initialize starting point for current direction
		int k, rd = row + x[dir], cd = col + y[dir];

		// First character is already checked, match remaining
		// characters
		for (k = 1; k < len; k++)
		{
			// If out of bound break
			if (rd >= R || rd < 0 || cd >= C || cd < 0)
				break;

			// If not matched, break
			if (grid[rd][cd] != word[k])
				break;

			// Moving in particular direction
			rd += x[dir], cd += y[dir];
		}

		// If all character matched, then value of must
		// be equal to length of word
		if (k == len)
			return true;
	}
	return false;
}

// Searches given word in a given matrix in all 8 directions
void patternSearch(char grid[R][C], string word)
{
	// Consider every point as starting point and search
	// given word
	for (int row = 0; row < R; row++)
	for (int col = 0; col < C; col++)
		if (search2D(grid, row, col, word))
			cout << "pattern found at " << row << ", "
				<< col << endl;
}

bool fn(char grid[R][C], string word, int X[], int Y[], int dir, int word_i, int size, int i, int j, bool visited[][C])
{
    if(word_i >= size)
    {
        return true;
    }
    if(i>=R || j>= C)
    {
        return false;
    }
    if(dir != -1)
    {
        int newX = i + X[dir];
        int newY = j + Y[dir];
        if(grid[newX][newY] == word[word_i] && !visited[newX][newY])
        {
            visited[newX][newY] = true;
            if( fn(grid, word, X, Y, dir, word_i+1, size, newX, newY, visited))
            {
                 visited[newX][newY] = false;
                return true;
            }
            else{
                 visited[newX][newY] = false;
                return false;
            }
        }
        else return false;
    }
    for(int k= 0; k<8; k++)
    {
        int newX = i + X[k];
        int newY = j + Y[k];
        if(grid[newX][newY] == word[word_i]  && !visited[newX][newY])
        {
            visited[newX][newY] = true;
            if(fn(grid, word, X, Y, k, word_i+1, size, newX, newY, visited))
            {
                 visited[newX][newY] = false;
                return true;
            }
            else
            {
                 visited[newX][newY] = false;
                return false;
            }
        }
    }
    visited[i][j] = false;
}

void patternSearch1(char grid[R][C], string word)
{
    int X[] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int Y[] = {-1, 0,  1,  1, 1, 0,-1, -1};
    bool visited[R][C];
    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++)
            visited[i][j] = false;
    int dir = -1;
    int size = word.length();
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            if(grid[i][j] == word[0])
            {
                if( fn(grid, word, X, Y, dir, 1, size, i, j, visited))
                {
                    cout<<"Found at "<<i<<" "<<j<<endl;
                }
                cout<<"Now visited matrix is "<<endl;
                for(int i=0;i<R;i++)
                {
                    for(int j=0;j<C;j++)
                        cout<<visited[i][j]<<" ";
                    cout<<endl;
                }
            }
        }
    }

}

// Driver program
int main()
{
	char grid[R][C] = {"GEEKSFORGEEKS",
					"GEEKSQUIZGEEK",
					"IDEQAPRACTICE"
					};

	patternSearch(grid, "GEEKS");
	cout << endl;
	patternSearch1(grid, "GEEKS");
	//patternSearch(grid, "EEE");
	return 0;
}

