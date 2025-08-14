/*
 * Copyright (c) 2023, Texas Instruments Incorporated - http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ============ ti_msp_dl_config.h =============
 *  Configured MSPM0 DriverLib module declarations
 *
 *  DO NOT EDIT - This file is generated for the MSPM0G350X
 *  by the SysConfig tool.
 */
#ifndef ti_msp_dl_config_h
#define ti_msp_dl_config_h

#define CONFIG_MSPM0G350X

#if defined(__ti_version__) || defined(__TI_COMPILER_VERSION__)
#define SYSCONFIG_WEAK __attribute__((weak))
#elif defined(__IAR_SYSTEMS_ICC__)
#define SYSCONFIG_WEAK __weak
#elif defined(__GNUC__)
#define SYSCONFIG_WEAK __attribute__((weak))
#endif

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/driverlib.h>
#include <ti/driverlib/m0p/dl_core.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform all required MSP DL initialization
 *
 *  This function should be called once at a point before any use of
 *  MSP DL.
 */


/* clang-format off */

#define POWER_STARTUP_DELAY                                                (16)


#define GPIO_HFXT_PORT                                                     GPIOA
#define GPIO_HFXIN_PIN                                             DL_GPIO_PIN_5
#define GPIO_HFXIN_IOMUX                                         (IOMUX_PINCM10)
#define GPIO_HFXOUT_PIN                                            DL_GPIO_PIN_6
#define GPIO_HFXOUT_IOMUX                                        (IOMUX_PINCM11)
#define CPUCLK_FREQ                                                     80000000



/* Defines for PWM_MOTOR */
#define PWM_MOTOR_INST                                                     TIMA1
#define PWM_MOTOR_INST_IRQHandler                               TIMA1_IRQHandler
#define PWM_MOTOR_INST_INT_IRQN                                 (TIMA1_INT_IRQn)
#define PWM_MOTOR_INST_CLK_FREQ                                         80000000
/* GPIO defines for channel 0 */
#define GPIO_PWM_MOTOR_C0_PORT                                             GPIOB
#define GPIO_PWM_MOTOR_C0_PIN                                      DL_GPIO_PIN_4
#define GPIO_PWM_MOTOR_C0_IOMUX                                  (IOMUX_PINCM17)
#define GPIO_PWM_MOTOR_C0_IOMUX_FUNC                 IOMUX_PINCM17_PF_TIMA1_CCP0
#define GPIO_PWM_MOTOR_C0_IDX                                DL_TIMER_CC_0_INDEX
/* GPIO defines for channel 1 */
#define GPIO_PWM_MOTOR_C1_PORT                                             GPIOA
#define GPIO_PWM_MOTOR_C1_PIN                                     DL_GPIO_PIN_24
#define GPIO_PWM_MOTOR_C1_IOMUX                                  (IOMUX_PINCM54)
#define GPIO_PWM_MOTOR_C1_IOMUX_FUNC                 IOMUX_PINCM54_PF_TIMA1_CCP1
#define GPIO_PWM_MOTOR_C1_IDX                                DL_TIMER_CC_1_INDEX



/* Defines for TIMER_0 */
#define TIMER_0_INST                                                     (TIMA0)
#define TIMER_0_INST_IRQHandler                                 TIMA0_IRQHandler
#define TIMER_0_INST_INT_IRQN                                   (TIMA0_INT_IRQn)
#define TIMER_0_INST_LOAD_VALUE                                            (99U)




/* Defines for I2C_OLED */
#define I2C_OLED_INST                                                       I2C0
#define I2C_OLED_INST_IRQHandler                                 I2C0_IRQHandler
#define I2C_OLED_INST_INT_IRQN                                     I2C0_INT_IRQn
#define I2C_OLED_BUS_SPEED_HZ                                             500000
#define GPIO_I2C_OLED_SDA_PORT                                             GPIOA
#define GPIO_I2C_OLED_SDA_PIN                                     DL_GPIO_PIN_28
#define GPIO_I2C_OLED_IOMUX_SDA                                   (IOMUX_PINCM3)
#define GPIO_I2C_OLED_IOMUX_SDA_FUNC                    IOMUX_PINCM3_PF_I2C0_SDA
#define GPIO_I2C_OLED_SCL_PORT                                             GPIOA
#define GPIO_I2C_OLED_SCL_PIN                                     DL_GPIO_PIN_31
#define GPIO_I2C_OLED_IOMUX_SCL                                   (IOMUX_PINCM6)
#define GPIO_I2C_OLED_IOMUX_SCL_FUNC                    IOMUX_PINCM6_PF_I2C0_SCL


