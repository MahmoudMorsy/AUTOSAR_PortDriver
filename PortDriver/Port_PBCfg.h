/*
 * Port_PBCfg.h
 *
 *  Created on: Apr 20, 2019
 *      Author: MORSY
 */

#ifndef PORTDRIVER_PORT_PBCFG_H_
#define PORTDRIVER_PORT_PBCFG_H_

/******************************************************************************
 *                             AUTOSAR Module Info                            *
 ******************************************************************************/
/*
 * Module Version 1.0.0
 */
#define PORT_PBCFG_SW_MAJOR_VERSION                                        (1U)
#define PORT_PBCFG_SW_MINOR_VERSION                                        (0U)
#define PORT_PBCFG_SW_PATCH_VERSION                                        (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_PBCFG_AR_RELEASE_MAJOR_VERSION                                (4U)
#define PORT_PBCFG_AR_RELEASE_MINOR_VERSION                                (0U)
#define PORT_PBCFG_AR_RELEASE_PATCH_VERSION                                (3U)

/******************************************************************************
 *                        Configuration Options & Parameters                  *
 ******************************************************************************/

/* Option for default pin level value */
#define PORT_DEFAULT_PIN_LEVEL_VALUE       (Port_PinLevelType)PORT_PIN_LEVEL_LOW

/* Option for default pin direction */
#define PORT_DEFAULT_PIN_DIRECTION           (Port_PinDirectionType)PORT_PIN_OUT

/* Option for default pin mode */
#define PORT_DEFAULT_PIN_MODE                (Port_PinModeType)PORT_PIN_MODE_DIO

/* Option for default direction changeable option */
#define PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE\
                                               PORT_PIN_DIRECTION_NOT_CHANGEABLE

/* Option for default mode changeable option */
#define PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE                  (boolean)STD_OFF

#endif /* PORTDRIVER_PORT_PBCFG_H_ */
