/*=====================================================================================================================
 * 
 * Repository path:     $HeadURL$
 * Last committed:      $Revision$
 * Last changed by:     $Author$
 * Last changed date:   $Date$
 * ID:                  $Id$
 *
 *===================================================================================================================*/
// $GPVTG
// Track Made Good and Ground Speed.
// 
// eg1. $GPVTG,360.0,T,348.7,M,000.0,N,000.0,K*43
// eg2. $GPVTG,054.7,T,034.4,M,005.5,N,010.2,K
// 
// 
// 054.7,T      True track made good
// 034.4,M      Magnetic track made good
// 005.5,N      Ground speed, knots
// 010.2,K      Ground speed, Kilometers per hour
// 
// 
// eg3. $GPVTG,t,T,,,s.ss,N,s.ss,K*hh
// 1    = Track made good
// 2    = Fixed text 'T' indicates that track made good is relative to true north
// 3    = not used
// 4    = not used
// 5    = Speed over ground in knots
// 6    = Fixed text 'N' indicates that speed over ground in in knots
// 7    = Speed over ground in kilometers/hour
// 8    = Fixed text 'K' indicates that speed over ground is in kilometers/hour
// 9    = Checksum
// The actual track made good and speed relative to the ground.
// 
// $--VTG,x.x,T,x.x,M,x.x,N,x.x,K
// x.x,T = Track, degrees True 
// x.x,M = Track, degrees Magnetic 
// x.x,N = Speed, knots 
// x.x,K = Speed, Km/hr

/*=====================================================================================================================
 * Body Identification  
 *===================================================================================================================*/
#ifdef __NMEA_GPVTG_C
    #error "!!! FileName ID. It should be Unique !!!"
#else
    #define __NMEA_GPVTG_C
#endif

/*=====================================================================================================================
 * Included files to resolve specific definitions in this file
 *===================================================================================================================*/
#include "nmea_gpvtg.h"


/*=====================================================================================================================
 * Local constants
 *===================================================================================================================*/
#define cVTG_FixStatusIndex         9  
#define cVTG_SpeedKnotsIndex        4
#define cVTG_SpeedKmhIndex          6





/*=====================================================================================================================
 * Local macros
 *===================================================================================================================*/

/*=====================================================================================================================
 * Local types
 *===================================================================================================================*/

/*=====================================================================================================================
 * Local data
 *===================================================================================================================*/

/*=====================================================================================================================
 * Constant Local Data
 *===================================================================================================================*/

/*=====================================================================================================================
 * Constant exported data                                                     
 *===================================================================================================================*/

/*=====================================================================================================================
 * Exported Data
 *===================================================================================================================*/

/*=====================================================================================================================
 * Local Functions Prototypes
 *===================================================================================================================*/


/*=====================================================================================================================
 *
 *                                  E X P O R T E D    F U N C T I O N S
 *
 *===================================================================================================================*/
/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
tGpsMask NMEAVtg_Decoder(U8 *pu8GpsField[], tNMEA_GPS_Data* GpsData, tGpsMask GpsStat)
{
    tGpsMask GpsStatLocal = GpsStat;
    U8 *pu8Char;
    U16 u16SpdKnots;

    if((*pu8GpsField[cVTG_FixStatusIndex] == 'A') || (*pu8GpsField[cVTG_FixStatusIndex] == 'D'))
    {
        // get speed
        if(*pu8GpsField[cVTG_SpeedKmhIndex] != '\0')
        {
            // get speed in knots
            pu8Char = (U8*)strchr((const char *)&pu8GpsField[cVTG_SpeedKnotsIndex], '.');
            u16SpdKnots = atoi((const char*)pu8Char);
            sprintf((char*)GpsData->AX25_GPS_Data.u8Speed, "%03d", u16SpdKnots);

            // get speed in km/h
            pu8Char = (U8*)strchr((const char *)&pu8GpsField[cVTG_SpeedKmhIndex], '.');

#if !defined(SMART_BEACONING_DEBUG)
            GpsData->u16GpsSpeed = atoi((const char*)pu8Char);
#endif

            GpsStatLocal |= cGPS_STAT_SPEED_SET;
        }
    }

    return GpsStatLocal;
}


/*=====================================================================================================================
 *                                                                            
 *                                     L O C A L    F U N C T I O N S                   
 *                                                                            
 *===================================================================================================================*/
/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/

