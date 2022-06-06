// Bonus Project - English Dictionary (15 pts)

// Yousef Ibrahim Gomaa Mahmoud - 320210207 - Section 10 - Group 4
// Code is also available on my GitHub protxtfile:
// https://github.com/37743/DS-Labs/tree/main/Bonus

// Libraries/Classes Needed: (fstream, iostream, string)
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Dictionary Class:
class Dictionary
{   
    // Binary Search Tree as a dictionary.
    private:
    int WordsSize = 0;
    struct DictNode
    {
        string WordStr = "";
        DictNode* left;
        DictNode* right;
    };

    DictNode* insertNode(DictNode* Root, string word) {
        if (Root == nullptr)
        {
            DictNode* node = new DictNode;
            node->right = nullptr;
            node->left = nullptr;
            node->WordStr = word;
            return node;
        }
        if (Root->WordStr > word) Root->left = insertNode(Root->left, word);
        else Root->right = insertNode(Root->right, word);
        return Root;
    }

    void inorderSearch(DictNode* Root, string word, bool* found) {
        if (Root == nullptr) return;
        inorderSearch(Root->left);
        if (Root->WordStr == word) found = true;
        inorderSearch(Root->right);
    }

    // Public - Methods: (Dictionary(string), insert(string), lookup(string), remove(string))
    public:
    Dictionary(string txtfilepath)
    {
        DictNode* Dict = nullptr;
        fstream txtfile;
        string WordStr;
        txtfile.open(txtfilepath);
        while(txtfile.is_open() && getline(txtfile,WordStr))
        {
            WordsSize++;
            cout<<"Node inserted is: "<<insertNode(Dict,WordStr)<<"\n";
        }
        txtfile.close();
    }
    int insert(string word)
    {
        txtfile.open(txtfilepath);
        while(txtfile.is_open() && getline(txtfile,WordStr))
        {
            if(WordStr == word)
            {
            cout<<"Word already exists in the dictionary!\n";
            txtfile.close();
            return 0;
            }
            else
            {
                ofstream txtfileout(txtfile,ios::app);
                txtfileout<<word;
                txtfileout.close();
                txtfile.close();
                insertNode(Dict,word);
                WordsSize++;
                return 1;
            }
        }
    }
    int lookup(string word)
    {
        bool* found = false;
        inorderSearch(Dict,word,&found);
        if (found==true) return 1;
        else return 0;
    }
    int remove(string word)
    {
        return 0;
    }
};

int main()
{
    Dictionary dct("dictionary.txt");
    cout<<"Hello! This is a dictionary.\n"<<
    "-------------------------\n"<<
    "You can look up words by entering: /lookup (InsertWord)\n"<<
    "You can also insert a new word by entering: /insert (InsertWord)\n"<<
    "As well as removing a word by entering: /remove (InsertWord)\n"<<
    "To end the program, enter: /end\n";
    // while(true)
    // {
    //     string inputStr = "";
    //     cin>>inputStr;
    //     split(inputStr,' ');
    //     cout<<"\n";
    //     if (inputStr[0] == "/end")
    //     {
    //         break;
    //     };
    //     else if (inputStr[0] == "/lookup") dct.lookup(inputStr[1]);
    //     else if (inputStr[0] == "/insert") dct.insert(inputStr[1]);
    //     else if (inputStr[0] == "/remove") dct.remove(inputStr[1]);
    //     else
    //     {
    //         cout<<"Incorrect input, restarting operation.\n";
    //     }
    // }
    // cout<<"Program has ended.\n";
}
