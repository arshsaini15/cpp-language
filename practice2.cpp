#include<iostream>
using namespace std;

class heap{
    public:
    
    int arr[100];
    int size;

    heap(){
        size = 0;
        arr[0] = -1;
    }

    void insert(int val){
        size += 1;
        arr[size] = val;

        int index = size;
        while(index > 1){
            int parent = index/2;
            if(arr[index] > arr[parent]){
                swap(arr[index], arr[parent]);
                index = parent;
            }
            else{
                return;
            }
        }
    }

    void deletion(){

        if(size == 0){
            return;
        }

        arr[1] = arr[size];
        size--;

        int i = 1;
        while(i <= size){
            int left = 2*i+1;
            int right = 2*i+2;

            if(left < size && arr[i] < arr[left]){
                swap(arr[i], arr[left]);
                i = left;
            }

            else if(right < size && arr[i] < arr[right]){
                swap(arr[i], arr[right]);
                i = right;
            }

            else{
                return;
            }
        }
    }

    void heapify(int arr[], int n, int i){
        int largest = i;
        int left = 2*i+1;
        int right = 2*i+2;

        if(left <= n && arr[largest] < arr[left]){
            largest = left;
        }

        if(right <= n && arr[largest] < arr[right]){
            largest = right;
        }

        if(largest != i){
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
    }

    void heapSort(int arr[], int n){
        int size = n;

        while(size > 1){
            swap(arr[1], arr[size]);
            size--;

            heapify(arr, size, 1);
        }

        
    }

    void print(){
        for(int i=1; i<=size; i++){
            cout << arr[i] << " ";
        }cout << endl;
    }
};

int main(){

    heap h;
    h.insert(55);
    h.insert(54);
    h.insert(59);
    h.insert(22);
    h.insert(98);

    h.print();

    h.deletion();
    h.print();

    return 0;
}