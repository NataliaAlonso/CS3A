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
    void incr1();
    // Increments the tens digit by 1
    void incr10();
    // Increments the hundreds digit by 1
    void incr100();
    // Increments the thousands digit by 1
    void incr1000();
    // Detects overflow; needs to check after each increment
    bool overflow();

    private:
    int counterMax;
    int total;

}


#endif // COUNTER_H
