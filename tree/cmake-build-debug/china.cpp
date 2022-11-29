#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

struct rib {
    int to;
    int w;
};
bool used[1000];
vector<int> order, component;

void dfs(vector<vector<rib> > &g, int v) {
    used[v] = true;
    for (rib e: g[v]) {
        if (!used[e.to]) {
            dfs(g, e.to);
        }
    }
}


void dfs1(int v, vector<vector<rib> > &g) {
    used[v] = true;
    for (rib e: g[v]) {
        if (!used[e.to]) {
            dfs1(e.to, g);
        }
    }
    order.push_back(v);
}

void dfs2(int v, vector<vector<rib> > &gr) {
    used[v] = true;
    component.push_back(v);
    for (rib e: gr[v]) {
        if (!used[e.to]) {
            dfs2(e.to, gr);
        }
    }
}

void condensation(vector<vector<rib> > &g, vector<int> &comp, int &countOfCond) {
    vector<vector<rib> > gr(g.size());
    rib e1;
    for (int i = 0; i < g.size(); ++i) {
        for (rib e: g[i]) {
            e1.to = i;
            gr[e.to].push_back(e1);
        }
    }
    for (int i = 0; i < g.size(); i++)
        used[i] = false;
    order.clear();
    for (int i = 0; i < g.size(); ++i) {
        if (!used[i]) {
            dfs1(i, g);
        }
    }
    for (int i = 0; i < g.size(); i++)
        used[i] = false;
    for (int i = gr.size() - 1; i >= 0; --i) {
        int v = order[i];
        if (!used[v]) {
            dfs2(v, gr);
            for (int i: component) {
                comp[i] = countOfCond;
            }
            countOfCond++;
            component.clear();
        }
    }
}

long long findMST(vector<vector<rib> > &g, int n, int root) {
    long long res = 0;
    auto minEdge = new int[n];
    for (int i = 0; i < n; ++i)
        minEdge[i] = 1000000000;
    for (vector<rib> i: g) {
        for (rib e: i) {
            minEdge[e.to] = min(e.w, minEdge[e.to]);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (i != root) {
            res += minEdge[i];
        }
    }
    vector<vector<rib> > zeroEdges(n);
    for (int i = 0; i < g.size(); ++i) {
        for (rib e: g[i]) {
            if (e.w == minEdge[e.to]) {
                zeroEdges[i].push_back(e);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        used[i] = false;
    }
    dfs(zeroEdges, root);
    bool flag = false;
    for (int i = 0; (i < n) && (!flag); ++i) {
        if (!used[i]) {
            flag = true;
        }
    }
    if (!flag) {
        return res;
    }
    int countOfCond = 0;
    vector<int> comp(n);
    condensation(zeroEdges, comp, countOfCond);
    vector<vector<rib> > cond(countOfCond);
    rib e1;
    for (int i = 0; i < g.size(); ++i) {
        for (rib e: g[i]) {
            if (comp[i] != comp[e.to]) {
                e1.to = comp[e.to];
                e1.w = e.w - minEdge[e.to];
                cond[comp[i]].push_back(e1);
            }
        }
    }
    res += findMST(cond, countOfCond, comp[root]);
    return res;
}

int main() {
    freopen("chinese.in", "r", stdin);
    freopen("chinese.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        used[i] = false;
    }
    int from;
    rib e1;
    vector<vector<rib> > g(n);
    for (int i = 0; i < m; ++i) {
        cin >> from >> e1.to >> e1.w;
        --from;
        --e1.to;
        g[from].push_back(e1);
    }
    dfs(g, 0);
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES" << '\n' << findMST(g, n, 0);
    return 0;
}

