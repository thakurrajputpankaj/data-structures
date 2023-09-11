#include <iostream>
#include <vector>

using namespace std;

void addDirectedEdge(vector<vector<int> >& adjacencyList, int u, int v) {
    adjacencyList[u].push_back(v);
}

void DFS(vector<vector<int> >& adjacencyList, int startingNode, vector<bool>& visited) {
    visited[startingNode] = true;
    cout << startingNode << endl;
    for (int neighbor : adjacencyList[startingNode]) {
        if (!visited[neighbor]) {
            DFS(adjacencyList, neighbor, visited);
        }
    }
}

int main() {
    int nOfVertices = 5;
    vector<vector<int> > adjacencyList(nOfVertices);

    addDirectedEdge(adjacencyList, 0, 1);
    addDirectedEdge(adjacencyList, 0, 2);
    addDirectedEdge(adjacencyList, 1, 2);
    addDirectedEdge(adjacencyList, 2, 3);
    addDirectedEdge(adjacencyList, 3, 4);

    vector<bool> visited(nOfVertices, false);
    for (int i = 0; i < nOfVertices; i++) {
        if (!visited[i]) {
            DFS(adjacencyList, i, visited);
        }
    }

    return 0;
}


/**
 * {
 *  0 : [1,2]
 *  1 : [2]
 *  2 : [3]
 *  3 : [4]
 * }
*/
