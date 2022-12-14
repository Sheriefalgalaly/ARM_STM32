#ifndef  GPIO_PRIVATE_H
#define  GPIO_PRIVATE_H

enum PINS {
PIN_0   ,
PIN_1   ,
PIN_2   ,
PIN_3   ,
PIN_4   ,
PIN_5   ,
PIN_6   ,
PIN_7   ,
PIN_8   ,
PIN_9   ,
PIN_10  ,
PIN_11  ,
PIN_12  ,
PIN_13  ,
PIN_14  ,
PIN_15
};

enum GPIO_PORT{
PORTA    ,
PORTB    ,
PORTC   };



typedef struct {

	u32 MODER     ;
	u32 OTYPER    ;
	u32 OSPEEDR   ;
	u32 PUPDR     ;
	u32 IDR       ;
	u32 ODR       ;
	u32 BSRR      ;
	u16 BSRR_R    ;
	u16 BSRR_S    ;
	u32 LCKR      ;
	u32 AFRL      ;
	u32 AFRH      ;
}PORT_t;

#define PORTA_REG    ((volatile PORT_t *) 0x40020000 )
#define PORTB_REG    ((volatile PORT_t *) 0x40020400 )
#define PORTC_REG    ((volatile PORT_t *) 0x40020800 )


#define PORTA_MODER    M_PORTA_0<<0   | M_PORTA_1<<2  |M_PORTA_2<<4  |M_PORTA_3<<6   | M_PORTA_4<<8   |M_PORTA_5<<10  | M_PORTA_6<<12 |  M_PORTA_7<<14  | M_PORTA_8<<16 |M_PORTA_9<<18 |M_PORTA_10<<20 | M_PORTA_11<<22 |M_PORTA_12<<24 |M_PORTA_15<<30

#define PORTA_TYPER    T_PORTA_0<<0   | T_PORTA_1<<1  |T_PORTA_2<<2  |T_PORTA_3<<3   | T_PORTA_4<<4   |T_PORTA_5<<5  | T_PORTA_6<<6 |  T_PORTA_7<<7  | T_PORTA_8<<8 |T_PORTA_9<<9 |T_PORTA_10<<10  |T_PORTA_12<<12 |  T_PORTA_15<<15

#define PORTA_SPEEDR   S_PORTA_0<<0   | S_PORTA_1<<2  |S_PORTA_2<<4  |S_PORTA_3<<6   | S_PORTA_4<<8   |S_PORTA_5<<10  | S_PORTA_6<<12 |  S_PORTA_7<<14  | S_PORTA_8<<16 |S_PORTA_9<<18 |S_PORTA_10<<20 | S_PORTA_11<<22 |S_PORTA_12<<24 |S_PORTA_15<<30

#define PORTA_PUDR     P_PORTA_0<<0   | P_PORTA_1<<2  |P_PORTA_2<<4  |P_PORTA_3<<6   | P_PORTA_4<<8   |P_PORTA_5<<10  | P_PORTA_6<<12 |  P_PORTA_7<<14  | P_PORTA_8<<16 |P_PORTA_9<<18 |P_PORTA_10<<20 | P_PORTA_11<<22 |P_PORTA_12<<24 |P_PORTA_15<<30


#define PORTB_MODER    M_PORTB_0<<0   | M_PORTB_1<<2  |M_PORTB_2<<4  |M_PORTB_3<<6   | M_PORTB_4<<8   |M_PORTB_5<<10  | M_PORTB_6<<12 |  M_PORTB_7<<14  | M_PORTB_8<<16 |M_PORTB_9<<18 |M_PORTB_10<<20 |M_PORTB_12<<24 | M_PORTB_13<<26 | M_PORTB_14<<28 | M_PORTB_15<<30

#define PORTB_TYPER    T_PORTB_0<<0   | T_PORTB_1<<1  |T_PORTB_2<<2  |T_PORTB_3<<3   | T_PORTB_4<<4   |T_PORTB_5<<5  | T_PORTB_6<<6 |  T_PORTB_7<<7  | T_PORTB_8<<8 |T_PORTB_9<<9 |T_PORTB_10<<10  |T_PORTB_12<<12 | T_PORTB_13<<13 | T_PORTB_14<<14 | T_PORTB_15<<15

#define PORTB_SPEEDR   S_PORTB_0<<0   | S_PORTB_1<<2  |S_PORTB_2<<4  |S_PORTB_3<<6   | S_PORTB_4<<8   |S_PORTB_5<<10  | S_PORTB_6<<12 |  S_PORTB_7<<14  | S_PORTB_8<<16 |S_PORTB_9<<18 |S_PORTB_10<<20  |S_PORTB_12<<24 | S_PORTB_13<<26 | S_PORTB_14<<28 | S_PORTB_15<<30

#define PORTB_PUDR     P_PORTB_0<<0   | P_PORTB_1<<2  |P_PORTB_2<<4  |P_PORTB_3<<6   | P_PORTB_4<<8   |P_PORTB_5<<10  | P_PORTB_6<<12 |  P_PORTB_7<<14  | P_PORTB_8<<16 |P_PORTB_9<<18 |P_PORTB_10<<20  |P_PORTB_12<<24 | P_PORTB_13<<26 | P_PORTB_14<<28 | P_PORTB_15<<30


#define PORTC_MODER    M_PORTC_13<<26 | M_PORTC_14<<28 | M_PORTC_15<<30

#define PORTC_TYPER    T_PORTC_13<<13 | T_PORTC_14<<14 | T_PORTC_15<<15

#define PORTC_SPEEDR   S_PORTC_13<<26 | S_PORTC_14<<28 | S_PORTC_15<<30

#define PORTC_PUDR     P_PORTC_13<<26 | P_PORTC_14<<28 | P_PORTC_15<<30





u16 GPIO_whichPINs(u8 inputRegister , u16 PINS);

#endif

