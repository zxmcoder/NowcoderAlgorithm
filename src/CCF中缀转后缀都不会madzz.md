![image](http://118.190.20.162/RequireFile.do?fid=rBtBTn4A)
```
//中缀表达式转换为后缀表达式，利用操作符栈
//弹出所有优先级大于或者等于该运算符的栈顶元素，然后将该运算符入栈
//后缀表达式的计算。利用数字栈，压入一个一个弹出两个一起弹出

#include<bits/stdc++.h>
using namespace std;

unordered_map<char,int> m;

int main(){
	m['x']=m['/']=2;
	m['+']=m['-']=1;
	int n;
	cin>>n;
	getchar();
	string s;
	for(int i=0;i<n;++i){
		getline(cin,s);
		//cout<<s;
		string tmp;
		stack<char> opt;
		stack<int> num;
		for(int i=0;i<s.size();++i){
			if(isdigit(s[i]))tmp+=s[i];
			else{
				if(opt.empty())opt.push(s[i]);
				else{
					while(opt.size()&&m[opt.top()]>=m[s[i]]){
						tmp+=opt.top();
						opt.pop();
					}
					opt.push(s[i]);
				}
			}
		}
		while(opt.size()){
			tmp+=opt.top();
			opt.pop();
		}
		//cout<<tmp<<endl;
		for(int i=0;i<tmp.size();++i){
			if(isdigit(tmp[i]))num.push(tmp[i]-'0');
			else{
				int b=num.top();
				num.pop();
				int a=num.top();
				num.pop();
				if(tmp[i]=='+')num.push(a+b);
				if(tmp[i]=='-')num.push(a-b);
				if(tmp[i]=='x')num.push(a*b);
				if(tmp[i]=='/')num.push(a/b);
			}
		}
		//cout<<num.top()<<endl;
		if(num.top()==24)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
```