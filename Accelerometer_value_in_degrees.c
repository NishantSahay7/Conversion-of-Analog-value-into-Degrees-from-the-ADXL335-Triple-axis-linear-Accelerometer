/////////////////////////////////////////////////////////////////////////////////////////////////////
///  Project Name : Accelerometer_value_in_degrees
//
//  Target Board : atmega32
//
//  Date Created : 16-07-2018 01:49:07
// 
//  Online Resource  : www.electronicsforstudents.com
//
//  Libraries Included : 
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include<avr/io.h>
#include<util/delay.h>



#include "adc.h"
#include "lcd.h"


unsigned int get_degree(int p)
{
	int x,y,z,dx,dy,dz;	//x,y,z are the 3 axes, and the dx,dy,dz are the degrees in each cordinate,for example dx=degree in x cordinate
	
	if(p==1)
	{
	x = adc_read(0);
	dx=335-x;	//for each raise in the value of 1 the degree changes by 1.384 degrees,so we are getting here the change in value and for each if we multiply it by 1.384 we will get the value in terms of degrees
	dx=dx*1.384;	//here is the conversion of the changed value in degrees
	return dx;
	}
	
	if(p==2)
	{
	y = adc_read(1);
	dy=335-y;	//same as for x cordinate
	dy=dy*1.384;
	return dy;
	}
	
	if(p==3)
	{
	z = adc_read(2);
	dz=335-z;	//same as for x cordinate
	dz=dz*1.384;
	return dz;
	}
	
}

int main()
{
	lcd_init();	//initializing the LCD
	adc_init();	//initializing the ADC module
	
	int i,x,y,z,dx,dy,dz;
	
	
	while (1)
	{
	
	
	lcd_gotoxy(0,0);	//0th row,0th coulmn
	lcd_clear();	//clearing the screen of LCD
	
	
	dx=get_degree(1);	//for getting the degree value of x cordinate
	
	dy=get_degree(2);	//for getting the degree value of y cordinate
	
	dz=get_degree(3);	//for getting the degree value of z cordinate

	
	
	lcd_num(dx);	//Printing the degrees value of x cordinate
	
	lcd_string(" ");	//this blank space leaves a gap in between x and y degrees
	
	lcd_num(dy);
	
	lcd_string(" ");
	
	lcd_num(dz);
	
	
	_delay_ms(500);


	}

}