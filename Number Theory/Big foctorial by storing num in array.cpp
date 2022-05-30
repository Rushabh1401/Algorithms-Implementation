#include <bits/stdc++.h>
using namespace std;

//Here number is stored in reverse order in array
//so ans is also in reverse order.
// for eg . 1332 is {2,3,3,1};


//Here a is big number
// n is size of array till the ans is stored.

void multiply(vector<int>&a, int &n, int no)
{
    int carry = 0;

    for(int i=0 ; i<n ; i++)
    {
        int product = a[i]*no + carry;
        a[i] = product % 10 ;
        carry = product/10;
    }

    while(carry)
    {
        a[n++] = carry%10;
        carry/=10;
    }
}

void big_factorial(int num)
{
    vector<int>a(1000,0);
    a[0] = 1;
    int n =1;

    for(int i=2 ; i<=num ; i++)
        multiply(a,n,i);

    for(int i = n-1 ; i>=0 ; i--)
        cout<<a[i];
    
}

int main() {
    big_factorial(100); //Calculating 100 factorial
}
