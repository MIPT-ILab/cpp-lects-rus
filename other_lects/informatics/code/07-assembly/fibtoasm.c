int
nth_fib(int n) {
  int fst = 0, snd = 1;

  while(--n) {
    int oldsnd = snd;
    snd = fst + snd;
    fst = oldsnd;
  }

  return snd;
}

