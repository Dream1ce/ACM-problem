/*
	���������
		�������ɸ��㣬�����ж���Щ���ܲ����������߰����Ƕ���������
	����˼·��
		���������õ������������Ƿ��ߵ����������������γɵ������߶ν��в��
	������Ϊ�������㹲�߷������㲻���ߣ���������ȡ���㣬������������������
	һ��ֱ�ߣ�������ֱ���ϵ����е㶼ɾ�������ʣ�µĵ��ܲ�������һ��ֱ�����
	������ΪYES, ����NO��

*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
bool used[maxn];
int n;
struct Point {
	long long x, y;
	Point() {};
	Point(long long __x, long long __y)
	{
		x = __x;
		y = __y;
	}
	friend Point operator- (const Point A, const Point B)
	{
		return Point(A.x - B.x, A.y - B.y);
	}
}P[maxn];
long long Cross(Point A, Point B)
{
	return A.x * B.y - B.x * A.y;
}
bool check()
{
	int Pa = -1;
	int Pb = -1;
	for (int i = 0; i < n; i++)
	{
		if (used[i] == true) continue;
		if (Pa == -1)
		{
			Pa = i;
		}
		else if (Pb == -1)
		{
			Pb = i;
		}
	}
	if (Pa == -1 && Pb == -1) return true;
	for (int i = 0; i < n; i++)
	{
		if (used[i] == true) continue;
		if (Cross(P[Pa] - P[Pb], P[Pa] - P[i]) != 0)
		{
			return false;
		}
	}
	return true;
}
bool judge(Point A, Point B)
{
	memset(used, 0, sizeof(used));
	for (int i = 0; i < n; i++)
	{
		if (Cross(A - B, A - P[i]) == 0)
		{
			used[i] = true;
		}
	}
	return check();
}
bool solve()
{
	if (n <= 3)
		return true;
	if (judge(P[0], P[1]) || judge(P[0], P[2]) || judge(P[1], P[2]))
		return true;
	else return false;
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		P[i].x = a;
		P[i].y = b;
	}
	if (solve())
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
//ps:�����е�Point������ݽṹ�ڼ��㼸����ʮ����Ҫ������������Ϊ��������������Ҫ�μǡ�
