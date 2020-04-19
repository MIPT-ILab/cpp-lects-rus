int printf(const char *, ...);

static const int c = CHECK_LEVEL;

#if defined(CHECK_LEVEL)
#undef CHECK_LEVEL
#endif

int main() {
  int CHECK_LEVEL = c;
  printf("Check level: %d\n", CHECK_LEVEL);
}

