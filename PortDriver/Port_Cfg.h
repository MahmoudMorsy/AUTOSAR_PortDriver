 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port_Cfg.h
 *
 * Description: Pre-Compile Configuration Header file for Port Module.
 *
 * Author: Mahmoud MORSY
 ******************************************************************************/
#ifndef PORT_CFG_H
#define PORT_CFG_H


/******************************************************************************
 *                             AUTOSAR Module Info                            *
 ******************************************************************************/
/*
 * Module Version 1.0.0
 */
#define PORT_CFG_SW_MAJOR_VERSION                                           (1U)
#define PORT_CFG_SW_MINOR_VERSION                                           (0U)
#define PORT_CFG_SW_PATCH_VERSION                                           (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_CFG_AR_RELEASE_MAJOR_VERSION                                   (4U)
#define PORT_CFG_AR_RELEASE_MINOR_VERSION                                   (0U)
#define PORT_CFG_AR_RELEASE_PATCH_VERSION                                   (3U)

/******************************************************************************
 *               PRE-Compile Configuration Options & Parameters               *
 ******************************************************************************/
/* Pre-compile option for Development Error Detect */
#define PORT_DEV_ERROR_DETECT                                           (STD_OFF)

/* Pre-compile option for Set Pin Direction API */
#define PORT_SET_PIN_DIRECTION_API                                      (STD_ON)

/* Pre-compile option for Set Pin Mode API */
#define PORT_SET_PIN_MODE_API                                           (STD_ON)

/* Pre-compile option for Get Version Info API */
#define PORT_VERSION_INFO_API                                           (STD_ON)

/* Pre-compile option for number of allowed pin modes per each pin */
#define PORT_NUMBER_OF_ALLOWED_PIN_MODES                                    (1U)

/* Pre-compile parameter for number of pins per each port */
#define PORT_NUMBER_OF_PORT_PINS                                            (8U)

/* Pre-compile parameter for number of ports in the controller */
#define PORT_NUMBER_OF_PORTS                                                (4U)

/* Pre-compile parameter for total number of pins in the controller */
#define PORT_NUMBER_OF_PINS                                                (32U)



/******************************************************************************
 *                   Generated Enumeration for Pin Names & IDs                *
 ******************************************************************************/
enum Port_PinNames
{
	/* Symbolic Name for Pin 0 in Port 0 */
	PORT_PIN_0,
	/* Symbolic Name for Pin 1 in Port 0 */
	PORT_PIN_1,
	/* Symbolic Name for Pin 2 in Port 0 */
	PORT_PIN_2,
	/* Symbolic Name for Pin 3 in Port 0 */
	PORT_PIN_3,
	/* Symbolic Name for Pin 4 in Port 0 */
	PORT_PIN_4,
	/* Symbolic Name for Pin 5 in Port 0 */
	PORT_PIN_5,
	/* Symbolic Name for Pin 6 in Port 0 */
	PORT_PIN_6,
	/* Symbolic Name for Pin 7 in Port 0 */
	PORT_PIN_7,
	/* Symbolic Name for Pin 0 in Port 1 */
	PORT_PIN_8,
	/* Symbolic Name for Pin 1 in Port 1 */
	PORT_PIN_9,
	/* Symbolic Name for Pin 2 in Port 1 */
	PORT_PIN_10,
	/* Symbolic Name for Pin 3 in Port 1 */
	PORT_PIN_11,
	/* Symbolic Name for Pin 4 in Port 1 */
	PORT_PIN_12,
	/* Symbolic Name for Pin 5 in Port 1 */
	PORT_PIN_13,
	/* Symbolic Name for Pin 6 in Port 1 */
	PORT_PIN_14,
	/* Symbolic Name for Pin 7 in Port 1 */
	PORT_PIN_15,
	/* Symbolic Name for Pin 0 in Port 2 */
	PORT_PIN_16,
	/* Symbolic Name for Pin 1 in Port 2 */
	PORT_PIN_17,
	/* Symbolic Name for Pin 2 in Port 2 */
	PORT_PIN_18,
	/* Symbolic Name for Pin 3 in Port 2 */
	PORT_PIN_19,
	/* Symbolic Name for Pin 4 in Port 2 */
	PORT_PIN_20,
	/* Symbolic Name for Pin 5 in Port 2 */
	PORT_PIN_21_LED_CHANNEL,
	/* Symbolic Name for Pin 6 in Port 2 */
	PORT_PIN_22,
	/* Symbolic Name for Pin 7 in Port 2 */
	PORT_PIN_23,
	/* Symbolic Name for Pin 0 in Port 3 */
	PORT_PIN_24,
	/* Symbolic Name for Pin 1 in Port 3 */
	PORT_PIN_25,
	/* Symbolic Name for Pin 2 in Port 3 */
	PORT_PIN_26_BUTTON_CHANNEL,
	/* Symbolic Name for Pin 3 in Port 3 */
	PORT_PIN_27,
	/* Symbolic Name for Pin 4 in Port 3 */
	PORT_PIN_28,
	/* Symbolic Name for Pin 5 in Port 3 */
	PORT_PIN_29,
	/* Symbolic Name for Pin 6 in Port 3 */
	PORT_PIN_30,
	/* Symbolic Name for Pin 7 in Port 3 */
	PORT_PIN_31,
};

#endif /* PORT_CFG_H */
