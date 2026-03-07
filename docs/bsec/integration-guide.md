## Bosch Sensortec BSEC Integration Guide

# **Integration Guide** Bosch Software Environmental Cluster (BSEC)

Modifications reserved | Data subject to change without notice | Document number: BST-BME-Integration-Guide-AN011-321000 Date 2025-04-29
c Bosch Sensortec GmbH 2025. All rights reserved, also regarding any disposal, exploitation, reproduction, editing, distribution, as
well as in the event of applications for industrial property rights.



1


## Bosch Sensortec BSEC Integration Guide

# **Contents**

**1** **BSEC Integration Guideline** **4**
1.1 Overview of BME Family Sensors . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 4
1.2 The Environmental Fusion Library BSEC . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 5
1.2.1 BSEC Library Solutions . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 5
1.2.2 BSEC Configuration Settings . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 6
1.2.3 Key Features . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 8
1.2.4 Supported Virtual Sensor Output Signals . . . . . . . . . . . . . . . . . . . . . . . . . . . . 9
1.3 Requirements for Integration . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 10
1.3.1 Hardware . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 10
1.3.2 Software Framework . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 10
1.3.3 Physical Input Sensor Signals . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 11
1.3.4 Build the Solution . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 11


**2** **How to integrate BSEC library** **12**
2.1 Prerequisites . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 12
2.2 Integration of BSEC Interfaces into BME6xy Sensors . . . . . . . . . . . . . . . . . . . . . . . . . . 12
2.2.1 Example code for BSEC Interfaces . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 15
2.3 Using BSEC 3.x for BME680/688 Sensor Variants . . . . . . . . . . . . . . . . . . . . . . . . . . . 15


**3** **FAQ** **16**
3.1 No Output From bsec_do_steps() . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 16
3.2 IAQ output does not change or accuracy remains 0 . . . . . . . . . . . . . . . . . . . . . . . . . . . 16
3.3 Error Codes and Corrective Measures . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 16
3.3.1 Errors Returned by bsec_do_steps() . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 16
3.3.2 Errors Returned by bsec_update_subscription() . . . . . . . . . . . . . . . . . . . . . . . . 19
3.3.3 Errors Returned by bsec_set_configuration() / bsec_set_state() . . . . . . . . . . . . . . . . 23
3.3.4 Errors Returned by bsec_sensor_control() . . . . . . . . . . . . . . . . . . . . . . . . . . . . 24
3.4 Upgrading from BME688/BME680 sensors to BME690 sensors . . . . . . . . . . . . . . . . . . . . 25


**4** **Module Documentation** **26**
4.1 BSEC Enumerations and Definitions . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 26
4.1.1 Enumerations . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 26
4.1.2 Defines . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 33
4.2 BSEC Interfaces . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 37
4.2.1 Interface Functions . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 37


**5** **Data Structure Documentation** **45**
5.1 bsec_bme_settings_t Struct Reference . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 45
5.1.1 Detailed Description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 45
5.1.2 Field Documentation . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 46
5.2 bsec_input_t Struct Reference . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 47
5.2.1 Detailed Description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 48
5.2.2 Field Documentation . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 48



Modifications reserved | Data subject to change without notice | Document number: BST-BME-Integration-Guide-AN011-321000 Date 2025-04-29
c Bosch Sensortec GmbH 2025. All rights reserved, also regarding any disposal, exploitation, reproduction, editing, distribution, as
well as in the event of applications for industrial property rights.



2


## Bosch Sensortec BSEC Integration Guide

5.3.2 Field Documentation . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 49
5.4 bsec_sensor_configuration_t Struct Reference . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 51
5.4.1 Detailed Description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 51
5.4.2 Field Documentation . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 51
5.5 bsec_version_t Struct Reference . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 52
5.5.1 Detailed Description . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 52
5.5.2 Field Documentation . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 52



Modifications reserved | Data subject to change without notice | Document number: BST-BME-Integration-Guide-AN011-321000 Date 2025-04-29
c Bosch Sensortec GmbH 2025. All rights reserved, also regarding any disposal, exploitation, reproduction, editing, distribution, as
well as in the event of applications for industrial property rights.



3


## Bosch Sensortec BSEC Integration Guide

# **1 BSEC Integration Guideline**

## **1.1 Overview of BME Family Sensors**

The BME sensor family has been designed to enable pressure, temperature, humidity and gas measurements. The
BME690 is the latest addition to the sensor family. It offers improved pressure and humidity sensor performance
compared to its predecessors - BME688 and BME680. Additionally, its robust hardware assembly makes it ideal
for high condensation applications. The sensors can be operated in different modes specified in supplied header
files. In general, higher data rate corresponds to higher power consumption.


This section will provide information about the integrated sensors which are used by the BSEC library and also a
brief overview of them.


**Temperature Sensor**


In order to guarantee fast response times, BME690/BME688 is expected to be mounted at a location in the device
that enables good air and temperature exchange. The integrated temperature sensor has been optimized for very
low noise and high resolution. It is primarily used for estimating ambient temperature and for temperature compensation of the other sensors present. The temperature measurement accuracy is specified in the corresponding
data sheet of the used hardware.


**Pressure Sensor**


The pressure sensor within BME690/BME688 is an absolute barometric pressure sensor featuring exceptionally
high accuracy and resolution at very low noise. The pressure measurement accuracy is specified in the
corresponding data sheet.


**Relative Humidity Sensor**


The humidity sensor within BME690/BME688 measures relative humidity from 0 to 100 percent across a
temperature range from -40 degrees centigrade to +85 degrees centigrade. The humidity measurement accuracy
is specified in the corresponding data sheet.


**Gas Sensor**


The gas sensor within BME690/BME688 can detect Volatile Organic Compounds (VOCs), Volatile Sulfer
Compounds(VSCs) and other gases such as carbon monoxide and hydrogen.


BME690 has adapted all features of BME688, including the gas scanner function. In standard configuration,
the presence of VSCs is being detected as an indicator for e.g. bacteria growth. And the gas scanner can be
customized with respect to sensitivity, selectivity, data rate and power consumption as well. The BME AI-Studio
tool enables customers to train the BME690/BME688 gas scanner on their specific application, like in home
appliances, IoT products or Smart Home.



Modifications reserved | Data subject to change without notice | Document number: BST-BME-Integration-Guide-AN011-321000 Date 2025-04-29
c Bosch Sensortec GmbH 2025. All rights reserved, also regarding any disposal, exploitation, reproduction, editing, distribution, as
well as in the event of applications for industrial property rights.



4


## Bosch Sensortec BSEC Integration Guide **1.2 The Environmental Fusion Library BSEC**

**General Description**


BSEC fusion library has been conceptualized to provide higher-level signal processing and fusion for the BME
sensor. The library receives compensated sensor values from the sensor API. It processes the BME sensor
signals (in combination with the additional optional device sensors) to provide the requested sensor outputs.
Inputs to BSEC signals are commonly called signals from _physical sensors_ . For the outputs of BSEC, several
denominations are coined for the name of the sensors providing the respective signal: composite sensors,
synthetic sensors, software-based sensors and virtual sensors. For BSEC, only the denomination _virtual sensors_
shall be used.


Prior to probing into BSEC Library, the entire BSEC system can be understood as a combination of the below
mentioned system architecture components


- BME690/BME688 sensor (pressure, temperature, humidity and gas)


- Device with BME690/BME688 integrated


- Sensor driver API - Provide software interfaces to get compensated raw data from sensor via SPI/I2C interface


- BSEC fusion library - Provides fused sensor outputs and AI interpreter for classifying and quantifying gas
related use cases


- BME AI Studio - AI toolchain to develop, verify and deploy custom classification and regression AI models for
classifying and quantifying gas related use cases


- _Optional_ : Additional device sensors (i.e., temperature of other heat sources in the device or position sensors)


**Advantages**


- Hardware and software co-design for optimal performance


- Complete software fusion solution


- Eliminates need for developing fusion software in customer's side


- Robust virtual sensor outputs optimized for the application


**1.2.1** **BSEC Library Solutions**


Offered BSEC solutions are

|Solution|Included features|
|---|---|
|SELECTIVITY|Gas classiﬁcation, gas quantiﬁcation with regression technique, Index for Air Quality (IAQ),<br>raw signals|
|IAQ|Index for Air Quality (IAQ), raw signals|



The SELECTIVITY(IAQ+SEL) solution is an all in one feature set of BSEC library, which enables the user to
subscribe for any one of the three BSEC primary features(i.e. IAQ, Classification or Regression). The IAQ solution
on the other hand is a memory efficient variant of BSEC for use cases that does not require the classification and
regression features of the library.


Based on customer requests it is technically possible to further customize BSEC to meet specific demands.



Modifications reserved | Data subject to change without notice | Document number: BST-BME-Integration-Guide-AN011-321000 Date 2025-04-29
c Bosch Sensortec GmbH 2025. All rights reserved, also regarding any disposal, exploitation, reproduction, editing, distribution, as
well as in the event of applications for industrial property rights.



5


## Bosch Sensortec BSEC Integration Guide

**1.2.2** **BSEC Configuration Settings**


BSEC offers the flexibility to configure the solution based on customer specific needs. The configuration can be
loaded to BSEC via bsec_set_configuration(). The following settings can be configured


- Supply voltage of the sensor. The supply voltage influences the self-heating of the sensor.


 - 1.8V or 3.3V


- Different power modes for the gas sensor and corresponding data rates are supported by the software solution:


 - Gas Scan mode (scan) is designed for interactive applications where gas classification or regression
estimates of the target gases are needed for the use cases. BSEC algorithm has been qualified for
identifying H2S gas with classification model and estimating the intensity in parts per million (ppm) of the H2S
gas with regression model. The standard heater profile has an update rate of 10.8s and can be finetuned for
use-cases using BME AI Studio.


 - Ultra low power (ULP) mode is designed for battery-powered and/or frequency-coupled devices over
extended periods of time. This mode features an update rate of 300 seconds and an average current
consumption of _<_ 0.05 mA


 - Low power (LP) mode that is designed for interactive applications where the air quality is tracked and
observed at a higher update rate of 3 seconds with a current consumption of _<_ 0.5 mA


 - Continuous(CONT) mode provides an update rate of 1 Hz and shall only be used short-term for use cases
that incorporate very fast events or stimulus. This mode has an average current consumption of _<_ 12 mA


- The history BSEC considers for the automatic background calibration of the IAQ is in days. That means
changes in this time period will influence the IAQ value.


 - 4days, means BSEC will consider the last 4 days of operation for the automatic background calibration.


 - 28days, means BSEC will consider the last 28 days of operation for the automatic background calibration.


**Configurations for BSEC library**


For Scan mode, the configurations finetuned to the intended application need to be generated from the BME
AI Studio. For accurate LP and ULP outputs it is important to use the right configuration file. Please select the
most appropriate configuration file from the specific folders provided in the release. The naming convention is as
follows: _<_ sensor variant _>_ _ _<_ features _>_ _ _<_ supply voltage _>_ _ _<_ sampling rate _>_ _ _<_ calibration days _>_ .


- _<_ sensor variant _>_ - Specifies the sensors compatible with the configuration.


 - 'bme690', 'bme688' or 'bme680'


- _<_ features _>_ - Indicates the features supported by the configuration.


 - 'sel' - Supports IAQ outputs in LP/ULP mode or classification outputs in scan mode.


 - 'reg' - Supports IAQ outputs in LP/ULP mode or regression outputs in scan mode


 - 'iaq' - Support only IAQ outputs in LP/ULP mode


- _<_ supply voltage _>_ - Denotes the supply voltages to which the configuration is finetuned.


 - '18v' - To be used when the supply volatge is 1.8v.


 - '33v' - To be used when the supply volatge is 3.3v


- _<_ sampling rate _>_ - The sampling rate supported by the configuration.


 - '3s' - For low power mode operations at 3 seconds sampling rate



Modifications reserved | Data subject to change without notice | Document number: BST-BME-Integration-Guide-AN011-321000 Date 2025-04-29
c Bosch Sensortec GmbH 2025. All rights reserved, also regarding any disposal, exploitation, reproduction, editing, distribution, as
well as in the event of applications for industrial property rights.



6


## Bosch Sensortec BSEC Integration Guide


 - '300s' - For ultra low power mode operations at 300 seconds sampling rate


 - '4d' - 4 day calibration period.


 - '28d' - 28 day calibration period.


For example, 'bme690_iaq_18v_3s_28d' configuration file is recommended when the users want to use the IAQ
Solution of BSEC with BME690 sensor hardware with a supply voltage of 1.8v, while subscribing for LP mode
outputs with 28 day calibration time.


For BME690 and BME688 sensors the following configuration sets are available for SELECTIVITY Solution of
BSEC library(where bme6XY corresponds to BME690 or BME688):
















|Configuration|Supply voltage|Max data rate<br>(IAQ)|Calibration<br>time (IAQ)|Gas estimate<br>output class|Regression es-<br>timate target|
|---|---|---|---|---|---|
|bme6XY_sel_←-_<br>_33v_3s_28d|3.3 V|3s|28 days|H2S/NonH2S|-|
|bme6XY_sel_←-_<br>_33v_3s_4d|3.3 V|3s|4 days|H2S/NonH2S|-|
|bme6XY_sel_←-_<br>_18v_3s_28d|1.8V|3s|28 days|H2S/NonH2S|-|
|bme6XY_sel_←-_<br>_18v_3s_4d|1.8V|3s|4 days|H2S/NonH2S|-|
|bme6XY_sel_←-_<br>_33v_300s←-_<br>28d|3.3 V|300s|28 days|H2S/NonH2S|-|
|bme6XY_sel_←-_<br>_33v_300s_4d|3.3 V|300s|4 days|H2S/NonH2S|-|
|bme6XY_sel_←-_<br>_18v_300s←-_<br>28d|1.8V|300s|28 days|H2S/NonH2S|-|
|bme6XY_sel_←-_<br>_18v_300s_4d|1.8V|300s|4 days|H2S/NonH2S|-|
|bme6XY_reg_←-_<br>_18v_300s_4d|1.8V|300s|4 days|-|H2S (ppm)|



