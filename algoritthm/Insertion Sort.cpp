#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];

    for(int i=1;i<n;i++)
    {
        int key=arr[i];
        int j=i;
        while(j>0 && arr[j-1]>key)
        {
            arr[j]=arr[j-1];
            j--;
        }
        arr[j]=key;

    }
    cout<<"Sorted Grades : ";
    for(int i=0;i<n;i++)cout<<arr[i]<<" ";




    return 0;
}
