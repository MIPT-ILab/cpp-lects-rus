int printf(const char *, ...);

#if !defined(CHECK_LEVEL)
  #define CHECK_LEVEL 0
#endif

int main() {
  printf("Check level: %d\n", CHECK_LEVEL);
}

