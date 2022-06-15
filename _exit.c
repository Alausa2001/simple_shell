#include "main.h"

/**
 * exit_cmd - kills processes
 */

void exit_cmd(void)
{
	kill(getpid(), SIGTERM);
}
