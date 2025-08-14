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

/* Defines for PWM_MOTOR_COPY */
#define PWM_MOTOR_COPY_INST                                                TIMG0
#define PWM_MOTOR_COPY_INST_IRQHandler                          TIMG0_IRQHandler
#define PWM_MOTOR_COPY_INST_INT_IRQN                            (TIMG0_INT_IRQn)
#define PWM_MOTOR_COPY_INST_CLK_FREQ                                    40000000
/* GPIO defines for channel 0 */
#define GPIO_PWM_MOTOR_COPY_C0_PORT                                        GPIOB
#define GPIO_PWM_MOTOR_COPY_C0_PIN                                DL_GPIO_PIN_10
#define GPIO_PWM_MOTOR_COPY_C0_IOMUX                             (IOMUX_PINCM27)
#define GPIO_PWM_MOTOR_COPY_C0_IOMUX_FUNC             IOMUX_PINCM27_PF_TIMG0_CCP0
#define GPIO_PWM_MOTOR_COPY_C0_IDX                           DL_TIMER_CC_0_INDEX
/* GPIO defines for channel 1 */
#define GPIO_PWM_MOTOR_COPY_C1_PORT                                        GPIOB
#define GPIO_PWM_MOTOR_COPY_C1_PIN                                DL_GPIO_PIN_11
#define GPIO_PWM_MOTOR_COPY_C1_IOMUX                             (IOMUX_PINCM28)
#define GPIO_PWM_MOTOR_COPY_C1_IOMUX_FUNC             IOMUX_PINCM28_PF_TIMG0_CCP1
#define GPIO_PWM_MOTOR_COPY_C1_IDX                           DL_TIMER_CC_1_INDEX

/* Defines for PWM_MOTOR_COPY_COPY */
#define PWM_MOTOR_COPY_COPY_INST                                           TIMG7
#define PWM_MOTOR_COPY_COPY_INST_IRQHandler                        TIMG7_IRQHandler
#define PWM_MOTOR_COPY_COPY_INST_INT_IRQN                        (TIMG7_INT_IRQn)
#define PWM_MOTOR_COPY_COPY_INST_CLK_FREQ                                80000000
/* GPIO defines for channel 0 */
#define GPIO_PWM_MOTOR_COPY_COPY_C0_PORT                                   GPIOA
#define GPIO_PWM_MOTOR_COPY_COPY_C0_PIN                           DL_GPIO_PIN_23
#define GPIO_PWM_MOTOR_COPY_COPY_C0_IOMUX                         (IOMUX_PINCM53)
#define GPIO_PWM_MOTOR_COPY_COPY_C0_IOMUX_FUNC             IOMUX_PINCM53_PF_TIMG7_CCP0
#define GPIO_PWM_MOTOR_COPY_COPY_C0_IDX                      DL_TIMER_CC_0_INDEX
/* GPIO defines for channel 1 */
#define GPIO_PWM_MOTOR_COPY_COPY_C1_PORT                                   GPIOA
#define GPIO_PWM_MOTOR_COPY_COPY_C1_PIN                           DL_GPIO_PIN_18
#define GPIO_PWM_MOTOR_COPY_COPY_C1_IOMUX                         (IOMUX_PINCM40)
#define GPIO_PWM_MOTOR_COPY_COPY_C1_IOMUX_FUNC             IOMUX_PINCM40_PF_TIMG7_CCP1
#define GPIO_PWM_MOTOR_COPY_COPY_C1_IDX                      DL_TIMER_CC_1_INDEX



