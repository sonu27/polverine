COINES_INSTALL_PATH ?= C:/COINES_SDK/v2.9.1/

EXAMPLE_FILE ?= bsec_iot_example.c

EXAMPLE_CODE_SRC = ../../src

C_SRCS += bsec_integration.c
C_SRCS += $(EXAMPLE_CODE_SRC)/bme69x/bme69x.c
C_SRCS += $(EXAMPLE_CODE_SRC)/config/bsec_selectivity.c

INCLUDEPATHS += $(EXAMPLE_CODE_SRC)/bme69x
INCLUDEPATHS += $(EXAMPLE_CODE_SRC)/config
INCLUDEPATHS += $(EXAMPLE_CODE_SRC)/inc

# Additional paths to look for library files
LIBPATHS += $(EXAMPLE_CODE_SRC)/cortex-m4/fpv4-sp-d16-hard

# Additional static/shared libraries
LIBS += algobsec

LOCATION?=FLASH
TARGET?=MCU_APP31

include $(COINES_INSTALL_PATH)/coines.mk