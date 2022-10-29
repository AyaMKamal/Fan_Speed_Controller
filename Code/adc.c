/************************************************************************************************
 * MODULE :  ADC
 *
 * FILE : ADC.c
 *
 * AUTHOR : Aya Mohamed
 **************************************************************************************************/
#include "adc.h"
#include "common_macros.h"
#include <avr/io.h>

void ADC_init(const ADC_ConfigType * Config_Ptr)
{
	ADMUX = 0;
	/*choose ref voltage*/
	ADMUX = (ADMUX & 0x3F) | ((Config_Ptr ->ref_volt)<<6);

	/* ADCSRA Register Bits Description:
		 * ADEN    = 1 Enable ADC
		 * ADIE    = 0 Disable ADC Interrupt
		 * ADATE   = 0 Disable Auto Trigger
		 * ADPS2:0 = first 3 bits to choose what clock ADC should work with --> ADC must operate in range 50-200Khz
		 */
	ADCSRA = (1<<ADEN);

	ADCSRA = (ADCSRA & 0xF8) | (Config_Ptr ->prescaler);

}
uint16 ADC_readChannel(uint8 channel_num)
{
	ADMUX=(ADMUX & 0XE0 )|(channel_num & 0X07); /* Input channel number must be 0 -> 7 and Clear first 5 bits in the ADMUX
	and Choose the correct channel*/
	SET_BIT (ADCSRA,ADSC);/*start conversion */
	while (BIT_IS_CLEAR(ADCSRA,ADIF));/*polling : wait for conversion to complete*/
	SET_BIT(ADCSRA,ADIF);/* clear ADIF by writing 1 in it*/
	 return ADC;/*read the value*/
}



