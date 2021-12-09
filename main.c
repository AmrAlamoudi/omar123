/*
 * File:   main.c
 * Author: hossa
 *
 * Created on September 24, 2021, 3:26 PM
 */
 
// MASTER AVR
#include <avr/io.h>
#include "config.h"
#include "mMotor.h"
#include "mLCD_4bit.h"
#include "mADC.h"
#include "mTimer.h"
#include "mSPI.h"
#include <string.h>
#include <util/delay.h>
#include"servo.h"
#include "ultra.h"






int main(void) {
    
    char* str1= 'obstacle';
    char* str2= 'detected';

    
    
    init_LCD_4bit();
              _delay_ms(50);

    servo_init();
              _delay_ms(50);

    init_Motor( Motor1);
              _delay_ms(50);

    init_Motor( Motor2);
              _delay_ms(50);

   SetupUltrasonic();
              _delay_ms(50);

    init_Leds();
          _delay_ms(50);

    
     sei();  
     
   

    Motor_Forward( Motor1 );
    Motor_Forward( Motor2 );

    while (1) { 
       
    
        SendTrigger();
        ReceiveEcho();
         
        if(RangeDetection(1,10)){ // if there is a block facing the car
           
            LCD_write_str_4bit(str1);
            LCD_write_str_4bit(str2);
            Motor_Stop( Motor1 );
            Motor_Stop( Motor2 );
            
            set_degree(0);   // look right
            
            SendTrigger();
            ReceiveEcho();
            
            if(!RangeDetection(1,10)){ // if there is no block on the  right of the car the go right
                
                set_degree(90);
                
                Motor_Dir(right);
                _delay_ms(500);
                
                Motor_Forward( Motor1 );
                Motor_Forward( Motor2 );
                
                
            }
            else{   // if there is another block on the  right of the car
                
                LCD_write_str_4bit(str1);
                LCD_write_str_4bit(str2);

                set_degree(180);  // look left
                
                SendTrigger();
                ReceiveEcho();
                
                if(!RangeDetection(1,10)){ // if there is no block on the left of the car the go left
               
                set_degree(90);
                
                Motor_Dir(left);
                _delay_ms(500);
                Motor_Forward( Motor1 );
                Motor_Forward( Motor2 );
                }
                
                else{ // if there is another block on the  left of the car
                     
                    LCD_write_str_4bit(str1);
                    LCD_write_str_4bit(str2);
                    Motor_Reverse( Motor1 ); // then move backward
                    Motor_Reverse( Motor2 );
                    _delay_ms(1000); // car need to look right & left every 1 second to determine the new direction
                }
           
            }
        }       
    }
    return 0;
    }
 

