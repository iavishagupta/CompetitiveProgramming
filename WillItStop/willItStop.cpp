#include<iostream>
using namespace std;
int willItStop(int n){
    if(n>1){
        if(((n ^ (n-1)) & n) == n) return 1;
        else return 0; 
    }
    return 0;
}

int main(){
    int i=0, n=100;
    while(i<=100){
        if(willItStop(i)) cout<<i<<" YES"<<endl;
        else cout<<i<<" NO"<<endl;
        i++;
    }
    return 0;
}