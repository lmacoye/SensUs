import ctypes

SDCMlib = ctypes.WinDLL("C:\\Users\\loren\\github\\SensUs\\InterfaceDll\\sdcm_std.dll")

print(SDCMlib.SDCM_Init(1, 0))


def Initialization():
    print(SDCMlib.SDCM_Init(0, 0))
    print(SDCMlib.SDCM_GetNumberOfDetectedElectronics())
