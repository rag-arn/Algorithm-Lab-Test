#include<bits/stdc++.h>
using namespace std;
int n;

void merge (vector<int> &arr, int st, int mid, int end) {
    vector<int> temp;
    
    int i=st, j=mid+1;

    while (i<=mid and j<=end) {
        if (arr[i]<arr[j]) {
            temp.push_back(arr[i]);
            i++;
        }

        else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    for (int ind=i; ind<=mid; ind++) {
        temp.push_back(arr[ind]);
    }
    
    for (int ind=j; ind<=end; ind++) {
        temp.push_back(arr[ind]);
    }

    int ind2 = 0;
    for (int ind=st; ind<=end; ind++) {
        arr[ind] = temp[ind2++];
    }
}

void m_sort(vector<int> &arr, int st, int end) {
    if (st<end) {
        int mid = st+(end-st)/2;

        m_sort(arr, st, mid);
        m_sort(arr, mid+1, end);

        merge(arr, st, mid, end);
    }
}

int main() {
    cin >> n;
    vector<int> arr(n);
    for (int i=0; i<n;i++) {
        cin >> arr[i];
    }

    m_sort(arr, 0, n-1);

    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
