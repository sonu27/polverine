/**
 * Copyright (C) Bosch Sensortec GmbH. All Rights Reserved. Confidential.
 *
 * Disclaimer
 *
 * Common:
 * Bosch Sensortec products are developed for the consumer goods industry. They may only be used
 * within the parameters of the respective valid product data sheet. Bosch Sensortec products are
 * provided with the express understanding that there is no warranty of fitness for a particular purpose.
 * They are not fit for use in life-sustaining, safety or security sensitive systems or any system or device
 * that may lead to bodily harm or property damage if the system or device malfunctions. In addition,
 * Bosch Sensortec products are not fit for use in products which interact with motor vehicle systems.
 * The resale and/or use of products are at the purchaser's own risk and his own responsibility. The
 * examination of fitness for the intended use is the sole responsibility of the Purchaser.
 *
 * The purchaser shall indemnify Bosch Sensortec from all third party claims, including any claims for
 * incidental, or consequential damages, arising from any product use not covered by the parameters of
 * the respective valid product data sheet or not approved by Bosch Sensortec and reimburse Bosch
 * Sensortec for all costs in connection with such claims.
 *
 * The purchaser must monitor the market for the purchased products, particularly with regard to
 * product safety and inform Bosch Sensortec without delay of all security relevant incidents.
 *
 * Engineering Samples are marked with an asterisk (*) or (e). Samples may vary from the valid
 * technical specifications of the product series. They are therefore not intended or fit for resale to third
 * parties or for use in end products. Their sole purpose is internal client testing. The testing of an
 * engineering sample may in no way replace the testing of a product series. Bosch Sensortec
 * assumes no liability for the use of engineering samples. By accepting the engineering samples, the
 * Purchaser agrees to indemnify Bosch Sensortec from all claims arising from the use of engineering
 * samples.
 *
 * Special:
 * This software module (hereinafter called "Software") and any information on application-sheets
 * (hereinafter called "Information") is provided free of charge for the sole purpose to support your
 * application work. The Software and Information is subject to the following terms and conditions:
 *
 * The Software is specifically designed for the exclusive use for Bosch Sensortec products by
 * personnel who have special experience and training. Do not use this Software if you do not have the
 * proper experience or training.
 *
 * This Software package is provided `` as is `` and without any expressed or implied warranties,
 * including without limitation, the implied warranties of merchantability and fitness for a particular
 * purpose.
 *
 * Bosch Sensortec and their representatives and agents deny any liability for the functional impairment
 * of this Software in terms of fitness, performance and safety. Bosch Sensortec and their
 * representatives and agents shall not be liable for any direct or indirect damages or injury, except as
 * otherwise stipulated in mandatory applicable law.
 *
 * The Information provided is believed to be accurate and reliable. Bosch Sensortec assumes no
 * responsibility for the consequences of use of such Information nor for any infringement of patents or
 * other rights of third parties which may result from its use. No license is granted by implication or
 * otherwise under any patent or patent rights of Bosch. Specifications mentioned in the Information are
 * subject to change without notice.
 *
 * It is not allowed to deliver the source code of the Software to any third party without permission of
 * Bosch Sensortec.
 *
 */

/*!
 * @file bsec_iot_example.c
 *
 * @brief
 * Example for using of BSEC library in a fixed configuration with the BME69x sensor.
 * This works by running an endless loop in the bsec_iot_loop() function.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "coines.h"
#include "bsec_selectivity.h"
#include "bsec_integration.h"


#define SID_BME69X                      UINT16_C(0x093)
#define SID_BME69X_X8                   UINT16_C(0x057)

#define _1_MIN                          UINT16_C(1000 * 60)

static uint8_t dev_addr[NUM_OF_SENS];
static uint32_t counter_ms = 0;
static bool tvoc_disable_flag = false;
static bool otf_temp = true;
uint8_t bme_cs[NUM_OF_SENS];
extern uint8_t n_sensors;
extern uint8_t *bsecInstance[NUM_OF_SENS];


static void shuttle_init();

static void coines_deinit(void);

/* BME communication methods */

static BME69X_INTF_RET_TYPE bme69x_i2c_read(uint8_t reg_addr, uint8_t *reg_data, uint32_t len, void *intf_ptr);

static BME69X_INTF_RET_TYPE bme69x_i2c_write(uint8_t reg_addr, const uint8_t *reg_data, uint32_t len, void *intf_ptr);

static BME69X_INTF_RET_TYPE bme69x_spi_read(uint8_t reg_addr, uint8_t *reg_data, uint32_t len, void *intf_ptr);

static BME69X_INTF_RET_TYPE bme69x_spi_write(uint8_t reg_addr, const uint8_t *reg_data, uint32_t len, void *intf_ptr);

static void bme69x_delay_us(uint32_t period, void *intf_ptr);

/* Callback methods */
static void bme69x_interface_init(struct bme69x_dev *bme, uint8_t intf, uint8_t sen_no);

static uint32_t state_load(uint8_t *state_buffer, uint32_t n_buffer);

