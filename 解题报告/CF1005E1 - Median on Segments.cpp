/*
	���������
		��һ����������������һ����Χʹ��һ�����������������Χ��Ϊ��λ����
	����˼·��
		���������Ҫ�������λ������λ����һ�������Ǿ�����һ�����������һ����Ϊ��λ������ô���������Ҫ���ڱ���С��������
	����С����-1��+1�����������ĿҪ����������ô���ǾͿ��Զ���һ����������¼�±����������ȥ����С��������x�ĸ���������ǰ׺
	�����ʣ��ڰ���m������ǰ׺����ͬ�ĺ�ǰ׺��-1�����������еĳ��ִ����ͺ��ˡ�
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 4e5 + 5;
const int offset = 2e5 + 2;//����ʹ�õ������飬����п��ܻ��������±�Խ����������Ҫ����ƫ�����������map����Բ������á�
int c[maxn];
int inp[maxn];
int n, m;

int main()
{

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> inp[i];
	}
	c[offset] = 1;
	int sum = 0;
	bool inclu = false;
	long long ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (inp[i]>m)
			sum++;
		else if (inp[i]<m)
			sum--;

		if (inp[i] == m)
			inclu = true;
		if (inclu)
			ans += c[sum - 1 + offset] + c[sum + offset];
		else c[sum + offset]++;
	}
	cout << ans << endl;
	return 0;
}
