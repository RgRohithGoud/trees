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

void sumreplace(node* root){
    if(root==NULL){
        return;
    }
    sumreplace(root->left);
    sumreplace(root->right);
    if(root->left!=NULL){
        root->data +=root->left->data;
    } 
    if(root->right!=NULL){
        root->data += root->right->data;
    }
}

int main(){
    struct node* root = new node(1);
    root->right = new node(3);
    root->left = new node(2); 
    root->left->left = new node(4);
    sumreplace(root); 
    inorder(root);
    return 0;
}