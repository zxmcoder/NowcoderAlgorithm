//https://www.nowcoder.com/study/live/249/9/3
#include<cstdio>
#include<algorithm>

using namespace std;

struct node{
    int a,b;
    bool operator<(const node &x)const{
        return a<x.a;
    }
}node[100005];

int main(){
    int x1,x2,y1,y2;
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    int n;
    scanf("%d",&n);
    int x,y;
    for(int i=0;i<n;++i){
        scanf("%d%d",&x,&y);
        node[i].a=(x-x1)*(x-x1)+(y-y1)*(y-y1);
        node[i].b=(x-x2)*(x-x2)+(y-y2)*(y-y2);
    }
    sort(node,node+n);
    int ans=node[n-1].a,tmp=0;
    for(int i=n-1;i>0;--i){
        tmp=max(tmp,node[i].b);
        ans=min(ans,node[i-1].a+tmp);
    }
    printf("%d\n",ans);
    return 0;
}