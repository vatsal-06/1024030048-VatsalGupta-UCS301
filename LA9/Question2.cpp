#include <iostream>
#include <stack>
using namespace std;

void DFS(int** adjacencyMatrix, int numVertices, int source) {
    bool* visited = new bool[numVertices];
    for(int i = 0; i < numVertices; i++) {
        visited[i] = false;
    }

    stack<int> s;

    s.push(source);

    while(!s.empty()) {
        int u = s.top();
        s.pop();

        if(!visited[u]) {
            cout << u << " ";
            visited[u] = true;
        }

        for(int v = 0; v < numVertices; v++) {
            if(adjacencyMatrix[u][v] == 1 && !visited[v]) {
                s.push(v);
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

    DFS(adjacencyMatrix, numVertices, 0);

    return 0;
}