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



#define CPUCLK_FREQ                                                     32000000



/* Defines for PWM_SERVO */
#define PWM_SERVO_INST                                                     TIMA1
#define PWM_SERVO_INST_IRQHandler                               TIMA1_IRQHandler
#define PWM_SERVO_INST_INT_IRQN                                 (TIMA1_INT_IRQn)
#define PWM_SERVO_INST_CLK_FREQ                                          1000000
/* GPIO defines for channel 0 */
#define GPIO_PWM_SERVO_C0_PORT                                             GPIOA
#define GPIO_PWM_SERVO_C0_PIN                                     DL_GPIO_PIN_28
#define GPIO_PWM_SERVO_C0_IOMUX                                   (IOMUX_PINCM3)
#define GPIO_PWM_SERVO_C0_IOMUX_FUNC                  IOMUX_PINCM3_PF_TIMA1_CCP0
#define GPIO_PWM_SERVO_C0_IDX                                DL_TIMER_CC_0_INDEX

/* Defines for PWM_MOTOR_A */
#define PWM_MOTOR_A_INST                                                  TIMG12
#define PWM_MOTOR_A_INST_IRQHandler                            TIMG12_IRQHandler
#define PWM_MOTOR_A_INST_INT_IRQN                              (TIMG12_INT_IRQn)
#define PWM_MOTOR_A_INST_CLK_FREQ                                       32000000
/* GPIO defines for channel 0 */
#define GPIO_PWM_MOTOR_A_C0_PORT                                           GPIOA
#define GPIO_PWM_MOTOR_A_C0_PIN                                   DL_GPIO_PIN_14
#define GPIO_PWM_MOTOR_A_C0_IOMUX                                (IOMUX_PINCM36)
#define GPIO_PWM_MOTOR_A_C0_IOMUX_FUNC              IOMUX_PINCM36_PF_TIMG12_CCP0
#define GPIO_PWM_MOTOR_A_C0_IDX                              DL_TIMER_CC_0_INDEX

/* Defines for PWM_MOTOR_B */
#define PWM_MOTOR_B_INST                                                   TIMG7
#define PWM_MOTOR_B_INST_IRQHandler                             TIMG7_IRQHandler
#define PWM_MOTOR_B_INST_INT_IRQN                               (TIMG7_INT_IRQn)
#define PWM_MOTOR_B_INST_CLK_FREQ                                       32000000
/* GPIO defines for channel 0 */
#define GPIO_PWM_MOTOR_B_C0_PORT                                           GPIOA
#define GPIO_PWM_MOTOR_B_C0_PIN                                   DL_GPIO_PIN_17
#define GPIO_PWM_MOTOR_B_C0_IOMUX                                (IOMUX_PINCM39)
#define GPIO_PWM_MOTOR_B_C0_IOMUX_FUNC               IOMUX_PINCM39_PF_TIMG7_CCP0
#define GPIO_PWM_MOTOR_B_C0_IDX                              DL_TIMER_CC_0_INDEX



/* Defines for ENCODER_TIM */
#define ENCODER_TIM_INST                                                 (TIMG0)
#define ENCODER_TIM_INST_IRQHandler                             TIMG0_IRQHandler
#define ENCODER_TIM_INST_INT_IRQN                               (TIMG0_INT_IRQn)
#define ENCODER_TIM_INST_LOAD_VALUE                                      (7999U)



/* Defines for UART_0 */
#define UART_0_INST                                                        UART0
#define UART_0_INST_IRQHandler                                  UART0_IRQHandler
#define UART_0_INST_INT_IRQN                                      UART0_INT_IRQn
#define GPIO_UART_0_RX_PORT                                                GPIOA
#define GPIO_UART_0_TX_PORT                                                GPIOA
#define GPIO_UART_0_RX_PIN                                        DL_GPIO_PIN_11
#define GPIO_UART_0_TX_PIN                                        DL_GPIO_PIN_10
#define GPIO_UART_0_IOMUX_RX                                     (IOMUX_PINCM22)
#define GPIO_UART_0_IOMUX_TX                                     (IOMUX_PINCM21)
#define GPIO_UART_0_IOMUX_RX_FUNC                      IOMUX_PINCM22_PF_UART0_RX
#define GPIO_UART_0_IOMUX_TX_FUNC                      IOMUX_PINCM21_PF_UART0_TX
#define UART_0_BAUD_RATE                                                  (9600)
#define UART_0_IBRD_4_MHZ_9600_BAUD                                         (26)
#define UART_0_FBRD_4_MHZ_9600_BAUD                                          (3)





