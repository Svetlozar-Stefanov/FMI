#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        next = nullptr;
    }
};

class List {
    Node* head;
    Node* tail;
    int size;

public:
    List()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void add(int x) {
        Node* newNode = new Node(x);

        if (tail == nullptr)
        {
            tail = newNode;
            head = tail;
            return;
        }

        tail->next = newNode;
        tail = tail->next;
        size++;
    }

    int shiftBack() {
        if (size < 2)
        {
            return 0;
        }

        int count = 0;
        while (head != nullptr && head->next->val > head->val)
        {
            count++;
            add(head->val);
            Node* toDel = head;
            head = head->next;
            delete toDel;
        }
        if (head != nullptr && head->next->val > head->val)
        {
            count++;
            add(head->val);
            Node* toDel = head;
            head = head->next;
            delete toDel;
        }
        return count;
    }

    vector<int> getAsArr() {
        vector<int> arr;
        Node* iter = head;
        while (iter != nullptr)
        {
            arr.push_back(iter->val);
            iter = iter->next;
        }

        return arr;
    }
};

int search(vector<int>& arr, int l, int r, int x) {
    if (l >= r)
    {
        if (arr[l] == x)
        {
            return l;
        }
        return -1;
    }

    int m = l + (r - l) / 2;

    if (x < arr[m])
    {
        return search(arr, l, m - 1, x);
    }
    else if (x > arr[m])
    {
        return search(arr, m + 1, r, x);
    }
    return m;
}

int main()
{
    int N;
    cin >> N;
    List list;
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        list.add(n);
    }

    int shift = list.shiftBack();

    vector<int> arr = list.getAsArr();

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << ' ';
    }

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        int q;
        cin >> q;

        int idx = search(arr, 0, arr.size() - 1, q);
        if (idx == -1)
        {
            cout << "-1\n";
            continue;
        }

        if (idx <= arr.size() - shift -1)
        {
            cout << idx + shift << '\n';
        }
        else
        {
            cout << idx - (arr.size() - shift) - 2 << '\n';
        }
    }
}
