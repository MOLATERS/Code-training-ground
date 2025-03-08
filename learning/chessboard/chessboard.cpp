#include <iostream>
using namespace std;

int main(){
    int n,m;
    while(cin>>n>>m){
        if(n==1&&m==1) cout<<"Y"<<endl; 
        else if(n==1||m==1) cout<<"N"<<endl; 
        else if(n%2==0||m%2==0) cout<<"Y"<<endl;
        else cout<<"N"<<endl;
    }
    return 0;
}
