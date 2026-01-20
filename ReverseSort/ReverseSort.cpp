#include<bits\stdc++.h>
using namespace std;

#define vi vector<int>

void printVec(vi& vec){
    for(int val: vec){
        cout<<val<<" ";
    }
    cout<<"\n";
}

int reverseSort(vi& vec){

    int cost=0;

    for(int i=0; i<vec.size()-1; i++){

        int min= *min_element(vec.begin() + i, vec.end());
        auto x = find(vec.begin(), vec.end(), min);
        reverse(vec.begin() + i, x+1);
        cost += distance(vec.begin(), x) - i + 1;
    }
    return cost;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif 

    std::ios::sync_with_stdio(false);

    int T;
    cin>>T;

    for(int c=1; c<T+1; c++){
        vi vec;

        int N;
        cin>>N;

        for(int i=0; i<N; i++){
            int num;
            cin>>num;
            vec.push_back(num);
        }
        cout<<"Case #"<<c<<"-\n";
        cout<<"\tUnsorted Array: ";
        printVec(vec);
        cout<<"\tCost: "<<reverseSort(vec)<<"\n"<<"\tSorted: ";
        printVec(vec);
        cout<<"\n";
    }
    return 0;
}