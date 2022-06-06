// Fill in the Missing Parts.
#include <iostream>
using namespace std;

struct Node
{
    Node* head;
    double data;
    struct Node* next;
};

struct List
{
public:
/*     void DisplayList()
    {
    Node* currNode = head; // (1)
    while (currNode != NULL) // (2)
        {
        cout << currNode->data << endl;
        currNode = currNode->next;
        }
    }
 */
/*     int List::FindNode(double x)
    {
        Node* currNode = head; // (1)
        int currIndex = 1;
        while (currNode && (currIndex != x)) // (2)
            currNode = currNode->next; // (3)
            currIndex++;
    }
    if (currNode)
        return 1; // (4)
    return 0;
 */
/*     void Stack::Push(const double x)
    {
        if (top >= n-1) //(1)
        cout << "Error." << endl;
        else
            values[top++] = x; // (2)
    }
    /* Assuming values[] is the array that contains the
    values while n is the stack size. */

/*     void Stack::Pop()
    {
        if (top<=-1) // (1)
        {
            cout << "Error" << endl;
            return -1;
        }
        else
        {
            return values[top--]; // (2)
        }
    } */
/*     void reverse(char str[])
    {
        int n = strlen(str);
        Stack* stack = createStack(n);
        int i;
        for (i = 0; i<n; i++)
            Push(stack,str[i]); // (1)
        for (i = 0; i<n; i++)
            str[i] = Pop(stack); // (2)
    } /* Assuming Push() is modified to take 1 extra parameter, which
    is the stack to be pushed into.
    Push takes 1 parameter (data) by default which is value of str[i] in this case.
    As well as Pop() being modified to take 1 parameter instead of none
    to access the stack to pop from. */
};

/* int main()
{
    Node* node1 = new Node;
    Node* node2 = new Node;
    Node* node3 = new Node;

    node1->data = 4;
    node2->data = 5;
    node3->data = 7;

    node1->next = node2;
    node2->next = node3;
    node3->next = nullptr;
} */