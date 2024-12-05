#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, j, min;
    cin>>n;
    int a[n];

    for(i=0; i<n; i++)
    {
        cin>>a[i];
    }
    for(i=0; i<n-1; i++)
    {
        min = i;
        for(j=i+1; j<n; j++)
        {
            if(a[j]<a[min])
                min = j;
        }
        swap(a[min], a[i]);
    }

    cout<<"sorted by ascending order:  ";
    for(i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }

    return 0;
}
