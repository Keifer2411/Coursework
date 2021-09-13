//singly linked list

#include <iostream>
using namespace std;

//A node is a data structure with a link
//If you know the head of a list you can access anything in a list
//To access members of a structure that are pointers use ->

struct point
{
    int x;
    int y;
    point* next;
};

class line
{
    private:
        point* head = nullptr;

    public:
        line(){}
        void insert_toEnd(int a, int b)
        {
            point* temp = new point; 
            point* curr = new point;
            temp->x = a;
            temp->y = b;
            temp->next = nullptr;
            if (head == nullptr)
            {
                head = temp;
                return;
            }
            else
                curr = head; //head is a pointer to the first node
            {
                while (curr->next != nullptr)
                {
                    curr = curr->next;
                }
                curr->next = temp;
            }
        }
        void insert_toBegin(int a, int b)
        {
            point *temp = new point;
            temp->x = a;
            temp->y = b;
            if(head == nullptr)
            {
                head = temp;
            }
            else
            {
                temp -> next = head;
                head = temp;
            }
        }
        recprint(){recprint(head);}
        void recprint(point * curr)
        {
            if (curr == nullptr)
            {
                return;
            }
            else
            {
                cout << curr -> x << " " << curr->y << endl;
                recprint (curr -> next);
            }
        }
};

int main()
{
    line sll;
    sll.insert_toEnd(2, 3);
    sll.insert_toEnd(2, 5);
    sll.insert_toEnd(5, 3);
    sll.insert_toBegin(8, 5);
    sll.recprint();
    return 0;

}

