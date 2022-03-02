/*------------------------------------

SDISK II LCD Firmware

2010.11.11 by Koichi Nishida
2012.01.26 by F�bio Belavenuto
2015.07.02 by Alexandre Suaide

-------------------------------------
*/

/*
2015.07.02 by Alexandre Suaide
Added support for SDHC cards and subdirectories
Removed DSK to NIC conversion
FAT16 and FAT32 disks should have at least 64 blocks per cluster
*/

/*
2012.01.26 by F�bio Belavenuto
Added support for image exchange using a button added in the Brazilian version by Victor Trucco
Added support for a 16x2 LCD
*/

/*
This is a part of the firmware for DISK II emulator by Nishida Radio.

Copyright (C) 2010 Koichi NISHIDA
email to Koichi NISHIDA: tulip-house@msf.biglobe.ne.jp

This program is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3 of the License.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef CONFIG_H_
#define CONFIG_H_

#define nop() __asm__ __volatile__ ("nop")
#define clear_bit(a,z) (a &= ~_BV(z))
#define set_bit(a,z) (a |= _BV(z))
//#define LCD_FLIP_ADD 0

/*
This is the second version of SDISK II built by Victor Trucco
with the Nokia 5110 graphical LCD display with USB connection
for firmware update.

DO NOT CHANGE THIS unless you really know what you are doing
*/

	#define _OLED_
	// OLED pins
	#define SDA_PIN 5
	#define SDA_PORT PORTC
	#define SCL_PIN 4
	#define SCL_PORT PORTC
	#define SSD1306_ADDRESS 0x3C

	// SPI (SD SLOT) pins
	#define SPI_MISO  0
	#define SPI_CLOCK 5
	#define SPI_MOSI  3 //DI
	#define SPI_CS    4
	#define SD_EJECT  1
	#define SPI_DDR   DDRD
	#define SPI_PIN   PIND
	#define SPI_PORT  PORTD
	#define _CLK_DI_CS	0b00111000
	#define _CLKNDI_CS	0b00110000
	#define NCLK_DI_CS	0b00011000
	#define NCLKNDI_CS	0b00010000
	#define _CLK_DINCS	0b00101000
	#define _CLKNDINCS	0b00100000
	#define NCLK_DINCS	0b00001000
	#define NCLKNDINCS	0b00000000

	// SD LED
	#define SD_LED_PORT PORTB
	#define SD_LED_PORTD DDRB
	#define SD_LED 4

	// BOTOES
	#define ENTER_PORT       PIND
	#define DOWN_PORT        PIND
	#define UP_PORT          PINB
	#define ENTER_PORTD      PORTD
	#define DOWN_PORTD       PORTD
	#define UP_PORTD         PORTB
	#define ENTER_BIT        DDD6
	#define DOWN_BIT         DDD7
	#define UP_BIT           DDB5

	// PINOS PARA A DISK II - APPLE
	#define DISKII_PIN       PINC
	#define DISKII_ENABLE    DDC0

#endif /* CONFIG_H_ */
