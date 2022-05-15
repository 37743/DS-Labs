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
    /* Assuming values is the array that contains the values
    and n is the stack size. */

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