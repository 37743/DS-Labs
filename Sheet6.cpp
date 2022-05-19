// Sheet 6 - Stack
#include <iostream>
using namespace std;
// Yousef Ibrahim Gomaa Mahmoud - ID: 320210207 - CSIT Section 10
// ------------------------------------------------
// Search for Q1,Q2,Q3,Q4,Q5 and Q6 in order to jump to their respective answers.

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

/*  Q2 - Write each of the functions (push, pop, top)
 for a stack implemented using a linked list. 
 ----------------------Answer---------------------- */

/* template <typename Type> class Stack
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
    reverseStr(str);
    cout << "\nReversed string is: " << str;
} */

/*  Q5 - Write a method to check if a string is palindrome using a stack.
 What is the complexity of your method in big O notation?
----------------------Answer----------------------
Similar to the reverse method, it takes n iterations to push the string into the stack,
then another n iterations to pop all the characters from the stack into a new array while
checking whether the newly appended element is equal to the correspondant element in the
non-reversed array. Therefore, the complexity is: O(2n) = O(n) */

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
} */

/*  Q6 - Write a method to reverse words in a given string. For example:
 if the input is “ I like data structures” the output will be “ structures data like I”.
 What is the complexity of your method in big O notation?
----------------------Answer---------------------- 
Again, similar to the reverse method, it takes n iterations to push the words into the stack,
then another n iterations to pop everyone words from the stack into a string.
Therefore, the complexity is: O(2n) = O(n) */

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
}  */