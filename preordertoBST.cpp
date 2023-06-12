#include <bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node* left;
    node* right;
    node(int a){
        val = a;
        left = NULL;
        right = NULL;
    }
};
node* constbst(int a[],int* ind,int n,int mn,int mx){
    if(*ind>= n){
        return NULL;
    }
    node* root = NULL;
    if(a[*ind]>mn && a[*ind]<mx){
        root = new node(a[*ind]);
        *ind = *ind + 1;
        if(*ind<n) root->left = constbst(a,ind,n,mn,root->val);
        if(*ind<n) root->right = constbst(a,ind,n,root->val,mx);
    }
    return root;
}
void inord(node* root){
    if(root==NULL) return;
    cout<<root->val<<" ";
    inord(root->left);
    inord(root->right);
}

int main(){
    int a[] = {10,2,1,13,11};
    int n = 5;
    int ind = 0;
    node* ans = constbst(a,&ind,n,INT_MIN,INT_MAX);
    inord(ans);
    return 0;
}