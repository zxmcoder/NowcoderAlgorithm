/*
题目描述 Description
Z小镇是一个景色宜人的地方，吸引来自各地的观光客来此旅游观光。
Z小镇附近共有
N(1<N≤500)个景点（编号为1,2,3,…,N），这些景点被M（0<M≤5000）条道路连接着，所有道路都是双向的，两个景点之间可能有多条道路。也许是为了保护该地的旅游资源，Z小镇有个奇怪的规定，就是对于一条给定的公路Ri，任何在该公路上行驶的车辆速度必须为Vi。频繁的改变速度使得游客们很不舒服，因此大家从一个景点前往另一个景点的时候，都希望选择行使过程中最大速度和最小速度的比尽可能小的路线，也就是所谓最舒适的路线。

输入描述 Input Description
第一行包含两个正整数，N和M。
接下来的M行每行包含三个正整数：x，y和v（1≤x,y≤N，0 最后一行包含两个正整数s，t，表示想知道从景点s到景点t最大最小速度比最小的路径。s和t不可能相同。

输出描述 Output Description
如果景点s到景点t没有路径，输出“IMPOSSIBLE”。否则输出一个数，表示最小的速度比。如果需要，输出一个既约分数。

样例输入 Sample Input
样例1
4 2
1 2 1
3 4 2
1 4
样例2
3 3
1 2 10
1 2 5
2 3 8
1 3
样例3
3 2
1 2 2
2 3 4
1 3

样例输出 Sample Output
样例1
IMPOSSIBLE
样例2
5/4
样例3
2

数据范围及提示 Data Size & Hint
N(1<N≤500)
M（0<M≤5000）
Vi在int范围内
 */
//这道题目两种做法
//一是并查集+特殊枚举技巧，时间使用较长
//把边按边长从小到大排序，枚举i作为生成树的最长边，然后从i到1添边，直到s和t相连，每次对最长边与最短边的比值取小即为答案。至于正确性是显然的，因为它尽量使生成树由边长相近的边组成，然后取小。
#include<bits/stdc++.h>
using namespace std;
struct node{
	int u,v,w;
	node(int _u,int _v,int _w):u(_u),v(_v),w(_w){}
};
vector<node> road;
bool cmp(const node &one,const node &two){
	return one.w<two.w;
}
int f[505];
int getf(int x){
	if(x!=f[x])f[x]=getf(f[x]);
	return f[x];
}
void merge(int x,int y){
	int t1=getf(x),t2=getf(y);
	if(t1!=t2)f[t2]=t1;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int a,b,c;
	for(int i=1;i<=m;++i){
		scanf("%d%d%d",&a,&b,&c);
		road.push_back(node(a,b,c));
	}
	sort(road.begin(),road.end(),cmp);
	scanf("%d%d",&a,&b);
	bool flag=false;
	double ans=INT_MAX*1.0;
	int tx,ty;
	//cout<<"yes"<<endl;
	for(int i=0;i<m;++i){
		for(int j=1;j<=n;++j)f[j]=j;
		for(int j=i;j>=0;--j){
			merge(road[j].u,road[j].v);
			if(getf(a)==getf(b)){
				double tmp=road[i].w*1.0/road[j].w;
				if(tmp<ans){
					ans=tmp;
					tx=road[i].w;
					ty=road[j].w;
				}
				flag=true;
				break;
			}
		}
	}
	if(flag==false)printf("IMPOSSIBLE");
	else{
		if(tx%ty==0)printf("%d",tx/ty);
		else printf("%d/%d",tx/__gcd(tx,ty),ty/__gcd(tx,ty));
	}
	return 0;
}
//二是bfs+priority_queue直接搜索