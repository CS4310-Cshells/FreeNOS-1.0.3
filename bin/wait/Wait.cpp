#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include "Wait.h"

Wait::Wait(int argc, char **argv)
    : POSIXApplication(argc, argv)
{
    parser().setDescription("Wait for a PID to finish its process");
    parser().registerPositional("PID ID", "The PID to wait for");
}

Wait::~Wait()
{
}

Wait::Result Wait::exec()
{
    sleep(2);
    return Success;
}