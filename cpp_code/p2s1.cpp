typedef struct pair 
{ 
  int x; 
  int y; 
} pair_t;

pair_t 
transpose_pair(pair_t pa)
{
  pair_t pr = {pa.y, pa.x};
  return pr;
} 

