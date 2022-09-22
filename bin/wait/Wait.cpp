#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include "Wait.h"
#include <sys/wait.h>

Wait::Wait(int argc, char **argv)
    : POSIXApplication(argc, argv)
{
    parser().setDescription("Wait for a child process to stop or terminate");
    parser().registerPositional("PID", "Process ID of child to wait for");
}

Wait::~Wait()
{
}

Wait::Result Wait::exec()
{   
    int tempPid = 0;
    tempPid = atoi(arguments().get("PID"));
    pid_t pid = (pid_t) tempPid;

    return Success;
}