//
// Created on Dec 21 2022; 16:30
// File: solution_3.cpp
//

#include <iostream>
#include <vector>

struct Edge {
    int u, v, w;
};

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


bool same_component(int p[], int x, int y) {
    return find_set(p, x) == find_set(p, y);
}

void kruskal(int p[], const std::vector<Edge>& edges) {
    std::vector<Edge> solution;
    int cost = 0;
    for (auto &edge: edges) {
        if (find_set(p, edge.u) != find_set(p, edge.v)) {
            solution.push_back(edge);
            cost = cost + edge.w;
            _union(p, edge.u, edge.v);
        }
    }

    std::cout << "MST" << std::endl;
    for (auto &edge: solution) {
        std::cout << edge.u << "-" << edge.v << " " << std::endl;
    }
    std::cout << "Weight:";
    for (int i = 0; i < solution.size(); i++) {
        if (i == solution.size() - 1) {
            std::cout << solution[i].w;
        } else {
            std::cout << solution[i].w << "+";
        }
    }
    std::cout << "=" << cost << std::endl;

}


// Kruskal's Algorithm
int main(int argc, char **argv) {
    // Taking user input: Number of Vertices and Edges
    int V, E;
    std::cin >> V >> E;

    // Taking user input: Edges and weights of the graph
    std::vector<Edge> edges;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    // Create Parent Array
    int p[V];
    for (int i = 0; i < V; ++i) {
        make_set(p, i);
    }

    // Sort the edges in ascending order
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.w < b.w;
    });

    // Call Kruskal's Algorithm
    kruskal(p, edges);

    return 0;
}