/*
 * Copyright (c) 2016 Intel Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <zephyr.h>
#include <init.h>
#include <misc/printk.h>
#include <stdio.h>
#include <sensor.h>

#define SLEEP_TIME	1000

void main(void)
{
	struct device *dev = device_get_binding("GROVE_LIGHT_SENSOR");

	if (dev == NULL) {
		printk("device not found.  aborting test.\n");
		return;
	}
	while (1) {
		struct sensor_value lux;

		sensor_sample_fetch(dev);
		sensor_channel_get(dev, SENSOR_CHAN_LIGHT, &lux);

		printf("lux: %f\n", sensor_value_to_double(&lux));

		k_sleep(SLEEP_TIME);
	}
}