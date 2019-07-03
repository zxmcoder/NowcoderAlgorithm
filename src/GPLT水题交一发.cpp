/*
学生互评作业的简单规则是这样定的：每个人的作业会被k个同学评审，得到k个成绩。系统需要去掉一个最高分和一个最低分，将剩下的分数取平均，就得到这个学生的最后成绩。本题就要求你编写这个互评系统的算分模块。

输入格式：
输入第一行给出3个正整数N（3 < N ≤10^4,学生总数）、k（3 ≤ k ≤ 10，每份作业的评审数）、M（≤ 20，需要输出的学生数）。随后N行，每行给出一份作业得到的k个评审成绩（在区间[0, 100]内），其间以空格分隔。

输出格式：
按非递减顺序输出最后得分最高的M个成绩，保留小数点后3位。分数间有1个空格，行首尾不得有多余空格。

输入样例：
6 5 3
88 90 85 99 60
67 60 80 76 70
90 93 96 99 99
78 65 77 70 72
88 88 88 88 88
55 55 55 55 55
输出样例：
87.667 88.000 96.000
 */
#include<bits/stdc++.h>
using namespace std;

bool cmp(const double& one,const double& two){
    return one>two;
}

int main(){
    int n,k,m;
    scanf("%d%d%d",&n,&k,&m);
    vector<double> v;
    vector<int> tmp(k);
    for(int i=0;i<n;++i){
        int sum=0;
        for(int j=0;j<k;++j){
            scanf("%d",&tmp[j]);
        }
        sort(tmp.begin(),tmp.end());
        for(int s=1;s<k-1;++s)
            sum+=tmp[s];
        v.push_back(sum*1.0/(k-2));
    }
    sort(v.begin(),v.end(),cmp);
    printf("%.3f",v[m-1]);
    for(int i=m-2;i>=0;--i)
        printf(" %.3f",v[i]);
    return 0;
}
//必须要吐槽！！！
//我还以为要什么堆排序取前K大+线性寻找最大最小
//结果发现只要sort就好了……
