/*
 * HSEVSEG_program.c
 *
 *  Created on: Aug 2, 2022
 *      Author: Admin
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_Interface.h"
#include "HLED_interface.h"
#include "HSEVSEF_interface.h"
#include "HSEVSEG_private.h"
void delay(){
	for (int i=0 ;i<1000;i++)
		asm ("nop");
}
static void HSevSeg_voidDisable(SevSeg_t* Sev){

	if(Sev->Common==CommonCathode)
		GPIO_PINWrite_High(*(Sev->port),*(Sev->pins));

	else if(Sev->Common==CommonAnode)
		GPIO_PINWrite_LOW(*(Sev->port),*(Sev->pins));



}
void HSevSeg_voidSetNum(SevSeg_t* Sev,u8 Num){
	if (Num>9)
return;

	u8 Local_u8num=SEVNumbers[Num];
	if(Sev->Common==CommonCathode)
	{
		GPIO_PINWrite_LOW(*(Sev->port),*(Sev->pins));
		for (u8 i=0;i<7;i++)
			if(GET_BIT(Local_u8num,i)==1)
				GPIO_PINWrite_High(*((Sev->port)+i),*( (Sev->pins)+i));
	}
	else if(Sev->Common==CommonAnode)
	{
		GPIO_PINWrite_High(*(Sev->port),*(Sev->pins));
		for (u8 i=0;i<7;i++)
			if(GET_BIT(Local_u8num,i)==1)
				GPIO_PINWrite_LOW(*((Sev->port)+i),*( (Sev->pins)+i));
	}

}
void HSevSeg_voidSetTwoNum(SevSeg_t* Sev1,SevSeg_t* Sev2,u8 Num){
	u8 Local_u8Ones=Num%10;
	u8 Local_u8Tens=Num/10;

	HSevSeg_voidClear(Sev1);

	HSevSeg_voidSetNum(Sev1, Local_u8Ones);
	delay();
	HSevSeg_voidDisable(Sev1);
	HSevSeg_voidClear(Sev1);

	HSevSeg_voidSetNum(Sev2, Local_u8Tens);
	delay();
	HSevSeg_voidDisable(Sev2);
	HSevSeg_voidClear(Sev2);

	return;

}

void HSevSeg_voidClear(SevSeg_t* Sev){
	if(Sev->Common==CommonCathode)
	{

		for (u8 i=0;i<7;i++)
				GPIO_PINWrite_LOW(*((Sev->port)+i),*( (Sev->pins)+i));
	}
	else if(Sev->Common==CommonAnode)
	{

		for (u8 i=0;i<7;i++)
				GPIO_PINWrite_High(*((Sev->port)+i),*( (Sev->pins)+i));
	}

	return;

}
