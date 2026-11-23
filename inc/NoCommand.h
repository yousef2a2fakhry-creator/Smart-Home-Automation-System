#ifndef NO_COMMAND_H
#define NO_COMMAND_H

#include "Command.h"

class NoCommand : public Command
{
public:
    ~NoCommand() noexcept override = default;

    void execute() override;
    void undo() override;
};

#endif
