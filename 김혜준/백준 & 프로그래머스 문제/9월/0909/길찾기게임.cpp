#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

vector<int>v1,v2;

typedef struct Tree{
    
    int idx;
    int x;
    int y;
    Tree *left=NULL;
    Tree *right=NULL;
    
}Tree;

void makeTree(Tree *root, Tree *child){
    if(root->x > child->x){
        if(root->left == NULL){
            root->left = child;
            return;
        }
        makeTree(root->left,child);
    }else{
        if(root->right==NULL){
            root->right=child;
            return;
        }
        makeTree(root->right,child);
    }
}


map<pair<int,int>,int>m;

bool cmp(vector<int> a,vector<int> b){
    return a[1]<b[1];
}

void preOrder(Tree *root){
    if(root==NULL) return;
    v1.push_back(root->idx);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Tree *root){
    if(root==NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    v2.push_back(root->idx);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    int i=1;
    for(auto w:nodeinfo){
        m[{w[0],w[1]}]=i++;
    }
    
    sort(nodeinfo.begin(),nodeinfo.end(),cmp);
    
    
    int x = nodeinfo[nodeinfo.size()-1][0];
    int y = nodeinfo[nodeinfo.size()-1][1];
    int idx = m[{x,y}];
    // cout << idx << endl;
    Tree *root = new Tree();
    root->x=x;
    root->y=y;
    root->idx=m[{x,y}];
    nodeinfo.pop_back();
    
    while(nodeinfo.size()){
        int x = nodeinfo[nodeinfo.size()-1][0];
        int y = nodeinfo[nodeinfo.size()-1][1];
        int idx = m[{x,y}];
        cout << idx << endl;
        Tree *child = new Tree();
        child->x=x;
        child->y=y;
        child->idx=m[{x,y}];
        makeTree(root,child);
        nodeinfo.pop_back();
    }
    
    preOrder(root);
    postOrder(root);
    
    answer.push_back(v1);
    answer.push_back(v2);
    
    
    return answer;
}