/* Defines for TIMER_0 */
#define TIMER_0_INST                                                     (TIMA0)
#define TIMER_0_INST_IRQHandler                                 TIMA0_IRQHandler
#define TIMER_0_INST_INT_IRQN                                   (TIMA0_INT_IRQn)
#define TIMER_0_INST_LOAD_VALUE                                           (399U)
/* Defines for TIMER_1 */
#define TIMER_1_INST                                                     (TIMG6)
#define TIMER_1_INST_IRQHandler                                 TIMG6_IRQHandler
#define TIMER_1_INST_INT_IRQN                                   (TIMG6_INT_IRQn)
#define TIMER_1_INST_LOAD_VALUE                                           (199U)




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
#define UART_0_DEBUG_BAUD_RATE                                          (115200)
#define UART_0_DEBUG_IBRD_4_MHZ_115200_BAUD                                  (2)
#define UART_0_DEBUG_FBRD_4_MHZ_115200_BAUD                                 (11)
/* Defines for UART_3 */
#define UART_3_INST                                                        UART3
#define UART_3_INST_IRQHandler                                  UART3_IRQHandler
#define UART_3_INST_INT_IRQN                                      UART3_INT_IRQn
#define GPIO_UART_3_RX_PORT                                                GPIOA
#define GPIO_UART_3_TX_PORT                                                GPIOA
#define GPIO_UART_3_RX_PIN                                        DL_GPIO_PIN_13
#define GPIO_UART_3_TX_PIN                                        DL_GPIO_PIN_26
#define GPIO_UART_3_IOMUX_RX                                     (IOMUX_PINCM35)
#define GPIO_UART_3_IOMUX_TX                                     (IOMUX_PINCM59)
#define GPIO_UART_3_IOMUX_RX_FUNC                      IOMUX_PINCM35_PF_UART3_RX
#define GPIO_UART_3_IOMUX_TX_FUNC                      IOMUX_PINCM59_PF_UART3_TX
#define UART_3_BAUD_RATE                                                (115200)
#define UART_3_IBRD_4_MHZ_115200_BAUD                                        (2)
#define UART_3_FBRD_4_MHZ_115200_BAUD                                       (11)
/* Defines for UART_1 */
#define UART_1_INST                                                        UART1
#define UART_1_INST_IRQHandler                                  UART1_IRQHandler
#define UART_1_INST_INT_IRQN                                      UART1_INT_IRQn
#define GPIO_UART_1_RX_PORT                                                GPIOB
#define GPIO_UART_1_TX_PORT                                                GPIOA
#define GPIO_UART_1_RX_PIN                                         DL_GPIO_PIN_5
#define GPIO_UART_1_TX_PIN                                        DL_GPIO_PIN_17
#define GPIO_UART_1_IOMUX_RX                                     (IOMUX_PINCM18)
#define GPIO_UART_1_IOMUX_TX                                     (IOMUX_PINCM39)
#define GPIO_UART_1_IOMUX_RX_FUNC                      IOMUX_PINCM18_PF_UART1_RX
#define GPIO_UART_1_IOMUX_TX_FUNC                      IOMUX_PINCM39_PF_UART1_TX
#define UART_1_BAUD_RATE                                                (115200)
#define UART_1_IBRD_4_MHZ_115200_BAUD                                        (2)
#define UART_1_FBRD_4_MHZ_115200_BAUD                                       (11)





