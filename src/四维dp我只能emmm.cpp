/*
题目描述 Description
小明过生日的时候，爸爸送给他一副乌龟棋当作礼物。 乌龟棋的棋盘是一行N个格子，每个格子上一个分数（非负整数）。棋盘第1格是唯一 的起点，第N格是终点，游戏要求玩家控制一个乌龟棋子从起点出发走到终点。

…… 1 2 3 4 5 ……N 乌龟棋中M张爬行卡片，分成4种不同的类型（M张卡片中不一定包含所有4种类型 的卡片，见样例），每种类型的卡片上分别标有1、2、3、4四个数字之一，表示使用这种卡 片后，乌龟棋子将向前爬行相应的格子数。游戏中，玩家每次需要从所有的爬行卡片中选择 一张之前没有使用过的爬行卡片，控制乌龟棋子前进相应的格子数，每张卡片只能使用一次。 游戏中，乌龟棋子自动获得起点格子的分数，并且在后续的爬行中每到达一个格子，就得到 该格子相应的分数。玩家最终游戏得分就是乌龟棋子从起点到终点过程中到过的所有格子的 分数总和。 很明显，用不同的爬行卡片使用顺序会使得最终游戏的得分不同，小明想要找到一种卡 片使用顺序使得最终游戏得分最多。 现在，告诉你棋盘上每个格子的分数和所有的爬行卡片，你能告诉小明，他最多能得到 多少分吗？

输入描述 Input Description
输入的每行中两个数之间用一个空格隔开。 第1行2个正整数N和M，分别表示棋盘格子数和爬行卡片数。 第2行N个非负整数，a1a2……aN

，其中ai表示棋盘第i个格子上的分数。 第3行M个整数，b1b2……bM

，表示M张爬行卡片上的数字。 输入数据保证到达终点时刚好用光M张爬行卡片，即N - 1=∑(1->M) bi

输出描述 Output Description
输出一行一个整数

样例输入 Sample Input
13 8

4 96 10 64 55 13 94 53 5 24 89 8 30

1 1 1 1 1 2 4 1

样例输出 Sample Output
455
 */

//四维dp,我真是日了狗
//首先循环范围要搞好，一定要<=最后一个所求的范围，不同于输入的时候<
//要确定重要的变量是什么，dp的下表是什么，dp的返回值是什么
//在这道题目中，点是没有意义的，只有留下了几个1234才是有意义的
#include<bits/stdc++.h>
using namespace std;

int dp[50][50][50][50];

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> v(n);
    for(int i=0;i<n;++i)
        cin>>v[i];
    int a,b,c,d,tmp;
    a=b=c=d=0;
    for(int i=0;i<m;++i){
        cin>>tmp;
        if(tmp==1)a++;
        if(tmp==2)b++;
        if(tmp==3)c++;
        if(tmp==4)d++;
    }
    dp[0][0][0][0]=v[0];
    for(int a1=0;a1<=a;++a1)
        for(int b1=0;b1<=b;++b1)
            for(int c1=0;c1<=c;++c1)
                for(int d1=0;d1<=d;++d1){
                	//cout<<"yes"<<endl;
                    int x=a1+2*b1+3*c1+4*d1;
                    if(a1)dp[a1][b1][c1][d1]=max(dp[a1][b1][c1][d1],dp[a1-1][b1][c1][d1]+v[x]);
                    if(b1)dp[a1][b1][c1][d1]=max(dp[a1][b1][c1][d1],dp[a1][b1-1][c1][d1]+v[x]);
                    if(c1)dp[a1][b1][c1][d1]=max(dp[a1][b1][c1][d1],dp[a1][b1][c1-1][d1]+v[x]);
                    if(d1)dp[a1][b1][c1][d1]=max(dp[a1][b1][c1][d1],dp[a1][b1][c1][d1-1]+v[x]);
                }
    cout<<dp[a][b][c][d];
    return 0;
}
