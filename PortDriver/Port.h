 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.h
 *
 * Description: Header file for Port Module.
 *
 * Author: Mahmoud MORSY
 ******************************************************************************/

#ifndef PORT_H
#define PORT_H


/******************************************************************************
 *                             Included Libraries                             *
 ******************************************************************************/
/* Standard AUTOSAR types */
#include "..\Std_Types.h"
/* Port Pre-Compile Configuration Header file */
#include "Port_Cfg.h"


/******************************************************************************
 *                             AUTOSAR Module Info                            *
 ******************************************************************************/
/* Id for the company in the AUTOSAR, for example Mahmoud Morsy's ID = 1995 */
#define PORT_VENDOR_ID                                                   (1995U)

/* Port Module Id */
#define PORT_MODULE_ID                                                    (124U)

/* Port Instance Id */
#define PORT_INSTANCE_ID                                                    (0U)

/*
 * Module Version 1.0.0
 */
#define PORT_SW_MAJOR_VERSION                                               (1U)
#define PORT_SW_MINOR_VERSION                                               (0U)
#define PORT_SW_PATCH_VERSION                                               (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_AR_RELEASE_MAJOR_VERSION                                       (4U)
#define PORT_AR_RELEASE_MINOR_VERSION                                       (0U)
#define PORT_AR_RELEASE_PATCH_VERSION                                       (3U)

/* AUTOSAR checking between Std Types and Port Modules */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif

/* AUTOSAR Version checking between Port_Cfg.h and Port.h files */
#if ((PORT_CFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Port_Cfg.h does not match the expected version"
#endif

/* Software Version checking between Dio_Cfg.h and Dio.h files */
#if ((PORT_CFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
 ||  (PORT_CFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
 ||  (PORT_CFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
  #error "The SW version of Port_Cfg.h does not match the expected version"
#endif


/******************************************************************************
 *                             API Service Id Macros                          *
 ******************************************************************************/
/* Service ID for PORT Initialization API */
#define PORT_INIT_SID           					                 (uint8)0x00

/* Service ID for PORT Set Pin Direction API */
#define PORT_SET_PIN_DIRECTION_SID           		                 (uint8)0x01

/* Service ID for PORT Refresh Port Direction API */
#define PORT_REFRESH_PORT_DIRECTION_SID                              (uint8)0x02

/* Service ID for PORT Get Version Info API */
#define PORT_VERSION_INFO_SID                                        (uint8)0x03

/* Service ID for PORT Set Pin Mode API */
#define PORT_SET_PIN_MODE_SID                                        (uint8)0x04


/*******************************************************************************
 *                               DET Error Codes                               *
 *******************************************************************************/
/* DET code to report Invalid Port Pin ID Request */
#define PORT_E_PARAM_PIN                                             (uint8)0x0A

/* DET code to report Port Pin not configured as changeable */
#define PORT_E_DIRECTION_UNCHANGEABLE                                (uint8)0x0B

/* DET code to report API Port_Init service called with wrong parameter. */
#define PORT_E_PARAM_CONFIG                                          (uint8)0x0C

/* DET code to report API Port_SetPinMode service when mode is unchangeable. */
#define PORT_E_PARAM_INVALID_MODE                                    (uint8)0x0D
#define PORT_E_MODE_UNCHANGEABLE                                     (uint8)0x0E

/* DET code to report API service called without module initialization */
#define PORT_E_UNINIT                                                (uint8)0x0F

/* DET code to report APIs called with a Null Pointer */
#define PORT_E_PARAM_POINTER                                         (uint8)0x10

/* CUSTOM DET code to report API called with Conflicting Parameters or with
 * Unknown values */
#define PORT_E_PARAM_BAD                                 (uint8)0xFE


/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/
/* Type definition for the symbolic name of a port pin */
typedef uint16 Port_PinType;

/* Type definition of structure of individual port pins' configuration */
typedef struct
{
	/* The initial direction of the pin (IN or OUT) */
	Port_PinDirectionType PinDirection;
	/* Parameter to indicate if the direction is changeable on a port pin during
	 * runtime or not */
	Port_PinDirectionChangeableType PinDirectionChangeable;
	/* Pin Id of the port pin */
	const Port_PinType PinID;
	/* Port pin mode from mode list for use with Port_Init() function */
	const Port_PinModeType PinInitialMode;
	/* Port Pin Level Value */
	Port_PinLevelType PinLevelValue;
	/* Port pin mode(s) from mode list */
	Port_PinModeType PinMode[PORT_NUMBER_OF_ALLOWED_PIN_MODES];
	/* Parameter to indicate if the mode is changeable on a port pin during
	 * runtime or not */
	boolean PinModeChangeable;
}Port_Pin;

/* Type definition of structure collecting the port pins */
typedef struct
{
	/* The number of specified PortPins in this PortContainer */
	uint8 NumberOfPortPins;
	/* Configuration of the individual port pins */
	Port_Pin Pins[PORT_NUMBER_OF_PORT_PINS];
}Port_Container;

/* Type definition of the structure containing initial data for PORT module */
typedef struct
{
	/* Configuration of the individual ports */
	Port_Container Ports[PORT_NUMBER_OF_PORTS];
}Port_ConfigType;


/*******************************************************************************
 *                          Public Functions Prototypes                         *
 *******************************************************************************/
/* Function for PORT Initialization API */
void Port_Init(const Port_ConfigType* ConfigPtr);

/* Function for PORT Set Pin Direction API */
#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction);
#endif

/* Function for PORT Refresh Port Direction API */
void Port_RefreshPortDirection(void);

/* Function for PORT Get Version Info API */
#if (PORT_VERSION_INFO_API == STD_ON)
void Port_GetVersionInfo(Std_VersionInfoType* versioninfo);
#endif

/* Function for PORT Set Pin Mode API */
#if (PORT_SET_PIN_MODE_API == STD_ON)
void Port_SetPinMode(Port_PinType Pin,Port_PinModeType Mode);
#endif


/*******************************************************************************
 *                             External Variables                              *
 *******************************************************************************/
/* External Post Build structures to be used by PORT and other modules */
extern Port_ConfigType Port_Configuration;

#endif /* PORT_H */
