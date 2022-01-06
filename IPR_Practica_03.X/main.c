/*
 * File:   main.c
 * Author: gustavomendoza
 *
 * Created on December 13, 2021, 1:37 PM
 */


#include <xc.h>
#include "configurationBits.h"
#include "libuart4550.h"

void main(void) {
    
    
    uartInit();// inicializamos modulo uart
    char mensaje[] = "Hola Mundo";
    while(1){//Ciclo Principal
        uartPrint(mensaje);
        __delay_ms(500);
    }
    
    
    return;
}
