  #!/bin/sh   
###
 # @Author: LiHeng
 # @Date: 2024-02-07 18:59:01
 # @LastEditors: LiHeng
 # @LastEditTime: 2024-02-07 23:39:32
 # @FilePath: /rtems/stm32f4_build.sh
 # @Description: 
 # 
 # Copyright (c) 2024 by LiHeng, All Rights Reserved. 
### 
  echo "[arm/stm32f4]" > config.ini   
  echo "BUILD_TESTS=False" >> config.ini 
  echo "BUILD_SAMPLES=True" >> config.ini     
  echo "RTEMS_DEBUG=True" >> config.ini     
  echo "STM32F4_ENABLE_USART_1=True" >> config.ini     
  echo "STM32F4_ENABLE_USART_3=False" >> config.ini     
  echo "OPTIMIZATION_FLAGS = -O0 -g3 -fdata-sections -ffunction-sections" >> config.ini
  ./waf configure --prefix=$RTEMS_HOME/rtems/6 &&   
  ./waf &&   
  ./waf install &&   
  echo "\nBuild finished!\n"    
