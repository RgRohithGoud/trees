#include <bits/stdc++.h>
using namespace std;
struct node
{
    int val;
    struct node* left;
    struct node* right;
    node(int a){
        val = a;
        left = NULL;
        right =NULL;
    }
};
int height(node* root){
    if(root==NULL){
        return 0;
    }
    return 1+ max(height(root->left),height(root->right));
}

int main(){
    struct node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    cout<<height(root);

    return 0;
}