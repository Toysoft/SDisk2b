# Customisation
## OLED Display - SSD1306
This firmware is made for SSD1306 IIC OLED, you can get them in 0.96 or 1.54 inches size.
pleasse take note of the pinout and make changes accordingly. 
pinout configuration for this PCB.
1. VCC
2. GND
3. SCL - PC4
4. SDA - PC5

IIC address is 0x3C

The above can be changed in "config.h"

## SDCARD reader / writer
This PCB uses SDCard reader from LC Studio, this is an old prrt in my bin. It comes with a AM1117-3.3v on board.
You can use any SPI SDcard reader but you will need to convert 5v from the Disk interface to 3.3v for the rest of the circuit.

You will need to disable SD_EJECT signal if your SDcard reader don't support it.

Change 
#define SD_ejected()             bit_is_set(SD_PIN,SD_EJECT)
to 
#define SD_ejected()             bit_is_clear(SD_PIN,SD_EJECT) // No SD_EJECT support

note. All VCC is 3.3v.

## Buttons
Buttons
Enter   - PD6
Down    - PD7
UP      - PB5

I am uaing TP223, button press is active high. 
So button detection is.

// Active high (using TP223)
#define enter_is_pressed() bit_is_set(ENTER_PORT,ENTER_BIT)
#define down_is_pressed()  bit_is_set(DOWN_PORT,DOWN_BIT)
#define up_is_pressed()    bit_is_set(UP_PORT,UP_BIT)

Change bit_is_set to bit_is_celar for active low switches. e.g tact switch with pull up resistor. 

# LED

LED is on PB4

# Compiling the firmware.
Use avr-gcc either on windows, mac or linux. 
see avr-gcc website on how to set up the toolchain. 

With the above info, you should be able to make your own SDISK2 version, please post your questions in the discussion page and I will try to help you with it. Thank you. 


