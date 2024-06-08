#include <bits/stdc++.h>
using namespace std;

class MaxHeap {
private:
    vector<int>arr;
    int currIndex;

public:
    MaxHeap() {
       currIndex = 0;
       arr.push_back(-1);
    }

    void insertInHeap(int num) {
        // O(logn) - Time
        // Formula for parent and left child and right child in this implementation is only valid beacuse its 1 based indexing
        currIndex++;
        int index = currIndex;
        arr.push_back(num);

        while(index > 1) {
            int parent = index / 2;
            
            if(arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            } else
                return;         
        }
    }

    void deleteFromHeap() {
        //Deleted node is always the top one (1st index):
        //O(logn) - Time
        // Copy the last node value to first node and then delete last node and then make the Heap formed valid:
        arr[1] = arr[currIndex];
        currIndex--;
        arr.pop_back();
        //This function takes root node from the heap and move it to its correct position
        heapify(arr, 1, currIndex);
    }

    void heapify(vector<int> &arr, int ind, int index) {
        //O(logn) - Time
        int i = ind;
        while(i <= index) {
            int leftChildIndex = 2 * i;
            int rightChildIndex = 2 * i + 1;
            //Left child should be greater than parent and right child (if it exists)
            if(leftChildIndex <= index && arr[i] < arr[leftChildIndex] && (rightChildIndex > index || arr[leftChildIndex] >= arr[rightChildIndex])) {
                swap(arr[i], arr[leftChildIndex]);
                i = leftChildIndex;
            } 
            //Right child should be greater than parent and left child
            else if(rightChildIndex <= index && arr[i] < arr[rightChildIndex] && arr[rightChildIndex] >= arr[leftChildIndex]) {
                swap(arr[i], arr[rightChildIndex]);
                i = rightChildIndex;
            }
            else
                return;

        }

        //Note: Recursion method of heapify(https://www.tutorialspoint.com/design_and_analysis_of_algorithms/design_and_analysis_of_algorithms_heapify_method.htm)and this method (iterative) works the same and gives same result.
    }

    void buildHeap(vector<int> &aux) {
        //This will make the array elements turn into a max heap
        //O(n) - Time and not O(nlogn) (https://stackoverflow.com/questions/9755721/how-can-building-a-heap-be-on-time-complexity)

        //We won't iterate on leaf nodes as they are already in their correct position
        //For 1 based indexing and Complete Binary tree leaf nodes are from (O(n/2 + 1) to O(n))
        int n = aux.size() - 1;
        for(int i = n / 2; i > 0; i--) {
            heapify(aux, i, currIndex);
        }
    } 

    void heapSort(vector<int> &aux) {
        //Sort a random array (which is not a heap currently) in the ascending order
        //O(nlogn) - Time

        //Build heap
        buildHeap(aux);

        int index = currIndex;

        while(index > 1) {
            //Swap first element (max element) with the last element so that max is always at last and then repeat for 0 to lastindex - 1
            swap(aux[1], aux[index]);
            index--;
            heapify(aux, 1, index);
        }
    }

    void print() {
        for(int i = 0; i <= currIndex; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

};


int main() {

    MaxHeap h;
    h.insertInHeap(50);
    h.insertInHeap(55);
    h.insertInHeap(53);
    h.insertInHeap(52);
    h.insertInHeap(54);

    h.print();

    h.deleteFromHeap();
    h.print();

    h.insertInHeap(55);
    h.print();

    vector<int> aux = {-1, 54, 53, 52, 50, 55};

    cout << "Before build heap" << endl;
    for(auto it: aux)
        cout << it << " ";
    cout << endl;
 
    h.buildHeap(aux);

    cout << "After build heap" << endl;
    for(auto it: aux)
        cout << it << " ";
    cout << endl;

    h.heapSort(aux);
    cout << "After Heap Sort" << endl;
    for(auto it: aux)
        cout << it << " ";
    cout << endl;

    return 0;

    // IMP NOTE FOR STL:
    
    // When we use cmp function (for any custom data type) ,  we should use this template:
    // priority_queue<data_type, vector<data_type>, cmp>, whether min or max heap otherwise complier will throw an error.

    // Also cmp function should have a template like this:

    // struct cmp {
    //     bool operator ()(pair<float, pair<int, int>> &a, pair<float, pair<int, int>> &b) {
    //         // For max heap
    //         return a.first < b.first;
    //     }
    // };

    // We can't use this template:
    // bool cmp(pair<float, pair<int, int>> &a, pair<float, pair<int, int>> &b) {
    //       // For max heap
    //       return a.first < b.first;
    //  }

}