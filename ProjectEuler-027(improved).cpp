#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define debug(x) cout << x << endl;
const int MAX = 8002000+5; // the highest value n,a and b can be is 2000 
static int isComposite[MAX+7];
vector<int> prime;
void setComposite()
{
	for(int i = 2; i <= sqrt(MAX); ++i)
	{
		if(isComposite[i] == 0)
		{
			if(i <= 2000)
				prime.push_back(i);
			for(int j = i + i; j <= MAX; j += i)
				isComposite[j] = 1;
		}
	}
}

bool isPrime(int n)
{
	if(isComposite[n] == 0)
		return true;
	return false;
}
int main()
{
	int n,maxA = 0,maxB = 0,maxCnt = 0;
	scanf("%d",&n);
	setComposite();
	for(int a = -1 * n; a <= n; ++a)
	{
		int i = 0;
		while(i < prime.size() && prime[i] <= n)
		{

			int cnt = 0, b = prime[i];
			while(isComposite[abs(cnt * cnt + a * cnt + b)] == 0)
				cnt++;
			if(cnt > maxCnt)
			{
				maxA = a;
				maxB = b;
				maxCnt = cnt;
			}
			i++;
		}
	}
	printf("%d %d\n",maxA,maxB);
	return 0;
}