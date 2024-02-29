#include <iostream>
#include <vector>
#include <queue>
#include <limits>

struct Vertex {
    int v;
    int d;
    bool operator<(const Vertex& a) const {
        return d > a.d;
    }
};

void Dijkstra( int v, int n, const std::vector<std::vector<Vertex>>& matrix, std::priority_queue<Vertex>& queue, std::vector<int>& dist,std::vector<int> &time) {
    std::vector<bool> reached(n, false);
    dist[v] = 0;

    queue.push({v,dist[v]});

    while (!queue.empty()) {
        Vertex current_vertex = queue.top();
        queue.pop();

        if (!reached[current_vertex.v]) {
            reached[current_vertex.v] = true;
            for (auto q : matrix[current_vertex.v]) {
                if (dist[q.v] > dist[current_vertex.v] + q.d + time[q.v]) {
                    dist[q.v] = dist[current_vertex.v] + q.d + time[q.v];
                    queue.push({q.v, dist[q.v]});
                }
                
            }

        }
    }
}



int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int V,E,n,s;
//    unsigned int a,b,c;

    std::cin >> V >> E;
    std::vector<std::vector<Vertex>> matrix(V);
    std::priority_queue<Vertex> queue;
    std::vector<int> dist(V, std::numeric_limits<int>::max());
    std::vector<int> times;
    for ( int i = 0; i < E; ++i) {
        int a,b,d;
        std::cin >> a >> b >> d;
        matrix[a].push_back({b,d});
//        matrix[b].push_back({a,d});
    }

//    std::vector<std::vector<int>> time(V);
// tutaj in case usun sobie rozmair i pushuj po prostu
    for ( int i = 0; i < V; ++i) {
        int time;
        std::cin >> time;
        times.push_back(time);
    }
    std::cin >> n;
    std::vector<int> destination;
    for ( int i = 0; i < n; ++i) {
        int vertex;
        std::cin >> vertex;
        destination.push_back(vertex);
    }
    std::cin >> s;
    Dijkstra(s,V,matrix,queue,dist,times);

    for ( int i = 0; i < n; ++i) {
        if (dist[destination[i]] == std::numeric_limits<int>::max()) std::cout << "NIE\n";
        else
            std::cout << dist[destination[i]] << std::endl;
    }



    return 0;
}