/* Defines for UART_0_DEBUG */
#define UART_0_DEBUG_INST                                                  UART0
#define UART_0_DEBUG_INST_IRQHandler                            UART0_IRQHandler
#define UART_0_DEBUG_INST_INT_IRQN                                UART0_INT_IRQn
#define GPIO_UART_0_DEBUG_RX_PORT                                          GPIOA
#define GPIO_UART_0_DEBUG_TX_PORT                                          GPIOA
#define GPIO_UART_0_DEBUG_RX_PIN                                  DL_GPIO_PIN_11
#define GPIO_UART_0_DEBUG_TX_PIN                                  DL_GPIO_PIN_10
#define GPIO_UART_0_DEBUG_IOMUX_RX                               (IOMUX_PINCM22)
#define GPIO_UART_0_DEBUG_IOMUX_TX                               (IOMUX_PINCM21)
#define GPIO_UART_0_DEBUG_IOMUX_RX_FUNC                IOMUX_PINCM22_PF_UART0_RX
#define GPIO_UART_0_DEBUG_IOMUX_TX_FUNC                IOMUX_PINCM21_PF_UART0_TX
#define UART_0_DEBUG_BAUD_RATE                                            (9600)
#define UART_0_DEBUG_IBRD_4_MHZ_9600_BAUD                                   (26)
#define UART_0_DEBUG_FBRD_4_MHZ_9600_BAUD                                    (3)
/* Defines for UART_JY61P */
#define UART_JY61P_INST                                                    UART2
#define UART_JY61P_INST_IRQHandler                              UART2_IRQHandler
#define UART_JY61P_INST_INT_IRQN                                  UART2_INT_IRQn
#define GPIO_UART_JY61P_RX_PORT                                            GPIOB
#define GPIO_UART_JY61P_TX_PORT                                            GPIOB
#define GPIO_UART_JY61P_RX_PIN                                    DL_GPIO_PIN_16
#define GPIO_UART_JY61P_TX_PIN                                    DL_GPIO_PIN_17
#define GPIO_UART_JY61P_IOMUX_RX                                 (IOMUX_PINCM33)
#define GPIO_UART_JY61P_IOMUX_TX                                 (IOMUX_PINCM43)
#define GPIO_UART_JY61P_IOMUX_RX_FUNC                  IOMUX_PINCM33_PF_UART2_RX
#define GPIO_UART_JY61P_IOMUX_TX_FUNC                  IOMUX_PINCM43_PF_UART2_TX
#define UART_JY61P_BAUD_RATE                                              (9600)
#define UART_JY61P_IBRD_4_MHZ_9600_BAUD                                     (26)
#define UART_JY61P_FBRD_4_MHZ_9600_BAUD                                      (3)





/* Port definition for Pin Group LED1 */
#define LED1_PORT                                                        (GPIOA)

/* Defines for PIN_14: GPIOA.14 with pinCMx 36 on package pin 7 */
#define LED1_PIN_14_PIN                                         (DL_GPIO_PIN_14)
#define LED1_PIN_14_IOMUX                                        (IOMUX_PINCM36)
/* Port definition for Pin Group BEEP */
#define BEEP_PORT                                                        (GPIOB)

/* Defines for PIN_12: GPIOB.12 with pinCMx 29 on package pin 64 */
#define BEEP_PIN_12_PIN                                         (DL_GPIO_PIN_12)
#define BEEP_PIN_12_IOMUX                                        (IOMUX_PINCM29)
/* Port definition for Pin Group KEY */
#define KEY_PORT                                                         (GPIOA)

