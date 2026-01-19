/*
Sorted Array
Two Pointer works for Sorted Array only.
*/

#include<iostream>
#include<vector>
using namespace std;

void printVec(vector<int>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

vector<int> BruteForcePS(vector<int>& vec, int target){
    vector<int> pair;
    for(int i=0; i<vec.size(); i++){
        for(int j=0; j<vec.size(); j++){
            if(vec[i]+vec[j] == target){
                pair.push_back(vec[i]);
                pair.push_back(vec[j]);
                return pair;
            }
        }
    }
    return pair;
    
}

vector<int> TwoPointerPS(vector<int>& vec, int target){
    vector<int> pair;
    int i=0, j=vec.size()-1;

    while(i<=j){
        if (vec[i]+vec[j] == target){
            pair.push_back(vec[i]);
            pair.push_back(vec[j]);
            return pair;
        }
        else if(vec[i]+vec[j]>target){
            j--;
        }
        else{
            i++;
        }
    }
    return pair;
}

int main(){
    vector<int> vec = {2, 7, 11, 17, 29};
    vector<int> pair1 = BruteForcePS(vec, 3);
    vector<int> pair2 = TwoPointerPS(vec, 1);
    printVec(pair1);
    printVec(pair2);
    return 0;
}