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
void setComposite()
{
	for(int i = 2; i <= sqrt(MAX); ++i)
	{
		if(isComposite[i] == 0)
			for(int j = i+i; j <= MAX; j += i)
				isComposite[j] = 1;
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
	for(int a = -1*n; a <= n; ++a)
		for(int b = -1*n; b <= n; ++b)
		{
			int cnt = 0;
			while(isComposite[abs(cnt*cnt + a*cnt + b)] == 0)
				cnt++;
			if(cnt > maxCnt)
			{
				maxA = a;
				maxB = b;
				maxCnt = cnt;
			}
		}
	printf("%d %d\n",maxA,maxB);
	return 0;
}