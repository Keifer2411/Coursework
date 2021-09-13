#pragma once
#include <iostream>
#include <string>

using namespace std;

enum difficulty{easy = 1, medium =2, hard = 3};

struct Problem
{
    string whole;
    int id;
    string name;
    difficulty diff;
};

struct node
{
    node* next;
    node* prev;
    Problem data;
};

class LinkedList
{
    private:
        node* head;
    public:
        LinkedList(){head =0;}
        void addtoEnd(Problem);
        //void addnode(int, Problem );
        //void removebyDiff(difficulty diff);
        //void removebyName(string name);
        //void removebyPos(int);
        //void sortbyDiff();
        //void sortbyName();
        //void sortbyID();
        void print(ofstream&);
};


//this was taken mainly from my extra_6_2_4
void LinkedList::addtoEnd(Problem toAdd)
{
    //cout << toAdd.whole <<endl;;
    node* temp = new node;

    temp->data = toAdd;

    if (head == nullptr)
    {
        head = temp;
        head->next = nullptr;
        head->prev = nullptr;
    }
    else
    {
        node* curr = head;
        while (curr->next != nullptr)
        {
            curr = curr->next;
        }
        temp->prev = curr;
        temp->next = nullptr;
        curr->next = temp;
    }
}

void LinkedList::print(ofstream &out)
{
    node* curr = head;

    while (curr != nullptr)
    {
        out << curr->data.whole << endl;
        curr = curr-> next;
    }
}