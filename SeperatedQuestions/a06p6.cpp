// Sheet 6 - Stack
#include <iostream>
using namespace std;
// Yousef Ibrahim Gomaa Mahmoud - ID: 320210207 - CSIT Section 10
// ------------------------------------------------

/*  Q6 - Write a method to reverse words in a given string. For example:
 if the input is “ I like data structures” the output will be “ structures data like I”.
 What is the complexity of your method in big O notation?
----------------------Answer---------------------- 
Again, similar to the reverse method, it takes n iterations to push the words into the stack,
then another n iterations to pop everyone words from the stack into a string.
Therefore, the complexity is: O(2n) = O(n) */

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

string reverseWords(string str)
{
    int i,j;
    str += " ";
    for (i = 0; str[i]; i++);
    Stack<string> stk;
    string word = "";
    for (j=0; j<i; j++)
    {
        if (str[j] == ' ')
        {
            stk.push(word + " ");
            word = "";
        }
        else
            word += str[j];
    }
    str = "";
    while (stk.c != -1)
        str += stk.pop();
    return str;
}

int main() // Testing
{
    string str = "I like data structures";
    cout << "String before reversing words is: " << str;
    str = reverseWords(str);
    cout << "\nAfter reversing words, string is: " << str;
} 