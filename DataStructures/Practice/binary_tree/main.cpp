//binary tree

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class binaryT
{
    private:
        vector<int> vect;
        int l_child(int index){return index/2 +1;}
        int r_child(int index){return index/2 +2;}
        int parent(int index){return index *2;}

    public:
        binaryT(){}
        void insertElem(int num)
        {
            vect.push_back(num);
        }
        int searchElem(int num)
        {
            int i =0;
            for (auto it= vect.begin(); it != vect.end(); it++)
            {
                if (*it == num) {return i;}
                i++;
            }
            return -1;
        }
        void deleteElem(int num)
        {
            for (int i = 0; i < vect.size(); i++)
            {
                if (vect[i] == num)
                {
                    swap(vect[i], vect[vect.size()-1]);
                    break;
                }
            }
            vect.pop_back();
            return;
        }
        void print()
        {
            for (auto it= vect.begin(); it != vect.end(); it++)
            {
                cout << *it << " ";
            }
            cout << endl;
        }
};

int main()
{
    int arr[] = {30, 23, 54, 12, 76, 3, 14};
    binaryT bT;
    for (int i=0; i<7; i++)
    {
        bT.insertElem(arr[i]);
    }
    bT.print();
    cout << "Element 12 found at pos: " << bT.searchElem(12) << endl;  
    bT.deleteElem(12);
    bT.print();



}