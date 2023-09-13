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

int shortestPath(vector<vector<int> >& adjacencyList, int startingNode, vector<bool> visited, int target){
    queue<pair<int,int> > q;
    pair<int,int> _p;
    _p.first = startingNode;  _p.second = 0; 
    q.push(_p);
    visited[startingNode] = true;

    while (!q.empty())
    {
        pair<int,int> _p_curr = q.front();
        q.pop();

        if(_p_curr.first == target){
            return _p_curr.second;
        }

        for(int neighbour : adjacencyList[_p_curr.first]){
            if(!visited[neighbour]){
                visited[neighbour] = true;
                pair<int,int> p;
                p.first = neighbour; p.second = _p_curr.second + 1;
                q.push(p);
            }
        }
    }
    return -1;
}


int main() {
    int nOfVertices = 5;
    vector<vector<int> > adjacencyList(nOfVertices);
    int largest = -1;

    addDirectedEdge(adjacencyList, 1, 2);
    addDirectedEdge(adjacencyList, 2, 3);
    addDirectedEdge(adjacencyList, 4, 3);
    addDirectedEdge(adjacencyList, 4, 5);
    addDirectedEdge(adjacencyList, 1, 5);
    addDirectedEdge(adjacencyList, 2, 1);
    addDirectedEdge(adjacencyList, 3, 2);
    addDirectedEdge(adjacencyList, 3, 4);
    addDirectedEdge(adjacencyList, 5, 4);
    addDirectedEdge(adjacencyList, 5, 1);

    vector<bool> visited(nOfVertices, false);

    for (int i = 0; i < nOfVertices; i++) {
        if (!visited[i]) {
            //int size = largestElementinGraph(adjacencyList, i, visited);
            //if(size > largest){
            //    largest = size;
            //}
        }
    }
    //cout<<largest;


    for (int i = 0; i < nOfVertices; i++) {
        if (!visited[i]) {
            //DFS(adjacencyList, i, visited);
        }
    }

    cout<<shortestPath(adjacencyList, 1, visited, 4);
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
