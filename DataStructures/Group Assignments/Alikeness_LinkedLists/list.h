#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct node{
    string data;
    node * next;
};

class list{
    private:
        int size = 0;
        node * head = new node;
        string *array;
    public:
        list();
        list(string filename);
        void printList();
        //string* createArray();
        vector<string> createArray();
        string at(int pos);
        int getSize(){ return size; }
        
};



#endif