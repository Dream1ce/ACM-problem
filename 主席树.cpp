//��ϯ��������ʽ�߶���)��Ϊ���İ汾���ڱ�����Ϊ����������
#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;

struct node
{
	int s;
	node *lc, *rc;
}T[maxn * 40], *root[maxn], *cnt;//cnt����ϯ����ʮ����Ҫ����������¼��ǰ���µĽڵ㣬��ֹ�ڵ㱻�ظ�д��

int a[maxn], n;
long long ans;

node *update(node* u, int l, int r, int num)
{
	node *ret = ++cnt;//������ȡһ���µĽڵ�
	*ret = *u;//������һ���ڵ�����ݵ��µĽڵ�
	ret->s++;
	if (l == r) return  ret;
	int mid = (l + r) >> 1;
	if (num>mid)//����������˲��ָ��µ�˼������б仯����£����򱣳�ԭ��
		ret->rc = update(ret->rc, mid + 1, r, num);
	else
		ret->lc = update(ret->lc, l, mid, num);
	return ret;
}

int query(node* u, node* v, int l, int r, int num)
{
	if (num <= l) return v->s - u->s;//��һ���Ǹ����������ġ�����
	int mid = (l + r) >> 1, an = query(u->rc, v->rc, m id + 1, r, num);
	if (mid >= num) an += query(u->lc, v->lc, l, mid, num);
	return an;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", a + i);
		if (a[i]>n) a[i] = n;
	}
	root[0] = T->lc = T->rc = cnt = T;
	T->s = 0;
	for (int i = 1; i <= n; i++)
	{
		root[i] = update(root[i - 1], 1, n, a[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		if (a[i]>i)
			ans += (long long)query(root[i], root[a[i]], 1, n, i);
	}
	printf("%lld\n", ans);
	return 0;
}
