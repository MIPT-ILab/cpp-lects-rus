struct pair_t 
{ 
  int x; 
  int y;
  pair_t transpose_pair(void); 
};

pair_t 
pair_t::transpose_pair(void)
{
  pair_t pr = {this->y, this->x};
  return pr;
} 

