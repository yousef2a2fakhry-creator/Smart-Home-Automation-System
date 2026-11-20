#ifndef CLOCK_H
#define CLOCK_H


class Clock
{
public:
    static int getHour();  
    static bool isNight(); 

    Clock() = delete; 
};

#endif