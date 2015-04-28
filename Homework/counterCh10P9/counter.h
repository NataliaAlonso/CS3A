#ifndef COUNTER_H
#define COUNTER_H

class counter
{
  public:
    // Create a counter object that can count up to 9999
    counter(int x);
    // Default counter object that can count up to 9999
    counter();
    // Set the counter's number to 0
    void reset();
    // Increments the units digit by 1
    void incr1(int x);
    // Increments the tens digit by 1
    void incr10(int x);
    // Increments the hundreds digit by 1
    void incr100(int x);
    // Increments the thousands digit by 1
    void incr1000(int x);
    // Detects overflow; needs to check after each increment
    bool overflow();
    // Display current total
    void display();
    int getOverflow();
    void getFunction(char s, int x);
    void getFunction(char s);

  private:
    int counterMax;
    int total;
    int overFlow;

};

#endif // COUNTER_H
