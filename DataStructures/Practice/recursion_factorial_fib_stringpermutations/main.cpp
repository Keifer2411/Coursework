//recursion
#include <string>
#include <iostream>

using namespace std;
//void stringpperm(string, int, int);
int factorial(int , int );

void stringperm(string str, int left, int right)
{
    if (left == right)
    {
        cout << str << endl;
        return;
    }
    else
    {
        for (int i=left; i<=right; i++)
        {
            swap(str[left], str[i]);
            stringperm(str, left+1, right); //left plus one moves on from fixed a in first position to fixed b in first postion during swap
            swap(str[left],str[i]); //allows you to print in right order*
        }
    }
}

int factorial(int num)
{
    if (num == 1)
    {
        return num;
    }
    return num * factorial(num-1);
}

int fibonacci(int num)
{
    if (num <= 1)
    {
        return num;
    }
    return fibonacci(num-1) + fibonacci(num-2);
}


int main()
{
    string s = "abcd";
    stringperm(s, 0, s.size()-1);
    cout << factorial(5) << endl;
    cout << fibonacci(8);

    return 0;
    
}