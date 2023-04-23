    
        \                                        __|  |    _)        |      |   
       _ \ \ \ /  -_)   _| _` |   _` |   -_)   \__ \    \   |   -_)  |   _` |   
     _/  _\ \_/ \___| _| \__,_| \__, | \___|   ____/ _| _| _| \___| _| \__,_|   
                                ____/                                           

<img src="https://user-images.githubusercontent.com/88851382/233837613-c5e93917-dbea-4d7e-97d9-332ee09b6272.png" align="right"
     height="75">

A minimised implementation of the SDU IO Expansion Board primarily desgined for use in EMB1 and EMB2.
The goal was to design an easily portable; code compatible device that's smaller than the Arduino Nano in every dimension.


## Limitations
* The 20x4 character LCD is replaced with a 128x32 0.91 inch OLED display. As such it is not directly code compatible and a translatory library (``SSD1306.h``) is required for operation.

* The LM75 is placed in close proximity to heat generating components and there is no direct path to ambient air to limit dust ingress. Thus the readings are skewed and are not representative of the ambient temperature. The ``LM75.h`` library was therefore altered to allow for emulation of the temperature through UART commands.

## Usage
WIP


## Hardware
A 4 layer PCB is used to achieve the desired form factor.
<img src="https://user-images.githubusercontent.com/88851382/233835004-bde6611e-34a7-46ee-a9cd-74797b62d04e.png" width="650">

The design is not cost or BOM optimised, a lot of work could be done to reduce the number of parts required. Due to small number that I intended to create, I was not concerned with the cost.

The outer shell was printed using an FDM process, the size and detail requirements would make MSLA a more suitable option for future devices.


