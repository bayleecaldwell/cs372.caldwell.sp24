#include <iostream>
#include <vector>

using namespace std;

bool hasSinkNode(const vector<vector<int>>& graph) {
    int n = graph.size();

    for (int i = 0; i < n; ++i) {
        bool isSinkNode = true;

        for (int j = 0; j < n; ++j) {
            if (graph[i][j] == 1) {
                isSinkNode = false;
                break;
            }
        }

        if (isSinkNode) {
            return true;
        }
    }

    return false;
}

int main() {
    vector<vector<int>> adjacencyMatrix = {
        {0, 1, 0, 0},
        {0, 0, 0, 0},
        {1, 0, 0, 0},
        {0, 1, 1, 0}
    };

    if (hasSinkNode(adjacencyMatrix)) {
        cout << "The graph has a sink node." << endl;
    } else {
        cout << "The graph does not have a sink node." << endl;
    }

    return 0;
}