/* Defines for DMA_CH2 */
#define DMA_CH2_CHAN_ID                                                      (0)
#define UART_1_INST_DMA_TRIGGER                              (DMA_UART1_TX_TRIG)



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
/* Defines for PIN_27: GPIOA.27 with pinCMx 60 on package pin 31 */
#define KEY_PIN_27_PIN                                          (DL_GPIO_PIN_27)
#define KEY_PIN_27_IOMUX                                         (IOMUX_PINCM60)
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
/* Defines for track1: GPIOB.1 with pinCMx 13 on package pin 48 */
#define TRACK_track1_PORT                                                (GPIOB)
#define TRACK_track1_PIN                                         (DL_GPIO_PIN_1)
#define TRACK_track1_IOMUX                                       (IOMUX_PINCM13)
/* Defines for track2: GPIOB.0 with pinCMx 12 on package pin 47 */
#define TRACK_track2_PORT                                                (GPIOB)
#define TRACK_track2_PIN                                         (DL_GPIO_PIN_0)
#define TRACK_track2_IOMUX                                       (IOMUX_PINCM12)
/* Defines for track3: GPIOA.30 with pinCMx 5 on package pin 37 */
#define TRACK_track3_PORT                                                (GPIOA)
#define TRACK_track3_PIN                                        (DL_GPIO_PIN_30)
#define TRACK_track3_IOMUX                                        (IOMUX_PINCM5)
/* Defines for track4: GPIOB.22 with pinCMx 50 on package pin 21 */
#define TRACK_track4_PORT                                                (GPIOB)
#define TRACK_track4_PIN                                        (DL_GPIO_PIN_22)
#define TRACK_track4_IOMUX                                       (IOMUX_PINCM50)
/* Defines for track5: GPIOB.21 with pinCMx 49 on package pin 20 */
#define TRACK_track5_PORT                                                (GPIOB)
#define TRACK_track5_PIN                                        (DL_GPIO_PIN_21)
#define TRACK_track5_IOMUX                                       (IOMUX_PINCM49)
/* Defines for track6: GPIOA.22 with pinCMx 47 on package pin 18 */
#define TRACK_track6_PORT                                                (GPIOA)
#define TRACK_track6_PIN                                        (DL_GPIO_PIN_22)
#define TRACK_track6_IOMUX                                       (IOMUX_PINCM47)
/* Defines for track7: GPIOB.25 with pinCMx 56 on package pin 27 */
#define TRACK_track7_PORT                                                (GPIOB)
#define TRACK_track7_PIN                                        (DL_GPIO_PIN_25)
#define TRACK_track7_IOMUX                                       (IOMUX_PINCM56)
/* Defines for track8: GPIOA.25 with pinCMx 55 on package pin 26 */
#define TRACK_track8_PORT                                                (GPIOA)
#define TRACK_track8_PIN                                        (DL_GPIO_PIN_25)
#define TRACK_track8_IOMUX                                       (IOMUX_PINCM55)
/* Defines for track9: GPIOB.13 with pinCMx 30 on package pin 1 */
#define TRACK_track9_PORT                                                (GPIOB)
#define TRACK_track9_PIN                                        (DL_GPIO_PIN_13)
#define TRACK_track9_IOMUX                                       (IOMUX_PINCM30)
/* Defines for track10: GPIOB.9 with pinCMx 26 on package pin 61 */
#define TRACK_track10_PORT                                               (GPIOB)
#define TRACK_track10_PIN                                        (DL_GPIO_PIN_9)
#define TRACK_track10_IOMUX                                      (IOMUX_PINCM26)
/* Defines for track11: GPIOB.26 with pinCMx 57 on package pin 28 */
#define TRACK_track11_PORT                                               (GPIOB)
#define TRACK_track11_PIN                                       (DL_GPIO_PIN_26)
#define TRACK_track11_IOMUX                                      (IOMUX_PINCM57)
/* Defines for track12: GPIOA.29 with pinCMx 4 on package pin 36 */
#define TRACK_track12_PORT                                               (GPIOA)
#define TRACK_track12_PIN                                       (DL_GPIO_PIN_29)
#define TRACK_track12_IOMUX                                       (IOMUX_PINCM4)
/* Port definition for Pin Group IIC_Software */
#define IIC_Software_PORT                                                (GPIOA)

/* Defines for SCL: GPIOA.1 with pinCMx 2 on package pin 34 */
#define IIC_Software_SCL_PIN                                     (DL_GPIO_PIN_1)
#define IIC_Software_SCL_IOMUX                                    (IOMUX_PINCM2)
/* Defines for SDA: GPIOA.0 with pinCMx 1 on package pin 33 */
#define IIC_Software_SDA_PIN                                     (DL_GPIO_PIN_0)
#define IIC_Software_SDA_IOMUX                                    (IOMUX_PINCM1)
/* Port definition for Pin Group STRA_MOTOR */
#define STRA_MOTOR_PORT                                                  (GPIOA)

