/*
	����ܹؼ��������Ҳ������κ����϶�����ɵ�һ�������⣬����������
	���������
		����n���¼�����ÿ���¼��л��ѵ�ʱ�������һ��������ÿ���¼����в�ͬ������
	ÿ�������в�ͬ��ѡ�񷽷������������Ŀ�������ڸ���ʱ����ʹ��һ���������
	����˼·��
		ֻ������ÿ�ֲ�����״̬ת�Ʒ��̾Ϳ��Խ����ˣ�˼·���Ƿ��鱳����
*/
#include<bits/stdc++.h>
using namespace std;

const int maxn = 100 + 5;

int cost[maxn];
int val[maxn];
int dp[2][maxn];
int n, T;
int atlestone(int a, int b)
{
	for (int j = 0; j <= T; j++) dp[b][j] = -0x3f3f3f3f;
	for (int i = 0; i < a; i++)
	{
		for (int j = T; j >= cost[i]; j--)
		{
			dp[b][j] = max(dp[b][j], max(dp[b ^ 1][j - cost[i]] + val[i], dp[b][j - cost[i]] + val[i]));
		}
	}
}
int nomoreone(int a, int b)
{
	for (int j = 0; j <= T; j++) dp[b][j] = dp[b ^ 1][j];
	for (int i = 0; i < a; i++)
	{
		for (int j = T; j >= cost[i]; j--)
		{
			dp[b][j] = max(dp[b][j], dp[b ^ 1][j - cost[i]] + val[i]);
		}
	}
}
int free(int a, int b)
{
	for (int j = 0; j <= T; j++) dp[b][j] = dp[b ^ 1][j];
	for (int i = 0; i < a; i++)
	{
		for (int j = T; j >= cost[i]; j--)
		{
			dp[b][j] = max(dp[b][j], max(dp[b ^ 1][j - cost[i]] + val[i], max(dp[b][j - cost[i]] + val[i], dp[b ^ 1][j])));
		}
	}
}
int main()
{
	while (scanf("%d%d", &n, &T) != EOF)
	{
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j <= T; j++)
			{
				if (i == 1)
					dp[i][j] = 0;
				else
					dp[i][j] = -INT_MAX;
			}
		}
		for (int i = 0; i < n; i++)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			for (int j = 0; j < a; j++)
			{
				scanf("%d%d", cost + j, val + j);
			}
			if (b == 0)
			{
				atlestone(a, i % 2);
			}
			if (b == 1)
			{
				nomoreone(a, i % 2);
			}
			if (b == 2)
			{
				free(a, i % 2);
			}
		}
		if (dp[(n - 1) % 2][T]<0)
			cout << -1 << endl;
		else
			cout << dp[(n - 1) % 2][T] << endl;
	}
	return 0;
}
