# Example code in C to demonstrate IAQ and Selectivity outputs in BME690 with BSEC3 library
 * Example for using of BSEC library in a fixed configuration with the BME690 sensor.
 * This works by running an endless loop in the bsec_iot_loop() function.
 * This example code has been tested using the BST Application Board 3.1 along with the BME690 Shuttle Boards.

# Prerequisites
 1. Download and install the mingw32 from "https://jmeubank.github.io/tdm-gcc/download/" (tdm64-gcc-10.3.0-2.exe), then add it to system environment variables.
 2. Download and install the GNU Arm Embedded Toolchain from "https://developer.arm.com/downloads/-/gnu-rm" (gcc-arm-none-eabi-10.3-2021.10-win32.exe), then add it to system environment variables.
 3. Download the coines sdk from "https://www.bosch-sensortec.com/software-tools/tools/coines/" website and install it in C drive, final coines installation 
	folder looks like this "C:/COINES_SDK/v2.9.1/". This is important because the makefile searches for coines in this location.
 4. The coines installation path in the Makefile has been updated as per the current website version of the coines sdk (v2.9.1).
	For different versions of the coines sdk, please update the coines sdk path to "COINES_INSTALL_PATH" in the Makefile.

# Hardware test details
 * By default all 8 sensors are supported and this can be modified in file "bsec_integration.h" macro "NUM_OF_SENS".
 * The communication mode to the sensor is via SPI in this illustration.

# Code compilation
 * The bsec_iot_example uses the configuration kept in "src/config/" subdirectory. By default the example code is configured to "bme690_sel_18v_300s_28d" settings.
   Depending on the use case, please change to the desired configuration by replacing "bsec_selectivity.c" and "bsec_selectivity.h" in "src/config/" folder.
 * Open the cmd prompt in project folder then run "mingw32-make TARGET=MCU_APP31"

# Code flash
 * Open the cmd prompt in project folder then run "mingw32-make TARGET=MCU_APP31 download"

# Switching between the output modes in BSEC
 * At any given time only one mode is supported in BSEC.
 * Change the macro "OUTPUT_MODE" to either "CLASSIFICATION" or "REGRESSION" or "IAQ" based on the requirement in "bsec_integration.h" file.
 * The default "OUTPUT_MODE" in the code is "IAQ".
 * Ensure to copy the appropriate config files based on the output mode.
 * IAQ output is supported in both classification and regression config file.
 * "SAMPLE_RATE" depends on the "OUTPUT_MODE",
 	* If the "OUTPUT_MODE"  value is "CLASSIFICATION" (or) "REGRESSION", the "SAMPLE_RATE" assigned is "BSEC_SAMPLE_RATE_SCAN" (default).
 	* If the "OUTPUT_MODE" value is "IAQ", the "SAMPLE_RATE" assigned is "BSEC_SAMPLE_RATE_ULP" (default).
	* For the "OUTPUT_MODE" as "IAQ" the other supported "SAMPLE_RATE" is "BSEC_SAMPLE_RATE_CONT" (or) "BSEC_SAMPLE_RATE_LP".