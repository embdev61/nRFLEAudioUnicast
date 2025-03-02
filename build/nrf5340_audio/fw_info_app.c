/*
 * Copyright (c) 2018 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

#include "fw_info_app.h"

#include <zephyr/kernel.h>
#include <stdio.h>
#include <zephyr/logging/log_ctrl.h>
#include "channel_assignment.h"
#include "ncs_version.h"

#include "macros_common.h"

#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(fw_info, CONFIG_FW_INFO_LOG_LEVEL);

static const char COMPILE_DATE[] = "Sun Mar 02 21:33:10 2025";
/* NOTE: The string below is used by the Nordic CI system */
static const char NRF5340_CORE[] = "nRF5340 Audio nRF5340 Audio DK cpuapp";

int fw_info_app_print(void)
{
	/* NOTE: The string below is used by the Nordic CI system */
	LOG_INF(COLOR_GREEN "\r\n\t %s \
			    \r\n\t NCS base version: %s \
			    \r\n\t Cmake run : %s" COLOR_RESET,
		NRF5340_CORE, NCS_VERSION_STRING, COMPILE_DATE);

#if (CONFIG_DEBUG)
	int ret;

	LOG_INF("------- DEBUG BUILD -------");

#if (CONFIG_AUDIO_DEV == HEADSET)
	enum audio_channel channel;

	channel_assignment_get(&channel);
	if (channel == AUDIO_CH_L) {
		ret = log_set_tag(CH_L_TAG);
		if (ret) {
			return ret;
		}
		/* NOTE: The string below is used by the Nordic CI system */
		LOG_INF(COLOR_CYAN "HEADSET left device" COLOR_RESET);
	} else if (channel == AUDIO_CH_R) {
		ret = log_set_tag(CH_R_TAG);
		if (ret) {
			return ret;
		}
		/* NOTE: The string below is used by the Nordic CI system */
		LOG_INF(COLOR_CYAN "HEADSET right device" COLOR_RESET);
	} else {
		__ASSERT(false, "Unknown channel");
	}

#elif CONFIG_AUDIO_DEV == GATEWAY
	ret = log_set_tag(GW_TAG);
	if (ret) {
		return ret;
	}
	LOG_INF(COLOR_CYAN "Compiled for GATEWAY device" COLOR_RESET);
#endif /* (CONFIG_AUDIO_DEV == HEADSET) */
#endif /* (CONFIG_DEBUG) */

	return 0;
}
