import ctypes

SDCMlib = ctypes.WinDLL("C:\\Users\\loren\\github\\SensUs\\InterfaceDll\\sdcm_std.dll")
SDCM_Init = SDCMlib.SDCM_Init

SDCM_Init.argtypes = ctypes.c_int, ctypes.c_int
SDCM_Init.restype = ctypes.c_int
ComportNr = ctypes.c_int32(0)
SearchComport = ctypes.c_int32(0)
Init_Return = SDCM_Init(ComportNr, SearchComport)
print(Init_Return)


def Initialization():
    print(SDCMlib.SDCM_Init(0, 0))
    print(SDCMlib.SDCM_GetNumberOfDetectedElectronics())
