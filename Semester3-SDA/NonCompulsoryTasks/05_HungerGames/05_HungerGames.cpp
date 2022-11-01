#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

void Ver01(vector<int> &arr, int N) {
    int count = 0;
    bool isEliminated = false;
    queue<int>* roundSurvivors = new queue<int>();
    for (int i = N - 1; i >= 0; i--)
    {
        if (i >= 1 && arr[i] > arr[i - 1])
        {
            isEliminated = true;
            continue;
        }
        roundSurvivors->push(arr[i]);
    }

    if (isEliminated)
    {
        count++;
    }

    while (isEliminated)
    {
        isEliminated = false;
        queue<int>* lastRoundSurvivors = roundSurvivors;
        roundSurvivors = new queue<int>();
        while (lastRoundSurvivors->size() > 0)
        {
            int current = lastRoundSurvivors->front();
            lastRoundSurvivors->pop();
            if (lastRoundSurvivors->size() <= 0)
            {
                roundSurvivors->push(current);

                break;
            }
            int next = lastRoundSurvivors->front();

            if (current > next)
            {
                isEliminated = true;
            }
            else
            {
                roundSurvivors->push(current);
            }
        }
        if (isEliminated)
        {
            count++;
        }
    }

    cout << count;
}

struct Node
{
    int val;
    Node* next;
    Node(int n) {
        val = n;
        next = nullptr;
    }
};

class List {
    Node* head;
    Node* tail; 

public:
    List() {
        head = nullptr;
        tail = nullptr;
    }

    void add(int n) {
        if (head == tail && head == nullptr)
        {
            head = new Node(n);
            tail = head;
            return;
        }

        Node* newTail = new Node(n);
        tail->next = newTail;
        tail = tail->next;
    }

    int eliminate() {
        if (head == nullptr)
        {
            return 0;
        }

        int maxCount = INT_MIN;
        int count = 1;
        Node* smallest = head;

        Node* prev = head;
        Node* iter = head->next;
        while (iter != nullptr)
        {
            if (iter->val > smallest->val && prev->val > iter->val)
            {
                count++;
            }
            else if (iter->val < smallest->val)
            {
                if (count > maxCount)
                {
                    maxCount = count;
                }
                count = 1;
                smallest->next = iter;
                smallest = iter;
            }
            prev = iter;
            iter = iter->next;
        }
        if (count > maxCount)
        {
            maxCount = count;
        }

        return maxCount;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    List arr;
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        arr.add(n);
    }

    cout << arr.eliminate();
}
