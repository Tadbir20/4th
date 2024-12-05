#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, j, temp;
    cin>>n;
    int a[n];

    for(i=0; i<n; i++)
    {
        cin>>a[i];
    }
    for(i=1; i<n; i++)
    {
        temp=a[i];
        j=i-1;
        while(a[j]>temp && j>=0)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
    cout<<"sorted grades: ";
    for(i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }

    return 0;
}
