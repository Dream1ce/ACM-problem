/*
	���������
		����n��ʮ������������kΪ��ʱ��Щ�������һλ�����Լ���Щ����Ϻ�����
	һλ�����ж��ٸ����ֱ���ʲô��
	����˼·��
		�������Խ������涨��ax+by = ��a,b��С��Լ���ı��������ɴ����ǿ����ȼ���
	��С����������ö�ٵ�����k�������ˣ�k��֮�����ѭ���ˡ�
*/
#include<bits/stdc++.h>
using namespace std;

int gdc(int a, int b)
{
	if (a<b)
		swap(a, b);
	return b == 0 ? a : gdc(b, a%b);
}

int main()
{
	int n, k;
	cin >> n >> k;
	int m = 0;
	int g = 0;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		g = gdc(g, t);
	}
	set<int> ans;
	long long s = 0;
	for (int i = 0; i < k; i++, s += g)
	{
		ans.insert(s%k);
	}
	cout << ans.size() << endl;
	for (set<int>::iterator i = ans.begin(); i != ans.end(); i++)
	{
		cout << *i << " ";
	}
	return 0;
}
