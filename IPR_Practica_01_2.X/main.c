/*
 * File:   main.c
 * Author: gustavomendoza
 *
 * Created on December 13, 2021, 1:37 PM
 */


#include <xc.h>
#include "configurationBits.h"

void main(void) {
    
    //Configuracion de pines 
    //Puerto entrada analogica
    //Configuramos el convertidor analogico digital
    ADCON0 = 0b00000001; // Habilitamos el convertidos y establecemos el puerto AN0
    ADCON1 = 0b00001110; // Establecemos referencias como Vdd y Vss, habilitamos slamente AN0 como analogico
    ADCON2 = 0b00111111; // Configuracion de registro de combertidor
    
    //Configuramos Puerto D como Salida
    PORTD = 0x00; //Limpiasmos Puerto
    LATD = 0x00; //Limpiamos PUerto
    TRISD = 0b00000000; //Configuramos como salida

    while(1){//Ciclo Principal
        while(ADCON0bits.ADON); //Esperamos a que terminen la conversion
        PORTD = ADRESL;         // Igualamos el registro de los bits menos siginifactivos de la comberciuon en el puerto D
        __delay_ms(250);
    }
    
    
    return;
}
