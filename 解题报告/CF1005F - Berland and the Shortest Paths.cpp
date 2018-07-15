/*
	���������
		��n���ڵ�,m���ߣ�����0Ϊ���Ĺ������·������k�ַ������������k�������k�֣���
	����˼·��
		������С���������ԣ���ͬ�����ÿ���㵽���ĵľ��붼����ͬ�ģ��������ǿ�����һ�����������棬ÿ����
	��ԭ��ľ��룬��ô�����������ʿ��Էǳ����׵ĵ�֪��*һ����������ڽڵ�ľ������������ڵ�ľ����һ��
	����������������������BFS�������·�������ɴ�*�ŵ��������ǿ��Ե�֪���·�����Ķ��������֮������������ˡ�
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int> > g(n);
	vector<int> a(m), b(m);
	for (int i = 0; i<m; i++)
	{
		cin >> a[i] >> b[i];
		a[i]--, b[i]--;
		g[a[i]].push_back(b[i]);
		g[b[i]].push_back(a[i]);
	}
	//����Ϊ�������ͼ
	queue<int> q;
	vector<int> d(n, INT_MAX);
	q.push(0);
	d[0] = 0;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int i = 0; i<g[u].size(); i++)
		{
			if (d[g[u][i]] == INT_MAX)
			{
				d[g[u][i]] = d[u] + 1;
				q.push(g[u][i]);
			}
		}
	}
	//����Ϊ���·�����Ľ���
	vector<vector<int> > inc(n);
	for (int i = 0; i<m; i++)
	{
		if (d[a[i]] + 1 == d[b[i]])
			inc[b[i]].push_back(i);
		if (d[b[i]] + 1 == d[a[i]])
			inc[a[i]].push_back(i);

	}
	//����Ϊ���������ȷ��
	vector<int> f(n, 0);
	vector<string> ans;
	for (int i = 0; i<k; i++)
	{
		string tem(m, '0');
		for (int j = 1; j<n; j++)
		{
			tem[inc[j][f[j]]] = '1';
		}
		ans.push_back(tem);
		bool ok = false;
		for (int j = 1; j<n; j++)
		{
			if (f[j] + 1<inc[j].size())
			{
				ok = true;
				f[j]++;
				break;
			}
			else
				f[j] = 0;
		}
		if (!ok)
			break;
	}
	cout << ans.size() << endl;
	for (int i = 0; i<ans.size(); i++)
	{
		cout << ans[i] << endl;
	}
	return 0;
}
