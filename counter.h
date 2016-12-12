#ifndef COUNTER_H
#define COUNTER_H


template <class T>
class Counter
{
public:
    Counter(){count++;}
    Counter(const Counter&){ count++;}
    ~Counter(){count--;}
    static int getCount(){return count;}
private:
    static int count;
};

template<class T>
int Counter<T>::count = 0;
#endif // COUNTER_H
