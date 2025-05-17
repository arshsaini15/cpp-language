// copying values of 2 different arrays and putting them in other array...!



#include<iostream>
using namespace std;
int main(){
    int arr1[5] = {1,2,3,4,5};
    int arr2[5] = {6,7,8,9,10};

    int arr3[5];
    int j = 0;

    for(int i=0;i<3;i++){
        arr3[i] = arr1[j++];
    }
 
    int k = 3; 

    for(int i=3;i<5;i++){
        arr3[i] = arr2[k++];
    }

    for(int i=0;i<5;i++){
        cout<<arr3[i]<<" ";
    }

    return 0;

}