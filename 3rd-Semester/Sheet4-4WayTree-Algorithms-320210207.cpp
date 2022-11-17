// Yousef Ibrahim Gomaa Mahmoud - 320210207 - Section 10
#include<vector>
#include<queue>
#include<iostream>
#include<algorithm>

using namespace std;

// Implementation of 4-Way Tree in C++

struct Node{
    int children;
    vector<int> value;
    vector<Node*> next;

    Node(int value){ // Creates a tree node of size 4 indices.
        for(int i = 0;i<4;i++){
            this->next.push_back(NULL);
        }
        this->value.push_back(value);
        this->children = 0;
    }
};


class FWTree{
    int h;
    Node* root;
    public:

    FWTree(int count){
        root = NULL;
    }

    // Print In-order Traversal
    void TreePrint(){
        if(root == NULL){
            cout<<"\nThere are no nodes in the tree.";
            return;
        }
        queue<Node*> q1; // Using queue library.
        q1.push(root);
        q1.push(NULL);
        while(!q1.empty()){
            Node * ptr = q1.front();
            q1.pop();
            if(ptr == NULL){
                cout<<"\n";
                continue;
            }
            for(int i =0;i<ptr->value.size();i++) cout<<ptr->value[i]<<" ";
            for(int i =0;i<ptr->value.size()+1;i++) q1.push(ptr->next[i]);
        }
        return;
    }

    Node* Searchnode(int val, Node* node, int* pos)
    {
        if (node == NULL) return NULL;
        else {
            if (Foundnode(val, node, pos)) return root;
            else return Searchnode(val, node->next[*pos], pos);
        }
    }
    
    bool Foundnode(int val, Node* node, int* pos)
    {
        if (val < node->value[1]) {
            *pos = 0;
            return 0;
        }
        else {
            *pos = node->children;
            while ((val < node->value[*pos]) && *pos > 1) (*pos)--;
            if (val == node->value[*pos])
                return true;
            else
                return false;
        }
    }
    vector<Node*> nodeVec;
    void getlevel(Node * ptr,int level){
        if (level == 0) {
			nodeVec.push_back(ptr);
		}
		else {
			if (ptr != NULL) for(int i =0;i<4;i++) getlevel(ptr->next[i], level - 1);
			else for(int i =0;i<4;i++) getlevel(NULL, level - 1);
		}
    }
    
    Node* TreeInsert(int item,Node* ptr){
        if(root == NULL){ // Case of empty tree, creates the first node.
            root = new Node(item);
            return root;
        }
        if(ptr == NULL){
            ptr = new Node(item);
            return ptr;
        }
        Node* newNode = new Node(item);
        if(ptr->value.size() == 3) // Inserts in node's children. (If full)
            for(int i =0 ;i< 3;i++){
                if(item < ptr->value[i]){
                    ptr->next[i] = TreeInsert(item,ptr->next[i]);
                    ptr->children += 1;
                    break;
                }   
                else if(item > ptr->value[2]){
                    ptr->next[3] = TreeInsert(item,ptr->next[3]);
                    ptr->children += 1;
                    break;
                }
            }
        else{        
            ptr->value.push_back(item);
            sort(ptr->value.begin(),ptr->value.end()); // Re-arrange vector
        }
        return ptr;
    }
    // Insert Method
    void Insert(int item){TreeInsert(item,root);}
    // Search Method
    void Print(){TreePrint();}
    void Search(int val, int* pos){Searchnode(val,root,pos);}
};

int main(){
    FWTree testTree(0); // Initialize tree
    // Given array:
    int arr1[] = {60, 30, 90, 10, 50, 80, 100, 20, 40, 70, 39, 38, 37, 36, 35, 34, 33, 32}; 
    int arrSize = sizeof(arr1)/sizeof(arr1[0]);
    for(int i =0; i < arrSize; i++) {testTree.Insert(arr1[i]); cout<<"Inserted node: "<<arr1[i]<<"\n";}
    cout<<"\n-----------------\n";
    int* position=0;
    cout<<"\nPrinting the tree (I-O T):\n\n";
    testTree.Print();
    // testTree.Search(30,position);
    // cout<<"Position of found element is: "<<position;
    cout<<"\n";
}