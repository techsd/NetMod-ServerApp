REM       COMMAND FILE BUILT BY IDEA 
REM       Mon Oct 09 05:20:43 2023
REM
cxstm8 -v -l +strict +debug +modsl0 +split +warn "networkmodule_vector.c"
cxstm8 -v -l +strict +debug +modsl0 +split +warn "bme280.c" "ds18b20.c" "enc28j60.c" "gpio.c" "httpd.c" "i2c.c" "ina226.c" "main.c" "mqtt.c" "mqtt_pal.c" "pcf8574.c" "spi.c" "timer.c" "uart.c" "uip.c" "uip_arp.c" "uip_tcpapphub.c"
clnk -v -sa -o "NetworkModule.sm8" -m "NetworkModule.map" "networkmodule.lkf"
chex -f3 -o "NetworkModule.sx" "NetworkModule.sm8"
clabs "NetworkModule.sm8"
