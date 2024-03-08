#!/bin/sh
###
 # @Author: LiHeng
 # @Date: 2024-02-21 16:59:34
 # @LastEditors: LiHeng
 # @LastEditTime: 2024-03-01 20:51:48
 # @FilePath: /quick-start/src/rtems/bsps/arm/imxrt/dts/gen_dtc.sh
 # @Description: 
 # 
 # Copyright (c) 2024 by LiHeng, All Rights Reserved. 
##

# arm-rtems6-cpp -P -x assembler-with-cpp -I ${RTEMS_HOME}/rtems/6/arm-rtems6/imxrt1166-cm7-saltshaker/lib/include -include "imxrt1166-cm7-saltshaker.dts" /dev/null &&
# dtc -O dtb -o "imxrt1166-cm7-saltshaker.dtb"  "imxrt1166-cm7-saltshaker.dts" -b 0 -p 64 

# rtems-bin2c -A 8 -C -N imxrt_dtb "imxrt1166-cm7-saltshaker.dtb" "imxrt1166-cm7-saltshaker.c"


# BSP_DIR=/home/lee/Documents/RTEMS/RTEMS6/quick-start/src/rtems/bsps/arm/imxrt
# arm-rtems6-cpp -P -x assembler-with-cpp -I "${BSP_DIR}/include/" -include "${BSP_DIR}/dts/imxrt1166-cm7-saltshaker.dts" /dev/null > dd.log
# dtc -O dtb -o "./imxrt1166-cm7-saltshaker.dtb" "./dd.log" &&
# rtems-bin2c -A 8 -C -N imxrt_dtb "${BSP_DIR}/dts/imxrt1166-cm7-saltshaker.dtb" "./imxrt1166-cm7-saltshaker.c"

BSP_DIR=/home/lee/Documents/RTEMS/RTEMS6/quick-start/src/rtems/bsps/arm/imxrt
arm-rtems6-cpp -P -x assembler-with-cpp -I "${BSP_DIR}/include/" -include "${BSP_DIR}/dts/imxrt1170-evk.dts" /dev/null > dd.log
dtc -O dtb -o "./imxrt1170-evk.dtb" "./dd.log" &&
rtems-bin2c -A 8 -C -N imxrt_dtb "${BSP_DIR}/dts/imxrt1170-evk.dtb" "./imxrt1170-evk.c"