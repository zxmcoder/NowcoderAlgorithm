```
/*
题目描述 Description
有这么一种说法：认识6个人，你就认识全世界的人。
Aiden现在有一张关系图，上面记载了N个人之间相互认识的情况。Aiden想知道，他能否只认识6个人就能间接认识这N个人呢？

输入描述 Input Description
第一行，两个数N，M，表示有N个人，M对认识关系。
接下来的M行，每行两个数ai，bi，表示ai与bi相互认识。
不保证认识关系不出现重复，保证ai≠bi。
N个人的编号为1...N。

输出描述 Output Description
若只认识6个人就能间接认识这N个人，则输出“^_^”。
若不行，则第一行输出“T_T”，第二行输出认识6个人最多能间接认识的人的个数。
输出不包括引号。

样例输入 Sample Input
6 7
1 2
1 3
2 4
3 5
4 6
5 6
3 2

样例输出 Sample Output
^_^
 */
#include<bits/stdc++.h>
using namespace std;
int f[100005];
int getf(int x){
	if(x==f[x])return f[x];
	else{
		f[x]=getf(f[x]);
		return f[x];
	}
}
void merge(int x,int y){
	int t1=getf(x);
	int t2=getf(y);
	if(t1!=t2){
		f[t2]=t1;
	}
}
unordered_map<int,int> res;
struct node{
	int root,cnt;
	node(int _root,int _cnt):root(_root),cnt(_cnt){}
};
vector<node> v;
bool cmp(const node &one,const node &two){
	return one.cnt>two.cnt;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		f[i]=i;
	int a,b;
	for(int i=0;i<m;++i){
		scanf("%d%d",&a,&b);
		merge(a,b);
	}
	for(int i=1;i<=n;++i){
		f[i]=getf(i);
		res[f[i]]++;
	}
	if(res.size()<=6)printf("^_^");
	else{
		for(auto it=res.begin();it!=res.end();++it)
			v.push_back(node(it->first,it->second));
		sort(v.begin(),v.end(),cmp);
		int ans=0;
		for(int i=0;i<6;++i)ans+=v[i].cnt;
		printf("T_T\n%d",ans);
	}
	return 0;
}
```