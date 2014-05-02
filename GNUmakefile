# *********************************************************************
#
#  Unix Makefile for examples (use  GNU make)
#
# ********************************************************************

#YOCTOPUCE SPECIFIC DEFINITIONS
#YOCTO_API_INCLUDE = yoctopuce_api/include/
#YOCTO_API_LIB = yoctopuce_api/lib/

YOCTO_API_INCLUDE = ../yoctoprod/yoctolib/v1.0/Public/cpp/Sources/
YOCTO_API_LIB = ../yoctoprod/yoctolib/v1.0/Public/cpp/Binaries/linux/mips


YOCTO_COMPILE_OPTIONS = -DCPU_BIG_ENDIAN -I$(YOCTO_API_INCLUDE)
YOCTO_LINK_OPTIONS = -L$(YOCTO_API_LIB) -lyocto-static


#OPEN WRT BUILD ROOT DEFINITIONS
MIPS_TARGET_ROOT = $(STAGING_DIR)/target-mips_34kc_uClibc-0.9.33.2/
CC = mips-openwrt-linux-gcc
CPP = mips-openwrt-linux-g++
OPEN_WRT_COMPILE_OPTIONS = -I$(MIPS_TARGET_ROOT)/usr/include/
OPEN_WRT_LINK_OPTIONS = -L$(MIPS_TARGET_ROOT)/usr/lib/ -lm -lpthread -lusb-1.0 



ywifi: main.cpp $(YOCTO_API_INCLUDE)*
	@$(CPP) -O2 -Wall $(YOCTO_COMPILE_OPTIONS) $(OPEN_WRT_COMPILE_OPTIONS) -o $@ main.cpp $(YOCTO_LINK_OPTIONS) $(OPEN_WRT_LINK_OPTIONS)


clean:
	@rm -rf  ywifi *.o

