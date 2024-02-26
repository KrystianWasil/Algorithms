#include <iostream>
#include <list>
#include <vector>
#include <queue>

struct Monkey {

    int hands;
    char letter;
    std::vector<Monkey*> children;

    void display() {

            std::cout << letter;
        for (int i = 0; i < children.size(); i++) {
            if (children[i] != nullptr) {
                children[i]->display();
            }
        }
    }
};






int main() {
    int k,n;
    std::cin >> k;

    for (int t = 0; t < k; t++) {
        std::cin >> n;
        std::queue<Monkey*> queue;
        Monkey *root = new Monkey;
        Monkey *firstMonkey = new Monkey;
        std::cin >> firstMonkey->letter >> firstMonkey->hands;
        root->children.push_back(firstMonkey);
        queue.push(root->children.front());
        for (int j = 1; j < n; j++) {
            Monkey *monkey = new Monkey;
            std::cin >> monkey->letter >> monkey->hands;
            queue.push(monkey);

            if (queue.front()->hands != 0) {
                queue.front()->children.push_back(monkey);
                queue.front()->hands --;
            }
            if (queue.front()->hands == 0) {
                queue.pop();
            }

        }
        root->children.front()->display();
        std::cout << std::endl;
    }

    return 0;
}
