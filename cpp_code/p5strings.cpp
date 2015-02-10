#include <string>
#include <cstdio>

void 
replace_all (std::string& str, 
             const std::string& from, 
             const std::string& to) 
{
  size_t start_pos = 0;

  if(from.empty())
    return;

  while((start_pos = str.find(from, start_pos)) != std::string::npos) 
    {
      str.replace(start_pos, from.length(), to);
      start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
    }
}

int
main (void)
{
  std::string str = "Hello, $username, how are you doing, $username?";
  std::string from = "$username";
  std::string to = "Eric, the Bloody Axe";

  replace_all (str, from, to);

  std::fprintf (stderr, "%s\n", str.c_str()); 

  return 0;
}

