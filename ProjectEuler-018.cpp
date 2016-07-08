#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define debug(x) cout << x << endl;
/////////////////////////////////////////////////////////
int ans = 0;
int sum = 0;
void printVec(vector<vector<int>> itr)
{
	for(int i = 0; i < 4; ++i)
	{
		for(int j = 0; j <= i; ++j)
			cout << itr[i][j] << " ";
		cout << endl;
	}
}
void findMax(vector<vector<int>> itr,int SIZE,int i,int j)
{
	sum += itr[i][j];
	ans = max(sum,ans);
	if(i < SIZE)
	{
		findMax(itr,SIZE,i+1,j);
		sum -= itr[i+1][j];
	}
	if(i< SIZE && j < SIZE)
	{
		findMax(itr,SIZE,i+1,j+1);
		sum -= itr[i+1][j+1];
	}
}
int main()
{	
	int tc;
	cin >> tc;
	while(tc--)
	{
		vector<vector<int>> tree;
		int SIZE;
		cin >> SIZE;
		for(int i = 0; i < SIZE; ++i)
			tree.push_back(vector<int>());
		for(int i = 0; i < SIZE; ++i)
			for(int j = 0; j <= i; ++j)	
			{
				int k;
				cin >> k;
				tree[i].push_back(k);
			}

		findMax(tree,SIZE-1,0,0);
		cout << ans << endl;
		sum = 0;
		ans = 0;
	}
}
