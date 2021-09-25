#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

vi merge(vi v, int a, int b) {
   vi v1;
   v1.resize(b - a + 1);
   copy(v.begin() + a, v.begin() + b + 1, v1.begin());
   return v1;
} 

vi mergeSort(vi v) {
   int k = v.size();
   if(k == 1) {
      return v;
   }
   vi v1 = mergeSort(merge(v, 0, k/2 - 1));
   vi v2 = mergeSort(merge(v, k/2, k-1));
   vi v3;
   v3.resize(k);
   int i1=0, i2=0;
   for(int i = 0; i < k; i++) {
      if((v1[i1] < v2[i2] && i1 != k/2)||i2 == k - k/2) {
         v3[i] = v1[i1];
         i1++;
      }
      else {
         v3[i] = v2[i2];
         i2++;
      }
   }
   return v3;
}

int main() {
   cin.tie(0);
   vi v = {7,6,5,4,3,2,1,0};
   v = mergeSort(v);
   for(int i : v) {
      cout << i << ' ';
   }
   cin.get();
}
