// Solution: 2
// Implement the following algorithms for identifying the connected components of a graph and complete the
// codes of the attached file connected_comp_incomplete.cpp.

#include <iostream>
#include <vector>

using namespace std;


void make_set(int p[], int x) {
    p[x] = x;
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
}

struct Edge {
    int u, v;
};


void connected_components(int p[], int V, vector<Edge> edges) {
    /// create the parent array for a disjoint set of V elements
    for (int i = 0; i < V; i++) {
        make_set(p, i);
    }

    /// for each edge (u, v) in the graph
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        /// if u and v are not in the same set
        if (find_set(p, u) != find_set(p, v)) {
            /// union u and v
            _union(p, u, v);
        }
    }
}

bool same_component(int p[], int u, int v) {
    return find_set(p, u) == find_set(p, v);
}

int main() {
    /// This code is for an undirected graph

    int V, E;
    /// take the number of vertices V and
    /// the number of edges E as input from user
    cin >> V >> E;

    /// take the E edges as input from the user
    vector<Edge> edges;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        Edge e{};
        e.u = u;
        e.v = v;
        edges.push_back(e);
    }

    /// create the parent array for a disjoint set of V elements
    int p[V];

    /// call the function connected_components
    connected_components(p, V, edges);


    while (1) {
        /// take an integer "option" as input.
        int option;
        cin >> option;

        /// if "option" is 1, take another integer x as input,
        /// check if x is an element of the disjoint set or not, and
        /// if it is then print the root/representative-element of x
        if (option == 1) {
            cout << "option 1: print the root" << endl;
            int x;
            cin >> x;
            if (x >= 0 && x < V) {
                cout << "root of " << x << " is " << find_set(p, x) << endl;
            } else {
                cout << x << " is not an element of the disjoint set" << endl;
            }
        }

            /// if "option" is 2, take integers x and y as input,
            /// check if x and y are elements of the disjoint set or not, and
            /// if they are, print whether they belong to the
            /// same connected component or not
        else if (option == 2) {
            cout << "option 2: same component or not" << endl;
            int x, y;
            cin >> x >> y;
            if (x >= 0 && x < V && y >= 0 && y < V) {
                if (same_component(p, x, y)) {
                    cout << x << " and " << y << " are in the same component" << endl;
                } else {
                    cout << x << " and " << y << " are not in the same component" << endl;
                }
            } else {
                cout << "invalid input" << endl;
            }

        }

            /// if "option" is 3, take integers x and y as input,
            /// check if x and y are elements of the disjoint set or not, and
            /// if they are, print if there is a path from x to y or not.
        else if (option == 3) {
            cout << "option 3: there is a path or not" << endl;
            int x, y;
            cin >> x >> y;
            if (x >= 0 && x < V && y >= 0 && y < V) {
                if (same_component(p, x, y)) {
                    cout << "there is a path between " << x << " and " << y << endl;
                } else {
                    cout << "there is no path between " << x << " and " << y << endl;
                }
            } else {
                cout << "invalid input" << endl;
            }
        }

            /// if "option" is 4, print all the roots of this disjoint set
        else if (option == 4) {
            cout << "option 4: print all the roots" << endl;
            for (int i = 0; i < V; i++) {
                if (i == find_set(p, i)) {
                    cout << i << " ";
                }
            }
            cout << endl;
        }

            /// if "option" is 5, print the vertices of each connected components
            /// in each line
        else if (option == 5) {
            cout << "option 5: vertices of each connected components" << endl;
            for (int i = 0; i < V; i++) {
                if (i == find_set(p, i)) {
                    for (int j = 0; j < V; ++j) {
                        if (find_set(p, i) == find_set(p, j)) {
                            cout << j << " ";
                        }
                    }
                    cout << endl;
                }
            }
            cout << endl;
        } else {
            return 0;
        }
    }

}
