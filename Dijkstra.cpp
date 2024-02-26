#include <iostream>
#include <vector>
#include <queue>
#include <limits>

struct Element {
    int vertex;
    int weight;
    bool operator<(const Element& a) const {
        return weight > a.weight;
    }
};

void Dijkstra(int v, int n, const std::vector<std::vector<Element>>& array, std::priority_queue<Element>& queue, std::vector<int>& d,std::vector<std::vector<int>> &delays) {
    std::vector<bool> reached(n, false);
    d[v] = 0;

    queue.push({v,d[v]});

    while (!queue.empty()) {
        Element current_vertex = queue.top();
        queue.pop();

        if (!reached[current_vertex.vertex]) {
            reached[current_vertex.vertex] = true;
            for (auto q : array[current_vertex.vertex]) {
                if (d[q.vertex] > d[current_vertex.vertex] + q.weight) {
                    d[q.vertex] = d[current_vertex.vertex] + q.weight;
                    for (int x = 0; x < delays[q.vertex].size(); ++x) {
                        if (d[q.vertex] == delays[q.vertex][x]) {
                            d[q.vertex] ++;
                        }
                    }
                    queue.push({q.vertex, d[q.vertex]});
                }
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int de, n, m, s, t,k1,k2;;
    std::cin >> de;

    for (int i = 0; i < de; ++i) {
        std::cin >> n >> m >> s;
        std::vector<std::vector<Element>> array(n);
        std::vector<int> d(n, std::numeric_limits<int>::max());
        std::priority_queue<Element> queue;


        for (int j = 0; j < m; j++) {
            Element x{}, y{};
            std::cin >> x.vertex >> y.vertex >> t;
            x.weight = t;
            y.weight = t;
            array[x.vertex].push_back(y);
            array[y.vertex].push_back(x);
        }

        std::vector<std::vector<int>> delays(n);

        for (int j = 0; j < n; j++) {
            std::cin >> k1;
                for (int l = 0; l < k1; l++) {
                    std::cin >> k2;
                    delays[j].push_back(k2);
                }

            }
        Dijkstra(s,n,array,queue,d,delays);

        std::cout << d[0] << std::endl;
    }
    return 0;
}
