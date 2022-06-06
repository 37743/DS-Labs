// Sheet 6 - Stack
#include <iostream>
using namespace std;
// Yousef Ibrahim Gomaa Mahmoud - ID: 320210207 - CSIT Section 10
// ------------------------------------------------

/*  Q1 - Write each of the functions (push, pop, top)
 for a stack implemented using an array.
 ----------------------Answer---------------------- */

template <typename Type> class Stack
{
private:
    int Top;
    int stkSize = 50;
    Type stk[50] = {0};
public:
    Stack()
    {
        Top = -1;
    }

    void push(Type data)
    {
        if(Top>=stkSize-1)
        {
            cout<<"ERROR: Stack Overflow!"<<endl;
            abort();
        }
        Top++;
        stk[Top] = data;
    }

    void pop()
    {
        if(Top<=-1)
        {
            cout<<"ERROR: Stack Underflow!"<<endl;
            abort();
        }
        cout<<"\nPopped! Popped value is: "<<stk[Top]<<endl;
        Top--;
    }

    int top()
    {
        if (Top < 0)
            return 0;
        return stk[Top];
    }
};

int main() // Testing
{
    Stack<int> stk;
    cout<<"New stack is empty.\nTop value is: "<<stk.top();
    stk.push(5);
    stk.push(7);
    cout<<"\nPushed 5 then 7 to the stack.\n";
    cout<<"Current Top value is: "<<stk.top();
    stk.pop();
    cout<<"Current Top value is: "<<stk.top();
    stk.pop();
    cout<<"Current Top value is: "<<stk.top();
}