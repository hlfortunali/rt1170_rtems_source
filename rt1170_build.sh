  #!/bin/sh   
###
 # @Author: LiHeng
 # @Date: 2024-02-07 19:36:50
 # @LastEditors: LiHeng
 # @LastEditTime: 2024-03-01 20:45:57
 # @FilePath: /quick-start/src/rtems/rt1170_build.sh
 # @Description: 
 # 
 # Copyright (c) 2024 by LiHeng, All Rights Reserved. 
### 
  echo "[arm/imxrt1170-evk]" > config.ini   
  echo "BUILD_TESTS = True" >> config.ini 
  echo "BUILD_SAMPLES=True" >> config.ini     
  echo "RTEMS_DEBUG=True" >> config.ini     
  echo "OPTIMIZATION_FLAGS = -O0 -g3 -fdata-sections -ffunction-sections" >> config.ini
  echo "IMXRT_MEMORY_FLASH_SIZE=0x1000000" >> config.ini
  echo "IMXRT_MEMORY_ITCM_SIZE=0x40000" >> config.ini
  echo "IMXRT_MEMORY_NULL_SIZE=0" >> config.ini
  ./waf configure --prefix=$RTEMS_HOME/rtems/6 &&   
  ./waf -j32 &&   
  ./waf install &&   
  echo "\nBuild finished!\n"    
