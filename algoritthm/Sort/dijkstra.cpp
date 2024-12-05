#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<long long>> arr = {
        {0, 50, 45, 10, 0, 0},
        {0, 0, 10, 15, 0, 0},
        {0, 0, 0, 0, 30, 0},
        {10, 0, 0, 0, 15, 0},
        {0, 20, 35, 0, 0, 0},
        {0, 0, 0, 0, 3, 0}};
    vector<long long> path = {INT_MAX, 50, 45, 10, INT_MAX, INT_MAX};
    vector<long long> check = path;
    for (int i = 1; i < path.size(); i++){
        int node = 0;
        for (int k = 0; k < path.size() - 1; k++)
            if (check[k + 1] < check[k])
                node = k + 1;
        check[node] = INT_MAX;
        for (int j = 0; j < path.size(); j++)
            if (arr[node][j] != 0 && (path[node] + arr[node][j] < path[j]))
                path[j] = path[node] + arr[node][j], check[j] = path[j];
    }
    for (int i = 1; i < path.size(); i++)
        cout << path[i] << " ";
}
