#include "lib/quakedef.h"

/*
 * Check if @param exists inside the array of arguments @largv.
 *
 * Return:
 * - succcess: index inside the array where the parameter was found
 * - fail: 0
 */
int32_t COM_CheckParam(int32_t com_argc, char* com_argv[], char* param) {

    for (int32_t i = 1; i < com_argc; ++i) {
        if (!Q_strcmp(com_argv[i], param)) {
            return i;
        }
    }
    return 0;
}
