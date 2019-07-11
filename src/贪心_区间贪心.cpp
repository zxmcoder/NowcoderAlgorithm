/*
题目描述 Description
    给定x轴上的N（0<N<100）条线段，每个线段由它的二个端点a_I和b_I确定，I=1,2,……N.这些坐标都是区间（－999，999）的整数。有些线段之间会相互交叠或覆盖。请你编写一个程序，从给出的线段中去掉尽量少的线段，使得剩下的线段两两之间没有内部公共点。所谓的内部公共点是指一个点同时属于两条线段且至少在其中一条线段的内部（即除去端点的部分）。

输入描述 Input Description
    输入第一行是一个整数N。接下来有N行，每行有二个空格隔开的整数，表示一条线段的二个端点的坐标。

输出描述 Output Description
    输出第一行是一个整数表示最多剩下的线段数。

样例输入 Sample Input
3

6  3

1  3

2  5

样例输出 Sample Output
2
 */
#include<bits/stdc++.h>
using namespace std;

struct node{
    int left,right;
    node(int _left,int _right):left(_left),right(_right){}
};

bool cmp(const node &one,const node &two){
    if(one.left!=two.left)return one.left>two.left;
    return one.right<two.right;
}

int main(){
    int n;
    cin>>n;
    vector<node> v;
    int a,b;
    for(int i=0;i<n;++i){
        cin>>a>>b;
        v.push_back(node(min(a,b),max(a,b)));
    }
    sort(v.begin(),v.end(),cmp);
    int ans=1,l=v[0].left;
    for(int i=1;i<v.size();++i){
        if(v[i].right>l)continue;
        else{
            l=v[i].left;
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
//区间贪心问题，很多贪心问题都需要排序，在这里按照左边值从大到小排序，相同时右边值从小到大排序，从最右边开始挑选，也就是一个一重循环。