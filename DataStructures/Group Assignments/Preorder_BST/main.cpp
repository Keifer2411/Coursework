#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "ArgumentManager.h"

using namespace std;

template <class T>
void printVect(vector<T>, ofstream&);

struct node {
   int data;
   struct node *left;
   struct node *right;
   struct node* parent;
};

struct node *createNode(int val) {
   struct node *temp = (struct node *)malloc(sizeof(struct node));
   temp->data = val;
   temp->left = temp->right = NULL;
   return temp;
}
void preorder(struct node *root, vector<char> dir, ofstream &outfile) {
   if (root != NULL) {
      outfile << "[";
      printVect(dir, outfile);
      outfile<< "] " << root->data << endl;
      
      if (root-> left != nullptr)
      {
        dir.push_back('l');
        preorder(root->left, dir, outfile);  
      }
      if (root->right != nullptr)
      {
        node* temp = root;
        if(temp->left != nullptr) {
          dir.pop_back();
        }
        dir.push_back('r');
        preorder(root->right, dir,outfile);
      }
   }
}
struct node* insertNode(struct node* n, int val) {
   if (n == NULL) return createNode(val);
   if (val < n->data)
   {
    node* leftchild = insertNode(n->left, val);
    n->left = leftchild;
    leftchild->parent = n;
   }
   else if (val > n->data)
   {
    node* rightchild = insertNode(n->right, val);
    n->right = rightchild;
    rightchild->parent = n;
   }
   return n;
}

template <class T>
void printVect(vector<T> vect, ofstream &outfile)
{
  for(auto it = vect.begin(); it != vect.end(); it++)
  {
    outfile << *it;
  }
}


int main(int argc, char *argv[]) {
	ArgumentManager am(argc, argv);
	const string input = am.get("input");
	const string output = am.get("output");
	

	ifstream infile;
	ofstream outfile;
	infile.open(input);
	outfile.open(output);
  
  string str;
  vector<int> value;
  vector<char> direction;
  
  while(getline(infile,str, ' ')) {
    
    int integer = atoi(str.c_str());
    value.push_back(integer);

  }
  
   struct node *root = NULL;
   root = insertNode(root, value[0]);
   direction.push_back('x'); //add root to vector
   //printVect(direction);

   for(int i = 0; i<value.size(); i++) {
      //if (value[i]<value[0]) {
      insertNode(root, value[i]);
      //}
    }
    

    //outfile<< "pre-order: "<< endl;
    preorder(root, direction, outfile);
    
    infile.close();
    outfile.close();
}


/*
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
struct node {
   int data;
   struct node *left;
   struct node *right;
};
struct node *createNode(int val) {
   struct node *temp = (struct node *)malloc(sizeof(struct node));
   temp->data = val;
   temp->left = temp->right = NULL;
   return temp;
}
void preorder(struct node *root) {
   if (root != NULL) {
      cout<<root->data<<" "<< endl;
      preorder(root->left);
      preorder(root->right);
   }
}
struct node* insertNode(struct node* node, int val) {
   if (node == NULL) return createNode(val);
   if (val < node->data)
   node->left = insertNode(node->left, val);
   else if (val > node->data)
   node->right = insertNode(node->right, val);
   return node;
}
int main() {
  ifstream ifs("input33.txt");
  
  string str;
  vector<int> value;
  
  while(getline(ifs,str, ' ')) {
    
    int integer = atoi(str.c_str());
    value.push_back(integer);

  }
  
   struct node *root = NULL;
   root = insertNode(root, value[0]);
   for(int i = 0; i<value.size(); i++) {
      //if (value[i]<value[0]) {
      insertNode(root, value[i]);
      //}
    }
    

    cout<< "pre-order: "<< endl;
    preorder(root);

    
}
*/