#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <unistd.h>
#include "Renice.h"
#include <ProcessClient.h>

Renice::Renice(int argc, char **argv)
    : POSIXApplication(argc, argv)
{
    parser().setDescription("Change the priority level of a process");
    parser().registerPositional("PRIORITY", "priority level to set the process to");
    parser().registerPositional("PID", "Process ID whose priority to change");
    parser().registerFlag('n', "priority", "If set, change the priority of the process");
}

Renice::~Renice()
{
}

Renice::Result Renice::exec()
{
    ProcessClient process;
    pid_t pid = atoi(arguments().get("PID"));
    PriorityLevel newPriority = atoi((arguments().get("PRIORITY")));
    process.setPriority(pid, newPriority);
}