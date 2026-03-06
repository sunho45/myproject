#include <iostream>
#include <queue>

using namespace std;
class node{
    public:
        int data;
        node*left;
        node*right;
        node(int data):data(data),left(nullptr),right(nullptr){}




};




class tree{
    public:
        node *root;
        tree():root(nullptr){};
        bool isempty(){
            return root==nullptr;
        }
        node* insertnode(node *newnode, node*root){

            if(root==nullptr){
                return root;
            }
            else{

                if(root->data>newnode->data){
                    root->left=insertnode(newnode,root->left);
                }
                else if(root->data<newnode->data){
                    root->right=insertnode(newnode,root->right);

                }




            }



        }

        

        void insert(int data){
            node *newnode=new node(data);
            if(isempty()){

                root=newnode;
            }
            else{

                root=insertnode(newnode,root);
                
            }





        }


        void preorder(node *root){
            if(root==nullptr){
                return;
            }
            else{
                cout<<root->data<<" ";
                preorder(root->left);
                preorder(root->right);
            }


        }



        void inorder(node *root){
            if(isempty()){

                return;
            }
            else{
                inorder(root->left);
;
                cout<<root->data<<" ";
                 inorder(root->right);


            }

        }

        void postorder(node *root){

            if(root==nullptr){
                return;

            }
            else{
                postorder(root->left);
                postorder(root->right);
                cout<<root->data<<"";
            }




        }






};