```

/*
题目描述 Description
农民约翰被选为他们镇的镇长！他其中一个竞选承诺就是在镇上建立起互联网，并连接到所有的农场。当然，他需要你的帮助。
约翰已经给他的农场安排了一条高速的网络线路，他想把这条线路共享给其他农场。为了用最小的消费，他想铺设最短的光纤去连接所有的农场。
你将得到一份各农场之间连接费用的列表，你必须找出能连接所有农场并所用光纤最短的方案。每两个农场间的距离不会超过100000

输入描述 Input Description
第一行： 农场的个数，N（3<=N<=100）。
第二行，某些行会紧接着另一些行。当然，对角线将会是0，因为不会有线路从第i个农..结尾: 后来的行包含了一个N*N的矩阵,表示每个农场之间的距离。理论上，他们是N行，每行由N个用空格分隔的数组成，实际上，他们限制在80个字符，因此场到它本身。

输出描述 Output Description
只有一个输出，其中包含连接到每个农场的光纤的最小长度。

样例输入 Sample Input
4
0 4 9 21
4 0 8 17
9 8 0 16
21 17 16 0

样例输出 Sample Output
28
 */
#include<bits/stdc++.h>
using namespace std;
struct e{
	int u,v,w;
	e(int _u,int _v,int _w):u(_u),v(_v),w(_w){}
};
vector<e> res;
bool cmp(const e &one,const e &two){
	return one.w<two.w;
}
int f[105];
int getf(int x){
	if(x!=f[x])
		f[x]=getf(f[x]);
	return f[x];
}
bool merge(int x,int y){
	int t1=getf(x);
	int t2=getf(y);
	if(t1!=t2){
		f[t2]=t1;
		return true;
	}
	return false;
}
int main(){
	int n;
	scanf("%d",&n);
	int len;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j){
			scanf("%d",&len);
			if(i>j)res.push_back(e(i,j,len));
		}
	for(int i=0;i<n;++i)f[i]=i;
	sort(res.begin(),res.end(),cmp);
	int ans=0,cnt=0;
	for(int i=0;i<res.size();++i){
		if(merge(res[i].u,res[i].v)){
			ans+=res[i].w;
			cnt++;
		}
		if(cnt==n-1)break;
	}
	printf("%d",ans);
	return 0;
}
```