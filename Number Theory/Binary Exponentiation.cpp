// a ,b, mod are max till 1e9   
// if a,mod is till 1e18 then we use binaryMultiplication
//This code works for b till 1e18 as we can store till that only in long long.
//Double can store even bigger values but for bigger number it doesn't store accurate value. There is precision errors.
//So we avoid using doubles.

int binaryExp(int a, int b, int mod)
    {
        int res = 1;
        a = a%mod;
        
        while(b>0)
        {
            if(b&1)
                res = (res*1LL*a) %mod;
            
            a = (a*1LL*a) % mod;
            b>>=1;
        }
        
        return res; 
    }
