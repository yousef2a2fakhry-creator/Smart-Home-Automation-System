#include <ctime>
#include "../inc/Clock.h"

int Clock::getHour()
{
    std::time_t now = std::time(nullptr);  
    std::tm *local = std::localtime(&now); 
    return local->tm_hour;                 
}

bool Clock::isNight()
{
    int hour = getHour();
    return hour >= 20 || hour < 6; 
}