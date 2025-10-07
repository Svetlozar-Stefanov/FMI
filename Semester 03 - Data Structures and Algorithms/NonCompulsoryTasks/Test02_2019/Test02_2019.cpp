#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


struct Node {
    Node* next;
    int data;
    Node(Node* _next, int _data) {
        next = _next;
        data = _data;
    }
};
class LinkedList {
public:
    LinkedList() {
        head = NULL;
    }
    ~LinkedList() {
        Node* tmp;
        while (head != NULL) {
            tmp = head;
            head = head->next;
            delete tmp;
        }
    }
    void add(int number) {
        Node* tmp = new Node(head, number);
        head = tmp;
    }
    void print() {
        Node* curr = head;
        while (curr != NULL) {
            cout << curr->data << " ";
            curr = curr->next;
        }
    }
    void removeComplex(int devidedBy) {
        Node* prev = nullptr;
        Node* iter = head;

        while (iter != nullptr)
        {
            if (iter->data % devidedBy == 0)
            {
                if (prev == nullptr)
                {
                    head = iter->next;
                    delete iter;
                    iter = head;
                }
                else
                {
                    prev->next = iter->next;
                    delete iter;
                    iter = prev->next;
                }
                continue;
            }

            prev = iter;
            iter = iter->next;
        }

    } // end removeComplex
private:
    Node* head;
};
int main() {
    LinkedList l;

    int n;
    cin >> n;
    int number;
    for (int i = 0; i < n; i++) {
        cin >> number;
        l.add(number);
    }
    int devidedBy;
    cin >> devidedBy;
    l.removeComplex(devidedBy);
    l.print();
}