    
        \                                        __|  |    _)        |      |   
       _ \ \ \ /  -_)   _| _` |   _` |   -_)   \__ \    \   |   -_)  |   _` |   
     _/  _\ \_/ \___| _| \__,_| \__, | \___|   ____/ _| _| _| \___| _| \__,_|   
                                ____/                                           

<img src="https://user-images.githubusercontent.com/88851382/233837613-c5e93917-dbea-4d7e-97d9-332ee09b6272.png" align="right"
     height="75">

A minimised implementation of the SDU IO Expansion Board primarily desgined for use in EMB1 and EMB2. The goal was to design an easily portable; code compatible device that's smaller than the Arduino Nano in every dimension. Final dimensions of the device, case included, are 35.5 x 14.5 x 6.7mm

Made by **Martin Gornall** & **Tadas Serva** - *January 2023*


## Limitations
* The 20x4 character LCD is replaced with a 128x32 0.91 inch OLED display. As such it is not directly code compatible and a translatory library (``SSD1306.h``) is required for operation.

* The LM75 is placed in close proximity to heat generating components and there is no direct path to ambient air to limit dust ingress. Thus the readings are skewed and are not representative of the ambient temperature. The ``LM75.h`` library was therefore altered to allow for emulation of the temperature through UART commands.

## Usage
WIP

## Hardware

Files required to reproduce the device can be found in the Hardware section of the repo.

### PCB

<img src="https://user-images.githubusercontent.com/88851382/233835004-bde6611e-34a7-46ee-a9cd-74797b62d04e.png" width="400"><img src="https://user-images.githubusercontent.com/88851382/233858264-692d44dd-7cad-4a20-9f79-ccd343e8895d.png" width="380">


A 4 layer PCB is used to achieve the desired form factor. As can be seen the screen was the primary constraint on the size of the device. While other, smaller screens exist; their resolutions make it difficult to achieve the 20x4 character requirement. The design is not cost or BOM optimised, a lot of work could be done to reduce the pricing and number of parts required. Due to small number that I intended to create, I was not concerned with the cost.

### Case


<img src="https://user-images.githubusercontent.com/88851382/233857499-0fe2f345-832b-4913-be1b-a4ff60d049b5.png" width="250"> <img src="https://user-images.githubusercontent.com/88851382/233857412-6a10bbc3-9e8a-4fed-b261-d0b38bf85ef2.png" width="250"> <img src="https://user-images.githubusercontent.com/88851382/233857825-f020e269-2ab6-4f50-9b69-9aac9adeaa5d.png" width="250">



The case is a two part clam shell that was printed using an FDM process, the size and detail requirements would make MSLA a more suitable option for future devices. The use of fasteners was difficult due to the screen fully occupying a layer of the stackup. Self securing methods required the size to be increased by multiple millimeters - unacceptable! Glue was unfortunately the method used to secure everything.


