/* new and delete */
#include <cstdlib>
#include <cstdio>
#include <cassert>
#include <new>

using namespace std;

class Widget
{
  private:
    int m_i;
  public:
    Widget(int a_i): m_i(a_i * a_i) {}
    int get_state() const  { return m_i; }
    ~Widget() {}
};

Widget *
test_malloced(int initializer)
{
  Widget *wbuf = (Widget *) malloc(sizeof(Widget));
  Widget *w = new (wbuf) Widget(initializer);
  return w;
}

int 
main(void)
{
  Widget *w = test_malloced(5);
  assert(w->get_state() == 25);
  w->~Widget();
  free(w);
  return 0;
}

