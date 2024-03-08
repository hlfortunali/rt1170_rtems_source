  #!/bin/sh   
###
 # @Author: LiHeng
 # @Date: 2024-02-07 18:59:01
 # @LastEditors: LiHeng
 # @LastEditTime: 2024-02-17 17:47:37
 # @FilePath: /rtems/zedboard_build.sh
 # @Description: 
 # 
 # Copyright (c) 2024 by LiHeng, All Rights Reserved. 
### 
  echo "[arm/xilinx_zynq_zedboard]" > config.ini   
  echo "BUILD_TESTS=True" >> config.ini 
  echo "BUILD_SAMPLES=True" >> config.ini     
  echo "RTEMS_DEBUG=True" >> config.ini     
  echo "ZYNQ_CLOCK_UART = 100000000" >> config.ini
  echo "BSP_ARM_A9MPCORE_PERIPHCLK = 333333334" >> config.ini
  echo "OPTIMIZATION_FLAGS = -O0 -g3 -fdata-sections -ffunction-sections" >> config.ini
  ./waf configure --prefix=$RTEMS_HOME/rtems/6 &&   
  ./waf &&   
  ./waf install &&   
  echo "\nBuild finished!\n"    
