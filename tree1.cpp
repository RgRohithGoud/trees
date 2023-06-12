#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node* right;
    struct node* left;
    node(int a){
        data = a;
        right = NULL;
        left = NULL;
    }
};

void inorder(node* root){
    if (root==NULL)
    {
        return;
    }
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    struct node* root = new node(3);
    root->right = new node(1);
    root->left = new node(2); 
    inorder(root);
    return 0;
}