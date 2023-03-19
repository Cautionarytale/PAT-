#include<iostream>
using namespace std;
#include<algorithm>
struct node{
    int data,height;
    node*left,*right;
}*root;
node*newNode(int data){
    node*Node=new node;
    Node->data=data;
    Node->height=1;
    Node->left=Node->right=NULL;
    return Node;
}
int getHeight(node*root){
    if(root==NULL)return 0;
    return root->height;
}
void updateHeight(node*root){
    root->height=max(getHeight(root->left),getHeight(root->right))+1;
}
int getBalanceFactor(node*root){
    return getHeight(root->left)-getHeight(root->right);
}
void L(node*&root){//left rotation
    node*temp=root->right;
    root->right=temp->left;
    temp->left=root;
    updateHeight(root);
    updateHeight(temp);
    root=temp;
}
void R(node*&root){//right rotation
    node*temp=root->left;
    root->left=temp->right;
    temp->right=root;
    updateHeight(root);
    updateHeight(temp);
    root=temp;
}
void insert(node*&root,int data){
    if(root==NULL)
    {
        root=newNode(data);
        return;
    }
    if(data<root->data){
        insert(root->left,data);
        updateHeight(root);
        if(getBalanceFactor(root)==2){
            if(getBalanceFactor(root->left)==1){//LL-type
                    R(root);
            }
            else if(getBalanceFactor(root->left)==-1){//LR-type
                L(root->left);
                R(root);
            }
        }
    }
    else{
        insert(root->right,data);
        updateHeight(root);
        if(getBalanceFactor(root)==-2){
            if(getBalanceFactor(root->right)==-1){//RR-type
                    L(root);
            }
            else if(getBalanceFactor(root->right)==1){//RL-type
                    R(root->right);
                    L(root);
            }
        }

    }
}
int  main()
{
    int n,data;cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>data;
        insert(root,data);
    }
    cout<<root->data<<endl;
    return 0;
}
