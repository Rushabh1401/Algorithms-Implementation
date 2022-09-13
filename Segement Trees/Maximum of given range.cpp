#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

vector<int>b;

struct SegTree
{
     int N;
     vector<int> st;

     void init(int n)
     {
          N = n;
          st.resize(4 * N + 5);
     }

     void Build(int node, int L, int R)
     {
          if (L == R)
          {
               st[node] = b[L];
               return;
          }
          int M = (L + R) / 2;
          Build(node * 2 + 1, L, M);
          Build(node * 2 + 2, M + 1, R);
          st[node] = max(st[node * 2 + 1], st[node * 2 + 2]);
     }

     void Update(int node, int L, int R, int pos, int val)
     {
          if (L == R)
          {
               st[node] = val;
               return;
          }
          int M = (L + R) / 2;
          if (pos <= M)
               Update(node * 2  + 1, L, M, pos, val);
          else
               Update(node * 2 + 2, M + 1, R, pos, val);

          st[node] = max(st[node * 2 + 1], st[node * 2 + 2]);
     }

     int Query(int node, int L, int R, int i, int j)
     {
          if (j < L || i > R)
               return INT_MIN;
          if (i <= L && R <= j)
               return st[node];
          int M = (L + R) / 2;
          return max(Query(node * 2 + 1, L, M, i, j), Query(node * 2 + 2, M + 1, R, i, j));

     }

     int query(int l, int r) { return Query(0, 0, N - 1, l, r); }

     void update(int pos, int val) {
          b[pos] = val;
          Update(0, 0, N - 1, pos, val);
     }

     void build() { Build(0, 0, N - 1); }

};



int main()
{
     fastio();
     int n;
     cin >> n;
     b.resize(n);

     for (int i = 0 ; i < n ; i++) {
          cin >> b[i];
     }

     SegTree seg;
     seg.init(n);
     seg.build();

     cout << seg.query(1, 6);
}
