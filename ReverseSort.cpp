#include<iostream>
using namespace std;

void printArr(int arr[], int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

int minVal(int arr[], int start, int end){
    int min = INT16_MAX, idx;
    for(int i=start; i<end; i++){
         if (min>arr[i]){
            min = arr[i];
            idx = i;
         }
    }
    return min, idx;
}

void reverse(int arr[], int start_idx, int last_idx){
    int i = start_idx, j = last_idx;
    while(i<j){
        swap(arr[i], arr[j]);
        i++; j--;
    }
    return;
}

void reverseSort(int arr[], int size){
    int min, idx;
    for(int i=0; i<size-1; i++){
        min, idx = minVal(arr, i, size);
        reverse(arr, i, idx);
        printArr(arr, size);
    }
}
int main(){
    int arr[5] = {31,72,13,41,2};
    int size = sizeof(arr)/sizeof(int);
    printArr(arr, size);
    reverseSort(arr, size);

    return 0;
}