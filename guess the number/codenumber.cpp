#include<iostream>
#include<random>
#include<cstdlib>
using namespace std;

int main() {
    int randomnumber,attemp=0,x;
randomnumber=rand() %101;
cout<<"introdu numarul"<<endl;
     while( attemp<11)
    { cin>>x;
        attemp++;
        if(x==randomnumber){
        cout<<"ai ghicit"<<endl;
        return 0;}
        if(x<randomnumber) cout<<"mai mare"<<endl;
    else cout<<"mai mic"<<endl;

    } 
    cout<<"ai pierdut"<<" numarul era "<<randomnumber; } 




    


