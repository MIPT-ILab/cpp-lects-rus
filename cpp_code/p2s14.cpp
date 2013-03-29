class TimeKeeper {
public:
  TimeKeeper() {};
  virtual ~TimeKeeper() {};
};

class SolarWatch : public TimeKeeper {/* ... some details ... */};
class SwissWatch : public TimeKeeper {/* ... some details ... */};
class AtomicClock : public TimeKeeper {/* ... some details ... */};

TimeKeeper * getTimeKeeper (double reqprec) 
{
  if (reqprec < 1.0)
    return new SolarWatch;
  if (reqprec < 10.0)
    return new SwissWatch;
  return new AtomicClock;
}

int use_time(TimeKeeper *clock)
{
  /* ... some details ... */
  return 0;
}

int main(void)
{
  TimeKeeper *ptk = getTimeKeeper(0.1);
  use_time(ptk);
  delete ptk;
}

