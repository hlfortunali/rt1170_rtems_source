  #!/bin/sh   
###
 # @Author: LiHeng
 # @Date: 2024-01-29 17:28:10
 # @LastEditors: LiHeng
 # @LastEditTime: 2024-02-07 19:37:46
 # @FilePath: /rtems/rt1052_build.sh
 # @Description: 
 # 
 # Copyright (c) 2024 by LiHeng, All Rights Reserved. 
### 
  echo "[arm/imxrt1052]" > config.ini   
  echo "BUILD_TESTS = True" >> config.ini 
  echo "BUILD_SAMPLES=True" >> config.ini     
  echo "RTEMS_DEBUG=True" >> config.ini     
  echo "OPTIMIZATION_FLAGS = -O0 -g3 -fdata-sections -ffunction-sections" >> config.ini
  ./waf configure --prefix=$RTEMS_HOME/rtems/6 &&   
  ./waf &&   
  ./waf install &&   
  echo "\nBuild finished!\n"    
