/*
	���������
		����2n������������������꣬ʹ��������ɵ����궼����������������ɵ��������У�����������ε���С�����
	����˼·��
		���յõ����������꣨x1,y1����x2,y2������������е��������x1<=x<=x2,y1<=y<=y2,��ô���������������������X��Y,�����ǵ���������ҵ�
	���������ϵĶ˵㡣
		��ô���վ�ֻ�����������һ�����������е��м䣬��һ�������е���ͷ����һ��������������Ϸֱ�ռ����ͷ���Ϳ��Կ�ʼ����ˡ�
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;

int inp[maxn * 2];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < 2 * n; i++)
		scanf("%d", &(inp[i]));
	sort(inp, inp + 2 * n);
	int now = INT_MAX;
	for (int i = 0; i < n; i++)
		now = min(now, inp[i + n - 1] - inp[i]);
	long long ans = (long long)min((long long)now*(long long)(inp[2 * n - 1] - inp[0]), (long long)(inp[n - 1] - inp[0])*(long long)(inp[2 * n - 1] - inp[n]));
	printf("%lld", ans);
	return 0;
}