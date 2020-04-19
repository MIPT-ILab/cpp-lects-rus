void abort();
int printf(const char *s, ...);

void check_cmdline(int n) {
#if defined(ENABLE_CHECKS)
  if (n > 2) {
    printf("%s\n", "Error");
    abort();
  }
#endif
}

int main(int argc, char **argv) {
  check_cmdline(argc);
  printf("%s\n", "Hello");
}
