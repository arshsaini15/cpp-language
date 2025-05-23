// Deletion in a Heap.

#include<iostream>
using namespace std;

class heap{

    public:
    int arr[100];
    int size;

    heap(){
        arr[0]=-1;
        size = 0;
    } 

    void deletion(){
        if(size == 0){
            return;
        }

        // Step 1: put last element to its correct position.
        arr[1] = arr[size];

        // Step 2: remove last element;
        size--;

        // Step 3: take root node to its correct position.
        int i=1;
        while(i<size){
            int leftIndex = 2*i;
            int rightIndex = 2*i+1;

            if(leftIndex < size && arr[i] < arr[leftIndex]){
                swap(arr[i],arr[leftIndex]);
                i = leftIndex;
            }
            else if(rightIndex < size && arr[i] < arr[rightIndex]){
                swap(arr[i],arr[rightIndex]);
                i = rightIndex;
            }
            else{
                return;
            }
        }  
    }

    void insert(int val){
        size+=1;
        int index = size;
        arr[index] = val;

        while(index > 1){

            int parent = index/2;

            if(arr[parent] < arr[index]){
                swap(arr[parent] , arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }
    }
    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }
};


int main(){

    heap h;

    h.insert(50);
    h.insert(55);
    h.insert(52);
    h.insert(54);

    h.print();

    h.deletion();
    h.print();

    return 0;
}