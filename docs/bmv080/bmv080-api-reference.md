# BMV080 API Reference



---

# bmv080.h — Main API

BMV080 sensor driver functions.
[More...](#details)

`#include <stdint.h>`  
`#include "bmv080_defs.h"`

Include dependency graph for bmv080.h:

&lt;p&gt;&lt;b&gt;This browser is not able to show SVG: try Firefox, Chrome, Safari, or Opera instead.&lt;/b&gt;&lt;/p&gt;

[Go to the source code of this file.](bmv080_8h_source.html)

|  |  |
| --- | --- |
| Functions | |
| [bmv080\_status\_code\_t](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32c) | [bmv080\_open](bmv080_8h.html#a3ef39e1817fcbd5e2b8583f6d45bbc5f) ([bmv080\_handle\_t](bmv080__defs_8h.html#ae9764f1ba50176cb891a184a3125029c) \*handle, const [bmv080\_sercom\_handle\_t](bmv080__defs_8h.html#a2fa6a9cc0debc81a6f3ebe269457fb7e) sercom\_handle, const [bmv080\_callback\_read\_t](bmv080__defs_8h.html#a5c75eb216732f7d8a079df64a45f41ef) read, const [bmv080\_callback\_write\_t](bmv080__defs_8h.html#ace4139eb94c8b978a45b66f53f394178) write, const [bmv080\_callback\_delay\_t](bmv080__defs_8h.html#a8f224ce471255f2e011e1ddacc80aac2) delay\_ms) |
|  | Open a sensor unit by initializing a new handle. |
|  | |
| [bmv080\_status\_code\_t](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32c) | [bmv080\_get\_driver\_version](bmv080_8h.html#a59dfa271ea9b0c64f9eafd6846b6e7b6) (uint16\_t \*major, uint16\_t \*minor, uint16\_t \*patch, char git\_hash[12], int32\_t \*num\_commits\_ahead) |
|  | Get the version information of this sensor driver. |
|  | |
| [bmv080\_status\_code\_t](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32c) | [bmv080\_reset](bmv080_8h.html#a7f315d343e3d04dc1e2ea59a535e5ca8) (const [bmv080\_handle\_t](bmv080__defs_8h.html#ae9764f1ba50176cb891a184a3125029c) handle) |
|  | Reset a sensor unit including both hardware and software. |
|  | |
| [bmv080\_status\_code\_t](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32c) | [bmv080\_get\_parameter](bmv080_8h.html#ab618e6c8df10e05202441ccb219919e9) (const [bmv080\_handle\_t](bmv080__defs_8h.html#ae9764f1ba50176cb891a184a3125029c) handle, const char \*key, void \*value) |
|  | Get a parameter. |
|  | |
| [bmv080\_status\_code\_t](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32c) | [bmv080\_set\_parameter](bmv080_8h.html#a373060d6a647c56d36d1d2deff8ad97f) (const [bmv080\_handle\_t](bmv080__defs_8h.html#ae9764f1ba50176cb891a184a3125029c) handle, const char \*key, const void \*value) |
|  | Set a parameter. |
|  | |
| [bmv080\_status\_code\_t](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32c) | [bmv080\_get\_sensor\_id](bmv080_8h.html#a37883c1c030b6c20d9e8404403d3ae51) (const [bmv080\_handle\_t](bmv080__defs_8h.html#ae9764f1ba50176cb891a184a3125029c) handle, char id[13]) |
|  | Get the sensor ID of a sensor unit. |
|  | |
| [bmv080\_status\_code\_t](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32c) | [bmv080\_start\_continuous\_measurement](bmv080_8h.html#a2dc111d3b517f284b7044757be86f799) (const [bmv080\_handle\_t](bmv080__defs_8h.html#ae9764f1ba50176cb891a184a3125029c) handle) |
|  | Start particle measurement in continuous mode. |
|  | |
| [bmv080\_status\_code\_t](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32c) | [bmv080\_start\_duty\_cycling\_measurement](bmv080_8h.html#a1c6028f83de7df5b510088358940dffa) (const [bmv080\_handle\_t](bmv080__defs_8h.html#ae9764f1ba50176cb891a184a3125029c) handle, const [bmv080\_callback\_tick\_t](bmv080__defs_8h.html#a081caa48b09b919a0aa30a74aaf6c6a8) get\_tick\_ms, [bmv080\_duty\_cycling\_mode\_t](bmv080__defs_8h.html#abec9248d3a867f49c03e5531add15d9a) duty\_cycling\_mode) |
|  | Start particle measurement in duty cycling mode. |
|  | |
| [bmv080\_status\_code\_t](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32c) | [bmv080\_serve\_interrupt](bmv080_8h.html#a288b1f6f41c96efc5a481fd61c4a2572) (const [bmv080\_handle\_t](bmv080__defs_8h.html#ae9764f1ba50176cb891a184a3125029c) handle, [bmv080\_callback\_data\_ready\_t](bmv080__defs_8h.html#a475c5833142f0e4a7367b86f7f8d4ed0) data\_ready, void \*callback\_parameters) |
|  | Serve an interrupt using a callback function. |
|  | |
| [bmv080\_status\_code\_t](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32c) | [bmv080\_stop\_measurement](bmv080_8h.html#aeb9fa87938812b3bea75166723a929ac) (const [bmv080\_handle\_t](bmv080__defs_8h.html#ae9764f1ba50176cb891a184a3125029c) handle) |
|  | Stop particle measurement. |
|  | |
| [bmv080\_status\_code\_t](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32c) | [bmv080\_close](bmv080_8h.html#a89e3e1fa71ddd186ff16baa01b2867be) ([bmv080\_handle\_t](bmv080__defs_8h.html#ae9764f1ba50176cb891a184a3125029c) \*handle) |
|  | Close the sensor unit. |
|  | |

## Detailed Description

BMV080 sensor driver functions.

Copyright (C) Bosch Sensortec GmbH. All Rights Reserved. Confidential.

<BST\_disclaimer>

## Function Documentation

## [◆](#a89e3e1fa71ddd186ff16baa01b2867be)bmv080\_close()

|  |  |  |  |  |  |
| --- | --- | --- | --- | --- | --- |
| [bmv080\_status\_code\_t](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32c) bmv080\_close | ( | [bmv080\_handle\_t](bmv080__defs_8h.html#ae9764f1ba50176cb891a184a3125029c) \* | *handle* | ) |  |

Close the sensor unit.

Precondition
:   Must be called last in order to destroy the *handle* created by *bmv080\_open*.

Parameters
:   |  |  |  |
    | --- | --- | --- |
    | [in] | handle | : Unique handle for a sensor unit. |

Returns
:   E\_BMV080\_OK if successful, otherwise the return value is a BMV080 status code.

## [◆](#a59dfa271ea9b0c64f9eafd6846b6e7b6)bmv080\_get\_driver\_version()

|  |  |  |  |
| --- | --- | --- | --- |
| [bmv080\_status\_code\_t](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32c) bmv080\_get\_driver\_version | ( | uint16\_t \* | *major*, |
|  |  | uint16\_t \* | *minor*, |
|  |  | uint16\_t \* | *patch*, |
|  |  | char | *git\_hash*[12], |
|  |  | int32\_t \* | *num\_commits\_ahead* |
|  | ) |  |  |

Get the version information of this sensor driver.

The version numbers follow [semantic versioning](https://semver.org/#semantic-versioning-200).

Precondition
:   No preconditions apply, i.e. no connected sensor unit or sensor driver *handle* is required.

Parameters
:   |  |  |  |
    | --- | --- | --- |
    | [out] | major | : Major version number. |
    | [out] | minor | : Minor version number. |
    | [out] | patch | : Patch version number. |
    | [out] | git\_hash | : Character array of 13 elements, for internal use only. |
    | [out] | num\_commits\_ahead | : For internal use only. |

Returns
:   E\_BMV080\_OK if successful, otherwise the return value is a BMV080 status code.

## [◆](#ab618e6c8df10e05202441ccb219919e9)bmv080\_get\_parameter()

|  |  |  |  |
| --- | --- | --- | --- |
| [bmv080\_status\_code\_t](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32c) bmv080\_get\_parameter | ( | const [bmv080\_handle\_t](bmv080__defs_8h.html#ae9764f1ba50176cb891a184a3125029c) | *handle*, |
|  |  | const char \* | *key*, |
|  |  | void \* | *value* |
|  | ) |  |  |

Get a parameter.

Table parameter lists the available parameters with their keys and the expected types. This function can be called multiple times and is optional.

Table parameter : Available parameters

| Key | Type | Unit | Default | Details |
| "error\_logging" | bool |  | false | Set if error log files are created.   Disabled if *false*, enabled if *true*. |
| "meta\_data\_logging" | bool |  | false | Set if meta data log files are created.   Disabled if *false*, enabled if *true*. |
| "path" | char\* |  | "" (empty) | Path to directory where log files are written.   The maximum allowed length is 256 characters, which must be pre-allocated.   File logging is not available on embedded platforms (e.g. ARM Cortex-M).   This is applicable to all parameters with the suffix "\_logging" in its name. |
| "pm\_logging" | bool |  | false | Set if particulate matter output log files are created.   Disabled if *false*, enabled if *true*. |
| "integration\_time" | float | s | 10 | Measurement window.   In duty cycling mode, this measurement window is also the sensor ON time. |
| "duty\_cycling\_period" | uint16\_t | s | 30 | Duty cycling period (sum of integration time and sensor OFF / sleep time).   This must be greater than integration time by at least 2 seconds. |
| "do\_obstruction\_detection" | bool |  | true | Set if obstruction detection feature is enabled. |
| "do\_vibration\_filtering" | bool |  | false | Set if vibration filter is enabled. |
| "measurement\_algorithm" | bmv080\_measurement\_algorithm\_t |  | E\_BMV080\_MEASUREMENT\_ALGORITHM\_HIGH\_PRECISION (3) | Selection of measurement algorithm based on the   use case, as defined by the type bmv080\_measurement\_algorithm\_t,   in [bmv080\_defs.h](bmv080__defs_8h.html "BMV080 sensor driver definitions."). For a duty cycling measurement, this parameter is   fixed to E\_BMV080\_MEASUREMENT\_ALGORITHM\_FAST\_RESPONSE. |

Precondition
:   A valid *handle* generated by *bmv080\_open* is required.

Parameters
:   |  |  |  |
    | --- | --- | --- |
    | [in] | handle | : Unique handle for a sensor unit. |
    | [in] | key | : Key of the parameter to get. Valid keys are listed in table parameter. |
    | [out] | value | : Value of the parameter to get of the in table parameter listed type casted as void-pointer. |

Returns
:   E\_BMV080\_OK if successful, otherwise the return value is a BMV080 status code.

## [◆](#a37883c1c030b6c20d9e8404403d3ae51)bmv080\_get\_sensor\_id()

|  |  |  |  |
| --- | --- | --- | --- |
| [bmv080\_status\_code\_t](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32c) bmv080\_get\_sensor\_id | ( | const [bmv080\_handle\_t](bmv080__defs_8h.html#ae9764f1ba50176cb891a184a3125029c) | *handle*, |
|  |  | char | *id*[13] |
|  | ) |  |  |

Get the sensor ID of a sensor unit.

Precondition
:   A valid *handle* generated by *bmv080\_open* is required.
:   The char array *id* must have been allocated by the application with a size of 13 elements.

Parameters
:   |  |  |  |
    | --- | --- | --- |
    | [in] | handle | : Unique handle for a sensor unit. |
    | [out] | id | : Character array of 13 elements. |

Returns
:   E\_BMV080\_OK if successful, otherwise the return value is a BMV080 status code.

## [◆](#a3ef39e1817fcbd5e2b8583f6d45bbc5f)bmv080\_open()

|  |  |  |  |
| --- | --- | --- | --- |
| [bmv080\_status\_code\_t](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32c) bmv080\_open | ( | [bmv080\_handle\_t](bmv080__defs_8h.html#ae9764f1ba50176cb891a184a3125029c) \* | *handle*, |
|  |  | const [bmv080\_sercom\_handle\_t](bmv080__defs_8h.html#a2fa6a9cc0debc81a6f3ebe269457fb7e) | *sercom\_handle*, |
|  |  | const [bmv080\_callback\_read\_t](bmv080__defs_8h.html#a5c75eb216732f7d8a079df64a45f41ef) | *read*, |
|  |  | const [bmv080\_callback\_write\_t](bmv080__defs_8h.html#ace4139eb94c8b978a45b66f53f394178) | *write*, |
|  |  | const [bmv080\_callback\_delay\_t](bmv080__defs_8h.html#a8f224ce471255f2e011e1ddacc80aac2) | *delay\_ms* |
|  | ) |  |  |

Open a sensor unit by initializing a new handle.

Precondition
:   Must be called first in order to create the *handle* required by other functions.

Postcondition
:   The *handle* must be destroyed via *bmv080\_close*.

Parameters
:   |  |  |  |
    | --- | --- | --- |
    | [out] | handle | : Unique handle for a sensor unit. |
    | [in] | sercom\_handle | : Unique handle for a serial communication interface. |
    | [in] | read | : Function pointer for reading from an endpoint. |
    | [in] | write | : Function pointer for writing to an endpoint. |
    | [in] | delay\_ms | : Function pointer for a delay in milliseconds. |

Returns
:   E\_BMV080\_OK if successful, otherwise the return value is a BMV080 status code.

## [◆](#a7f315d343e3d04dc1e2ea59a535e5ca8)bmv080\_reset()

|  |  |  |  |  |  |
| --- | --- | --- | --- | --- | --- |
| [bmv080\_status\_code\_t](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32c) bmv080\_reset | ( | const [bmv080\_handle\_t](bmv080__defs_8h.html#ae9764f1ba50176cb891a184a3125029c) | *handle* | ) |  |

Reset a sensor unit including both hardware and software.

Precondition
:   A valid *handle* generated by *bmv080\_open* is required.

Postcondition
:   Any parameter changed through *bmv080\_set\_parameter* is reverted back to its default.

Parameters
:   |  |  |  |
    | --- | --- | --- |
    | [in] | handle | : Unique handle for a sensor unit. |

Returns
:   E\_BMV080\_OK if successful, otherwise the return value is a BMV080 status code.

## [◆](#a288b1f6f41c96efc5a481fd61c4a2572)bmv080\_serve\_interrupt()

|  |  |  |  |
| --- | --- | --- | --- |
| [bmv080\_status\_code\_t](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32c) bmv080\_serve\_interrupt | ( | const [bmv080\_handle\_t](bmv080__defs_8h.html#ae9764f1ba50176cb891a184a3125029c) | *handle*, |
|  |  | [bmv080\_callback\_data\_ready\_t](bmv080__defs_8h.html#a475c5833142f0e4a7367b86f7f8d4ed0) | *data\_ready*, |
|  |  | void \* | *callback\_parameters* |
|  | ) |  |  |

Serve an interrupt using a callback function.

Precondition
:   A valid *handle* generated by *bmv080\_open* is required and the sensor unit entered measurement mode via *bmv080\_start\_continuous\_measurement* or *bmv080\_start\_duty\_cycling\_measurement*.
:   The application can call this function every time the sensor or the application triggers an interrupt. This interrupt may be a type of a software timeout (e.g. at least once per second) or a hardware interrupt (e.g. FIFO watermark exceeded).
:   This function tolerates very frequent or random calls to a certain extent. However, not calling *bmv080\_serve\_interrupt* over longer periods might impair the measurement mode since events might be missed.
:   In continuous mode, new sensor output is available every second Hence, *data\_ready* is called once every second of the sensor unit's uptime. For example, if *bmv080\_serve\_interrupt* is called 5 seconds after *bmv080\_start\_continuous\_measurement*, the callback function *data\_ready* would subsequently be called 5 times to report the collected sensor output of each period.
:   In duty cycling mode, new sensor output is available every duty cycling period. Hence, *data\_ready* is called at the end of the integration time, once every duty cycling period. Note, *bmv080\_serve\_interrupt* must be called at least once per second.
:   The recommendation is to call this function based on hardware interrupts.
:   The callback function *bmv080\_callback\_data\_ready\_t* and the according *callback\_parameter* are provided by the caller application.

Postcondition
:   Interrupt condition is served, e.g. FIFO is fetched or ASIC condition is solved

Parameters
:   |  |  |  |
    | --- | --- | --- |
    | [in] | handle | : Unique handle for a sensor unit. |
    | [in] | data\_ready | : User defined callback function which is called when sensor output is available. |
    | [in] | callback\_parameters | : User defined parameters to be passed to the callback function. |

Returns
:   E\_BMV080\_OK if successful, otherwise the return value is a BMV080 status code.

## [◆](#a373060d6a647c56d36d1d2deff8ad97f)bmv080\_set\_parameter()

|  |  |  |  |
| --- | --- | --- | --- |
| [bmv080\_status\_code\_t](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32c) bmv080\_set\_parameter | ( | const [bmv080\_handle\_t](bmv080__defs_8h.html#ae9764f1ba50176cb891a184a3125029c) | *handle*, |
|  |  | const char \* | *key*, |
|  |  | const void \* | *value* |
|  | ) |  |  |

Set a parameter.

Table parameter lists the available parameters with their keys and the expected types. This function can be called multiple times and is optional.

Table parameter : Available parameters

| Key | Type | Unit | Default | Details |
| "error\_logging" | bool |  | false | Set if error log files are created.   Disabled if *false*, enabled if *true*. |
| "meta\_data\_logging" | bool |  | false | Set if meta data log files are created.   Disabled if *false*, enabled if *true*. |
| "path" | char\* |  | "" (empty) | Path to directory where log files are written.   The path length must be less than 256 characters.   Relative and absolute paths with separators ( / ) or ( \ ) are supported.   ( . ) indicates the working directory and ( .. ) the parent directory.   File logging is not available on embedded platforms (e.g. ARM Cortex-M).   This is applicable to all parameters with the suffix "\_logging" in its name. |
| "pm\_logging" | bool |  | false | Set if particulate matter output log files are created.   Disabled if *false*, enabled if *true*. |
| "integration\_time" | float | s | 10 | Measurement window.   In duty cycling mode, this measurement window is also the sensor ON time. |
| "duty\_cycling\_period" | uint16\_t | s | 30 | Duty cycling period (sum of integration time and sensor OFF / sleep time).   This must be greater than integration time by at least 2 seconds. |
| "do\_obstruction\_detection" | bool |  | true | Set if obstruction detection feature is enabled. |
| "do\_vibration\_filtering" | bool |  | false | Set if vibration filter is enabled. |
| "measurement\_algorithm" | bmv080\_measurement\_algorithm\_t |  | E\_BMV080\_MEASUREMENT\_ALGORITHM\_HIGH\_PRECISION (3) | Selection of measurement algorithm based on the   use case, as defined by the type bmv080\_measurement\_algorithm\_t,   in [bmv080\_defs.h](bmv080__defs_8h.html "BMV080 sensor driver definitions."). For a duty cycling measurement, this parameter is   fixed to E\_BMV080\_MEASUREMENT\_ALGORITHM\_FAST\_RESPONSE. |

Precondition
:   A valid *handle* generated by *bmv080\_open* is required.
:   This function must be called before *bmv080\_start\_continuous\_measurement* or *bmv080\_start\_duty\_cycling\_measurement* in order to apply the parameter in the configuration of particle measurement.

Parameters
:   |  |  |  |
    | --- | --- | --- |
    | [in] | handle | : Unique handle for a sensor unit. |
    | [in] | key | : Key of the parameter to set. Valid keys are listed in table parameter. |
    | [in] | value | : Value of the parameter to set of the in table parameter listed type casted as void-pointer. |

Returns
:   E\_BMV080\_OK if successful, otherwise the return value is a BMV080 status code.

## [◆](#a2dc111d3b517f284b7044757be86f799)bmv080\_start\_continuous\_measurement()

|  |  |  |  |  |  |
| --- | --- | --- | --- | --- | --- |
| [bmv080\_status\_code\_t](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32c) bmv080\_start\_continuous\_measurement | ( | const [bmv080\_handle\_t](bmv080__defs_8h.html#ae9764f1ba50176cb891a184a3125029c) | *handle* | ) |  |

Start particle measurement in continuous mode.

Precondition
:   A valid *handle* generated by *bmv080\_open* is required.
:   Optionally, parameters can be set by preceding *bmv080\_set\_parameter* calls.

Postcondition
:   The measurement mode increases energy consumption.
:   The sensor unit stays in measurement mode until *bmv080\_stop\_measurement* is called.
:   In measurement mode, *bmv080\_serve\_interrupt* should be called regularly.

Parameters
:   |  |  |  |
    | --- | --- | --- |
    | [in] | handle | : Unique handle for a sensor unit. |

Returns
:   E\_BMV080\_OK if successful, otherwise the return value is a BMV080 status code.

## [◆](#a1c6028f83de7df5b510088358940dffa)bmv080\_start\_duty\_cycling\_measurement()

|  |  |  |  |
| --- | --- | --- | --- |
| [bmv080\_status\_code\_t](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32c) bmv080\_start\_duty\_cycling\_measurement | ( | const [bmv080\_handle\_t](bmv080__defs_8h.html#ae9764f1ba50176cb891a184a3125029c) | *handle*, |
|  |  | const [bmv080\_callback\_tick\_t](bmv080__defs_8h.html#a081caa48b09b919a0aa30a74aaf6c6a8) | *get\_tick\_ms*, |
|  |  | [bmv080\_duty\_cycling\_mode\_t](bmv080__defs_8h.html#abec9248d3a867f49c03e5531add15d9a) | *duty\_cycling\_mode* |
|  | ) |  |  |

Start particle measurement in duty cycling mode.

Precondition
:   A valid *handle* generated by *bmv080\_open* is required.
:   Optionally, duty cycling parameters (integration\_time and duty\_cycling\_period) can be set by preceding *bmv080\_set\_parameter* calls.

Postcondition
:   The sensor unit stays in duty cycling mode until *bmv080\_stop\_measurement* is called.
:   In measurement mode, *bmv080\_serve\_interrupt* should be called regularly.

Parameters
:   |  |  |  |
    | --- | --- | --- |
    | [in] | handle | : Unique handle for a sensor unit. |
    | [in] | get\_tick\_ms | : Function pointer that provides a tick value in milliseconds (based on the host system clock). |
    | [in] | duty\_cycling\_mode | : Mode of performing the duty cycling measurement. |

Returns
:   E\_BMV080\_OK if successful, otherwise the return value is a BMV080 status code.

## [◆](#aeb9fa87938812b3bea75166723a929ac)bmv080\_stop\_measurement()

|  |  |  |  |  |  |
| --- | --- | --- | --- | --- | --- |
| [bmv080\_status\_code\_t](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32c) bmv080\_stop\_measurement | ( | const [bmv080\_handle\_t](bmv080__defs_8h.html#ae9764f1ba50176cb891a184a3125029c) | *handle* | ) |  |

Stop particle measurement.

Precondition
:   A valid *handle* generated by *bmv080\_open* is required and the sensor unit entered measurement mode via *bmv080\_start\_continuous\_measurement* or *bmv080\_start\_duty\_cycling\_measurement*.
:   Must be called at the end of a data acquisition cycle to ensure that the sensor unit is ready for the next measurement cycle.

Parameters
:   |  |  |  |
    | --- | --- | --- |
    | [in] | handle | : Unique handle for a sensor unit. |

Returns
:   E\_BMV080\_OK if successful, otherwise the return value is a BMV080 status code.

---

# bmv080_defs.h — Definitions

BMV080 sensor driver definitions.
[More...](#details)

`#include <stdint.h>`  
`#include <stdbool.h>`

Include dependency graph for bmv080\_defs.h:

&lt;p&gt;&lt;b&gt;This browser is not able to show SVG: try Firefox, Chrome, Safari, or Opera instead.&lt;/b&gt;&lt;/p&gt;

This graph shows which files directly or indirectly include this file:

&lt;p&gt;&lt;b&gt;This browser is not able to show SVG: try Firefox, Chrome, Safari, or Opera instead.&lt;/b&gt;&lt;/p&gt;

[Go to the source code of this file.](bmv080__defs_8h_source.html)

|  |  |
| --- | --- |
| Classes | |
| struct | [bmv080\_output\_t](structbmv080__output__t.html) |
|  | Output structure which is updated by bmv080\_serve\_interrupt when sensor output is available. [More...](structbmv080__output__t.html#details) |
|  | |

|  |  |
| --- | --- |
| Typedefs | |
| typedef void \* | [bmv080\_handle\_t](bmv080__defs_8h.html#ae9764f1ba50176cb891a184a3125029c) |
|  | Unique handle for a sensor unit. |
|  | |
| typedef void \* | [bmv080\_sercom\_handle\_t](bmv080__defs_8h.html#a2fa6a9cc0debc81a6f3ebe269457fb7e) |
|  | Unique handle for a serial communication, i.e. the hardware connection to the sensor unit. |
|  | |
| typedef int8\_t(\* | [bmv080\_callback\_read\_t](bmv080__defs_8h.html#a5c75eb216732f7d8a079df64a45f41ef)) ([bmv080\_sercom\_handle\_t](bmv080__defs_8h.html#a2fa6a9cc0debc81a6f3ebe269457fb7e) sercom\_handle, uint16\_t header, uint16\_t \*payload, uint16\_t payload\_length) |
|  | Function pointer for reading an array of *payload\_length* words of 16 bit *payload*. |
|  | |
| typedef int8\_t(\* | [bmv080\_callback\_write\_t](bmv080__defs_8h.html#ace4139eb94c8b978a45b66f53f394178)) ([bmv080\_sercom\_handle\_t](bmv080__defs_8h.html#a2fa6a9cc0debc81a6f3ebe269457fb7e) sercom\_handle, uint16\_t header, const uint16\_t \*payload, uint16\_t payload\_length) |
|  | Function pointer for writing an array of *payload\_length* words of 16 bit *payload*. |
|  | |
| typedef int8\_t(\* | [bmv080\_callback\_delay\_t](bmv080__defs_8h.html#a8f224ce471255f2e011e1ddacc80aac2)) (uint32\_t duration\_in\_ms) |
|  | Function pointer for executing a software delay operation. |
|  | |
| typedef uint32\_t(\* | [bmv080\_callback\_tick\_t](bmv080__defs_8h.html#a081caa48b09b919a0aa30a74aaf6c6a8)) (void) |
|  | Function pointer for getting a tick value in milliseconds (based on the host system clock). |
|  | |
| typedef void(\* | [bmv080\_callback\_data\_ready\_t](bmv080__defs_8h.html#a475c5833142f0e4a7367b86f7f8d4ed0)) ([bmv080\_output\_t](structbmv080__output__t.html) bmv080\_output, void \*callback\_parameters) |
|  | Function pointer for handling the sensor's output information. |
|  | |

|  |  |
| --- | --- |
| Enumerations | |
| enum | [bmv080\_status\_code\_t](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32c) {     [E\_BMV080\_OK](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca2f4eec048a3f43d9450e88c5b0748072) = 0 , [E\_BMV080\_WARNING\_INVALID\_REG\_READ](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca56923d567ccb5649dc10152def6ca955) = 1 , [E\_BMV080\_WARNING\_INVALID\_REG\_WRITE](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca200f29551e6593be1c39adeb8df2d9ed) = 2 , [E\_BMV080\_WARNING\_FIFO\_READ](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32cab119dafb57ee1688a59007d91116ff5d) = 3 ,     [E\_BMV080\_WARNING\_FIFO\_EVENTS\_OVERFLOW](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32cad5301169eb0d2b44e5f2bf40e31b9b14) = 4 , [E\_BMV080\_WARNING\_FIFO\_SW\_BUFFER\_SIZE](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca190ebe9aa41eb7da6a8d6c22b920ac05) = 208 , [E\_BMV080\_WARNING\_FIFO\_HW\_BUFFER\_SIZE](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca6ac4ee65b9c47dc4bb34835211983417) = 209 , [E\_BMV080\_ERROR\_NULLPTR](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca3bb66b04f6485a8c00f6a81a2eb7bc7b) = 100 ,     [E\_BMV080\_ERROR\_REG\_ADDR](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca4e0bd18e96843d76e8cdda21a2de7b76) = 101 , [E\_BMV080\_ERROR\_PARAM\_LOCKED](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32cafe9373ec575e202702de6a3fcf9d8c83) = 179 , [E\_BMV080\_ERROR\_PARAM\_INVALID](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca2ab99cada049f34d0cf5b7533addc2cd) = 115 , [E\_BMV080\_ERROR\_PARAM\_INVALID\_CHANNEL](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca687b7bf8eaaaf7f3f28d11e2a1c94989) = 102 ,     [E\_BMV080\_ERROR\_PARAM\_INVALID\_VALUE](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca9ea380ebf40acf7eed56a6be7f39ae5e) = 123 , [E\_BMV080\_ERROR\_PARAM\_INVALID\_INTERNAL\_CONFIG](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca7df62706c3bd810bd5f35af54a89560f) = 104 , [E\_BMV080\_ERROR\_PRECONDITION\_UNSATISFIED](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca9015d333b71a5e818a792fd21ad72771) = 180 , [E\_BMV080\_ERROR\_HW\_READ](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca5c8000c75af910518668a7d8fdcb1637) = 105 ,     [E\_BMV080\_ERROR\_HW\_WRITE](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32caa9493cfddb4df8beeb17e68a796932f3) = 106 , [E\_BMV080\_ERROR\_MISMATCH\_CHIP\_ID](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32caf49be65624464077afdc92cb0d66b629) = 107 , [E\_BMV080\_ERROR\_MISMATCH\_REG\_VALUE](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca3c5fba4a1d8c7b1cbfa6443ed9b309f7) = 160 , [E\_BMV080\_ERROR\_OPERATION\_MODE\_INVALID](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32cac05ecebcafef6f39755dd08dc593a1b6) = 116 ,     [E\_BMV080\_ERROR\_OPERATION\_MODE\_CHANGE](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca746bd0b9b4ce8edbb6850add461b2eaf) = 113 , [E\_BMV080\_ERROR\_OPERATION\_MODE\_CHANNELS\_OUT\_OF\_SYNC](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32cadf70756557523d32c909ed08992253c9) = 114 , [E\_BMV080\_ERROR\_ASIC\_NOT\_CONFIGURED](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32cacf4a7de4e5a4d82a7d393c087a3253ea) = 157 , [E\_BMV080\_ERROR\_MEM\_READ](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca5cef629802b3f13449bc0549ccfd782c) = 133 ,     [E\_BMV080\_ERROR\_MEM\_ADDRESS](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32cad5f84195aaa7a88861f8b844023c4601) = 135 , [E\_BMV080\_ERROR\_MEM\_CMD](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca1ec0fcb468962dca1148a8d1b1979c52) = 136 , [E\_BMV080\_ERROR\_MEM\_TIMEOUT](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca37d8d9a4c44be5d3fbc05a4caa882028) = 137 , [E\_BMV080\_ERROR\_MEM\_INVALID](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca32f0199be92c5ca980cbabcf4fecc4f8) = 138 ,     [E\_BMV080\_ERROR\_MEM\_OBSOLETE](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32cab71b0696fb0b9acff31182239f974efb) = 139 , [E\_BMV080\_ERROR\_MEM\_OPERATION\_MODE](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32caa95866ccf2f3f9539bc42d9a12ef9956) = 140 , [E\_BMV080\_ERROR\_MEM\_DATA\_INTEGRITY](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32caea343d266ee58f0b611fb4a182c8eb79) = 153 , [E\_BMV080\_ERROR\_MEM\_DATA\_INTEGRITY\_INTERNAL\_TEST\_1](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32cab45848a84df902d0b61db8d8bb1c2c37) = 154 ,     [E\_BMV080\_ERROR\_MEM\_INTERNAL\_TEST\_1](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32caa812a4c231c6fe41adfe6b8fba2dc161) = 156 , [E\_BMV080\_ERROR\_MEM\_DATA\_INTEGRITY\_INTERNAL\_TEST\_2](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca076021ff65421933aeea8713a178d979) = 159 , [E\_BMV080\_ERROR\_MEM\_INTERNAL\_TEST\_2](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca0f911df2c4fdfe7afd9ff85a331fb987) = 181 , [E\_BMV080\_ERROR\_FIFO\_FORMAT](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca5fb121441ab88e20f1788de1170138ac) = 210 ,     [E\_BMV080\_ERROR\_FIFO\_EVENTS\_COUNT\_SATURATED](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32cadf0876d44c6fba6aaf1739ae97791fea) = 213 , [E\_BMV080\_ERROR\_FIFO\_UNAVAILABLE](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32cabb17558222333339ee0e44bce4a91c12) = 174 , [E\_BMV080\_ERROR\_FIFO\_EVENTS\_COUNT\_DIFF](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca9f8b9b926d8a9c8e7dddb858930105f4) = 214 , [E\_BMV080\_ERROR\_SYNC\_COMM](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca8276fd5f19f7de8e521ce24bbeb03ffc) = 161 ,     [E\_BMV080\_ERROR\_SYNC\_CTRL](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca3cc7c0ffab613267fabbdc03e68780d6) = 162 , [E\_BMV080\_ERROR\_SYNC\_MEAS](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca83018de43aedcc99e5f2ce56f82457c6) = 163 , [E\_BMV080\_ERROR\_SYNC\_LOCKED](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32cab20ecf13623e0bff95e54ebfe9e9f6de) = 164 , [E\_BMV080\_ERROR\_DC\_CANCEL\_RANGE](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca6a701954c897f9ebcc5bd85ba5797dc4) = 165 ,     [E\_BMV080\_ERROR\_DC\_ESTIM\_RANGE](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32cae1d33d92f69219a0653e64860b3aebd5) = 166 , [E\_BMV080\_ERROR\_LPWR\_T](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca605b7f2aa57104f517a4b1a61ea0ae9a) = 167 , [E\_BMV080\_ERROR\_LPWR\_RANGE](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32cac28873af9088fba86190b3a0e796102f) = 168 , [E\_BMV080\_ERROR\_POWER\_DOMAIN](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32cab3320cd0a26869758245fb87b74df0e6) = 169 ,     [E\_BMV080\_ERROR\_HEADROOM\_VDDL](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca74b08440bc167ea6958cc05b12339889) = 170 , [E\_BMV080\_ERROR\_HEADROOM\_LDV\_OUTPUT](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca3a534bb4242223d8deae0e7c640b27e1) = 171 , [E\_BMV080\_ERROR\_HEADROOM\_LDV\_REF](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca6e1800a56e737a0ebe7d2bc68e3141d3) = 172 , [E\_BMV080\_ERROR\_HEADROOM\_INTERNAL](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32caafa2647a89a75f86f00951b484bf0040) = 173 ,     [E\_BMV080\_ERROR\_SAFETY\_PRECAUTION](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca68ce56d97eb53326fce3bb5115739ec6) = 120 , [E\_BMV080\_ERROR\_TIMESTAMP\_DIFFERENCE](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca458124171e6edf08f3eb5cfc3946cb3f) = 211 , [E\_BMV080\_ERROR\_TIMESTAMP\_OVERFLOW](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32cab5eaa6476a6ad24f932e0d74255c0e15) = 212 , [E\_BMV080\_ERROR\_LIB\_VERSION\_INCOMPATIBLE](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32caae201e2e4d77b93e71be18762d8c8180) = 300 ,     [E\_BMV080\_ERROR\_INTERNAL\_PARAMETER\_VERSION\_INVALID](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32cab7dcf7bd5937d3e791c561f89946ba12) = 301 , [E\_BMV080\_ERROR\_INTERNAL\_PARAMETER\_INDEX\_INVALID](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca35558e4dae25b883c843879c4fb40f36) = 302 , [E\_BMV080\_ERROR\_MEMORY\_ALLOCATION](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca4e44966da155b30d53f0e274d5afd423) = 403 , [E\_BMV080\_ERROR\_CALLBACK\_DELAY](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca7a89d1728e4defb6a2ea6ec1fa6ae3cf) = 303 ,     [E\_BMV080\_ERROR\_INCOMPATIBLE\_SENSOR\_HW](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca94e19808553823ee0e3b2e7e70f20619) = 418   } |
|  | Status codes returned by the BMV080 sensor driver. [More...](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32c) |
|  | |
| enum | [bmv080\_duty\_cycling\_mode\_t](bmv080__defs_8h.html#abec9248d3a867f49c03e5531add15d9a) { [E\_BMV080\_DUTY\_CYCLING\_MODE\_0](bmv080__defs_8h.html#abec9248d3a867f49c03e5531add15d9aa3a049126ab19c5958c78f417bf32c5a2) = 0 } |
|  | Modes of performing a duty cycling measurement. [More...](bmv080__defs_8h.html#abec9248d3a867f49c03e5531add15d9a) |
|  | |
| enum | [bmv080\_measurement\_algorithm\_t](bmv080__defs_8h.html#adb54025c7d5f35df05910713d5c22cf8) { [E\_BMV080\_MEASUREMENT\_ALGORITHM\_FAST\_RESPONSE](bmv080__defs_8h.html#adb54025c7d5f35df05910713d5c22cf8a62839c5160212320947700c4b2b4e4d3) = 1 , [E\_BMV080\_MEASUREMENT\_ALGORITHM\_BALANCED](bmv080__defs_8h.html#adb54025c7d5f35df05910713d5c22cf8a0d057e1b008f8de732a226074392df81) = 2 , [E\_BMV080\_MEASUREMENT\_ALGORITHM\_HIGH\_PRECISION](bmv080__defs_8h.html#adb54025c7d5f35df05910713d5c22cf8a1a8c69f2b58309c75f0f26cf0f84de5a) = 3 } |
|  | Measurement algorithm choices. [More...](bmv080__defs_8h.html#adb54025c7d5f35df05910713d5c22cf8) |
|  | |

## Detailed Description

BMV080 sensor driver definitions.

Copyright (C) Bosch Sensortec GmbH. All Rights Reserved. Confidential.

<BST\_disclaimer>

## Typedef Documentation

## [◆](#a475c5833142f0e4a7367b86f7f8d4ed0)bmv080\_callback\_data\_ready\_t

|  |
| --- |
| typedef void(\* bmv080\_callback\_data\_ready\_t) ([bmv080\_output\_t](structbmv080__output__t.html) bmv080\_output, void \*callback\_parameters) |

Function pointer for handling the sensor's output information.

Parameters
:   |  |  |  |
    | --- | --- | --- |
    | [in] | bmv080\_output | : Structure containing sensor output. |
    | [in,out] | callback\_parameters | : user defined parameters to be passed to the callback function. |

## [◆](#a8f224ce471255f2e011e1ddacc80aac2)bmv080\_callback\_delay\_t

|  |
| --- |
| typedef int8\_t(\* bmv080\_callback\_delay\_t) (uint32\_t duration\_in\_ms) |

Function pointer for executing a software delay operation.

Parameters
:   |  |  |  |
    | --- | --- | --- |
    | [in] | duration\_in\_ms | : Duration of the delay in milliseconds. |

Returns
:   Zero if successful, otherwise the return value is an externally defined error code.

## [◆](#a5c75eb216732f7d8a079df64a45f41ef)bmv080\_callback\_read\_t

|  |
| --- |
| typedef int8\_t(\* bmv080\_callback\_read\_t) ([bmv080\_sercom\_handle\_t](bmv080__defs_8h.html#a2fa6a9cc0debc81a6f3ebe269457fb7e) sercom\_handle, uint16\_t header, uint16\_t \*payload, uint16\_t payload\_length) |

Function pointer for reading an array of *payload\_length* words of 16 bit *payload*.

All data, *header* and *payload*, is transferred as MSB first.

Precondition
:   Both *header* and *payload* words are 16 bit and combined. A *payload* is only transferred on a complete transmission of 16 bits.
:   Burst transfers, i.e. reading a *header* followed by several *payload* elements, must be supported.

Parameters
:   |  |  |  |
    | --- | --- | --- |
    | [in] | sercom\_handle | : Handle for a serial communication interface to a specific sensor unit. |
    | [in] | header | : Header information for the following *payload*. |
    | [out] | payload | : Payload to be read consisting of 16 bit words. |
    | [in] | payload\_length | : Number of *payload* elements to be read. |

Returns
:   Zero if successful, otherwise the return value is an externally defined error code.

## [◆](#a081caa48b09b919a0aa30a74aaf6c6a8)bmv080\_callback\_tick\_t

|  |
| --- |
| typedef uint32\_t(\* bmv080\_callback\_tick\_t) (void) |

Function pointer for getting a tick value in milliseconds (based on the host system clock).

This serves as a measure of the elapsed time since start up, .e.g uint32\_t HAL\_GetTick(void) of the STM32 HAL Framework or uint32\_t GetTickCount(void) of the Windows API.

Returns
:   Tick value in milliseconds

## [◆](#ace4139eb94c8b978a45b66f53f394178)bmv080\_callback\_write\_t

|  |
| --- |
| typedef int8\_t(\* bmv080\_callback\_write\_t) ([bmv080\_sercom\_handle\_t](bmv080__defs_8h.html#a2fa6a9cc0debc81a6f3ebe269457fb7e) sercom\_handle, uint16\_t header, const uint16\_t \*payload, uint16\_t payload\_length) |

Function pointer for writing an array of *payload\_length* words of 16 bit *payload*.

All data, *header* and *payload*, is transferred as MSB first.

Precondition
:   Both *header* and *payload* words are 16 bit. A *payload* is only transferred on a complete transmission of 16 bits.
:   Burst transfers, i.e. writing a *header* followed by several *payload* elements, must be supported.

Parameters
:   |  |  |  |
    | --- | --- | --- |
    | [in] | sercom\_handle | : Handle for a serial communication interface to a specific sensor unit. |
    | [in] | header | : Header information for the following *payload*. |
    | [in] | payload | : Payload to be written consisting of 16 bit words. |
    | [in] | payload\_length | : Number of *payload* elements to be written. |

Returns
:   Zero if successful, otherwise the return value is an externally defined error code.

## [◆](#ae9764f1ba50176cb891a184a3125029c)bmv080\_handle\_t

|  |
| --- |
| typedef void\* [bmv080\_handle\_t](bmv080__defs_8h.html#ae9764f1ba50176cb891a184a3125029c) |

Unique handle for a sensor unit.

## [◆](#a2fa6a9cc0debc81a6f3ebe269457fb7e)bmv080\_sercom\_handle\_t

|  |
| --- |
| typedef void\* [bmv080\_sercom\_handle\_t](bmv080__defs_8h.html#a2fa6a9cc0debc81a6f3ebe269457fb7e) |

Unique handle for a serial communication, i.e. the hardware connection to the sensor unit.

## Enumeration Type Documentation

## [◆](#abec9248d3a867f49c03e5531add15d9a)bmv080\_duty\_cycling\_mode\_t

|  |
| --- |
| enum [bmv080\_duty\_cycling\_mode\_t](bmv080__defs_8h.html#abec9248d3a867f49c03e5531add15d9a) |

Modes of performing a duty cycling measurement.

| Enumerator | |
| --- | --- |
| E\_BMV080\_DUTY\_CYCLING\_MODE\_0 | 0: Mode with fixed duty cycle, ON time = integration\_time and OFF time = sleep time |

## [◆](#adb54025c7d5f35df05910713d5c22cf8)bmv080\_measurement\_algorithm\_t

|  |
| --- |
| enum [bmv080\_measurement\_algorithm\_t](bmv080__defs_8h.html#adb54025c7d5f35df05910713d5c22cf8) |

Measurement algorithm choices.

| Enumerator | |
| --- | --- |
| E\_BMV080\_MEASUREMENT\_ALGORITHM\_FAST\_RESPONSE |  |
| E\_BMV080\_MEASUREMENT\_ALGORITHM\_BALANCED |  |
| E\_BMV080\_MEASUREMENT\_ALGORITHM\_HIGH\_PRECISION |  |

## [◆](#abb6cddddc89657e96e2c9585a85bc32c)bmv080\_status\_code\_t

|  |
| --- |
| enum [bmv080\_status\_code\_t](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32c) |

Status codes returned by the BMV080 sensor driver.

| Enumerator | |
| --- | --- |
| E\_BMV080\_OK | 0: Default result on success or if there is no warning / error. |
| E\_BMV080\_WARNING\_INVALID\_REG\_READ | 1: Misuse detected in BMV080 API integration. |
| E\_BMV080\_WARNING\_INVALID\_REG\_WRITE | 2: Misuse detected in BMV080 API integration. |
| E\_BMV080\_WARNING\_FIFO\_READ | 3: Misuse detected in BMV080 API integration. Hint: Please review SPI / I2C implementation, specifically multi-word reads. |
| E\_BMV080\_WARNING\_FIFO\_EVENTS\_OVERFLOW | 4: Too many particle / obstruction events detected than can be processed by bmv080\_serve\_interrupt API. Hint: Call bmv080\_serve\_interrupt more frequently, or switch from polling to interrupt based use, or remove potential obstructions from field of view. |
| E\_BMV080\_WARNING\_FIFO\_SW\_BUFFER\_SIZE | 208: Misuse detected in BMV080 API integration. |
| E\_BMV080\_WARNING\_FIFO\_HW\_BUFFER\_SIZE | 209: Too many particle / obstruction events detected than can be processed by bmv080\_serve\_interrupt API. Hint: Call bmv080\_serve\_interrupt more frequently, or switch from polling to interrupt based use, or remove potential obstructions from field of view. |
| E\_BMV080\_ERROR\_NULLPTR | 100: Misuse detected in BMV080 API integration. A reference points to an invalid / null address. Hint: Please check the pointer arguments of the API e.g. device handle. |
| E\_BMV080\_ERROR\_REG\_ADDR | 101: Misuse detected in BMV080 API integration. |
| E\_BMV080\_ERROR\_PARAM\_LOCKED | 179: The sensor parameter is locked during measurement. Hint: Please configure BMV080 file logging (e.g. path) before starting a measurement. This is valid for general purpose platforms. |
| E\_BMV080\_ERROR\_PARAM\_INVALID | 115: The parameter key is invalid. Hint: Invalid key provided to bmv080\_set\_parameters or bmv080\_get\_parameters APIs. |
| E\_BMV080\_ERROR\_PARAM\_INVALID\_CHANNEL | 102: Misuse detected in BMV080 API integration |
| E\_BMV080\_ERROR\_PARAM\_INVALID\_VALUE | 123: The parameter's value is invalid. Hint: Please provide correct value to bmv080\_set\_parameters API (e.g. duty\_cycling\_period) as specified in the API documentation. |
| E\_BMV080\_ERROR\_PARAM\_INVALID\_INTERNAL\_CONFIG | 104: Misuse detected in BMV080 API integration. |
| E\_BMV080\_ERROR\_PRECONDITION\_UNSATISFIED | 180: An API call is invalid because a precondition is still unsatisfied. Hint: Please ensure correct 'API calling sequence' or handle previously occurred errors. |
| E\_BMV080\_ERROR\_HW\_READ | 105: Reading via the provided hardware communication interface failed. Hint: Please review communication or implementation of SPI / I2C read function. |
| E\_BMV080\_ERROR\_HW\_WRITE | 106: Writing via the provided hardware communication interface failed. Hint: Please review communication or implementation of SPI / I2C write function. |
| E\_BMV080\_ERROR\_MISMATCH\_CHIP\_ID | 107: The immutable "chip id" changed. Hint: Please review communication or implementation of SPI / I2C interface. |
| E\_BMV080\_ERROR\_MISMATCH\_REG\_VALUE | 160: Misuse detected in BMV080 API integration. |
| E\_BMV080\_ERROR\_OPERATION\_MODE\_INVALID | 116: The requested operation mode is invalid. Hint: Please check that power provided to BMV080 is sufficient & stable. |
| E\_BMV080\_ERROR\_OPERATION\_MODE\_CHANGE | 113: Changing to the requested operation mode failed. Hint: Please check that power provided to BMV080 is sufficient & stable. |
| E\_BMV080\_ERROR\_OPERATION\_MODE\_CHANNELS\_OUT\_OF\_SYNC | 114: The operation modes of different channels are out of sync. Hint: Please check that power provided to BMV080 is sufficient & stable. |
| E\_BMV080\_ERROR\_ASIC\_NOT\_CONFIGURED | 157: Misuse detected in BMV080 API integration. Hint: Please contact BST customer support team. |
| E\_BMV080\_ERROR\_MEM\_READ | 133: Memory read failed. Hint: Please check that power provided to BMV080 is sufficient & stable. |
| E\_BMV080\_ERROR\_MEM\_ADDRESS | 135: Misuse detected in BMV080 API integration. Hint: Please contact BST customer support team. |
| E\_BMV080\_ERROR\_MEM\_CMD | 136: Memory command failed. Hint: Please check that power provided to BMV080 is sufficient & stable. |
| E\_BMV080\_ERROR\_MEM\_TIMEOUT | 137: Memory access timeout. Hint: Please check that power provided to BMV080 is sufficient & stable. |
| E\_BMV080\_ERROR\_MEM\_INVALID | 138: Misuse detected in BMV080 API integration. |
| E\_BMV080\_ERROR\_MEM\_OBSOLETE | 139: Misuse detected in BMV080 API integration. |
| E\_BMV080\_ERROR\_MEM\_OPERATION\_MODE | 140: Changing to the requested operation mode failed. Hint: Please check that power provided to BMV080 is sufficient & stable. |
| E\_BMV080\_ERROR\_MEM\_DATA\_INTEGRITY | 153: Memory data integrity check failed. Hint: Please contact BST customer support team. |
| E\_BMV080\_ERROR\_MEM\_DATA\_INTEGRITY\_INTERNAL\_TEST\_1 | 154: Memory data integrity check for internal test 1 region failed. Hint: Please contact BST customer support team. |
| E\_BMV080\_ERROR\_MEM\_INTERNAL\_TEST\_1 | 156: Memory check for internal test 1 region failed. Hint: Please contact BST customer support team. |
| E\_BMV080\_ERROR\_MEM\_DATA\_INTEGRITY\_INTERNAL\_TEST\_2 | 159: Memory data integrity check for internal test 2 region failed. Hint: Please contact BST customer support team. |
| E\_BMV080\_ERROR\_MEM\_INTERNAL\_TEST\_2 | 181: Memory check for internal test 2 region failed. Hint: Please contact BST customer support team. |
| E\_BMV080\_ERROR\_FIFO\_FORMAT | 210: Misuse detected in BMV080 API integration. Hint: Please review SPI / I2C implementation. |
| E\_BMV080\_ERROR\_FIFO\_EVENTS\_COUNT\_SATURATED | 213: Too many particle / obstruction events detected than can be processed by bmv080\_serve\_interrupt API. Hint: Call bmv080\_serve\_interrupt more frequently, or switch from polling to interrupt based use, or remove potential obstructions from field of view. |
| E\_BMV080\_ERROR\_FIFO\_UNAVAILABLE | 174: Misuse detected in BMV080 API integration. Hint: Please review SPI / I2C implementation and check that power provided to BMV080 is sufficient & stable. |
| E\_BMV080\_ERROR\_FIFO\_EVENTS\_COUNT\_DIFF | 214: Misuse detected in BMV080 API integration. Hint: Please contact BST customer support team. |
| E\_BMV080\_ERROR\_SYNC\_COMM | 161: An error occurred regarding the communication synchronization. Hint: Please check that power provided to BMV080 is sufficient & stable. If the problem is not resolved, please contact BST customer support team. |
| E\_BMV080\_ERROR\_SYNC\_CTRL | 162: An error occurred regarding the control synchronization. Hint: Please check that power provided to BMV080 is sufficient & stable. If the problem is not resolved, please contact BST customer support team. |
| E\_BMV080\_ERROR\_SYNC\_MEAS | 163: An error occurred regarding the measurement synchronization. Hint: Please check that power provided to BMV080 is sufficient & stable. If the problem is not resolved, please contact BST customer support team. |
| E\_BMV080\_ERROR\_SYNC\_LOCKED | 164: An error occurred regarding a locked synchronization. Hint: Please check that power provided to BMV080 is sufficient & stable. If the problem is not resolved, please contact BST customer support team. |
| E\_BMV080\_ERROR\_DC\_CANCEL\_RANGE | 165: An error occurred regarding the DC cancellation range. Hint: Please check thermal integration and/or remove potential obstructions from field of view. If the problem is not resolved, please contact BST customer support team. |
| E\_BMV080\_ERROR\_DC\_ESTIM\_RANGE | 166: An error occurred regarding the DC estimation range. Hint: Please check thermal integration and/or remove potential obstructions from field of view. If the problem is not resolved, please contact BST customer support team. |
| E\_BMV080\_ERROR\_LPWR\_T | 167: Misuse detected in BMV080 API integration. Hint: Please contact BST customer support team. |
| E\_BMV080\_ERROR\_LPWR\_RANGE | 168: An error occurred regarding LPWR range. Hint: Please check thermal integration sensor wear-out, humidity, and/or remove potential obstructions from field of view. If the problem is not resolved, please contact BST customer support team. |
| E\_BMV080\_ERROR\_POWER\_DOMAIN | 169: An error occurred regarding the power domain. Hint: Please check that power provided to BMV080 is sufficient & stable (VDDL, VDDA or VSS). If the problem is not resolved, please contact BST customer support team. |
| E\_BMV080\_ERROR\_HEADROOM\_VDDL | 170: An error occurred regarding the headroom detection. Hint: Please check that power provided to BMV080 is sufficient & stable (VDDL). If the problem is not resolved, please contact BST customer support team. |
| E\_BMV080\_ERROR\_HEADROOM\_LDV\_OUTPUT | 171: An error occurred regarding the headroom LDV output. Hint: Please check that power provided to BMV080 is sufficient & stable (VDDL). If the problem is not resolved, please contact BST customer support team. |
| E\_BMV080\_ERROR\_HEADROOM\_LDV\_REF | 172: An error occurred regarding the headroom LDV reference. Hint: Please check that power provided to BMV080 is sufficient & stable (VDDL). If the problem is not resolved, please contact BST customer support team. |
| E\_BMV080\_ERROR\_HEADROOM\_INTERNAL | 173: An error occurred regarding the user headroom detection. Hint: Please contact BST customer support team. |
| E\_BMV080\_ERROR\_SAFETY\_PRECAUTION | 120: An error occurred due to a safety precaution mechanism. Hint: Please contact BST customer support team. |
| E\_BMV080\_ERROR\_TIMESTAMP\_DIFFERENCE | 211: Possible communication issue on SPI/I2C or too many particle / obstruction events detected than can be processed by bmv080\_serve\_interrupt API. Hint: Please review communication or implementation of SPI / I2C interface. |
| E\_BMV080\_ERROR\_TIMESTAMP\_OVERFLOW | 212: The timestamp is smaller than the previous timestamp. Hint: Please review communication or implementation of SPI / I2C interface. |
| E\_BMV080\_ERROR\_LIB\_VERSION\_INCOMPATIBLE | 300: BMV080 libraries are incompatible with each other. Hint: Please use compatible API libraries from the same SW package. |
| E\_BMV080\_ERROR\_INTERNAL\_PARAMETER\_VERSION\_INVALID | 301: Hint: Please contact BST customer support team. |
| E\_BMV080\_ERROR\_INTERNAL\_PARAMETER\_INDEX\_INVALID | 302: Hint: Please contact BST customer support team. |
| E\_BMV080\_ERROR\_MEMORY\_ALLOCATION | 403: FIFO level invalid leading to memory allocation issue. Hint: Please review communication or implementation of SPI / I2C read function. If the problem is not resolved, please contact BST customer support team. |
| E\_BMV080\_ERROR\_CALLBACK\_DELAY | 303: A linked delay callback function produced an error. Hint: callback function of type bmv080\_callback\_delay\_t does not return 0, when it is called internally to perform a delay operation. Please check implementation of the delay function. |
| E\_BMV080\_ERROR\_INCOMPATIBLE\_SENSOR\_HW | 418: Sensor driver is not compatible with the used sensor HW sample. Hint: Please contact BST customer support team. |

---

# bmv080_output_t Struct Reference

Output structure which is updated by bmv080\_serve\_interrupt when sensor output is available.
[More...](structbmv080__output__t.html#details)

`#include <bmv080_defs.h>`

|  |  |
| --- | --- |
| Public Attributes | |
| float | [runtime\_in\_sec](structbmv080__output__t.html#ad8f1a4ee17f4fc9c9f62e968f333a3e7) |
|  | |
| float | [pm2\_5\_mass\_concentration](structbmv080__output__t.html#a7e7c622cca03e7f621dd7d479090fc79) |
|  | |
| float | [pm1\_mass\_concentration](structbmv080__output__t.html#af3880835265f26156e0cec4440c17747) |
|  | |
| float | [pm10\_mass\_concentration](structbmv080__output__t.html#a1d94f0ce30913a75932a539e8e1dd10f) |
|  | |
| float | [pm2\_5\_number\_concentration](structbmv080__output__t.html#ae7159830ad8e76157bf52929091063e2) |
|  | |
| float | [pm1\_number\_concentration](structbmv080__output__t.html#a5079f5d195bf5fa0ca7a51932761d15a) |
|  | |
| float | [pm10\_number\_concentration](structbmv080__output__t.html#a355d405516fbd60c107a1a9b73b5bc00) |
|  | |
| bool | [is\_obstructed](structbmv080__output__t.html#a9dea98595d2af1fe5eef435387df8fa5) |
|  | |
| bool | [is\_outside\_measurement\_range](structbmv080__output__t.html#a017189b23ee7b880b0ef446ddcd6f5ec) |
|  | |
| float | [reserved\_0](structbmv080__output__t.html#a2cd53760a1ac15a52ff85d5158719414) |
|  | |
| float | [reserved\_1](structbmv080__output__t.html#a48464ce5527975e5f58f8252a5eb2eac) |
|  | |
| float | [reserved\_2](structbmv080__output__t.html#a2355e45a2594f28e5e42c94baea9270d) |
|  | |
| struct bmv080\_extended\_info\_s \* | [extended\_info](structbmv080__output__t.html#a0908cc09b1914eceab619687aa9e8d9d) |
|  | |

## Detailed Description

Output structure which is updated by bmv080\_serve\_interrupt when sensor output is available.

## Member Data Documentation

## [◆](#a0908cc09b1914eceab619687aa9e8d9d)extended\_info

|  |
| --- |
| struct bmv080\_extended\_info\_s\* bmv080\_output\_t::extended\_info |

extended\_info: for internal use only

## [◆](#a9dea98595d2af1fe5eef435387df8fa5)is\_obstructed

|  |
| --- |
| bool bmv080\_output\_t::is\_obstructed |

is\_obstructed: flag to indicate whether the sensor is obstructed and cannot perform a valid measurement

## [◆](#a017189b23ee7b880b0ef446ddcd6f5ec)is\_outside\_measurement\_range

|  |
| --- |
| bool bmv080\_output\_t::is\_outside\_measurement\_range |

is\_outside\_measurement\_range: flag to indicate whether the PM2.5 concentration is outside the specified measurement range (0..1000 ug/m3)

## [◆](#a1d94f0ce30913a75932a539e8e1dd10f)pm10\_mass\_concentration

|  |
| --- |
| float bmv080\_output\_t::pm10\_mass\_concentration |

pm10\_mass\_concentration: PM10 value in ug/m3

## [◆](#a355d405516fbd60c107a1a9b73b5bc00)pm10\_number\_concentration

|  |
| --- |
| float bmv080\_output\_t::pm10\_number\_concentration |

pm10\_number\_concentration: PM10 value in particles/cm3

## [◆](#af3880835265f26156e0cec4440c17747)pm1\_mass\_concentration

|  |
| --- |
| float bmv080\_output\_t::pm1\_mass\_concentration |

pm1\_mass\_concentration: PM1 value in ug/m3

## [◆](#a5079f5d195bf5fa0ca7a51932761d15a)pm1\_number\_concentration

|  |
| --- |
| float bmv080\_output\_t::pm1\_number\_concentration |

pm1\_number\_concentration: PM1 value in particles/cm3

## [◆](#a7e7c622cca03e7f621dd7d479090fc79)pm2\_5\_mass\_concentration

|  |
| --- |
| float bmv080\_output\_t::pm2\_5\_mass\_concentration |

pm2\_5\_mass\_concentration: PM2.5 value in ug/m3

## [◆](#ae7159830ad8e76157bf52929091063e2)pm2\_5\_number\_concentration

|  |
| --- |
| float bmv080\_output\_t::pm2\_5\_number\_concentration |

pm2\_5\_number\_concentration: PM2.5 value in particles/cm3

## [◆](#a2cd53760a1ac15a52ff85d5158719414)reserved\_0

|  |
| --- |
| float bmv080\_output\_t::reserved\_0 |

reserved\_0: for internal use only

## [◆](#a48464ce5527975e5f58f8252a5eb2eac)reserved\_1

|  |
| --- |
| float bmv080\_output\_t::reserved\_1 |

reserved\_1: for internal use only

## [◆](#a2355e45a2594f28e5e42c94baea9270d)reserved\_2

|  |
| --- |
| float bmv080\_output\_t::reserved\_2 |

reserved\_2: for internal use only

## [◆](#ad8f1a4ee17f4fc9c9f62e968f333a3e7)runtime\_in\_sec

|  |
| --- |
| float bmv080\_output\_t::runtime\_in\_sec |

runtime\_in\_sec: estimate of the time passed since the start of the measurement, in seconds

---

The documentation for this struct was generated from the following file:

* [bmv080\_defs.h](bmv080__defs_8h_source.html)

---

# Globals

Here is a list of all file members with links to the files they belong to:

### - b -

* bmv080\_callback\_data\_ready\_t : [bmv080\_defs.h](bmv080__defs_8h.html#a475c5833142f0e4a7367b86f7f8d4ed0)
* bmv080\_callback\_delay\_t : [bmv080\_defs.h](bmv080__defs_8h.html#a8f224ce471255f2e011e1ddacc80aac2)
* bmv080\_callback\_read\_t : [bmv080\_defs.h](bmv080__defs_8h.html#a5c75eb216732f7d8a079df64a45f41ef)
* bmv080\_callback\_tick\_t : [bmv080\_defs.h](bmv080__defs_8h.html#a081caa48b09b919a0aa30a74aaf6c6a8)
* bmv080\_callback\_write\_t : [bmv080\_defs.h](bmv080__defs_8h.html#ace4139eb94c8b978a45b66f53f394178)
* bmv080\_close() : [bmv080.h](bmv080_8h.html#a89e3e1fa71ddd186ff16baa01b2867be)
* bmv080\_duty\_cycling\_mode\_t : [bmv080\_defs.h](bmv080__defs_8h.html#abec9248d3a867f49c03e5531add15d9a)
* bmv080\_get\_driver\_version() : [bmv080.h](bmv080_8h.html#a59dfa271ea9b0c64f9eafd6846b6e7b6)
* bmv080\_get\_parameter() : [bmv080.h](bmv080_8h.html#ab618e6c8df10e05202441ccb219919e9)
* bmv080\_get\_sensor\_id() : [bmv080.h](bmv080_8h.html#a37883c1c030b6c20d9e8404403d3ae51)
* bmv080\_handle\_t : [bmv080\_defs.h](bmv080__defs_8h.html#ae9764f1ba50176cb891a184a3125029c)
* bmv080\_measurement\_algorithm\_t : [bmv080\_defs.h](bmv080__defs_8h.html#adb54025c7d5f35df05910713d5c22cf8)
* bmv080\_open() : [bmv080.h](bmv080_8h.html#a3ef39e1817fcbd5e2b8583f6d45bbc5f)
* bmv080\_reset() : [bmv080.h](bmv080_8h.html#a7f315d343e3d04dc1e2ea59a535e5ca8)
* bmv080\_sercom\_handle\_t : [bmv080\_defs.h](bmv080__defs_8h.html#a2fa6a9cc0debc81a6f3ebe269457fb7e)
* bmv080\_serve\_interrupt() : [bmv080.h](bmv080_8h.html#a288b1f6f41c96efc5a481fd61c4a2572)
* bmv080\_set\_parameter() : [bmv080.h](bmv080_8h.html#a373060d6a647c56d36d1d2deff8ad97f)
* bmv080\_start\_continuous\_measurement() : [bmv080.h](bmv080_8h.html#a2dc111d3b517f284b7044757be86f799)
* bmv080\_start\_duty\_cycling\_measurement() : [bmv080.h](bmv080_8h.html#a1c6028f83de7df5b510088358940dffa)
* bmv080\_status\_code\_t : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32c)
* bmv080\_stop\_measurement() : [bmv080.h](bmv080_8h.html#aeb9fa87938812b3bea75166723a929ac)

### - e -

* E\_BMV080\_DUTY\_CYCLING\_MODE\_0 : [bmv080\_defs.h](bmv080__defs_8h.html#abec9248d3a867f49c03e5531add15d9aa3a049126ab19c5958c78f417bf32c5a2)
* E\_BMV080\_ERROR\_ASIC\_NOT\_CONFIGURED : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32cacf4a7de4e5a4d82a7d393c087a3253ea)
* E\_BMV080\_ERROR\_CALLBACK\_DELAY : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca7a89d1728e4defb6a2ea6ec1fa6ae3cf)
* E\_BMV080\_ERROR\_DC\_CANCEL\_RANGE : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca6a701954c897f9ebcc5bd85ba5797dc4)
* E\_BMV080\_ERROR\_DC\_ESTIM\_RANGE : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32cae1d33d92f69219a0653e64860b3aebd5)
* E\_BMV080\_ERROR\_FIFO\_EVENTS\_COUNT\_DIFF : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca9f8b9b926d8a9c8e7dddb858930105f4)
* E\_BMV080\_ERROR\_FIFO\_EVENTS\_COUNT\_SATURATED : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32cadf0876d44c6fba6aaf1739ae97791fea)
* E\_BMV080\_ERROR\_FIFO\_FORMAT : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca5fb121441ab88e20f1788de1170138ac)
* E\_BMV080\_ERROR\_FIFO\_UNAVAILABLE : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32cabb17558222333339ee0e44bce4a91c12)
* E\_BMV080\_ERROR\_HEADROOM\_INTERNAL : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32caafa2647a89a75f86f00951b484bf0040)
* E\_BMV080\_ERROR\_HEADROOM\_LDV\_OUTPUT : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca3a534bb4242223d8deae0e7c640b27e1)
* E\_BMV080\_ERROR\_HEADROOM\_LDV\_REF : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca6e1800a56e737a0ebe7d2bc68e3141d3)
* E\_BMV080\_ERROR\_HEADROOM\_VDDL : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca74b08440bc167ea6958cc05b12339889)
* E\_BMV080\_ERROR\_HW\_READ : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca5c8000c75af910518668a7d8fdcb1637)
* E\_BMV080\_ERROR\_HW\_WRITE : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32caa9493cfddb4df8beeb17e68a796932f3)
* E\_BMV080\_ERROR\_INCOMPATIBLE\_SENSOR\_HW : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca94e19808553823ee0e3b2e7e70f20619)
* E\_BMV080\_ERROR\_INTERNAL\_PARAMETER\_INDEX\_INVALID : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca35558e4dae25b883c843879c4fb40f36)
* E\_BMV080\_ERROR\_INTERNAL\_PARAMETER\_VERSION\_INVALID : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32cab7dcf7bd5937d3e791c561f89946ba12)
* E\_BMV080\_ERROR\_LIB\_VERSION\_INCOMPATIBLE : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32caae201e2e4d77b93e71be18762d8c8180)
* E\_BMV080\_ERROR\_LPWR\_RANGE : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32cac28873af9088fba86190b3a0e796102f)
* E\_BMV080\_ERROR\_LPWR\_T : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca605b7f2aa57104f517a4b1a61ea0ae9a)
* E\_BMV080\_ERROR\_MEM\_ADDRESS : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32cad5f84195aaa7a88861f8b844023c4601)
* E\_BMV080\_ERROR\_MEM\_CMD : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca1ec0fcb468962dca1148a8d1b1979c52)
* E\_BMV080\_ERROR\_MEM\_DATA\_INTEGRITY : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32caea343d266ee58f0b611fb4a182c8eb79)
* E\_BMV080\_ERROR\_MEM\_DATA\_INTEGRITY\_INTERNAL\_TEST\_1 : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32cab45848a84df902d0b61db8d8bb1c2c37)
* E\_BMV080\_ERROR\_MEM\_DATA\_INTEGRITY\_INTERNAL\_TEST\_2 : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca076021ff65421933aeea8713a178d979)
* E\_BMV080\_ERROR\_MEM\_INTERNAL\_TEST\_1 : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32caa812a4c231c6fe41adfe6b8fba2dc161)
* E\_BMV080\_ERROR\_MEM\_INTERNAL\_TEST\_2 : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca0f911df2c4fdfe7afd9ff85a331fb987)
* E\_BMV080\_ERROR\_MEM\_INVALID : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca32f0199be92c5ca980cbabcf4fecc4f8)
* E\_BMV080\_ERROR\_MEM\_OBSOLETE : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32cab71b0696fb0b9acff31182239f974efb)
* E\_BMV080\_ERROR\_MEM\_OPERATION\_MODE : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32caa95866ccf2f3f9539bc42d9a12ef9956)
* E\_BMV080\_ERROR\_MEM\_READ : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca5cef629802b3f13449bc0549ccfd782c)
* E\_BMV080\_ERROR\_MEM\_TIMEOUT : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca37d8d9a4c44be5d3fbc05a4caa882028)
* E\_BMV080\_ERROR\_MEMORY\_ALLOCATION : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca4e44966da155b30d53f0e274d5afd423)
* E\_BMV080\_ERROR\_MISMATCH\_CHIP\_ID : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32caf49be65624464077afdc92cb0d66b629)
* E\_BMV080\_ERROR\_MISMATCH\_REG\_VALUE : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca3c5fba4a1d8c7b1cbfa6443ed9b309f7)
* E\_BMV080\_ERROR\_NULLPTR : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca3bb66b04f6485a8c00f6a81a2eb7bc7b)
* E\_BMV080\_ERROR\_OPERATION\_MODE\_CHANGE : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca746bd0b9b4ce8edbb6850add461b2eaf)
* E\_BMV080\_ERROR\_OPERATION\_MODE\_CHANNELS\_OUT\_OF\_SYNC : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32cadf70756557523d32c909ed08992253c9)
* E\_BMV080\_ERROR\_OPERATION\_MODE\_INVALID : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32cac05ecebcafef6f39755dd08dc593a1b6)
* E\_BMV080\_ERROR\_PARAM\_INVALID : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca2ab99cada049f34d0cf5b7533addc2cd)
* E\_BMV080\_ERROR\_PARAM\_INVALID\_CHANNEL : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca687b7bf8eaaaf7f3f28d11e2a1c94989)
* E\_BMV080\_ERROR\_PARAM\_INVALID\_INTERNAL\_CONFIG : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca7df62706c3bd810bd5f35af54a89560f)
* E\_BMV080\_ERROR\_PARAM\_INVALID\_VALUE : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca9ea380ebf40acf7eed56a6be7f39ae5e)
* E\_BMV080\_ERROR\_PARAM\_LOCKED : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32cafe9373ec575e202702de6a3fcf9d8c83)
* E\_BMV080\_ERROR\_POWER\_DOMAIN : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32cab3320cd0a26869758245fb87b74df0e6)
* E\_BMV080\_ERROR\_PRECONDITION\_UNSATISFIED : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca9015d333b71a5e818a792fd21ad72771)
* E\_BMV080\_ERROR\_REG\_ADDR : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca4e0bd18e96843d76e8cdda21a2de7b76)
* E\_BMV080\_ERROR\_SAFETY\_PRECAUTION : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca68ce56d97eb53326fce3bb5115739ec6)
* E\_BMV080\_ERROR\_SYNC\_COMM : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca8276fd5f19f7de8e521ce24bbeb03ffc)
* E\_BMV080\_ERROR\_SYNC\_CTRL : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca3cc7c0ffab613267fabbdc03e68780d6)
* E\_BMV080\_ERROR\_SYNC\_LOCKED : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32cab20ecf13623e0bff95e54ebfe9e9f6de)
* E\_BMV080\_ERROR\_SYNC\_MEAS : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca83018de43aedcc99e5f2ce56f82457c6)
* E\_BMV080\_ERROR\_TIMESTAMP\_DIFFERENCE : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca458124171e6edf08f3eb5cfc3946cb3f)
* E\_BMV080\_ERROR\_TIMESTAMP\_OVERFLOW : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32cab5eaa6476a6ad24f932e0d74255c0e15)
* E\_BMV080\_MEASUREMENT\_ALGORITHM\_BALANCED : [bmv080\_defs.h](bmv080__defs_8h.html#adb54025c7d5f35df05910713d5c22cf8a0d057e1b008f8de732a226074392df81)
* E\_BMV080\_MEASUREMENT\_ALGORITHM\_FAST\_RESPONSE : [bmv080\_defs.h](bmv080__defs_8h.html#adb54025c7d5f35df05910713d5c22cf8a62839c5160212320947700c4b2b4e4d3)
* E\_BMV080\_MEASUREMENT\_ALGORITHM\_HIGH\_PRECISION : [bmv080\_defs.h](bmv080__defs_8h.html#adb54025c7d5f35df05910713d5c22cf8a1a8c69f2b58309c75f0f26cf0f84de5a)
* E\_BMV080\_OK : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca2f4eec048a3f43d9450e88c5b0748072)
* E\_BMV080\_WARNING\_FIFO\_EVENTS\_OVERFLOW : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32cad5301169eb0d2b44e5f2bf40e31b9b14)
* E\_BMV080\_WARNING\_FIFO\_HW\_BUFFER\_SIZE : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca6ac4ee65b9c47dc4bb34835211983417)
* E\_BMV080\_WARNING\_FIFO\_READ : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32cab119dafb57ee1688a59007d91116ff5d)
* E\_BMV080\_WARNING\_FIFO\_SW\_BUFFER\_SIZE : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca190ebe9aa41eb7da6a8d6c22b920ac05)
* E\_BMV080\_WARNING\_INVALID\_REG\_READ : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca56923d567ccb5649dc10152def6ca955)
* E\_BMV080\_WARNING\_INVALID\_REG\_WRITE : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca200f29551e6593be1c39adeb8df2d9ed)

---

# Global Functions

Here is a list of all functions with links to the files they belong to:

* bmv080\_close() : [bmv080.h](bmv080_8h.html#a89e3e1fa71ddd186ff16baa01b2867be)
* bmv080\_get\_driver\_version() : [bmv080.h](bmv080_8h.html#a59dfa271ea9b0c64f9eafd6846b6e7b6)
* bmv080\_get\_parameter() : [bmv080.h](bmv080_8h.html#ab618e6c8df10e05202441ccb219919e9)
* bmv080\_get\_sensor\_id() : [bmv080.h](bmv080_8h.html#a37883c1c030b6c20d9e8404403d3ae51)
* bmv080\_open() : [bmv080.h](bmv080_8h.html#a3ef39e1817fcbd5e2b8583f6d45bbc5f)
* bmv080\_reset() : [bmv080.h](bmv080_8h.html#a7f315d343e3d04dc1e2ea59a535e5ca8)
* bmv080\_serve\_interrupt() : [bmv080.h](bmv080_8h.html#a288b1f6f41c96efc5a481fd61c4a2572)
* bmv080\_set\_parameter() : [bmv080.h](bmv080_8h.html#a373060d6a647c56d36d1d2deff8ad97f)
* bmv080\_start\_continuous\_measurement() : [bmv080.h](bmv080_8h.html#a2dc111d3b517f284b7044757be86f799)
* bmv080\_start\_duty\_cycling\_measurement() : [bmv080.h](bmv080_8h.html#a1c6028f83de7df5b510088358940dffa)
* bmv080\_stop\_measurement() : [bmv080.h](bmv080_8h.html#aeb9fa87938812b3bea75166723a929ac)

---

# Global Typedefs

Here is a list of all typedefs with links to the files they belong to:

* bmv080\_callback\_data\_ready\_t : [bmv080\_defs.h](bmv080__defs_8h.html#a475c5833142f0e4a7367b86f7f8d4ed0)
* bmv080\_callback\_delay\_t : [bmv080\_defs.h](bmv080__defs_8h.html#a8f224ce471255f2e011e1ddacc80aac2)
* bmv080\_callback\_read\_t : [bmv080\_defs.h](bmv080__defs_8h.html#a5c75eb216732f7d8a079df64a45f41ef)
* bmv080\_callback\_tick\_t : [bmv080\_defs.h](bmv080__defs_8h.html#a081caa48b09b919a0aa30a74aaf6c6a8)
* bmv080\_callback\_write\_t : [bmv080\_defs.h](bmv080__defs_8h.html#ace4139eb94c8b978a45b66f53f394178)
* bmv080\_handle\_t : [bmv080\_defs.h](bmv080__defs_8h.html#ae9764f1ba50176cb891a184a3125029c)
* bmv080\_sercom\_handle\_t : [bmv080\_defs.h](bmv080__defs_8h.html#a2fa6a9cc0debc81a6f3ebe269457fb7e)

---

# Global Enumerations

Here is a list of all enums with links to the files they belong to:

* bmv080\_duty\_cycling\_mode\_t : [bmv080\_defs.h](bmv080__defs_8h.html#abec9248d3a867f49c03e5531add15d9a)
* bmv080\_measurement\_algorithm\_t : [bmv080\_defs.h](bmv080__defs_8h.html#adb54025c7d5f35df05910713d5c22cf8)
* bmv080\_status\_code\_t : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32c)

---

# Global Enumerator Values

Here is a list of all enum values with links to the files they belong to:

### - e -

* E\_BMV080\_DUTY\_CYCLING\_MODE\_0 : [bmv080\_defs.h](bmv080__defs_8h.html#abec9248d3a867f49c03e5531add15d9aa3a049126ab19c5958c78f417bf32c5a2)
* E\_BMV080\_ERROR\_ASIC\_NOT\_CONFIGURED : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32cacf4a7de4e5a4d82a7d393c087a3253ea)
* E\_BMV080\_ERROR\_CALLBACK\_DELAY : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca7a89d1728e4defb6a2ea6ec1fa6ae3cf)
* E\_BMV080\_ERROR\_DC\_CANCEL\_RANGE : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca6a701954c897f9ebcc5bd85ba5797dc4)
* E\_BMV080\_ERROR\_DC\_ESTIM\_RANGE : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32cae1d33d92f69219a0653e64860b3aebd5)
* E\_BMV080\_ERROR\_FIFO\_EVENTS\_COUNT\_DIFF : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca9f8b9b926d8a9c8e7dddb858930105f4)
* E\_BMV080\_ERROR\_FIFO\_EVENTS\_COUNT\_SATURATED : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32cadf0876d44c6fba6aaf1739ae97791fea)
* E\_BMV080\_ERROR\_FIFO\_FORMAT : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca5fb121441ab88e20f1788de1170138ac)
* E\_BMV080\_ERROR\_FIFO\_UNAVAILABLE : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32cabb17558222333339ee0e44bce4a91c12)
* E\_BMV080\_ERROR\_HEADROOM\_INTERNAL : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32caafa2647a89a75f86f00951b484bf0040)
* E\_BMV080\_ERROR\_HEADROOM\_LDV\_OUTPUT : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca3a534bb4242223d8deae0e7c640b27e1)
* E\_BMV080\_ERROR\_HEADROOM\_LDV\_REF : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca6e1800a56e737a0ebe7d2bc68e3141d3)
* E\_BMV080\_ERROR\_HEADROOM\_VDDL : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca74b08440bc167ea6958cc05b12339889)
* E\_BMV080\_ERROR\_HW\_READ : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca5c8000c75af910518668a7d8fdcb1637)
* E\_BMV080\_ERROR\_HW\_WRITE : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32caa9493cfddb4df8beeb17e68a796932f3)
* E\_BMV080\_ERROR\_INCOMPATIBLE\_SENSOR\_HW : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca94e19808553823ee0e3b2e7e70f20619)
* E\_BMV080\_ERROR\_INTERNAL\_PARAMETER\_INDEX\_INVALID : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca35558e4dae25b883c843879c4fb40f36)
* E\_BMV080\_ERROR\_INTERNAL\_PARAMETER\_VERSION\_INVALID : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32cab7dcf7bd5937d3e791c561f89946ba12)
* E\_BMV080\_ERROR\_LIB\_VERSION\_INCOMPATIBLE : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32caae201e2e4d77b93e71be18762d8c8180)
* E\_BMV080\_ERROR\_LPWR\_RANGE : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32cac28873af9088fba86190b3a0e796102f)
* E\_BMV080\_ERROR\_LPWR\_T : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca605b7f2aa57104f517a4b1a61ea0ae9a)
* E\_BMV080\_ERROR\_MEM\_ADDRESS : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32cad5f84195aaa7a88861f8b844023c4601)
* E\_BMV080\_ERROR\_MEM\_CMD : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca1ec0fcb468962dca1148a8d1b1979c52)
* E\_BMV080\_ERROR\_MEM\_DATA\_INTEGRITY : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32caea343d266ee58f0b611fb4a182c8eb79)
* E\_BMV080\_ERROR\_MEM\_DATA\_INTEGRITY\_INTERNAL\_TEST\_1 : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32cab45848a84df902d0b61db8d8bb1c2c37)
* E\_BMV080\_ERROR\_MEM\_DATA\_INTEGRITY\_INTERNAL\_TEST\_2 : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca076021ff65421933aeea8713a178d979)
* E\_BMV080\_ERROR\_MEM\_INTERNAL\_TEST\_1 : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32caa812a4c231c6fe41adfe6b8fba2dc161)
* E\_BMV080\_ERROR\_MEM\_INTERNAL\_TEST\_2 : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca0f911df2c4fdfe7afd9ff85a331fb987)
* E\_BMV080\_ERROR\_MEM\_INVALID : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca32f0199be92c5ca980cbabcf4fecc4f8)
* E\_BMV080\_ERROR\_MEM\_OBSOLETE : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32cab71b0696fb0b9acff31182239f974efb)
* E\_BMV080\_ERROR\_MEM\_OPERATION\_MODE : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32caa95866ccf2f3f9539bc42d9a12ef9956)
* E\_BMV080\_ERROR\_MEM\_READ : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca5cef629802b3f13449bc0549ccfd782c)
* E\_BMV080\_ERROR\_MEM\_TIMEOUT : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca37d8d9a4c44be5d3fbc05a4caa882028)
* E\_BMV080\_ERROR\_MEMORY\_ALLOCATION : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca4e44966da155b30d53f0e274d5afd423)
* E\_BMV080\_ERROR\_MISMATCH\_CHIP\_ID : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32caf49be65624464077afdc92cb0d66b629)
* E\_BMV080\_ERROR\_MISMATCH\_REG\_VALUE : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca3c5fba4a1d8c7b1cbfa6443ed9b309f7)
* E\_BMV080\_ERROR\_NULLPTR : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca3bb66b04f6485a8c00f6a81a2eb7bc7b)
* E\_BMV080\_ERROR\_OPERATION\_MODE\_CHANGE : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca746bd0b9b4ce8edbb6850add461b2eaf)
* E\_BMV080\_ERROR\_OPERATION\_MODE\_CHANNELS\_OUT\_OF\_SYNC : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32cadf70756557523d32c909ed08992253c9)
* E\_BMV080\_ERROR\_OPERATION\_MODE\_INVALID : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32cac05ecebcafef6f39755dd08dc593a1b6)
* E\_BMV080\_ERROR\_PARAM\_INVALID : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca2ab99cada049f34d0cf5b7533addc2cd)
* E\_BMV080\_ERROR\_PARAM\_INVALID\_CHANNEL : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca687b7bf8eaaaf7f3f28d11e2a1c94989)
* E\_BMV080\_ERROR\_PARAM\_INVALID\_INTERNAL\_CONFIG : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca7df62706c3bd810bd5f35af54a89560f)
* E\_BMV080\_ERROR\_PARAM\_INVALID\_VALUE : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca9ea380ebf40acf7eed56a6be7f39ae5e)
* E\_BMV080\_ERROR\_PARAM\_LOCKED : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32cafe9373ec575e202702de6a3fcf9d8c83)
* E\_BMV080\_ERROR\_POWER\_DOMAIN : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32cab3320cd0a26869758245fb87b74df0e6)
* E\_BMV080\_ERROR\_PRECONDITION\_UNSATISFIED : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca9015d333b71a5e818a792fd21ad72771)
* E\_BMV080\_ERROR\_REG\_ADDR : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca4e0bd18e96843d76e8cdda21a2de7b76)
* E\_BMV080\_ERROR\_SAFETY\_PRECAUTION : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca68ce56d97eb53326fce3bb5115739ec6)
* E\_BMV080\_ERROR\_SYNC\_COMM : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca8276fd5f19f7de8e521ce24bbeb03ffc)
* E\_BMV080\_ERROR\_SYNC\_CTRL : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca3cc7c0ffab613267fabbdc03e68780d6)
* E\_BMV080\_ERROR\_SYNC\_LOCKED : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32cab20ecf13623e0bff95e54ebfe9e9f6de)
* E\_BMV080\_ERROR\_SYNC\_MEAS : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca83018de43aedcc99e5f2ce56f82457c6)
* E\_BMV080\_ERROR\_TIMESTAMP\_DIFFERENCE : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca458124171e6edf08f3eb5cfc3946cb3f)
* E\_BMV080\_ERROR\_TIMESTAMP\_OVERFLOW : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32cab5eaa6476a6ad24f932e0d74255c0e15)
* E\_BMV080\_MEASUREMENT\_ALGORITHM\_BALANCED : [bmv080\_defs.h](bmv080__defs_8h.html#adb54025c7d5f35df05910713d5c22cf8a0d057e1b008f8de732a226074392df81)
* E\_BMV080\_MEASUREMENT\_ALGORITHM\_FAST\_RESPONSE : [bmv080\_defs.h](bmv080__defs_8h.html#adb54025c7d5f35df05910713d5c22cf8a62839c5160212320947700c4b2b4e4d3)
* E\_BMV080\_MEASUREMENT\_ALGORITHM\_HIGH\_PRECISION : [bmv080\_defs.h](bmv080__defs_8h.html#adb54025c7d5f35df05910713d5c22cf8a1a8c69f2b58309c75f0f26cf0f84de5a)
* E\_BMV080\_OK : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca2f4eec048a3f43d9450e88c5b0748072)
* E\_BMV080\_WARNING\_FIFO\_EVENTS\_OVERFLOW : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32cad5301169eb0d2b44e5f2bf40e31b9b14)
* E\_BMV080\_WARNING\_FIFO\_HW\_BUFFER\_SIZE : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca6ac4ee65b9c47dc4bb34835211983417)
* E\_BMV080\_WARNING\_FIFO\_READ : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32cab119dafb57ee1688a59007d91116ff5d)
* E\_BMV080\_WARNING\_FIFO\_SW\_BUFFER\_SIZE : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca190ebe9aa41eb7da6a8d6c22b920ac05)
* E\_BMV080\_WARNING\_INVALID\_REG\_READ : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca56923d567ccb5649dc10152def6ca955)
* E\_BMV080\_WARNING\_INVALID\_REG\_WRITE : [bmv080\_defs.h](bmv080__defs_8h.html#abb6cddddc89657e96e2c9585a85bc32ca200f29551e6593be1c39adeb8df2d9ed)