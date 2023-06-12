#include <bits/stdc++.h>
using namespace std;
struct node{
    int val;
    struct node* left;
    struct node* right;
    node(int a){
        val= a;
        left = NULL;
        right = NULL;
    }
};
void lview(node* root){
    if(root==NULL){
        return;
    }
    queue <node*> q;
    q.push(root);
    cout<<root->val<<endl;
    q.push(NULL);
    while(!q.empty()){
        node* curr = q.front();
        q.pop();
        if(curr!=NULL){
            if(curr->left!=NULL) q.push(curr->left);
            if(curr->right!=NULL) q.push(curr->right);
        }
        else{
            if(!q.empty()){
                cout<<q.front()->val<<endl;
                q.push(NULL);
            }
        }
    }
}

int main(){
    struct node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    lview(root);
    return 0;
}