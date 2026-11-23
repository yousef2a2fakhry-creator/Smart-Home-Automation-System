#include "../inc/CommandInvoker.h"

void CommandInvoker::execute(std::shared_ptr<Command> cmd)
{
    if (!cmd)
        return;
    cmd->execute();
    history.push(cmd);
}

void CommandInvoker::enqueue(std::shared_ptr<Command> cmd)
{
    if (cmd)
        pending.push(cmd);
}

void CommandInvoker::runQueued()
{
    while (!pending.empty())
    {
        execute(pending.front());
        pending.pop();
    }
}

void CommandInvoker::undoLast()
{
    if (history.empty())
        return;
    history.top()->undo();
    history.pop();
}
