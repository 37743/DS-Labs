// Sheet 6 - Stack
#include <iostream>
using namespace std;
// Yousef Ibrahim Gomaa Mahmoud - ID: 320210207 - CSIT Section 10
// ------------------------------------------------

/*  Q2 - Write each of the functions (push, pop, top)
 for a stack implemented using a linked list. 
 ----------------------Answer---------------------- */

template <typename Type> class Stack
{
private:
    struct Node
    {
        Type data;
        Node* next;
    };
    Node* Top = new Node;
    int c;
public:
    Stack()
    {
        Top->next = nullptr;
        c = -1;
    }

    void push(Type data)
    {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = Top;
        Top = newNode;
        c++;
    }

    Type pop()
    { // Confirms the stack is not empty. (Stack Underflow)
        if (Top == nullptr)
        {
            cout<<"ERROR: Stack is empty!";
            abort();
         }
        Node* temp = new Node;
        temp = Top;
        Type oldData = Top->data;
        Top = Top->next;
        c--;
        delete temp;
        return oldData;
    }

    Type top()
    {
        if (c < 0)
            return 0;
        return Top->data;
    }
};

int main() // Testing
{
    Stack<int> stk;
    cout<<"New stack is empty.\nTop value is: "<<stk.top();
    stk.push(6);
    stk.push(3);
    cout<<"\nPushed 6 then 3 to the stack.\n"
    <<"Current Top value is: "<<stk.top()
    <<"\nPopped! Popped value is: "<<stk.pop()<<endl
    <<"Current Top value is: "<<stk.top()
    <<"\nPopped! Popped value is: "<<stk.pop()<<endl
    <<"Current Top value is: "<<stk.top();
}