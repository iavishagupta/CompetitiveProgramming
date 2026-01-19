#include <iostream>
#include <climits>
#include <vector>
using namespace std;

void printArr(int arr[], int st, int end) {
    for (int i = st; i <= end; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int BruteForce(vector<int>& arr) {
    int max_sum = INT_MIN;

    for (int i = 0; i < arr.size(); i++) {
        int sum = 0;
        for (int j = i; j < arr.size(); j++) {
            sum += arr[j];
            max_sum = max(max_sum, sum);
        }
    }

    return max_sum;
}

int KadanesAlgorithm(vector<int>& nums) {
    int sum=0, max_sum=INT_MIN;
    for(int val: nums){
        sum+=val;
        max_sum=max(sum, max_sum);
        if(sum<0) sum=0;
    }
    return max_sum;
}

int main() {
    vector<int> arr = {3, -4, 5, 4, -1, 7, -8};

    cout << "Maximum Subarray Sum:\n1. Brute Force: "
         << BruteForce(arr)<<"\n2. Kadane's Algorithm: "<<KadanesAlgorithm(arr);

    return 0;
}
