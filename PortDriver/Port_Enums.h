 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port_Types.h
 *
 * Description: Enumerations used in PORT Module.
 *
 * Author: Mahmoud MORSY
 ******************************************************************************/
#ifndef PORT_ENUMS_H
#define PORT_ENUMS_H

/*******************************************************************************
 *                              Module Enumerations                             *
 *******************************************************************************/
/* Type definition for PORT Module Status */
typedef enum
{
	PORT_NOT_INITIALIZED,
	PORT_INITIALIZED
}Port_ModuleStatusType;

/* Type definition for enumeration for possible directions of a port pin */
typedef enum
{
	/* Port Pin direction set as input */
	PORT_PIN_IN = 0,
	/* Port Pin direction set as input with internal pull up resistance */
	PORT_PIN_IN_PULLUP = 1,
	/* Port Pin direction set as output */
	PORT_PIN_OUT = 2
}Port_PinDirectionType;

/* Type definition for enumeration for possible outputs on a port pin */
typedef enum
{
	/* Port Pin level is Low */
	PORT_PIN_LEVEL_LOW,
	/* Port Pin level is High */
	PORT_PIN_LEVEL_HIGH
}Port_PinLevelType;


/* Type definition for enumeration for possible different port pin modes */
typedef enum
{
	/* Port Pin used by ADC */
	PORT_PIN_MODE_ADC,
	/* Port Pin used for CAN */
	PORT_PIN_MODE_CAN,
	/* Port Pin configured for DIO, Controlled by DIO Driver */
	PORT_PIN_MODE_DIO,
	/* Port Pin configured for DIO, Controlled by GPT Driver */
	PORT_PIN_MODE_DIO_GPT,
	/* Port Pin configured for DIO, Controlled by WDG Driver */
	PORT_PIN_MODE_DIO_WDG,
	/* Port Pin used for FlexRay */
	PORT_PIN_MODE_FLEXRAY,
	/* Port Pin used by ICU */
	PORT_PIN_MODE_ICU,
	/* Port Pin used for LIN */
	PORT_PIN_MODE_LIN,
	/* Port Pin used for external memory, Controlled by Memory Driver */
	PORT_PIN_MODE_MEM,
	/* Port Pin used by PWM */
	PORT_PIN_MODE_PWM,
	/* Port Pin used by SPI */
	PORT_PIN_MODE_SPI
}Port_PinModeType;

/* Type definition for enumeration for possible PinDirectionChangeable States */
typedef enum
{
	PORT_PIN_DIRECTION_NOT_CHANGEABLE,
	PORT_PIN_DIRECTION_IS_CHANGEABLE
}Port_PinDirectionChangeableType;

#endif /* PORT_ENUMS_H */
