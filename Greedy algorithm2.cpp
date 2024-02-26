#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n ,m;
    std::string **names;
    std::cin >> n >> m;
    names = new std::string*[1500]; // inicjalizuje sobie pamiec dynamiczna pameitaj zeby usunac
    for (int i = 0; i < 1500; ++i)
        names[i] = new std::string[4];

    for (int i = 0 ; i < m; ++i) {
        int start = 0, end = 3;
        std::string temp_name;
        std::cin >> temp_name;
        for (int j = 0; j < 4; ++j) {
            for (int k = start; k < end; ++k){
                names[i%1500][j] += temp_name[k];
            }
            start +=3;
            end +=3;
        }

    }
    for (int i = m; i < n; ++i)
        for (int j = 0; j < 4; ++j) {
            int x;
            std::cin >> x;
            names[i%1500][j] = names[x%1500][j]; // czytam sobie z weirsza x wartosc od 1 do 4 bo tyle jest czesci w nazwisku
        }

    for (int i = 0; i < 4; ++i)
        std::cout << names[(n -1) %1500][i]; // n - 1 bo indeys= od 0

        for(int i = 0; i < 1500; ++i)
            delete[] names[i];

        delete[] names;

    return 0;
}
