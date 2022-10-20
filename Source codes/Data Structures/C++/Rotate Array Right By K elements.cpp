#include<iostream>
using namespace std;

void reverse(int *arr, int start, int end){
    int i = start, j = end;
    while(i<j){
        swap(arr[i],arr[j]);
        i++;j--;
    }
}

int main(){
    int n;
    cin >> n;
    
    int k;
    cin >> k;
    k = k%n;
    
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    reverse(arr,0,n-1);
    reverse(arr,0,k-1);
    reverse(arr,k,n-1);
    
    for(int i = 0; i < n; i ++){
        cout << arr[i] << " ";
    }
}
