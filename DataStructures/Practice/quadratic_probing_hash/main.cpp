//Quadratic Probing

#include <iostream>
#include <vector>
using namespace std;

class HashTable
{
    private:
        int tablesize;
        vector<int> table;

    public:
        HashTable(int s)
        {
            vector<int> arr(s);
            table = arr;
            tablesize = s;
        }

        int hashFunc(int key)
        {
            //cout << key << "%" << tablesize << endl;
            return key%tablesize;
        }

        int hashFunc2(int key)
        {
            return key*3 % tablesize;
        }

        void insert(int key)
        {

            int index = hashFunc(key);
            int index2 = hashFunc2(key);
            int i = 1;

            while(table[index] != 0)
            {
                index = (index+(i*i)) %tablesize; //quadratic
                //index = (index+1) %tablesize; //linear
                //index = (index + i*index2)% tablesize; //double
                i++;
            }
            table[index] = key;
        }

        void print()
        {
            for(int i =0; i < tablesize; i++)
            {
                cout << i << ": " << table[i] << endl;
            }
        }

};


int main()
{
    int arr[] = {17, 22, 13, 27, 34, 18, 5, 36, 41};
    int s = 9;
    HashTable h(s);
    for (int i=0; i < s; i++)
    {
        h.insert(arr[i]);
    }
    
    h.print();
}