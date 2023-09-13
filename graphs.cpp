#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void addDirectedEdge(vector<vector<int> >& adjacencyList, int u, int v) {
    adjacencyList[u].push_back(v);
}

void addBiDirectedEdge(vector<vector<int> >& adjacencyList, int u , int v){
    adjacencyList[u].push_back(v);
    adjacencyList[v].push_back(u);
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

void BFS(vector<vector<int> > &adjacencyList, int startingNode, vector<bool> & visited){
    cout<<startingNode<<endl;
    queue<int> q;
    q.push(startingNode);
    visited[startingNode] = true;

    while (!q.empty())
    {
        int currNode = q.front();
        q.pop();

        for(int neighbor : adjacencyList[currNode]){
            if(!visited[neighbor]){
                cout<< neighbor << endl;
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int largestElementinGraph(vector<vector<int> >& adjacencyList, int startingNode, vector<bool> visited){
    int size = 1;
    queue<int> q;
    q.push(startingNode);
    visited[startingNode] = true;

    while (!q.empty())
    {
        int currElement = q.front();
        q.pop();

        for(int neighbour : adjacencyList[currElement]){
            if(!visited[neighbour]){
                visited[neighbour] = true;
                q.push(neighbour);
                size++;
            }
        }
    }
    return size;
}

int main() {
    int nOfVertices = 5;
    vector<vector<int> > adjacencyList(nOfVertices);
    int largest = -1;

    addDirectedEdge(adjacencyList, 0, 8);
    addDirectedEdge(adjacencyList, 0, 1);
    addDirectedEdge(adjacencyList, 0, 5);
    addDirectedEdge(adjacencyList, 1, 0);
    addDirectedEdge(adjacencyList, 5, 0);
    addDirectedEdge(adjacencyList, 5, 8);
    addDirectedEdge(adjacencyList, 8, 0);
    addDirectedEdge(adjacencyList, 8, 5);
    addDirectedEdge(adjacencyList, 2, 3);
    addDirectedEdge(adjacencyList, 2, 4);
    addDirectedEdge(adjacencyList, 3, 2);
    addDirectedEdge(adjacencyList, 3, 4);
    addDirectedEdge(adjacencyList, 4, 3);
    addDirectedEdge(adjacencyList, 4, 2);

    vector<bool> visited(nOfVertices, false);

    for (int i = 0; i < nOfVertices; i++) {
        if (!visited[i]) {
            int size = largestElementinGraph(adjacencyList, i, visited);
            if(size > largest){
                largest = size;
            }
        }
    }
    cout<<largest;


    for (int i = 0; i < nOfVertices; i++) {
        if (!visited[i]) {
            //DFS(adjacencyList, i, visited);
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
