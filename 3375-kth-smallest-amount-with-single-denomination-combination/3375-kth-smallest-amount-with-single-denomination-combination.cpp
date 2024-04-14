#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    void print(auto& S){
        for(auto x: S) cout<<x<<", ";
        cout<<endl;
    }

    vector<int> dp;// storing the LCM's
    //inclusion-exclusion principle
    long long f(long long x, unsigned bitMask){
        long long cnt=0;
        for(unsigned i=1; i<=bitMask; i++)
            cnt+=(popcount(i)&1)?(x/dp[i]):(-x/dp[i]);
        return cnt;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        //reducing of redundant of coins combinations
        sort(coins.rbegin(), coins.rend());
        if (coins.back()==1) return k;
        bitset<26> valid_coin=0;
        for (int c: coins){
            valid_coin[c]=1;
            for(int r=2*c; r<26; r+=c) valid_coin[r]=0;
        }
        coins.clear();
        for(int i=1; i<=25; i++) 
            if(valid_coin[i]) coins.push_back(i);
    //    print(coins);
        //new setting for coins up to here

        int sz=coins.size();
        // trivial case but an edge case
        if (sz==1) return (long long)coins[0]*k;

        unsigned bitMask=(1<<sz)-1;
        dp.assign(1<<sz, -1);

        // Loop through all possible subsets of coins
        for (int bMask=1; bMask<=bitMask; bMask++) {
            long long lcm=1;
            for (int i=0; i<sz; i++) {
                if (bMask & (1 << i)) {
                    // lcm(x,y)=(x*y)/gcd(x,y)
                    lcm=lcm*coins[i]/gcd(lcm, coins[i]); //compute LCM
                }
            }
            dp[bMask]=lcm;
        }
    //    cout<<"dp:"; print(dp);

        //Shrink the searching range
        long long l=k+1, r=(long long)coins[0]*k, mid;
    //    cout<<"r="<<r<<", f(r)="<<f(r, bitMask)<<endl;
        while (l<r) {
            mid=l+(r-l)/2;
            if (f(mid, bitMask)<k)
                l=mid+1;
            else
                r=mid;
        }
        return l;
    }
};


auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();