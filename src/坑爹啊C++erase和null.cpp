//https://pintia.cn/problem-sets/15/problems/712
#include<bits/stdc++.h>
using namespace std;

struct node{//定义节点
    int data;
    node* l;//需要注意一下！这里的节点定义要分开定义比较好
    node* r;//千万别写成node* l,r的形式，因为这样的话，r不是一个指针
};

void insert(node* &root,int x){//root需要用指针的引用，插入删除都需要指针的引用
    if(root==NULL){
        node* tmp=new node;
        tmp->data=x;
        tmp->l=NULL;
        tmp->r=NULL;
        root=tmp;
        return;
    }
    if(root->data<x)insert(root->r,x);
    if(root->data>x)insert(root->l,x);
    //return;
}

bool same(node* one,node* two){//递归判断两个BST是否相等
    if(one==NULL&&two==NULL)return true;
    if(one==NULL&&two!=NULL)return false;
    if(one!=NULL&&two==NULL)return false;
    if(one->data!=two->data)return false;
    return same(one->l,two->l)&&same(one->r,two->r);
}

int main(){
    int n,m;
    while(true){
        cin>>n;
        if(n==0)break;
        cin>>m;
        int tmp;
        node* base=NULL;//在C++里面，指针一旦定义就要赋值，NULL千万不能忘！！！
        //cout<<2<<endl;
        for(int i=0;i<n;++i){
            cin>>tmp;
            //cout<<tmp<<endl;
            insert(base,tmp);
        }
        //cout<<3<<endl;
        while(m--){
        	node* other=NULL;//，每一次都要重新定义other，并把它赋值为NULL
            for(int i=0;i<n;++i){
                cin>>tmp;
                insert(other,tmp);
            }
            cout<<(same(base,other)?"Yes":"No")<<endl;
            //cout<<1<<endl;
        }
    }
    return 0;
}
/*
C++的另外一个坑爹的地方是：
v.erase(remove(v.begin(),v.end(),num),v.end());
 */