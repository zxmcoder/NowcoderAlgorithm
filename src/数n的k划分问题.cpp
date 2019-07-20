//http://codevs.cn/problem/1039/
/*
dp[i,j]=dp[i-1,j-1]+dp[i-j,j]
动态规划递推理解：
假设划分中最小的数字是w:
如果w=1,则dp[i-1,j-1]
如果w>1,最小的>1,所有的都>1,则dp[i-j,j]
边界条件：
dp[i][j]=0 if i<j
dp[i][i]=1
dp[i][1]=1
 */
#include<bits/stdc++.h>
using namespace std;

int divide(int i,int j){
    if(j==1)return 1;
    if(i==j)return 1;
    if(i<j)return 0;
    return divide(i-j,j)+divide(i-1,j-1);
}

int main(){
    int n,k;
    cin>>n>>k;
    cout<<divide(n,k);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

int dp[205][10];

int main(){
    int n,k;
    cin>>n>>k;
    for(int i=0;i<205;++i){
        for(int j=0;j<10;++j){
            if(i<j)dp[i][j]=0;
            if(i==j)dp[i][j]=1;
        }
    }
    for(int i=1;i<205;++i)dp[i][1]=1;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=i&&j<=k;++j){
            dp[i][j]=dp[i-j][j]+dp[i-1][j-1];
        }
    }
    cout<<dp[n][k];
    return 0;
}