#include <bits/stdc++.h>
using namespace std;

//Implimentation with O(log n);
//We will convert n in binary form.
// 5 :   1     0    1
//     5*5*5  5*5   5   //If there is set bit we multiply with ans.


int power_optimised(int a, int n)
{
    int ans = 1;

    while(n>0)
    {
        int last_bit = n&1;

        if(last_bit)
        ans*=a;

        a*=a;
        n>>=1;
    }

    return ans;
}

int main() {
    cout<<power_optimised(3,5);
}
