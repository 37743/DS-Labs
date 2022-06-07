// Bonus Project - English Dictionary (15 pts)

// Yousef Ibrahim Gomaa Mahmoud - 320210207 - Section 10 - Group 4
// Code is also available on my GitHub DS-Labs repo:
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
        string preWord = "";
        DictNode* left;
        DictNode* right;
    };
    // Counts amount of nodes/words in the tree.
    int countWords(DictNode* Root)
    {
        if (Root == NULL) return 0;
        else return countWords(Root->left)+countWords(Root->right)+1;
    }
    // Inserts a new node.
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
    // Modifies the string to the closest smaller string in the tree.
    void getPredecessor(DictNode* Root, string& word)
    {
        while(Root->right != NULL) Root = Root->right;
        word = Root->WordStr;
    }
    // Delete method(s).
    void Delete(DictNode*& Root, string& word)
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
            Root = Root->right;
            delete Temp;
        }
        else if (Root->right == NULL) {
            Root = Root->left;
            delete Temp;
        }
        else
        {
            getPredecessor(Root->left, word);
            Root->WordStr = word;
            Delete(Root->left, word);
        }
    }
    // Returns true if the entered string has been found in the dictionary.
    void locateNode(DictNode* Root, string& word, bool& found)
    {
        if (Root == NULL) found = false;
        else if(word<Root->WordStr) locateNode(Root->left, word, found);
        else if(word>Root->WordStr)
        {             
            Root->preWord = Root->WordStr;
            locateNode(Root->right, word, found);
        }
        else
        {
            word = Root->WordStr;
            found = true;
        }
    }
    // Writes all nodes into the open .txt file.
    void inorderSave(DictNode* Root)
    {
        if (Root == nullptr) return;
        inorderSave(Root->left);
        txtfileout<<Root->WordStr<< '\n';
        inorderSave(Root->right);
    }

    // Public - Methods: (Dictionary(string), size(), insert(string), lookup(string), remove(string), inorderSave(DictNode))
    public:
    ifstream txtfile; // input instance
    ofstream txtfileout; // output instance
    DictNode* Dict = nullptr;
    Dictionary(string txtfilepath)
    {
        txtfile.open(txtfilepath); // accesses the file for input.
        string WordStr;
        while(txtfile.is_open() && getline(txtfile,WordStr))
        {
            insertNode(Dict,WordStr); // inserts each line's string in the file as a node.
        }
        txtfile.close(); // closes the file.
    }
    // Calls the insert method on the dictionary class if node doesn't already exist.
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
    // Calls the locate method to search for the given string.
    int lookup(string word)
    {
        bool found = false;
        locateNode(Dict,word,found);
        if (found) return 1;
        else return 0;
    }
    // Calls the remove method if node exists, otherwise suggests the closest string in lexographical order.
    int remove(string word)
    {
        if (lookup(word))
        {
            Delete(Dict,word);
            return 1;
        }
        else
        {
            string preWord="";
            string postWord="";
            DictNode* Node = Dict;
            while(Node)
            {
                if (word<Node->WordStr)
                {
                    postWord = Node->WordStr;
                    Node = Node->left;
                }
                else if (word>Node->WordStr)
                {
                    preWord = Node->WordStr;
                    Node = Node->right;
                }
            }
            if (word.size()-preWord.size() > word.size()-postWord.size()) word = preWord;
            else word = postWord;
            cout<<"Word not found! Did you perhaps mean "<<word<<"?\n";
            return 0;
        } 
    }
    // Calls the count method to return amount of words in the dictionary.
    int size()
    {
        cout<<"Current word size is: "<<countWords(Dict)<<'\n';
        return 1;
    }
    // Calls the inorder saving method to write all nodes' strings into the .txt file.
    int save()
    {
        inorderSave(Dict);
        return 1;
    }
};

int main()
{
    Dictionary dct("dictionary.txt"); // creates an object of type Dictionary with its filepath.
    cout<<"Hello! This is a dictionary. Created by Yousef Ibrahim Gomaa Mahmoud - ID: 320210207\n"<<
    "-------------------------\n"<<
    "You can look up words by entering:\t\t\t\t\t /lookup (InsertWord)\n"<<
    "You can also insert a new word by entering:\t\t\t\t /insert (InsertWord)\n"<<
    "As well as removing a word by entering:\t\t\t\t\t /remove (InsertWord)\n"<<
    "To retrieve the amount of words in the dictionary, enter:\t\t /size\n"<<
    "To end the program and commit all changes into the .txt file, enter:\t /end\n"<<
    "-------------------------\n";
    while(true) // Infinite loop to keep the interface open.
    {   /* Takes input and splits the string into 2 parts,
         'command' and 'input string', which changes behavior of program
         according to the given command.*/
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
        if (command[0] == "/end") // Saves all changes if prompt enters: '/end'
        {
            dct.txtfileout.open("dictionary.txt");
            dct.save();
            dct.txtfileout.close();
            break; // Breaks out of the infinite loop.
        }
        else if (command[0] == "/lookup") cout<<dct.lookup(command[1])<<'\n';
        else if (command[0] == "/insert") cout<<dct.insert(command[1])<<'\n';
        else if (command[0] == "/remove") cout<<dct.remove(command[1])<<'\n';
        else if (command[0] == "/size") cout<<dct.size()<<'\n';
        else
        {
            cout<<"Incorrect input. Restarting operation.\n\n";
        }
    }
    cout<<"Program has ended, all info has been saved inside the .txt file.";
}
