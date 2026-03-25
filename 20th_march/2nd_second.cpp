#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

vector<int> parent;

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) parent[a] = b;
}

int kruskal(int n, vector<Edge>& edges, int skipEdgeIndex) {
    parent.resize(n + 1);
    for (int i = 1; i <= n; i++) parent[i] = i;

    int weight = 0, count = 0;

    for (int i = 0; i < edges.size(); i++) {
        if (i == skipEdgeIndex) continue;

        int u = edges[i].u;
        int v = edges[i].v;

        if (find(u) != find(v)) {
            unite(u, v);
            weight += edges[i].w;
            count++;
        }
    }

    if (count == n - 1) return weight;
    return INT_MAX;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);

    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    sort(edges.begin(), edges.end(), cmp);

    // Step 1: Find MST
    int mst = kruskal(n, edges, -1);

    // Step 2: Find second MST
    int secondMST = INT_MAX;

    for (int i = 0; i < m; i++) {
        int val = kruskal(n, edges, i);
        if (val > mst) {
            secondMST = min(secondMST, val);
        }
    }

    cout << mst << " " << secondMST << endl;
}