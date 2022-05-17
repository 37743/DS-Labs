// Sheet 6 - Stack
#include <iostream>
using namespace std;
// Yousef Ibrahim Gomaa Mahmoud - ID: 320210207 - CSIT Section 10
// ------------------------------------------------
// Search for Q1,Q2,Q3,Q4,Q5 and Q6 in order to jump to their respective answers.
/*  Q1 - Write each of the functions (push, pop, top)
 for a stack implemented using an array.
 ----------------------Answer---------------------- */

/* template <typename Type> class Stack
{
private:
    int Top;
    int stkSize = 50;
    int stk[50] = {0};
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
            return 0;
        }
        Top++;
        stk[Top] = data;
    }

    void pop()
    {
        if(Top<=-1)
        {
            cout<<"ERROR: Stack Underflow!"<<endl;
            return 0;
        }
        cout<<"\nPopped! Popped value is: "<<stk[Top]<<endl;
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
    cout<<"New stack is empty.\nTop is: "<<stk.top();
    stk.push(5);
    stk.push(7);
    cout<<"\nPushed 5 then 7 to the stack.\n";
    cout<<"Current Top is: "<<stk.top();
    stk.pop();
    cout<<"Current Top is: "<<stk.top();
    stk.pop();
    cout<<"Current Top is: "<<stk.top();
} */

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
    int c;
public:
    Stack()
    {
        Top->next = nullptr;
        c = -1;
    }

    void push(int data)
    {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = Top;
        Top = newNode;
        c++;
    }

    int pop()
    { // Confirms the stack is not empty. (Stack Underflow)
        if (Top == nullptr)
        {
            cout<<"ERROR: Stack is empty!";
            return 0;
         }
        Node* temp = new Node;
        temp = Top;
        int oldData = Top->data;
        Top = Top->next;
        c--;
        delete temp;
        return oldData;
    }

    int top()
    {
        return c;
    }
}; */

/* int main()
{
    Stack stk;
    cout<<"New stack is empty.\nTop is: "<<stk.top();
    stk.push(6);
    stk.push(3);
    cout<<"\nPushed 6 then 3 to the stack.\n"
    <<"Current Top is: "<<stk.top()
    <<"\nPopped! Popped value is: "<<stk.pop()<<endl
    <<"Current Top is: "<<stk.top()
    <<"\nPopped! Popped value is: "<<stk.pop()<<endl
    <<"Current Top is: "<<stk.top();
} */

/*  Q3 - What is the complexity in big O notation
  for push, pop, and top stack operations?
----------------------Answer----------------------
All of the stack operations (push,pop and top) are O(1)
as there are no loops or recursions in their implementation. */

/* Q4 - Write a method to reverse a string using a stack.
 What is the complexity of your method in big O notation?
----------------------Answer----------------------
It takes n iterations to push the string into the stack, then another
n iterations to pop all the characters from the stack. Therefore, the
complexity is: O(2n) = O(n) */

/* template <typename T> class Stack
{
private:
    struct Node
    {
        T data;
        Node* next;
    };
    Node* Top = new Node;

public:
    int c;
    Stack()
    {
        Top->next = nullptr;
        c = -1;
    }

    void push(T data)
    {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = Top;
        Top = newNode;
        c++;
    }

    T pop()
    { // Confirms the stack is not empty. (Stack Underflow)
        if (Top == nullptr){
            cout<<"ERROR: Stack is empty!";
            return 0;
        }
        Node* temp = new Node;
        temp = Top;
        T oldData = Top->data;
        Top = Top->next;
        c--;
        delete temp;
        return oldData;
    }

    int top()
    {
        return c;
    }
};

void reverseStr(char str[])
{
    int i,j;
    for (i = 0; str[i]; i++);
    Stack<char> stk;
    for (j=0; j<i; j++)
    {
        stk.push(str[j]);
    }
    for (j=0; j<i; j++)
    {
    str[j] = stk.pop();
    }
} */

/* int main()
{
    char str[] = "Hello! This is Yousef Ibrahim.";
    reverseStr(str);
    cout << "\nReversed string is " << str;
} */