
#include <bits/stdc++.h>
using namespace std;

int n;

int crossing_sum(vector<int> &arr, int st, int mid, int end) {
    int left_sum = INT_MIN;
    int right_sum = INT_MIN;

    int sum = 0;

    for (int i = mid; i >= st; i--) {
        sum += arr[i];
        left_sum = max(left_sum, sum);
    }

    sum = 0;

    for (int i = mid + 1; i <= end; i++) {
        sum += arr[i];
        right_sum = max(right_sum, sum);
    }

    return left_sum + right_sum;
}

int max_sum(vector<int> &arr, int st, int end) {

    if (st == end) {
        return arr[st];
    }

    int mid = st + (end - st) / 2;

    int lss = max_sum(arr, st, mid);
    int rss = max_sum(arr, mid + 1, end);
    int css = crossing_sum(arr, st, mid, end);

    return max(lss, max(rss, css));
}

int main() {
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (n <= 0) return 0;

    int ans = max_sum(arr, 0, n - 1);

    cout << ans << endl;
}
