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
    int x; cin >> x;
    queue<int> que;
    vector<bool> visited(n, false);
    que.push(x - 1);
    visited[x - 1] = true;
    cout << "BFS : ";
    while (!que.empty()) {
        int a = que.front();
        que.pop();
        cout << a + 1 << " ";
        for (int j = 0; j < n; j++) {
            if (arr[a][j] == 1 && !visited[j]) {
                que.push(j);
                visited[j] = true;
            }
        }
    }
}
