#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Number of vertices: ";
    cin >> n;
    int edge;
    cout << "Number of edges : ";
    cin >> edge;
    vector<pair<pair<int, int>, int>> saijja(edge);
    for (int i = 0; i < edge; i++) {
        int x, y, z;
        cout << "Edge " << i + 1 << ": " << endl << "i,j : ";
        cin >> x >> y;
        cout << "Enter the value of edge : ";
        cin >> z;
        saijja[i] = {{x, y}, z};
    }
    vector<long long> result(n,INT_MAX);
    result[0] = 0;
    for(int i = 0 ; i < n - 1 ; i++){
        int check = 0;
        for(int j = 0 ; j < edge ; j++){
            int a = saijja[j].first.first - 1;
            int b = saijja[j].first.second - 1;
            int c = saijja[j].second;
            if(result[a] + c < result[b]) result[b] = result[a] + c , check = 1;
        }
        if(check == 0) break;
    }
    cout << endl << "vertices and their values : " << endl;
    for(int i = 0 ; i < n ; i++) cout << "Node " << i+1 << " : " << result[i] << endl;
}
