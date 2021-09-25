#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

const int N = 10;

vi countingSort(vi v) {
   int arr[N];
   memset(arr, 0, N * 4);
   for(int i : v) {
      arr[i]++;
   }
   for(int i = 1; i < N; i++) {
      arr[i]+=arr[i - 1];
   }
   int n = v.size();
   vi v1(n);
   for(int i = 0; i < n; i++) {
      v1[--arr[v[i]]] = v[i];
   }
   return v1;
}

int main() {
   cin.tie(0);
   vi v = {7, 6, 5, 4, 3, 2, 1};
   v = countingSort(v);
   for(int i : v) {
      cout << i << ' ';
   }
   cin.get();
}
