/*
	���������
		��������Tom��Ҫ�ӿΣ�����������ѧУ��ʱ����С��������k�ڿΣ�����ѧУ��ʱ��Ϊ���ĵ�һ�ڿε����һ��
	�ε�ʱ���������ܹ�Ҫ��n��ĿΣ�������n�����Ͽε����ʱ��Ϊ���١�
	����˼·��
		�ȶ��Ͽ�ʱ�����Ԥ���������ÿ���Ͽ���i�ڿ�Ҫ�ϵ���Сʱ�䣬������һ�����鱳�������ˡ�
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 500 + 5;
int cla[maxn];
int mt[maxn][maxn];
int dp[maxn][maxn];
int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
	{
		int num = 0;
		for (int j = 0; j < m; j++)
		{
			char ch;
			cin >> ch;
			if (ch == '1')
			{
				cla[++num] = j;
			}
		}
		for (int j = 0; j < num; j++)//���ﲻ����k��Ϊ�п���һ��û��k�ڿΣ�
		{
			mt[i][j] = cla[num] - cla[1] + 1;
			for (int l = 0; l <= j; l++)
			{
				mt[i][j] = min(mt[i][j], cla[num - j + l] - cla[l + 1] + 1);
			}
		}
		mt[i][num] = 0;
	}
	memset(dp, 0x3f, sizeof(dp));
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			for (int l = 0; l <= j; l++)
			{
				dp[i][j] = min(dp[i][j], dp[i - 1][j - l] + mt[i][l]);
			}
		}
	}
	cout << dp[n][k];
	return 0;
}