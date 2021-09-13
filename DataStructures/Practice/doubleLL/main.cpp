#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;
};

class DLL
{
    private:
        Node* head;
        Node* tail;

    public:
        DLL()
        {
            head = 0;
            tail = 0;
        }
        //~DLL(){delete this;}
        void insertNode_end(int value)
        {
            Node* temp = new Node;
            temp->data = value;
            
            if (head == nullptr)
            {
                head = temp;
                head->next = nullptr;
                head->prev = nullptr;
            }
            else
            {
                Node* curr = head;
                while (curr->next != nullptr)
                {
                    curr = curr->next;
                }
                temp->prev = curr;
                temp->next = nullptr;
                curr->next = temp;
                tail = temp;
            }
        }
        void insertNode_begin(int value)
        {
            Node* temp = new Node;
            temp->data = value;

            if (head == nullptr)
            {
                temp = head;
                head->next = nullptr;
                head->prev = nullptr;
            }
            else
            {
                temp->prev = nullptr;
                temp->next = head;
                head->prev = temp;
                if (head->next == nullptr)
                {
                    tail = head;
                }
                head = temp;
            }
        }

        void deleteNode(int value)
        {
            if (head == nullptr){return;}
            if (head->data == value && head->next == nullptr)
            {
                head = 0;
                return;
            }
            Node* curr = head;            
            while (curr != nullptr)
            {
                if(curr-> data == value)
                {
                    Node* temp = curr;
                    if (curr == head)
                    {
                        head->next->prev = nullptr;
                        head = head->next;
                        curr = temp->next;
                        delete temp;
                        continue;
                    }
                    if (curr->next == nullptr)
                    {
                        curr->prev->next = nullptr;
                        tail = curr->prev;
                        delete temp;
                        return;
                    }
                    else
                    {
                        curr -> prev -> next = curr -> next;
                        curr -> next -> prev = curr -> prev;
                        curr = temp->next;
                        delete temp;
                        continue;
                    }
                }
                curr = curr->next;
            }
            return;
        }
        void print()
        {
            Node* curr = head;
            while (curr != nullptr)
            {
                cout << curr->data << " ";
                curr = curr->next;
            }
            
        }
};



int main()
{
    DLL linkedlist;
    linkedlist.insertNode_end(2);
    linkedlist.insertNode_end(4);
    linkedlist.insertNode_end(9);
    linkedlist.insertNode_end(8);
    linkedlist.insertNode_end(3);
    linkedlist.insertNode_end(1);
    linkedlist.insertNode_end(5);
    linkedlist.insertNode_end(10);
    linkedlist.insertNode_begin(8);
    linkedlist.insertNode_begin(9);
    linkedlist.print();
    cout << endl;
    linkedlist.deleteNode(9);
    linkedlist.print();

    return 0;
    
}