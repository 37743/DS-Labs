#include <iostream>
using namespace std;


class Tree
{
    struct TreeNode()
    {
        int data;
        TreeNode* left;
        TreeNode* right;
    }

    Tree(int value)
    {
        TreeNode* head;
        head->data = value;
        int level = -1;
        int counter = 0;
    }

    int inorder(Tree1*,k)
    {
        if (Tree1)
        {
        level++;
        counter++;
        inorder(Tree1->left);
        cout<<str(Tree1->data)+" ";
        inorder(Tree1->right);
        }
        if ((level-counter+1) == k) cout<<"Found! Element is at level "<<level;
    }

    void InsertItem(int item)
    {
      Insert(root, item);
    }

    void Insert(TreeNode*, int item)
    {
        if(tree == NULL)
        {
            tree = new TreeNode;
            tree->right = NULL;
            tree->left = NULL;
            tree->info = item;
        }
        else if(item < tree->info)
            Insert(tree->left, item);
        else
        Insert(tree->right, item);
    }
}

int main()
{
    Tree    
}