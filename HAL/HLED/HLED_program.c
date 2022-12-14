/*
 * HLED_program.c
 *
 *  Created on: Aug 2, 2022
 *      Author: Admin
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_Interface.h"
#include "HLED_interface.h"

void HLED_voidTurnOn(LED_t* LED){
	if(LED->state == AtciveHigh)
	   GPIO_PINWrite_LOW(LED->Port, LED->Pin);
	else if (LED->state == ActiveLow)
		GPIO_PINWrite_High(LED->Port, LED->Pin);
}
void HLED_voidTurnOff(LED_t* LED){
	if(LED->state == AtciveHigh)
    	GPIO_PINWrite_High(LED->Port, LED->Pin);
	else if (LED->state == ActiveLow)
		GPIO_PINWrite_LOW(LED->Port, LED->Pin);

}

