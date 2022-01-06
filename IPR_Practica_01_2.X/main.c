/*
 * File:   main.c
 * Author: gustavomendoza
 *
 * Created on December 13, 2021, 1:37 PM
 */


#include <xc.h>
#include <pic18f4550.h>
#include "configurationBits.h"


void main(void) {
    
    //Configuracion de pines 
    //Puerto entrada analogica
    //Configuramos el convertidor analogico digital de acuerdo a la hoja de datos
    // configurar modulo A/D
    TRISAbits.RA0 = 1; //configuramos puerto AN0 cono entrada
    ADCON1 = 0b00001110; // Establecemos referencias como Vdd y Vss, habilitamos slamente AN0 como analogico
    ADCON0 = 0b00000001; // Habilitamos el convertidor y establecemos el puerto AN0
    ADCON2 = 0b00010101; // configurar TAD = 4 conversion cloc Fosc/16
    
    //Configuramos Puerto D como Salida
    PORTD = 0x00; //Limpiasmos Puerto
    LATD = 0x00; //Limpiamos PUerto
    TRISD = 0b00000000; //Configuramos como salida

    while(1){//Ciclo Principal
        ADCON0bits.GO_DONE = 1;
        while(ADCON0bits.GO_DONE); //Esperamos a que terminen la conversion
        PORTD = ADRESL;         // Igualamos el registro de los bits menos siginifactivos de la comberciuon en el puerto D
        __delay_ms(250);
    }
    
    
    return;
}
