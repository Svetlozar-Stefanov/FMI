#include <iostream>
#include <list>

using namespace std;

class Stack
{
    list<int> stack;
    int min;
    
public:
    void push(int x)
    {
        stack.push_front(x);
        if (x < min)
        {
            min = x;
        }
    }

    void pop() {
        int top = stack.front();
        stack.pop_front();

        if (top == min)
        {
            int temp = INT_MAX;
            for (int i = 0; i < stack.size(); i++)
            {
                int n = stack.front();
                if (n < temp)
                {
                    temp = n;
                }
                stack.pop_front();
                stack.push_back(n);
            }
            min = temp;
        }
    }

    int peek() {
        return stack.front();
    }

    int min() {
        return min;
    }
};

int main()
{
}
