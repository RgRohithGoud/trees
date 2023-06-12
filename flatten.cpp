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

void flat(node* root){
    if(root==NULL || root->left==NULL && root->right ==NULL){
        return;
    }
    if(root->left!=NULL){
        flat(root->left);
        node* rg = root->right;
        root->right = root->left;
        root->left = NULL;
        node* t = root->right;
        while (t->right!=NULL)
        {
            t= t->right;
        }
        t->right = rg;
        
    }
}



int main(){
    struct node* root = new node(3);
    root->right = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    flat(root);
    while(root!=NULL){
        cout<<root->data<<" ";
        root = root->right;
    }
    return 0;
}