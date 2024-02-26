#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t, n, c, d, t1, t2;
    std::cin >> t;

    for (int iter = 0; iter < t; ++iter) {
        int sum = 0;
        std::cin >> n >> c >> d;
        std::vector<int> times1;
        std::vector<int> times2;

        for (int i = 0; i < n; ++i) {
            std::cin >> t1 >> t2;
            times1.push_back(t1);
            times2.push_back(t2);
            sum += c + d * (t2 - t1);
        }

        std::sort(times1.begin(), times1.end()); //rosnace  0 1 3 4 9
        std::sort(times2.rbegin(), times2.rend()); //malejace konce 10 9 8 3 1
        for (int i = 0; i < n; ++i)  {
            auto upper = std::upper_bound(times1.begin(), times1.end(), times2[i]);
                if (upper != times1.end()) {
                    int index = upper - times1.begin();
                    if ((times1[index] - times2[i]) * d < c) {
                        sum = sum - c + d * (times1[index] - times2[i]);
                       times1.erase(times1.begin() + index);
                }

            }

        }

        std::cout << sum << std::endl;

    }

    return 0;
}
