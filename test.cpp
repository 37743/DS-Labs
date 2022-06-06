// Random Queue Code

#include <iostream>
using namespace std;
template <typename Type>

class Queue{
    private:
        class Node
        {
        public:
            Node* next;
            Type data;
        };
    public:
        Node* front = new Node;
        Node* back = new Node; 
        int Qsize = 0;
        Queue()
        {
            front = back = NULL;
        }

        void addQueue(Type iData)
        {
            Node* newNode = new Node;
            newNode->data = iData;
            newNode->next = nullptr;
            if (!back) {
                front = back = newNode;
            } else {
                back->next = newNode;
                back = newNode;
            }
            /*if (!isFull())
            {
                Node* temp = new Node;
                temp = back;
                back = newNode;
                Qsize++;
                cout<<"Added "<<newNode->data<<" to the queue."<<endl;
            }
            else
            {
                front = back = newNode;
                Qsize++;
                cout<<"Added "<<newNode->data<<" to the queue."<<endl;
            }*/
        }
        Type removeQueue()
        {
            if (!isEmpty())
            {
                Type temp = front->data;
                front = front->next;
                Qsize--;
                cout<<"Removed "<<temp<<" from the queue."<<endl;
                return temp;
            }
            back = NULL;
            cout<<"Queue is empty."<<endl;
            return 0;
        }

        bool isFull() {return Qsize != 50;}
        bool isEmpty() {return front == NULL;}
};

int main()
{
    Queue<int> q;
    q.addQueue(5);
    q.addQueue(6);
    q.addQueue(7);
    q.addQueue(8);
    q.removeQueue();
    q.removeQueue();
    q.removeQueue();
    q.removeQueue();
    q.removeQueue();
}