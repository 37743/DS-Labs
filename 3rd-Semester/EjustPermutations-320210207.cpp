// Yousef Ibrahim Gomaa Mahmoud - 320210207

// Sheet 8 - Question 4
#include <iostream>
using namespace std;

void calcPerm(string strIn, string strOut)
{
    int j = 0;
    if (strIn.length() == 0) {
        cout<<strOut<<"\n";
        return;
    }

    for (char i: strIn)
    {
        char temp = i; // Store letter temporarily
        // Append the letter to the end and continue the recursion function.
        calcPerm(strIn.substr(0, j)+strIn.substr(j+1), strOut+temp);
        j++;
    }
}

int main()
{
    string Input = "EJUST";
    string Output = "";
    cout<<"######## Question 4 ########\n---------------------------"
    <<"\nAll permutations of the string \"EJUST\" are:\n\n";
    calcPerm(Input, Output);
}