Bosch Sensortec



Bosch Sensortec GmbH

Gerhard-Kindler-Straße 9

72770 Reutlingen

Tel 07121 3535-900

www.bosch-sensortec.com


|Release Notes|Col2|
|---|---|
|Product name|BSEC|
|Compatible hardware|BME680, BME688 and BME690|
|Release version (number)|3.2.1.0|
|Date of release|28-04-2025|
|Name of release package|BSEC_3.2.1.0_Generic_Release_28042025|
|Release type (reason for<br>the release)|Website release of Version 3.2.1.0|













Registered Office: Kusterdingen, Registration Court: Stuttgart HRB 382674,
Ust.IdNr. DE 183276693 - Steuer-Nr. 99012/08040
Managing Director: Stefan Finkbeiner, Oliver Weiss
Bosch und die Bildmarke sind registrierte Marken der Robert Bosch GmbH, Stuttgart
Banking connection: Deutsche Bank (BLZ 600 700 70) Kto.-Nr. 1 655 448


Bosch Sensortec





Page 2 of 3




|Version history|Changes|
|---|---|
|BSEC 3.2.0.0|• <br>Included support for IAQ – ULP mode with reduced power<br>consumption and selectivity mode for BME690|
|BSEC 3.1.0.0|• <br>BME690 included with support for only IAQ – LP mode with<br>reduced power consumption<br>• <br>multi-instance interface made as default standard function<br>• <br>Updated example code|
|BSEC 2.6.1.0|• <br>Included a lesser memory footprint variant of BSEC static library<br>named ‘bsec_IAQ’ as part of the package which supports IAQ<br>feature only. Additionally, the BSEC variant ‘bsec_IAQ_Sel’ will<br>continue supporting either the IAQ feature or selectivity at a time.<br>• <br>Run in time improvement implemented for quicker sensor<br>stabilization after an off period or sleep mode.<br>• <br>Improved compensation implemented for influence of T and rH on<br>gas resistance enabling more reliable IAQ output.|
|BSEC 2.5.0.2|• <br>Included the Data Augmentation feature to optimize the sensor to<br>sensor deviation effects<br>• <br>Introduded the regression estimation feature to enable quantitative<br>output|
|BSEC 2.4.0.0|• <br>Multi instance interface support – BSEC will support multiple<br>sensors. Additional interface file ‘bsec_interface_multi.h’ added to<br>support multi instance APIs.<br>• <br>Unified static library to support sensor variants, Configuration files<br>offered separately for BME680 and BME688 sensors.|


Bosch Sensortec


Page 3 of 3


|Col1|• Reduced library size by optimizing configuration and state<br>properties for catering to multi instance support.|
|---|---|
|BSEC 2.2.0.0|• <br>configuration update.<br>• <br>IAQ algorithm improved w/r to interaction and performance by<br>optimized baseline adaptation. Accordingly, the IAQ adaptation<br>points have been updated to 50 & 200 for best user experience<br>(former versions used 25 & 250).<br>• <br>IAQ output available in continuous mode operation (ODR 1 Hz).<br>• <br>Temperature-Humidity compensation in IAQ output updated<br>(adopted from BSEC version 1.4.8.0).<br>• <br>Merged BSEC 1.x and BSEC 2.x (means BSEC 2.2.0.0 incl. full<br>functionality of BSEC 1.4.9.2).<br>• <br>Static code error/warning fixes.|
|BSEC 2.0.6.1|-/- (initial release)|


