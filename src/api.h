/*=====================================================================================================================
 * 
 * Repository path:     $HeadURL$
 * Last committed:      $Revision$
 * Last changed by:     $Author$
 * Last changed date:   $Date$
 * ID:                  $Id$
 *
 *===================================================================================================================*/
#ifndef __API_H
#define __API_H

/*=====================================================================================================================
 * Included files to resolve specific definitions in this file                
 *===================================================================================================================*/
#include "basedef.h"

/*=====================================================================================================================
 * Callback channels                                                              
 *===================================================================================================================*/
/*
** APRS channel
*/
//controls
#define cAprsCtrlStartTrmt                  0
#define cAprsCtrlStop                       1
// callback controls
#define cAprsCallbackCtrlOK                 0
#define cAprsCallbackCtrlError              1
// callback funct
extern void Aprs_TransmitCallback(tCtrl Ctrl);

/*=====================================================================================================================
 * Exported functions                     				                        
 *===================================================================================================================*/

#endif /* __API_H */
