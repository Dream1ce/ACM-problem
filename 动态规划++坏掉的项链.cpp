#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
char s[700],c;
int a, b, w, ans;//b�����ұߵ�����ȣ�a������ߵ������
int main(){
    int n;
    scanf("%d%s",&n,s);
    memcpy(s+n,s,n);
    //printf(" c  a  b  w  ans\n");
    for(int i = 0; i < n<<1; i++) {
        if(s[i] == 'w') b++,w++;else
        if(s[i] ==  c ) b++,w=0;else
        ans=max(ans,a+b),a=b-w,b=w+1,w=0,c=s[i];//a=b-w:�ǳ���w֮�������ֵ,b=w+1:����������еĳ�ʼ���ȣ�w=0:wҪ���¼���,c=s[i]��¼����һ��Ҫƥ����ַ���
        //printf("%2c %2d %2d %2d %2d\n",c,a,b,w,ans);
    }
    ans=max(ans,a+b);
    printf("%d\n",min(ans,n));
    return 0;
}