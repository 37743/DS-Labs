// Sheet 6 - Stack
#include <iostream>
using namespace std;
// Yousef Ibrahim Gomaa Mahmoud - ID: 320210207 - CSIT Section 10
// ------------------------------------------------

/* Q4 - Write a method to reverse a string using a stack.
 What is the complexity of your method in big O notation?
----------------------Answer----------------------
It takes n iterations to push the string into the stack, then another
n iterations to pop all the characters from the stack. Therefore, the
complexity is: O(2n) = O(n) */

template <typename T> class Stack
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

    T top()
    {
        if (c < 0)
            return 0;
        return Top->data;
    }
};

void reverseStr(char str[])
{
    int i,j;
    for (i = 0; str[i]; i++);
    Stack<char> stk;
    for (j=0; j<i; j++)
        stk.push(str[j]);
    for (j=0; j<i; j++)
        str[j] = stk.pop();
}

int main() // Testing
{
    char str[] = "Hello! This is Yousef Ibrahim.";
    cout << "String is: " << str;
    reverseStr(str);
    cout << "\nReversed string is: " << str;
}