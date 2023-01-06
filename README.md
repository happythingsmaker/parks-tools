# parks-tools
opensource. I made this because I need this.

This is Dial board for those who wants to make their own dial by themselves.

The board can be cut half and use for one dial. That's why the product name is XE (X times Encoder)

![PCB](/hardware/parks-tool-12E-AT.jpg)

## VID and PID
myboard.build.vid=0x1209

myboard.build.pid=0x6100 (requesting soon)

myboard.build.usb_product="Park's Tools XE-AT"


This board is based on Arduino Micro Pro (Ardiino Leonardo)


## To add the device name on Arduino IDE
Modifying boards.txt

Open C:\Program Files (x86)\Arduino\hardware\arduino\avr\boards.txt

At its end, add:

    ##############################################################


    parkstools.name=Park's Tools XE-AT
    parkstools.vid.0=0x1209
    parkstools.pid.0=0x6100

    parkstools.upload.tool=avrdude
    parkstools.upload.protocol=avr109
    parkstools.upload.maximum_size=28672
    parkstools.upload.maximum_data_size=2560
    parkstools.upload.speed=57600
    parkstools.upload.disable_flushing=true
    parkstools.upload.use_1200bps_touch=true
    parkstools.upload.wait_for_upload_port=true

    parkstools.bootloader.tool=avrdude
    parkstools.bootloader.low_fuses=0xff
    parkstools.bootloader.high_fuses=0xd8
    parkstools.bootloader.extended_fuses=0xcb
    parkstools.bootloader.file=caterina/Caterina-Leonardo.hex
    parkstools.bootloader.unlock_bits=0x3F
    parkstools.bootloader.lock_bits=0x2F

    parkstools.build.mcu=atmega32u4
    parkstools.build.f_cpu=16000000L
    parkstools.build.vid=0x1209
    parkstools.build.pid=0x6100
    parkstools.build.usb_product="Park's Tools XE-AT"
    parkstools.build.board=AVR_LEONARDO
    parkstools.build.core=arduino
    parkstools.build.variant=leonardo
    parkstools.build.extra_flags={build.usb_flags}
