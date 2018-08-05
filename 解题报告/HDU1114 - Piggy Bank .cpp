/*
	���������
		����洢�޵Ĵ�С���͸���Ӳ�ҵļ�ֵ�ʹ�С����֪��װ������洢�޵�ʱ�����е���С��ֵ�Ƕ��١�
	����˼·��
		����һ����ȫ���������ģ���⡣���ǰ�ģ���е�max,,����min�ͺ��ˡ�

*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 10005;
struct coin
{
	int val;
	int weight;
};
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	int e, f;

	while (T--)
	{
		int n;
		coin a[505];
		cin >> e >> f;
		int vol = f - e;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			int c, b;
			cin >> c >> b;
			if (b <= vol)
			{
				a[i].val = c;
				a[i].weight = b;
			}
		}
		int dp[maxn];
		for (int i = 0; i < maxn; i++)
		{
			dp[i] = 0x3f3f3f3f;
		}
		dp[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = a[i].weight; j <= vol; j++)
			{
				dp[j] = min(dp[j], dp[j - a[i].weight] + a[i].val);
			}
		}
		if (dp[vol] == 0x3f3f3f3f)
		{
			cout << "This is impossible." << endl;
		}
		else
			cout << "The minimum amount of money in the piggy-bank is " << dp[vol] << '.' << endl;
	}

	return 0;
}
