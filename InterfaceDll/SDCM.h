/*---------------------------------------------------------------------------*/
/*                                                                           */
/* FILE:    SDCM.h															 */
/* VERSION:	3.28	24/11/2009														 */
/*                                                                           */
/* PURPOSE: This is the header file for SDCM.dll. It is used by the			 */
/*          calling project to gain access to the library functions			 */
/*																			 */	
/*                                                                           */
/*			Copyright (c) by INSION GmbH   		 */
/*---------------------------------------------------------------------------*/


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

#ifdef WIN32

#ifdef SDCM_EXPORTS
#define SDCM_API	__declspec(dllexport)
#else
#define SDCM_API	__declspec(dllimport)
#endif // SDCM_EXPORTS

#else // WIN32

#define SDCM_API

#endif // WIN32

/* Structure Definition */
typedef struct PARAM_EXPORT
{
	char electronic[9];	// electronic type SDCM_VIS, MTI_VIS, BIM_NIRP
	int channels;		// count of channels (normally 1)
	int pixels;			// count of pixels
	int preheat;		// lamp pre-heat time [ms]
	int tint;			// integration time [ms]
	float fit[5];		// contains 5 polynomial fit values
} PARAM;

typedef struct XPARAM_EXPORT
{
	float fastscan;	// time [ms] to next fastscan
	float sensor;	// choice of image sensor
	float gain;		// gain channel 0 (V/V)
	float offset;	// offset channel 0 (mV)
	int parallel;	// parallel interface on
	int spi;		// spi interface on
	int lowgain;	// low or high gain
	int lamp;		// lamp enable on
	int lamplow;	// lamp low active on
	int led;		// LED enable on (not used by INSION spectrometer )
} XPARAM;

//struct for the internal sc30 calculation
typedef struct SC30PARAM_EXPORT
{
	float fFactor;
	int iStartWave;
	int iEndWave;
	int iSampleRate;
	int iNumberOfValues;
	int ColumnWidth;
	int Iterations;
	char cPower[4];
}SC30PARAM;


/*internal declaration*/
typedef union 
{
  unsigned short int i ;
  unsigned char ch[2] ;
}checksumvalues;

char Electronic[9];
int error;
/**********************/
	
/*function declaration*/
SDCM_API int SDCM_Init (int *iComPortNr, int iSearchComPort);
SDCM_API int SDCM_Close (void);
SDCM_API int SDCM_GetGeneral (PARAM *GenParam);
SDCM_API int SDCM_GetGeneralSingle (char electronic[9], int *channels, int *pixels, int *preheat, int *tint, float *fit);
SDCM_API int SDCM_SetGeneral (PARAM GenParam);
SDCM_API int SDCM_SetGeneralSingle (int channels, int pixels, int preheat, int tint, float fit[]);
SDCM_API int SDCM_GetExpanded (XPARAM *ExpParam);
SDCM_API int SDCM_GetExpandedSingle (float *fastscan, float *sensor, float *gain, float *offset, int *parallel, int *spi, int *lowgain, int *lamp, int *lamplow, int *led);
SDCM_API int SDCM_SetExpanded (XPARAM ExpParam);
SDCM_API int SDCM_SetExpandedSingle (float fastscan, float sensor, float gain, float offset, int parallel, int spi, int lowgain, int lamp, int lamplow, int led);
SDCM_API int SDCM_StartMeasDark (int Tint, int Scans);
SDCM_API int SDCM_ReadDark (int *Data);
SDCM_API int SDCM_StartMeasSpec (int Tint, int Scans);
SDCM_API int SDCM_ReadSpec (int *Data);
SDCM_API int SDCM_StartMeasDiff (int Tint, int Scans);
SDCM_API int SDCM_ReadDiff (int *Data);
SDCM_API int SDCM_GetStatus (void);
SDCM_API int SDCM_SetOffset (float Offset);
SDCM_API float SDCM_GetOffset(void);
SDCM_API int SDCM_SetGain (float Gain);
SDCM_API int SDCM_IllumOn (void);
SDCM_API int SDCM_IllumOff (void);
SDCM_API int SDCM_ReadUserData(int begin,int end ,char UserData[65536]);
SDCM_API int SDCM_WriteUserData(int Section,char UserData[1026]);
SDCM_API int SDCM_ReadCommentLine(char CommentLine[1024]);
SDCM_API int SDCM_WriteCommentLine(char CommentLine[1024]);
SDCM_API int SDCM_GetAdRange(void);
SDCM_API int SDCM_SetAdRange(int iVolt);
SDCM_API int SDCM_GetDelay();
SDCM_API int SDCM_Save(void);//Save the parameters non-volatile into eeprom
SDCM_API int SDCM_GetReceiveTime(void);//Returns the time in ms between sending a command and receiving datas
//Returns the system information of electronic
SDCM_API int SDCM_SystemInfo(char SerialNoSpectrometer[9],char SerialNoElectronic[5],char Electronictype[9],char Firmwareversion[5],char Baudrate[7],char SerialPort[4],char VersionInterfaceDll[5]);
//Allowed the request of the time progress during a measurement
SDCM_API int SDCM_TimeProgress(void);
//Function to get the polynom fits with the command *para:fit?
SDCM_API int SDCM_GetFit(int FitNo,float *Fit);
//Function to write the polynom fits with the command *para:fit
SDCM_API int SDCM_SetFit(int FitNo,float Fit);
//Function to set a new baudrate with the command *wrbaud
SDCM_API int zSDCM_SetBaudrate(int Baudrate);

