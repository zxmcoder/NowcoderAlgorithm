//http://codevs.cn/problem/2833/
#include<bits/stdc++.h>
using namespace std;
vector<int> v[10005];//建立邻接表，tpsort用邻接表相对方便而且省空间
int in[10005];//记录每一个顶点的入度
int n,m,num=0;//num代表完成tpsort流程的点，也就是说，所有的有向无环图中的点
bool tpsort(){
    queue<int> q;
    for(int i=1;i<=n;++i)
        if(in[i]==0)q.push(i);//先把入度为0的点加入队列，也就是在任何时候都可以开始的活动
    while(q.size()){//当队列不为空
        int u=q.front();
        q.pop();//取出队首元素，这里可以记录tp序列
        num++;//完成操作的点++
        for(int i=0;i<v[u].size();++i){
            in[v[u][i]]--;//对已经完成的点的所有下一个点，下一个点的in--
            if(in[v[u][i]]==0)q.push(v[u][i]);//当in--成为0的时候，代表下一个点前置条件都已经满足了，可以加入队列
        }
    }
    if(num==n)return true;//完成tpsort的点的数量==n有向无环图
    else return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    int a,b;
    for(int i=0;i<m;++i){
        cin>>a>>b;
        v[a].push_back(b);
        in[b]++;
    }
    if(tpsort())cout<<"o(∩_∩)o";
    else cout<<"T_T"<<endl<<n-num;
    return 0;
}