 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port_PBCfg.c
 *
 * Description: Post Build Configuration Source file for Port Module.
 *
 * Author: Mahmoud MORSY
 ******************************************************************************/

#include "Port.h"

/* AUTOSAR Version checking between Port_PBcfg.c and Port.h files */
#if ((PORT_PBCFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_PBCFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_PBCFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of PBcfg.c does not match the expected version"
#endif

/* Software Version checking between Port_PBcfg.c and Port.h files */
#if ((PORT_PBCFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
 ||  (PORT_PBCFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
 ||  (PORT_PBCFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
  #error "The SW version of PBcfg.c does not match the expected version"
#endif

/* PB structure used with Dio_Init API */
Port_ConfigType Port_Configuration = {
{
   /* ******************************** PORT A ******************************* */
   {
	   /* Number Of Pins */
	   (uint8)PORT_NUMBER_OF_PORT_PINS,
	   /* Configured Pins */
	   {
		   /* Pin 0 */
		   {
			   /* Pin Direction */
			   PORT_DEFAULT_PIN_DIRECTION,
			   /* Pin Direction Changeable */
			   PORT_PIN_DIRECTION_IS_CHANGEABLE,
			   /* Pin ID */
			   (Port_PinType)PORT_PIN_0,
			   /* Pin Initial Mode */
			   PORT_DEFAULT_PIN_MODE,
			   /* Pin Level Value */
			   PORT_PIN_LEVEL_LOW,
			   /* Pin Mode(s) Array */
			   { PORT_DEFAULT_PIN_MODE },
			   /* Pin Mode Changeable */
			   PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
		   },
		   /* Pin 1 */
		   {
			   /* Pin Direction */
			   PORT_DEFAULT_PIN_DIRECTION,
			   /* Pin Direction Changeable */
			   PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
			   /* Pin ID */
			   (Port_PinType)PORT_PIN_1,
			   /* Pin Initial Mode */
			   PORT_DEFAULT_PIN_MODE,
			   /* Pin Level Value */
			   PORT_DEFAULT_PIN_LEVEL_VALUE,
			   /* Pin Mode(s) Array */
			   { PORT_DEFAULT_PIN_MODE },
			   /* Pin Mode Changeable */
			   PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
		   },
		   /* Pin 2 */
		   {
			   /* Pin Direction */
			   PORT_DEFAULT_PIN_DIRECTION,
			   /* Pin Direction Changeable */
			   PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
			   /* Pin ID */
			   (Port_PinType)PORT_PIN_2,
			   /* Pin Initial Mode */
			   PORT_DEFAULT_PIN_MODE,
			   /* Pin Level Value */
			   PORT_DEFAULT_PIN_LEVEL_VALUE,
			   /* Pin Mode(s) Array */
			   { PORT_DEFAULT_PIN_MODE },
			   /* Pin Mode Changeable */
			   PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
		   },
		   /* Pin 3 */
		   {
			   /* Pin Direction */
			   PORT_DEFAULT_PIN_DIRECTION,
			   /* Pin Direction Changeable */
			   PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
			   /* Pin ID */
			   (Port_PinType)PORT_PIN_3,
			   /* Pin Initial Mode */
			   PORT_DEFAULT_PIN_MODE,
			   /* Pin Level Value */
			   PORT_DEFAULT_PIN_LEVEL_VALUE,
			   /* Pin Mode(s) Array */
			   { PORT_DEFAULT_PIN_MODE },
			   /* Pin Mode Changeable */
			   PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
		   },
		   /* Pin 4 */
		   {
			   /* Pin Direction */
			   PORT_DEFAULT_PIN_DIRECTION,
			   /* Pin Direction Changeable */
			   PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
			   /* Pin ID */
			   (Port_PinType)PORT_PIN_4,
			   /* Pin Initial Mode */
			   PORT_DEFAULT_PIN_MODE,
			   /* Pin Level Value */
			   PORT_DEFAULT_PIN_LEVEL_VALUE,
			   /* Pin Mode(s) Array */
			   { PORT_DEFAULT_PIN_MODE },
			   /* Pin Mode Changeable */
			   PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
		   },
		   /* Pin 5 */
		   {
			   /* Pin Direction */
			   PORT_DEFAULT_PIN_DIRECTION,
			   /* Pin Direction Changeable */
			   PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
			   /* Pin ID */
			   (Port_PinType)PORT_PIN_5,
			   /* Pin Initial Mode */
			   PORT_DEFAULT_PIN_MODE,
			   /* Pin Level Value */
			   PORT_DEFAULT_PIN_LEVEL_VALUE,
			   /* Pin Mode(s) Array */
			   { PORT_DEFAULT_PIN_MODE },
			   /* Pin Mode Changeable */
			   PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
		   },
		   /* Pin 6 */
		   {
			   /* Pin Direction */
			   PORT_DEFAULT_PIN_DIRECTION,
			   /* Pin Direction Changeable */
			   PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
			   /* Pin ID */
			   (Port_PinType)PORT_PIN_6,
			   /* Pin Initial Mode */
			   PORT_DEFAULT_PIN_MODE,
			   /* Pin Level Value */
			   PORT_DEFAULT_PIN_LEVEL_VALUE,
			   /* Pin Mode(s) Array */
			   { PORT_DEFAULT_PIN_MODE },
			   /* Pin Mode Changeable */
			   PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
		   },
		   /* Pin 7 */
		   {
			   /* Pin Direction */
			   PORT_DEFAULT_PIN_DIRECTION,
			   /* Pin Direction Changeable */
			   PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
			   /* Pin ID */
			   (Port_PinType)PORT_PIN_7,
			   /* Pin Initial Mode */
			   PORT_DEFAULT_PIN_MODE,
			   /* Pin Level Value */
			   PORT_DEFAULT_PIN_LEVEL_VALUE,
			   /* Pin Mode(s) Array */
			   { PORT_DEFAULT_PIN_MODE },
			   /* Pin Mode Changeable */
			   PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
		   }
	   }
   },
   /* ******************************** PORT B ******************************* */
   {
	   /* Number Of Pins */
	   (uint8)PORT_NUMBER_OF_PORT_PINS,
	   /* Configured Pins */
	   {
		   /* Pin 8 */
		   {
			   /* Pin Direction */
			   PORT_DEFAULT_PIN_DIRECTION,
			   /* Pin Direction Changeable */
			   PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
			   /* Pin ID */
			   (Port_PinType)PORT_PIN_8,
			   /* Pin Initial Mode */
			   PORT_DEFAULT_PIN_MODE,
			   /* Pin Level Value */
			   PORT_DEFAULT_PIN_LEVEL_VALUE,
			   /* Pin Mode(s) Array */
			   { PORT_DEFAULT_PIN_MODE },
			   /* Pin Mode Changeable */
			   PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
		   },
		   /* Pin 9 */
		   {
			   /* Pin Direction */
			   PORT_DEFAULT_PIN_DIRECTION,
			   /* Pin Direction Changeable */
			   PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
			   /* Pin ID */
			   (Port_PinType)PORT_PIN_9,
			   /* Pin Initial Mode */
			   PORT_DEFAULT_PIN_MODE,
			   /* Pin Level Value */
			   PORT_DEFAULT_PIN_LEVEL_VALUE,
			   /* Pin Mode(s) Array */
			   { PORT_DEFAULT_PIN_MODE },
			   /* Pin Mode Changeable */
			   PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
		   },
		   /* Pin 10 */
		   {
			   /* Pin Direction */
			   PORT_DEFAULT_PIN_DIRECTION,
			   /* Pin Direction Changeable */
			   PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
			   /* Pin ID */
			   (Port_PinType)PORT_PIN_10,
			   /* Pin Initial Mode */
			   PORT_DEFAULT_PIN_MODE,
			   /* Pin Level Value */
			   PORT_DEFAULT_PIN_LEVEL_VALUE,
			   /* Pin Mode(s) Array */
			   { PORT_DEFAULT_PIN_MODE },
			   /* Pin Mode Changeable */
			   PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
		   },
		   /* Pin 11 */
		   {
			   /* Pin Direction */
			   PORT_DEFAULT_PIN_DIRECTION,
			   /* Pin Direction Changeable */
			   PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
			   /* Pin ID */
			   (Port_PinType)PORT_PIN_11,
			   /* Pin Initial Mode */
			   PORT_DEFAULT_PIN_MODE,
			   /* Pin Level Value */
			   PORT_DEFAULT_PIN_LEVEL_VALUE,
			   /* Pin Mode(s) Array */
			   { PORT_DEFAULT_PIN_MODE },
			   /* Pin Mode Changeable */
			   PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
		   },
		   /* Pin 12 */
		   {
			   /* Pin Direction */
			   PORT_DEFAULT_PIN_DIRECTION,
			   /* Pin Direction Changeable */
			   PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
			   /* Pin ID */
			   (Port_PinType)PORT_PIN_12,
			   /* Pin Initial Mode */
			   PORT_DEFAULT_PIN_MODE,
			   /* Pin Level Value */
			   PORT_DEFAULT_PIN_LEVEL_VALUE,
			   /* Pin Mode(s) Array */
			   { PORT_DEFAULT_PIN_MODE },
			   /* Pin Mode Changeable */
			   PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
		   },
		   /* Pin 13 */
		   {
			   /* Pin Direction */
			   PORT_DEFAULT_PIN_DIRECTION,
			   /* Pin Direction Changeable */
			   PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
			   /* Pin ID */
			   (Port_PinType)PORT_PIN_13,
			   /* Pin Initial Mode */
			   PORT_DEFAULT_PIN_MODE,
			   /* Pin Level Value */
			   PORT_DEFAULT_PIN_LEVEL_VALUE,
			   /* Pin Mode(s) Array */
			   { PORT_DEFAULT_PIN_MODE },
			   /* Pin Mode Changeable */
			   PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
		   },
		   /* Pin 14 */
		   {
			   /* Pin Direction */
			   PORT_DEFAULT_PIN_DIRECTION,
			   /* Pin Direction Changeable */
			   PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
			   /* Pin ID */
			   (Port_PinType)PORT_PIN_14,
			   /* Pin Initial Mode */
			   PORT_DEFAULT_PIN_MODE,
			   /* Pin Level Value */
			   PORT_DEFAULT_PIN_LEVEL_VALUE,
			   /* Pin Mode(s) Array */
			   { PORT_DEFAULT_PIN_MODE },
			   /* Pin Mode Changeable */
			   PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
		   },
		   /* Pin 15 */
		   {
			   /* Pin Direction */
			   PORT_DEFAULT_PIN_DIRECTION,
			   /* Pin Direction Changeable */
			   PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
			   /* Pin ID */
			   (Port_PinType)PORT_PIN_15,
			   /* Pin Initial Mode */
			   PORT_DEFAULT_PIN_MODE,
			   /* Pin Level Value */
			   PORT_PIN_LEVEL_HIGH,
			   /* Pin Mode(s) Array */
			   { PORT_DEFAULT_PIN_MODE },
			   /* Pin Mode Changeable */
			   PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
		   }
	   }
   },
   /* ******************************** PORT C ******************************* */
   {
	   /* Number Of Pins */
	   (uint8)PORT_NUMBER_OF_PORT_PINS,
	   /* Configured Pins */
	   {
		   /* Pin 16 */
		   {
			   /* Pin Direction */
			   PORT_DEFAULT_PIN_DIRECTION,
			   /* Pin Direction Changeable */
			   PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
			   /* Pin ID */
			   (Port_PinType)PORT_PIN_16,
			   /* Pin Initial Mode */
			   PORT_DEFAULT_PIN_MODE,
			   /* Pin Level Value */
			   PORT_DEFAULT_PIN_LEVEL_VALUE,
			   /* Pin Mode(s) Array */
			   { PORT_DEFAULT_PIN_MODE },
			   /* Pin Mode Changeable */
			   PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
		   },
		   /* Pin 17 */
		   {
			   /* Pin Direction */
			   PORT_DEFAULT_PIN_DIRECTION,
			   /* Pin Direction Changeable */
			   PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
			   /* Pin ID */
			   (Port_PinType)PORT_PIN_17,
			   /* Pin Initial Mode */
			   PORT_DEFAULT_PIN_MODE,
			   /* Pin Level Value */
			   PORT_DEFAULT_PIN_LEVEL_VALUE,
			   /* Pin Mode(s) Array */
			   { PORT_DEFAULT_PIN_MODE },
			   /* Pin Mode Changeable */
			   PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
		   },
		   /* Pin 18 */
		   {
			   /* Pin Direction */
			   PORT_DEFAULT_PIN_DIRECTION,
			   /* Pin Direction Changeable */
			   PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
			   /* Pin ID */
			   (Port_PinType)PORT_PIN_18,
			   /* Pin Initial Mode */
			   PORT_DEFAULT_PIN_MODE,
			   /* Pin Level Value */
			   PORT_DEFAULT_PIN_LEVEL_VALUE,
			   /* Pin Mode(s) Array */
			   { PORT_DEFAULT_PIN_MODE },
			   /* Pin Mode Changeable */
			   PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
		   },
		   /* Pin 19 */
		   {
			   /* Pin Direction */
			   PORT_DEFAULT_PIN_DIRECTION,
			   /* Pin Direction Changeable */
			   PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
			   /* Pin ID */
			   (Port_PinType)PORT_PIN_19,
			   /* Pin Initial Mode */
			   PORT_DEFAULT_PIN_MODE,
			   /* Pin Level Value */
			   PORT_DEFAULT_PIN_LEVEL_VALUE,
			   /* Pin Mode(s) Array */
			   { PORT_DEFAULT_PIN_MODE },
			   /* Pin Mode Changeable */
			   PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
		   },
		   /* Pin 20 */
		   {
			   /* Pin Direction */
			   PORT_DEFAULT_PIN_DIRECTION,
			   /* Pin Direction Changeable */
			   PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
			   /* Pin ID */
			   (Port_PinType)PORT_PIN_20,
			   /* Pin Initial Mode */
			   PORT_DEFAULT_PIN_MODE,
			   /* Pin Level Value */
			   PORT_DEFAULT_PIN_LEVEL_VALUE,
			   /* Pin Mode(s) Array */
			   { PORT_DEFAULT_PIN_MODE },
			   /* Pin Mode Changeable */
			   PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
		   },
		   /* Pin 21 */
		   {
			   /* Pin Direction */
			   PORT_PIN_OUT,
			   /* Pin Direction Changeable */
			   PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
			   /* Pin ID */
			   (Port_PinType)PORT_PIN_21_LED_CHANNEL,
			   /* Pin Initial Mode */
			   PORT_DEFAULT_PIN_MODE,
			   /* Pin Level Value */
			   PORT_PIN_LEVEL_LOW,
			   /* Pin Mode(s) Array */
			   { PORT_DEFAULT_PIN_MODE },
			   /* Pin Mode Changeable */
			   PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
		   },
		   /* Pin 22 */
		   {
			   /* Pin Direction */
			   PORT_DEFAULT_PIN_DIRECTION,
			   /* Pin Direction Changeable */
			   PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
			   /* Pin ID */
			   (Port_PinType)PORT_PIN_22,
			   /* Pin Initial Mode */
			   PORT_DEFAULT_PIN_MODE,
			   /* Pin Level Value */
			   PORT_PIN_LEVEL_HIGH,
			   /* Pin Mode(s) Array */
			   { PORT_DEFAULT_PIN_MODE },
			   /* Pin Mode Changeable */
			   PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
		   },
		   /* Pin 23 */
		   {
			   /* Pin Direction */
			   PORT_DEFAULT_PIN_DIRECTION,
			   /* Pin Direction Changeable */
			   PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
			   /* Pin ID */
			   (Port_PinType)PORT_PIN_23,
			   /* Pin Initial Mode */
			   PORT_DEFAULT_PIN_MODE,
			   /* Pin Level Value */
			   PORT_DEFAULT_PIN_LEVEL_VALUE,
			   /* Pin Mode(s) Array */
			   { PORT_DEFAULT_PIN_MODE },
			   /* Pin Mode Changeable */
			   PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
		   }
	   }
   },
   /* ******************************** PORT D ******************************* */
   {
	   /* Number Of Pins */
	   (uint8)PORT_NUMBER_OF_PORT_PINS,
	   /* Configured Pins */
	   {
		   /* Pin 24 */
		   {
			   /* Pin Direction */
			   PORT_DEFAULT_PIN_DIRECTION,
			   /* Pin Direction Changeable */
			   PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
			   /* Pin ID */
			   (Port_PinType)PORT_PIN_24,
			   /* Pin Initial Mode */
			   PORT_DEFAULT_PIN_MODE,
			   /* Pin Level Value */
			   PORT_DEFAULT_PIN_LEVEL_VALUE,
			   /* Pin Mode(s) Array */
			   { PORT_DEFAULT_PIN_MODE },
			   /* Pin Mode Changeable */
			   PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
		   },
		   /* Pin 25 */
		   {
			   /* Pin Direction */
			   PORT_DEFAULT_PIN_DIRECTION,
			   /* Pin Direction Changeable */
			   PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
			   /* Pin ID */
			   (Port_PinType)PORT_PIN_25,
			   /* Pin Initial Mode */
			   PORT_DEFAULT_PIN_MODE,
			   /* Pin Level Value */
			   PORT_DEFAULT_PIN_LEVEL_VALUE,
			   /* Pin Mode(s) Array */
			   { PORT_DEFAULT_PIN_MODE },
			   /* Pin Mode Changeable */
			   PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
		   },
		   /* Pin 26 */
		   {
			   /* Pin Direction */
			   PORT_PIN_IN,
			   /* Pin Direction Changeable */
			   PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
			   /* Pin ID */
			   (Port_PinType)PORT_PIN_26_BUTTON_CHANNEL,
			   /* Pin Initial Mode */
			   PORT_DEFAULT_PIN_MODE,
			   /* Pin Level Value */
			   PORT_DEFAULT_PIN_LEVEL_VALUE,
			   /* Pin Mode(s) Array */
			   { PORT_DEFAULT_PIN_MODE },
			   /* Pin Mode Changeable */
			   PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
		   },
		   /* Pin 27 */
		   {
			   /* Pin Direction */
			   PORT_DEFAULT_PIN_DIRECTION,
			   /* Pin Direction Changeable */
			   PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
			   /* Pin ID */
			   (Port_PinType)PORT_PIN_27,
			   /* Pin Initial Mode */
			   PORT_DEFAULT_PIN_MODE,
			   /* Pin Level Value */
			   PORT_DEFAULT_PIN_LEVEL_VALUE,
			   /* Pin Mode(s) Array */
			   { PORT_DEFAULT_PIN_MODE },
			   /* Pin Mode Changeable */
			   PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
		   },
		   /* Pin 28 */
		   {
			   /* Pin Direction */
			   PORT_DEFAULT_PIN_DIRECTION,
			   /* Pin Direction Changeable */
			   PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
			   /* Pin ID */
			   (Port_PinType)PORT_PIN_28,
			   /* Pin Initial Mode */
			   PORT_DEFAULT_PIN_MODE,
			   /* Pin Level Value */
			   PORT_DEFAULT_PIN_LEVEL_VALUE,
			   /* Pin Mode(s) Array */
			   { PORT_DEFAULT_PIN_MODE },
			   /* Pin Mode Changeable */
			   PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
		   },
		   /* Pin 29 */
		   {
			   /* Pin Direction */
			   PORT_DEFAULT_PIN_DIRECTION,
			   /* Pin Direction Changeable */
			   PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
			   /* Pin ID */
			   (Port_PinType)PORT_PIN_29,
			   /* Pin Initial Mode */
			   PORT_DEFAULT_PIN_MODE,
			   /* Pin Level Value */
			   PORT_DEFAULT_PIN_LEVEL_VALUE,
			   /* Pin Mode(s) Array */
			   { PORT_DEFAULT_PIN_MODE },
			   /* Pin Mode Changeable */
			   PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
		   },
		   /* Pin 30 */
		   {
			   /* Pin Direction */
			   PORT_DEFAULT_PIN_DIRECTION,
			   /* Pin Direction Changeable */
			   PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
			   /* Pin ID */
			   (Port_PinType)PORT_PIN_30,
			   /* Pin Initial Mode */
			   PORT_DEFAULT_PIN_MODE,
			   /* Pin Level Value */
			   PORT_DEFAULT_PIN_LEVEL_VALUE,
			   /* Pin Mode(s) Array */
			   { PORT_DEFAULT_PIN_MODE },
			   /* Pin Mode Changeable */
			   PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
		   },
		   /* Pin 31 */
		   {
			   /* Pin Direction */
			   PORT_DEFAULT_PIN_DIRECTION,
			   /* Pin Direction Changeable */
			   PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
			   /* Pin ID */
			   (Port_PinType)PORT_PIN_31,
			   /* Pin Initial Mode */
			   PORT_DEFAULT_PIN_MODE,
			   /* Pin Level Value */
			   PORT_PIN_LEVEL_HIGH,
			   /* Pin Mode(s) Array */
			   { PORT_DEFAULT_PIN_MODE },
			   /* Pin Mode Changeable */
			   PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
		   }
	   }
   }
}};
