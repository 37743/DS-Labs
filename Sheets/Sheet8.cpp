// Fill in the Missing Parts.
#include <iostream>
using namespace std;


// template <typename Type> class Queue
// {
// private:
//     int front;
//     int back;
// public:
//     int Ecount;
//     int Qsize;
//     Type* iQ = new Type[Qsize];
//     Queue(int maxQueueSize)
//     {
//         Ecount = 0;
//         front = -1;
//         back = -1;
//         Qsize = maxQueueSize;  
//     }
//     bool isFull()
//     {
//         return Ecount == Qsize;
//     }
//     bool isEmpty()
//     {
//         return Ecount == 0;
//     }
//     void add(Type value)
//     {
//         if (!isFull())
//         {
//             iQ[++back] = value;
//             Ecount++;
//             return true;
//         }
//         else
//         {
//             cout<<"Queue is full"<<endl;
//             return false;
//         }
//     }
//     Type remove()
//     {
//         if (!isEmpty())
//         {
//             Ecount--;
//             return iQ[++front];
//         }
//         else cout<<"Queue is empty"<<endl;
//     }
// };

// int main()
// {
//     Queue<int> Q(5);
//     Q.add(6);
//     cout<<"Number of current elements: "<<Q.Ecount<<endl;
//     Q.remove();
//     cout<<"Number of current elements: "<<Q.Ecount<<endl;
//     Q.add(7);
//     Q.add(8);
//     cout<<"Number of current elements: "<<Q.Ecount<<endl;
//     Q.remove();
//     Q.remove();
//     cout<<"Number of current elements: "<<Q.Ecount<<endl;
// }

// void selectionSort(int a[], int nElems) {
//     int out, in, min;
//     for (out=0; out<nElems-1; out++)
//     {
//         int min = out;
//         for (in=out+1; in<nElems; in++)
//             if (a[in]<a[min]) min = in;
//         swap(a[out],a[min]);
//     }
// }
// int main(){
//     int test[8] = {5,6,3,2,6,1,7,3};
//     selectionSort(test,8);
//     for (int i=0; test[i]; i++) cout<<test[i]<<" ";
// }

void merge(int arrA[], int sizeA, int arrB[], int sizeB, int arrC[])
 {
     int aDex=0, bDex=0, cDex=0;
     while ((aDex <= sizeA) && (bDex <= sizeB))
     {
        if (arrA[aDex] <= arrB[bDex]) arrC[cDex++] = arrA[aDex++]; 
        else arrC[cDex++] = arrB[bDex++];   
      }
      while (aDex <= sizeA) arrC[cDex++] = arrA[aDex++]; 
      while (bDex <= sizeB) arrC[cDex++] = arrB[bDex++];
    
 }

int main()
{
    int testA[] = { 1,2,3,4,5,6 };
    int testB[] = {3,6,7,8,9,10};
    int testC[12] = {0};
    merge(testA,6,testB,6,testC);
    for (int i=0; i<12; i++) cout<<testC[i]<<" ";
}

// bool Queue::Enqueue(double x) {
//     if (isFull())
//     {
//         cout<<"Error: queue is full."<<endl;
//         return false;
//     }
//     else {
//         position = (position+1)%max;
//         arr[position] = value;
//         counter++;
//         return true;
//     }
// }