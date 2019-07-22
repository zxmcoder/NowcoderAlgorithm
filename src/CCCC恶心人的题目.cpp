//https://pintia.cn/problem-sets/994805046380707840/problems/994805054698012672
#include<bits/stdc++.h>
using namespace std;

bool fm[1005];//记录性别
int pnum[1005];//记录每个照片的人数
int p[1005][1005];//记录照片里面的人
double resa[1005][1005];//记录a与异性的亲密度关系
double resb[1005][1005];//记录b与异性亲密度关系

int main(){
    ios::sync_with_stdio(false);//关闭同步加速
    int n,m;
    cin>>n>>m;
    int k;
    string s;
    for(int i=0;i<m;++i){//输入照片
        cin>>k;
        pnum[i]=k;//记录每张照片的人数
        for(int j=0;j<k;++j){
            cin>>s;//字符串输入防止-0
            bool f=(s[0]=='-'?true:false);
            int id=(f==true?stoi(s.substr(1)):stoi(s));
            fm[id]=f;//记录性别
            p[i][j]=id;//记录数字人
        }
    }
    string a,b;
    cin>>a>>b;//字符串输入a,b同学
    int ida=(a[0]=='-'?stoi(a.substr(1)):stoi(a));//a的数字序号
    int idb=(b[0]=='-'?stoi(b.substr(1)):stoi(b));//同上
    double ra=0,rb=0;//记录各自与异性的最高亲密度
    for(int i=0;i<m;++i){//针对每一张照片进行分析
        bool fa=0,fb=0;
        for(int j=0;j<pnum[i];++j){//探测这张照片里面是否有ida或者idb
            if(p[i][j]==ida)fa=1;
            if(p[i][j]==idb)fb=1;
        }
        if(fa){//如果照片里面出现了a
            for(int j=0;j<pnum[i];++j){//针对照片中的每个人进行分析
                if(fm[ida]!=fm[p[i][j]]){//如果性别不同，双向记录亲密度累加
                    resa[ida][p[i][j]]+=1.0/pnum[i];
                    resa[p[i][j]][ida]=resa[ida][p[i][j]];
                    if(resa[ida][p[i][j]]>ra)ra=resa[ida][p[i][j]];//找出a的亲密度最大的那个数字
                }
            }
        }
        if(fb){//同上
            for(int j=0;j<pnum[i];++j){
                if(fm[idb]!=fm[p[i][j]]){
                    resb[idb][p[i][j]]+=1.0/pnum[i];
                    resb[p[i][j]][idb]=resb[idb][p[i][j]];
                    if(resb[idb][p[i][j]]>rb)rb=resb[idb][p[i][j]];
                }
            }
     
        }
    }
    //结束上述对每张照片的分析之后
    //我们得到了a和b各自与其它异性的亲密度，其它无用的数据没有得到！
    if(resa[ida][idb]==ra&&resb[ida][idb]==rb)cout<<a<<" "<<b;//如果最高的异性分别是对方则输出结束
    else{//否则进入别的输出，不用排序，遍历1000范围，按序号输出所有等于最高亲密度的异性
        for(int i=0;i<=1000;++i){
            if(resa[ida][i]==ra){
                cout<<a<<" ";
                cout<<(fm[i]?"-":"")<<i<<endl;
            }
        }
        for(int i=0;i<=1000;++i){
            if(resb[idb][i]==rb){
                cout<<b<<" ";
                cout<<(fm[i]?"-":"")<<i<<endl;
            }
        }
    }
    return 0;
}