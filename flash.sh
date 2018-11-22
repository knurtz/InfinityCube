arm-none-eabi-objcopy -I ihex --output-target=binary Debug/InfinityCube.hex Debug/InfinityCube.bin
st-flash write Debug/InfinityCube.bin 0x8000000
