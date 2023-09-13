#include <iostream>
#include <vector>
#include <queue>
#include<unordered_set>
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

bool explore(vector<vector<char> >& grid, int r, int c, unordered_set<int>& visited, int numRows, int numCols) {
    // Boundary checks
    if (r < 0 || r >= numRows || c < 0 || c >= numCols) {
        return false;
    }
    if (grid[r][c] == 'W') { // Check if it's water
        return false;
    }

    // Calculate a unique index for the position
    int posIndex = r * numCols + c;

    // Check if the position has already been visited
    if (visited.find(posIndex) != visited.end()) {
        return false;
    }

    // Mark the position as visited
    visited.insert(posIndex);

    // Explore adjacent positions
    explore(grid, r + 1, c, visited, numRows, numCols);
    explore(grid, r, c + 1, visited, numRows, numCols);
    explore(grid, r - 1, c, visited, numRows, numCols);
    explore(grid, r, c - 1, visited, numRows, numCols);

    return true;
}
int islandCount(vector<vector<char> >& grid) {
    int count = 0;
    int numRows = grid.size();
    int numCols = grid[0].size();
    unordered_set<int> visited;

    for (int r = 0; r < numRows; r++) {
        for (int c = 0; c < numCols; c++) {
            if (explore(grid, r, c, visited, numRows, numCols) == true) {
                count++;
            }
        }
    }

    return count;
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
        //if (!visited[i]) {
            //int size = largestElementinGraph(adjacencyList, i, visited);
            //if(size > largest){
            //    largest = size;
            //}
        //}
    }
    //cout<<largest;


    for (int i = 0; i < nOfVertices; i++) {
        //if (!visited[i]) {
            //DFS(adjacencyList, i, visited);
        //}
    }

    //cout<<shortestPath(adjacencyList, 1, visited, 4);

    vector<vector<char> > grid {
        { 'W', 'L', 'W', 'W', 'W' },
        { 'W', 'L', 'W', 'W', 'W' },
        { 'W', 'W', 'W', 'L', 'W' },
        { 'W', 'W', 'L', 'L', 'W' },
        { 'L', 'W', 'W', 'L', 'L' },
        { 'L', 'L', 'W', 'W', 'W' }
    };

    cout << islandCount(matrix) << endl;
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
