/*
	���������
		��һ���ƣ���0ʱ���򿪣�mʱ��رգ���0��m�����ʱ������n��ʱ����ʹ�Ƶ�״̬�ı䣬����Ҫ��������һ����ʹ��
	����ʱ�����
	����˼·��
		���ŵķ��÷���������������ұ߰��ĵط�����,����ʣ�µ�ֻ�б����ˣ�Ϊ������ٶȣ����ǿ��Խ�������ʱ��Ͱ���ʱ
	��һ���¼������������ʡ��������ظ�����Ĳ��衣
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

int inp[maxn];
int light[maxn][2];
int n;
int M;

int main()
{
	cin >> n >> M;
	for (int i = 1; i <= n; i++)
	{
		cin >> inp[i];
	}
	inp[0] = 0;
	inp[n + 1] = M;
	int ans = 0;
	for (int i = n; i >= 0; i--)
	{
		light[i][0] = light[i + 1][0];
		light[i][1] = light[i + 1][1];
		if (i % 2 == 0)
		{
			light[i][0] += inp[i + 1] - inp[i];
			ans += inp[i + 1] - inp[i];
		}
		else
		{
			light[i][1] += inp[i + 1] - inp[i];
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (i % 2 == 1)
		{
			int now1 = light[0][0] - light[i][0];//���ұߵ�ʱ��
			int now2 = light[0][0] - light[i - 1][0];//����ߵ�ʱ��
			if (inp[i] - inp[i - 1] >= 2)
			{
				ans = max(ans, now2 + light[i][1] + inp[i] - inp[i - 1] - 1);
			}
			if (inp[i + 1] - inp[i] >= 2)
			{
				ans = max(ans, now1 + light[i + 1][1] + inp[i + 1] - inp[i] - 1);
			}
		}
	}
	cout << ans << endl;
}
