#include <stdio.h>
#include <stdbool.h>

#define V 5 // Number of vertices in the graph

void printSolution(int path[V]);
bool isSafe(int v, bool graph[V][V], int path[], int pos);
bool hamiltonianCycleUtil(bool graph[V][V], int path[], int pos);

void hamiltonianCycle(bool graph[V][V]) {
    int path[V];
    for (int i = 0; i < V; i++)
        path[i] = -1;

    path[0] = 0;

    if (hamiltonianCycleUtil(graph, path, 1) == false) {
        printf("Hamiltonian Circuit does not exist.\n");
        return;
    }

    printSolution(path);
}

bool hamiltonianCycleUtil(bool graph[V][V], int path[], int pos) {
    if (pos == V) {
        // Check if there is an edge from the last vertex to the first vertex
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }

    for (int v = 1; v < V; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;

            if (hamiltonianCycleUtil(graph, path, pos + 1) == true)
                return true;

            path[pos] = -1;
        }
    }

    return false;
}

bool isSafe(int v, bool graph[V][V], int path[], int pos) {
    if (graph[path[pos - 1]][v] == 0)
        return false;

    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

void printSolution(int path[V]) {
    printf("Hamiltonian Circuit exists:\n");
    for (int i = 0; i < V; i++)
        printf("%d ", path[i]);
    printf("%d\n", path[0]); // Print the first vertex again to complete the cycle
}

int main() {
    bool graph[V][V];

    // Input the adjacency matrix from the user
    printf("Enter the adjacency matrix for the graph:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    hamiltonianCycle(graph);

    return 0;
}
