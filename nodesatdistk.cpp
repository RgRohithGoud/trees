#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;
    node(int a){
        data = a;
        left =NULL;
        right = NULL;
    }
};

void printnodes(node* root,int k){
    if(root==NULL||k<0){
        return;
    }
    if(k==0){
        cout<<root->data<<" ";
    }
    printnodes(root->left,k-1);
    printnodes(root->right,k-1);
}

int nodeatk(node* root,node* target, int k){
    if(root ==NULL){
        return -1;
    }
    if(root==target){
        printnodes(root,k);
        return 0;
    }
    int dl = nodeatk(root->left,target,k);
    if(dl!=-1){
        if(dl==k-1){
            cout<<root->data<<" ";
        }
        else{
            printnodes(root->right,k-dl-2);
        }
    }

    int dr = nodeatk(root->right,target,k);
    if(dr!=-1){
        if(dr==k-1){
            cout<<root->data<<" ";
        }
        else{
            printnodes(root->left,k-dr-2);
        }
    }

    return -1;
}


int main(){
    struct node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    node* target = root->left;
    nodeatk(root,target,1);
    return 0;
}