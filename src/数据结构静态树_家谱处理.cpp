//https://pintia.cn/problem-sets/15/problems/842
/*
人类学研究对于家族很感兴趣，于是研究人员搜集了一些家族的家谱进行研究。实验中，使用计算机处理家谱。为了实现这个目的，研究人员将家谱转换为文本文件。下面为家谱文本文件的实例：

John
  Robert
    Frank
    Andrew
  Nancy
    David
家谱文本文件中，每一行包含一个人的名字。第一行中的名字是这个家族最早的祖先。家谱仅包含最早祖先的后代，而他们的丈夫或妻子不出现在家谱中。每个人的子女比父母多缩进2个空格。以上述家谱文本文件为例，John这个家族最早的祖先，他有两个子女Robert和Nancy，Robert有两个子女Frank和Andrew，Nancy只有一个子女David。

在实验中，研究人员还收集了家庭文件，并提取了家谱中有关两个人关系的陈述语句。下面为家谱中关系的陈述语句实例：

John is the parent of Robert
Robert is a sibling of Nancy
David is a descendant of Robert
研究人员需要判断每个陈述语句是真还是假，请编写程序帮助研究人员判断。

输入格式:
输入首先给出2个正整数N（2≤N≤100）和M（≤100），其中N为家谱中名字的数量，M为家谱中陈述语句的数量，输入的每行不超过70个字符。

名字的字符串由不超过10个英文字母组成。在家谱中的第一行给出的名字前没有缩进空格。家谱中的其他名字至少缩进2个空格，即他们是家谱中最早祖先（第一行给出的名字）的后代，且如果家谱中一个名字前缩进k个空格，则下一行中名字至多缩进k+2个空格。

在一个家谱中同样的名字不会出现两次，且家谱中没有出现的名字不会出现在陈述语句中。每句陈述语句格式如下，其中X和Y为家谱中的不同名字：

X is a child of Y
X is the parent of Y
X is a sibling of Y
X is a descendant of Y
X is an ancestor of Y
输出格式:
对于测试用例中的每句陈述语句，在一行中输出True，如果陈述为真，或False，如果陈述为假。

输入样例:
6 5
John
  Robert
    Frank
    Andrew
  Nancy
    David
Robert is a child of John
Robert is an ancestor of Andrew
Robert is a sibling of Nancy
Nancy is the parent of Frank
John is a descendant of Andrew
输出样例:
True
True
True
False
False
 */
#include<bits/stdc++.h>
using namespace std;
int father[105];
vector<int> son[105];
unordered_map<string,int> h;
int blank[105];
bool fun(int u,int v){
    v=father[v];
    while(v){
        if(u==v)return true;
        v=father[v];
    }
    return false;
}
int main(){
    //ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    getchar();
    //cout<<n<<" "<<m<<endl;
    string str;
    for(int i=1;i<=n;++i){
        getline(cin,str);
        //cout<<str<<endl;
        int cnt=0;
        while(str[cnt++]==' ');
        h[str.substr(cnt-1)]=i;
        blank[i]=cnt-1;
    }
    //cout<<h["Andrew"]<<endl;
    //cout<<blank[4];
    father[1]=0;
    for(int i=2;i<=n;++i)
        for(int j=i-1;j>=1;--j)
            if(blank[j]==blank[i]-2){
                father[i]=j;
                break;
            }
    //for(int i=1;i<=n;++i)cout<<father[i]<<" ";
    for(int i=2;i<=n;++i)
        son[father[i]].push_back(i);
    string tmp,u,v,w;
    while(m--){
        cin>>u>>tmp>>tmp>>w>>tmp>>v;
        if(w=="sibling")cout<<(father[h[u]]==father[h[v]]?"True":"False")<<endl;
        else if(w=="child")cout<<(father[h[u]]==h[v]?"True":"False")<<endl;
        else if(w=="parent")cout<<(father[h[v]]==h[u]?"True":"False")<<endl;
        else if(w=="ancestor")cout<<(fun(h[u],h[v])?"True":"False")<<endl;
        else cout<<(fun(h[v],h[u])?"True":"False")<<endl;
    }
    return 0;
}