#include<avr/io.h>
#include<util/delay.h>
#include <avr/interrupt.h>

#define DD_MOSI 5
#define DD_MISO 6
#define DD_SCK 7
#define DDR_SPI DDRB

void SPI_SlaveInit(void)
{
	// Set MISO output, all others input
	DDR_SPI = (1<<DD_MISO);
	// Enable SPI
	SPCR = (1<<SPE);
}

char SPI_SlaveReceive(void)
{
	// Wait for reception complete
	// SPI Status Reg & 1<<SPI Interrupt Flag
	while(!(SPSR & (1<<SPIF)));

	// Return data register
	return SPDR;
}

int main()
{
	SPI_SlaveInit();
	DDRC=255; //PORTC as output,for testing
	

	while(1)
	{
		SPI_SlaveInit();
		PORTC=SPI_SlaveReceive();
	}
	return 0;
}