/* Defines for PIN_15: GPIOA.15 with pinCMx 37 on package pin 8 */
// pins affected by this interrupt request:["PIN_15"]
#define KEY_INT_IRQN                                            (GPIOA_INT_IRQn)
#define KEY_INT_IIDX                            (DL_INTERRUPT_GROUP1_IIDX_GPIOA)
#define KEY_PIN_15_IIDX                                     (DL_GPIO_IIDX_DIO15)
#define KEY_PIN_15_PIN                                          (DL_GPIO_PIN_15)
#define KEY_PIN_15_IOMUX                                         (IOMUX_PINCM37)
/* Defines for PIN_16: GPIOA.16 with pinCMx 38 on package pin 9 */
#define KEY_PIN_16_PIN                                          (DL_GPIO_PIN_16)
#define KEY_PIN_16_IOMUX                                         (IOMUX_PINCM38)
/* Defines for PIN_17: GPIOA.17 with pinCMx 39 on package pin 10 */
#define KEY_PIN_17_PIN                                          (DL_GPIO_PIN_17)
#define KEY_PIN_17_IOMUX                                         (IOMUX_PINCM39)
/* Defines for PIN_21: GPIOA.21 with pinCMx 46 on package pin 17 */
#define KEY_PIN_21_PIN                                          (DL_GPIO_PIN_21)
#define KEY_PIN_21_IOMUX                                         (IOMUX_PINCM46)
/* Port definition for Pin Group ENCODER */
#define ENCODER_PORT                                                     (GPIOB)

/* Defines for E1A: GPIOB.18 with pinCMx 44 on package pin 15 */
// pins affected by this interrupt request:["E1A","E1B","E2A","E2B"]
#define ENCODER_INT_IRQN                                        (GPIOB_INT_IRQn)
#define ENCODER_INT_IIDX                        (DL_INTERRUPT_GROUP1_IIDX_GPIOB)
#define ENCODER_E1A_IIDX                                    (DL_GPIO_IIDX_DIO18)
#define ENCODER_E1A_PIN                                         (DL_GPIO_PIN_18)
#define ENCODER_E1A_IOMUX                                        (IOMUX_PINCM44)
/* Defines for E1B: GPIOB.6 with pinCMx 23 on package pin 58 */
#define ENCODER_E1B_IIDX                                     (DL_GPIO_IIDX_DIO6)
#define ENCODER_E1B_PIN                                          (DL_GPIO_PIN_6)
#define ENCODER_E1B_IOMUX                                        (IOMUX_PINCM23)
/* Defines for E2A: GPIOB.7 with pinCMx 24 on package pin 59 */
#define ENCODER_E2A_IIDX                                     (DL_GPIO_IIDX_DIO7)
#define ENCODER_E2A_PIN                                          (DL_GPIO_PIN_7)
#define ENCODER_E2A_IOMUX                                        (IOMUX_PINCM24)
/* Defines for E2B: GPIOB.8 with pinCMx 25 on package pin 60 */
#define ENCODER_E2B_IIDX                                     (DL_GPIO_IIDX_DIO8)
#define ENCODER_E2B_PIN                                          (DL_GPIO_PIN_8)
#define ENCODER_E2B_IOMUX                                        (IOMUX_PINCM25)
/* Defines for AIN1_A02: GPIOA.2 with pinCMx 7 on package pin 42 */
#define MOTOR_AIN1_A02_PORT                                              (GPIOA)
#define MOTOR_AIN1_A02_PIN                                       (DL_GPIO_PIN_2)
#define MOTOR_AIN1_A02_IOMUX                                      (IOMUX_PINCM7)
/* Defines for AIN2_B24: GPIOB.24 with pinCMx 52 on package pin 23 */
#define MOTOR_AIN2_B24_PORT                                              (GPIOB)
#define MOTOR_AIN2_B24_PIN                                      (DL_GPIO_PIN_24)
#define MOTOR_AIN2_B24_IOMUX                                     (IOMUX_PINCM52)
/* Defines for BIN1_B20: GPIOB.20 with pinCMx 48 on package pin 19 */
#define MOTOR_BIN1_B20_PORT                                              (GPIOB)
#define MOTOR_BIN1_B20_PIN                                      (DL_GPIO_PIN_20)
#define MOTOR_BIN1_B20_IOMUX                                     (IOMUX_PINCM48)
/* Defines for BIN2_B19: GPIOB.19 with pinCMx 45 on package pin 16 */
#define MOTOR_BIN2_B19_PORT                                              (GPIOB)
#define MOTOR_BIN2_B19_PIN                                      (DL_GPIO_PIN_19)
#define MOTOR_BIN2_B19_IOMUX                                     (IOMUX_PINCM45)
/* Port definition for Pin Group GYRO */
#define GYRO_PORT                                                        (GPIOA)

