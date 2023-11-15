/*
 * Copyright (c) 2022 Toost Solutions
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/drivers/sensor.h>

#include "app_version.h"

#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(main, CONFIG_APP_LOG_LEVEL);

int main(void)
{
	printk("Hello Mind! Application %s\n", APP_VERSION_STR);

	while (1) {
		k_sleep(K_MSEC(1000));
	}
}

