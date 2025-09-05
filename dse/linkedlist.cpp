#include <iostream>
using namespace std;

class node{
    public:
    node *left;
    node* right;
    int num;

node(int num):left(nullptr),right(nullptr),num(num){}


};
class linkedlist{

node *tail, *head;
linkedlist():tail(nullptr),head(nullptr){}
bool isempty(){


    return head==nullptr&&tail==nullptr ? true:false;
}
void push(int num){
node* newnode= new node(num);
    if(isempty()){

        head=tail=newnode;
    }
    else{
        tail->right=newnode;
        newnode->left=tail;
        tail=newnode;






    }



}







};







int main(){















}