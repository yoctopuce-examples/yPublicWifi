# *********************************************************************
#
#  Unix Makefile for examples (use  GNU make)
#
# ********************************************************************

#YOCTOPUCE SPECIFIC DEFINITIONS
YOCTO_API_INCLUDE = yoctopuce_api/include/
YOCTO_API_LIB = yoctopuce_api/lib/

YOCTO_COMPILE_OPTIONS = -DCPU_BIG_ENDIAN -I$(YOCTO_API_INCLUDE)
YOCTO_LINK_OPTIONS = -L$(YOCTO_API_LIB) -lyocto-static


#OPEN WRT BUILD ROOT DEFINITIONS
TARGET_OPEN_WRT_IP = 192.168.0.254

MIPS_TARGET_ROOT = $(STAGING_DIR)/target-mips_34kc_uClibc-0.9.33.2/
CC = mips-openwrt-linux-gcc
CPP = mips-openwrt-linux-g++
OPEN_WRT_COMPILE_OPTIONS = -I$(MIPS_TARGET_ROOT)/usr/include/
OPEN_WRT_LINK_OPTIONS = -L$(MIPS_TARGET_ROOT)/usr/lib/ -lm -lpthread -lusb-1.0 



yPublicWiFi: main.cpp $(YOCTO_API_INCLUDE)*
	@$(CPP) -O2 -Wall $(YOCTO_COMPILE_OPTIONS) $(OPEN_WRT_COMPILE_OPTIONS) -o $@ main.cpp $(YOCTO_LINK_OPTIONS) $(OPEN_WRT_LINK_OPTIONS)

upload: yPublicWiFi
	@scp yPublicWiFi root@$(TARGET_OPEN_WRT_IP):/usr/sbin
	@scp startupscript.sh root@$(TARGET_OPEN_WRT_IP):/etc/init.d/ypublicwifi
	@echo connect to $(TARGET_OPEN_WRT_IP) and enable yPublicWifi with:
	@echo     ypublicwifi enable
	@echo     ypublicwifi start


clean:
	@rm -rf  ywifi *.o

