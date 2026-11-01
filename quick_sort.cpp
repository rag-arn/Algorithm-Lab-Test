#include<bits/stdc++.h>
using namespace std;
int n;

int partition (vector<int> &arr, int st, int end) {
    int pivot = arr[end];
    int i = st;

    for (int j=st; j<=end; j++) {
        if (arr[j]<pivot) {
            swap (arr[i], arr[j]);
            i++;
        } 
    }
    swap(arr[i], pivot);
    return i;
}

void q_sort (vector<int> &arr, int st, int end) {
    if (st<end) {
        int p = partition(arr, st, end);
        q_sort(arr, st, p-1);
        q_sort(arr, p+1, end);
    }
}

int main() {
    cin >> n;
    vector<int> arr(n);
    for (int i=0; i<n;i++) {
        cin >> arr[i];
    }

    q_sort(arr, 0, n-1);

    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
