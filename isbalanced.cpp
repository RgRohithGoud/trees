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

bool isbalanced(node* root, int* height){
    if(root==NULL){
        return true;
    }
    int lh = 0,rh=0;
    if(isbalanced(root->left,&lh)==false) return false;
    if(isbalanced(root->right,&rh)==false) return false;
    *height = max(lh ,rh)+1;
    if(abs(lh-rh)<=1){
        return true;
    }
    else return false;
}

int main(){
    struct node* root  = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    int height = 0;
    cout<<isbalanced(root,&height);
    
    return 0;
}