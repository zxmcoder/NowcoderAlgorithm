/*
题目描述 Description
有一个箱子容量为V（正整数，0＜＝V＜＝20000），同时有n个物品（0＜n＜＝30），每个物品有一个体积（正整数）。

要求n个物品中，任取若干个装入箱内，使箱子的剩余空间为最小。

输入描述 Input Description
一个整数v，表示箱子容量

一个整数n，表示有n个物品

接下来n个整数，分别表示这n 个物品的各自体积

输出描述 Output Description
一个整数，表示箱子剩余空间。

样例输入 Sample Input
24

6

8

3

12

7

9

7

样例输出 Sample Output
0
 */
//神奇的题目，dfs暴力竟然可以过……
#include<bits/stdc++.h>
using namespace std;

int v,n;
vector<int> a;

int dfs(int i,int j){
	int res;
	if(i==n)res=0;
	else if(j<a[i])res=dfs(i+1,j);
	else res=max(dfs(i+1,j),dfs(i+1,j-a[i])+a[i]);
	return res;
}

int main(){
    cin>>v>>n;
    a.resize(n);
    for(int i=0;i<n;++i)
        cin>>a[i];
    cout<<v-dfs(0,v);
    return 0;
}

//记忆化dfs
//从0到n再到0

#include<bits/stdc++.h>
using namespace std;

int v,n;
vector<int> a;

int dp[31][20005];

int dfs(int i,int j){
    if(dp[i][j]>=0)return dp[i][j];
    int res;
    if(i==n)res=0;
    else if(j<a[i])res=dfs(i+1,j);
    else res=max(dfs(i+1,j),dfs(i+1,j-a[i])+a[i]);
    return dp[i][j]=res;
}

int main(){
    memset(dp,-1,sizeof(dp));
    cin>>v>>n;
    a.resize(n);
    for(int i=0;i<n;++i)
        cin>>a[i];
    cout<<v-dfs(0,v);
    return 0;
}

//根据模板dp
//直接从n到0返回dp(0,v)

#include<bits/stdc++.h>
using namespace std;

int dp[31][20005];

int main(){
    int v,n;
    cin>>v>>n;
    vector<int> a(n);
    for(int i=0;i<n;++i)
        cin>>a[i];
    for(int i=n-1;i>=0;--i){
        for(int j=0;j<=v;++j){
            if(a[i]>j)dp[i][j]=dp[i+1][j];
            else dp[i][j]=max(dp[i+1][j],dp[i+1][j-a[i]]+a[i]);
        }
    }
    cout<<v-dp[0][v];
    return 0;
}

//另一种模板dp
//这样的dp第0层表示没有挑选物品，第n层才表示挑选了从0-n-1的物品

#include<bits/stdc++.h>
using namespace std;

int dp[31][20005];

int main(){
    int v,n;
    cin>>v>>n;
    vector<int> a(n);
    for(int i=0;i<n;++i)
        cin>>a[i];
    for(int i=0;i<n;++i){
        for(int j=0;j<=v;++j){
            if(a[i]>j)dp[i+1][j]=dp[i][j];
            else dp[i+1][j]=max(dp[i][j],dp[i][j-a[i]]+a[i]);
        }
    }
    cout<<v-dp[n][v];
    return 0;
}

//自己设计一个dp来解决这个问题
//递推公式见程序

#include<bits/stdc++.h>
using namespace std;

int dp[31][20005];

int main(){
    int v,n;
    cin>>v>>n;
    vector<int> a(n);
    for(int i=0;i<n;++i)
        cin>>a[i];
    for(int i=0;i<=v;++i)
        dp[0][i]=i;
    for(int i=1;i<=n;++i){
        for(int j=0;j<=v;++j){
            if(a[i-1]>j)dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=min(dp[i-1][j],dp[i-1][j-a[i-1]]);
        }
    }
    cout<<dp[n][v];
    return 0;
}