static uint32_t config_load(uint8_t *config_buffer, uint32_t n_buffer);

static uint32_t get_timestamp_ms();

static void state_save(const uint8_t *state_buffer, uint32_t length);

static void output_ready(char *outputs);

static void tvoc_equivalent_calibration(void);


int main(void)
{
    bsec_version_t version;
    return_values_init ret = {BME69X_OK, BSEC_OK};
    char header[400];

    shuttle_init();
	
	ret = bsec_iot_init(SAMPLE_RATE, bme69x_interface_init, state_load, config_load);
	
	if (ret.bme69x_status != BME69X_OK) {
		printf("ERROR while initializing BME69x: %d\r\n", ret.bme69x_status);
		return ret.bme69x_status;
	}
	if (ret.bsec_status < BSEC_OK) {
		printf("\nERROR while initializing BSEC library: %d\n", ret.bsec_status);
		return ret.bsec_status;
	}
	else if (ret.bsec_status > BSEC_OK) {
		printf("\nWARNING while initializing BSEC library: %d\n", ret.bsec_status);
	}

	ret.bsec_status = bsec_get_version(bsecInstance, &version);

    printf("BSEC Version : %u.%u.%u.%u\r\n",version.major,version.minor,version.major_bugfix,version.minor_bugfix);

#if (OUTPUT_MODE == IAQ)
    sprintf(header, "Sensor_No, Time(ms), IAQ,  IAQ_accuracy, Static_IAQ, TVOC_Equivalent, TVOC_Equivalent_Accuracy, Raw_Temperature(degC), Raw_Humidity(%%rH), Comp_Temperature(degC),  Comp_Humidity(%%rH), Raw_pressure(Pa), Raw_Gas(ohms), Gas_percentage, CO2, bVOC, Stabilization_status, Run_in_status, Bsec_status\r\n");
#else
    sprintf(header, "Sensor_No, Time(ms), Class/Target_1_prediction, Class/Target_2_prediction, Class/Target_3_prediction, Class/Target_4_prediction, Prediction_accuracy_1, Prediction_accuracy_2, Prediction_accuracy_3, Prediction_accuracy_4, Raw_pressure(Pa), Raw_Temperature(degC),  Raw_Humidity(%%rH), Raw_Gas(ohm), Raw_Gas_Index(num), Bsec_status\r\n");
#endif

    printf("%s",header);

    bsec_iot_loop(state_save, get_timestamp_ms, output_ready, tvoc_equivalent_calibration);
	
    coines_deinit();

    return ret.bsec_status;
}

static void shuttle_init()
{
    struct coines_board_info board_info;
    int16_t result = coines_open_comm_intf(COINES_COMM_INTF_USB, NULL);
	
    if (result < COINES_SUCCESS)
    {
        printf("Unable to connect with Application Board\n");
        exit(result);
    }

    result = coines_get_board_info(&board_info);

    if (result == COINES_SUCCESS)
    {
        if (board_info.shuttle_id == SID_BME69X)
        {
            bme_cs[0] = COINES_MINI_SHUTTLE_PIN_2_1;
            n_sensors = 1;
            printf("BME690 1x shuttle is connected, shuttle id : 0x%x\r\n",SID_BME69X);
        }
        else if(board_info.shuttle_id == SID_BME69X_X8)
        {
            bme_cs[0] = COINES_MINI_SHUTTLE_PIN_1_4;
            bme_cs[1] = COINES_MINI_SHUTTLE_PIN_1_5;
            bme_cs[2] = COINES_MINI_SHUTTLE_PIN_1_6;
            bme_cs[3] = COINES_MINI_SHUTTLE_PIN_1_7;
            bme_cs[4] = COINES_MINI_SHUTTLE_PIN_2_5;
            bme_cs[5] = COINES_MINI_SHUTTLE_PIN_2_6;
            bme_cs[6] = COINES_MINI_SHUTTLE_PIN_2_7;
            bme_cs[7] = COINES_MINI_SHUTTLE_PIN_2_8;
            n_sensors = NUM_OF_SENS;
            printf("BME690 8x shuttle is connected, shuttle id : 0x%x\r\n",SID_BME69X_X8);
        }
        else
        {
            printf("Invalid bme69x sensor shuttle id\r\n");
            exit(result);
        }
    }

    coines_set_shuttleboard_vdd_vddio_config(0, 0);
    coines_delay_msec(100);
    coines_config_spi_bus(COINES_SPI_BUS_0, COINES_SPI_SPEED_10_MHZ, COINES_SPI_MODE0);
    coines_delay_msec(100);
    coines_set_shuttleboard_vdd_vddio_config(1800, 1800);
}

static void coines_deinit(void)
{
    fflush(stdout);

    coines_set_shuttleboard_vdd_vddio_config(0, 0);
    coines_delay_msec(1000);

    /* Coines interface reset */
    coines_soft_reset();
    coines_delay_msec(1000);
    coines_close_comm_intf(COINES_COMM_INTF_USB, NULL);
}

