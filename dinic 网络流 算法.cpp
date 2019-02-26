/*pat top level 1003 ������
  �����������������㷨��������·�㷨�����������������Ѱ������·��������Ϊ������·�㷨������Ҫ��˼���ǵ�����������˵�Ƿ��ڣ�����dinicʹ�÷ֲ�ͼ�����ص��㷨�����˸Ľ���ͬʱ��¼�Ѿ��������·
������Ч�����Ч��

*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
#include<cstring>
#include<queue>
using namespace std;


const int maxn = 505;
const int INF = 0x3f3f3f3f;
map<string,int> mp;
int cur[maxn*2];
int depth[maxn*2];
int head[maxn*2];
int nexts[maxn*2];
int w[maxn*2];
int V[maxn*2];
int cnt = -1;
int s,t;
int vcnt = 0;
bool bfs()
{
    queue<int> Q;
    while(!Q.empty()) Q.pop();
    Q.push(s);
    memset(depth,0,sizeof(depth));
    depth[s] = 1;
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for(int i = head[u]; i!=-1; i = nexts[i])
        {
            if(w[i]>0 && depth[V[i]]==0)
            {
                depth[V[i]] = depth[u]+1;
                Q.push(V[i]);
            }
        }
    }
    if(depth[t]==0)
        return false;
    return true;
}
bool dfs(int u, int dist)
{
    if(u==t)
    {
           return dist;
    }
    for(int &i = cur[u]; i != -1; i=nexts[i])
    {
        //cout<<i<<" "<<u<<endl;
        if(w[i]!=0 &&(depth[V[i]]==depth[u]+1))
        {
           // cout<<w[i]<<endl;
            int d = dfs(V[i],min(dist,w[i]));
            if(d > 0)
            {
                w[i]-=d;
                w[i^1]+=d;
                return d;
            }
        }
    }
    return 0;
}

void _add(int u, int v, int ws)
{
    cnt++;
    nexts[cnt]=head[u];
    V[cnt] = v;
    w[cnt] = ws;
    head[u] = cnt;
}
void add_edge(int u, int v, int w)
{
    _add(u,v,w);
    _add(v,u,0);
}

int dinic()
{
    int ans = 0;
    while(bfs())
    {
        for(int i = 0; i < vcnt; i++)
        {
            cur[i] = head[i];
        }
        while(int b = dfs(s,INF))
        {
            ans+=b;
        }

    }
    return ans;
}

int main()
{
    string a,b;
    int l;
    for(int i = 0; i < maxn*2; i++)
    {
        head[i] = -1;
        nexts[i] = -1;
    }
    cin>>a>>b>>l;
    s=1;t=0;
    mp[a] = vcnt++;
    mp[b] = vcnt++;
    for(int i = 0; i < l; i++)
    {
        int weight;
        cin>>a>>b>>weight;
        int an,bn;
        if(!mp.count(a))
            mp[a] = vcnt++;
        if(!mp.count(b))
            mp[b] = vcnt++;
        an = mp[a];
        bn = mp[b];
        add_edge(bn,an,weight);
    //    cout<<" "<<an<<" "<<bn<<endl;
    }
    cout<<dinic();
}
