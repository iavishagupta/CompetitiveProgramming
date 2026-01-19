/* To find majority element */

#include<iostream>
#include<vector>
using namespace std;

int MooresAlgo(vector<int>& nums){
    int frequency=0, element=0;

    for(int i=0; i<nums.size(); i++){
        if(frequency==0) element=nums[i];
        
        if(element == nums[i]){
            frequency++;
        }
        else{
            frequency--;
        }
    }
    if(frequency>0) return element;
    return -1;
}

int main(){
    vector<int> vec = {6, 6, 7, 6, 6, 2, 6, 3};
    cout<<"Majority Element: "<<MooresAlgo(vec);
    return 0;
}