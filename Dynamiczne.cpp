#include <iostream>
#include <algorithm>

class Comparator {
public:
    bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) const {
        return a.second < b.second;
    }
};

int main() {
    int t, n;
    Comparator comp;
    std::cin >> t;

    for (int i = 0; i < t; ++i) {
        std::cin >> n;
        bool* cameras = new bool[n]();
        bool flag = true;
        auto* data = new std::pair<int, int>[n];
        for (int j = 0; j < n; ++j) {
            std::cin >> data[j].first >> data[j].second;
            
        }

        std::sort(data, data + n, comp);

        for (int j = 0; j < n; ++j) {
            int start = data[j].first;
            int end = data[j].second;
            for (int k = start; k <= end; ++k) {
                if (!cameras[k]) {
                    cameras[k] = true;
                    break;
                }
            }
        }


        for (int j = 0; j < n; ++j) {
            if (!cameras[j]) {
                flag = false;
                break;
            }
        }


        if (flag) {
            std::cout << "TAK\n";
        } else {
            std::cout << "NIE\n";
        }

        delete[] data;
        delete[] cameras;
    }

    return 0;
}