/* Defines for SCL: GPIOA.1 with pinCMx 2 on package pin 34 */
#define GYRO_SCL_PIN                                             (DL_GPIO_PIN_1)
#define GYRO_SCL_IOMUX                                            (IOMUX_PINCM2)
/* Defines for SDA: GPIOA.0 with pinCMx 1 on package pin 33 */
#define GYRO_SDA_PIN                                             (DL_GPIO_PIN_0)
#define GYRO_SDA_IOMUX                                            (IOMUX_PINCM1)
/* Defines for S1: GPIOA.25 with pinCMx 55 on package pin 26 */
#define TRACK_S1_PORT                                                    (GPIOA)
#define TRACK_S1_PIN                                            (DL_GPIO_PIN_25)
#define TRACK_S1_IOMUX                                           (IOMUX_PINCM55)
/* Defines for S2: GPIOA.12 with pinCMx 34 on package pin 5 */
#define TRACK_S2_PORT                                                    (GPIOA)
#define TRACK_S2_PIN                                            (DL_GPIO_PIN_12)
#define TRACK_S2_IOMUX                                           (IOMUX_PINCM34)
/* Defines for S3: GPIOA.22 with pinCMx 47 on package pin 18 */
#define TRACK_S3_PORT                                                    (GPIOA)
#define TRACK_S3_PIN                                            (DL_GPIO_PIN_22)
#define TRACK_S3_IOMUX                                           (IOMUX_PINCM47)
/* Defines for S4: GPIOA.13 with pinCMx 35 on package pin 6 */
#define TRACK_S4_PORT                                                    (GPIOA)
#define TRACK_S4_PIN                                            (DL_GPIO_PIN_13)
#define TRACK_S4_IOMUX                                           (IOMUX_PINCM35)
/* Defines for S5: GPIOB.9 with pinCMx 26 on package pin 61 */
#define TRACK_S5_PORT                                                    (GPIOB)
#define TRACK_S5_PIN                                             (DL_GPIO_PIN_9)
#define TRACK_S5_IOMUX                                           (IOMUX_PINCM26)
/* Port definition for Pin Group OLED */
#define OLED_PORT                                                        (GPIOB)

/* Defines for RES: GPIOB.10 with pinCMx 27 on package pin 62 */
#define OLED_RES_PIN                                            (DL_GPIO_PIN_10)
#define OLED_RES_IOMUX                                           (IOMUX_PINCM27)
/* Defines for DC: GPIOB.1 with pinCMx 13 on package pin 48 */
#define OLED_DC_PIN                                              (DL_GPIO_PIN_1)
#define OLED_DC_IOMUX                                            (IOMUX_PINCM13)
/* Defines for CS: GPIOB.0 with pinCMx 12 on package pin 47 */
#define OLED_CS_PIN                                              (DL_GPIO_PIN_0)
#define OLED_CS_IOMUX                                            (IOMUX_PINCM12)



/* clang-format on */

void SYSCFG_DL_init(void);
void SYSCFG_DL_initPower(void);
void SYSCFG_DL_GPIO_init(void);
void SYSCFG_DL_SYSCTL_init(void);
void SYSCFG_DL_PWM_MOTOR_init(void);
void SYSCFG_DL_TIMER_0_init(void);
void SYSCFG_DL_I2C_OLED_init(void);
void SYSCFG_DL_UART_0_DEBUG_init(void);
void SYSCFG_DL_UART_JY61P_init(void);

void SYSCFG_DL_SYSTICK_init(void);

bool SYSCFG_DL_saveConfiguration(void);
bool SYSCFG_DL_restoreConfiguration(void);

#ifdef __cplusplus
}
#endif

#endif /* ti_msp_dl_config_h */
