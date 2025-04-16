// 参考Dio R24-11规范
// 目标芯片 S32K144
#include <Dio.h>

Dio_LevelType Dio_ReadChannel (Dio_ChannelType ChannelId)
{
    Dio_LevelType channelLevel = STD_LOW;
    // Pin Contral Register引脚控制寄存器
    // 对于S32K144来说，有五个端口ABCDE，每个端口32个引脚。
    // 举例，PT D 16：32*3+16=112
    Dio_PortType PortId = ChannelId / NUM_PINS_PER_PORT;
    uint8 PinId = ChannelId % NUM_PINS_PER_PORT;
    Dio_PortLevelType PortLevel = Dio_ReadPort(PortId);
    channelLevel = (PortLevel >> PinId) & 0x1; // 提取第PinId位，即 P20.3 的电平状态
    return channelLevel;
}

void Dio_WriteChannel (Dio_ChannelType ChannelId, Dio_LevelType Level)
{
    Dio_PortType PortId = ChannelId / NUM_PINS_PER_PORT;
    uint8 PinId = ChannelId % NUM_PINS_PER_PORT;
    Dio_PortLevelType PortLevel = 0x0;
    if(Level == STD_LOW)
    {
        PortLevel &= ~(1 << PinId); // 设置 P20.3 为低电平
    }
    else
    {
        PortLevel |= (1 << PinId);  // 设置 P20.3 为高电平
    }
    Dio_WritePort(PortId, PortLevel);
}

Dio_PortLevelType Dio_ReadPort (Dio_PortType PortId)
{
    Dio_PortLevelType PortLevel = 0x0;
    PortLevel = (Dio_PortLevelType)((REG_READ32(GPIO_PDIR_ADDR32(PortId)))); // 独立到供应商的代码里面去
    return PortLevel;
}

void Dio_WritePort (Dio_PortType PortId, Dio_PortLevelType Level)
{
    REG_WRITE32(GPIO_PDOR_ADDR32(PortId), Level); // 独立到供应商的代码里面去
}

Dio_PortLevelType Dio_ReadChannelGroup (const Dio_ChannelGroupType* ChannelGroupIdPtr)
{
    // TODO
}

void Dio_WriteChannelGroup (const Dio_ChannelGroupType* ChannelGroupIdPtr, Dio_PortLevelType Level)
{
    // TODO
}

void Dio_GetVersionInfo (Std_VersionInfoType* VersionInfo)
{
    VersionInfo->vendorID = DIO_VENDOR_ID;
    VersionInfo->moduleID = DIO_MODULE_ID;
    VersionInfo->sw_major_version = DIO_SW_MAJOR_VERSION;
    VersionInfo->sw_minor_version = DIO_SW_MINOR_VERSION;
    VersionInfo->sw_patch_version = DIO_SW_PATCH_VERSION;
}

Dio_LevelType Dio_FlipChannel (Dio_ChannelType ChannelId)
{
    // TODO
}

void Dio_MaskedWritePort (Dio_PortType PortId, Dio_PortLevelType Level, Dio_PortLevelType Mask)
{
    // TODO
}
