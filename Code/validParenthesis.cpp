#include <iostream>
#include <fstream>
#include <stack>
using namespace std;
int main()
{
    string line;
    ifstream myFile;
    stack<char> stack;
    bool valid = true;

    // by default open mode = ios::in mode
    myFile.open("validParenthesisCodeExample.txt");

    // Execute a loop until EOF (End of File)
    while (myFile)
    {

        // Read a Line from File
        getline(myFile, line);

        // Print line in Console
        for (int i = 0; i < line.length(); i++)
        {
            if ((line[i] == '{') || (line[i] == '(') || (line[i] == '['))
            {
                stack.push(line[i]);
            }
            else if (((line[i] == '}') && (stack.top() == '{')) || ((line[i] == ')') && (stack.top() == '(')) || ((line[i] == ']') && (stack.top() == '[')))
            {
                stack.pop();
            }
            else if (((line[i] == '}') && (stack.top() != '{')) || ((line[i] == ')') && (stack.top() != '(')) || ((line[i] == ']') && (stack.top() != '[')))
            {
                valid = false;
                break;
            }
        }
    }
    if (stack.empty() && valid != false)
    {
        cout << "Valid parenthesis";
    }
    else
    {
        cout << "Not valid parenthesis";
    }

    // Close the file
    myFile.close();

    return 0;
}