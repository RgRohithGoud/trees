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

int nodescount(node* root){
    if(root==NULL){
        return 0;
    }
    return nodescount(root->left)+nodescount(root->right)+root->data;
}
int main(){
    struct node* root = new node(3);
    root->right = new node(1);
    root->left = new node(2); 
    int ans = nodescount(root);
    cout<<ans;
    return 0;
}