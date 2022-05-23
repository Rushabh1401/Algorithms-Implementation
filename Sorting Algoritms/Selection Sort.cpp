#include <bits/stdc++.h>
using namespace std;

//Simply select min

//Logic : Select min element from next index to end 
// Swap that element with the element at curr index

//No extra array is required
//Input array is modified, TC : O(n*n)

void selection_sort(vector<int>nums)
{
    int n = nums.size();

    for(int i=0 ; i<n ; i++)
    {
        int min_ele_index = i;

        for(int j=i+1 ; j<n ; j++)
        {
            if(nums[j] < nums[min_ele_index])
                min_ele_index = j;
        }

        swap(nums[i], nums[min_ele_index]) ;
    }

    for(int i=0 ; i<n ; i++)
    cout<<nums[i]<<" ";
}

int main() {

    vector<int>nums = {4,5,3,6,7,7,8,8,9};

    selection_sort(nums);
}
