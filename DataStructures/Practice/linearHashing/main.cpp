//hashing
#include <iostream>
#include <vector>
using namespace std;

struct Node
{
        int key;
        string name;
};


class Hash
{
    private:
        int buckets;
        vector<Node*> table;

    public:
        Hash(int size)
        {
            vector<Node*> arr(size);
            table = arr;
            buckets = size;
        }
        int hashFunc1 (int key)
        {
            return (key % buckets);
        }
        void insert(int key, string name) //key, value pair 
        {
            bool found = false;
            Node* temp = new Node;
            temp->key = key;
            temp->name = name;
            int index = hashFunc1(key);

            while (table[index] != nullptr && table[index]->key != key) //this loop would not exist in direct hashing since the value just gets overwritten
            //this loop would also not be needed if open hashing because we would just pushback onto the vector or list index (vect[index].push_back(Node))
            {
                if (table[index]->name == name)
                {
                    found == true;
                }
                else
                {
                    index = (index+1) % buckets; //in quadratic probing this would be (index+1)^2 % buckets
                }
            }
            if (found){cout << "Dupe" << endl;}
            else {table[index] = temp;};
        }
        void print()
        {
            for (int i = 0; i < buckets; i++)
            {
                cout << "bucket " << i << ": ";
                cout << table[i]->name << endl;
            }
        }
};


int main()
{
    Hash table_1(6);
    table_1.insert(23, "Jacob");
    table_1.insert(36, "Billy");
    table_1.insert(53, "Maria");
    table_1.insert(14, "Jack");
    table_1.insert(72, "Jill");
    table_1.insert(42, "Bob");
    table_1.print();

}