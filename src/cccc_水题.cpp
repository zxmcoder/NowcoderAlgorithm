//水一题
/*
社交网络中我们给每个人定义了一个“活跃度”，现希望根据这个指标把人群分为两大类，即外向型（outgoing，即活跃度高的）和内向型（introverted，即活跃度低的）。要求两类人群的规模尽可能接近，而他们的总活跃度差距尽可能拉开。

输入格式：
输入第一行给出一个正整数N（2≤N≤10
​5
​​ ）。随后一行给出N个正整数，分别是每个人的活跃度，其间以空格分隔。题目保证这些数字以及它们的和都不会超过2
​31
​​ 。

输出格式：
按下列格式输出：

Outgoing #: N1
Introverted #: N2
Diff = N3
其中N1是外向型人的个数；N2是内向型人的个数；N3是两群人总活跃度之差的绝对值。

输入样例1：
10
23 8 10 99 46 2333 46 1 666 555
输出样例1：
Outgoing #: 5
Introverted #: 5
Diff = 3611
输入样例2：
13
110 79 218 69 3721 100 29 135 2 6 13 5188 85
输出样例2：
Outgoing #: 7
Introverted #: 6
Diff = 9359
 */
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    int sum1=0;
    for(int  i=0;i<n;++i){
        cin>>v[i];
        sum1+=v[i];
    }
    sort(v.begin(),v.end());
    int o=n%2?n/2+1:n/2;
    cout<<"Outgoing #: "<<o<<endl<<"Introverted #: "<<n-o<<endl;
    int sum2=0;
    for(int i=0;i<n-o;++i)sum2+=v[i];
    cout<<"Diff = "<<sum1-sum2-sum2;
    return 0;
}