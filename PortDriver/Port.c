/*******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.c
 *
 * Description: Source file for Port Module.
 *
 * Author: Mahmoud MORSY
 ******************************************************************************/

#include "Port.h"

/* Non AUTOSAR files */
#include "..\Common_Macros.h"
#include "..\Micro_Config.h"

#if (PORT_DEV_ERROR_DETECT == STD_ON)
	#include "..\Det.h"
	/* AUTOSAR Version checking between Det and Port Modules */
	#if ((DET_AR_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
	 || (DET_AR_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
	 || (DET_AR_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
	  #error "The AR version of Det.h does not match the expected version"
	#endif
#endif

/*******************************************************************************
 *                           Private Global Variables                          *
 *******************************************************************************/
/* Variable to Store Current PORT Module Status, Initially Not initialized */
Port_ModuleStatusType Port_Status = PORT_NOT_INITIALIZED;

/* Pointer to the Configured Container */
Port_ConfigType * Port_Configurations = NULL_PTR;

/*******************************************************************************
 *                          Private Functions Prototypes                       *
 *******************************************************************************/
/*
 * Function that configures a specific pin as input or output and writes a
 * specific values (High or Low) in case of output direction
 */
STATIC void Port_ConfigurePinModeDio(
		const uint8 PortNumber,
		const uint8 InnerPinNumber,
		const Port_PinDirectionType PinDirection,
		const Port_PinLevelType PinLevel,
		const boolean ChangePinValue);

/*******************************************************************************
 *                        Private Functions Implementations                    *
 *******************************************************************************/
/*
 * Function that configures a specific pin as input or output and writes a
 * specific values (High or Low) in case of output direction
 */
STATIC void Port_ConfigurePinModeDio(
		/* Port Number */
		const uint8 PortNumber,
		/* Pin Number (Location) inside the port register */
		const uint8 InnerPinNumber,
		/* Pin Direction to be set as Input, Input with Pullup or Output */
		const Port_PinDirectionType PinDirection,
		/* Pin Level to be set only if Direction is output, otherwise this
		 * parameter is discarded
		 */
		const Port_PinLevelType PinLevel,
		/* Boolean Parameter if it's true, the pin level will be written
		 * and if not, it will discard the pin level parameter even when it's
		 * configured as output pin.
		 */
		const boolean ChangePinValue)
{
	uint8 * Local_DirectionRegPtr = NULL_PTR;
	uint8 * Local_PortRegPtr = NULL_PTR;

	/* Getting Port DDR and PORT Registers' Pointers */
	switch(PortNumber)
	{
	/* PORT A */
	case 0:
		Local_DirectionRegPtr = (uint8*)&DDRA;
		Local_PortRegPtr = (uint8*)&PORTA;
		break;
	/* PORT B */
	case 1:
		Local_DirectionRegPtr = (uint8*)&DDRB;
		Local_PortRegPtr = (uint8*)&PORTB;
		break;
	/* PORT C */
	case 2:
		Local_DirectionRegPtr = (uint8*)&DDRC;
		Local_PortRegPtr = (uint8*)&PORTC;
		break;
	/* PORT D */
	case 3:
		Local_DirectionRegPtr = (uint8*)&DDRD;
		Local_PortRegPtr = (uint8*)&PORTD;
		break;
	default:
	#if (PORT_DEV_ERROR_DETECT == STD_ON)
		/* Report Development Error for Bad Parameter */
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID,
				PORT_E_PARAM_BAD);
	#endif
		break;
	}

	/* Adjusting Pin Direction */
	switch(PinDirection)
	{
		case PORT_PIN_IN:
			CLEAR_BIT(*Local_DirectionRegPtr, InnerPinNumber);
			CLEAR_BIT(*Local_PortRegPtr, InnerPinNumber);
			break;
		case PORT_PIN_IN_PULLUP:
			CLEAR_BIT(*Local_DirectionRegPtr, InnerPinNumber);
			SET_BIT(*Local_PortRegPtr, InnerPinNumber);
			CLEAR_BIT(SFIOR, PUD);
			break;
		case PORT_PIN_OUT:
			SET_BIT(*Local_DirectionRegPtr, InnerPinNumber);
			break;
		default:
		#if (PORT_DEV_ERROR_DETECT == STD_ON)
			/* Report Development Error for Bad Parameter */
			Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID,
					PORT_E_PARAM_BAD);
		#endif
			break;

	}
	if (PORT_PIN_OUT == PinDirection && STD_ON == ChangePinValue)
	{
		/* Adjusting Output Pin Initial Value */
		switch(PinLevel)
		{
			case PORT_PIN_LEVEL_HIGH:
				SET_BIT(*Local_PortRegPtr, InnerPinNumber);
				break;
			case PORT_PIN_LEVEL_LOW:
				CLEAR_BIT(*Local_PortRegPtr, InnerPinNumber);
				break;
			default:
			#if (PORT_DEV_ERROR_DETECT == STD_ON)
				/* Report Development Error for Bad Parameter */
				Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID,
						PORT_E_PARAM_BAD);
			#endif
				break;
		}
	}
	else
	{
		/* Do Nothing */
	}
}

