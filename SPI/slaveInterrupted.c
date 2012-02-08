#include<avr/io.h>
// #include<util/delay.h>
#include <avr/interrupt.h>

#define DD_MOSI 5
#define DD_MISO 6
#define DD_SCK 7
#define DDR_SPI DDRB

int Data[8];
int x;



void SPI_SlaveInterruptInit(void) // For Interrupted SPI
{
	// PORTB = 00001000
	DDR_SPI = (1<<DD_MISO);
	// set SPI enable, spi clock polarity ,  spi interrupts enable
	SPCR = (1<<SPE)|(1<<CPOL)|(1<<SPIE);
}

ISR (SPI_STC_vect)                  // SPI interrupts
{
	Data[x] = SPDR;// receive and store byte
	x++;// shift to next byte array (0 1 2 3 4 5 6 7 8 9 = 10 bytes)
	x%=10;// When 10 = reset

	PORTC=  SPDR; //Testing port
}


int main()
{
	DDRC=255; // Set PORTC as output
	PORTC=1;
	x=0;

	Data[0]=0;

	SPI_SlaveInterruptInit();

	sei();	//Enable interrupts

	while(1)
	{

	}
	return 0;
}


