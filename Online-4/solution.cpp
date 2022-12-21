#include <iostream>
#include <vector>

using namespace std;

// Connected Component Edge
struct Edge {
    int u, v;
};

void make_set(int p[], int x) {
    p[x] = x;
    cout << "making a one-element set of " << x << endl;
}

int find_set(int p[], int x) {
    if (x != p[x])
        return find_set(p, p[x]);
    return p[x];
}

void _union(int p[], int x, int y) {
    int a = find_set(p, x);
    int b = find_set(p, y);
    p[a] = b;
    cout << "union " << a << " and " << b << endl;
}

bool same_component(int p[], int x, int y) {
    return find_set(p, x) == find_set(p, y);
}


// Connected components
void connected_components(int p[], int V, vector<Edge> edges) {
    for (int i = 0; i < V; i++) {
        make_set(p, i);
    }

    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        if (find_set(p, u) != find_set(p, v)) {
            _union(p, u, v);
        }
    }
}


int main() {
    // Taking user input: Number of Vertices
    int vertices;
    cin >> vertices;

    // Taking user input: Number of edges
    int edge;
    cin >> edge;

    // Taking user input: Edges of the graph
    vector<Edge> edges;
    for (int i = 0; i < edge; ++i) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    // Taking user input: n pair of vertices
    int n;
    cin >> n;

    // Create Parent Array
    int p[vertices];
    connected_components(p, vertices, edges);

    // Taking user input: Testing the inputs
    for (int i = 0; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        if (same_component(p, u, v)) {
            cout << u << " and " << v << " are in the same component" << endl;
        } else
            cout << u << " and " << v << " are not in the same component" << endl;
    }
}
