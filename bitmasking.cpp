#include <iostream>
using namespace std;

int main(){

int n;
cin>>n;
int bitmask=0;
while(n>0){
    string s;
    cin>>s;
    if(s=="exit"){
        return 0;
    }

    else if(s=="add"){
        int num;
        cin>>num;
        bitmask|=(1<<(num-1));


    }
    else if(s=="remove"){
        int num;
        cin>>num;
        bitmask&=~(1<<(num-1));



    }

    else if(s=="check"){
        int num;
        cin>>num;
        if(bitmask&(1<<(num-1))){
            cout<<"yes"<<endl;
        }
        else{
            cout<<"no"<<endl;
        }
    }
    else if(s=="toggle"){
        int num;
        cin>>num;
        bitmask^=(1<<(num-1));


    }
    else if(s=="all"){
        bitmask=(1<<n)-1; // n개의 비트 모두 1로 설정
    }
    else if(s=="empty"){
        bitmask=0; // 모든 비트 0으로 설정
    }
    else{
        cout<<"Invalid command"<<endl;
    }








}




}