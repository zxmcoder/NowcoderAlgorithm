#include<bits/stdc++.h>
using namespace std;

int mp[10][10];
int color[10];
int n,ans=0;

void dfs(int x){
    if(x==n+1)return;
    for(int i=1;i<=4;++i){
        int flag=0;
        for(int j=1;j<=n;++j){
            if(mp[x][j]==1&&color[j]==i)
                flag=1;
        }
        if(flag==0){
            color[x]=i;
            if(x==n)ans++;
            dfs(x+1);
            color[x]=0;
        }
    }
}

int main(){
    cin>>n;
    int tmp;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j){
            cin>>tmp;
            if(tmp){
                mp[i][j]=1;
                mp[j][i]=1;
            }
        }
    dfs(1);
    cout<<ans;
    return 0;
}