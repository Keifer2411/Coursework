//Heap Sort

//in heap sort we create heap from array (heap represented by array)
//left child of a node in a heap is i*2+1 (the blus one is becasue the array starts at index 0 and not 1) and right child is i*2+2 based on i position of that node in the array (), 
//max heap- max value is root, min heap- min value is at root
//assuming we are doing a max heap
//heapify brings max value to the top of the heap
//we move that value to the end of the array, knowing it is the max value, and remove it from the tree
//we heapify, which moves the new max value in the heap to the root and put that value in the second last position of the heap
//... and so on
//priority queue can use heap


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class maxHeap
{
    private:
        int size; //number of nodes in heap
        vector<int> vect; //vector to sort
        int parent (int index) {return index/2;}
        int l_child (int index) {return index*2 +1;}
        int r_child (int index) {return index*2 +2;}
    
    public:
        maxHeap (vector<int> v) //constructing heap
        {
            this->vect = v;
            this->size = v.size();

            for(int i= size/2-1; i>=0; i--)
            {
                maxHeapify(vect, i, size);
            }
        }
        void heapsort()
        {
            for (int i = size/2 -1; i >= 0; i--){maxHeapify(vect, i,size);}
            extractMax(vect);
        }
        void extractMax(vector<int> &vect)
        {
            for (int i= size -1; i > 0; i--)
            {
                swap(vect[0], vect[i]);
                maxHeapify(vect, 0, i);
            }
        }
        void maxHeapify(vector<int> &vect, int i, int s) //for every subtree, if a child is greater than the parent swap them with the parent
        {
            int index_of_largest = i;
            int l = l_child(i);
            int r = r_child(i);

            //check left side
            if (l < s && vect[l] > vect[index_of_largest]) //if child is greater than parent
            {
                index_of_largest = l;
            }    
            //check right side
            if (r < s && vect[r] > vect[index_of_largest]) //if child is greater than parent
            {
                index_of_largest = r;
            }
            if (index_of_largest != i) //if parent node is not the largest, index_of_largest no longer equals i, and we need to swap with parent
            {
                swap(vect[i], vect[index_of_largest]);
                maxHeapify(vect, i, s); //this is called until index of largest = i;
            }
        }

        bool isEmpty() {return size==0;}

        void print()
        {
            for (auto it = vect.begin(); it != vect.end(); it++)
            {
                cout << *it << " ";
            }
        }
    

};

int main()
{
    vector<int> v = {12, 45, 62, 23, 44, 9, 36};
    maxHeap heap(v);
    heap.print();
    heap.heapsort();
    cout << endl;
    heap.print();
    //this heap sort is basically a priority queue
}

//to delete from sorted heap:
//delete node from array
//replace it with farthest right on lowest level
//heapify
//heapsort