int numberOf1Bits(int n) {
  int res = 0;
  while (n != 0) {
    n -= (n & -n);
    res++;
  }
  return res;
}