/* Defines for PIN_0: GPIOA.8 with pinCMx 19 on package pin 54 */
#define STRA_MOTOR_PIN_0_PIN                                     (DL_GPIO_PIN_8)
#define STRA_MOTOR_PIN_0_IOMUX                                   (IOMUX_PINCM19)
/* Defines for PIN_1: GPIOA.9 with pinCMx 20 on package pin 55 */
#define STRA_MOTOR_PIN_1_PIN                                     (DL_GPIO_PIN_9)
#define STRA_MOTOR_PIN_1_IOMUX                                   (IOMUX_PINCM20)
/* Defines for CE: GPIOB.15 with pinCMx 32 on package pin 3 */
#define SPI_connect_CE_PORT                                              (GPIOB)
#define SPI_connect_CE_PIN                                      (DL_GPIO_PIN_15)
#define SPI_connect_CE_IOMUX                                     (IOMUX_PINCM32)
/* Defines for SCK: GPIOB.2 with pinCMx 15 on package pin 50 */
#define SPI_connect_SCK_PORT                                             (GPIOB)
#define SPI_connect_SCK_PIN                                      (DL_GPIO_PIN_2)
#define SPI_connect_SCK_IOMUX                                    (IOMUX_PINCM15)
/* Defines for MISO: GPIOB.3 with pinCMx 16 on package pin 51 */
#define SPI_connect_MISO_PORT                                            (GPIOB)
#define SPI_connect_MISO_PIN                                     (DL_GPIO_PIN_3)
#define SPI_connect_MISO_IOMUX                                   (IOMUX_PINCM16)
/* Defines for CSN: GPIOA.12 with pinCMx 34 on package pin 5 */
#define SPI_connect_CSN_PORT                                             (GPIOA)
#define SPI_connect_CSN_PIN                                     (DL_GPIO_PIN_12)
#define SPI_connect_CSN_IOMUX                                    (IOMUX_PINCM34)
/* Defines for MOSI: GPIOB.23 with pinCMx 51 on package pin 22 */
#define SPI_connect_MOSI_PORT                                            (GPIOB)
#define SPI_connect_MOSI_PIN                                    (DL_GPIO_PIN_23)
#define SPI_connect_MOSI_IOMUX                                   (IOMUX_PINCM51)
/* Defines for IRQ: GPIOB.27 with pinCMx 58 on package pin 29 */
#define SPI_connect_IRQ_PORT                                             (GPIOB)
#define SPI_connect_IRQ_PIN                                     (DL_GPIO_PIN_27)
#define SPI_connect_IRQ_IOMUX                                    (IOMUX_PINCM58)
/* Defines for PIN_2: GPIOB.16 with pinCMx 33 on package pin 4 */
#define SPI_connect_PIN_2_PORT                                           (GPIOB)
#define SPI_connect_PIN_2_PIN                                   (DL_GPIO_PIN_16)
#define SPI_connect_PIN_2_IOMUX                                  (IOMUX_PINCM33)
/* Defines for PIN_3: GPIOB.17 with pinCMx 43 on package pin 14 */
#define SPI_connect_PIN_3_PORT                                           (GPIOB)
#define SPI_connect_PIN_3_PIN                                   (DL_GPIO_PIN_17)
#define SPI_connect_PIN_3_IOMUX                                  (IOMUX_PINCM43)



/* clang-format on */

void SYSCFG_DL_init(void);
void SYSCFG_DL_initPower(void);
void SYSCFG_DL_GPIO_init(void);
void SYSCFG_DL_SYSCTL_init(void);
void SYSCFG_DL_PWM_MOTOR_init(void);
void SYSCFG_DL_PWM_MOTOR_COPY_init(void);
void SYSCFG_DL_PWM_MOTOR_COPY_COPY_init(void);
void SYSCFG_DL_TIMER_0_init(void);
void SYSCFG_DL_TIMER_1_init(void);
void SYSCFG_DL_I2C_OLED_init(void);
void SYSCFG_DL_UART_0_DEBUG_init(void);
void SYSCFG_DL_UART_3_init(void);
void SYSCFG_DL_UART_1_init(void);
void SYSCFG_DL_DMA_init(void);

void SYSCFG_DL_SYSTICK_init(void);

bool SYSCFG_DL_saveConfiguration(void);
bool SYSCFG_DL_restoreConfiguration(void);

#ifdef __cplusplus
}
#endif

#endif /* ti_msp_dl_config_h */
