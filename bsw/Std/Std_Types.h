#ifndef STD_TYPES_H
#define STD_TYPES_H

# include "Platform_Types.h"
# include "Compiler.h"

# define STD_HIGH     1u /* Physical state 5V or 3.3V */
# define STD_LOW      0u /* Physical state 0V */




typedef uint8 Std_ReturnType;
typedef struct
{
   uint16 vendorID;
   uint16 moduleID;
   uint8  sw_major_version;
   uint8  sw_minor_version;
   uint8  sw_patch_version;
} Std_VersionInfoType;

#endif  /* STD_TYPES_H */