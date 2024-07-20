// 2d prefix sum
for (int i = 1; i <= N; i++)
{
    for (int j = 1; j <= N; j++)
    {
        prefix[i][j] = forest[i][j] + prefix[i - 1][j] +
                       prefix[i][j - 1] - prefix[i - 1][j - 1];
    }
}

for (int q = 0; q < Q; q++)
{
  int x1, x2, y1, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  cout << prefix[x2][y2] - prefix[x1 - 1][y2] -prefix[x2][y1 - 1] +prefix[x1 - 1][y1 - 1]<< '\n';
}


//  numberOfDivisors  1e18
ll numberOfDivisors(ll n)
{
    int primes[]={2,3,5,7,11,13,17,19};
    ll num=1,ans=1;
    for (int it:primes)
    {
        int c=0;
        while(n%it==0)
        {
            n/=it;
            c++;
        }
        ans*=c+1;
        num*=it;
    }
    int all=0;
    for(int i=1;i<num;i++)
    {
        bool can=1;
        for (int it:primes)
        {
            if(i%it==0)
            {
                can=0;
            }
        }
        if(can)
        {
            ll o=i;
            for (;o*o<n;o+=num)
            {
                if(n%o==0)
                {
                    all += 2;
                }
            }
            if (o*o==n)
            {
                all++;
            }
        }
    }
    return ans*all;
}
// //////////////
struct coordinateCopmression{
private:
    vector<ll>init;
    void compress(vector<ll>&v)
    {
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
    }
public:
    coordinateCopmression(vector<ll>&v)
    {
        init=v;
        compress(init);
    }
    int index(ll val)
    {
        return lower_bound(init.begin(),init.end(),val)-init.begin();
    }
    ll initVal(int idx)
    {
        return init[idx];
    }
};
