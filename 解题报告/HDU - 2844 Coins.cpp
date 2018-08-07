/*
	���������
		��һ��������һ���ֱ�ֻ֪������ֱ���ۼ۲�����m����֪ÿһ��Ӳ�ҵļ۸񣬺�������������ϳ������ּ۸񲻳���m.
	����˼·��
		��ȫ�������⣺
			����Ʒ������ת���ɶ����ƣ�����0-1����������������⣬���dp[i]����ѯ������۸�Ϳ�����ϡ�
*/
#include<bits/stdc++.h>
using namespace std;

const int maxn = 100 + 5;
const int maxd = 1e6 + 5;

int a[maxn];
int c[maxn];
int dp[maxd];
int main()
{
	int n, m;
	while (1)
	{
		bool vis[maxd] = { 0 };
		for (int i = 0; i < maxd; i++)
		{
			dp[i] = -INT_MAX;
		}
		dp[0] = 0;
		cin >> n >> m;
		if (n == 0 && m == 0)
		{
			return 0;
		}
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++)
		{
			cin >> c[i];
		}
		for (int i = 1; i <= n; i++)
		{
			int num = min(c[i], m / a[i]);
			for (int k = 1; num > 0; k *= 2)
			{
				if (k>num) k = num;
				num -= k;
				for (int j = m; j >= k * a[i]; j--)
				{
					dp[j] = max(dp[j], dp[j - k * a[i]] + k * a[i]);
				}
			}
		}
		int cnt = 0;
		for (int i = 1; i <= m; i++)
		{
			if (dp[i]>0) cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
}
