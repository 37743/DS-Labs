// Sheet 6 - Stack
#include <iostream>
using namespace std;
// Yousef Ibrahim Gomaa Mahmoud - ID: 320210207 - CSIT Section 10 
// Search for Q1,Q2,Q3,Q4,Q5 and Q6 in order to jump to their respective answers. 
/*  Q1 - Write each of the functions (push, pop, top)
 for a stack implemented using an array. 
 ----------------------Answer---------------------- */

template <typename Type> class Stack
{
private:
    int Top;
    int arrSize;
public:
    Stack()
    {
        Top = -1;
        arrSize = 50;
        arr1[arrSize] = {0};
    }

    void push(Type data)
    {
        Top++;
        arr1[Top] = data;
    }

    void pop()
    {
        arr1[Top] = 0;
        Top--; 
    }

    int top()
    {
        return Top;
    }
};

int main()
{
    Stack<int> stk;
    stk.push(5);
    stk.push(7);
    stk.pop();
    cout<<stk.top();
}

/*  Q2 - Write each of the functions (push, pop, top)
 for a stack implemented using a linked list. 
 ----------------------Answer---------------------- */
/* class Stack
{
private:
    struct Node
    {
        int data;
        Node* next;
    };
    Node* Top = new Node;
public:
    Stack()
    {
        Top->next = NULL;
    }

    void push(int data)
    {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = Top;
        Top = newNode;
    }

    int pop()
    { // Confirms the stack is not empty. (Stack Underflow)
        if (Top == nullptr)
            cout<<"ERROR: Stack is empty!";
        Node* temp = new Node;
        temp = Top;
        int oldData = Top->data;
        Top = Top->next;
        delete Top;
        return oldData;
    }

    int top()
    {
        return Top->data;
    }
}; */

/* int main()
{
    Stack stk;
    stk.push(2);
    stk.push(3);
    stk.pop();
    stk.push(4);
    cout<<stk.top();
} */

/*  Q3 - What is the complexity in big O notation
  for push, pop, and top stack operations?
----------------------Answer----------------------
All of the stack operations (push,pop and top) are O(1)
as there are no loops or recursions in their implementation. */
