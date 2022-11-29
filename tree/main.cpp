#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

struct point {
    short int x;
    short int y;
};

int main() {
    const double max = 1000000000000;
    freopen("spantree.in", "r", stdin);
    freopen("spantree.out", "w", stdout);
    short int n;
    double tmp, sum;
    cin >> n;
    vector<point> apex;
    apex.resize(n);
    vector<bool> used(n);
    vector<double> min(n, max);
    for (int i = 0; i < n; i++) {
        cin >> apex[i].x;
        cin >> apex[i].y;
    }
    tmp = 0;
    sum = 0;
    min[0] = 0;
    for (int i = 0; i < n; ++i) {
        int v = -1;
        for (int j = 0; j < n; ++j) {
            if (!used[j] && (v == -1 || min[j] < min[v])) {
                v = j;
            }
        }
        used[v] = true;
        sum += min[v];
        for (int to = 0; to < n; ++to) {
            if (v != to) {
                tmp = (sqrt((apex[v].x - apex[to].x) * (apex[v].x - apex[to].x) +
                            (apex[v].y - apex[to].y) * (apex[v].y - apex[to].y)));
                if (tmp < min[to]) {
                    min[to] = tmp;
                }
            }
        }
    }
    cout << fixed << setprecision(100) << sum << endl;
    return 0;
}
