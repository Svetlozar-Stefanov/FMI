#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
    //TODO define and use it for the linkedlist
};

class LinkedList {
public:
    void add(int val, int pos) {
        // TODO
    }

    void print() {
        //TODO
    }

    void remove(int pos) {
        //TODO
    }

    void reverse() {
        // TODO
    }

    void remove_all(int val) {
        // TODO
    }

    void group(int a, int b) {
        // TODO
    }

    void count(int val) {
        // TODO
    }

    void is_palindrome() {
        // TODO
    }

    ~LinkedList() {
        // TODO
    }

private:
    // TODO define your private variables
};

int main() {
    int cases;
    std::cin >> cases;
    for (int i = 0; i < cases; i++) {
        LinkedList ll;
        int ops;
        std::string op;
        std::cin >> ops;
        for (int j = 0; j < ops; j++) {
            std::cin >> op;

            if (op == "count") {
                int arg1;
                std::cin >> arg1;
                ll.count(arg1);
            }

            if (op == "add") {
                int arg1, arg2;
                std::cin >> arg1 >> arg2;
                ll.add(arg1, arg2);
            }

            if (op == "print") {
                ll.print();
            }

            if (op == "remove") {
                int arg1;
                std::cin >> arg1;
                ll.remove(arg1);
            }

            if (op == "reverse") {
                ll.reverse();
            }

            if (op == "remove_all") {
                int arg1;
                std::cin >> arg1;
                ll.remove_all(arg1);
            }

            if (op == "group") {
                int arg1, arg2;
                std::cin >> arg1 >> arg2;
                ll.group(arg1, arg2);
            }

            if (op == "is_palindrom") {
                ll.is_palindrome();
            }
        }

        std::cout << std::endl;

    }
    return 0;
}