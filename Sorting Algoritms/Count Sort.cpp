#include <bits/stdc++.h>
using namespace std;

vector<int> count_sort(vector<int>arr, int min, int max)
{
    int n = arr.size();
    int size = max-min+1;
    vector<int>freq(size);
    vector<int>output;

    for(int i=0 ; i<n ; i++)
    {
        freq[arr[i]-min]++;
    }

    for(int i=0 ; i<size ; i++)
    {
        if(freq[i] == 0)
        continue;

        int curr = i+min;

        while(freq[i]--)
           output.push_back(curr);
    }
    return output;
}

int main() {

    vector<int>arr = {4,5,3,6,7,7,8,8,9};
    vector<int>output = count_sort(arr,3,9);

    for(int i=0 ; i<output.size() ; i++)
    cout<<output[i]<<" ";
}
