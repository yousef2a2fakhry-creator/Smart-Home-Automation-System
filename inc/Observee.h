#ifndef OBSERVEE_H
#define OBSERVEE_H
#include <string>
#include <memory>
class Observer;
class Observee
{
private:
    
public:
    virtual void notifyAll() const;
    virtual std::string registerUser(std::shared_ptr<Observer> subscruiber);
    virtual void removeUser(std::string) ;
    virtual std::string generate_uuid() const;
    virtual ~Observee() noexcept = default;
};


#endif