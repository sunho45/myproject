#include <iostream>
using namespace std;

void add(int **num){
    (**num)++;
    (*num)++;


}


void addarr(int *arr){
    int sum=0;
for(int i=0;i<9;i++){

    cout<<*(arr+i)<<endl;

}




}
struct student{
int score;
string name;


};

int main(){

    int arr[9]={1,5,7,4,3,2,4,5,8};

    int (*p)[9]=&arr;
    int b=30;
int *a=&b;
int **aa=&a;

cout<<(*p)[0]<<endl;




}