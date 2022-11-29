#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("spantree3.in", "r", stdin);
    freopen("spantree3.out", "w", stdout);
    priority_queue<pair<int, pair<int, int>>> graf;
    int max_radix, m;
    long int n, x, y, w;
    long long sum = 0;
    max_radix = 0;
    cin >> n >> m;
    vector<int> used(n, 0);
    vector<vector<int>> comp(n);
    pair<long int, pair<long int, long int>> tmp;
    int max = 0;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> w;
        x--;
        y--;
        tmp.second.second = y;
        tmp.second.first = x;
        tmp.first = w * -1;
        if (w > max) {
            max = w;
        }
        graf.push(tmp);
        if (n <= m) {
            if (i < n) {
                used[i] = i;
                comp[i].push_back(i);
            }
        }
    }
    if (n > m) {
        for (int i = 0; i < n; i++) {
            used[i] = i;
            comp[i].push_back(i);
        }
    }
    long int j, k, fl;
    j = 0;
    sum = 0;
    bool flag = 1;
    for (int i = 0; i < m; i++) {
        tmp = graf.top();
        graf.pop();
        long int left, right;
        left = tmp.second.first;
        right = tmp.second.second;
        if (used[left] != used[right]) {
            int a, b;
            a = used[left];
            b = used[right];
            if (comp[a].size() < comp[b].size()) {
                swap(a, b);
            }
            while (!comp[b].empty()) {
                int tmp3 = comp[b].back();
                comp[b].pop_back();
                used[tmp3] = a;
                comp[a].push_back(tmp3);
            }
            if ((comp[a].size() == n) || (comp[b].size() == n)) {
                flag = 0;
            }
            sum += tmp.first * -1;
        }
    }
    cout << sum;
    return 0;
}
