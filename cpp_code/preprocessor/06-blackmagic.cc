struct command {
   char *name;
   void (*function) (void);
};

#define COMMAND(NAME)  { #NAME, NAME ## _command }
     
struct command commands[] =
{
  COMMAND (quit),
  COMMAND (help),
  /* ..... */
};

