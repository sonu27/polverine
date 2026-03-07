# BSEC Binary Size Information

**BESC version: 3.2.1.0**


**1.** **Platform Supported Currently**







|Platform|Compiler|TYPE|
|---|---|---|
|Cortex-M|Keil5 ARMCC|Cortex-M0, M0+, M3, M4, M4F, M7|
|Cortex-M|arm-none-eabi-gcc|Cortex-M0, M0+, M3, M33, M33F, M4, M4F, M7,<br>ARMv8-m|
|Cortex-A|arm-none-eabi-gcc|Cortex-A7, A73|
|AVR_8bit|Atmel Studio AVR-GCC|MegaAVR, XMEGA|
|AVR_32bit|Atmel Studio AVR-GCC|32-bit AVR UC3|
|ESP|xtensa-lx106-elf-gcc|ESP8266, ESP32, ESP32-S2, ESP32-S3|
|ESP|riscv32-esp-elf-gcc|ESP32-C2, ESP32-C3|
|MSP430|msp430-elf-gcc|MSP430|
|IAR|IAR compiler|Cortex-M0, M0+, M3, M4, M4F, M7|
|Raspberry pi|Arm-linux-gnueabihf-gcc|Pi 3 armv6, Pi 3 armv8-a|
|Raspberry pi|Aarch64-linux-gnu-gcc|Pi 4 armv8-a|
|Windows|TDM-GCC|x86, x64|
|Linux|GCC|x86, x64|


**2.** **Binary Size on different platform**




















|Platform Type|Compiler|ROM(.text+.data) in<br>bytes<br>IAQ_Sel/IAQ|RAM(.data+.bss) in<br>bytes<br>IAQ_Sel /IAQ|
|---|---|---|---|
|Cortex-M0|Keil5.29 ARMCC<br> <br>v5.29|29513/24021|3984/1384|
|Cortex-M0+|Cortex-M0+|29513/24021|3984/1384|
|Cortex-M3|Cortex-M3|28135/22829|3984/1384|
|Cortex-M4|Cortex-M4|28135/22829|3984/1384|
|Cortex-M4F|Cortex-M4F|30021/24389|3984/1384|
|Cortex-M7|Cortex-M7|28143/22841|3984/1384|
|Cortex-M0|arm-none-eabi-gcc<br> <br>v9.2.1|35694/28690|3984/1384|
|Cortex-M0+|Cortex-M0+|35694/28690|3984/1384|
|Cortex-M3|Cortex-M3|32550/26386|3984/1384|


|Cortex-M33|Col2|32570/26390|3984/1384|
|---|---|---|---|
|Cortex-M33F|Cortex-M33F|32910/25926|3984/1384|
|Cortex-M4|Cortex-M4|32506/26346|3984/1384|
|Cortex-M4F|Cortex-M4F|32998/25998|3984/1384|
|Cortex-M7|Cortex-M7|32914/26454|3984/1384|
|ARMv8|ARMv8|35338/28738|3984/1384|
|Cortex-A7|Cortex-A7|33406/26926|3984/1384|
|Cortex-A73|Cortex-A73|39026/31802|3992/1400|
|AVR8bit-MegaAVR|Atmel Studio AVR-GCC<br> <br>v7.0.2397|70410/55684|3912/1317|
|AVR8bit-XMEGA|AVR8bit-XMEGA|69228/54772|3912/1317|
|AVR32|AVR32|37178/30278|4536/1768|
|ESP32|xtensa-esp32-elf-gcc<br> <br>v4.8.5|37925/30439|3992/1400|
|ESP32-S2|<br>xtensa-esp32s2-elf-gcc<br> <br>v11.2.0|40378/32112|3992/1400|
|ESP32-S3|xtensa-esp32s3-elf<br> <br>v11.2.0|37575/29905|3992/1400|
|ESP32-C2/C3|riscv32-esp-elf-gcc<br> <br>v11.2.0|44898/36190|3992/1400|
|ESP8266|xtensa-lx106-elf-gcc<br> <br>v4.8.2|43026/34696|3992/1400|
|MSP430_GCC_OUT|<br>msp430-elf-gcc<br> <br>v8.3.1|54180/43354|3924/1330|
|PiThree_Armv6|<br>Arm-linux-gnueabihf-gcc<br> <br>v4.9.3|84516/68476|3992/1400|
|PiThree_Armv8|PiThree_Armv8|85144/69028|3992/1400|
|PiFour_Armv8|<br>Aarch64-linux-gnu-gcc<br> <br>V11.3|53170/43342|3992/1400|
|Cortex-M0|<br>IAR7<br> <br>v7.80.4.12462|32084/26046|3984/1384|
|Cortex-M0+|Cortex-M0+|32084/26046|3984/1384|
|Cortex-M3|Cortex-M3|31842/25948|3984/1384|
|Cortex-M4|Cortex-M4|31842/25948|3984/1384|
|Cortex-M4F|Cortex-M4F|32492/26574|3984/1384|
|Cortex-M7|Cortex-M7|31842/25948|3984/1384|
|Cortex-M0|IAR8<br> <br>V8.40.1.212|32352/26322|3984/1384|
|Cortex-M0+|Cortex-M0+|32352/26322|3984/1384|
|Cortex-M3|Cortex-M3|31536/25750|3984/1384|


|Cortex-M4|Col2|31536/25750|3984/1384|
|---|---|---|---|
|Cortex-M4F|Cortex-M4F|32286/26348|3984/1384|
|Cortex-M7|Cortex-M7|31536/25750|3984/1384|
|Windows_x64|TDM-GCC<br> <br>v5.3.0|54880/44676|4032/1408|
|Windows_x86|Windows_x86|52212/41884|4032/1408|
|Linux_m64|<br>GCC<br> <br>V11.4.0|61955/50713|4008/1400|
|Linux_m32|Linux_m32|74987/60166|3980/1364|


*Note:
1. ROM/RAM size is basic requirement of BSEC. Static Lib File size doesn’t count.
2. M4F/M33F means the MCU with FPU.


