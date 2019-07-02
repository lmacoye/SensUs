cdef extern from "SDCM.h":
    int SDCM_Init(int *iComPortNr, int iSearchComPort);
    int SDCM_GetStatus();
    int SDCM_StartMeasSpec (int Tint, int Scans);
    int SDCM_ReadSpec (int *Data);
    int SDCM_Close ();
