// CodeJAM 2018 Problem
#include<bits/stdc++.h>
using namespace std;
#define vi vector<int> 

void print(vi& vec){
    for(int i=0; i<vec.size(); i++){
        cout<<vec[i]<<" ";
    }
    cout<<"\n";
}

void TroubleSortWorked(vi &vec){
    vi odd, even, TroSoOutput;

    for(int i=0; i<vec.size(); i++){
        if(i%2 == 0) even.push_back(vec[i]);
        else odd.push_back(vec[i]);
    }

        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end());

    for(int i=0; i<vec.size(); i++){
        if(i%2 == 0){
            TroSoOutput.push_back(even[0]);
            even.erase(even.begin());

        }
        else{
            TroSoOutput.push_back(odd[0]);
            odd.erase(odd.begin());
        }
    }
    int flag = -1;
    for(int i=0; i<TroSoOutput.size(); i++){
        if(TroSoOutput[i]<TroSoOutput[i+1]) continue;
        else flag=i;
    }

    if(flag!=-1) cout<<flag;
    else cout<<"YES";
}

int main(){
    vi vec = {5, 8, 1};
    TroubleSortWorked(vec);
    return 0;
}