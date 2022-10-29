/******************************************************************************
 * File Name: main.c
 *
 * Description: Fan_Controller
 *
 * Author: Aya Mohamed
 *
 *******************************************************************************/

#include "lcd.h"
#include "lm35.h"
#include "motor.h"
#include "adc.h"

uint8 temperature=0;
/*Configure ADC**/
ADC_ConfigType config_type ={ref_volt,F_CPU_8};

int main()
{
/**********Init ADC - LCD - DCMOTOR Function************************/
	ADC_init(&config_type);
	LCD_init();
	DCmotor_init();


	while (1)
	{
		temperature = LM35_getTemperature();
	/**************Checking if temp less than 30 then turn off the fan ***********************/
		if ( temperature < 30)
		{

			DCmotor_Rotate(STOP,0);
			LCD_moveCursor(0,1);
			LCD_displayString("Fan is OFF");
			LCD_moveCursor(1,1);
			LCD_displayString("Temp = ");
			LCD_intgerToString(temperature);

		}
		else if((temperature >= 30) && (temperature <60))
		{

			DCmotor_Rotate(CW,64);
			LCD_moveCursor(0,1);
			LCD_displayString("Fan is ON ");
			LCD_moveCursor(1,1);
			LCD_displayString("Temp =  ");
			LCD_intgerToString(temperature);
		}
		else if((temperature >= 60) && (temperature <90))
		{

			DCmotor_Rotate(CW,128);
			LCD_moveCursor(0,1);
			LCD_displayString("Fan is ON ");
			LCD_moveCursor(1,1);
			LCD_displayString("Temp =  ");
			LCD_intgerToString(temperature);
		}
		else if((temperature >= 90) && (temperature <120))
		{

			DCmotor_Rotate(CW,192);
			LCD_moveCursor(0,1);
			LCD_displayString("Fan is ON ");
			LCD_moveCursor(1,1);
			LCD_displayString("Temp =  ");
			LCD_intgerToString(temperature);

		}

		else if(temperature >= 120)
		{

			DCmotor_Rotate(CW,255);
			LCD_moveCursor(0,1);
			LCD_displayString("Fan is ON ");
			LCD_moveCursor(1,1);
			LCD_displayString("Temp =  ");
			LCD_intgerToString(temperature);
		}
	}

}
