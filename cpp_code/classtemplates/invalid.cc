template <typename T> class Invalid {};
template <> class Invalid<double> {};
Invalid <double> i;
int main () {}