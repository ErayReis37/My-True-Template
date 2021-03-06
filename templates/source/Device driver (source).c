/*==========================================================================*/
/*
@@INCLUDE:$\templates\source\header-base@@
*/
/*--------------------------------------------------------------------------*/
/*
@@INCLUDE:$\templates\source\header-gnu@@
*/
/*--------------------------------------------------------------------------*/
/*
@@INCLUDE:$\templates\source\header-cvs@@
*/
/*==========================================================================*/
#ifndef __@@UPPERFILE_NAME@@_@@UPPERFILE_EXT@@__
#define __@@UPPERFILE_NAME@@_@@UPPERFILE_EXT@@__
/*==========================================================================*/
#include "DrvNULL.h"
#include <string.h>
#include <wchar.h>
/*==========================================================================*/
/*                            DRIVER FUNCTIONS                              */
/*==========================================================================*/
// FUNCTION: Install driver
// ARGUMENTS:
//     1) Pionter to driver handle
// RETURN:
//     1) 0 - if ok
//     2) -1 - if error
DRIVER_API int Driver_Install(void** DriverHandle)
{
	if (DriverHandle == NULL)
		return -1;
	else
		return 0;
}
/*--------------------------------------------------------------------------*/
// FUNCTION: Uninstall driver
// ARGUMENTS:
//     1) Pionter to driver handle
// RETURN:
//     1) 0 - if ok
//     2) -1 - if error
DRIVER_API int Driver_Uninstall(void** DriverHandle)
{
	if (DriverHandle == NULL)
		return -1;
	else
		return 0;
}
/*--------------------------------------------------------------------------*/
// FUNCTION: Get driver name
// ARGUMENTS:
//     1) Driver handle
//     2) Driver name (256 bytes)
// RETURN:
//     1) 0 - if ok
//     2) -1 - if error
DRIVER_API int Driver_GetDriverNameA(void* DriverHandle, char* Name)
{
	if (DriverHandle == NULL)
		return -1;
	strncpy(Name, "NULL driver", 256);
	return 0;
}
/*--------------------------------------------------------------------------*/
// FUNCTION: Get driver name (unicode version)
// ARGUMENTS:
//     1) Driver handle
//     2) Driver name (256 wide bytes)
// RETURN:
//     1) 0 - if ok
//     2) -1 - if error
DRIVER_API int Driver_GetDriverNameW(void* DriverHandle, wchar_t* Name)
{
	if (DriverHandle == NULL)
		return -1;
	wcsncpy(Name, L"NULL driver", 256);
	return 0;
}
/*--------------------------------------------------------------------------*/
// FUNCTION: Get device name
// ARGUMENTS:
//     1) Driver handle
//     2) Device index
//     3) Device name (256 bytes)
// RETURN:
//     1) 0 - if ok
//     2) -1 - if error
DRIVER_API int Driver_GetDeviceNameA(void* DriverHandle, int DeviceIndex, char* Name)
{
	if (DriverHandle == NULL)
		return -1;
	if (DeviceIndex == 0)
	{
		strncpy(Name, "Default NULL device", 256);
		return 0;
	}
	if (DeviceIndex == 1)
	{
		strncpy(Name, "System NULL device", 256);
		return 0;
	}
	return -1;
}
/*--------------------------------------------------------------------------*/
// FUNCTION: Get device name (unicode version)
// ARGUMENTS:
//     1) Driver handle
//     2) Device index
//     3) Device name (256 wide bytes)
// RETURN:
//     1) 0 - if ok
//     2) -1 - if error
DRIVER_API int Driver_GetDeviceNameW(void* DriverHandle, int DeviceIndex, wchar_t* Name)
{
	if (DriverHandle == NULL)
		return -1;
	if (DeviceIndex == 0)
	{
		wcsncpy(Name, L"Default NULL device", 256);
		return 0;
	}
	if (DeviceIndex==1)
	{
		wcsncpy(Name, L"System NULL device", 256);
		return 0;
	}
	return -1;
}
/*--------------------------------------------------------------------------*/
// FUNCTION: Get device count
// ARGUMENTS:
//     1) Driver handle
// RETURN:
//     1) Device count
DRIVER_API int Driver_GetDeviceCount(void* DriverHandle)
{
	if (DriverHandle == NULL)
		return 0;
	else
		return 1;
}
/*--------------------------------------------------------------------------*/
// FUNCTION: Init device
// ARGUMENTS:
//     1) Driver handle
//     2) Pionter to device handle
//     3) Device index
// RETURN:
//     1) 0 - if ok
//     2) -1 - if error
DRIVER_API int Driver_Init(void* DriverHandle, void** DeviceHandle, int DeviceIndex)
{
	if ((DriverHandle == NULL) || (DeviceHandle == NULL))
		return -1;
	if ((DeviceIndex < 0) || (DeviceIndex > 1))
		return -1;
	else
		return 0;
}
/*--------------------------------------------------------------------------*/
// FUNCTION: Close device
// ARGUMENTS:
//     1) Driver handle
//     2) Pionter to device handle
// RETURN:
//     1) 0 - if ok
//     2) -1 - if error
DRIVER_API int Driver_Close(void* DriverHandle, void** DeviceHandle)
{
	if ((DriverHandle == NULL) || (DeviceHandle == NULL))
		return -1;
	else
		return 0;
}
/*==========================================================================*/
#endif
