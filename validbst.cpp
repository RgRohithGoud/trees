#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;
    node(int a){
        data = a;
        left = NULL;
        right = NULL;
    } 
};

bool bst(node* root,node* min,node* max){
    if(root==NULL){
        return true;
    }
    if(min!=NULL && root->data <=min->data){
        return false;
    }
    if(max!=NULL && root->data>= max->data){
        return false;
    }
    return bst(root->left,min,root) && bst(root->right,root,max);
}

int main(){
    struct node* root = new node(2);
    root->left = new node(1);
    root->right = new node(3);
    root->left->left = new node(0);
    cout<<bst(root,NULL,NULL);
    return 0;
}
