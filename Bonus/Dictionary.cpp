// Bonus Project - English Dictionary (15 pts)

// Yousef Ibrahim Gomaa Mahmoud - 320210207 - Section 10 - Group 4
// Code is also available on my GitHub protxtfile:
// https://github.com/37743/DS-Labs/tree/main/Bonus

// Libraries/Classes Needed: (fstream, iostream, string)
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

// Dictionary Class:
class Dictionary
{
    // Binary Save Tree as a dictionary.
    private:
    struct DictNode
    {
        string WordStr = "";
        DictNode* left;
        DictNode* right;
    };

    int countWords(DictNode* Root)
    {
        if (Root == NULL) return 0;
        else return countWords(Root->left)+countWords(Root->right)+1;
    }

    DictNode* insertNode(DictNode*& Root, string word) {
        if (Root == nullptr)
        {
            Root = new DictNode;
            Root->right = nullptr;
            Root->left = nullptr;
            Root->WordStr = word;
            return Root;
        }
        if (Root->WordStr > word) Root->left = insertNode(Root->left, word);
        else Root->right = insertNode(Root->right, word);
        return Root;
    }

    void getPredecessor(DictNode* Root, string word)
    {
        while(Root->right != NULL) Root = Root->right;
        word = Root->WordStr;
    }

    void Delete(DictNode*& Root, string word)
    {
        if (word < Root->WordStr) Delete(Root->left, word);
        else if (word > Root->WordStr) Delete(Root->right, word);
        else deleteNode(Root);
    }

    DictNode* deleteNode(DictNode*& Root)
    {
        string word;
        DictNode* Temp = Root;
        if (Root->left == NULL) {
            Root  = Root->right;
            delete Temp;
        }
        else if (Root->right == NULL) {
            Root = Root->left;
            delete Temp;
        }
        else{
            getPredecessor(Root->left, word);
            Root->WordStr = word;
            Delete(Root->left, word);
        }
    }

    void locateNode(DictNode* Root, string& word, bool& found)
    {
        if (Root == NULL)
        {
            found = false;
        }
        else if(word<Root->WordStr) locateNode(Root->left, word, found);
        else if(word>Root->WordStr) locateNode(Root->right, word, found);
        else
        {
            word = Root->WordStr;
            found = true;
        }
    }

    void inorderSave(DictNode* Root)
    {
        if (Root == nullptr) return;
        inorderSave(Root->left);
        txtfileout<<Root->WordStr<< '\n';
        inorderSave(Root->right);
    }

    // Public - Methods: (Dictionary(string), size(), insert(string), lookup(string), remove(string), inorderSave(DictNode))
    public:
    ifstream txtfile;
    ofstream txtfileout;
    DictNode* Dict = nullptr;
    Dictionary(string txtfilepath)
    {
        txtfile.open(txtfilepath);
        string WordStr;
        while(txtfile.is_open() && getline(txtfile,WordStr))
        {
            insertNode(Dict,WordStr);
        }
        txtfile.close();
    }

    int insert(string word)
    {
        if (lookup(word)==0)
        {
            insertNode(Dict,word);
            cout<<"Node inserted is: "<<word<<"\n";
            return 1;
        }
        else return 0;
    }

    int lookup(string word)
    {
        bool found = false;
        locateNode(Dict,word,found);
        if (found) return 1;
        else return 0;
    }

    int remove(string word)
    {
        if (lookup(word))
        {
            Delete(Dict,word);
            return 1;
        }
        else return 0;
    }

    int size()
    {
        cout<<"Current words size is: "<<countWords(Dict)<<'\n';
        return 1;
    }

    int save()
    {
        inorderSave(Dict);
        return 1;
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
    "To retrieve the amount of words in the dictionary, enter: /size\n"<<
    "To end the program, enter: /end\n"<<
    "-------------------------\n";
    while(true)
    {
        string inputStr = "";
        getline(cin,inputStr);
        stringstream data(inputStr);
        string command[2];
        int index = 0;
        while(getline(data, inputStr,' '))
        {
            command[index]= inputStr;
            index++;
        }
        cout<<"\n";
        if (command[0] == "/end")
        {
            dct.txtfileout.open("dictionary.txt");
            dct.save();
            dct.txtfileout.close();
            break;
        }
        else if (command[0] == "/lookup") cout<<dct.lookup(command[1])<<'\n';
        else if (command[0] == "/insert") cout<<dct.insert(command[1])<<'\n';
        else if (command[0] == "/remove") cout<<dct.remove(command[1])<<'\n';
        else if (command[0] == "/size") cout<<dct.size()<<'\n';
        else
        {
            cout<<"\nIncorrect input. Restarting operation.\n\n";
        }
    }
    cout<<"\nProgram has ended.";
}
