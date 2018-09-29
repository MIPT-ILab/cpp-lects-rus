#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct sieve_t {
  unsigned size;
  unsigned char *sieve;
};

struct sieve_t 
init_sieve (unsigned n) 
{
  assert(n > 2);
  unsigned char *sieve = calloc(n, sizeof(unsigned char));
  struct sieve_t res = { n, sieve };
  assert ((n > 1) && (sieve != NULL));
  unsigned r = (unsigned) sqrt (n) + 1;
  res.sieve[0] = res.sieve[1] = 1;

  // TODO: your code here
  return res;
}

void 
free_sieve(struct sieve_t *s) 
{
  free(s->sieve);
  s->sieve = 0;
  s->size = 0;
}

int
is_prime (struct sieve_t s, unsigned n) {
  assert (n < s.size);
  return (s.sieve[n] == 1) ? 0 : 1;
}

int
main ()
{
  struct sieve_t s = init_sieve(100);
  assert (is_prime(s, 96) == 0);
  assert (is_prime(s, 97) == 1);
  free_sieve(&s);
}