static BME69X_INTF_RET_TYPE bme69x_i2c_read(uint8_t reg_addr, uint8_t *reg_data, uint32_t len, void *intf_ptr)
{
    uint8_t device_addr = *(uint8_t*)intf_ptr;

    (void)intf_ptr;

    return coines_read_i2c(COINES_I2C_BUS_0, device_addr, reg_addr, reg_data, (uint16_t)len);
}

static BME69X_INTF_RET_TYPE bme69x_i2c_write(uint8_t reg_addr, const uint8_t *reg_data, uint32_t len, void *intf_ptr)
{
    uint8_t device_addr = *(uint8_t*)intf_ptr;

    (void)intf_ptr;

    return coines_write_i2c(COINES_I2C_BUS_0, device_addr, reg_addr, (uint8_t *)reg_data, (uint16_t)len);
}

static BME69X_INTF_RET_TYPE bme69x_spi_read(uint8_t reg_addr, uint8_t *reg_data, uint32_t len, void *intf_ptr)
{
    uint8_t device_addr = *(uint8_t*)intf_ptr;

    (void)intf_ptr;

    return coines_read_spi(COINES_SPI_BUS_0, device_addr, reg_addr, reg_data, (uint16_t)len);
}

static BME69X_INTF_RET_TYPE bme69x_spi_write(uint8_t reg_addr, const uint8_t *reg_data, uint32_t len, void *intf_ptr)
{
    uint8_t device_addr = *(uint8_t*)intf_ptr;

    (void)intf_ptr;

    return coines_write_spi(COINES_SPI_BUS_0, device_addr, reg_addr, (uint8_t *)reg_data, (uint16_t)len);
}

static void bme69x_delay_us(uint32_t period, void *intf_ptr)
{
    (void)intf_ptr;
    coines_delay_usec(period);
}

static void bme69x_interface_init(struct bme69x_dev *bme, uint8_t intf, uint8_t sen_no)
{
    if (bme == NULL)
        return;

    /* Bus configuration : I2C */
    if (intf == BME69X_I2C_INTF)
    {
        dev_addr[sen_no] = BME69X_I2C_ADDR_LOW;
        bme->read = bme69x_i2c_read;
        bme->write = bme69x_i2c_write;
        bme->intf = BME69X_I2C_INTF;

        /* SDO pin is made low */
        coines_set_pin_config(COINES_SHUTTLE_PIN_SDO, COINES_PIN_DIRECTION_OUT, COINES_PIN_VALUE_LOW);

        coines_config_i2c_bus(COINES_I2C_BUS_0, COINES_I2C_STANDARD_MODE);
    }
    /* Bus configuration : SPI */
    else if (intf == BME69X_SPI_INTF)
    {
        dev_addr[sen_no] = bme_cs[sen_no];
        bme->read = bme69x_spi_read;
        bme->write = bme69x_spi_write;
        bme->intf = BME69X_SPI_INTF;
    }

    bme->delay_us = bme69x_delay_us;
    bme->intf_ptr = &dev_addr[sen_no];
    bme->amb_temp = 25; /* The ambient temperature in deg C is used for defining the heater temperature */
}

static uint32_t state_load(uint8_t *state_buffer, uint32_t n_buffer)
{
    // ...
    // Load a previous library state from non-volatile memory, if available.
    //
    // Return zero if loading was unsuccessful or no state was available, 
    // otherwise return length of loaded state string.
    // ...
    return 0;
}

static uint32_t config_load(uint8_t *config_buffer, uint32_t n_buffer)
{
	memcpy(config_buffer, bsec_config_selectivity, n_buffer);
    return n_buffer;
}

static uint32_t get_timestamp_ms()
{    
    return coines_get_millis();
}

static void state_save(const uint8_t *state_buffer, uint32_t length)
{
    // ...
    // Save the string some form of non-volatile memory, if possible.
    // ...
}

static void output_ready(char *outputs)
{
    coines_set_led(COINES_LED_RED, COINES_LED_STATE_ON);
    
    printf("%s",outputs);

    coines_set_led(COINES_LED_RED, COINES_LED_STATE_OFF);
}

/**
 * @brief Function to calibrate the TVOC equivalent by enabling and disabling the baseline adaptation.
 * Note : TVOC equivalent calibration is only possilbe in LP Mode.
 */
static void tvoc_equivalent_calibration(void)
{
    if (get_sample_rate() == BSEC_SAMPLE_RATE_LP) 
    {
        if (counter_ms == 0)
        {
            set_tvoc_equivalent_baseline(true);
            tvoc_disable_flag = true;
        }
        else if ((counter_ms >= (_1_MIN * 30)) && tvoc_disable_flag)
        {
            set_tvoc_equivalent_baseline(false);
            tvoc_disable_flag = false;
        }
        counter_ms = get_timestamp_ms();
    }
    else if (otf_temp)
    {
        printf("[INFO] TVOC equivalent calibration not supported in current BSEC mode.\n");
        otf_temp = false;
    }
}