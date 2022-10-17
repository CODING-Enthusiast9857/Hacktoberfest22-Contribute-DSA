// C++ program for Linear Search
// Time Complexity: O(N)
// Auxiliary Space: O(1)

#include <iostream>
using namespace std;
 
int linearSearch(int array[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (array[i] == x)
        {
            return i;
        }
            
    }
        
    return -1;
}
 
// Driver's code
int main()
{

    //Taking Size of Array from user
    cout<<"Enter size of array :\n";
    int n;
    cin>>n;

    // Taking Array elements from user
    cout<<"\nEnter array elements :\n";
    int array[n];
    for(int i=0;i<n;i++)
    {
        cin>>array[i];
    }
    
    // Taking the element from the user to search

    int x;
    cout<<"\nEnter the Element to be searched in the array :\n";
    cin>>x;
 
    // Linear Search Function call
    int found = linearSearch(array, n, x);
    
    if(found==-1)
    {
        cout << "\nElement is not present in array\n";
    }
    else
    {
        cout << "\nElement is present at index \n" << found;
    }

    return 0;
    
}