  #!/bin/sh   
###
 # @Author: LiHeng
 # @Date: 2024-02-07 19:36:50
 # @LastEditors: LiHeng
 # @LastEditTime: 2024-02-25 16:21:36
 # @FilePath: /rtems/tms570_build.sh
 # @Description: 
 # 
 # Copyright (c) 2024 by LiHeng, All Rights Reserved. 
### 
  echo "[arm/tms570ls3137_hdk_sdram]" > config.ini   
  echo "BUILD_TESTS = True" >> config.ini 
  echo "BUILD_SAMPLES=True" >> config.ini     
  echo "RTEMS_DEBUG=True" >> config.ini     
  echo "OPTIMIZATION_FLAGS = -O0 -g3 -fdata-sections -ffunction-sections" >> config.ini
  ./waf configure --prefix=$RTEMS_HOME/rtems/6 &&   
  ./waf -j32 &&   
  ./waf install &&   
  echo "\nBuild finished!\n"    
