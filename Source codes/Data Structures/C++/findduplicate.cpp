#include <iostream>
#include <vector>
#include <algorithm >
using namespace std;

int findDuplicate(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int k=1;
    for (int i=0;i<nums.size();i++){
        if(nums[i]==nums[i+1]){
            nums.erase(nums.begin()+i+1);
            k++;
        }
    }
    return k;
}

int main(){
    vector<int> nums={3,0,1,1,2,3,2};
    cout<<findDuplicate(nums)<<endl;
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
}
