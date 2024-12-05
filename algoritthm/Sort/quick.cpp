#include<bits/stdc++.h>
using namespace std;

void quick_sort(int arr[] , int low , int high){
    if(low <= high){
        int pivot = arr[low];
        int i = low , j = high;

        while(i < j){
            while(arr[i] <= pivot && i < high) i++;
            while(arr[j] > pivot && j > low) j--;

            if(i < j) swap(arr[i] , arr[j]);
        }
        swap(arr[low] , arr[j]);

        quick_sort(arr , low , j-1);
        quick_sort(arr , j+1 , high);
    }
}
int main(){
    int n; 
    cout << "Give the size of an array: "; cin >> n;
    int arr[n];
    cout << "Insert an array: "; for(int i = 0 ; i < n ; i++) cin >> arr[i]; cout << endl;

    quick_sort(arr , 0 , n-1);

    cout << "Final array: "; for(int i = 0 ; i < n ; i++) cout << arr[i] << " ";
}
