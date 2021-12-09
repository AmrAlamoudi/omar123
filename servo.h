/* 
 * File:   servo.h
 * Author: mahmoud yasser
 *
 * Created on November 14, 2021, 10:35 AM
 */

#ifndef SERVO_H
#define	SERVO_H

#ifdef	__cplusplus
extern "C" {
#endif
  void servo_init(); 
 float set_degree();
#include "mTimer.h"
#include "config.h"    
#ifdef	__cplusplus
}
#endif

#endif	/* SERVO_H */

