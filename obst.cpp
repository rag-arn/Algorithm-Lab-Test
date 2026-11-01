#include<bits/stdc++.h>
using namespace std;
int n;

int range_sum(vector<int> &freq, int st, int end) {
    int sum=0;
    for (int i=st; i<=end; i++) {
        sum += freq[i];
    }
    return sum;
}

int optimal_bst(vector<int> &freq) {
    vector<vector<int>> dp (n, vector<int> (n, 0));

    for (int i=0; i<n; i++) {
        dp[i][i] = freq[i];
    }

    for (int len=2; len<=n; len++) {
        for (int i=0; i<=n-len; i++) {
            int j=i+len-1;

            dp[i][j] = INT_MAX;

            int fsum = range_sum(freq, i, j);

            for (int r=i; r<=j; r++) {
                int left = (r==i)? 0:dp[i][r-1];
                int right = (r==j)? 0:dp[r+1][j];

                dp[i][j] = min(dp[i][j], left+right+fsum);
            }
        }
    }

    return dp[0][n-1];
}

int main() {
    cin >> n;
    vector<int> keys(n), freq(n);
    for (int i=0; i<n; i++) cin >> keys[i];
    for (int i=0; i<n; i++) cin >> freq[i];

    cout << optimal_bst(freq) << endl;

    return 0;
}
