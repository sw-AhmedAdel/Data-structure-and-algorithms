#include <iostream>
using namespace std;

 
void print(int arr[] , int size) {
    for(int i=0 ;i<size ; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

 
void ShellSort(int arr[], int size){
    for(int gap= size /2 ; gap >=1 ; gap = gap/2) {//get the gab for each iteration 
        for(int j=gap ; j<size ; j++) {
            int temp=arr[j];
            int i= j-gap;//if gap is 5 so j will point at f and i at 0 and compare between them
            while(i>=0 && arr[i] > temp) {
                arr[i+gap] =arr[i]; //if i=0 and gab is 5 but number in i is > temp which is index 5 so swap >0+5= number in index i
                //and change i >>> i=i-gap , -5= 0-5; so -5 <0 so break the loop
                i=i-gap;
            }
            arr[i+gap]=temp;//here i=-5 + gap 5 so will be 0 so index 0 will have what data in temp 
            //what if arr[i]< temp so nothing happend to temp >> if i=0 and gab is 5 and no swap so i=i+5 = temp >>0+5=5 
            //so index 5 will have temp which is the same data 
        }
    }
}
 
int main() {
 
    int arr[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    ShellSort(arr,n);
    print(arr,n);
 
    return 0;
}