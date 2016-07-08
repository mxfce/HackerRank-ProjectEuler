#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define debug(x) cout << x << endl;
const int MAX = 5000+7;
static int ans[MAX];
static int status[MAX];
int getDigit(vector<int> vec)
{
	int cnt = 0;
	for(int i = vec.size()-1; i >= 0; --i)
		cnt++;
	return cnt;
}
void fibo()
{
	vector<int> a;
	vector<int> b;
	a.push_back(0);
	b.push_back(1);
	int nDigit = 0,cnt = 1;
	while(nDigit < MAX)
	{
		vector<int> tmp = b;
		int j,carry = 0;
		for(j = 0; j < a.size(); ++j)
		{
			int sum = a[j] + b[j] + carry;
			b[j] = sum % 10;
			carry = sum / 10;
		}
		while(carry > 0)
		{
			if(j >= b.size())
			{
				b.push_back(carry%10);
				carry /= 10;
			}
			else
			{
				int sum = b[j] + carry;
				b[j] = sum % 10;
				carry = sum / 10;
			}		
		}
		nDigit = getDigit(b);
		if(status[nDigit] == 0)
		{
			ans[nDigit] = cnt;
			status[nDigit] = 1;
		}
		a = tmp;
		cnt++;
	}
}		
int main()
{	
	fibo();
	int tc;
	cin >> tc;
	while(tc--)
	{
		int n;
		cin >> n;
		cout << ans[n] + 1 << endl;
	}
}
