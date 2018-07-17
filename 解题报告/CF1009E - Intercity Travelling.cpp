/*
	���������
		leha�������0��n���м���������п�������Ϣ��Ҳ����û����Ϣ�㡣����������kվ��ÿ��վ��
	ƣ��ֵΪa1,a2,a3...ak�������kվ����Ϣ�㣬��ô������ڴ˴���Ϣ��Ȼ���������վ���ƣ��ֵ��
	a1��ʼ,�������Ϊak+1����Ŀ�и���n��ai,ÿ��վ������Ϣվ�ĸ���Ϊ1/2��������ֵ*2^(n-1)��ֵ��
	����˼·��
		����վ��Ĳ�ͬ�г�aǰ���ϵ�����ҳ����ɣ��г����̣�ת��Ϊ���ԣ���ʼ��⡣
		���̴�ţ�

		*/
#include<bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int add(int x, int y)
{
	x += y;
	while (x >= MOD)
		x -= MOD;
	while (x<0)
		x += MOD;
	return x;
}

int mul(int x, int y)
{
	return (x * 1LL * y) % MOD;
}
int main()
{
	int n;
	ios::sync_with_stdio(false);
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i<n; i++)
		cin >> a[i];
	long long ans = 0;
	vector<int> pw2(1, 1);
	while (pw2.size()<n)
	{
		pw2.push_back(mul(pw2.back(), 2));
	}
	//Ԥ�ȴ���ϵ��
	long long cur = mul(pw2[n - 1], a[0]);
	for (int i = 0; i<n; i++)
	{
		ans = add(ans, cur);
		if (i<n - 1)
		{
			cur = add(cur, -mul(pw2[n - 2 - i], a[i]));
			cur = add(cur, mul(pw2[n - 2 - i], a[i + 1]));
		}
	}
	cout << ans;
}