/*******************************************************************************
 *                        Public Functions Implementations                     *
 *******************************************************************************/

/*******************************************************************************
* Service Name: Port_Init
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): ConfigPtr - Pointer to post-build configuration data
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Initialize the Port Driver module.
********************************************************************************/
void Port_Init(const Port_ConfigType * ConfigPtr)
{
#if (PORT_DEV_ERROR_DETECT == STD_ON)
	if (NULL_PTR == ConfigPtr)
	{
		/* Report Development Error for Null Pointer Parameter */
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID,
				PORT_E_PARAM_CONFIG);
	}
	else
#endif
	{
		/* Local variable to iterate over all pins in configurations */
		uint8 Local_PinsCounter = (uint8)0;
		/* Local Variable to store Port Number of the chosen pin number */
		uint8 Local_PortNumber = (uint8)0;
		/* Local variable to store Pin Number inside the specific port for
		 * the chosen pin number */
		uint8 Local_PinNumber = (uint8)0;
		/* Local Pointer to point on current selected pin */
		Port_Pin* Local_PinPtr = NULL_PTR;

		for (; Local_PinsCounter < PORT_NUMBER_OF_PINS; Local_PinsCounter++)
		{
			/* Calculating Current Port Number */
			Local_PortNumber = (uint8)(Local_PinsCounter / PORT_NUMBER_OF_PORT_PINS);
			/* Calculating Current Pin Number inside the Port */
			Local_PinNumber = (uint8)(Local_PinsCounter % PORT_NUMBER_OF_PORT_PINS);
			/* Getting Current Pin Structure */
			Local_PinPtr = (Port_Pin*)&((ConfigPtr->Ports[Local_PortNumber]).Pins[Local_PinNumber]);

			switch(Local_PinPtr->PinInitialMode)
			{
				/* Pin configured as ADC Pin */
				case PORT_PIN_MODE_ADC:
					Port_ConfigurePinModeDio(Local_PortNumber, Local_PinNumber,
						PORT_PIN_IN, Local_PinPtr->PinLevelValue,
						STD_OFF);
					break;
				/* Pin configured as DIO Pin */
				case PORT_PIN_MODE_DIO:
					Port_ConfigurePinModeDio(Local_PortNumber, Local_PinNumber,
						Local_PinPtr->PinDirection, Local_PinPtr->PinLevelValue,
						STD_ON);
					break;
				/* Pin configured as DIO Pin Controlled by GPT */
				case PORT_PIN_MODE_DIO_GPT:
					break;
				/* Pin configured as DIO Pin Controlled by WDG */
				case PORT_PIN_MODE_DIO_WDG:
					break;
				/* Pin configured as PWM Pin */
				case PORT_PIN_MODE_PWM:
					break;
				/* Pin configured as SPI Pin */
				case PORT_PIN_MODE_SPI:
					break;
				/* Modes that are not supported by the controller */
				case PORT_PIN_MODE_CAN:
				case PORT_PIN_MODE_FLEXRAY:
				case PORT_PIN_MODE_ICU:
				case PORT_PIN_MODE_LIN:
				case PORT_PIN_MODE_MEM:
				default:
				#if (PORT_DEV_ERROR_DETECT == STD_ON)
					/* Report Development Error for Bad Parameter */
					Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID,
							PORT_E_PARAM_BAD);
				#endif
					break;
			}
		}
		/* Setting Port Module Status as Initialized */
		Port_Status = PORT_INITIALIZED;
	}
}

