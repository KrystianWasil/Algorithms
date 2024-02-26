#include <iostream>
#include <string>

class Stack_for_char{         //stack z leckji wykaldow
private:
    struct Operands{
        char value;
        Operands * next;
    };

      Operands * head;
public:
    Stack_for_char(){
        head = nullptr ;
    }
    ~Stack_for_char () {
        Operands *pom;
        while (head != nullptr) {
            pom = head;
            head = head->next;
            delete pom;
        }
    }
    bool empty() {
        if ( head == nullptr ) return true ;
        else return false ;
    }
    void push(char someVal) {
        Operands * newOperand = new Operands;
        newOperand->value = someVal;
        newOperand->next = head;
        head = newOperand;
    }
    void pop() {
        if (head != nullptr) {
            Operands *temp = head;
            head = head->next;
            delete temp;
        }
    }
    char top() {
        if (head!= nullptr) {
            return head->value;
        }
    }
};

class Stack_for_double{         //stack z leckji wykaldow
private:
    struct Numbers{
        double value;
        Numbers * next;
    };

    Numbers * head;
public:
    Stack_for_double() {
        head = nullptr ;
    }
    ~Stack_for_double () {
        Numbers *pom;
        while (head != nullptr) {
            pom = head;
            head = head->next;
            delete pom;
        }
    }
    bool empty() {
        if ( head == nullptr ) return true ;
        else return false ;
    }
    void push(double someVal) {
        Numbers * newOperand = new Numbers;
        newOperand->value = someVal;
        newOperand->next = head;
        head = newOperand;
    }
    void pop() {
        if (head != nullptr) {
            Numbers *temp = head;
            head = head->next;
            delete temp;
        }
    }
    double top() {
        if (head!= nullptr) {
            return head->value;
        }
    }
};


class Queue { //kolejka charów z wykaldów (kilka zmian)
private:
    char * arr;
    unsigned int head, tail;
    unsigned int size;
public:
    Queue();
    ~Queue();
    bool empty();
    void push(char element);
    char pop();
    char front();
};

Queue::Queue() {
    head = tail = 0;
    size = 100;
    arr = new char [size];

}

Queue::~Queue() {
    delete [] arr;
}

bool Queue::empty() {
    if ( head == tail) return true ;
    else return false ;
}

void Queue::push(char element) {
    arr[tail]= element;
    tail=(tail+1) % size;
    if (head == tail){
        char * arr_temp = new char [2* size ];
        unsigned int i=0;
        do{
            arr_temp [i]= arr [ head ];
            head =( head +1)% size ;
            i++;
        } while ( head != tail );
        delete [] arr ;
        arr = arr_temp ;
        head = 0;
        tail = size ;
        size *=2;
    }
}

char Queue::pop() {
    char temp = arr[head];
        head = (head+1) % size;
        return temp;
}

char Queue::front() {
    return arr[head];
}

void d(std::string s) {
    for (char i : s) {
       std::cout << i;
    }
}

bool ONP(std::string e,Queue &onp) {
    int iter = 0;
    Stack_for_char stack;
    while (iter < e.size()) {
        if (isdigit(e[iter]) && isdigit(e[iter+1])) {
            onp.push(e[iter]);
        } else if (isdigit(e[iter]) && !isdigit(e[iter+1]) ) {
            onp.push(e[iter]);
            onp.push(';');
        } else if (e[iter] == '+' || e[iter] == '-') {
            while (!stack.empty() &&
                   (stack.top() == '+' || stack.top() == '-' || stack.top() == '*' || stack.top() == '/')) {
                onp.push(stack.top());
                stack.pop();
            }
            stack.push(e[iter]);

        } else if (e[iter] == '*' || e[iter] == '/') {
            while (!stack.empty() && (stack.top() == '*' || stack.top() == '/')) {
                onp.push(stack.top());
                stack.pop();
            }
            stack.push(e[iter]);
        } else if (e[iter] == '(' || e[iter] == '{' || e[iter] == '[') {
            stack.push(e[iter]);
        } else if (e[iter] == ')') {
            while (!stack.empty() && stack.top() != '(') {
                onp.push(stack.top());
                stack.pop();

            }
            if (stack.empty()){
                return  false;
            }
            stack.pop();
        } else if (e[iter] == '}') {
            while (!stack.empty() && stack.top() != '{') {
                onp.push(stack.top());
                stack.pop();
            }
            if (stack.empty()){
                return false;
            }
            stack.pop();
        } else if (e[iter] == ']') {
            while (!stack.empty() && stack.top() != '[') {
                onp.push(stack.top());
                stack.pop();
            }
            if (stack.empty()){
                return false;
            }
            stack.pop();
        }
        iter++;
    }
    while (!stack.empty()) {
        if (stack.top() == '(' ||stack.top() == '{' || stack.top() == '[')
            return false;
        onp.push(stack.top());
        stack.pop();
    }
    return true;
}

double calculateONP(Queue& s) {
    std::string current_numb;
    double a, b;
    Stack_for_double stack;

    while (!s.empty()) {
        char current_char = s.front();
        s.pop();

        if (isdigit(current_char)) {
            current_numb.push_back(current_char);
        } else if (current_char == ';' && !current_numb.empty()) {
            stack.push(std::stod(current_numb));
            current_numb.clear();
        } else if (current_char == '+' || current_char == '-' || current_char == '*' || current_char == '/') {
            b = stack.top();
            stack.pop();
            a = stack.top();
            stack.pop();

            switch (current_char) {
                case '+':
                    stack.push(a + b);
                    break;
                case '-':
                    stack.push(a - b);
                    break;
                case '*':
                    stack.push(a * b);
                    break;
                case '/':
                    stack.push(a / b);
                    break;
                default:
                    break;
            }
        }
    }
    return stack.top();
}


int main() {
    int n;
    std::cin >> n;
    std::cin.ignore();
    std::string e;
    for (int i = 0; i < n; ++i) {
        Queue onp;
        getline(std::cin, e);
        if (ONP(e,onp)) {
            std::cout << calculateONP(onp);
        } else {
            std::cout << "BLAD";
        }
        std::cout << std::endl;
    }
    return 0;
}
