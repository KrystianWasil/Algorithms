#include <iostream>


struct Places {
    std::string S;
    int order;
    short L = 0;
};

void swap(Places& e1, Places& e2) {
    Places temp;
    temp = e1;
    e1 = e2;
    e2 = temp;
}

void ShiftUP(int index, Places *array) {
    int parent;
    if (index % 2 == 0) {
        parent = (index - 2) / 2;
    } else {
        parent = (index - 1) / 2;
    }

    if (index == 0 || array[index].L <= array[parent].L)
        return;

    swap(array[index], array[parent]);
    ShiftUP(parent, array);

}


void ShiftDown(Places *array, int index, int size) {
    int next = index;
    if ((2 * index + 1) <= size && (array[2 * index + 1].L > array[next].L || (array[2 * index + 1].L == array[next].L && array[2 * index + 1].order < array[next].order))) {
        next = 2 * index + 1;
    }

    if ((2 * index + 2) <= size && (array[2 * index + 2].L > array[next].L || (array[2 * index + 2].L == array[next].L && array[2 * index + 2].order < array[next].order))) {
        next = 2 * index + 2;
    }

    if (next != index) {
        swap(array[index], array[next]);
        ShiftDown(array, next, size);
    }
}








int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);


    unsigned int N,K;
    std::cin >> N;
    auto *array = new Places[N];
    for (int i = 0; i < N; ++ i) {
        std::cin >> array[i].S >> array[i].L;
        array[i].order = i;
    }
    std::cin >> K;
    for (int i = 0; i < N; ++i) {
        ShiftUP(i,array);
    }
    int size = N - 1;
    for ( int i = 0; i < N; ++i ) {
        if (array[0].L <= K) {
            std::cout << array[0].S<< " ";
            K -= array[0].L;
        }
        if (K == 0) {
            break;
        }

        array[0] = array[size];
        size--;
        ShiftDown(array,0,size);
    }





    delete[] array;
    return  0;
}
