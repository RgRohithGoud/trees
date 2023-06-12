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

int searc(int intr[],int start,int end,int val){
    for(int i=start;i<=end;i++){
        if(intr[i] == val){
            return i;
        }
    }
    return -1;
}
node* buildtree(int inr[],int postr[],int start,int end){
    static int ind = end;
    if(start>end){
        return NULL;
    }

    int val = postr[ind];
    struct node* root  = new node(val);
    ind--;
    if(start == end){
        return root;
    }
    int p = searc(inr,start,end,val);
    root->left = buildtree(inr,postr,start,p-1);
    root->right = buildtree(inr,postr,p+1,end);

    return root;

}
void inord(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    inord(root->left);
    inord(root->right);
    
}
int main(){
    int inr[] = {4,2,1,5,3};
    int postr[] = {4,2,5,3,1}; 
    node* root  = buildtree(inr,postr,0,4);
    inord(root);
    return 0;
}