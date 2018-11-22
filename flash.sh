arm-none-eabi-objcopy -I ihex --output-target=binary InfinityCube.hex InfinityCube.bin
st-flash write InfinityCube.bin 0x8000000