/*******************************************************************************
* Service Name: Port_SetPinDirection
* Service ID[hex]: 0x01
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): PinType - Port Pin ID number
*                  PinDirectionType - Port Pin Direction
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Set the port pin direction.
********************************************************************************/
#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
void Port_SetPinDirection(
    Port_PinType Pin,
    Port_PinDirectionType Direction
)
{
#if (PORT_DEV_ERROR_DETECT == STD_ON)
	if (PORT_NOT_INITIALIZED == Port_Status)
	{
		/* Report Development Error for calling API while Port not initialized */
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
				PORT_SET_PIN_DIRECTION_SID ,PORT_E_UNINIT);
	}
	else if (Pin >= PORT_NUMBER_OF_PINS)
	{
		/* Report Development Error for Incorrect Port Pin ID passed */
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
				PORT_SET_PIN_DIRECTION_SID ,PORT_E_PARAM_PIN);
	}
	else
#endif
	{
		/* Local Variable to store Port Number of the chosen pin number */
		uint8 Local_PortNumber = (uint8)(Pin / PORT_NUMBER_OF_PORT_PINS);
		/* Local variable to store Pin Number inside the specific port for
		 * the chosen pin number */
		uint8 Local_PinNumber = (uint8)(Pin % PORT_NUMBER_OF_PORT_PINS);
		/* Local Pointer to Pin Structure */
		Port_Pin * Local_PinPtr = (Port_Pin*)&((Port_Configurations->Ports[Local_PortNumber]).Pins[Local_PinNumber]);
	#if (PORT_DEV_ERROR_DETECT == STD_ON)
		if (PORT_PIN_DIRECTION_IS_CHANGEABLE == Local_PinPtr->PinDirectionChangeable)
		{
			/* Report Development Error for PortPin not configured changeable */
			Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
					PORT_SET_PIN_DIRECTION_SID ,PORT_E_DIRECTION_UNCHANGEABLE);
		}
		else
	#endif
		{
			switch(Direction)
			{
				case PORT_PIN_IN:
					Port_ConfigurePinModeDio(Local_PortNumber, Local_PinNumber,
							PORT_PIN_IN, PORT_PIN_LEVEL_LOW, STD_OFF);
					Local_PinPtr->PinDirection = PORT_PIN_IN;
					break;
				case PORT_PIN_IN_PULLUP:
					Port_ConfigurePinModeDio(Local_PortNumber, Local_PinNumber,
							PORT_PIN_IN_PULLUP, PORT_PIN_LEVEL_LOW, STD_OFF);
					Local_PinPtr->PinDirection = PORT_PIN_IN_PULLUP;
					break;
				case PORT_PIN_OUT:
					Port_ConfigurePinModeDio(Local_PortNumber, Local_PinNumber,
							PORT_PIN_OUT, PORT_PIN_LEVEL_LOW, STD_OFF);
					Local_PinPtr->PinDirection = PORT_PIN_OUT;
					break;
				default:
					#if (PORT_DEV_ERROR_DETECT == STD_ON)
					/* Report Development Error for invalid direction parameter */
					Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
							PORT_SET_PIN_DIRECTION_SID ,PORT_E_PARAM_BAD);
					#endif
					break;
			}
		}
	}
}
#endif

