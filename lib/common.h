#ifndef COMMON_H
#define COMMON_H

#include "quakedef.h"

/*
 * In the original quake a limit of 50 command lines was stated as windows
 * had the problem of dividing the command line options inside the main
 * arguments
 */
#define MAX_NUM_ARGVS 50

int32_t COM_CheckParam(int32_t, char**, char* param);

#endif
