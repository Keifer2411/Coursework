#include <iostream>
using namespace std;

//Binary search tree is used exclusively for searching and its elements are inserted in order
//A binary tree does not have to be in any order but does have a max of two children per parent
//BST
struct node
{
    int data;
    node* left;
    node* right;
};

node* minV(node* root)
{
    while(root->left != nullptr)
    {
        root =root->left;
    }
    return root;
}

node* insert (node* root, int num)
{
    if (root == nullptr)
    {
        node* newNode = new node;
        newNode->data = num;
        newNode->right = nullptr;
        newNode->left = nullptr;
        root = newNode;
    }
    else if(num <= root->data){root->left = insert(root->left, num);}
    else {root->right= insert(root->right, num);}
    return root;
}
node* remove_node (node* root, int num) //n starts as root
{
    if (root == nullptr)
    {
        return root;
    }
    //searching for node
    if (num < root->data){root->left = remove_node(root->left, num);}
    else if (num > root->data){root->right = remove_node(root->right, num);}
    //if found we need to delete it and move nodes accordingly
    else
    {
        if (root->left == nullptr && root->right == nullptr){return nullptr;} //if no child make the node that is found a nullptr
        else if (root->left != nullptr && root->right == nullptr)
        {
            node* temp = root->left;
            delete root;
            return temp;
        }
        else if (root->right != nullptr && root->left == nullptr)
        {
            node* temp = root->right;
            delete root;
            return temp;
        }
        else
        {
            node* temp = minV(root->right); //temp is equal to the minimum Value in the right subtree
            root->data = temp->data; //replace root with that minvalue
            root->right = remove_node(root->right, temp->data); //remove original root, needs to be recursive
        }
    }
    return root;
}

void print(node* root) //in order, print is the same as search excebt we return false if root==nullptr, and instead of cout we add an if statement
{
    if (root == nullptr) {return;}
    print(root->left);
    cout << root->data << " ";
    print(root->right);
}


int main()
{

    int arr[8] = {72, 56, 67, 36, 21, 94, 32, 8};


    node* root = nullptr;
    for (int i = 0; i < 8; i++)
    {
        root = insert(root, arr[i]);
        cout << "inserted: " << arr[i] << endl;
    }

    print(root);
    cout << endl;

    root = remove_node(root, 32);

    print(root);

    return 0;

}