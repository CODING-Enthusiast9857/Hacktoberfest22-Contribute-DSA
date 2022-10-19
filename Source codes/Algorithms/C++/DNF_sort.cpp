//Dutch National Flag
//dnf_sort is also called 0,1,2_sort since it can only sort arrays consisting only of 0s, 1s and 2s  elements
//time complexity - O(n)
//method:-
//check value of arr[mid]
//if 0, swap arr[low] and arr[mid], low++,mid++
//if 1, mid++
//if 2, swap arr[mid] and arr[high] , high--
#include<iostream>
#include<algorithm>
using namespace std;

void swap(int arr[],int i,int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;

}

void dnfsort(int arr[], int n){
    int low =0, mid =0, high =n-1;

    while(mid<=high){
        if(arr[mid]==0){
            swap(arr,low,mid);
            low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr,mid,high);
            high--;
        }
    }
}

int main(){
    int n;
    cout<<"Enter no. of elements : ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements : ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    dnfsort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
}

->test cases
Input: {0, 1, 2, 0, 1, 2}
Output: {0, 0, 1, 1, 2, 2}

Input: {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1}
Output: {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2}

--------------------------------------------------------
Time Complexity: O(n), Only nonnested traversals of the array are needed.
Space Complexity: O(1)
