#include<iostream>
#include<random>
#include<cstdlib>
using namespace std;

int main() {
    int randomnumber,attemp=10,x;
randomnumber=rand() %101;
cout<<"introdu numarul"<<endl;
cin>>x;
attemp++;
     while(x!=randomnumber)
    {
        if(x<randomnumber) cout<<"mai mare"<<endl;
    else cout<<"mai mic"<<endl;
    cin>>x;
    attemp++;

    }
    cout<<"ai ghicit"<<endl; }



    


