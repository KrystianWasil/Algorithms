#include <iostream>
#include <limits.h>
#include <vector>
#include <queue>

struct Data {
    int x, y;
    int d;
    int monitors;

    bool operator<(const Data& a) const {
        if (d == a.d) {
            return monitors > a.monitors;
        }
        return d > a.d;
    }
};

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void bfs(Data v, char** map, int n, int m, bool** visited, Data& resultX) {
    std::priority_queue<Data> pq;
    pq.push(v);
    visited[v.x][v.y] = true;

    while (!pq.empty()) {
        Data current = pq.top();
        pq.pop();

        for (int i = 0; i < 4; ++i) {
            int x = current.x + dx[i];
            int y = current.y + dy[i];

            if (x >= 0 && y >= 0 && x < n && y < m && map[x][y] != '#' && !visited[x][y]) {
                int monitors;
                int dist = current.d + 1;
                if (map[x][y] == 'M')
                    monitors = current.monitors+1;
                else
                    monitors = current.monitors;

                visited[x][y] = true;
                pq.push({x, y, dist, monitors});

                if (map[x][y] == 'X') {
                    resultX = {x, y, dist, monitors};
                }
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m;
    Data v, resultX;
    std::cin >> n >> m;
    char** map = new char*[n];
    bool** visited = new bool*[n];

    for (int i = 0; i < n; ++i) {
        map[i] = new char[m];
        visited[i] = new bool[m]();

        for (int j = 0; j < m; ++j) {
            std::cin >> map[i][j];
            if (map[i][j] == 'S') {
                v.x = i;
                v.y = j;
                v.d = 0;
                v.monitors = 0;
            }
        }
    }

    bfs(v, map, n, m, visited, resultX);

    std::cout <<  resultX.d << " " <<resultX.monitors << '\n';
    for (int i = 0; i < n; ++i) {
        delete[] map[i];
        delete[] visited[i];
    }
    delete[] map;
    delete[] visited;

    return 0;
}
