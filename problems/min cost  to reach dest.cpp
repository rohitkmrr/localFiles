// A Dynamic Programming based solution to find min cost
// to reach station N-1 from station 0.
#include<bits/stdc++.h>
#include<climits>
using namespace std;

#define INF INT_MAX
#define N 4

// This function returns the smallest possible cost to
// reach station N-1 from station 0.
int minCost(int cost[][N])
{
	// dist[i] stores minimum cost to reach station i
	// from station 0.
	int dist[N];
	for (int i=0; i<N; i++)
	dist[i] = INF;
	dist[0] = 0;

	// Go through every station and check if using it
	// as an intermediate station gives better path
	for (int i=0; i<N; i++)
	for (int j=i+1; j<N; j++)
		if (dist[j] > dist[i] + cost[i][j])
			dist[j] = dist[i] + cost[i][j];

	return dist[N-1];
}

int minCost1(int cost[][N])
{
    int DP[N] = {INT_MAX,INT_MAX,INT_MAX,INT_MAX};
   /* cout<<" Default array is "<<endl;
    for(int i=0;i<N;i++)
    {
        cout<<DP[i]<<" ";
    }
    cout<<endl;*/
    DP[0] = 0;
    for(int i=1;i<N;i++)
    {
        for(int j = 0;j<i;j++)
        {
            DP[i] = min(DP[i],DP[j]+ cost[j][i]);
        }
    }
    cout<<endl;
    for(int i=0;i<N;i++)
    {
        cout<<DP[i]<<" ";
    }
    cout<<endl;
    return DP[N-1];

}

// Driver program to test above function
int main()
{
	int cost[N][N] = { {0, 150, 300, 900},
					{INF, 0, 400, 500},
					{INF, INF, 0, 700},
					{INF, INF, INF, 0}
					};
	cout << "The Minimum cost to reach station "
		<< N << " is " << minCost1(cost);
    cout<<endl<<minCost(cost);
	return 0;
}

