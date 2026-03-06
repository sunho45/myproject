#include <iostream>
using namespace std;
int main(){
cout<<"please enter your number you want"<<endl;
int num;
cin>>num;
   while(true){
    string functions;
if(functions=="add"){
int x;

cout<<"please enter your position you want to add "<<endl;
cin>>x;
num|=1<<(x-1);


}


if(functions=="minus"){
int x;

cout<<"please enter your position you want to minus "<<endl;
cin>>x;
num&=~(1<<(x-1));


}
if(functions=="clear"){
num=0;

}
if(functions=="check"){
    int x;
    cin>>x;
if((1<<(x-1))==(num&=(1<<(x-1)))){
num&=~(1<<(x-1));


}

}


if(functions=="toggle"){
int x;

cout<<"please enter your position you want to toggle "<<endl;
cin>>x;

if((1<<(x-1))==(num&=(1<<(x-1)))){
num&=~(1<<(x-1));


}
else{
num|=1<<(x-1);

}


}




   }





   }
   












