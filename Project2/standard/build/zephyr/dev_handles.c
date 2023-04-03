#include <zephyr/device.h>
#include <zephyr/toolchain.h>

/* 1 : /soc/rcc@40023800:
 * Supported:
 *    - /soc/pin-controller@40020000/gpio@40021c00
 *    - /soc/pin-controller@40020000/gpio@40021800
 *    - /soc/pin-controller@40020000/gpio@40021400
 *    - /soc/pin-controller@40020000/gpio@40021000
 *    - /soc/pin-controller@40020000/gpio@40020c00
 *    - /soc/pin-controller@40020000/gpio@40020800
 *    - /soc/pin-controller@40020000/gpio@40020400
 *    - /soc/pin-controller@40020000/gpio@40020000
 *    - /soc/rcc@40023800/reset-controller
 *    - /soc/serial@40004400
 *    - /soc/serial@40011000
 *    - /soc/i2c@40005400
 */
const Z_DECL_ALIGN(device_handle_t) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_dts_ord_9[] = { DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, DEVICE_HANDLE_ENDS };

/* 2 : /soc/interrupt-controller@40013c00:
 */
const Z_DECL_ALIGN(device_handle_t) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_dts_ord_39[] = { DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 3 : /soc/pin-controller@40020000/gpio@40021c00:
 * Direct Dependencies:
 *    - /soc/rcc@40023800
 */
const Z_DECL_ALIGN(device_handle_t) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_dts_ord_84[] = { 1, DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 4 : /soc/pin-controller@40020000/gpio@40021800:
 * Direct Dependencies:
 *    - /soc/rcc@40023800
 */
const Z_DECL_ALIGN(device_handle_t) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_dts_ord_83[] = { 1, DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 5 : /soc/pin-controller@40020000/gpio@40021400:
 * Direct Dependencies:
 *    - /soc/rcc@40023800
 */
const Z_DECL_ALIGN(device_handle_t) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_dts_ord_82[] = { 1, DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 6 : /soc/pin-controller@40020000/gpio@40021000:
 * Direct Dependencies:
 *    - /soc/rcc@40023800
 */
const Z_DECL_ALIGN(device_handle_t) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_dts_ord_81[] = { 1, DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 7 : /soc/pin-controller@40020000/gpio@40020c00:
 * Direct Dependencies:
 *    - /soc/rcc@40023800
 */
const Z_DECL_ALIGN(device_handle_t) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_dts_ord_80[] = { 1, DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 8 : /soc/pin-controller@40020000/gpio@40020800:
 * Direct Dependencies:
 *    - /soc/rcc@40023800
 */
const Z_DECL_ALIGN(device_handle_t) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_dts_ord_22[] = { 1, DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 9 : /soc/pin-controller@40020000/gpio@40020400:
 * Direct Dependencies:
 *    - /soc/rcc@40023800
 * Supported:
 *    - /soc/i2c@40005400/lsm303agr-accel@19
 *    - /soc/i2c@40005400/lsm303agr-magn@1e
 *    - /soc/i2c@40005400/lsm6dsl@6b
 */
const Z_DECL_ALIGN(device_handle_t) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_dts_ord_54[] = { 1, DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, 16, 17, 19, DEVICE_HANDLE_ENDS };

/* 10 : /soc/pin-controller@40020000/gpio@40020000:
 * Direct Dependencies:
 *    - /soc/rcc@40023800
 */
const Z_DECL_ALIGN(device_handle_t) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_dts_ord_25[] = { 1, DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 11 : /soc/rcc@40023800/reset-controller:
 * Direct Dependencies:
 *    - /soc/rcc@40023800
 * Supported:
 *    - /soc/serial@40004400
 *    - /soc/serial@40011000
 */
const Z_DECL_ALIGN(device_handle_t) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_dts_ord_28[] = { 1, DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, 12, 13, DEVICE_HANDLE_ENDS };

/* 12 : /soc/serial@40004400:
 * Direct Dependencies:
 *    - /soc/rcc@40023800
 *    - /soc/rcc@40023800/reset-controller
 */
const Z_DECL_ALIGN(device_handle_t) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_dts_ord_43[] = { 1, 11, DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 13 : /soc/serial@40011000:
 * Direct Dependencies:
 *    - /soc/rcc@40023800
 *    - /soc/rcc@40023800/reset-controller
 */
const Z_DECL_ALIGN(device_handle_t) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_dts_ord_46[] = { 1, 11, DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 14 : /soc/i2c@40005400:
 * Direct Dependencies:
 *    - /soc/rcc@40023800
 * Supported:
 *    - /soc/i2c@40005400/hts221@5f
 *    - /soc/i2c@40005400/lsm303agr-accel@19
 *    - /soc/i2c@40005400/lsm303agr-magn@1e
 *    - /soc/i2c@40005400/lps22hb-press@5d
 *    - /soc/i2c@40005400/lsm6dsl@6b
 */
const Z_DECL_ALIGN(device_handle_t) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_dts_ord_74[] = { 1, DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, 15, 16, 17, 18, 19, DEVICE_HANDLE_ENDS };

/* 15 : /soc/i2c@40005400/hts221@5f:
 * Direct Dependencies:
 *    - /soc/i2c@40005400
 */
const Z_DECL_ALIGN(device_handle_t) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_dts_ord_75[] = { 14, DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 16 : /soc/i2c@40005400/lsm303agr-accel@19:
 * Direct Dependencies:
 *    - /soc/pin-controller@40020000/gpio@40020400
 *    - /soc/i2c@40005400
 */
const Z_DECL_ALIGN(device_handle_t) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_dts_ord_77[] = { 9, 14, DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 17 : /soc/i2c@40005400/lsm303agr-magn@1e:
 * Direct Dependencies:
 *    - /soc/pin-controller@40020000/gpio@40020400
 *    - /soc/i2c@40005400
 */
const Z_DECL_ALIGN(device_handle_t) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_dts_ord_78[] = { 9, 14, DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 18 : /soc/i2c@40005400/lps22hb-press@5d:
 * Direct Dependencies:
 *    - /soc/i2c@40005400
 */
const Z_DECL_ALIGN(device_handle_t) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_dts_ord_76[] = { 14, DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 19 : /soc/i2c@40005400/lsm6dsl@6b:
 * Direct Dependencies:
 *    - /soc/pin-controller@40020000/gpio@40020400
 *    - /soc/i2c@40005400
 */
const Z_DECL_ALIGN(device_handle_t) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_dts_ord_79[] = { 9, 14, DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };
