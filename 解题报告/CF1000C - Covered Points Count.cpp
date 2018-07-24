//������ѹ��

/*
	���������
		�������ɸ����䣬ÿ�θ�һ�����䣬�������ݱ����ǵĴ�����С�������������
	����˼·��
		����������С����Ŀ������������
		ά��һ������cnt,����ÿ�θ�����l��r��cnt[l]++,cnt[r+1]--,��ǰ׺������ÿ��cnt[i]
	�������������䱻���ǵ���������
		���������в�������д�� 
		������������������Բ��ܽ�����cnt����Ž�������м��㣬�������ǵ�˼·���ɿ���������
	��������ѹ���ļ�����ά��cnt��
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<pair<long long, long long> > a(n);
	vector<long long> point;
	for (int i = 0; i<n; i++)
	{
		cin >> a[i].first >> a[i].second;
		point.push_back(a[i].first);
		point.push_back(a[i].second + 1);
	}
	sort(point.begin(), point.end());
	point.resize(unique(point.begin(), point.end()) - point.begin());//������ѹ��

	vector<int> cnt(2 * n);
	for (int i = 0; i<n; i++)
	{
		int posl = lower_bound(point.begin(), point.end(), a[i].first) - point.begin();
		int posr = lower_bound(point.begin(), point.end(), a[i].second + 1) - point.begin();
		cnt[posl]++;
		cnt[posr]--;
	}
	for (int i = 1; i< 2 * n; i++)
	{
		cnt[i] += cnt[i - 1];
	}
	vector<long long> ans(n + 1);
	for (int i = 1; i<2 * n; i++)
	{
		ans[cnt[i - 1]] += (point[i] - point[i - 1]);
	}
	for (int i = 1; i <= n; i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}
