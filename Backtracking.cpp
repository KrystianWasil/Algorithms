#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

int calories(int max,int n,int sum, std::vector<int> &array) {
    if (sum == max) {
        return 1;
    }
    if (sum > max || n == 0) {
        return 0;
    }
    int old_sum = sum;
    sum += array[n - 1];
    array.pop_back();
    int way_1 = calories(max,n - 1,sum,array);
    int way_0 = calories(max,n - 1,old_sum,array);
    int result = way_0 + way_1;
    return result;

}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t, n, k;
    std::cin >> t;

    for (int iter = 0; iter < t; ++iter) {
        std::cin >> n;
        std::vector<int> data(n);

        for (int i = 0; i < n; ++i) {
            std::cin >> data[i];
        }
        std::cin >> k;
        std::sort(data.begin(), data.end());
        int final_result = calories(k,n,0,data);
        std::cout << final_result << std::endl;
    }

    return 0;
}
