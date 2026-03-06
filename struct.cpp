
#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>
using namespace std;

class path{

    private :
        int x,y;
    public: 
        path(int x,int y):x(x),y(y){}
        int getX() const { return x; }
        int getY() const{return  y;}




};



int main(){

    unordered_map<string,int> m;
    string s;
    cin>>s;
    m[s]=10;
    int a=m.count(s) ? m[s] : 0;
    
    cout<< "Value for 'apple': " << a << endl;

    m.emplace("banana", 20);
    m.emplace("orange", 30);
    cout << "Size of map: " << m.size() << endl;

    






}
