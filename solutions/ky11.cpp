#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

struct Treenode{
    char c;
    Treenode* left;
    Treenode* right;
};

int pos = 0;

Treenode* create(Treenode* &root, string s){
    if(s.length()==pos)
        return NULL;
    char c = s[pos++];
    if(c=='#')
        return NULL;
    else{
        root = new Treenode;
        root->c = c;
        root->left = NULL;
        root->right = NULL;
        create(root->left,s);
        create(root->right,s);
    }
    return root;
}

void Inordertraverse(Treenode* root){
    if(root!=NULL){
        Inordertraverse(root->left);
        cout<<root->c<<" ";
        Inordertraverse(root->right);
    }
}

int main(){
    string s;
    while(cin>>s){
        Treenode* root = new Treenode;
        pos = 0;
        root = create(root,s);
        Inordertraverse(root);
        cout<<endl;
    }
    return 0;
}
