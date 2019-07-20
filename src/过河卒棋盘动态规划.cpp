//http://codevs.cn/problem/1010/
#include<bits/stdc++.h>
using namespace std;
int n,m,x,y;
int dp[20][20];
int dis[8][2]={{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,-1},{-2,1}};
bool check(int s,int t){
    if(s==x&&t==y)return false;
    for(int i=0;i<8;++i)
        if(s==(x+dis[i][0])&&(t==(y+dis[i][1])))
            return false;
    return true;
}
int main(){
    cin>>n>>m>>x>>y;
    dp[0][0]=1;
    int cnt=0;
    for(int i=0;i<=n;++i){
        for(int j=0;j<=m;++j){
            if(i>=1)dp[i][j]+=dp[i-1][j];
            if(j>=1)dp[i][j]+=dp[i][j-1];
            if(!check(i,j))dp[i][j]=0;//cout<<"yes"<<endl;cnt++;}
        }
    }
    //cout<<cnt<<endl;
    cout<<dp[n][m];
    //cout<<check(4,4);
    return 0;
}