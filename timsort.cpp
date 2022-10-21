#include<bits/stdc++.h>
using namespace std;
const int RUN = 32; // Initialising the RUN to get chunks
void insertionSort(int arr[], int left, int right) // Implementing insertion
sort for RUN size chunks{
   for (int i = left + 1; i <= right; i++){
      int t = arr[i];
      int j = i - 1;
      while (j >= left && t < arr[j]){
         arr[j+1] = arr[j--];
      }
      arr[j+1] = t;
   }
}
void merge(int arr[], int l, int m, int r) // using the merge function the
sorted chunks of size 32 are merged into one{
   int len1 = m - l + 1, len2 = r - m;
   int left[len1], right[len2];
   for (int i = 0; i < len1; i++)
      left[i] = arr[l + i]; // Filling left array
   for (int i = 0; i < len2; i++)
      right[i] = arr[m + 1 + i]; // Filling right array
   int i = 0;
   int j = 0;
   int k = l;
   while (i < len1 && j < len2) // Iterate into both arrays left and right{
      if (left[i] <= right[j]) // IF element in left is less then increment i by pushing into larger array{
         arr[k] = left[i];
         i++;
      } else {
         arr[k] = right[j]; // Element in right array is greater
         increment j
         j++;
      }
      k++;
   }
   while (i < len1) // This loop copies remaining element in left array{
      arr[k] = left[i];
      k++;
      i++;
   }
   while (j < len2) // This loop copies remaining element in right array{
      arr[k] = right[j];
      k++;
      j++;
   }
}
void timSortAlgo(int arr[], int n){
   for (int i = 0; i < n; i+=RUN) insertionSort(arr, i, min((i+31), (n-1))); //Call insertionSort()
   for (int s = RUN; s < n; s = 2*s) // Start merging from size RUN (or 32). It will continue upto 2*RUN{
      // pick starting point of left sub array. We are going to merge
      arr[left..left+size-1]
      // and arr[left+size, left+2*size-1]
      // After every merge, we
      // increase left by 2*size
      for (int left = 0; left < n;left += 2*s){
         int mid = left + s - 1; // find ending point of left sub
         array mid+1 is starting point of right sub array
         int right = min((left + 2*s - 1), (n-1));
         merge(arr, left, mid, right); // merge sub array
         arr[left.....mid] & arr[mid+1....right]
      }
   }
}
void printArray(int arr[], int n){
   for (int i = 0; i < n; i++)
      cout << arr[i] << " ";
   cout << endl;
}
// Main function to implement timsort algorithm
int main(){
   int arr[] = {-2, 7, 15, -14, 0, 15, 0, 7, -7, -4, -13, 5, 8, -14, 12};
   int n = sizeof(arr)/sizeof(arr[0]);
   cout << "The Original array- ";
   printArray(arr, n);
   // calling the timsortAlgo function to sort array
   timSortAlgo(arr, n);
   cout<<"After Sorting Array Using TimSort Algorithm- ";
   printArray(arr, n); // Calling print function
   return 0;
}