//New functions for MSM-NIR1.7 with electronic BIM_NIRP
SDCM_API int SDCM_GetGainBimNir(void);//Get gain low/high
SDCM_API int SDCM_SetGainBimNir(int Gain);//Set gain low/high
SDCM_API int SDCM_SetTempConfig(int Mode);//Set temp control mode (0=off/2=on)
SDCM_API int SDCM_GetTempConfig(void);//Get temp control mode (0=off/2=on)
SDCM_API int SDCM_SetNominalTemp(float Temp);//Set nominal temp for temp control
SDCM_API float SDCM_GetNominalTemp(void);//Get nominal temp for temp control
SDCM_API float SDCM_GetDetectorTemp(void);//Get detector temp
SDCM_API int SDCM_GetDetectorTemperature(float *DetectorTemp);//Alternative to 'SDCM_GetDetectorTemp'
SDCM_API int SDCM_GetDefPixel(int DefPixel[5]);//Return numbers of def pixel and the def pixel 
SDCM_API float SDCM_GetPfactor(void);//Get proportional rate of temp control
SDCM_API int SDCM_SetPfactor(float Pfactor);//Set proportional rate of temp control
SDCM_API float SDCM_GetIfactor(void);//Get integral rate of temp control
SDCM_API int SDCM_SetIfactor(float Ifactor);//Set integral rate of temp control
SDCM_API int SDCM_StartCycleMeas(int Itime,int Scans,int CycleTime);
SDCM_API int SDCM_ReadCycleMeas(int *Values);
SDCM_API int SDCM_StopCyleMeas(void);
//New at version 3.22
SDCM_API int SDCM_GetTecSens(void);//Get tec sensor
SDCM_API int SDCM_SetTecSens(int TecSensor);//Set tec sensor
//-------------------
//New at version 3.26
int SDCM_GetGainFactor(float *GainFactor);
int SDCM_GetFastScan(int *FastScan);
int SDCM_GetSensor(int *Sensor);
int SDCM_SetGainFactor(float GainFactor);
int SDCM_SetFastScan(int FastScan);
int SDCM_SetSensor(int Sensor);
//-------------------
//Function for special customer
SDCM_API int SDCM_CycleMeas(int Itime,int Scans,int Averages,float* Dark,float* Ref);

//////////////////////////////////////////////////////////////////////////////////////
//								internal SC30 calculation							//
//		implemeted in elctronic sdcm_vis at firmware version 2.21					//
//					and SDCM_VIS2 at firmware version 1.03							//
//////////////////////////////////////////////////////////////////////////////////////
//Set/Get parameters for internal sc30 calculation
SDCM_API int SDCM_SetSc30Parameters(SC30PARAM Sc30Parameters);
SDCM_API int SDCM_xSetSc30Parameters(float fFactor,int iStartWave,int iEndWave,int iSampleRate,int iNumberOfValues,int ColumnWidth,int Iterations,char cPower[4]);
SDCM_API int SDCM_SetSc30Factor(float factor);
SDCM_API int SDCM_GetSc30Parameters(SC30PARAM *Sc30Parameters);
SDCM_API int SDCM_xGetSc30Parameters(float *fFactor,int *iStartWave,int *iEndWave,int *iSampleRate,int *iNumberOfValues,int *ColumnWidth,int *Iterations,char cPower[4]);
SDCM_API int SDCM_ConvertSc30Data(void);
SDCM_API int SDCM_StartSc30Calc(float *wavelength,float *values);
//////////////////////////////////////////////////////////////////////////////////////