For BME690, BME688 and BME680 sensors the following configuration sets are available for IAQ Solution of
BSEC library(where bme6XY corresponds to BME690 or BME688 or BME680):


|Configuration|Supply voltage|Max data rate (IAQ)|Calibration time (IAQ)|
|---|---|---|---|
|bme6XY_iaq_33v_3s_28d|3.3 V|3s|28 days|
|bme6XY_iaq_33v_3s_4d|3.3 V|3s|4 days|
|bme6XY_iaq_18v_3s_28d|1.8V|3s|28 days|
|bme6XY_iaq_18v_3s_4d|1.8V|3s|4 days|
|bme6XY_iaq_33v_300s_28d|3.3 V|300s|28 days|
|bme6XY_iaq_33v_300s_4d|3.3 V|300s|4 days|
|bme6XY_iaq_18v_300s_28d|1.8V|300s|28 days|
|bme6XY_iaq_18v_300s_4d|1.8V|300s|4 days|



Modifications reserved | Data subject to change without notice | Document number: BST-BME-Integration-Guide-AN011-321000 Date 2025-04-29
c Bosch Sensortec GmbH 2025. All rights reserved, also regarding any disposal, exploitation, reproduction, editing, distribution, as
well as in the event of applications for industrial property rights.



7


## Bosch Sensortec BSEC Integration Guide

Note:


no external configuration file is used can be 'bme690_iaq_18v_300s_4d' and 'bme690_sel_18v_300s_4d'
respectively.


- It is mandatory to provide configuration setting for getting outputs in scan mode, else output will be all zeros.


- Users can update the settings for gas classification and regression estimation using BME AI-Studio. For a
BME AI-Studio generated configuration file, the default settings for all outputs other than gas classification and
regression estimate outputs are based on 'bme688_sel_18v_300s_28d' file settings.


- BSEC support a maximum of 4 classes for gas classification outputs. However above mentioned configuration
settings is defined for only two classes.


- BSEC support a maximum of 4 target gases for regression estimate outputs as well, and the above mentioned
configuration settings is defined for only one target gas.


**1.2.3** **Key Features**


- Precise calculation of sensor heat compensated temperature outside the device


- Precise calculation of sensor heat compensated relative humidity outside the device


- Precise calculation of atmospheric pressure outside the device


- Precise calculation of Index for Air Quality(IAQ) level outside the device


- Provide the probability of the detected target gas(eg: H2S, nonH2S) class


- Provide the quantification of the target gas by regression method (eg.: 0.1ppm H2S, 0.5ppm H2S etc.)


- A conditioning mechanism with LP and ULP modes to avoid prolonged power-on stabilization time.


**Selectivity Mode with BME690/BME688**


- Generally the idea of the gas scanner is to collect as much information of the present gas mixture. The
intelligent AI model of BSEC then establishes a correlation between the collected gas data and the ground
truth information provided by the user. Subsequently, when the sensor encounters the same gas composition
again, BSEC efficiently identifies and associates it with the reference used during training.


- For the state of the art classification feature, BSEC requires the label/class names as reference, such as
'Gas'-'No-Gas', 'Low'-'Moderate'-'High ' etc.


- On the other hand, the regression feature of BSEC utilizes the numerical relationship of the gas environment
as a reference to provide a quantitative estimation similar to the reference value. This feature leverages
continuous sensor data instead of a range of data, making it suitable for applications in controlled environments
like laboratories, server rooms etc., where external gases and other environmental changes are limited.


- At a time, only one of the feature can be enabled: gas estimation or regression estimation in scan mode. Both
are not available together.


- Under this mode of operation, the heater is operated under multiple temperature points and a maximum of 10
heater points is supported by the library.


- The Selectivity feature of BSEC library is a platform that could be customized as per different usecases. The
BME AI Studio tool is used to configure the BME sensor and train BSEC AI Model as per the requirement of
the user.



Modifications reserved | Data subject to change without notice | Document number: BST-BME-Integration-Guide-AN011-321000 Date 2025-04-29
c Bosch Sensortec GmbH 2025. All rights reserved, also regarding any disposal, exploitation, reproduction, editing, distribution, as
well as in the event of applications for industrial property rights.



8


## Bosch Sensortec BSEC Integration Guide

**1.2.4** **Supported Virtual Sensor Output Signals**


BSEC provides the output signals given in the table below. All signals from virtual sensor outputs are timecontinuous signals sampled in equidistant time intervals.


















|Signal name|Min|Max|Unit|Acc 1|Supporting Modes 2|
|---|---|---|---|---|---|
|BSEC_OUTPUT_GAS_ESTIMATE_1|0.00|1|probability 3|yes|scan|
|BSEC_OUTPUT_GAS_ESTIMATE_2|0.00|1|probability 3|yes|scan|
|BSEC_OUTPUT_GAS_ESTIMATE_3|0.00|1|probability 3|yes|scan|
|BSEC_OUTPUT_GAS_ESTIMATE_4|0.00|1|probability 3|yes|scan|
|BSEC_OUTPUT_REGRESSION_E_←-_<br>STIMATE_1|0|-|-|yes|scan|
|BSEC_OUTPUT_REGRESSION_E_←-_<br>STIMATE_2|0|-|-|yes|scan|
|BSEC_OUTPUT_REGRESSION_E_←-_<br>STIMATE_3|0|-|-|yes|scan|
|BSEC_OUTPUT_REGRESSION_E_←-_<br>STIMATE_4|0|-|-|yes|scan|
|BSEC_OUTPUT_RAW_PRESSURE|30000|110000|Pa|no|ULP,LP,CONT,scan|
|BSEC_OUTPUT_RAW_TEMPERAT_←-_<br>URE|-40|85|deg C|no|ULP,LP,CONT,scan|
|BSEC_OUTPUT_RAW_HUMIDITY|0|100|%|no|ULP,LP,CONT,scan|
|BSEC_OUTPUT_RAW_GAS|170|103000000|Ohm|no|ULP,LP,CONT,scan|
|BSEC_OUTPUT_RAW_GAS_INDEX|0|9||no|scan|
|BSEC_OUTPUT_IAQ|0|500||yes|ULP,LP,CONT|
|BSEC_OUTPUT_STATIC_IAQ|0|-||yes|ULP,LP,CONT|
|BSEC_OUTPUT_CO2_EQUIVALENT|400|-|ppm|yes|ULP,LP,CONT|
|BSEC_OUTPUT_COMPENSATED←-_<br>GAS|2.23|8.01|ohm|no|ULP,LP,CONT|
|BSEC_OUTPUT_BREATH_VOC_E_←-_<br>QUIVALENT|0|10000|ppm|yes|ULP,LP,CONT|
|BSEC_OUTPUT_SENSOR_HEAT←-_<br>COMPENSATED_TEMPERATURE|-45|85|deg C|no|ULP,LP,CONT|
|BSEC_OUTPUT_SENSOR_HEAT←-_<br>COMPENSATED_HUMIDITY|0|100|%|no|ULP,LP,CONT|
|BSEC_OUTPUT_STABILIZATION←-_<br>STATUS|False|True||no|ULP,LP,CONT|
|BSEC_OUTPUT_RUN_IN_STATUS|False|True||no|ULP,LP,CONT|
|BSEC_OUTPUT_GAS_PERCENTA_←-_<br>GE|0|100|%|yes|ULP,LP,CONT|
|BSEC_OUTPUT_TVOC_EQUIVALE_←-_<br>NT|0|-|ppb|yes|LP|



To achieve best gas sensor performance, the user shall not switch between different modes during the lifetime of
a given sensor.



Modifications reserved | Data subject to change without notice | Document number: BST-BME-Integration-Guide-AN011-321000 Date 2025-04-29
c Bosch Sensortec GmbH 2025. All rights reserved, also regarding any disposal, exploitation, reproduction, editing, distribution, as
well as in the event of applications for industrial property rights.



9


## Bosch Sensortec BSEC Integration Guide

1 Accuracy status available (see bsec_output_t::accuracy).


performed in the background if the sensor is exposed to clean or polluted air for approximately 30 minutes each.

2 The sample rate of ULP, LP, CONT and scan mode are 1/300Hz, 1/3Hz, 1Hz and 1/18Hz respectively.

3 Probability denotes the range 0.00-1

## **1.3 Requirements for Integration**


**1.3.1** **Hardware**


BSEC was specifically designed to work together with Bosch environmental sensor of the BME6xy family. No
other sensors are supported. To ensure a consistent performance, the sensors shall be configured by BSEC itself
by the use of the bsec_sensor_control() interface.


**1.3.2** **Software Framework**


The framework must provide the sample rates requested by the user for the virtual sensors to BSEC via bsec_ _←�_
update_subscription(), e.g., using an application on the end-user graphical interface like an Android application.
BSEC internally configures itself according to the requested output sample rates. The framework must then use
bsec_sensor_control() periodically to configure the BME6xy family sensor. After every call to bsec_sensor_ _←�_
control(), the next call to bsec_sensor_control() should be scheduled by the framework as specified in the returned
sensor settings structure.


Figure 1.1: BSEC Overview


_∗_ Refer Configurations for BSEC library for modes and configurations supported by the sensors.


Typical durations for the "Sleep until measurement is finished" are 0.100 seconds for LP mode, 1 second for ULP
mode, 0.9 seconds for CONT mode and 0.190 seconds for scan mode. Typical durations for the "Sleep until next
time bsec_sensor_control() asked to be called" are 2.9 seconds for LP mode, 299 seconds for ULP mode, 0.1



Modifications reserved | Data subject to change without notice | Document number: BST-BME-Integration-Guide-AN011-321000 Date 2025-04-29
c Bosch Sensortec GmbH 2025. All rights reserved, also regarding any disposal, exploitation, reproduction, editing, distribution, as
well as in the event of applications for industrial property rights.



10


## Bosch Sensortec BSEC Integration Guide

