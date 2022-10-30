#include <iostream>

using namespace std;

struct Pishtov {
    int topic;
    Pishtov* next;
    Pishtov* previous;

    Pishtov(int topic) {
        this->topic = topic;
        next = nullptr;
        previous = nullptr;
    }
};

class PishtovList {
    Pishtov* head;
    Pishtov* tail;
    Pishtov* middle;

public:
    int size;

    PishtovList() {
        head = nullptr;
        tail = nullptr;
        middle = nullptr;
        size = 0;
    }

    void add(int x) {
        if (tail == nullptr)
        {
            tail = new Pishtov(x);
            middle = tail;
            head = tail;
            size++;
            return;
        }
        Pishtov* newTail = new Pishtov(x);
        tail->next = newTail;
        newTail->previous = tail;
        tail = newTail;
        size++;
        if (size % 2 == 0 && size > 2)
        {
            middle = middle->next;
        }
    }

    void use() {
        if (size <= 1)
        {
            delete head;
            head = nullptr;
            middle = nullptr;
            tail = nullptr;
            size--;
            return;
        }

        Pishtov* temp = tail->previous;
        delete tail;
        tail = temp;
        tail->next = nullptr;
        if (size % 2 == 0 && size > 2)
        {
            middle = middle->previous;
        }
        size--;
    }

    void chechev_ramble() {
        if (size <= 1)
        {
            return;
        }

        Pishtov* newMid = tail;
        if (size % 2 != 0)
        {
            newMid = newMid->previous;
        }

        tail->next = head;
        head->previous = tail;
        head = middle->next;
        head->previous = nullptr;
        tail = middle;
        tail->next = nullptr;

        middle = newMid;
    }

    void print() {
        cout << size << '\n';
        Pishtov* iter = head;
        while (iter != nullptr)
        {
            cout << iter->topic << ' ';
            iter = iter->next;
        }
        cout << '\n';
    }
};

int main()
{
    int N;
    cin >> N;
    PishtovList list;
    for (int i = 0; i < N; i++)
    {
        string command;
        cin >> command;
        if (command == "add")
        {
            int n;
            cin >> n;
            list.add(n);
        }
        else if (command == "gun")
        {
            list.use();
        }
        else
        {
            list.chechev_ramble();
        }

        list.print();
    }

    list.print();
}
