#include <iostream>
#include <vector>
#include <list>
#include <queue>

struct Pair{
    int p1,p2;
};

//do kolejki dodawaj 2 wartosci zamek i odelglosc ma to sens bo np od 0 do 2 to masz 1 czyki 2 ma 1 punkt odleglsoc wzgledem 0 gfajno

void bfs(int v, std::vector<std::vector<int>> &array, std::vector<bool> &visited, std::vector<int> &dd) {
    std::queue<int> castles;
    std::queue<int> distances;
    castles.push(v);
    distances.push(0);
    visited[v] = true;
    dd[v] = 0;

    while (!castles.empty()) {
        int currentCastle = castles.front();
        castles.pop();
        int currentDistance = distances.front();
        distances.pop();
        for (int & it : array[currentCastle]) {
            if (!visited[it]) {
                visited[it] = true;
                dd[it] = currentDistance + 1;
                castles.push(it);
                distances.push(currentDistance+1);
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);




    int n,m,s,d;
    std::cin >> n >> m >> s >> d;
    int numbOfhelp = 0;
    int lastCastle = 0;
    std::vector<bool> visited(n);
    std::vector<std::vector<int>> array(n);
    std::vector<int> dd(n);
    for (int i = 0; i < m; ++i){
        Pair pair{};
        std::cin >> pair.p1 >> pair.p2;
        if (pair.p1 < n && pair.p2 < n) {
            array[pair.p1].push_back(pair.p2);
            array[pair.p2].push_back(pair.p1);
        }
    }

    bfs(s, array, visited,dd);
    for (int i = 0; i < dd.size(); ++i) {
        if (dd[i] <= d/2 && dd[i] != 0)
            numbOfhelp++;
        if (dd[i] > lastCastle)
            lastCastle = dd[i];

    }
    std::cout << lastCastle << " " << numbOfhelp;






    return 0;
}
