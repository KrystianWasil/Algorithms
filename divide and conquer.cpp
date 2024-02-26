#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


bool comparePairs(const std::pair<int, int> &a, const std::pair<int, int> &b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
}


void check(int m, std::vector<std::vector<int>> &map, int xx, int yy, int value) {
    int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
    int dy[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
    std::vector<std::pair<int,int>> arr;

    for (int i = 0; i < 8; ++i) {
        int ny = yy + dy[i];
        int nx = xx + dx[i];

        if (nx >= 0 && nx < m && ny >= 0 && ny < m && map[ny][nx] == value) {
            arr.emplace_back(nx, ny);
        }
    }


    std::sort(arr.begin(), arr.end());

    for (const auto &p : arr) {
        std::cout << p.first << " " << p.second << " ";
    }
    std::cout << std::endl;
}

void fill(int m, std::vector<std::vector<int>> &map, std::pair<int, int> L, std::pair<int, int> x, std::pair<int, int> y, int &counter) {
    std::pair<int, int> L1, L2, L3, L4;


    if (m == 2) {
        counter++;
        if (L.first == x.first && L.second == y.second) {
            map[y.first][x.first] = counter ;
            map[y.first][x.second] = counter ;
            map[y.second][x.second ] = counter ;
        }
        if (L.first == x.first && L.second == y.first) {
            map[y.second][x.first ] = counter ;
            map[y.first ][x.second] = counter ;
            map[y.second][x.second ] = counter ;

        }
        if (L.first == x.second && L.second == y.first) {
            map[y.second][x.first] = counter ;
            map[y.first][x.first] =counter ;
            map[y.second][x.second] =counter ;
        }
        if (L.first == x.second && L.second == y.second) {
            map[y.first][x.first] = counter ;
            map[y.second][x.first] = counter ;
            map[y.first][x.second] = counter ;

        }
        return;
    }

    int middleX1 = ((x.first + x.second) / 2);
    int middleX2 = middleX1 + 1;
    int middleY1 = ((y.first + y.second) / 2);
    int middleY2 = middleY1 + 1;
    counter ++;
    if (L.first >= x.first && L.first <= middleX1 && L.second >= y.first && L.second <= middleY1) {
        L1 = L;
        L2 = { middleX2, middleY1 };
        L3 = { middleX1, middleY2 };
        L4 = { middleX2, middleY2 };

    }
    if (L.first >= middleX2 && L.first <= x.second && L.second >= y.first && L.second <= middleY1) {
        L1 = { middleX1, middleY1 };
        L2 = L;
        L3 = { middleX1, middleY2 };
        L4 = { middleX2, middleY2 };

    }
    if (L.first >= x.first && L.first <= middleX1 && L.second >= middleY2 && L.second <= y.second) {
        L1 = { middleX1, middleY1 };
        L2 = { middleX2, middleY1 };
        L3 = L;
        L4 = { middleX2, middleY2 };

    }
    if (L.first >= middleX2 && L.first <= x.second && L.second >= middleY2 && L.second <= y.second) {
        L1 = { middleX1, middleY1 };
        L2 = { middleX2, middleY1 };
        L3 = { middleX1, middleY2 };
        L4 = L;

    }
    if (map[L1.second][L1.first] == -2)
        map[L1.second][L1.first] = counter;
    if (map[L2.second][L2.first] == -2)
        map[L2.second][L2.first] = counter;
    if (map[L3.second][L3.first] == -2)
        map[L3.second][L3.first] = counter;
    if (map[L4.second][L4.first] == -2)
        map[L4.second][L4.first] = counter;



    fill(m/2, map, L1, { x.first, middleX1 }, { y.first, middleY1 }, counter);
    fill(m/2, map, L2, { middleX2, x.second }, { y.first, middleY1 }, counter);
    fill(m/2, map, L3, { x.first, middleX1 }, { middleY2, y.second }, counter);
    fill(m/2, map, L4, { middleX2, x.second }, { middleY2, y.second }, counter);
}
//zaaa duzo ifów
int main() {
    int n, m, x, y, p;
    std::cin >> n;
    for (int a = 0; a < n; ++a) {
        std::cin >> m >> x >> y >> p;
        std::vector<std::vector<int>> map(m, std::vector<int>(m, -2));

        int counter = -1;
        map[y][x] = -1;
        fill(m, map, { x , y }, { 0, m - 1 }, { 0, m - 1 }, counter);
        std::vector<std::pair<int, int>> coordinates;
        for (int i = 0; i < p; ++i) {
            int xx, yy;
            std::cin >> xx >> yy;
            check(m,map, xx, yy, map[yy][xx]);

        }



    }
    return 0;
}
