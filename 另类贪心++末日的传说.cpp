#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[50001];
	long long n, m;
	cin >> m >> n;
	int mins = 1, maxs = m;
	for (long long i = 1; i <= m; i++)
	{
		long long t = (long long)(m - i - 1)*(m - i) / 2;
		if (t >= n)
		{
			a[mins++] = i;
		}
		else
		{
			a[maxs--] = i;
			n -= (maxs - mins + 1);//��һ������maxs�ȼ���1����Ҫ�����1�ӻ���
		}
	}
	for (int i = 1; i <= m; i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}
