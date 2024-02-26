#include <iostream>
#include <cmath>


//double P(int i,int j) {
//
//}

double Search(int start_n,int start_m, int n, int m) {
    int middle_c = ((start_m + m)/2);
    double local_max = 0;
    int y;
    int left,right;
    left = middle_c - 1;
    right = middle_c + 1;

    for (int i = start_n; i < n; ++i) {
        if (P(i,middle_c) > local_max){
            local_max = P(i,middle_c);
            y = i;
        }
    }

    if (P(y, right) > local_max && left < 0) {
        return local_max;
    } else if (P(y, left) > local_max && right > m) {
        return local_max;
    } else if (P(y, left) > local_max && left >= 0) {
        return Search(start_n, start_m, n, middle_c); 
    } else if (P(y, right) > local_max && right < m) {
        return Search(start_n, middle_c, n, m); 
    } else if (P(y, left) < local_max && P(y, right) < local_max) {
        return local_max;
    }

    return local_max;

}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n,m;
    std::cin >> n >> m;
    std::cout << (int)floor(Search(0,0,n,m));

    return 0;
}
