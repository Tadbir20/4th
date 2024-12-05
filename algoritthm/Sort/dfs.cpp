#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            cout << i + 1 << "--" << j + 1 << " :  ";
            cin >> arr[i][j];
            arr[j][i] = arr[i][j];
        }
        cout << endl;
    }
    cout << "Starting vertex : ";
    int i; cin >> i;
    stack<int>stk;
    vector<bool>visited(n,false);
    stk.push(i);
    visited[i-1] = true;
    cout << "DFS : " << i << " ";
    while(!stk.empty()){
        int a = stk.top();
        bool check = false;
        for(int j = 0 ; j < n ; j++){
            if(arr[a-1][j] == 1 && !visited[j]){
                arr[a-1][j] = 0;
                arr[j][a-1] = 0;
                stk.push(j + 1);
                visited[j] = true;
                cout << j + 1 << " ";
                check = true;
                break;
            }
        }
        if(!check) stk.pop();
    }
}
