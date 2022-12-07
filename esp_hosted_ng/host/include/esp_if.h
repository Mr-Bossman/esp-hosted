// SPDX-License-Identifier: GPL-2.0-only
/*
 * Espressif Systems Wireless LAN device driver
 *
 * SPDX-FileCopyrightText: 2015-2023 Espressif Systems (Shanghai) CO LTD
 *
 */
#ifndef __ESP_IF__H_
#define __ESP_IF__H_

#include "esp.h"

struct esp_if_ops {
	int (*init)(struct esp_adapter *adapter);
	struct sk_buff* (*read)(struct esp_adapter *adapter);
	int (*write)(struct esp_adapter *adapter, struct sk_buff *skb);
	int (*deinit)(struct esp_adapter *adapter);
};

struct esp_if_params {
	uint8_t speed;
	uint32_t handshake_pin;
	uint32_t chip_select;
	uint32_t data_ready_pin;
};

int esp_init_interface_layer(struct esp_adapter *adapter, const struct esp_if_params *speed);
void esp_deinit_interface_layer(void);

#endif
