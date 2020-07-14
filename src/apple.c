#include <stdio.h>

int n;
int k;
int A[100000];

int need_bag(int m){
  int nb = 0;
  for(int i = 0; i < n; i ++){
    nb = nb + (A[i] + m - 1) / m;
  }
  return nb;
}

int p(int m){
  return need_bag(m) <= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = 1e9;
  while(ub - lb > 1) {
    int mid = (lb + ub) / 2;
    if(p(mid)){
      ub = mid;
    }
    else {
      lb = mid;
    }
  }
  printf("%d\n", ub);
  return 0;
}