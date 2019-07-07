//https://www.luogu.org/problemnew/show/P1090
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	priority_queue<int,vector<int>,greater<int>> pq;
	int tmp;
	for(int i=0;i<n;++i){
		cin>>tmp;
		pq.push(tmp);
	}
	int sum=0,a,b;
	while(pq.size()!=1){
		a=pq.top();
		pq.pop();
		b=pq.top();
		pq.pop();
		sum+=(a+b);
		pq.push(a+b);
	}
	cout<<sum;
	return 0;
}
//下面这个代码是会超时的，因为它一直在重复建堆的过程
//建堆的代码时间复杂度是n,外循环n，所有是n^2
#include<bits/stdc++.h>
using namespace std;

bool cmp(const int &a,const int &b){
    return a>b;
}

int main(){
    int n;
    cin>>n;
    vector<int> v;
    int tmp;
    for(int i=0;i<n;++i){
        cin>>tmp;
        v.push_back(tmp);
    }
    //执行次数为n-1
    int sum=0;
    for(int i=0;i<n-1;++i){
        make_heap(v.begin()+i,v.end(),cmp);
        sum+=v[i];
        make_heap(v.begin()+i+1,v.end(),cmp);
        sum+=v[i+1];
        v[i+1]+=v[i];
    }
    cout<<sum;
    return 0;
}
//STL heap代码需要修改如下
//讲句实在话，STL的heap不太好用，但是执行速度比pq快一点点……
#include<bits/stdc++.h>
using namespace std;

bool cmp(const int &a,const int &b){
	return a>b;
}

int main(){
	int n;
	cin>>n;
	vector<int> v;
	int tmp;
	for(int i=0;i<n;++i){
		cin>>tmp;
		v.push_back(tmp);
	}
	make_heap(v.begin(),v.end(),cmp);
	//cout<<v.size()<<endl;
	//cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<endl;
	//执行次数为n-1
	int sum=0;
	for(int i=0;i<n-1;++i){
		pop_heap(v.begin(),v.begin()+n-i,cmp);
		sum+=v[n-1-i];
		//cout<<sum<<endl;
		pop_heap(v.begin(),v.begin()+n-i-1,cmp);
		sum+=v[n-2-i];
		//cout<<sum<<endl;
		v[n-2-i]+=v[n-1-i];
		push_heap(v.begin(),v.begin()+n-i-1,cmp);
	}
	cout<<sum;
	return 0;
}
//手写heap操作
//主要是up和down操作
//以及两种不一样的建堆方式
//下标从1到n
#include<bits/stdc++.h>
using namespace std;

vector<int> v;
int n;

//经典的错误代码！！！
//看上去逻辑没有什么错误
//但是在转换的过程中，把原本指向的元素丢掉了！！
/*void down(int i){
	while(2*i<=n){
		int j=i;
		if(v[2*i]<v[i]){
			swap(v[2*i],v[i]);
			j=2*i;
		}
		if(2*i+1<=n){
			if(v[2*i+1]<v[i]){
				swap(v[2*i+1],v[i]);
				j=2*i+1;
			}
		}
		if(j==i)break;
		else i=j;
	}
}*/

void down(int i){
	while(2*i<=n){
		int j=2*i;
		if(j+1<=n&&v[j+1]<v[j]){
			j++;
		}
		if(v[j]<v[i]){
			swap(v[j],v[i]);
			i=j;
		}else{
			break;
		}
		
	}
}

void up(int i){
	while(i>1&&v[i]<v[i/2]){
		swap(v[i],v[i/2]);
		i/=2;
	}
}

int main(){
	cin>>n;
	int m=n;
	v.resize(m+1);
	for(int i=1;i<=m;++i)
		cin>>v[i];
	for(int i=m/2;i>=1;--i)
		down(i);
	int sum=0,a,b;
	for(int i=0;i<m-1;++i){
		a=v[1];
		v[1]=v[n];
		n--;
		down(1);
		b=v[1];
		v[1]=v[n];
		n--;
		down(1);
		sum+=a+b;
		n++;
		v[n]=a+b;
		up(n);
	}
	cout<<sum;
	return 0;
}