//infix to postfix
//example used from https://www.geeksforgeeks.org/stack-set-2-infix-to-postfix/

#include <iostream>
#include <stack>

using namespace std;

int order (char c)
{
    if (c == '/'){return 2;}
    if (c == '*'){return 1;}
    if (c == '+' || c == '-'){return 0;}
    else {return -1;}
}
void infixToPostfix(string str)
{
    stack<char> operators;
    string result = "";
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if(ch >= '0' && ch <= '9') //if number
        {
            result = result + ch;
        }
        else if (ch == '(')
        {
            operators.push(ch);
        }
        else if (ch == ')')
        {
            while (operators.top() != '(')
            {
                result = result + operators.top();
                operators.pop();
            }
            operators.pop(); //pop the (
        }
        else
        {
            while(!operators.empty() && order(ch) <= order(operators.top())) //while stack is not empty and the character is less than or equal to the top of stack
            {
                result = result + operators.top();
                operators.pop();
            }
            operators.push(ch); //if stack is empty push
        }  
    }
    while (!operators.empty())
    {
        result = result + operators.top();
        operators.pop();
    }
    cout << result;
}


int main()
{

    infixToPostfix("(6+3)*8+24/4");
    return 0;
}

