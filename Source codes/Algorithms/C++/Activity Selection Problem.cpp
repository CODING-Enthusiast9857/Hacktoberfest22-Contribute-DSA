// There are n activities with their start and finish times. Select the maximum number of activities that can be performed by a single person, assuming that a person
// can only work on a single activity at a time.

// Algorithm:
// - Sort the activities according to their finishing time
// - Select the first activity from sorted array
// - Do the following for remaining activities, if start time is greater than or equal to the finish time of previously selected activity then select this activity and
//   print this.

// Program:
#include <bits/stdc++.h>
using namespace std;

// activity has a start time, finish time
struct activity
{
    int start, finish;
};

// comparator for sorting
bool activityCompare(activity s1, activity s2)
{
    return (s1.finish < s2.finish);
}

void activitySelection(activity arr[], int n)
{
    // Sort jobs according to finish time
    sort(arr, arr + n, activityCompare);

    cout << "Following activities are selected :\n";

    // The first activity always gets selected
    int i = 0;
    cout << "(" << arr[i].start << ", " << arr[i].finish << ")";

    for (int j = 1; j < n; j++)
    {
        // If this activity has start time greater than or equal to the finish time of previously selected activity, then select it
        if (arr[j].start >= arr[i].finish)
        {
            cout << ", (" << arr[j].start << ", " << arr[j].finish << ")";
            i = j;
        }
    }
}

int main()
{
    activity arr[] = {{5, 9}, {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}};
    int n = sizeof(arr) / sizeof(arr[0]);

    activitySelection(arr, n);
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)