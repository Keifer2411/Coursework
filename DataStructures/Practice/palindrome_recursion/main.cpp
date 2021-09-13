#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string str, int left, int right)
{
    if (left == right)
    {
        return true;
    }
    if(str[left] != str[right])
    {
        return false;
    }
    else
    {
        return isPalindrome(str, left+1, right-1);
    }

}



int main()
{
    string word = "madam";

    cout << "Is it a palindrome?" << endl;

    if (isPalindrome(word, 0, word.length()-1))
    {
        cout << "yes";
    }
    else
    {
        cout << "no";
    }
    return 0;

}