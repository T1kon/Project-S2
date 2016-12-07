#ifndef COUNTER_H
#define COUNTER_H


template <class T>
class Counter
{
public:
    Counter(){count++;}
    ~Counter(){count--;}
    int getCount(){return count;}
protected:
    static int count;
};

#endif // COUNTER_H
