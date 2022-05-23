vector<int> repeatedNumber(const vector<int> &A) {

    int xor1 = 0;
    int n = A.size();

    for(int i=0 ; i<n ; i++)
    xor1^=A[i];

    for(int i=1 ; i<=n ; i++)
    xor1^=i;
     
    //This is very important!
    int set_bit_no = xor1 & ~(xor1 - 1);

    int bas1 =0, bas2 =0;

    for(int i=0 ; i<n ; i++)
    {
        if(A[i] & set_bit_no)
        bas1^=A[i];

        else
        bas2^=A[i];
    }

    for(int i=1 ; i<=n ; i++)
    {
        if(i & set_bit_no)
        bas1^=i;

        else
        bas2^=i;
    }
    vector<int>ans;

    for(int i=0 ; i<n ; i++)
    {
        if(A[i] == bas1)
        {
            return {bas1,bas2};
        }
        
    }

    return {bas2,bas1};
}
