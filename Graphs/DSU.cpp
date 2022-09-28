class dsu{
    public: 
    vector<int>p;
    vector<int>sz;
        
    void init(int N)
    {
        p.resize(N);
        for(int i=0 ; i<N ; i++)
            p[i] = i;
        
        sz.resize(N,1);
    }

    int find_parent(int x)
    {
        return p[x] == x ? x : p[x] = find_parent(p[x]);
    }

    void unite(int x, int y)
    {
        x = find_parent(x);
        y = find_parent(y);

        if(p[x]!=p[y])
        {
            if(sz[x] > sz[y])
                swap(x,y);
            
            p[x] = y;
            sz[y] += sz[x];
        }

    }

};
