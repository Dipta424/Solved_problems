#include <bits/stdc++.h>
#include <queue>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;

    // Store n pairs of type ((int, int), int)
    vector<pair<pair<int,int>,int>>pairs(n);
    for (int i = 0; i < n; i++) {
        cin >> pairs[i].first.first;
    }
    for (int i = 0; i < n; i++) {
        cin >> pairs[i].first.second;
    }
    for (int i = 0; i < n; i++) {
        cin >> pairs[i].second;
    }

    // hash map creating
    unordered_map<int, priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>> pair_map;
    int m;
    cin >> m;
    vector<int>v(m);
    for (int i = 0; i < m; i++) {
      cin>>v[i];
    }

    for (int i = 0; i < n; i++) {
      int key1 = pairs[i].first.second;
      int key2 = pairs[i].second;
      int val = pairs[i].first.first;

      pair_map[key1].push({val, i});
      pair_map[key2].push({val, i});
    }

    unordered_set<int> idx_used;
    
    for (int i = 0; i < m; i++) {
      int target = v[i];

      if (pair_map.find(target) == pair_map.end()) {
        cout<<-1<<" ";
      }
      else {
        bool ck = true;
        while (!pair_map[target].empty()) {
          auto [val, idx] = pair_map[target].top();
          pair_map[target].pop();

          if (idx_used.find(idx) == idx_used.end()) {
            cout << val << " ";
            idx_used.insert(idx);
            ck = false;
            break;
          }
        }
        if (ck)
          cout<<-1<<" ";
      }
    }
}