// Sheet 6 - Stack
#include <iostream>
using namespace std;
// Yousef Ibrahim Gomaa Mahmoud - ID: 320210207 - CSIT Section 10
// ------------------------------------------------

/*  Q5 - Write a method to check if a string is palindrome using a stack.
 What is the complexity of your method in big O notation?
----------------------Answer----------------------
Similar to the reverse method, it takes n iterations to push the string into the stack,
then another n iterations to pop all the characters from the stack into a new array while
checking whether the newly appended element is equal to the correspondant element in the
non-reversed array. Therefore, the complexity is: O(2n) = O(n) */

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

bool isStrPali(char str[])
{
    int i,j;
    for (i = 0; str[i]; i++);
    char* revStr = new char[i];
    Stack<char> stk;
    for (j=0; j<i; j++)
        stk.push(str[j]);
    for (j=0; j<i; j++)
    {
        revStr[j] = stk.pop();
        if (revStr[j] != str[j])
           return false;
    }
    return true;
}

int main() // Testing
{
    // Case 1
    char str[] = "StrrtS";
    cout<<"Is the string \""<<str<<"\" a Palindrome?\n"
    <<isStrPali(str)<<endl;
    // Case 2
    char str2[] = "Str";
    cout<<"Is the string \""<<str2<<"\" a Palindrome?\n"
    <<isStrPali(str2);
}