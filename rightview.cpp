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

void rview(node* root){
    if(root ==NULL){
        return;
    }
    queue<node*> q;
    q.push(root);

    while(!q.empty()){

        int n = q.size();
        for(int i=0;i<n;i++){
            node* curr = q.front();
            q.pop();
            if(i==n-1){
                cout<<curr->data<<" ";
            }
            if(curr->left !=NULL) q.push(curr->left);
            if(curr->right!=NULL) q.push(curr->right);
        }
    }
    return;
}

int main(){
    struct node* root = new node(3);
    root->right = new node(1);
    root->left = new node(2);
    root->left->left = new node(5);
    rview(root);
    return 0;
}