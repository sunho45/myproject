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
void push_back(int num){
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



void push_front(int num){
    node* newnode= new node(num);
      if(isempty()){

        head=tail=newnode;
    }
    else{
        head->left=newnode;
        newnode->right=head;
        head=newnode;
    }


}

int pop_front(){
if(isempty()){
    cerr<<"error"<<endl;

}

else{
    if(head==tail){

int num=head->num;
node *current=head;
delete current;
return num;
}

else{
int num=head->num;
node *current=head;
head=head->right;
delete current;

return num;
}
}




}

int pop_back(){
if(isempty()){
    cerr<<"error"<<endl;

}

else{
if(head==tail){

int num=tail->num;
node *current=head;
delete current;
return num;
}



else{
int num=tail->num;
node *current=head;
head=head->right;
delete current;

return num;
}
}




}

void insert(int pos, int num){
node *newnode=new node(num);
if(isempty()){

cerr<<"empty"<<endl;




}

else{
node *current=head;
int cpos=0; /*cpos= current pos*/
while(current!=nullptr&&cpos<pos){
current=current->right;


}

if(current==nullptr){
    cerr<<"inapproirate approach"<<endl;
}
else{

if(current->left==nullptr){
head->left=newnode;
newnode->right=head;
head=newnode;
}
else if(current->right==nullptr){
tail->right=newnode;
newnode->left=tail;
tail=newnode;



}
else{
current->left->right=newnode;
newnode->left=current;
current->right->left=newnode;
newnode->right=current->right;

}



}


}







}





};







int main(){















}