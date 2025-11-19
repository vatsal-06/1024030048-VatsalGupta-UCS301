#include <iostream>
#include <queue>
using namespace std;

void BFS(int** adjacencyMatrix, int numVertices, int source) {
    bool* visited = new bool[numVertices];
    for(int i = 0; i < numVertices; i++) {
        visited[i] = false;
    }

    queue<int> q;

    q.push(source);
    visited[source] = true;

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        cout << u << " ";

        for(int v = 0; v < numVertices; v++) {
            if(adjacencyMatrix[u][v] == 1 && !visited[v]) {
                q.push(v);
                visited[v] = true;
            }
        }
    }
};

int main() {
    int numVertices = 5;
    int** adjacencyMatrix = new int*[numVertices];
    for (int i = 0; i < numVertices; i++) {
        adjacencyMatrix[i] = new int[numVertices];
    }
    adjacencyMatrix[0][1] = 1;
    adjacencyMatrix[0][3] = 1;
    adjacencyMatrix[3][2] = 1;
    adjacencyMatrix[1][3] = 1;
    adjacencyMatrix[2][3] = 1;
    adjacencyMatrix[3][4] = 1;

    BFS(adjacencyMatrix, numVertices, 0);

    return 0;
}