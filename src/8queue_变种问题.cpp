//https://www.luogu.org/problemnew/show/P1219
#include<bits/stdc++.h>
using namespace std;

bool row[20],x[40],y[40];
int cnt=3,ans=0,n;
int res[20];

bool check(int i,int j){
    return !row[j]&&!x[i+j]&&!y[i-j+n];
}

void dfs(int i){
    if(i==n){
        ans++;
        if(cnt){
            for(int s=0;s<n;++s)
                cout<<res[s]+1<<" ";
            cout<<endl;
            cnt--;
        }
        return;
    }
    for(int j=0;j<n;++j){
        if(check(i,j)){
            res[i]=j;
            row[j]=x[i+j]=y[i-j+n]=true;
            dfs(i+1);
            row[j]=x[i+j]=y[i-j+n]=false;
        }
    }
}

int main(){
    cin>>n;
    dfs(0);
    cout<<ans;
    return 0;
}