#include <iostream>
#include <vector>
using namespace std;
const int Max = 1000;

// merge sort
void Merge(std::vector<int> &Array, int front, int mid, int end){

    // 利用 std::vector 的constructor,
    // 把array[front]~array[mid]放進 LeftSub[]
    // 把array[mid+1]~array[end]放進 RightSub[]
    std::vector<int> LeftSub(Array.begin()+front, Array.begin()+mid+1),
                     RightSub(Array.begin()+mid+1, Array.begin()+end+1);

    LeftSub.insert(LeftSub.end(), Max);      // 在LeftSub[]尾端加入值為 Max 的元素
    RightSub.insert(RightSub.end(), Max);    // 在RightSub[]尾端加入值為 Max 的元素

    int idxLeft = 0, idxRight = 0;

    for (int i = front; i <= end; i++) {

        if (LeftSub[idxLeft] <= RightSub[idxRight] ) {
            Array[i] = LeftSub[idxLeft];
            idxLeft++;
        }
        else{
            Array[i] = RightSub[idxRight];
            idxRight++;
        }
    }
}

void MergeSort(std::vector<int> &array, int front, int end){
                                        
    if (front < end) {
        int mid = (front+end)/2;
        MergeSort(array, front, mid);
        MergeSort(array, mid+1, end);
        Merge(array, front, mid, end);
    }
}
// quick sort
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int Partition(vector<int> &array, int front, int end){
    int pivot = array[end];
    int i = front -1;
    for (int j = front; j < end; j++) {
        if (array[j] < pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    i++;
    swap(&array[i], &array[end]);
    return i;
}
void QuickSort(vector<int> &array, int front, int end){
    if (front < end) {
        int pivot = Partition(array, front, end);
        QuickSort(array, front, pivot - 1);
        QuickSort(array, pivot + 1, end);
    }
}
void InsertionSort(vector<int> &array){
    for(int i = 1; i<array.size();i++){
        int key = array[i];
        int j = i-1;
        while (key < array[j] && j >= 0) {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
    }
}
void PrintArray(std::vector<int> &array){
    for (int i = 0; i < array.size(); i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int main() {

    int arr[] = {5,3,8,6,2,7,1,4};
  
    
    vector<int> array(arr, arr+sizeof(arr)/sizeof(int));

    cout << "original:\n";
    PrintArray(array);

    InsertionSort(array);
    std::cout << "sorted:\n";
    PrintArray(array);

    return 0;
}
