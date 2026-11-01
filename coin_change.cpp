#include<bits/stdc++.h>
using namespace std;
int n, sum;

void coin_no (vector<int> &coin, int sum) {
    vector<int> dp(sum+1, INT_MAX);

    dp[0] = 0;

    for (int j=1; j<=sum; j++) {
        for (int i=0; i<coin.size(); i++) {
            if (coin[i]<=j and dp[j-coin[i]]!=INT_MAX) {
                dp[j] = min(dp[j], dp[j-coin[i]]+1);
            }
        }
    }
    if (dp[sum]==INT_MAX) cout << "Not possible" << endl;
    else
        cout << dp[sum] << endl;
}

int main() {
    int n;
    cin >> n;

    vector<int> coin(n);
    for (int i=0; i<n; i++) {
        cin >> coin[i];
    }

    int sum;
    cin >> sum;

    coin_no(coin, sum);
}
