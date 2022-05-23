#include <bits/stdc++.h>
using namespace std;

vector<int>nums;

void merge(int low,int high, int mid)
{
    int size_l = mid-low+1;
    int size_r = high-mid;

    //Taking arrays is must //You cant modify original directly
    //It will change the comparisons then.
    
    vector<int>arr_l(size_l);
    vector<int>arr_r(size_r);

    for(int i=low ; i<=mid ; i++)
        arr_l[i-low] = nums[i];

    for(int i=mid+1 ; i<=high; i++)
        arr_r[i-mid-1] = nums[i];

    int left = 0;
    int right = 0;
    int i; //for traversing

    for(i = low; i<= high && left < size_l && right < size_r ; i++)
    {
        if(arr_l[left] <= arr_r[right])
            nums[i] = arr_l[left++];

        else
            nums[i] = arr_r[right++];
    }

    while(left < size_l)
    nums[i++] = arr_l[left++];

    while(right < size_r)
    nums[i++] = arr_r[right++];

}

void merge_sort(int low, int high)
{
    if(low==high)
    return;  //Because single element is sorted

    int mid = low + (high-low)/2 ;

    merge_sort(low,mid);
    merge_sort(mid+1,high);

    merge(low,high,mid);
}

int main() {
    nums = {4,2,3,1,5,0,9};

    merge_sort(0,nums.size()-1);

    for(int i=0 ; i<nums.size() ; i++)
        cout<<nums[i]<<" ";
}
