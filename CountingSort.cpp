#include <iostream>
//#include <vector>

// w ponizszym kodzie uzylem algorytmu z wykladu
int main() {
    int n;
    std::cin >> n;
    std::vector<std::pair<int,std::string>> input(n);
    std::vector<int> counter(n);
    std::vector<std::pair<int,std::string>> output(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> input[i].second; // nazwy
        std::cin >> input[i].first; //numery
    }

//Counting sort dla %
    for (int i = 0; i < n; ++i) {
        counter[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        counter[input[i].first%n] += 1;
    }
    counter[0] -= 1;

    for (int i = 1; i < n; ++i) {
        counter[i] = counter[i] + counter[i-1];
    }

    for (int i = n - 1; i >=0; --i) {
        output[counter[input[i].first%n]].first = input[i].first;
        output[counter[input[i].first%n]].second = input[i].second;
        counter[input[i].first%n] -= 1;
    }

    input = output;

//Counting sort dla /
    for (int i = 0; i < n; ++i) {
        counter[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        counter[input[i].first/n] += 1;
    }
   counter[0] -= 1;
    for (int i = 1; i < n; ++i) {
        counter[i] = counter[i] + counter[i-1];
    }

    for (int i = n - 1; i >=0; --i) {
        output[counter[input[i].first/n]].first = input[i].first;
        output[counter[input[i].first/n]].second = input[i].second;
        counter[input[i].first/n] -= 1;
    }

    for (int i = 0; i < n; ++i) {
        std::cout << output[i].second << " ";
    }



    return 0;
}
