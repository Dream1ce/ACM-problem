/*
	���������
		����n��Ӳ�ң�ÿ��Ӳ�Ҷ���2��x�η���ÿ�β�ѯ����һ������������Ҫ����öӲ�ҡ�
	����˼·��
		����ʹ������Ӳ�ң��ܼ򵥵�һ��̰�ģ�����д������Щ���ɡ�
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> deg(33);
int n, m;

int main()
{
	cin >> n >> m;
	for (int i = 0; i<n; i++)
	{
		int a;
		cin >> a;
		deg[__builtin_ctz(a)]++;//����ڽ�������ʾ���λ��1��λ��
	}
	for (int i = 0; i<m; i++)
	{
		int a;
		cin >> a;
		int ans = 0;
		for (int i = 31; i >= 0; i--)
		{
			int needs = min(a >> i, deg[i]);//�жϹ������Сֵ
			ans += needs;
			a -= (1 << i)*needs;
		}
		if (a == 0) cout << ans << endl;
		else cout << -1 << endl;
	}
	return 0;
}