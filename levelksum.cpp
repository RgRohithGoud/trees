#include <bits/stdc++.h>
using namespace std;

struct node
{
    int val;
    struct node* left;
    struct node* right;
    node(int a){
        val = a;
        left  = NULL;
        right = NULL;
    }
};
int levelord(node* root,int k ){
    if(root ==NULL){
        return -1;
    }
    int level =0,sum=0;
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* p = q.front();
        q.pop();
        if(p!=NULL){
            if(level ==k){
                sum+= p->val;
            }
            
            if(p->left!=NULL){
                q.push(p->left);
            }
            if(p->right!=NULL){
                q.push(p->right);
            }
        }
        else{
            if(!q.empty()) q.push(NULL);
            level ++;
        }
        
    }
    return sum;
}

int main(){
    struct node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(5);    
    root->right = new node(3);
    root->right->left = new node(6);
    root->right->right = new node(7);


    int s = levelord(root,2);
    cout<<s;
    return 0;
}