/*******************************************************************************
* Service Name: Port_RefreshPortDirection
* Service ID[hex]: 0x02
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Refresh the port direction.
********************************************************************************/
void Port_RefreshPortDirection(
    void
)
{
#if (PORT_DEV_ERROR_DETECT == STD_ON)
	if (PORT_NOT_INITIALIZED == Port_Status)
	{
		/* Report Development Error for calling API while Port not initialized */
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
				PORT_REFRESH_PORT_DIRECTION_SID ,PORT_E_UNINIT);
	}
	else
#endif
	{
		/* Local variable to iterate over all pins in configurations */
		uint8 Local_PinsCounter = (uint8)0;
		/* Local Variable to store Port Number of the chosen pin number */
		uint8 Local_PortNumber = (uint8)0;
		/* Local variable to store Pin Number inside the specific port for
		 * the chosen pin number */
		uint8 Local_PinNumber = (uint8)0;
		/* Local Pointer to point on current selected pin */
		Port_Pin* Local_PinPtr = NULL_PTR;

		for (; Local_PinsCounter < PORT_NUMBER_OF_PINS; Local_PinsCounter++)
		{
			Local_PortNumber = (uint8)(Local_PinsCounter / PORT_NUMBER_OF_PORT_PINS);
			Local_PinNumber = (uint8)(Local_PinsCounter % PORT_NUMBER_OF_PORT_PINS);
			Local_PinPtr = (Port_Pin*)&((Port_Configurations->Ports[Local_PortNumber]).Pins[Local_PinNumber]);

			switch(Local_PinPtr->PinDirection)
			{
				case PORT_PIN_IN:
					Port_ConfigurePinModeDio(Local_PortNumber, Local_PinNumber,
							PORT_PIN_IN, PORT_PIN_LEVEL_LOW, STD_OFF);
					break;
				case PORT_PIN_IN_PULLUP:
					Port_ConfigurePinModeDio(Local_PortNumber, Local_PinNumber,
							PORT_PIN_IN_PULLUP, PORT_PIN_LEVEL_LOW, STD_OFF);
					break;
				case PORT_PIN_OUT:
					Port_ConfigurePinModeDio(Local_PortNumber, Local_PinNumber,
							PORT_PIN_OUT, PORT_PIN_LEVEL_LOW, STD_OFF);
					break;
				default:
					#if (PORT_DEV_ERROR_DETECT == STD_ON)
					/* Report Development Error for invalid direction parameter */
					Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
							PORT_REFRESH_PORT_DIRECTION_SID ,PORT_E_PARAM_BAD);
					#endif
					break;
			}
		}
	}
}

/*******************************************************************************
* Service Name: Port_GetVersionInfo
* Service ID[hex]: 0x03
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): versioninfo - Pointer to where to store the version information
*                   of this module
* Return value: None
* Description: Function to Return the version information of this module.
********************************************************************************/
#if (PORT_VERSION_INFO_API == STD_ON)
void Port_GetVersionInfo(
    Std_VersionInfoType* VersionInfoPtr
)
{
#if (PORT_DEV_ERROR_DETECT == STD_ON)
	if (PORT_NOT_INITIALIZED == Port_Status)
	{
		/* Report Development Error for calling API while Port not initialized */
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
				PORT_VERSION_INFO_SID ,PORT_E_UNINIT);
	}
	else if (NULL_PTR == VersionInfoPtr)
	{
		/* Report Development Error for calling API with a null pointer */
			Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
					PORT_VERSION_INFO_SID ,PORT_E_PARAM_POINTER);
	}
	else
#endif
	{
		/* Copy the vendor Id */
		VersionInfoPtr->vendorID = (uint16)PORT_VENDOR_ID;
		/* Copy the module Id */
		VersionInfoPtr->moduleID = (uint16)PORT_MODULE_ID;
		/* Copy Software Major Version */
		VersionInfoPtr->sw_major_version = (uint8)PORT_SW_MAJOR_VERSION;
		/* Copy Software Minor Version */
		VersionInfoPtr->sw_minor_version = (uint8)PORT_SW_MINOR_VERSION;
		/* Copy Software Patch Version */
		VersionInfoPtr->sw_patch_version = (uint8)PORT_SW_PATCH_VERSION;
	}
}
#endif

