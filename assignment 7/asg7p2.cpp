#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <unordered_set>

class SocialGraph {
public:
    void addEdge(const std::string& person1, const std::string& person2) {
        graph[person1].push_back(person2);
        graph[person2].push_back(person1);
    }

    std::pair<bool, std::vector<std::string>> areConnected(const std::string& person1, const std::string& person2) {
        if (!graph.count(person1) || !graph.count(person2))
            return {false, {}};

        std::unordered_set<std::string> visited;
        std::queue<std::vector<std::string>> q;
        q.push({person1});

        while (!q.empty()) {
            auto path = q.front();
            q.pop();
            auto node = path.back();

            if (node == person2)
                return {true, path};

            if (visited.find(node) == visited.end()) {
                visited.insert(node);
                for (const auto& neighbor : graph[node]) {
                    auto new_path = path;
                    new_path.push_back(neighbor);
                    q.push(new_path);
                }
            }
        }

        return {false, {}};
    }

private:
    std::unordered_map<std::string, std::vector<std::string>> graph;
};

int main() {
    SocialGraph socialNetwork;

    socialNetwork.addEdge("You", "Friend1");
    socialNetwork.addEdge("You", "Friend2");
    socialNetwork.addEdge("You", "Friend3");
    socialNetwork.addEdge("Friend1", "Friend4");
    socialNetwork.addEdge("Friend2", "Friend5");
    socialNetwork.addEdge("Friend3", "Friend6");
    socialNetwork.addEdge("Friend4", "Friend7");
    socialNetwork.addEdge("Friend5", "Friend8");
    socialNetwork.addEdge("Friend6", "Friend9");
    socialNetwork.addEdge("Friend7", "Friend10");
    socialNetwork.addEdge("Friend8", "Friend11");
    socialNetwork.addEdge("Friend9", "Friend12");
    socialNetwork.addEdge("Friend10", "Friend13");
    socialNetwork.addEdge("Friend11", "Friend14");
    socialNetwork.addEdge("Friend12", "Friend15");
    socialNetwork.addEdge("Friend13", "Kevin Bacon");
    socialNetwork.addEdge("Friend14", "Friend16");
    socialNetwork.addEdge("Friend15", "Friend17");

    auto [connected, path] = socialNetwork.areConnected("You", "Kevin Bacon");
    if (connected) {
        std::cout << "You are connected to Kevin Bacon!" << std::endl;
        std::cout << "Path: ";
        for (size_t i = 0; i < path.size() - 1; ++i)
            std::cout << path[i] << " -> ";
        std::cout << path.back() << std::endl;
    } else {
        std::cout << "You are not connected to Kevin Bacon!" << std::endl;
    }
    
    
    return 0;
}
