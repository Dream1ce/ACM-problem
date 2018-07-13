/*
	���������
		����n���ڵ㣬Ҫ����һ�ã���ļ�·���Ȳ��ó���d��ÿ���ڵ�����������ó���k��
	����˼·��
		�����Ŀ�Ѿ�����������ļ�·�ĳ��ȣ���������Ҫ�������ȹ���һ�����·��ͬʱά��һ��set������ÿ���ڵ��·��
	���ȣ���һ������������¼ÿ���ڵ�Ķ�����ÿ�����һ���ڵ�������·�ĳ�������һ���ڵ��һ��
		�жϲ����ܹ�������ļ���������1��d>=n 2���ڹ����ʱ�����нڵ�Ķȶ��Ѿ�����k 3���ڹ����ʱ���Ѿ��нڵ�����·�ĳ��ȵ���d
		���һ���ڵ�����������������ֱ��������
*/
#include<bits/stdc++.h>
using namespace std;

int n, d, k;
int main()
{
	cin >> n >> d >> k;
	vector<int> deg(n, 0);
	set<pair<int, int> > pa;
	vector<pair<int, int> > ans;
	if (d >= n)
	{
		cout << "NO";
		return 0;
	}
	for (int i = 0; i<d; i++)
	{
		deg[i]++;
		deg[i + 1]++;
		if (deg[i]>k || deg[i + 1]>k)
		{
			cout << "NO";
			return 0;
		}
		ans.push_back(make_pair(i, i + 1));
	}
	for (int i = 1; i<d; i++)//��Ϊ��ͷ�����·������d,����i��1��ʼ��d-1
	{
		pa.insert(make_pair(max(i, d - i), i));
	}
	for (int i = d + 1; i<n; i++)
	{
		while (!pa.empty() && deg[pa.begin()->second] == k)//���ȱ�֤�����Ķ�û�б�����
			pa.erase(pa.begin());
		if (pa.empty() || pa.begin()->first == d)//������������·�����Ѿ�����d����ô�������Ǹ��ط��ӵ㶼��ʹ���ĳ��ȼ�1�����Կ���ֱ���жϲ�����
		{
			cout << "NO";
			return 0;
		}
		deg[i]++;
		deg[pa.begin()->second]++;
		ans.push_back(make_pair(i, pa.begin()->second));
		pa.insert(make_pair(pa.begin()->first + 1, i));
	}
	cout << "YES" << endl;
	for (int i = 0; i<n - 1; i++)
	{
		cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
	}
	return 0;
}
