cimport cSDCM
import numpy as np
cimport numpy as np

from cpython.pycapsule cimport *

def SDCM_Init(np.ndarray[int, ndim=1, mode="c"] iComPortNr, int iSearchComPort):
    cSDCM.SDCM_Init(&iComPortNr[0], iSearchComPort)

def SDCM_GetStatus():
    cSDCM.SDCM_GetStatus()

def SDCM_StartMeasSpec(int Tint, int Scans):
    cSDCM.SDCM_StartMeasSpec(Tint, Scans)

def SDCM_ReadSpec(np.ndarray[int, ndim=1, mode="c"] data):
    cSDCM.SDCM_ReadSpec(&data[0])

def SDCM_Close():
    cSDCM.SDCM_Close()
