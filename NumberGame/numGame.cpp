#include<bits/stdc++.h>
using namespace std;

string numberGameResultPred(int A, int B){
    if(A == B) return "B wins";
        
    if(A>B){
        if(A>=2*B){
            return "A wins";
        }
        else{
            return numberGameResultPred(A-B, B);
        }
    }
    else{
        if(B >= 2*A){
            return "B- wins";
        }
        else{
            return numberGameResultPred(A, B-A);
        }
    }
}

long long  int CountWinningPositions(int A1, int A2, int B1, int B2){
    long long int ANS=0;
    const double PHI=(1 + sqrt(5.0))/2;
    for (int b = B1; b <= B2; b++) {
        int low = floor(b / PHI);
        int high = floor(b * PHI);

        // winning positions: a < low OR a > high

        // count a < low
        int left = max(0, min(A2, low - 1) - A1 + 1);

        // count a > high
        int right = max(0, A2 - max(A1, high + 1) + 1);

        ANS += left + right;
    }
    return ANS;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif

    int T;
    cin>>T;

    while(T--){
        int A, B;
        cin>>A>>B;
        cout<<A<<" "<<B<<" "<<numberGameResultPred(A, B)<<"\n";

        int A1, A2, B1, B2;
        cin>>A1>>A2>>B1>>B2;
        cout<<CountWinningPositions(A1, A2, B1, B2)<<"\n";
    }

    return 0;
}