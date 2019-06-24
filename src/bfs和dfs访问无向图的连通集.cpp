/*
给定一个有N个顶点和E条边的无向图，请用DFS和BFS分别列出其所有的连通集。假设顶点从0到N−1编号。进行搜索时，假设我们总是从编号最小的顶点出发，按编号递增的顺序访问邻接点。

输入格式:
输入第1行给出2个整数N(0<N≤10)和E，分别是图的顶点数和边数。随后E行，每行给出一条边的两个端点。每行中的数字之间用1空格分隔。

输出格式:
每行输出一个连通集。先输出DFS的结果，再输出BFS的结果。

输入样例:
8 6
0 7
0 1
2 0
4 1
2 4
3 5
输出样例:
{ 0 1 4 2 7 }
{ 3 5 }
{ 6 }
{ 0 1 2 7 4 }
{ 3 5 }
{ 6 }
*/
#include<bits/stdc++.h>
using namespace std;
bool mp[15][15];
bool vis[15];
int n,e;
void dfs(int x){
	if(vis[x]==true)return;
	vis[x]=true;
	cout<<x<<" ";
	for(int i=0;i<n;++i)
		if(mp[x][i]==true)dfs(i);
}
void bfs(int x){
	queue<int> q;
	q.push(x);
	vis[x]=true;
	while(q.size()){
		int tmp=q.front();
		q.pop();
		cout<<tmp<<" ";
		for(int i=0;i<n;++i){
			if(mp[tmp][i]==true&&vis[i]==false){
				q.push(i);
				vis[i]=true;
			}
		}
	}
}
int main(){
	cin>>n>>e;
	int a,b;
	for(int i=0;i<e;++i){
		cin>>a>>b;
		mp[a][b]=true;
		mp[b][a]=true;
	}
	for(int i=0;i<n;++i){
		if(vis[i]==false){
			cout<<"{ ";
			dfs(i);
			cout<<"}"<<endl;
		}
	}
	memset(vis,0,sizeof(vis));
	for(int i=0;i<n;++i){
		if(vis[i]==false){
			cout<<"{ ";
			bfs(i);
			cout<<"}"<<endl;
		}
	}
	return 0;
}