//复杂度n^2,但这个问题规模5000，可以解决
#include<bits/stdc++.h>
using namespace std;

int dp[5005];

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;++i)
        cin>>v[i];
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;++i){
        for(int j=0;j<i;++j){
            if(v[j]<=v[i])
                dp[i]=max(dp[i],dp[j]+1);
            else
                dp[i]=max(dp[i],dp[j]);
        }
    }
    cout<<dp[n];
    return 0;
}
//nlogn的代码真的是神奇！！！
#include<bits/stdc++.h>
using namespace std;

int dp[5005];
const int INF=100000000;

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;++i)
        cin>>v[i];
    fill(dp,dp+n,INF);
    for(int i=0;i<n;++i){
        *lower_bound(dp,dp+n,v[i])=v[i];
    }
    cout<<lower_bound(dp,dp+n,INF)-dp;
    return 0;
}