#include <assert.h>
#include <stdio.h>
#include <string.h>

const char *strstr_(const char *haystack, const char *needle) {
  // TODO: write code
}

int main() {
  const char *needle = "ab";
  const char *src = "abracadabra";
  const char *pos1, *pos2, *pos3; 

  pos1 = strstr_(src, needle); 
  assert(pos1 != NULL);
  pos2 = strstr_(pos1 + 2, needle);
  assert(pos2 != NULL);
  pos3 = strstr_(pos2 + 2, needle);
  assert(pos3 == NULL);
}

