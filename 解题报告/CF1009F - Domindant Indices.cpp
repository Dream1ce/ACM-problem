//���鼯��Ӧ��
/*
	���������
		����һ������������һ�����飬Dx,i����������x����������Ҫ����i���ߵĶ��������������һ�������������������һ�����±�Ϊi����ǰ�ߵ������������С�������
	�����������������ô�ͳ������Ϊ���±ꡣ������ÿ���ڵ�����±�Ϊ���٣�
	����˼·��
		�����뷨:����ÿһ���ڵ㶼Ҫ��һ����������¼Dx,i��ÿ�β���һ���ڵ㣬�����Ƚڵ����������Ӧ��Ԫ�ض�Ҫ����1��������ÿ���ڵ��ҵ����±�,�����Ļ�ʱ�临��
	��ΪO(n^2),�ռ临�Ӷ�ΪO(n^2)
		��һ���Ż���������ӵ����Ϲ�����ôÿ���ڵ�ĸ��ڵ����Ϣ���Ǹ��ڵ�������ӽڵ����Ϣ֮�ͣ���ô�ڹ�������ʱ����Ϣ�Ե����ϴ���ͬʱ��¼ÿ���ڵ�����±꣬
	��ô�����Ļ��Ϳ��Խ�ʱ�临�Ӷ�ת��ΪO(n)��
*/
#include<bits/stdc++.h>
using namespace std;

const int maxn = 1000043;

struct node
{
	vector<int> *d;//�����vectorֻ������ָ��,ȫ���������ϴ�
	int cur_max;//�����¼�����±��ֵ
	int sz()
	{
		return d->size();
	}
	void add(int i, int val)
	{
		(*d)[i] += val;
		if (make_pair((*d)[i], i)>make_pair((*d)[cur_max], cur_max))//�����Ǵӵ����������µ�Ԫ������ѹ�����ʽ����������Խ����ԽС
			cur_max = i;
	}
};

node pull(node z)//���������Ŀ������merge�����Ժ��ټ���Dx,0
{
	if (z.sz() == 0)
	{
		node c;
		c.d = new vector<int>(1, 1);
		c.cur_max = 0;
		return c;
	}
	else
	{
		node c;
		c.d = z.d;
		c.cur_max = z.cur_max;
		c.d->push_back(0);
		c.add(c.sz() - 1, 1);
		return c;
	}

}

node merge(node a, node b)//merge���������ϲ�����
{
	if (a.sz()<b.sz())
		swap(a, b);
	//node c;
	//c.d = a.d;
	//c.cur_max = a.cur_max;
	int as = a.sz();
	int bs = b.sz();
	for (int i = 0; i < bs; i++)
		a.add(as - i - 1, (*(b.d))[bs - i - 1]);//��ĩβ�ӵ����֤������˼��һ�µ�
	return a;
}

node s[maxn];
int ans[maxn];
vector<int> g[maxn];

void dfs(int x, int p = -1)
{
	s[x].d = new vector<int>(0);
	s[x].cur_max = 0;
	for (auto y : g[x])
	{
		if (y != p)//��ֹ�ɻ�
		{
			dfs(y, x);
			s[x] = merge(s[x], s[y]);
		}
	}
	s[x] = pull(s[x]);
	ans[x] = s[x].sz() - 1 - s[x].cur_max;
	return;
}
int main()
{
	int n;
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(0);
	for (int i = 0; i < n; i++)
	{
		cout << ans[i] << endl;
	}
	return 0;
}