cdef extern from "C:\\Users\\loren\\github\\SensUs\\InterfaceDll\\SDCM.h":
    int _stdcall SDCM_Init(int *iComPortNr, int iSearchComPort);
    int _stdcall SDCM_GetStatus();
    int _stdcall SDCM_StartMeasSpec (int Tint, int Scans);
    int _stdcall SDCM_ReadSpec (int *Data);
    int _stdcall SDCM_Close ();
