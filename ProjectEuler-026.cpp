#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define debug(x) cout << x << endl;
/////////////////////////////////////////////////////////////////
const int MAX = 10000+7;

int getDigit(int d)
{
	int seen[d+7] = {0};
	int n = 1;
	int cnt = 1;
	while(n > 0)
	{
		if(seen[n] > 0)
			return cnt - seen[n];
		seen[n] = cnt;
		n *= 10;
		n %= d;
		cnt++;
	}
	return 0;
}
int main()
{	
	int ans[MAX] = {0};
	int highest = 1;
	int pos = 3;
	ans[3] = 3;
	for(int i = 4; i < MAX; ++i)
	{
		int k = getDigit(i);
		if(k <= highest)
			ans[i] = pos;
		else
		{
			ans[i] = ans[i-1];
			highest = k;
			pos = i;
		}
	}
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int n;
		scanf("%d",&n);
		printf("%d\n",ans[n]);
	}
}
