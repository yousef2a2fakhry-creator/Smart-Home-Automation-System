#include "../inc/IDGenerator.h"
#include <random>
#include <sstream>
#include <iomanip>
std::string IDGenerator::generate_uuid() 
{
    static std::mt19937_64 gen{std::random_device{}()};
    std::uniform_int_distribution<unsigned long long> dist;
    std::ostringstream ss;
    ss << std::hex << std::setfill('0')
       << std::setw(16) << dist(gen) << std::setw(16) << dist(gen);
    return ss.str();
}