/*******************************************************************************
* Service Name: Port_SetPinMode
* Service ID[hex]: 0x04
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): PinType - Port Pin ID number
*                  PinMode - New Port Pin mode to be set on port pin.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Set the port pin direction.
********************************************************************************/
#if (PORT_SET_PIN_MODE_API == STD_ON)
void Port_SetPinMode(
    Port_PinType Pin,
    Port_PinModeType Mode
)
{
#if (PORT_DEV_ERROR_DETECT == STD_ON)
	if (PORT_NOT_INITIALIZED == Port_Status)
	{
		/* Report Development Error for calling API while Port not initialized */
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
				PORT_SET_PIN_MODE_SID ,PORT_E_UNINIT);
	}
	else if (Pin >= PORT_NUMBER_OF_PINS)
	{
		/* Report Development Error for Incorrect Port Pin ID passed */
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
				PORT_SET_PIN_MODE_SID ,PORT_E_PARAM_PIN);
	}
	else
#endif
	{
		/* Local Variable to store Port Number of the chosen pin number */
		uint8 Local_PortNumber = (uint8)(Pin / PORT_NUMBER_OF_PORT_PINS);
		/* Local variable to store Pin Number inside the specific port for
		 * the chosen pin number */
		uint8 Local_PinNumber = (uint8)(Pin % PORT_NUMBER_OF_PORT_PINS);
		/* Local Pointer to Pin Structure */
		Port_Pin* Local_PinPtr = (Port_Pin*)&((Port_Configurations->Ports[Local_PortNumber]).Pins[Local_PinNumber]);
	#if (PORT_DEV_ERROR_DETECT == STD_ON)
		if (STD_OFF == Local_PinPtr->PinModeChangeable)
		{
			/* Report Development Error for PinMode not configured changeable */
			Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
					PORT_SET_PIN_MODE_SID ,PORT_E_MODE_UNCHANGEABLE);
		}
		else
	#endif
		{
			switch (Mode)
			{
			case PORT_PIN_MODE_ADC:
				Local_PinPtr->PinMode[0] = PORT_PIN_MODE_ADC;
				//TODO check with M.T bec. what if Direction is unchangeable?
				Local_PinPtr->PinDirection = PORT_PIN_IN;
				Port_ConfigurePinModeDio(Local_PortNumber, Local_PinNumber,
						PORT_PIN_IN, PORT_PIN_LEVEL_LOW, STD_OFF);
				break;
			case PORT_PIN_MODE_DIO:
				Local_PinPtr->PinMode[0] = PORT_PIN_MODE_ADC;
				break;
			case PORT_PIN_MODE_DIO_GPT:
				Local_PinPtr->PinMode[0] = PORT_PIN_MODE_DIO_GPT;
				break;
			case PORT_PIN_MODE_DIO_WDG:
				Local_PinPtr->PinMode[0] = PORT_PIN_MODE_DIO_WDG;
				break;
			case PORT_PIN_MODE_PWM:
				Local_PinPtr->PinMode[0] = PORT_PIN_MODE_PWM;
				//TODO check with M.T bec. what if Direction is unchangeable?
				Local_PinPtr->PinDirection = PORT_PIN_OUT;
				Local_PinPtr->PinLevelValue = PORT_PIN_LEVEL_LOW;
				Port_ConfigurePinModeDio(Local_PortNumber, Local_PinNumber,
						PORT_PIN_OUT, PORT_PIN_LEVEL_LOW, STD_ON);
				break;
			case PORT_PIN_MODE_SPI:
				break;
			case PORT_PIN_MODE_CAN:
			case PORT_PIN_MODE_FLEXRAY:
			case PORT_PIN_MODE_ICU:
			case PORT_PIN_MODE_LIN:
			case PORT_PIN_MODE_MEM:
			default:
				#if (PORT_DEV_ERROR_DETECT == STD_ON)
				/* Report Development Error for invalid mode parameter */
				Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
						PORT_SET_PIN_MODE_SID ,PORT_E_PARAM_INVALID_MODE);
				#endif
				break;
			}
		}
	}
}
#endif
