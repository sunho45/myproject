/* this program is queue*/

#include <iostream>
#include <queue>
using namespace std;

class node{

    public:
        int data;
        node *prev;
        node *next;
        node(int data):data(data), prev(nullptr), next(nullptr) {}
            
        };










class queue{
    public:
        queue():head(nullptr), tail(nullptr) {}
    node *head, *tail;



    bool isempty(){
        return head==nullptr&& tail==nullptr;
    }
    void push_front(int data){
        if(isempty()){

            head=tail=new node(data);
        }

        else{
            node *newnode=new node(data);
            newnode->next=head;

            head->prev=newnode;
           head=newnode;
            




        }





    }

    void push_back(int data){
        if(isempty()){

            head=tail=new node(data);
        }

        else{
            node *newnode=new node(data);
            tail->next=newnode;
            newnode->prev=tail;
            tail=newnode;
        }   





    }
    
    int pop_back(){
        if(isempty()){

            throw runtime_error("Queue is empty");
        }

        else{
            node *temp=tail;
            int num=tail->data;
            tail=tail->prev;
             if(tail){
                tail->next=nullptr;
             }
             else{
                head=nullptr;
             }
            delete temp;


            return num;
        }   





    }
    int pop_front(){
        if(isempty()){

            throw runtime_error("Queue is empty");
        }

        else{
            node *temp=head;
            int num=head->data;
            head=head->next;
            if(head){
                head->prev=nullptr;
            }
            else{
                tail=nullptr;
            }



            head->prev=nullptr;
            delete temp;


            return num;
        }   





    }
    void insert(int data, int num){
        node *newnode=new node(data);
        if(isempty()){
            tail=head=newnode;

        }
        else{
            node *current=head;
            int i=0;
            while(current!=nullptr && i<num){
                current=current->next;
                i++;
            }
            if(current==nullptr){

                tail->next=newnode;
                newnode->prev=tail;
                tail=newnode;
            }

            else{
                if(current->prev==nullptr){
                    newnode->next=head;
                    head->prev=newnode;
                    head=newnode;


                }
                else{
                    current->prev->next=newnode;
                    newnode->prev=current->prev;
                    current->prev=newnode;
                    newnode->next=current;




                }





            }









        }






    }













};