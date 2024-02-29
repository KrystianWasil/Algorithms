#include <iostream>


struct element {
    int value = 0;
    element *next = nullptr;
    element *prev = nullptr;
};

class List {
private:
    int size = 0;
    element *head = nullptr;
    element *tail = nullptr;

public:
    element *first();

    element *last();

    int Size();

    void push_front(int);

    void push_back(int);

    void pop_front();

    void pop_back();

};


element *List::first() { //operacja 1
    return head;
}
element *List::last() {
    return tail;
}
int List::Size() {
    return size;
}

void List::push_front(int v) {
    auto* newElement = new element;
    newElement->value = v;
    if (size == 0)
        head = tail = newElement;
    else {
        newElement->next = head;
        head->prev = newElement;
        head = newElement;
    }
    size++;
}

void List::push_back(int v) {
    auto * newElement = new element;
    newElement->value = v;
    if (size == 0) head = tail = newElement;
    else {
        tail->next = newElement;
        newElement->prev = tail;
        tail = newElement;
    }
    size++;
}

void List::pop_front() {
    if (size == 0) return;
    if (size == 1) {
        delete head;
        head = tail = nullptr;
    } else {
        element* newHead = head->next;
        delete head;
        head = newHead;
        head->prev = nullptr;
    }
    size--;
}

void List::pop_back() {
    if (size == 0) return;
    if (size == 1) {
        delete tail;
        head = tail = nullptr;
    } else {
        element *prevTail = tail->prev;
        delete tail;
        tail = prevTail;
        tail->next = nullptr;
    }
    size--;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    int n, arg,operation;
    std::cin >> n;
//    std::cin.ignore();
    List list;
    for (int i = 0; i < n; ++i) {
        std::cin>>operation;
//        std::cin.ignore();
        if (operation == 4 || operation == 5 )
            std::cin >> arg;
        switch (operation) {
            case 1 :
                if (list.Size() == 0) {
                    std::cout << "PUSTA\n";
                }else {
                    std::cout << list.first()->value << std::endl;
                }
                break;
            case 2 :
                if (list.Size() == 0) {
                    std::cout << "PUSTA\n";
                } else {
                    std::cout << list.last()->value << std::endl;
                }
                break;
            case 3 :
                std::cout << list.Size() << std::endl;
                break;
            case 4 :

                list.push_front(arg);
                break;
            case 5 :
                list.push_back(arg);
                break;
            case 6 :
                if (list.Size() == 0) std::cout << "PUSTA\n";
                else {
                    list.pop_front();
                }
                break;
            case 7 :
                if (list.Size() == 0) std::cout << "PUSTA\n";
                else {
                    list.pop_back();
                }
                break;
        }
    }
    return 0;
}
