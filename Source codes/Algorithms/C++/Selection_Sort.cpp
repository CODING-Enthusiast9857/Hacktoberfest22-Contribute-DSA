#include "iostream"
using namespace std;
void selection_sort(int arr[],int size)
{
    for(int i=0;i<size-1;i++)
    {
        int min_index=i;
        int temp;
        for(int j=i+1;j<size;j++)
        {
             if(arr[j]<arr[min_index])
             {
                 min_index=j;
             }
        }
        if(min_index!=i) {
            temp = arr[min_index];
            arr[min_index] = arr[i];
            arr[i] = temp;
        }
    }
}

int main()
{
    int n;
    cout<<"Enter the number of elements you want in the array:";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements:";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    selection_sort(arr,n);
    cout<<"Sorted Elements are:";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

}


