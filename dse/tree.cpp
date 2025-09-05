#include <iostream>

#include <queue>
using namespace std;

class node{
    public:
    int num;

    node* left,*right;


    node(int num):num(num),left(nullptr),right(nullptr){}






};
class tree{
node *root;
tree():root(nullptr){}
bool isempty(){

return root==nullptr ? true:false;


}

void insertnode(node *root,node *node){
if(root==nullptr){
    root=node;
}
else{
    if(node->num<root->num){
         insertnode(root->left, node);
    }
    else{
        insertnode(root->right, node);
    }

}

}

void insert(int num){
    node *newnode=new node(num);
    if(isempty()){
        root=newnode;

    }

    else{
        insertnode(root, newnode);


    }




}

void preorder(node *root){
cout<<root->num<<endl;
if(root->left!=nullptr){
preorder(root->left);

}cout<<root->num<<endl;
if(root->right!=nullptr){
preorder(root->right);

}


}
void preorders(){

if(isempty()){
    return;
}
    preorder(root);
}


void inorder(node *root){

if(root->left!=nullptr){
inorder(root->left);

}
cout<<root->num<<endl;
if(root->right!=nullptr){
inorder(root->right);

}


}
void inorders(){
    if(isempty()){
    return;
}

    inorder(root);
}
void postorder(node *root){

if(root->left!=nullptr){
postorder(root->left);

}

if(root->right!=nullptr){
postorder(root->right);

}
cout<<root->num<<endl;

}
void postorders(){
    if(isempty()){
    return;
}

    postorder(root);
}

void levelorder(){
queue <node*> qu;


qu.push(root);
while(!qu.empty()){
cout<<qu.front()->num<<endl;
if(qu.front()->left!=nullptr){
    qu.push(qu.front()->left);
}
if(qu.front()->right!=nullptr){
    qu.push(qu.front()->right);
}

}


}




};



int main(){


















}
