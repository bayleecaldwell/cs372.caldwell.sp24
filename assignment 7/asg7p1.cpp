#include <iostream>
#include <vector>
#include <algorithm>

class Graph {
public:
    Graph(int numVertices) : numVertices(numVertices) {}
    virtual void addEdge(int v1, int v2) = 0;
    virtual void removeEdge(int v1, int v2) = 0;
    virtual void display() = 0;
protected:
    int numVertices;
};

class AdjacencyListGraph : public Graph {
public:
    AdjacencyListGraph(int numVertices) : Graph(numVertices) {
        adjList.resize(numVertices);
    }
    
    void addEdge(int v1, int v2) override {
        adjList[v1].push_back(v2);
        adjList[v2].push_back(v1);
    }
    
    void removeEdge(int v1, int v2) override {
        auto it1 = std::find(adjList[v1].begin(), adjList[v1].end(), v2);
        if (it1 != adjList[v1].end()) adjList[v1].erase(it1);

        auto it2 = std::find(adjList[v2].begin(), adjList[v2].end(), v1);
        if (it2 != adjList[v2].end()) adjList[v2].erase(it2);
    }
    
    void display() override {
        for (int i = 0; i < numVertices; ++i) {
            std::cout << "Vertex " << i << ": ";
            for (int v : adjList[i]) {
                std::cout << v << " ";
            }
            std::cout << std::endl;
        }
    }
private:
    std::vector<std::vector<int>> adjList;
};

class AdjacencyMatrixGraph : public Graph {
public:
    AdjacencyMatrixGraph(int numVertices) : Graph(numVertices) {
        adjMatrix.resize(numVertices, std::vector<int>(numVertices, 0));
    }
    
    void addEdge(int v1, int v2) override {
        adjMatrix[v1][v2] = 1;
        adjMatrix[v2][v1] = 1;
    }
    
    void removeEdge(int v1, int v2) override {
        adjMatrix[v1][v2] = 0;
        adjMatrix[v2][v1] = 0;
    }
    
    void display() override {
        for (int i = 0; i < numVertices; ++i) {
            std::cout << "Vertex " << i << ": ";
            for (int j = 0; j < numVertices; ++j) {
                if (adjMatrix[i][j] == 1) {
                    std::cout << j << " ";
                }
            }
            std::cout << std::endl;
        }
    }
private:
    std::vector<std::vector<int>> adjMatrix;
};

int main() {
    AdjacencyListGraph adjListGraph(5);
    adjListGraph.addEdge(0, 1);
    adjListGraph.addEdge(0, 2);
    adjListGraph.addEdge(1, 3);
    adjListGraph.addEdge(2, 4);
    adjListGraph.display();

    std::cout << std::endl;

    AdjacencyMatrixGraph adjMatrixGraph(5);
    adjMatrixGraph.addEdge(0, 1);
    adjMatrixGraph.addEdge(0, 2);
    adjMatrixGraph.addEdge(1, 3);
    adjMatrixGraph.addEdge(2, 4);
    adjMatrixGraph.display();

    return 0;
}