duration is the multiplication of total profile duration and number of OFF scan cycle. Sleep duration of standard
heater profile (Heater Profile #354 with 5/10 duty cycle) is 107.8 seconds.


For each input data, an exact time stamp shall be provided synchronized to each other when they belong to
the same instant in time, i.e., they are "aligned". The processing function requires at least one input signal.In
selectivity mode, more than 1 data could be read from sensor using 3 member FIFO, which could be passed with
same timestamp but with different BSEC_INPUT_PROFILE_PART updated.


**1.3.3** **Physical Input Sensor Signals**


BSEC is designed to be used exclusively together with sensors of the BME6xy family, BME690/BME688/BME680.


Moreover, ambient temperature and humidity estimation may require additional inputs from the host system to
compensate for self-heating effects caused by the operation of the host device. This may include information
such as supply voltage, charging status or display status.


**1.3.4** **Build the Solution**


BSEC is delivered as a pre-compiled static library to be linked against the host integration code. The library
includes the following header files which need to be included along with BSEC library package.



|Header file|Description|
|---|---|
|bsec←-_<br>datatypes.h|Data types and deﬁnes used by interface functions|
|bsec_interface.h|Declaration of BSEC interface functions|


Modifications reserved | Data subject to change without notice | Document number: BST-BME-Integration-Guide-AN011-321000 Date 2025-04-29
c Bosch Sensortec GmbH 2025. All rights reserved, also regarding any disposal, exploitation, reproduction, editing, distribution, as
well as in the event of applications for industrial property rights.



11


## Bosch Sensortec BSEC Integration Guide

# **2 How to integrate BSEC library**

This section describes how you can integrate BSEC library into your own environment and prerequisites for its
integration into frameworks on supported platforms. Furthermore, a brief explanation of sequence of API calls
with example code is also provided.

## **2.1 Prerequisites**


First of all, you require a BME sensor that is connected to a microcontroller (MCU). The MCU will be used to
control the operation of the sensor and to process the sensor signals. Of course, you will also need a development
environment for the MCU of your choice. Key software tools for BME sensors are listed below
|Software components|Type|Function|
|---|---|---|
|BME6xy senor API|C code|Provide software interfaces to get compensated raw data from<br>sensor via SPI/I2C interface|
|BSEC|C static library|Provides fused sensor outputs and AI interpreter for classifying and<br>quantifying gas related use cases|
|BME AI Studio|PC Aplication|AI toolchain to develop, verify and deploy custom classiﬁcation and<br>regression AI models for classifying and quantifying gas related<br>use case.|


## **2.2 Integration of BSEC Interfaces into BME6xy Sensors**


Integration of BSEC library into BME6xy sensors requires following the below mentioned steps

















|Steps|Function|APIs to be called|
|---|---|---|
|Initialization of BME6xy sensor|Initialization of sensor|BME690: bme69x_init()<br>Refer` B`ME69x-senor-API<br>BME68x: bme68x_init()<br>Refer` B`ME68x-senor-API|
|Initialization of the BSEC library|Initialization of library<br>Update<br>conﬁguration<br>settings<br>(op-<br>tional)<br>Restore state of library (optional)|bsec_init()<br>bsec_set_conﬁguration()<br>bsec_set_state()|
|Subscribe ouputs|Enable library outputs with speciﬁed<br>mode|bsec_update_subscription()|
|Signal processing with BSEC library|Retrieve BME690 sensor instructions<br>Main signal processing function|bsec_sensor_control()<br>bsec_do_steps()|
|Retrieval of BSEC library state on<br>power cycle|Retrieve the current internal library<br>state (optional)|bsec_get_state()|



Modifications reserved | Data subject to change without notice | Document number: BST-BME-Integration-Guide-AN011-321000 Date 2025-04-29
c Bosch Sensortec GmbH 2025. All rights reserved, also regarding any disposal, exploitation, reproduction, editing, distribution, as
well as in the event of applications for industrial property rights.



12


## Bosch Sensortec BSEC Integration Guide

**BSEC Interface Sequence**


For reliable operation of BSEC software, the following sequence need to be followed.


**Initialization of BME6xy sensors and BSEC instances**


The primary step for any application is initialzing the BME sensors and BSEC software. As BSEC supports
multi-interface feature by default, one or more BME6xy sensors of same sensor variant could be integrated to a
single application code. For each sensor, seperate BSEC instance need to be initialzied as well. The maximum
number of instances is limited only by the memory of the MCU used.


Figure 2.1: Initialization Sequence Diagram



Modifications reserved | Data subject to change without notice | Document number: BST-BME-Integration-Guide-AN011-321000 Date 2025-04-29
c Bosch Sensortec GmbH 2025. All rights reserved, also regarding any disposal, exploitation, reproduction, editing, distribution, as
well as in the event of applications for industrial property rights.



13


## Bosch Sensortec BSEC Integration Guide

**BSEC processing**


As per the application and configuration loaded, the BME690 sensor data need to be fed to BSEC at defined
sample rates for getting the subscribed outputs from the software.


Figure 2.2: BSEC Processing Sequence Diagram


Note: Please refer to bsec_interface.h for detailed description, interface definitions and sample usage of abovementioned APIs



Modifications reserved | Data subject to change without notice | Document number: BST-BME-Integration-Guide-AN011-321000 Date 2025-04-29
c Bosch Sensortec GmbH 2025. All rights reserved, also regarding any disposal, exploitation, reproduction, editing, distribution, as
well as in the event of applications for industrial property rights.



14


## Bosch Sensortec BSEC Integration Guide

**2.2.1** **Example code for BSEC Interfaces**


For easy integration and demo purpose, BSEC comes with example code illustrating its features. Please refer
the "examples\BSEC_Integration_Examples\README.md" for prerequisites and instructions for using those
examples in Bosch APP boards.








|Example code|Description|Source|
|---|---|---|
|bsec_iot←-_<br>example.c|Reference example code for using the B_←-_<br>SEC library in a custom setup|BSEC 3.x Package from` B`ME690 Software|


## **2.3 Using BSEC 3.x for BME680/688 Sensor Variants**

The BSEC 3.x package includes example code in C, named IOT_Example_Code, which is compatible with the
BME690 sensor shuttles on the `A` [pplication Board 3.1.](https://www.bosch-sensortec.com/software-tools/tools/application-board-3-1/) If you would like to use BSEC 3.x with older sensor variants,
please refer to the older IOT_Example_Code available with `B` [SEC 2.x and make a few changes.](https://www.bosch-sensortec.com/software-tools/software/bme688-software/)


Changes in BSEC 3.x Interface


- bsec_interface.h by default supports multiple instances. Users can now define one or more instances.


- BSEC API calls are now standardized, and the multi-instance extensions have been removed from the API
names (e.g., bsec_init_m() is now bsec_init()).


Note: The standard interfaces of BSEC 2.x are no more supported. Please refer to bsec_interface.h for detailed
description, interface definitions and sample usage of all the APIs



Modifications reserved | Data subject to change without notice | Document number: BST-BME-Integration-Guide-AN011-321000 Date 2025-04-29
c Bosch Sensortec GmbH 2025. All rights reserved, also regarding any disposal, exploitation, reproduction, editing, distribution, as
well as in the event of applications for industrial property rights.



15


## Bosch Sensortec BSEC Integration Guide

# **3 FAQ**

## **3.1 No Output From bsec_do_steps()**

Possible reasons:


- The virtual sensor was not enabled via bsec_update_subscription()


- The input signals required for that virtual sensor were not provided to bsec_do_steps()


- The timestamps passed to bsec_do_steps() are duplicated or are not in nanosecond resolution

## **3.2 IAQ output does not change or accuracy remains 0**


Possible reason:


- Timing of gas measurements is not within 6.25% of the target values. For example, when running the sensor
in low-power mode the intended sample period is 3 s. In this case the difference between two consecutive
measurements must not exceed 106.25% of 3 s which is 3.1875 s. When integrating BSEC, it is crucial to
strictly follow the timing between measurements as returned by bsec_sensor_control() in the bsec_sensor_ _←�_
settings_t::next_call field.


Correction method:


- Ensure accurate timestamps with ns resolution, especially avoid overflows of the timer or issues with 64-bit
arrithmetic


- Ensure that the bsec_sensor_control() and bsec_do_steps() loop is correctly implemented and the bsec_ _←�_
sensor_settings_t::next_call field is used to determine the frequency between measurements.

## **3.3 Error Codes and Corrective Measures**


This chapter will give possible possible correction methods in order to fix the issues mentioned below. An overview
of the error codes is given in bsec_library_return_t.


**3.3.1** **Errors Returned by bsec_do_steps()**


**3.3.1.1** **BSEC_E_DOSTEPS_INVALIDINPUT**


Possible reasons:


- General description: BSEC_E_DOSTEPS_INVALIDINPUT


- The sensor id of the input (physical) sensor passed to bsec_do_steps() is not in valid range or not valid for the
requested output (virtual) sensor.



Modifications reserved | Data subject to change without notice | Document number: BST-BME-Integration-Guide-AN011-321000 Date 2025-04-29
c Bosch Sensortec GmbH 2025. All rights reserved, also regarding any disposal, exploitation, reproduction, editing, distribution, as
well as in the event of applications for industrial property rights.



16


## Bosch Sensortec BSEC Integration Guide

E.g:

```
  inputs[0].sensor_id = 100;
  inputs[0].signal = 25;
  inputs[0].time_stamp= ts;
  n_inputs = 3;
  status = bsec_do_steps(inputs, n_inputs, outputs, &n_outputs);

```

Correction methods:


- The sensor_id field in the inputs structure passed to bsec_do_steps() should be one among the input (physical)
sensors ids returned from bsec_update_subscription() stored in required_sensor_settings array.


- The sensor_id field in the inputs structure passed to bsec_do_steps() should be in the range of bsec_physical _←�_
_sensor_t enum.


- n_inputs should be equal to the number of inputs passed to bsec_do_steps(),i.e. size of inputs structure array.


**3.3.1.2** **BSEC_E_DOSTEPS_VALUELIMITS**


Possible reasons:


- General description: BSEC_E_DOSTEPS_VALUELIMITS


- The value of the input (physical) sensor signal passed to bsec_do_steps() is not in the valid range.


E.g:

```
  inputs[0].sensor_id = BSEC_INPUT_TEMPERATURE;
  inputs[0].signal = 250;
  inputs[0].time_stamp= ts;
  n_inputs = 1;
  status = bsec_do_steps(inputs, n_inputs, outputs, &n_outputs);

```

Correction methods:


- The value of signal field in the inputs structure passed to bsec_do_steps() should be in a valid range. The
allowed input value range for the sensors is listed below.


 - TEMPERATURE (-40 to 85)


 - HUMIDITY (0 to 100)


 - PRESSURE (300 to 110000)


 - GASRESISTOR (170 to 103000000)


 - PROFILE_PART (0 to 9)


 - Other Sensors (-3.4028e+38 to +3.4028e+38)



Modifications reserved | Data subject to change without notice | Document number: BST-BME-Integration-Guide-AN011-321000 Date 2025-04-29
c Bosch Sensortec GmbH 2025. All rights reserved, also regarding any disposal, exploitation, reproduction, editing, distribution, as
well as in the event of applications for industrial property rights.



17


## Bosch Sensortec BSEC Integration Guide

**3.3.1.3** **BSEC_E_DOSTEPS_DUPLICATEINPUT**


Possible reasons:


- General description: BSEC_E_DOSTEPS_DUPLICATEINPUT


- Duplicate input (physical) sensor ids are passed to bsec_do_steps().


E.g:

```
  inputs[0].sensor_id = BSEC_INPUT_TEMPERATURE;
  inputs[0].signal = 25;
  inputs[0].time_stamp= ts;
  inputs[1].sensor_id = BSEC_INPUT_TEMPERATURE;
  inputs[1].signal = 30;
  inputs[1].time_stamp= ts;
  n_inputs = 2;
  status = bsec_do_steps(inputs, n_inputs, outputs, &n_outputs);

```

Correction methods:


- Each input (physical) sensor id passed to bsec_do_steps() should be unique.


**3.3.1.4** **BSEC_I_DOSTEPS_NOOUTPUTSRETURNABLE**


Possible reasons:


- General description: BSEC_I_DOSTEPS_NOOUTPUTSRETURNABLE


- Some virtual sensors are requested, but no memory is allocated to hold the returned output values corresponding to these virtual sensors from bsec_do_steps().


E.g:

```
  n_outputs=0; /*Requested number of virtual sensor is 5*/
  status = bsec_do_steps(inputs, n_inputs, outputs, &n_outputs);

```

Correction methods:


- n_outputs should be assigned the value equal to the maximum number of virtual sensors defined in bsec_ _←�_
virtual_sensor_t enum.


**3.3.1.5** **BSEC_W_DOSTEPS_EXCESSOUTPUTS**


Possible reasons:


- General description: BSEC_W_DOSTEPS_EXCESSOUTPUTS


- Some virtual sensors are requested, but not enough memory is allocated to hold the returned output values
corresponding to these virtual sensors from bsec_do_steps().


E.g:

```
  n_outputs = 2 ; /*Requested number of virtual sensor is 5*/
  status=bsec_do_steps(inputs, n_inputs, outputs, &n_outputs);

```

Correction methods:


- n_outputs should be assigned the value equal to the maximum number of virtual sensors defined in bsec_ _←�_
virtual_sensor_t enum.



Modifications reserved | Data subject to change without notice | Document number: BST-BME-Integration-Guide-AN011-321000 Date 2025-04-29
c Bosch Sensortec GmbH 2025. All rights reserved, also regarding any disposal, exploitation, reproduction, editing, distribution, as
well as in the event of applications for industrial property rights.



18


## Bosch Sensortec BSEC Integration Guide

**3.3.1.6** **BSEC_W_DOSTEPS_TSINTRADIFFOUTOFRANGE**


Possible reasons:


- General description: BSEC_W_DOSTEPS_TSINTRADIFFOUTOFRANGE


- Current timestamp of the inputs passed to bsec_do_steps() is same as the previous one stored for the same
inputs.


Correction methods:


- time_stamp field of the inputs structure passed to bsec_do_steps() should be unique.


**3.3.2** **Errors Returned by bsec_update_subscription()**


**3.3.2.1** **BSEC_E_SU_WRONGDATARATE**


Possible reasons:


- General description: BSEC_E_SU_WRONGDATARATE


- Virtual sensors are requested with a sampling rate which is not allowed, e.g. 100 Hz.


E.g:

```
  requested_virtual_sensors[virtual_sensor_count].sample_rate = 100;
  requested_virtual_sensors[virtual_sensor_count].sensor_id = BSEC_OUTPUT_RAW_GAS;
  status = bsec_update_subscription(requested_virtual_sensors,
     n_requested_virtual_sensors, required_sensor_settings, &n_required_sensor_settings);

```

Correction methods:


- The sample_rate field in the requested_virtual_sensors structure passed to bsec_update_subscription() should
match with the sampling rate defined for that sensor. The allowed sampling rate(s) in hertz for each sensor is
listed in this table.


**3.3.2.2** **BSEC_E_SU_SAMPLERATELIMITS**


Possible reasons:


- General description: BSEC_E_SU_SAMPLERATELIMITS


- Virtual sensors are requested with an incorrect sampling rate.


E.g:

```
  requested_virtual_sensors[virtual_sensor_count].sample_rate = 5;
  requested_virtual_sensors[virtual_sensor_count].sensor_id = BSEC_OUTPUT_RAW_GAS;
  status=bsec_update_subscription(requested_virtual_sensors,
     n_requested_virtual_sensors, required_sensor_settings, &n_required_sensor_settings);

```

Correction methods:


- The sample_rate field in the requested_virtual_sensors structure passed to bsec_update_subscription() should
match with the sampling rate defined for that sensor. The allowed sampling rate(s) in hertz for each sensor is
listed in this table.



Modifications reserved | Data subject to change without notice | Document number: BST-BME-Integration-Guide-AN011-321000 Date 2025-04-29
c Bosch Sensortec GmbH 2025. All rights reserved, also regarding any disposal, exploitation, reproduction, editing, distribution, as
well as in the event of applications for industrial property rights.



19


## Bosch Sensortec BSEC Integration Guide

**3.3.2.3** **BSEC_E_SU_DUPLICATEGATE**


Possible reasons:


- General description: BSEC_E_SU_DUPLICATEGATE


- Duplicate virtual sensors are requested through bsec_update_subscription() function.


E.g:

```
  requested_virtual_sensors[virtual_sensor_count].sample_rate = 1;
  requested_virtual_sensors[virtual_sensor_count].sensor_id = BSEC_OUTPUT_RAW_GAS;
  virtual_sensor_count++;
  requested_virtual_sensors[virtual_sensor_count].sample_rate = 1;
  requested_virtual_sensors[virtual_sensor_count].sensor_id = BSEC_OUTPUT_RAW_GAS;
  status = bsec_update_subscription(requested_virtual_sensors,
     n_requested_virtual_sensors, required_sensor_settings,&n_required_sensor_settings);

```

Correction methods:


- The sensor_id field in the requested_virtual_sensors structure passed to bsec_update_subscription() should
be unique.


**3.3.2.4** **BSEC_E_SU_INVALIDSAMPLERATE**


Possible reasons:


- General description: BSEC_E_SU_INVALIDSAMPLERATE


- The sampling rate of the requested virtual sensors in not within the valid limit.


E.g:

```
  requested_virtual_sensors[virtual_sensor_count].sample_rate = 100;
  requested_virtual_sensors[virtual_sensor_count].sensor_id = BSEC_OUTPUT_RAW_GAS;
  status = bsec_update_subscription(requested_virtual_sensors,
     n_requested_virtual_sensors, required_sensor_settings, &n_required_sensor_settings);

```

Correction methods:


- The sample_rate field in the requested_virtual_sensors structure passed to bsec_update_subscription() should
match with the sampling rate defined for that sensor. The allowed sampling rate(s) in hertz for each sensor is
listed in this table.


**3.3.2.5** **BSEC_E_SU_GATECOUNTEXCEEDSARRAY**


Possible reasons:


- General description: BSEC_E_SU_GATECOUNTEXCEEDSARRAY


- Enough memory is not allocated to hold the returned physical sensor data from bsec_update_subscription().


E.g:

```
  n_required_sensor_settings = 0;
  status = bsec_update_subscription(requested_virtual_sensors,
     n_requested_virtual_sensors, required_sensor_settings, &n_required_sensor_settings);

```

Correction methods:


- n_required_sensor_settings passed to bsec_update_subscription() should be equal to BSEC_MAX_PHYSIC _←�_
AL_SENSOR.



Modifications reserved | Data subject to change without notice | Document number: BST-BME-Integration-Guide-AN011-321000 Date 2025-04-29
c Bosch Sensortec GmbH 2025. All rights reserved, also regarding any disposal, exploitation, reproduction, editing, distribution, as
well as in the event of applications for industrial property rights.



20


## Bosch Sensortec BSEC Integration Guide

**3.3.2.6** **BSEC_E_SU_SAMPLINTVLINTEGERMULT**


Possible reasons:


- General description: BSEC_E_SU_SAMPLINTVLINTEGERMULT


- The sampling rate of an output requested via bsec_update_subscription() is not an integer multiple of the other
active sampling rates.


Correction methods:


- Use one of the sampling rates listed in this table.


**3.3.2.7** **BSEC_E_SU_MULTGASSAMPLINTVL**


Possible reasons:


- General description: BSEC_E_SU_MULTGASSAMPLINTVL


- The sampling rate of the requested output requires the gas sensor, which is currently running at a different
sampling rate.


Correction methods:


- The outputs that require the gas sensor must have equal sampling rates.


**3.3.2.8** **BSEC_E_SU_HIGHHEATERONDURATION**


Possible reasons:


- General description: BSEC_E_SU_HIGHHEATERONDURATION


- The sampling period of the requested output is lower than the duration of a complete measurement.


Correction methods:


- Use a slower sampling rate.


**3.3.2.9** **BSEC_W_SU_UNKNOWNOUTPUTGATE**


Possible reasons:


- General description: BSEC_W_SU_UNKNOWNOUTPUTGATE


- Requested virtual sensor id is not valid.


- Number of virtual sensors passed to bsec_update_subscription() is greater than the actual number of output(virtual) sensors requested.


E.g:

```
  requested_virtual_sensors[virtual_sensor_count].sample_rate = 1;
  requested_virtual_sensors[virtual_sensor_count].sensor_id = 100;

  n_requested_virtual_sensors = 3;
  status = bsec_update_subscription(requested_virtual_sensors,
     n_requested_virtual_sensors, required_sensor_settings, &n_required_sensor_settings);

```

Correction methods:


- The sensor_id field in the requested_virtual_sensors structure passed to bsec_update_subscription() should
be in the range of bsec_virtual_sensor_t enum.



Modifications reserved | Data subject to change without notice | Document number: BST-BME-Integration-Guide-AN011-321000 Date 2025-04-29
c Bosch Sensortec GmbH 2025. All rights reserved, also regarding any disposal, exploitation, reproduction, editing, distribution, as
well as in the event of applications for industrial property rights.



21


## Bosch Sensortec BSEC Integration Guide

bsec_update_subscription() i.e. size of requested_virtual_sensors structure array.


**3.3.2.10** **BSEC_W_SU_SAMPLERATEMISMATCH**


Possible reasons:


- General description: BSEC_W_SU_SAMPLERATEMISMATCH


- The subscribed sample rate for the outputs are not matching with the configured sampling rate


Correction methods:


- To ensure proper operation keep configured sample rate as same as outputs subscription rate.


**3.3.2.11** **BSEC_I_SU_SUBSCRIBEDOUTPUTGATES**


Possible reasons:


- General description: BSEC_I_SU_SUBSCRIBEDOUTPUTGATES


- No output (virtual) sensor requested through bsec_update_subscription()


- Number of requested output (virtual) sensors passed to bsec_update_subscription() is zero even when there
are some output (virtual) sensors requested.


E.g:

```
  requested_virtual_sensors[virtual_sensor_count].sample_rate = 1/300;
  requested_virtual_sensors[virtual_sensor_count].sensor_id = BSEC_OUTPUT_RAW_GAS;
  n_requested_virtual_sensors = 0;
  status = bsec_update_subscription(requested_virtual_sensors,
     n_requested_virtual_sensors, required_sensor_settings, &n_required_sensor_settings);

```

Correction methods:


- requested_virtual_sensors structure to bsec_update_subscription() should be populated with the data of the
required output (virtual) sensors. It should not be empty.


- n_requested_virtual_sensors should be equal to the number of output (virtual) sensors requested via bsec_ _←�_
update_subscription(), i.e., size of requested_virtual_sensors structure array. It should not be zero.


**3.3.2.12** **BSEC_W_SU_MODINNOULP**


Possible reasons:


- General description: BSEC_W_SU_MODINNOULP


- Triggering measurement on demand (MOD) in non-ULP mode


Correction methods:


- Ensure that sensors are running in ULP mode or enable ULP mode using bsec_update_subscription() before
triggering MOD



Modifications reserved | Data subject to change without notice | Document number: BST-BME-Integration-Guide-AN011-321000 Date 2025-04-29
c Bosch Sensortec GmbH 2025. All rights reserved, also regarding any disposal, exploitation, reproduction, editing, distribution, as
well as in the event of applications for industrial property rights.



22


## Bosch Sensortec BSEC Integration Guide

**3.3.3** **Errors Returned by bsec_set_configuration() / bsec_set_state()**


**3.3.3.1** **BSEC_E_CONFIG_VERSIONMISMATCH**


Possible reasons:


- General description: BSEC_E_CONFIG_VERSIONMISMATCH


- Version mentioned in the configuration string or state string passed to bsec_set_configuration() or bsec_set_ _←�_
state(), respectively, does not match with the current version.


Correction methods:


- Obtain a compatible string.


- A call to bsec_get_version() would give the current version information.


**3.3.3.2** **BSEC_E_CONFIG_FEATUREMISMATCH**


Possible reasons:


- General description: BSEC_E_CONFIG_FEATUREMISMATCH


- Enabled features encoded in configuration/state strings passed to bsec_set_configuration() / bsec_set_state()
does not match with current library implementation or subscribed outputs.


Correction methods:


- Ensure the configuration/state strings generated for current library implementation is passed to bsec_set_ _←�_
configuration() / bsec_set_state() also check that only GAS_ESTIMATE outputs are subscribed or enabled with
configuration for classification, and not REGRESSION_ESTIMATE outputs and vise-versa.


**3.3.3.3** **BSEC_E_CONFIG_CRCMISMATCH**


Possible reasons:


- General description: BSEC_E_CONFIG_CRCMISMATCH


- Difference in configuration/state strings passed to bsec_set_configuration() / bsec_set_state() from what is
generated for current library implementation.


- String was corrupted during storage or loading.


- String was truncated.


- String is shorter than the size argument provided to the setter function.


Correction methods:


- Ensure the configuration/state strings generated for current library implementation is passed to bsec_set_ _←�_
configuration() / bsec_set_state().


**3.3.3.4** **BSEC_E_CONFIG_EMPTY**


Possible reasons:


- General description: BSEC_E_CONFIG_EMPTY


- String passed to the setter function is too short to be able to be a valid string.



Modifications reserved | Data subject to change without notice | Document number: BST-BME-Integration-Guide-AN011-321000 Date 2025-04-29
c Bosch Sensortec GmbH 2025. All rights reserved, also regarding any disposal, exploitation, reproduction, editing, distribution, as
well as in the event of applications for industrial property rights.



23


## Bosch Sensortec BSEC Integration Guide

Correction methods:


- Obtain a valid config string.


**3.3.3.5** **BSEC_E_CONFIG_INSUFFICIENTWORKBUFFER**


Possible reasons:


- General description: BSEC_E_CONFIG_INSUFFICIENTWORKBUFFER


- Length of work buffer passed to bsec_set_configuration() or bsec_set_state() is less than required value.


- Length of work buffer passed to bsec_get_configuration() or bsec_get_state() is less than required value.


Correction methods:


- Value of n_work_buffer_size passed to bsec_set_configuration() and bsec_set_state() should be assigned the
maximum value BSEC_MAX_PROPERTY_BLOB_SIZE.


- Value of n_work_buffer passed to bsec_get_configuration() and bsec_get_state() should be assigned the
maximum value BSEC_MAX_PROPERTY_BLOB_SIZE.


**3.3.3.6** **BSEC_E_CONFIG_INVALIDSTRINGSIZE**


Possible reasons:


- General description: BSEC_E_CONFIG_INVALIDSTRINGSIZE


- String size encoded in configuration/state strings passed to bsec_set_configuration() / bsec_set_state() does
not match with the actual string size n_serialized_settings/n_serialized_state passed to these functions.


Correction methods:


- Ensure the configuration/state strings generated for current library implementation is passed to bsec_set_ _←�_
configuration() / bsec_set_state().


**3.3.3.7** **BSEC_E_CONFIG_INSUFFICIENTBUFFER**


Possible reasons:


- General description: BSEC_E_CONFIG_INSUFFICIENTBUFFER


- Value of n_serialized_settings_max/n_serialized_state_max passed to bsec_get_configuration() / bsec_get_ _←�_
state() is insufficient to hold serialized data from BSEC library.


Correction methods:


- Value of n_serialized_settings_max/n_serialized_state_max passed to bsec_get_configuration() / bsec_get_ _←�_
state() should be equal to BSEC_MAX_PROPERTY_BLOB_SIZE.


**3.3.4** **Errors Returned by bsec_sensor_control()**


**3.3.4.1** **BSEC_W_SC_CALL_TIMING_VIOLATION**


Possible reasons:


- General description: BSEC_W_SC_CALL_TIMING_VIOLATION



Modifications reserved | Data subject to change without notice | Document number: BST-BME-Integration-Guide-AN011-321000 Date 2025-04-29
c Bosch Sensortec GmbH 2025. All rights reserved, also regarding any disposal, exploitation, reproduction, editing, distribution, as
well as in the event of applications for industrial property rights.



24


## Bosch Sensortec BSEC Integration Guide

returned during the previous call in the .next_call struct member by more than 6.25%.


Correction methods:


- Ensure that your system calls bsec_sensor_control() at the time instructed in the previous call.


- To ensure proper operation, a maximum jitter of 6.25% is allowed.

## **3.4 Upgrading from BME688/BME680 sensors to BME690 sensors**


Applicable users:


- BME688/BME680 customers who want to upgrade to BME690 sensors with BSEC 3.x support.


Changes required:


- Update the sensor API calls which includes replacing 'bme68x' keywords to 'bme69x'.


- For customers who are using multi-interface functionality of BSEC 2.x, refer Using BSEC 3.x for BME680/688
Sensor Variants for updating to BSEC 3.x interface.


- Customers who are using the Standard interface functions of BSEC 2.x need to refactor their application code
as per upgraded BSEC 3.x interface function.



Modifications reserved | Data subject to change without notice | Document number: BST-BME-Integration-Guide-AN011-321000 Date 2025-04-29
c Bosch Sensortec GmbH 2025. All rights reserved, also regarding any disposal, exploitation, reproduction, editing, distribution, as
well as in the event of applications for industrial property rights.



25


## Bosch Sensortec BSEC Integration Guide

# **4 Module Documentation**

## **4.1 BSEC Enumerations and Definitions**

**4.1.1** **Enumerations**


**4.1.1.1** **bsec_library_return_t**

```
enum bsec_library_return_t

```

Enumeration for function return codes.


|Enumerator|Col2|
|---|---|
|BSEC_OK|Function execution successful|
|BSEC_E_DOSTEPS_INVALIDINPUT|Input (physical) sensor id passed to bsec_do_steps()<br>is not in the valid range or not valid for requested<br>virtual sensor|
|BSEC_E_DOSTEPS_VALUELIMITS|Value of input (physical) sensor signal passed to<br>bsec_do_steps() is not in the valid range|
|BSEC_W_DOSTEPS_TSINTRADIFFOUTOFRANGE|Past timestamps passed to bsec_do_steps()|
|BSEC_E_DOSTEPS_DUPLICATEINPUT|Duplicate input (physical) sensor ids passed as input<br>to bsec_do_steps()|
|BSEC_I_DOSTEPS_NOOUTPUTSRETURNABLE|No memory allocated to hold return values from<br>bsec_do_steps(), i.e., n_outputs == 0|
|BSEC_W_DOSTEPS_EXCESSOUTPUTS|Not enough memory allocated to hold return values<br>from bsec_do_steps(), i.e., n_outputs_ <_ maximum<br>number of requested output (virtual) sensors|
|BSEC_W_DOSTEPS_GASINDEXMISS|Gas index not provided to bsec_do_steps()|
|BSEC_E_SU_WRONGDATARATE|The sample_rate of the requested output (virtual)<br>sensor passed to bsec_update_subscription() is zero|
|BSEC_E_SU_SAMPLERATELIMITS|The sample_rate of the requested output (virtual)<br>sensor passed to bsec_update_subscription() does<br>not match with the sampling rate allowed for that<br>sensor|
|BSEC_E_SU_DUPLICATEGATE|Duplicate output (virtual) sensor ids requested<br>through bsec_update_subscription()|
|BSEC_E_SU_INVALIDSAMPLERATE|The sample_rate of the requested output (virtual)<br>sensor passed to bsec_update_subscription() does<br>not fall within the global minimum and maximum<br>sampling rates|



Modifications reserved | Data subject to change without notice | Document number: BST-BME-Integration-Guide-AN011-321000 Date 2025-04-29
c Bosch Sensortec GmbH 2025. All rights reserved, also regarding any disposal, exploitation, reproduction, editing, distribution, as
well as in the event of applications for industrial property rights.



26


## Bosch Sensortec BSEC Integration Guide


|Enumerator|Col2|
|---|---|
|BSEC_E_SU_GATECOUNTEXCEEDSARRAY|Not enough memory allocated to hold returned input<br>(physical) sensor data from<br>bsec_update_subscription(), i.e.,<br>n_required_sensor_settings<br>BSEC_MAX_PHYSICAL_SENSOR|
|BSEC_E_SU_SAMPLINTVLINTEGERMULT|The sample_rate of the requested output (virtual)<br>sensor passed to bsec_update_subscription() is not<br>correct|
|BSEC_E_SU_MULTGASSAMPLINTVL|The sample_rate of the requested output (virtual),<br>which requires the gas sensor, is not equal to the<br>sample_rate that the gas sensor is being operated|
|BSEC_E_SU_HIGHHEATERONDURATION|The duration of one measurement is longer than the<br>requested sampling interval|
|BSEC_W_SU_UNKNOWNOUTPUTGATE|Output (virtual) sensor id passed to<br>bsec_update_subscription() is not in the valid range;<br>e.g., n_requested_virtual_sensors_ >_ actual number of<br>output (virtual) sensors requested|
|BSEC_W_SU_MODINNOULP|ULP plus can not be requested in non-ulp mode|
|BSEC_I_SU_SUBSCRIBEDOUTPUTGATES|No output (virtual) sensor data were requested via<br>bsec_update_subscription()|
|BSEC_I_SU_GASESTIMATEPRECEDENCE|GAS_ESTIMATE is suscribed and take precedence<br>over other requested outputs|
|BSEC_W_SU_SAMPLERATEMISMATCH|Subscriped sample rate of the output is not matching<br>with conﬁgured sample rate. For example if user used<br>the conﬁguration of ULP and outputs subscribed for<br>LP mode this warning will inform the user about this<br>mismatch|
|BSEC_E_PARSE_SECTIONEXCEEDSWORKBU_←-_<br>FFER|n_work_buﬀer_size passed to<br>bsec_set_[conﬁguration/state]() not suﬃcient|
|BSEC_E_CONFIG_FAIL|Conﬁguration failed|
|BSEC_E_CONFIG_VERSIONMISMATCH|Version encoded in serialized_[settings/state] passed<br>to bsec_set_[conﬁguration/state]() does not match<br>with current version|
|BSEC_E_CONFIG_FEATUREMISMATCH|Enabled features encoded in<br>serialized_[settings/state] passed to<br>bsec_set_[conﬁguration/state]() does not match with<br>current library implementation or subscribed outputs|
|BSEC_E_CONFIG_CRCMISMATCH|serialized_[settings/state] passed to<br>bsec_set_[conﬁguration/state]() is corrupted|
|BSEC_E_CONFIG_EMPTY|n_serialized_[settings/state] passed to<br>bsec_set_[conﬁguration/state]() is to short to be valid|
|BSEC_E_CONFIG_INSUFFICIENTWORKBUFFER|Provided work_buﬀer is not large enough to hold the<br>desired string|



Modifications reserved | Data subject to change without notice | Document number: BST-BME-Integration-Guide-AN011-321000 Date 2025-04-29
c Bosch Sensortec GmbH 2025. All rights reserved, also regarding any disposal, exploitation, reproduction, editing, distribution, as
well as in the event of applications for industrial property rights.



27


## Bosch Sensortec BSEC Integration Guide

|Enumerator|Col2|
|---|---|
|BSEC_E_CONFIG_INVALIDSTRINGSIZE|String size encoded in conﬁguration/state strings<br>passed to bsec_set_[conﬁguration/state]() does not<br>match with the actual string size<br>n_serialized_[settings/state] passed to these functions|
|BSEC_E_CONFIG_INSUFFICIENTBUFFER|String buﬀer insuﬃcient to hold serialized data from<br>BSEC library|
|BSEC_E_SET_INVALIDCHANNELIDENTIFIER|Internal error code, size of work buﬀer in setConﬁg<br>must be set to BSEC_MAX_WORKBUFFER_SIZE|
|BSEC_E_SET_INVALIDLENGTH|Internal error code|
|BSEC_W_SC_CALL_TIMING_VIOLATION|Diﬀerence between actual and deﬁned sampling<br>intervals of bsec_sensor_control() greater than<br>allowed|
|BSEC_W_SC_MODEXCEEDULPTIMELIMIT|ULP plus is not allowed because an ULP<br>measurement just took or will take place|
|BSEC_W_SC_MODINSUFFICIENTWAITTIME|ULP plus is not allowed because not suﬃcient time<br>passed since last ULP plus|



**4.1.1.2** **bsec_physical_sensor_t**

```
enum bsec_physical_sensor_t

```

Enumeration for input (physical) sensors.


Used to populate bsec_input_t::sensor_id. It is also used in bsec_sensor_configuration_t::sensor_id structs
returned in the parameter required_sensor_settings of bsec_update_subscription().


See also


bsec_sensor_configuration_t
bsec_input_t


|Enumerator|Col2|
|---|---|
|BSEC_INPUT_PRESSURE|Pressure sensor output of BME6xy [Pa].|
|BSEC_INPUT_HUMIDITY|Humidity sensor output of BME6xy [%].<br>Note<br>Relative humidity strongly depends on the<br>temperature (it is measured at). It may require a<br>conversion to the temperature outside of the<br>device.<br>See also<br>bsec_virtual_sensor_t|



Modifications reserved | Data subject to change without notice | Document number: BST-BME-Integration-Guide-AN011-321000 Date 2025-04-29
c Bosch Sensortec GmbH 2025. All rights reserved, also regarding any disposal, exploitation, reproduction, editing, distribution, as
well as in the event of applications for industrial property rights.



28


## Bosch Sensortec BSEC Integration Guide


|Enumerator|Col2|
|---|---|
|BSEC_INPUT_TEMPERATURE|Temperature sensor output of BME6xy [degrees Celsius].<br>Note<br>The BME6xy is factory trimmed, thus the<br>temperature sensor of the BME6xy is very<br>accurate. The temperature value is a very local<br>measurement value and can be inﬂuenced by<br>external heat sources.<br>See also<br>bsec_virtual_sensor_t|
|BSEC_INPUT_GASRESISTOR|Gas sensor resistance output of BME6xy [Ohm]. The<br>resistance value changes due to varying VOC<br>concentrations (the higher the concentration of reducing<br>VOCs, the lower the resistance and vice versa).|
|BSEC_INPUT_HEATSOURCE|Additional input for device heat compensation. The value<br>is subtracted from BSEC_INPUT_TEMPERATURE to<br>compute BSEC_OUTPUT_SENSOR_HEAT_COMPE_←-_<br>NSATED_TEMPERATURE.<br>See also<br>bsec_virtual_sensor_t|
|BSEC_INPUT_DISABLE_BASELINE_TRACKER|Additional input for controlling IAQ and TVOC equivalent<br>baseline trackers. Allowed input values are:<br>0 - Default value. IAQ baseline adaptation is enabled<br>and TVOC equivalent baseline adpatation is disabled.<br>1 - IAQ baseline adaptation is disabled and wait up to 10<br>seconds before restarting adaptation when input is reset<br>to 0.<br>2 - IAQ baseline adaptation is disabled and wait up to 3<br>seconds before restarting adaptation when input is reset<br>to 0.<br>3 - TVOC equivalent baseline adaptation enabled.<br>Note<br>Baseline is a mechanism for compensating the<br>long term drifts in the enviornment and ensure the<br>consistency of IAQ and TVOC equivalent outputs<br>across diﬀerent BME sensors.|
|BSEC_INPUT_PROFILE_PART|Additional input that provides information about the state<br>of the proﬁle (1-9)|



Modifications reserved | Data subject to change without notice | Document number: BST-BME-Integration-Guide-AN011-321000 Date 2025-04-29
c Bosch Sensortec GmbH 2025. All rights reserved, also regarding any disposal, exploitation, reproduction, editing, distribution, as
well as in the event of applications for industrial property rights.



29


## Bosch Sensortec BSEC Integration Guide

**4.1.1.3** **bsec_virtual_sensor_t**

```
enum bsec_virtual_sensor_t

```

Enumeration for output (virtual) sensors.


Used to populate bsec_output_t::sensor_id. It is also used in bsec_sensor_configuration_t::sensor_id structs
passed in the parameter requested_virtual_sensors of bsec_update_subscription().


See also


bsec_sensor_configuration_t
bsec_output_t


|Enumerator|Col2|
|---|---|
|BSEC_OUTPUT_IAQ|Indoor-air-quality estimate [0-500]. Indoor-air-quality<br>(IAQ) gives an indication of the relative change in<br>ambient TVOCs detected by BME6xy.<br>Note<br>The IAQ scale ranges from 0 (clean air) to 500<br>(heavily polluted air). During operation,<br>algorithms automatically calibrate and adapt<br>themselves to the typical environments where<br>the sensor is operated (e.g., home, workplace,<br>inside a car, etc.).This automatic background<br>calibration ensures that users experience<br>consistent IAQ performance. The calibration<br>process considers the recent measurement<br>history (typ. up to four days) to ensure that<br>IAQ=50 corresponds to typical good air and<br>IAQ=200 indicates typical polluted air.|
|BSEC_OUTPUT_STATIC_IAQ|Unscaled indoor-air-quality estimate|
|BSEC_OUTPUT_CO2_EQUIVALENT|CO2 equivalent estimate [ppm]|
|BSEC_OUTPUT_BREATH_VOC_EQUIVALENT|Breath VOC concentration estimate [ppm]|
|BSEC_OUTPUT_RAW_TEMPERATURE|Temperature sensor signal [degrees Celsius].<br>Temperature directly measured by BME6xy in degree<br>Celsius.<br>Note<br>This value is cross-inﬂuenced by the sensor<br>heating and device speciﬁc heating.|
|BSEC_OUTPUT_RAW_PRESSURE|Pressure sensor signal [Pa]. Pressure directly<br>measured by the BME6xy in Pa.|



Modifications reserved | Data subject to change without notice | Document number: BST-BME-Integration-Guide-AN011-321000 Date 2025-04-29
c Bosch Sensortec GmbH 2025. All rights reserved, also regarding any disposal, exploitation, reproduction, editing, distribution, as
well as in the event of applications for industrial property rights.



30


## Bosch Sensortec BSEC Integration Guide


|Enumerator|Col2|
|---|---|
|BSEC_OUTPUT_RAW_HUMIDITY|Relative humidity sensor signal [%]. Relative humidity<br>directly measured by the BME6xy in %.<br>Note<br>This value is cross-inﬂuenced by the sensor<br>heating and device speciﬁc heating.|
|BSEC_OUTPUT_RAW_GAS|Gas sensor signal [Ohm]. Gas resistance measured<br>directly by the BME6xy in Ohm.The resistance value<br>changes due to varying VOC concentrations (the<br>higher the concentration of reducing VOCs, the lower<br>the resistance and vice versa).|
|BSEC_OUTPUT_STABILIZATION_STATUS|Gas sensor stabilization status [boolean]. Indicates<br>initial stabilization status of the gas sensor element:<br>stabilization is ongoing (0) or stabilization is ﬁnished<br>(1).|
|BSEC_OUTPUT_RUN_IN_STATUS|Gas sensor run-in status [boolean]. Dynamicaly<br>tracks the power-on stabilization of the gas sensor<br>element: stabilization is ongoing (0) or stabilization is<br>ﬁnished (1). It depends on how long the sensor has<br>been turn oﬀ. A power-on conditioning has been<br>employed for early stabilization of BME sensors.|



Modifications reserved | Data subject to change without notice | Document number: BST-BME-Integration-Guide-AN011-321000 Date 2025-04-29
c Bosch Sensortec GmbH 2025. All rights reserved, also regarding any disposal, exploitation, reproduction, editing, distribution, as
well as in the event of applications for industrial property rights.



31


## Bosch Sensortec BSEC Integration Guide








|Enumerator|Col2|
|---|---|
|BSEC_OUTPUT_SENSOR_HEAT_COMPENSAT_←-_<br>ED_TEMPERATURE|Sensor heat compensated temperature [degrees<br>Celsius]. Temperature measured by BME6xy which is<br>compensated for the inﬂuence of sensor (heater) in<br>degree Celsius. The self heating introduced by the<br>heater is depending on the sensor operation mode<br>and the sensor supply voltage.<br>Note<br>In addition, the temperature output can be<br>compensated by an user deﬁned value<br>(BSEC_INPUT_HEATSOURCE in degrees<br>Celsius), which represents the device speciﬁc<br>self-heating.<br>Thus, the value is calculated as follows:<br>· `BSEC_OUTPUT_SENSOR_HEAT_COMPENSATED_TEMP`_←-_<br>`ERATURE = BSEC_INPUT_TEMPERATURE -`<br>`function(sensor operation mode, sensor`<br>`supply voltage) - BSEC_INPUT_HEATSOURCE`<br>The self-heating in operation mode<br>BSEC_SAMPLE_RATE_ULP is negligible. The<br>self-heating in operation mode<br>BSEC_SAMPLE_RATE_LP is supported for 1.8V by<br>default (no conﬁg ﬁle required). If the BME6xy sensor<br>supply voltage is 3.3V, the corresponding conﬁg ﬁle<br>shall be used.|
|BSEC_OUTPUT_SENSOR_HEAT_COMPENSAT_←-_<br>ED_HUMIDITY|Sensor heat compensated humidity [%]. Relative<br>humidity measured by BME6xy which is compensated<br>for the inﬂuence of sensor (heater) in %.<br>It converts the BSEC_INPUT_HUMIDITY from<br>temperature BSEC_INPUT_TEMPERATURE to<br>temperature BSEC_OUTPUT_SENSOR_HEAT_C_←-_<br>OMPENSATED_TEMPERATURE.<br>Note<br>If BSEC_INPUT_HEATSOURCE is used for<br>device speciﬁc temperature compensation, it will<br>be eﬀective for BSEC_OUTPUT_SENSOR_H_←-_<br>EAT_COMPENSATED_HUMIDITY<br>too.|
|BSEC_OUTPUT_COMPENSATED_GAS|Raw gas resistance compensated by temperature and<br>humidity inﬂuences [ohm]. The eﬀect of temperature<br>and humidity on the gas resistance is eleminated to a<br>good extend and it is further linearized to log scale for<br>estimation of the compensated gas resistance.|



Modifications reserved | Data subject to change without notice | Document number: BST-BME-Integration-Guide-AN011-321000 Date 2025-04-29
c Bosch Sensortec GmbH 2025. All rights reserved, also regarding any disposal, exploitation, reproduction, editing, distribution, as
well as in the event of applications for industrial property rights.



32


## Bosch Sensortec BSEC Integration Guide

|Enumerator|Col2|
|---|---|
|BSEC_OUTPUT_GAS_PERCENTAGE|Percentage of min and max ﬁltered gas value [%]|
|BSEC_OUTPUT_GAS_ESTIMATE_1|Gas estimate output channel 1 [0-1]. The gas scan<br>result is given in probability for each of the used<br>gases. In standard scan mode, the probability of H2S<br>and non-H2S is provided by the variables<br>BSEC_OUTPUT_GAS_ESTIMATE_1 &<br>BSEC_OUTPUT_GAS_ESTIMATE_2 respectively. A<br>maximum of 4 classes can be used by conﬁguring<br>with BME AI-studio.|
|BSEC_OUTPUT_GAS_ESTIMATE_2|Gas estimate output channel 2 [0-1]|
|BSEC_OUTPUT_GAS_ESTIMATE_3|Gas estimate output channel 3 [0-1]|
|BSEC_OUTPUT_GAS_ESTIMATE_4|Gas estimate output channel 4 [0-1]|
|BSEC_OUTPUT_RAW_GAS_INDEX|Gas index cyclically running from 0 to<br>::heater_proﬁle_len-1, range of heater proﬁle length is<br>from 1 to 10, default being 10|
|BSEC_OUTPUT_REGRESSION_ESTIMATE_1|Regression estimate output channel 1. The<br>regression estimate gives the quantitative<br>measurement of the gases used. A maximum of 4<br>gas targets can be used by conﬁguring with BME<br>AI-studio.|
|BSEC_OUTPUT_REGRESSION_ESTIMATE_2|Regression estimate output channel 2|
|BSEC_OUTPUT_REGRESSION_ESTIMATE_3|Regression estimate output channel 3|
|BSEC_OUTPUT_REGRESSION_ESTIMATE_4|Regression estimate output channel 4|
|BSEC_OUTPUT_TVOC_EQUIVALENT|TVOC Equivalent in ppb|



**4.1.2** **Defines**


**4.1.2.1** **BSEC_MAX_PHYSICAL_SENSOR**

```
#define BSEC_MAX_PHYSICAL_SENSOR (8)

```

Number of physical sensors that need allocated space before calling bsec_update_subscription()


**4.1.2.2** **BSEC_MAX_PROPERTY_BLOB_SIZE**

```
#define BSEC_MAX_PROPERTY_BLOB_SIZE (2005)

```

Maximum size (in bytes) of the data blobs returned by bsec_get_configuration()


**4.1.2.3** **BSEC_MAX_STATE_BLOB_SIZE**

```
#define BSEC_MAX_STATE_BLOB_SIZE (259)

```

Maximum size (in bytes) of the data blobs returned by bsec_get_state()



Modifications reserved | Data subject to change without notice | Document number: BST-BME-Integration-Guide-AN011-321000 Date 2025-04-29
c Bosch Sensortec GmbH 2025. All rights reserved, also regarding any disposal, exploitation, reproduction, editing, distribution, as
well as in the event of applications for industrial property rights.



33


## Bosch Sensortec BSEC Integration Guide

**4.1.2.4** **BSEC_MAX_WORKBUFFER_SIZE**

```
#define BSEC_MAX_WORKBUFFER_SIZE (4096)

```

Maximum size (in bytes) of the work buffer


**4.1.2.5** **BSEC_NUMBER_OUTPUTS**

```
#define BSEC_NUMBER_OUTPUTS (24)

```

Number of outputs, depending on solution


**4.1.2.6** **BSEC_OUTPUT_INCLUDED**

```
#define BSEC_OUTPUT_INCLUDED (2146597359)

```

bitfield that indicates which outputs are included in the solution


**4.1.2.7** **BSEC_PROCESS_GAS**


`#define` `BSEC_PROCESS_GAS` `(1` _<<_ `(BSEC_INPUT_GASRESISTOR-1))`


process_data bitfield constant for gas sensor


See also


bsec_bme_settings_t


**4.1.2.8** **BSEC_PROCESS_HUMIDITY**


`#define` `BSEC_PROCESS_HUMIDITY` `(1` _<<_ `(BSEC_INPUT_HUMIDITY-1))`


process_data bitfield constant for humidity


See also


bsec_bme_settings_t


**4.1.2.9** **BSEC_PROCESS_PRESSURE**


`#define` `BSEC_PROCESS_PRESSURE` `(1` _<<_ `(BSEC_INPUT_PRESSURE-1))`


process_data bitfield constant for pressure


See also


bsec_bme_settings_t


Modifications reserved | Data subject to change without notice | Document number: BST-BME-Integration-Guide-AN011-321000 Date 2025-04-29
c Bosch Sensortec GmbH 2025. All rights reserved, also regarding any disposal, exploitation, reproduction, editing, distribution, as
well as in the event of applications for industrial property rights.



34


## Bosch Sensortec BSEC Integration Guide

**4.1.2.10** **BSEC_PROCESS_PROFILE_PART**


`#define` `BSEC_PROCESS_PROFILE_PART` `(1` _<<_ `(BSEC_INPUT_PROFILE_PART-1))`


process_data bitfield constant for gas sensor


See also


bsec_bme_settings_t


**4.1.2.11** **BSEC_PROCESS_TEMPERATURE**


`#define` `BSEC_PROCESS_TEMPERATURE` `(1` _<<_ `(BSEC_INPUT_TEMPERATURE-1))`


process_data bitfield constant for temperature


See also


bsec_bme_settings_t


**4.1.2.12** **BSEC_SAMPLE_RATE_CONT**

```
#define BSEC_SAMPLE_RATE_CONT (1.0f)

```

Sample rate in case of Continuous Mode


**4.1.2.13** **BSEC_SAMPLE_RATE_DISABLED**

```
#define BSEC_SAMPLE_RATE_DISABLED (65535.0f)

```

Sample rate of a disabled sensor


**4.1.2.14** **BSEC_SAMPLE_RATE_LP**

```
#define BSEC_SAMPLE_RATE_LP (0.33333f)

```

Sample rate in case of Low Power Mode


**4.1.2.15** **BSEC_SAMPLE_RATE_SCAN**

```
#define BSEC_SAMPLE_RATE_SCAN (0.055556f)

```

Sample rate in case of scan mode


**4.1.2.16** **BSEC_SAMPLE_RATE_ULP**

```
#define BSEC_SAMPLE_RATE_ULP (0.0033333f)

```

Sample rate in case of Ultra Low Power Mode


Modifications reserved | Data subject to change without notice | Document number: BST-BME-Integration-Guide-AN011-321000 Date 2025-04-29
c Bosch Sensortec GmbH 2025. All rights reserved, also regarding any disposal, exploitation, reproduction, editing, distribution, as
well as in the event of applications for industrial property rights.



35


## Bosch Sensortec BSEC Integration Guide

**4.1.2.17** **BSEC_SAMPLE_RATE_ULP_MEASUREMENT_ON_DEMAND**

```
#define BSEC_SAMPLE_RATE_ULP_MEASUREMENT_ON_DEMAND (0.0f)

```

Input value used to trigger an extra measurment (ULP plus)


**4.1.2.18** **BSEC_STRUCT_NAME**

```
#define BSEC_STRUCT_NAME Bsec

```

Internal struct name


Modifications reserved | Data subject to change without notice | Document number: BST-BME-Integration-Guide-AN011-321000 Date 2025-04-29
c Bosch Sensortec GmbH 2025. All rights reserved, also regarding any disposal, exploitation, reproduction, editing, distribution, as
well as in the event of applications for industrial property rights.



36


## Bosch Sensortec BSEC Integration Guide **4.2 BSEC Interfaces**

The interface functions are used for interfacing one or more sensors with corresponding BSEC library instances.


**4.2.1** **Interface Functions**


**4.2.1.1** **bsec_do_steps()**

```
bsec_library_return_t bsec_do_steps (

```

`void` _∗_ _`inst,`_


`const` `bsec_input_t` _∗_ `const` _`inputs,`_

```
       const uint8_t n_inputs,

```

`bsec_output_t` _∗_ _`outputs,`_


`uint8_t` _∗_ _`n_outputs`_ `)`


Main signal processing function of BSEC library instance.


Processing of the input signals and returning of output samples for each instances of BSEC library is performed
by bsec_do_steps().


- The samples of all library inputs must be passed with unique identifiers representing the input signals from
physical sensors where the order of these inputs can be chosen arbitrary. However, all input have to be
provided within the same time period as they are read. A sequential provision to the library might result in
undefined behavior.


- The samples of all library outputs are returned with unique identifiers corresponding to the output signals of
virtual sensors where the order of the returned outputs may be arbitrary.


- The samples of all input as well as output signals of physical as well as virtual sensors use the same
representation in memory with the following fields:


- Sensor identifier:


 - For inputs: required to identify the input signal from a physical sensor


 - For output: overwritten by bsec_do_steps() to identify the returned signal from a virtual sensor


 - Time stamp of the sample


Calling bsec_do_steps() requires the samples of the input signals to be provided along with their time stamp
when they are recorded and only when they are acquired. Repetition of samples with the same time stamp are
ignored and result in a warning. Repetition of values of samples which are not acquired anew by a sensor result
in deviations of the computed output signals. Concerning the returned output samples, an important feature is,
that a value is returned for an output only when a new occurrence has been computed. A sample of an output
signal is returned only once.


Parameters


|in,out|inst|Reference to the pointer containing the instance|
|---|---|---|
|`i`n|_inputs_|Array of input data samples. Each array element represents a sample of a diﬀerent<br>physical sensor.|
|`i`n|_n_inputs_|Number of passed input data structs.|
|`o`ut|_outputs_|Array of output data samples. Each array element represents a sample of a diﬀerent<br>virtual sensor.|
|`i`n,out|_n_outputs_|[in] Number of allocated output structs, [out] number of outputs returned|



Modifications reserved | Data subject to change without notice | Document number: BST-BME-Integration-Guide-AN011-321000 Date 2025-04-29
c Bosch Sensortec GmbH 2025. All rights reserved, also regarding any disposal, exploitation, reproduction, editing, distribution, as
well as in the event of applications for industrial property rights.



37


## Bosch Sensortec BSEC Integration Guide

Returns


Zero when successful, otherwise an error code


**4.2.1.2** **bsec_get_configuration()**

```
bsec_library_return_t bsec_get_configuration (

```

`void` _∗_ _`inst,`_

```
       const uint8_t config_id,

```

`uint8_t` _∗_ _`serialized_settings,`_

```
       const uint32_t n_serialized_settings_max,

```

`uint8_t` _∗_ _`work_buffer,`_

```
       const uint32_t n_work_buffer,

```

`uint32_t` _∗_ _`n_serialized_settings`_ `)`


Retrieve the current library instance configuration.


BSEC allows to retrieve the current configuration of the library instance using bsec_get_configuration(). This API
returns a binary blob encoding. the current configuration parameters of the library in a format compatible with
bsec_set_configuration().


Please use BSEC_MAX_PROPERTY_BLOB_SIZE for allotting the required size.


Parameters

|in,out|inst|Reference to the pointer containing the instance|
|---|---|---|
|`i`n|_conﬁg_id_|Identiﬁer for a speciﬁc set of conﬁguration settings to be returned; shall<br>be zero to retrieve all conﬁguration settings.|
|`o`ut|_serialized_settings_|Buﬀer to hold the serialized conﬁg blob|
|`i`n|_n_serialized_settings_max_|Maximum available size for the serialized settings|
|`i`n,out|_work_buﬀer_|Work buﬀer used to parse the binary blob|
|`i`n|_n_work_buﬀer_|Length of the work buﬀer available for parsing the blob|
|`o`ut|_n_serialized_settings_|Actual size of the returned serialized conﬁguration blob|



Returns


Zero when successful, otherwise an error code


**4.2.1.3** **bsec_get_instance_size()**

```
size_t bsec_get_instance_size (

       void )

```

Function that provides the size of the internal instance in bytes. To be used for allocating memory for struct
BSEC_STRUCT_NAME.


Returns


Size of the internal instance in bytes



Modifications reserved | Data subject to change without notice | Document number: BST-BME-Integration-Guide-AN011-321000 Date 2025-04-29
c Bosch Sensortec GmbH 2025. All rights reserved, also regarding any disposal, exploitation, reproduction, editing, distribution, as
well as in the event of applications for industrial property rights.



38


## Bosch Sensortec BSEC Integration Guide

**4.2.1.4** **bsec_get_state()**

```
bsec_library_return_t bsec_get_state (

```

`void` _∗_ _`inst,`_

```
       const uint8_t state_set_id,

```

`uint8_t` _∗_ _`serialized_state,`_

```
       const uint32_t n_serialized_state_max,

```

`uint8_t` _∗_ _`work_buffer,`_

```
       const uint32_t n_work_buffer,

```

`uint32_t` _∗_ _`n_serialized_state`_ `)`


Retrieve the current internal library instance state.


BSEC allows to retrieve the current states of all signal processing modules and the BSEC module of the library
instance using bsec_get_state(). This allows a restart of the processing after a reboot of the system by calling
bsec_set_state().


Please use BSEC_MAX_STATE_BLOB_SIZE for allotting the required size.


Parameters

|in,out|inst|Reference to the pointer containing the instance|
|---|---|---|
|`i`n|_state_set_id_|Identiﬁer for a speciﬁc set of states to be returned; shall be zero to retrieve<br>all states.|
|`o`ut|_serialized_state_|Buﬀer to hold the serialized conﬁg blob|
|`i`n|_n_serialized_state_max_|Maximum available size for the serialized states|
|`i`n,out|_work_buﬀer_|Work buﬀer used to parse the blob|
|`i`n|_n_work_buﬀer_|Length of the work buﬀer available for parsing the blob|
|`o`ut|_n_serialized_state_|Actual size of the returned serialized blob|



Returns


Zero when successful, otherwise an error code


**4.2.1.5** **bsec_get_version()**

```
bsec_library_return_t bsec_get_version (

```

`void` _∗_ _`inst,`_


`bsec_version_t` _∗_ _`bsec_version_p`_ `)`


Return the version information of BSEC library instance.


Parameters






|in,out|inst|Reference to the pointer containing the instance|
|---|---|---|
|`o`ut|_bsec_version←-_<br>__p_|pointer to struct which is to be populated with the version information|



Modifications reserved | Data subject to change without notice | Document number: BST-BME-Integration-Guide-AN011-321000 Date 2025-04-29
c Bosch Sensortec GmbH 2025. All rights reserved, also regarding any disposal, exploitation, reproduction, editing, distribution, as
well as in the event of applications for industrial property rights.



39


## Bosch Sensortec BSEC Integration Guide

Returns


Zero if successful, otherwise an error code


See also: bsec_version_t


**4.2.1.6** **bsec_init()**

```
bsec_library_return_t bsec_init (

```

`void` _∗_ _`inst`_ `)`


Initialize the library instance.


Initialization and reset of BSEC library instance is performed by calling bsec_init(). Calling this function sets up
the relation among all internal modules, initializes run-time dependent library states and resets the configuration
and state of all BSEC signal processing modules to defaults.


Before any further use, the library must be initialized. This ensure that all memory and states are in defined
conditions prior to processing any data.


Parameters


`i` n,out _inst_ Reference to the pointer containing the instance


Returns


Zero if successful, otherwise an error code


**4.2.1.7** **bsec_reset_output()**

```
bsec_library_return_t bsec_reset_output (

```

`void` _∗_ _`inst,`_

```
       uint8_t sensor_id )

```

Reset a particular virtual sensor output of the library instance.


This function allows specific virtual sensor outputs of each library instance to be reset to be reset. The meaning of
"reset" depends on the specific output. In case of the IAQ output, reset means zeroing the output to the current
ambient conditions.


Parameters



|in,out|inst|Reference to the pointer containing the instance|
|---|---|---|
|`i`n|_sensor←-_<br>__id_|Virtual sensor to be reset|


Modifications reserved | Data subject to change without notice | Document number: BST-BME-Integration-Guide-AN011-321000 Date 2025-04-29
c Bosch Sensortec GmbH 2025. All rights reserved, also regarding any disposal, exploitation, reproduction, editing, distribution, as
well as in the event of applications for industrial property rights.



40


## Bosch Sensortec BSEC Integration Guide

Returns


Zero when successful, otherwise an error code


**4.2.1.8** **bsec_sensor_control()**

```
bsec_library_return_t bsec_sensor_control (

```

`void` _∗_ _`inst,`_

```
       const int64_t time_stamp,

```

`bsec_bme_settings_t` _∗_ _`sensor_settings`_ `)`


Retrieve BMExxx sensor instructions for the library instance.


The bsec_sensor_control() interface is a key feature of BSEC, as it allows an easy way for the signal processing
library to control the operation of the BME sensor using the correspodning BSEC library instance. This is important
since gas sensor behaviour is mainly determined by how the integrated heater is configured. To ensure an easy
integration of BSEC into any system, bsec_sensor_control() will provide the caller with information about the
current sensor configuration that is necessary to fulfill the input requirements derived from the current outputs
requested via bsec_update_subscription().


In practice the use of this function shall be as follows:


- Call bsec_sensor_control() which returns a bsec_bme_settings_t struct.


- Based on the information contained in this struct, the sensor is configured and a forced-mode measurement is
triggered if requested by bsec_sensor_control().


- Once this forced-mode measurement is complete, the signals specified in this struct shall be passed to
bsec_do_steps() to perform the signal processing.


- After processing, the process should sleep until the bsec_bme_settings_t::next_call timestamp is reached.


Parameters

|in,out|inst|Reference to the pointer containing the instance|
|---|---|---|
|`i`n|_time_stamp_|Current timestamp in [ns]|
|`o`ut|_sensor_settings_|Settings to be passed to API to operate sensor at this time instance|



Returns


Zero when successful, otherwise an error code


**4.2.1.9** **bsec_set_configuration()**

```
bsec_library_return_t bsec_set_configuration (

```

`void` _∗_ _`inst,`_


`const` `uint8_t` _∗_ `const` _`serialized_settings,`_

```
       const uint32_t n_serialized_settings,

```

`uint8_t` _∗_ _`work_buffer,`_

```
       const uint32_t n_work_buffer_size )

```

Update algorithm configuration parameters of the library instance.



Modifications reserved | Data subject to change without notice | Document number: BST-BME-Integration-Guide-AN011-321000 Date 2025-04-29
c Bosch Sensortec GmbH 2025. All rights reserved, also regarding any disposal, exploitation, reproduction, editing, distribution, as
well as in the event of applications for industrial property rights.



41


## Bosch Sensortec BSEC Integration Guide

customized by bsec_set_configuration(). This is an optional step.


Note


A work buffer with sufficient size is required and has to be provided by the function caller to decompose the
serialization and apply it to the library and its modules.


Please use BSEC_MAX_PROPERTY_BLOB_SIZE for allotting the required size.


Parameters

|in,out|inst|Reference to the pointer containing the instance|
|---|---|---|
|`i`n|_serialized_settings_|Settings serialized to a binary blob|
|`i`n|_n_serialized_settings_|Size of the settings blob|
|`i`n,out|_work_buﬀer_|Work buﬀer used to parse the blob|
|`i`n|_n_work_buﬀer_size_|Length of the work buﬀer available for parsing the blob|



Returns


Zero when successful, otherwise an error code


**4.2.1.10** **bsec_set_state()**

```
bsec_library_return_t bsec_set_state (

```

`void` _∗_ _`inst,`_


`const` `uint8_t` _∗_ `const` _`serialized_state,`_

```
       const uint32_t n_serialized_state,

```

`uint8_t` _∗_ _`work_buffer,`_

```
       const uint32_t n_work_buffer_size )

```

Restore the internal state of the library instance.


BSEC uses a default state for all signal processing modules and the BSEC module for each instance. To ensure
optimal performance, especially of the gas sensor functionality, it is recommended to retrieve the state using
bsec_get_state() before unloading the library, storing it in some form of non-volatile memory, and setting it using
bsec_set_state() before resuming further operation of the library.


Note


A work buffer with sufficient size is required and has to be provided by the function caller to decompose the
serialization and apply it to the library and its modules.


Please use BSEC_MAX_STATE_BLOB_SIZE for allotting the required size.


Parameters


|in,out|inst|Reference to the pointer containing the instance|
|---|---|---|
|`i`n|_serialized_state_|States serialized to a binary blob|
|`i`n|_n_serialized_state_|Size of the state blob|
|`i`n,out|_work_buﬀer_|Work buﬀer used to parse the blob|
|`i`n|_n_work_buﬀer_size_|Length of the work buﬀer available for parsing the blob|



Modifications reserved | Data subject to change without notice | Document number: BST-BME-Integration-Guide-AN011-321000 Date 2025-04-29
c Bosch Sensortec GmbH 2025. All rights reserved, also regarding any disposal, exploitation, reproduction, editing, distribution, as
well as in the event of applications for industrial property rights.



42


## Bosch Sensortec BSEC Integration Guide

Returns


Zero when successful, otherwise an error code


**4.2.1.11** **bsec_update_subscription()**

```
bsec_library_return_t bsec_update_subscription (

```

`void` _∗_ _`inst,`_


`const` `bsec_sensor_configuration_t` _∗_ `const` _`requested_virtual_sensors,`_

```
       const uint8_t n_requested_virtual_sensors,

```

`bsec_sensor_configuration_t` _∗_ _`required_sensor_settings,`_


`uint8_t` _∗_ _`n_required_sensor_settings`_ `)`


Subscribe to library virtual sensors outputs.


Use bsec_update_subscription() to instruct BSEC which of the processed output signals of the library instance
are requested at which sample rates.


See bsec_virtual_sensor_t for available library outputs.


Based on the requested virtual sensors outputs, BSEC will provide information about the required physical
sensor input signals (see bsec_physical_sensor_t) with corresponding sample rates. This information is purely
informational as bsec_sensor_control() will ensure the sensor is operated in the required manner. To disable a
virtual sensor, set the sample rate to BSEC_SAMPLE_RATE_DISABLED.


The subscription update using bsec_update_subscription() is apart from the signal processing one of the the
most important functions. It allows to enable the desired library outputs. The function determines which physical
input sensor signals are required at which sample rate to produce the virtual output sensor signals requested
by the user. When this function returns with success, the requested outputs are called subscribed. A very
important feature is the retaining of already subscribed outputs. Further outputs can be requested or disabled
both individually and group-wise in addition to already subscribed outputs without changing them unless a change
of already subscribed outputs is requested.


Note


The state of the library concerning the subscribed outputs cannot be retained among reboots.


The interface of bsec_update_subscription() requires the usage of arrays of sensor configuration structures. Such
a structure has the fields sensor identifier and sample rate. These fields have the properties:


- Output signals of virtual sensors must be requested using unique identifiers (Member of bsec_virtual_sensor_t)


- Different sets of identifiers are available for inputs of physical sensors and outputs of virtual sensors


- Identifiers are unique values defined by the library, not from external


- Sample rates must be provided as value of


 - An allowed sample rate for continuously sampled signals


 - 65535.0f (BSEC_SAMPLE_RATE_DISABLED) to turn off outputs and identify disabled inputs


Note


The same sensor identifiers are also used within the functions bsec_do_steps().


The usage principles of bsec_update_subscription() are:


- Differential updates (i.e., only asking for outputs that the user would like to change) is supported.



Modifications reserved | Data subject to change without notice | Document number: BST-BME-Integration-Guide-AN011-321000 Date 2025-04-29
c Bosch Sensortec GmbH 2025. All rights reserved, also regarding any disposal, exploitation, reproduction, editing, distribution, as
well as in the event of applications for industrial property rights.



43


## Bosch Sensortec BSEC Integration Guide

ignored. At the same time, a warning is returned.


- To disable BSEC, all outputs shall be turned off. Only enabled (subscribed) outputs have to be disabled while
already disabled outputs do not have to be disabled explicitly.


Parameters

|in,out|inst|Reference to the pointer containing the instance|
|---|---|---|
|`i`n|_requested_virtual_sensors_|Pointer to array of requested virtual sensor (output) conﬁgurations for<br>the library|
|`i`n|_n_requested_virtual_sensors_|Number of virtual sensor structs pointed by<br>requested_virtual_sensors|
|`o`ut|_required_sensor_settings_|Pointer to array of required physical sensor conﬁgurations for the<br>library|
|`i`n,out|_n_required_sensor_settings_|[in] Size of allocated required_sensor_settings array, [out] number of<br>sensor conﬁgurations returned|



Returns


Zero when successful, otherwise an error code


See also


bsec_sensor_configuration_t
bsec_physical_sensor_t
bsec_virtual_sensor_t



Modifications reserved | Data subject to change without notice | Document number: BST-BME-Integration-Guide-AN011-321000 Date 2025-04-29
c Bosch Sensortec GmbH 2025. All rights reserved, also regarding any disposal, exploitation, reproduction, editing, distribution, as
well as in the event of applications for industrial property rights.



44


## Bosch Sensortec BSEC Integration Guide

# **5 Data Structure Documentation**

## **5.1 bsec_bme_settings_t Struct Reference**

**Data Fields**


- int64_t next_call


_Time stamp of the next call of the sensor_control._

- uint32_t process_data


_Bit field describing which data is to be passed to bsec_do_steps()_

- uint16_t heater_temperature


_Heater temperature [degrees Celsius]._

- uint16_t heater_duration


_Heater duration [ms]._

- uint16_t heater_temperature_profile [10]


_Heater temperature profile [degrees Celsius]._

- uint16_t heater_duration_profile [10]


_Heater duration profile [ms]._

- uint8_t heater_profile_len


_Heater profile length [1-10]._

- uint8_t run_gas


_Enable gas measurements [0/1]._

- uint8_t pressure_oversampling


_Pressure oversampling settings [0-5]._

- uint8_t temperature_oversampling


_Temperature oversampling settings [0-5]._

- uint8_t humidity_oversampling


_Humidity oversampling settings [0-5]._

- uint8_t trigger_measurement


_Trigger a forced measurement with these settings now [0/1]._

- uint8_t op_mode


_Sensor operation mode [0/1]._


**5.1.1** **Detailed Description**


Structure returned by bsec_sensor_control() to configure BME6xy sensor.


This structure contains settings that must be used to configure the BME6xy to perform a forced-mode measurement. A measurement should only be executed if bsec_bme_settings_t::trigger_measurement is 1. If
so, the oversampling settings for temperature, humidity, and pressure should be set to the provided settings



Modifications reserved | Data subject to change without notice | Document number: BST-BME-Integration-Guide-AN011-321000 Date 2025-04-29
c Bosch Sensortec GmbH 2025. All rights reserved, also regarding any disposal, exploitation, reproduction, editing, distribution, as
well as in the event of applications for industrial property rights.



45


## Bosch Sensortec BSEC Integration Guide

bsec_bme_settings_t::pressure_oversampling, respectively.


In case of bsec_bme_settings_t::run_gas = 1, the gas sensor must be enabled with the provided bsec_bme_ _←�_
settings_t::heater_temperature and bsec_bme_settings_t::heating_duration settings.


**5.1.2** **Field Documentation**


**5.1.2.1** **heater_duration**

```
uint16_t bsec_bme_settings_t::heater_duration

```

Heater duration [ms].


**5.1.2.2** **heater_duration_profile**

```
uint16_t bsec_bme_settings_t::heater_duration_profile[10]

```

Heater duration profile [ms].


**5.1.2.3** **heater_profile_len**

```
uint8_t bsec_bme_settings_t::heater_profile_len

```

Heater profile length [1-10].


**5.1.2.4** **heater_temperature**

```
uint16_t bsec_bme_settings_t::heater_temperature

```

Heater temperature [degrees Celsius].


**5.1.2.5** **heater_temperature_profile**

```
uint16_t bsec_bme_settings_t::heater_temperature_profile[10]

```

Heater temperature profile [degrees Celsius].


**5.1.2.6** **humidity_oversampling**

```
uint8_t bsec_bme_settings_t::humidity_oversampling

```

Humidity oversampling settings [0-5].


**5.1.2.7** **next_call**

```
int64_t bsec_bme_settings_t::next_call

```

Time stamp of the next call of the sensor_control.



Modifications reserved | Data subject to change without notice | Document number: BST-BME-Integration-Guide-AN011-321000 Date 2025-04-29
c Bosch Sensortec GmbH 2025. All rights reserved, also regarding any disposal, exploitation, reproduction, editing, distribution, as
well as in the event of applications for industrial property rights.



46


## Bosch Sensortec BSEC Integration Guide

**5.1.2.8** **op_mode**

```
uint8_t bsec_bme_settings_t::op_mode

```

Sensor operation mode [0/1].


**5.1.2.9** **pressure_oversampling**

```
uint8_t bsec_bme_settings_t::pressure_oversampling

```

Pressure oversampling settings [0-5].


**5.1.2.10** **process_data**

```
uint32_t bsec_bme_settings_t::process_data

```

Bit field describing which data is to be passed to bsec_do_steps()


See also


BSEC_PROCESS_GAS, BSEC_PROCESS_TEMPERATURE, BSEC_PROCESS_HUMIDITY, BSEC_P _←�_
ROCESS_PRESSURE


**5.1.2.11** **run_gas**

```
uint8_t bsec_bme_settings_t::run_gas

```

Enable gas measurements [0/1].


**5.1.2.12** **temperature_oversampling**

```
uint8_t bsec_bme_settings_t::temperature_oversampling

```

Temperature oversampling settings [0-5].


**5.1.2.13** **trigger_measurement**

```
uint8_t bsec_bme_settings_t::trigger_measurement

```

Trigger a forced measurement with these settings now [0/1].

## **5.2 bsec_input_t Struct Reference**


**Data Fields**


- int64_t time_stamp


_Time stamp in nanosecond resolution [ns]._

- float signal


_Signal sample in the unit defined for the respective sensor_id._



Modifications reserved | Data subject to change without notice | Document number: BST-BME-Integration-Guide-AN011-321000 Date 2025-04-29
c Bosch Sensortec GmbH 2025. All rights reserved, also regarding any disposal, exploitation, reproduction, editing, distribution, as
well as in the event of applications for industrial property rights.



47


## Bosch Sensortec BSEC Integration Guide


- uint8_t signal_dimensions


_Signal dimensions (reserved for future use, shall be set to 1)_

- uint8_t sensor_id


_Identifier of physical sensor._


**5.2.1** **Detailed Description**


Structure describing an input sample to the library.


Each input sample is provided to BSEC as an element in a struct array of this type. Timestamps must be provided
in nanosecond resolution. Moreover, duplicate timestamps for subsequent samples are not allowed and will
results in an error code being returned from bsec_do_steps().


The meaning unit of the signal field are determined by the bsec_input_t::sensor_id field content. Possible
bsec_input_t::sensor_id values and and their meaning are described in bsec_physical_sensor_t.


See also


bsec_physical_sensor_t


**5.2.2** **Field Documentation**


**5.2.2.1** **sensor_id**

```
uint8_t bsec_input_t::sensor_id

```

Identifier of physical sensor.


See also


bsec_physical_sensor_t


**5.2.2.2** **signal**

```
float bsec_input_t::signal

```

Signal sample in the unit defined for the respective sensor_id.


See also


bsec_physical_sensor_t


**5.2.2.3** **signal_dimensions**

```
uint8_t bsec_input_t::signal_dimensions

```

Signal dimensions (reserved for future use, shall be set to 1)



Modifications reserved | Data subject to change without notice | Document number: BST-BME-Integration-Guide-AN011-321000 Date 2025-04-29
c Bosch Sensortec GmbH 2025. All rights reserved, also regarding any disposal, exploitation, reproduction, editing, distribution, as
well as in the event of applications for industrial property rights.



48


## Bosch Sensortec BSEC Integration Guide

**5.2.2.4** **time_stamp**

```
int64_t bsec_input_t::time_stamp

```

Time stamp in nanosecond resolution [ns].


Timestamps must be provided as non-repeating and increasing values. They can have their 0-points at system
start or at a defined wall-clock time (e.g., 01-Jan-1970 00:00:00)

## **5.3 bsec_output_t Struct Reference**


**Data Fields**


- int64_t time_stamp


_Time stamp in nanosecond resolution as provided as input [ns]._

- float signal


_Signal sample in the unit defined for the respective bsec_output_t::sensor_id._

- uint8_t signal_dimensions


_Signal dimensions (reserved for future use, shall be set to 1)_

- uint8_t sensor_id


_Identifier of virtual sensor._

- uint8_t accuracy


_Accuracy status 0-3._


**5.3.1** **Detailed Description**


Structure describing an output sample of the library.


Each output sample is returned from BSEC by populating the element of a struct array of this type. The contents
of the signal field is defined by the supplied bsec_output_t::sensor_id. Possible output bsec_output_t::sensor_id
values are defined in bsec_virtual_sensor_t.


See also


bsec_virtual_sensor_t


**5.3.2** **Field Documentation**


**5.3.2.1** **accuracy**

```
uint8_t bsec_output_t::accuracy

```

Accuracy status 0-3.


Some virtual sensors provide a value in the accuracy field. If this is the case, the meaning of the field is as follows:


|Name|Value|Accuracy description|
|---|---|---|
|UNRELIABLE|0|Sensor data is unreliable, the sensor must be calibrated|
|LOW_ACCURACY|1|Reliability of virtual sensor is low, sensor should be calibrated|



Modifications reserved | Data subject to change without notice | Document number: BST-BME-Integration-Guide-AN011-321000 Date 2025-04-29
c Bosch Sensortec GmbH 2025. All rights reserved, also regarding any disposal, exploitation, reproduction, editing, distribution, as
well as in the event of applications for industrial property rights.



49


## Bosch Sensortec BSEC Integration Guide

|Name|Value|Accuracy description|
|---|---|---|
|MEDIUM_ACCURACY|2|Medium reliability, sensor calibration or training may improve performance|
|HIGH_ACCURACY|3|High reliability|



For example:


- IAQ accuracy indicator will notify the user when she/he should initiate a calibration process. Calibration is
performed automatically in the background if the sensor is exposed to clean and polluted air for approximately
30 minutes each.

|Virtual sensor|Value|Accuracy description|
|---|---|---|
|IAQ|0|Stabilization / run-in ongoing|
||1|Low accuracy,to reach high accuracy(3),please expose sensor once to good air (e.g.<br>outdoor air) and bad air (e.g. box with exhaled breath) for auto-trimming|
||2|Medium accuracy: auto-trimming ongoing|
||3|High accuracy|



- Gas estimator accuracy indicator will notify the user when she/he gets valid gas prediction output.

|Virtual sensor|Value|Accuracy description|
|---|---|---|
|GAS_ESTIMATE_x_∗_|0|No valid gas estimate found - BSEC collecting gas features|
||3|Gas estimate prediction available|



_∗_ GAS_ESTIMATE_1, GAS_ESTIMATE_2, GAS_ESTIMATE_3, GAS_ESTIMATE_4


- Regression estimate accuracy will notify the user when she/he gets valid regression estimate output.

|Virtual sensor|Value|Accuracy description|
|---|---|---|
|REGRESSION_ESTIMATE_x_∗_|0|No valid regression estimate output found - BSEC collecting gas<br>features|
||2|Predicted regression estimate output is not within the value of the<br>label present in the training data|
||3|Predicted regression estimate output is within the the value of the<br>label present in the training data|



_∗_
REGRESSION_ESTIMATE_1, REGRESSION_ESTIMATE_2, REGRESSION_ESTIMATE_3, REGRESSION _←�_
_ESTIMATE_4


**5.3.2.2** **sensor_id**

```
uint8_t bsec_output_t::sensor_id

```

Identifier of virtual sensor.


See also


bsec_virtual_sensor_t



Modifications reserved | Data subject to change without notice | Document number: BST-BME-Integration-Guide-AN011-321000 Date 2025-04-29
c Bosch Sensortec GmbH 2025. All rights reserved, also regarding any disposal, exploitation, reproduction, editing, distribution, as
well as in the event of applications for industrial property rights.



50


## Bosch Sensortec BSEC Integration Guide

**5.3.2.3** **signal**

```
float bsec_output_t::signal

```

Signal sample in the unit defined for the respective bsec_output_t::sensor_id.


See also


bsec_virtual_sensor_t


**5.3.2.4** **signal_dimensions**

```
uint8_t bsec_output_t::signal_dimensions

```

Signal dimensions (reserved for future use, shall be set to 1)


**5.3.2.5** **time_stamp**

```
int64_t bsec_output_t::time_stamp

```

Time stamp in nanosecond resolution as provided as input [ns].

## **5.4 bsec_sensor_configuration_t Struct Reference**


**Data Fields**


- float sample_rate


_Sample rate of the virtual or physical sensor in Hertz [Hz]._

- uint8_t sensor_id


_Identifier of the virtual or physical sensor._


**5.4.1** **Detailed Description**


Structure describing sample rate of physical/virtual sensors.


This structure is used together with bsec_update_subscription() to enable BSEC outputs and to retrieve information
about the sample rates used for BSEC inputs.


**5.4.2** **Field Documentation**


**5.4.2.1** **sample_rate**

```
float bsec_sensor_configuration_t::sample_rate

```

Sample rate of the virtual or physical sensor in Hertz [Hz].


Only supported sample rates are allowed.



Modifications reserved | Data subject to change without notice | Document number: BST-BME-Integration-Guide-AN011-321000 Date 2025-04-29
c Bosch Sensortec GmbH 2025. All rights reserved, also regarding any disposal, exploitation, reproduction, editing, distribution, as
well as in the event of applications for industrial property rights.



51


## Bosch Sensortec BSEC Integration Guide

**5.4.2.2** **sensor_id**

```
uint8_t bsec_sensor_configuration_t::sensor_id

```

Identifier of the virtual or physical sensor.


The meaning of this field changes depending on whether the structs are as the requested_virtual_sensors
argument to bsec_update_subscription() or as the required_sensor_settings argument.


See also

|bsec_update_subscription() argument|sensor_id field interpretation|
|---|---|
|requested_virtual_sensors|bsec_virtual_sensor_t|
|required_sensor_settings|bsec_physical_sensor_t|



bsec_physical_sensor_t
bsec_virtual_sensor_t

## **5.5 bsec_version_t Struct Reference**


**Data Fields**


- uint8_t major


_Major version._

- uint8_t minor


_Minor version._

- uint8_t major_bugfix


_Major bug fix version._

- uint8_t minor_bugfix


_Minor bug fix version._


**5.5.1** **Detailed Description**


Structure containing the version information.


Please note that configuration and state strings are coded to a specific version and will not be accepted by other
versions of BSEC.


**5.5.2** **Field Documentation**


**5.5.2.1** **major**

```
uint8_t bsec_version_t::major

```

Major version.



Modifications reserved | Data subject to change without notice | Document number: BST-BME-Integration-Guide-AN011-321000 Date 2025-04-29
c Bosch Sensortec GmbH 2025. All rights reserved, also regarding any disposal, exploitation, reproduction, editing, distribution, as
well as in the event of applications for industrial property rights.



52


## Bosch Sensortec BSEC Integration Guide

**5.5.2.2** **major_bugfix**

```
uint8_t bsec_version_t::major_bugfix

```

Major bug fix version.


**5.5.2.3** **minor**

```
uint8_t bsec_version_t::minor

```

Minor version.


**5.5.2.4** **minor_bugfix**

```
uint8_t bsec_version_t::minor_bugfix

```

Minor bug fix version.


Modifications reserved | Data subject to change without notice | Document number: BST-BME-Integration-Guide-AN011-321000 Date 2025-04-29
c Bosch Sensortec GmbH 2025. All rights reserved, also regarding any disposal, exploitation, reproduction, editing, distribution, as
well as in the event of applications for industrial property rights.



53


