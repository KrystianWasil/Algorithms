#include<iostream>
#include <string>


class Person {
public:
    std::string name;
    int x;

};

//sortowanie z wykladu 
void SelectionSort(Person *Arr, unsigned n) {
    for (unsigned int i = 0; i < n - 1; i++) {
        unsigned int max = i;
        for (unsigned int j = i + 1; j < n; j++) {
            if (Arr[j].x > Arr[max].x || (Arr[j].x == Arr[max].x && Arr[j].name < Arr[max].name)) {
                max = j;
            }
        }
        std::swap(Arr[i], Arr[max]);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t,n,p;


    Person *Arr;

    std::cin >> t;

    while(t--) {
        std::cin >> n;
        std::cin >> p;

        Arr = new Person[n];

        for (int j = 0; j < n; j++) {
            std::cin >> Arr[j].name;
            std::cin >> Arr[j].x;
        }
        SelectionSort(Arr,n);
        int checked = 0;
        long int result = 0;
        for (int j = 0; j < n; j++) {
            result += (1 + Arr[j].x * checked);
            checked++;
        }

        //wyświetlam wynik sortowania (tylko imiona) i wynik result
        for (int j = 0; j < p; j++) {
            std::cout << Arr[j].name << " ";
        }
        std::cout << std::endl << result%(1000003) << std::endl;

        Arr = nullptr;
        delete [] Arr;

    }
    return 0;
}
