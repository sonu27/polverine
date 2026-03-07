#ifndef CPU_TEMP_H
#define CPU_TEMP_H

#include "esp_err.h"

esp_err_t cpu_temp_init(void);
float cpu_temp_read(void);

#endif
