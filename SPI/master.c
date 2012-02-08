#include<avr/io.h>
#include<util/delay.h>
#include <avr/interrupt.h>

#define DD_MOSI 5
#define DD_MISO 6
#define DD_SCK 7
#define DDR_SPI DDRB

void SPI_MasterInit(void)
{
	// Set MOSI and SCK output, all others input
	DDR_SPI = (1<<DD_MOSI)|(1<<DD_SCK);
	// Enable SPI, Master, set clock rate fck/16
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
}


void SPI_MasterTransmit(char cData)
{
	// Start transmission
	SPDR = cData;

	//PORTC=SPDR;// JUST CHECKING!

	// Wait for transmission complete
	while(!(SPSR & (1<<SPIF)));
}

int main()
{
	DDRC=255; //PORTC as output,used for Slave Selections

	while(1)
	{
		PORTC=0;
		_delay_ms(1000);
		SPI_MasterInit();
		SPI_MasterTransmit(255);
		PORTC=255;
		_delay_ms(1000);


		PORTC=0;
		_delay_ms(1000);
		SPI_MasterInit();
		SPI_MasterTransmit(0);
		PORTC=255;
		_delay_ms(1000);
	}
	return 0;
}

