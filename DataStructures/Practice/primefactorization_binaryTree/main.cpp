#include <iostream>
using namespace std;

//prime factorization Binary tree

void factors(int n, int i)
{
    if(i >= n/2)
    {
        return;
    }
    if (n%i == 0)
    {
        cout << i << " ";
    }
    factors(n, i+1);
}


int main()
{
    cout << "factors of 48: ";
    factors(48, 1);

    return 0;

}


//recursively access leaves of a tree
//you do not need new keyword to allocate space unless you are inserting a node* (pretty sure)
struct  Node
{
    int data;
    struct Node *left, *right;

}


void printLeaves(Node* root)
{
    //root is null return

    Node* curr = root;
    if (curr -> next == nullptr & curr -> right == nullptr)
    {
        cout << curr->value;
    }
    if (curr -> left != nullptr)
    {
        printLeaves(curr->next);
    }
    if(curr -> right != nullptr)
    {
        printLeaves(curr->right);
    }
}

void printMax(Node* root)
{
    Node* curr = root;
    if (curr->right == nullptr)
    {
        cout << curr->value;
        return;
    }
    printMax(curr->right);
}
