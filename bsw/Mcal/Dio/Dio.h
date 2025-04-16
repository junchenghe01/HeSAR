#ifndef DIO_H
#define DIO_H

/*=======================================include files=============================================*/
#include "Std_Types.h"
#include "Reg_eSys_Gpio.h"
#include "StdRegMacros.h"
/*=======================================Macro Definition=============================================*/

#define NUM_PINS_PER_PORT 32 /* S32K1xx 需要芯片厂商确定*/

#define DIO_VENDOR_ID                        0 // 0--->Open
#define DIO_MODULE_ID                        120
#define DIO_SW_MAJOR_VERSION                 1
#define DIO_SW_MINOR_VERSION                 0
#define DIO_SW_PATCH_VERSION                 0


/*=======================================Type definitions=============================================*/

typedef uint16 Dio_ChannelType; /* Numeric ID of a DIO channel. */

typedef uint8 Dio_PortType; /* Numeric ID of a DIO port. */

typedef struct
{
    uint8 mask; /* This element mask which defines the positions of the channel group. */
    uint8 offset; /* This element shall be the position of the Channel Group on the port, counted from the LSB. */
    Dio_PortType port; /* This shall be the port on which the Channel group is defined. */
} Dio_ChannelGroupType; /* Type for the definition of a channel group, which consists of several adjoining channels within a port. */

typedef uint8 Dio_LevelType; /* These are the possible levels a DIO channel can have (input or output) */

typedef uint32 Dio_PortLevelType; /* If the μC owns ports of different port widths (e.g. 4, 8,16...Bit) Dio_PortLevelType inherits the size of the largest port. */

/*=======================================Function definitions=============================================*/
/**
 * @brief Returns the value of the specified DIO channel.
 * 
 * @param ChannelId ID of DIO channel
 * @return Dio_LevelType the value of the specified DIO channel.
 */
Dio_LevelType Dio_ReadChannel (Dio_ChannelType ChannelId);

/**
 * @brief Service to set a level of a channel.
 * 
 * @param ChannelId ID of DIO channel
 * @param Level Value to be written
 */
void Dio_WriteChannel (Dio_ChannelType ChannelId, Dio_LevelType Level);

/**
 * @brief Returns the level of all channels of that port.
 * 
 * @param PortId ID of DIO Port
 * @return Dio_PortLevelType Level of all channels of that port
 */
Dio_PortLevelType Dio_ReadPort (Dio_PortType PortId);

/**
 * @brief Service to set a value of the port.
 * 
 * @param PortId ID of DIO Port
 * @param Level Value to be written
 */
void Dio_WritePort (Dio_PortType PortId, Dio_PortLevelType Level);

/**
 * @brief This Service reads a subset of the adjoining bits of a port.
 * 
 * @param ChannelGroupIdPtr Pointer to ChannelGroup
 * @return Dio_PortLevelType Level of a subset of the adjoining bits of a port
 */
Dio_PortLevelType Dio_ReadChannelGroup (const Dio_ChannelGroupType* ChannelGroupIdPtr);

/**
 * @brief Service to set a subset of the adjoining bits of a port to a specified level.
 * 
 * @param ChannelGroupIdPtr Pointer to ChannelGroup
 * @param Level Value to be written
 */
void Dio_WriteChannelGroup (const Dio_ChannelGroupType* ChannelGroupIdPtr, Dio_PortLevelType Level);

/**
 * @brief Service to get the version information of this module.
 * 
 * @param VersionInfo Pointer to where to store the version information of this module.
 */
void Dio_GetVersionInfo (Std_VersionInfoType* VersionInfo);

/**
 * @brief Service to flip (change from 1 to 0 or from 0 to 1) the level of a channel and return the level of the channel after flip.
 * 
 * @param ChannelId ID of DIO channel
 * @return Dio_LevelType the level of the channel after flip.
 */
Dio_LevelType Dio_FlipChannel (Dio_ChannelType ChannelId);

/**
 * @brief Service to set the value of a given port with required mask.
 * 
 * @param PortId ID of DIO Port
 * @param Level Value to be written
 * @param Mask Channels to be masked in the port
 */
void Dio_MaskedWritePort (Dio_PortType PortId, Dio_PortLevelType Level, Dio_PortLevelType Mask);

#endif /* DIO_H */
