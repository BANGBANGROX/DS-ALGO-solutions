#include<bits/stdc++.h>
using namespace std;

struct Job
{
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

bool comp(Job a, Job b) {
    if (a.dead != b.dead) return a.dead < b.dead;
    if (a.profit != b.profit) return a.profit > b.profit;
    return a.id < b.id;
}

vector<int> JobScheduling(Job a[], int n) {
    int noOfJobs = 0, totalProfit = 0;
    sort(a, a + n, comp);
    priority_queue<pair<int, pair<int, int>>> q;

    for (int i = n - 1; i > -1; --i) {
        int slotSize = a[i].dead;
        if (i > 0) slotSize -= a[i - 1].dead;
        q.push({ a[i].profit,{a[i].dead,a[i].id} });
        while (slotSize && !q.empty()) {
            int profit = q.top().first;
            int deadline = q.top().second.first;
            int id = q.top().second.second;
            q.pop();
            --slotSize;
            ++noOfJobs;
            totalProfit += profit;
        }
    }

    return { noOfJobs,totalProfit };
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        Job* j = new Job[n];
        for (int i = 0; i < n; ++i) {
            cin >> j[i].id >> j[i].dead >> j[i].profit;
        }

        vector<int> ans = JobScheduling(j, n);
        cout << ans[0] << " " << ans[1] << endl;
    }

    return 0;
}