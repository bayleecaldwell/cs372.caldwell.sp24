#include <iostream>
#include <queue>

int josephus(int N, int M) {
    std::queue<int> q;
    for (int i = 1; i <= N; ++i)
        q.push(i);

    while (q.size() > 1) {
        for (int i = 0; i < M - 1; ++i) {
            int front = q.front();
            q.pop();
            q.push(front);
        }
        q.pop();
    }
    return q.front();
}

int main() {
    int N, M;
    std::cout << "Enter the number of people: ";
    std::cin >> N;
    std::cout << "Enter the count for elimination ";
    std::cin >> M;

    int winner = josephus(N, M);
    std::cout << "The winning position is: " << winner << std::endl;

    return 0;
}
