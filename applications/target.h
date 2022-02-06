#ifndef __TARGET_H__
#define __TARGET_H__

#include "main.h"

#define TARGET_PERIOD           100
#define TARGET_STACK_SIZE       512
#define TARGET_PRIORITY         1
#define TARGET_TICK             1

struct target
{
    rt_thread_t simulation_thread;      /**< Simulation Thread */

    rt_mailbox_t mb_gpio;               /**< GPIO mailbox */
    rt_mailbox_t mb_ping;               /**< Ping mailbox */
};
typedef struct target *target_t;

static void simulation_thread_entry(void *param);
target_t target_init(rt_mailbox_t mb_ping, rt_mailbox_t mb_gpio);
rt_err_t target_start(struct target *target);

#endif
