#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>&arr , int left , int mid , int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int>arr1(n1) , arr2(n2);

    for(int i = 0 ; i < n1 ; i++) arr1[i] = arr[left + i];
    for(int i = 0 ; i < n2 ; i++) arr2[i] = arr[mid + 1 + i];

    int i = 0 , j = 0;
    int k = left;

    while(i < n1 && j < n2){
        if(arr1[i] <= arr2[j]){
            arr[k] = arr1[i];
            i++;
            k++;
        }else{
            arr[k] = arr2[j];
            j++;
            k++;
        }
    }

    while(i < n1){
        arr[k] = arr1[i];
        i++;
        k++;
    }
    while(j < n2){
        arr[k] = arr2[j];
        j++;
        k++;
    }
}
void merge_sort(vector<int>&arr , int left , int right){
    if(left >= right) return;
    int mid = left + (right - left) / 2;

    merge_sort(arr , left , mid);
    for(int i = left ; i <= mid ; i++) cout << arr[i] << "<-";
    cout << endl;
    merge_sort(arr , mid + 1 , right);
    for(int i = mid + 1 ; i <= right ; i++) cout << arr[i] << "->";
    cout << endl;

    merge(arr , left , mid , right);
}

int main(){
    int n;
    cout << "Enter array size : ";
    cin >> n;
    vector<int>arr(n);
    cout << "Enter the array : ";
    for(int i = 0 ; i < n ; i++) cin >> arr[i];

    merge_sort(arr , 0 , n-1);

    cout << endl;
    cout << "Final array : ";
    for(int i = 0 ; i < arr.size() ; i++) cout << arr[i] << " ";
}
