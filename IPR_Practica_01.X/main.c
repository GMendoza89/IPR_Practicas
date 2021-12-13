/*
 * File:   main.c
 * Author: gustavomendoza
 *
 * Created on December 13, 2021, 1:37 PM
 */


#include <xc.h>
#include "configurationbits.h"

void main(void) {
    
    //Configuracion de pines 
    //Puerto A como entrada
    PORTA = 0x00; //Limpiasmos Puerto
    LATA = 0x00; //Limpiamos PUerto
    TRISA = 0b00111111; //Configuramos como salida
    //Configuramos Puerto B como entrada
    PORTB = 0x00; //Limpiasmos Puerto
    LATB = 0x00; //Limpiamos PUerto
    TRISB = 0b11111111; //Configuramos como salida
    //Configuramos Puerto c como entrada
    PORTC = 0x00; //Limpiasmos Puerto
    LATC = 0x00; //Limpiamos PUerto
    TRISC = 0b11110000; //Configuramos como salida
    //Configuramos Puerto D como Salida
    PORTD = 0x00; //Limpiasmos Puerto
    LATD = 0x00; //Limpiamos PUerto
    TRISD = 0b00000000; //Configuramos como salida

    while(1){//Ciclo Principal
        if(PORTCbits.RC7){
            PORTD = PORTA;
        }else{
            PORTD = PORTB;
        }
        
    }
    
    
    return;
}
