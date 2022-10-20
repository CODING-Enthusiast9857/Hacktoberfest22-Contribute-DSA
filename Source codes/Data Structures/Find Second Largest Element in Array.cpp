#include <iostream>
using namespace std;
#include<climits>
int findSecondLargest(int *input, int n)
{
    if(n<=1){
        return INT_MIN;
    }
    int Max = INT_MIN, SecondMax = INT_MIN;
    for(int i = 0; i < n; i++){
        if(input[i]>Max){
            SecondMax = Max;
            Max = input[i];
        }
        else if(input[i] > SecondMax && input[i]!=Max){
            SecondMax = input[i];
        }
    }
	return SecondMax;
    
}

int main()
{
		int size;
		cout<<"Enter no. of elements : ";
		cin >> size;
		int *input = new int[size];

		cout<<"Enter elements : ";
		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cout << "Second Largest: " << findSecondLargest(input, size) << endl;

		delete[] input;
  
	return 0;
}
