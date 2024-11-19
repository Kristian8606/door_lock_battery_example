/*
   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/

#include <esp_log.h>
#include <stdlib.h>
#include <string.h>

#include <esp_matter.h>
#include "bsp/esp-bsp.h"

#include <app_priv.h>

static const char *TAG = "app_driver";

using namespace chip::app::Clusters;
using namespace esp_matter;

extern uint16_t door_lock_endpoint_id;

esp_err_t app_driver_set_defaults(uint16_t endpoint_id)
{
	 esp_err_t err = ESP_OK;
    void *priv_data = endpoint::get_priv_data(endpoint_id);
   // led_indicator_handle_t handle = (led_indicator_handle_t)priv_data;
    node_t *node = node::get();
    endpoint_t *endpoint = endpoint::get(node, endpoint_id);
    cluster_t *cluster = NULL;
    attribute_t *attribute = NULL;
    esp_matter_attr_val_t val = esp_matter_invalid(NULL);

    /* Setting brightness */
    cluster = cluster::get(endpoint, DoorLock::Id);
    attribute = attribute::get(cluster, DoorLock::Attributes::LockState::Id);
    attribute::get_val(attribute, &val);
    val.val.u8 = 1;
    attribute::set_val(attribute, &val);
     int value = val.val.u8;
 //    gpio_hold_dis(GPIO_NUM); 
  //   gpio_set_level(GPIO_NUM, false);
  //  gpio_hold_en(GPIO_NUM); 
                printf("SET_DEFAULT LockState %d\n",value);
   // err |= app_driver_light_set_brightness(handle, &val);
    return err;

}


esp_err_t app_driver_attribute_update(app_driver_handle_t driver_handle, uint16_t endpoint_id, uint32_t cluster_id,
                                      uint32_t attribute_id, esp_matter_attr_val_t *val)
{
    esp_err_t err = ESP_OK;
  //  printf("PRE_UPDATE\n");
    
    return err;
}


