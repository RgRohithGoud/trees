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

node* lca(node* root,int n1,int n2){
    if(root  == NULL){
        return NULL;
    }
    if(root->data ==n1|| root->data == n2){
        return root;
    }
    node* lef  = lca(root->left,n1,n2);
    node* rig = lca(root->right,n1,n2);
    if(lef!=NULL && rig !=NULL){
        return root;
    }
    if(lef==NULL && rig ==NULL){
        return NULL;
    }
    if(left!=NULL){
        return lef;
    }
    else return rig;

}
int height(node* root,int n,int dist){
    if(root == NULL){
        return -1;
    }
    if(root->data ==n){
        return dist;
    }
    int l = height(root->left,n,dist+1);
    if(l!=-1){
        return l;
    }
    return height(root->right,n,dist+1);

}

int shortdist(node* root,int n1,int n2){
    node* cmn = lca(root,n1,n2);
    int d1= height(cmn,n1,0);
    int d2= height(cmn,n2,0);
    return d1+d2;
}

int main(){
    struct node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    cout<<shortdist(root,3,4);
    return 0;
}