/* Port definition for Pin Group KEY */
#define KEY_PORT                                                         (GPIOA)

/* Defines for PIN_18: GPIOA.18 with pinCMx 40 on package pin 11 */
// groups represented: ["ENCODER","KEY"]
// pins affected: ["E1A","E1B","E2B","PIN_18"]
#define GPIO_MULTIPLE_GPIOA_INT_IRQN                            (GPIOA_INT_IRQn)
#define GPIO_MULTIPLE_GPIOA_INT_IIDX            (DL_INTERRUPT_GROUP1_IIDX_GPIOA)
#define KEY_PIN_18_IIDX                                     (DL_GPIO_IIDX_DIO18)
#define KEY_PIN_18_PIN                                          (DL_GPIO_PIN_18)
#define KEY_PIN_18_IOMUX                                         (IOMUX_PINCM40)
/* Port definition for Pin Group AIN */
#define AIN_PORT                                                         (GPIOA)

/* Defines for AIN1: GPIOA.12 with pinCMx 34 on package pin 5 */
#define AIN_AIN1_PIN                                            (DL_GPIO_PIN_12)
#define AIN_AIN1_IOMUX                                           (IOMUX_PINCM34)
/* Defines for AIN2: GPIOA.13 with pinCMx 35 on package pin 6 */
#define AIN_AIN2_PIN                                            (DL_GPIO_PIN_13)
#define AIN_AIN2_IOMUX                                           (IOMUX_PINCM35)
/* Port definition for Pin Group BIN */
#define BIN_PORT                                                         (GPIOA)

/* Defines for BIN1: GPIOA.15 with pinCMx 37 on package pin 8 */
#define BIN_BIN1_PIN                                            (DL_GPIO_PIN_15)
#define BIN_BIN1_IOMUX                                           (IOMUX_PINCM37)
/* Defines for BIN2: GPIOA.16 with pinCMx 38 on package pin 9 */
#define BIN_BIN2_PIN                                            (DL_GPIO_PIN_16)
#define BIN_BIN2_IOMUX                                           (IOMUX_PINCM38)
/* Port definition for Pin Group ENCODER */
#define ENCODER_PORT                                                     (GPIOA)

/* Defines for E1A: GPIOA.21 with pinCMx 46 on package pin 17 */
#define ENCODER_E1A_IIDX                                    (DL_GPIO_IIDX_DIO21)
#define ENCODER_E1A_PIN                                         (DL_GPIO_PIN_21)
#define ENCODER_E1A_IOMUX                                        (IOMUX_PINCM46)
/* Defines for E2A: GPIOA.23 with pinCMx 53 on package pin 24 */
#define ENCODER_E2A_PIN                                         (DL_GPIO_PIN_23)
#define ENCODER_E2A_IOMUX                                        (IOMUX_PINCM53)
/* Defines for E1B: GPIOA.22 with pinCMx 47 on package pin 18 */
#define ENCODER_E1B_IIDX                                    (DL_GPIO_IIDX_DIO22)
#define ENCODER_E1B_PIN                                         (DL_GPIO_PIN_22)
#define ENCODER_E1B_IOMUX                                        (IOMUX_PINCM47)
/* Defines for E2B: GPIOA.24 with pinCMx 54 on package pin 25 */
#define ENCODER_E2B_IIDX                                    (DL_GPIO_IIDX_DIO24)
#define ENCODER_E2B_PIN                                         (DL_GPIO_PIN_24)
#define ENCODER_E2B_IOMUX                                        (IOMUX_PINCM54)



/* clang-format on */

void SYSCFG_DL_init(void);
void SYSCFG_DL_initPower(void);
void SYSCFG_DL_GPIO_init(void);
void SYSCFG_DL_SYSCTL_init(void);
void SYSCFG_DL_PWM_SERVO_init(void);
void SYSCFG_DL_PWM_MOTOR_A_init(void);
void SYSCFG_DL_PWM_MOTOR_B_init(void);
void SYSCFG_DL_ENCODER_TIM_init(void);
void SYSCFG_DL_UART_0_init(void);

void SYSCFG_DL_SYSTICK_init(void);

bool SYSCFG_DL_saveConfiguration(void);
bool SYSCFG_DL_restoreConfiguration(void);

#ifdef __cplusplus
}
#endif

#endif /* ti_msp_dl_config_h */
