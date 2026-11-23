#ifndef COMMAND_INVOKER_H
#define COMMAND_INVOKER_H

#include <memory>
#include <queue>
#include <stack>
#include "Command.h"

class CommandInvoker
{
private:
    std::stack<std::shared_ptr<Command>> history; 
    std::queue<std::shared_ptr<Command>> pending; 

public:
    void execute(std::shared_ptr<Command> cmd); 
    void enqueue(std::shared_ptr<Command> cmd); 
    void runQueued();                           
    void undoLast();                          
    bool canUndo() const { return !history.empty(); }
};

#endif
