/*
	���������
		ÿ��ˮ������������a[i],b[i]���㵱a[i],b[i]����sigma(a[i])/sigma(b[i]) = k ʱ sigma(a[i])�����ֵ��
	����˼·��
		����ʽ����ת����������ѱ������������� a[i]-k*b[i]�滻�������ת��Ϊ��n��ˮ��������Ϊ���ʱ��sigma(a[i])�����ֵ��
		Ҫע����������ˮ���������������ֵ������Ҫ��һ��ƫ������
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 105;
const int INF = 0x3f3f3f;
int dp[105][maxn*maxn * 10 * 4];
int N;
int a[maxn];
int b[maxn];
int c[maxn];
int main()
{
	int n, k;
	cin >> n >> k;
	N = 1000 * n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
		c[i] = a[i] - k * b[i];
	}
	for (int i = 0; i < maxn; i++)
	{
		for (int j = 0; j <= maxn * maxn * 20; j++)
		{
			dp[i][j] = -INT_MAX;
		}
	}
	dp[0][N] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 2 * N; j >= c[i]; j--)
		{
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - c[i]] + a[i]);
		}
	}
	if (dp[n][N] <= 0)
	{
		cout << -1;
	}
	else
	{
		cout << dp[n][N] << endl;
	}
	return 0;
}