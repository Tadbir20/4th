#include <iostream>
#include <climits>
using namespace std;

void fcfs(int n, int arrival[], int burst[]) {
    int time = 0, total_tat = 0, total_wt = 0, total_rt = 0;
    for (int i = 0; i < n; i++) {
        if (time < arrival[i]) time = arrival[i]; // Wait if necessary
        int start = time;
        int finish = start + burst[i];
        int rt = start - arrival[i]; // Response time
        total_wt += start - arrival[i];
        total_tat += finish - arrival[i];
        total_rt += rt;
        time = finish;
    }
    cout << "\n=== FCFS ===\n";
    cout << "Avg Turnaround Time: " << (double)total_tat / n << endl;
    cout << "Avg Waiting Time: " << (double)total_wt / n << endl;
    cout << "Avg Response Time: " << (double)total_rt / n << endl;
}

void srtf(int n, int arrival[], int burst[]) {
    int remaining[n], time = 0, complete = 0, minm, shortest;
    int tat[n], wt[n], rt[n];
    for (int i = 0; i < n; i++) remaining[i] = burst[i];

    while (complete != n) {
        minm = INT_MAX;
        shortest = -1;
        for (int i = 0; i < n; i++) {
            if (arrival[i] <= time && remaining[i] > 0 && remaining[i] < minm) {
                minm = remaining[i];
                shortest = i;
            }
        }
        if (shortest == -1) {
            time++;
            continue;
        }
        if (rt[shortest] == -1) rt[shortest] = time - arrival[shortest]; // First response time
        remaining[shortest]--;
        if (remaining[shortest] == 0) {
            complete++;
        }
        time++;
    }

    int total_tat = 0, total_wt = 0, total_rt = 0;
    for (int i = 0; i < n; i++) {
        tat[i] = time - arrival[i];  // Turnaround Time
        wt[i] = tat[i] - burst[i];  // Waiting Time
        total_tat += tat[i];
        total_wt += wt[i];
        total_rt += rt[i];
    }

    cout << "\n=== SRTF ===\n";
    cout << "Avg Turnaround Time: " << (double)total_tat / n << endl;
    cout << "Avg Waiting Time: " << (double)total_wt / n << endl;
    cout << "Avg Response Time: " << (double)total_rt / n << endl;
}

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int arrival[n], burst[n];
    cout << "Enter arrival times:\n";
    for (int i = 0; i < n; i++) {
        cout << "Arrival time for process " << i+1 << ": ";
        cin >> arrival[i];
    }

    cout << "Enter burst times:\n";
    for (int i = 0; i < n; i++) {
        cout << "Burst time for process " << i+1 << ": ";
        cin >> burst[i];
    }

    fcfs(n, arrival, burst); // Call FCFS
    srtf(n, arrival, burst); // Call SRTF

    return 0;
}
