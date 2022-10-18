#include "iostream"
using namespace std;
void selection_sort(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        int min_index=i,temp;
        for(int j=i+1;j<size;j++)
        {
             if(arr[j]<arr[min_index])
             {
                 min_index=j;
             }
        }
        temp=arr[min_index];
        arr[min_index]=arr[i];
        arr[i]=temp;
    }
}

int main()
{
    int arr[10];
    cout<<"Enter the elements:";
    for(int i=0;i<10;i++)
    {
        cin>>arr[i];
    }
    selection_sort(arr,10);
    cout<<"Sorted Elements are:";
    for(int i=0;i<10;i++)
    {
        cout<<arr[i]<<" ";
    }

}


