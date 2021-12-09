/* 
 * File:   ultra.h
 * Author: mahmoud yasser
 *
 * Created on November 17, 2021, 8:35 AM
 */

#ifndef ULTRA_H
#define	ULTRA_H

#ifdef	__cplusplus
extern "C" {
#endif

    
    
#define ECHO_PIN      6      //pin 6
#define TRIGGER_PIN   5      //pin 5
#define Sensor_DDR    DDRD
#define Sensor_PORT   PORTD


void SetupUltrasonic();
void delay_10us();
void SendTrigger();
void ReceiveEcho();
int RangeDetection(unsigned char min, unsigned char max);

#ifdef	__cplusplus
}
#endif

#endif	/* ULTRA_H */

