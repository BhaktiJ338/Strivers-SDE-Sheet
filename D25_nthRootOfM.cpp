
int multiply(int num, int cnt, int m){
  long long res = 1;

  for(int i=0; i<cnt; i++){
    res *= num;
    if(res>m) return 2;
  }
  if(res==m) return 1;
  return 0;
}

int NthRoot(int n, int m) {
  int l=1, r=m;

  while(l<=r){
    int mid = (l+r)/2;

    int val = multiply(mid, n, m);
    if(val==1) return mid;  //val=m
    else if(val==2) r = mid-1; //val>m
    else l = mid+1; //val<m
  }

  return -1;
}
