/*
 * Configuation settings for the Renesas HACHIKO board
 *
 * Copyright (C) 2014 Carlo Caione <carlo@caione.org>.
 *
 * based on rskrza1.h
 *
 * Copyright (C) 2013 Renesas Solutions Corp.
 * Copyright (C) 2012 Renesas Electronics Europe Ltd.
 * Copyright (C) 2012 Phil Edworthy
 *
 * This file is released under the terms of GPL v2 and any later version.
 * See the file COPYING in the root directory of the source tree for details.
 */

#ifndef __HACHIKO_H
#define __HACHIKO_H

#undef DEBUG
#define CONFIG_ARMV7		1	/* This is an ARM V7 CPU core */
#define CONFIG_CPU_RZA1	1
#define CONFIG_BOARD_LATE_INIT	1
#define CONFIG_MACH_TYPE MACH_TYPE_HACHIKO
#define CONFIG_BOARD_EARLY_INIT_F

#define CONFIG_CMD_NET
#define CONFIG_CMD_MII
#define CONFIG_CMD_PING
#define CONFIG_CMD_DHCP
#define CONFIG_CMD_USB
#define CONFIG_CMD_EXT2
#define CONFIG_CMD_EXT4
#define CONFIG_CMD_FAT
#define CONFIG_CMD_SF
#define CONFIG_CMD_I2C
#define CONFIG_CMD_EEPROM
#define CONFIG_CMD_DATE
#define CONFIG_DOS_PARTITION
#define CONFIG_MAC_PARTITION
#define CONFIG_USB_STORAGE
#define CONFIG_CMD_SNTP
#define CONFIG_BOOTP_NTPSERVER
#define CONFIG_BOOTP_TIMEOFFSET

#define CONFIG_OF_LIBFDT
#define CONFIG_CMDLINE_EDITING
#define CONFIG_CMDLINE_TAG
#define CONFIG_SETUP_MEMORY_TAGS
#define CONFIG_INITRD_TAG

#ifndef _CONFIG_CMD_DEFAULT_H
# include <config_cmd_default.h>
#endif

#if !defined(CONFIG_RAM_64MB)
#define ENV_PARAMS 			\
	"kernel_addr=0x20007fc0\0" 	\
	"fdt_addr=0x20500000\0"		\
	"initpath=init=/init\0"		\
	"fbparam=\0"
#else
#define ENV_PARAMS 			\
	"kernel_addr=0x0f000000\0" 	\
	"fdt_addr=0x0e500000\0"		\
	"initpath=\0"			\
	"fbparam=vdc5fb0=3 vdc5fb1=4\0"
#endif

#define CONFIG_BOOTCOMMAND \
	"if run usbload; then run boot_usb; else run boot_nor; fi"

#define CONFIG_EXTRA_ENV_SETTINGS 																	\
	ENV_PARAMS 																			\
	"usbload=usb start && ext2load usb 0 ${kernel_addr} /boot/uImage ; ext2load usb 0 ${fdt_addr} /boot/rza1-hachiko.dtb\0" 					\
	"boot_usb=run setusbargs; bootm ${kernel_addr} - ${fdt_addr}\0" 												\
	"boot_nor=run setnorargs; bootm 0x180c0000 - 0x184c0000\0" 													\
	"setusbargs=setenv bootargs console=ttySC3,115200 root=/dev/sda1 rw rootdelay=3 ignore_loglevel earlyprintk=sh-sci.3,115200 ${initpath} ${fbparam}\0" 		\
	"setnorargs=setenv bootargs console=ttySC3,115200 root=/dev/mtdblock4 rw rootfstype=jffs2 ignore_loglevel earlyprintk=sh-sci.3,115200 ${initpath} ${fbparam}\0"

#define CONFIG_BAUDRATE		115200

#define CONFIG_BOOTDELAY	3
#define CONFIG_SYS_BAUDRATE_TABLE	{ CONFIG_BAUDRATE }

#define CONFIG_SYS_LONGHELP		/* undef to save memory	*/
#define CONFIG_SYS_PROMPT	"=> "	/* Monitor Command Prompt */
#define CONFIG_SYS_CBSIZE	256	/* Boot Argument Buffer Size */
#define CONFIG_SYS_PBSIZE	256	/* Print Buffer Size */
#define CONFIG_SYS_MAXARGS	16	/* max number of command args */

#define CONFIG_SYS_HUSH_PARSER
#define CONFIG_SYS_PROMPT_HUSH_PS2      "> "

#define CONFIG_SYS_ARM_CACHE_WRITETHROUGH

/* Serial */
#define CONFIG_SCIF_CONSOLE
#define CONFIG_CONS_SCIF3
#define SCIF3_BASE			0xE8008800

/* Memory */
/* u-boot relocated to top 256KB of ram */
#define CONFIG_NR_DRAM_BANKS		1
#define CONFIG_SYS_TEXT_BASE		0x18000000

#if !defined(CONFIG_RAM_64MB)
#define CONFIG_SYS_SDRAM_BASE		0x20000000
#define CONFIG_SYS_SDRAM_SIZE		(10 * 1024 * 1024)
#else
#define CONFIG_SYS_SDRAM_BASE		0x0c000000
#define CONFIG_SYS_SDRAM_SIZE		(64 * 1024 * 1024)
#endif

#define CONFIG_SYS_MEMTEST_START	CONFIG_SYS_SDRAM_BASE
#define CONFIG_SYS_MEMTEST_END		(CONFIG_SYS_SDRAM_BASE + 0x4000000)
#define CONFIG_SYS_MALLOC_LEN		(256 * 1024)
#define CONFIG_SYS_MONITOR_LEN		(128 * 1024)
#define CONFIG_SYS_LOAD_ADDR		(CONFIG_SYS_SDRAM_BASE + 4*1024*1024)
#define	CONFIG_LOADADDR			CONFIG_SYS_SDRAM_BASE

#if !defined(CONFIG_RAM_64MB)
#define CONFIG_SYS_INIT_SP_ADDR         (0x20500000)
#else
#define CONFIG_SYS_INIT_SP_ADDR		(0x0e000000)
#endif

#define CONFIG_SYS_NO_FLASH
#undef CONFIG_CMD_IMLS

#if !defined(CONFIG_BOOT_MODE0)
#define CONFIG_ENV_IS_IN_SPI_FLASH
#define CONFIG_ENV_OFFSET	0x80000
#define CONFIG_ENV_SECT_SIZE	0x40000
#else
#define CONFIG_ENV_IS_IN_FLASH
#define CONFIG_ENV_OFFSET	(512 * 1024)
#define CONFIG_ENV_SECT_SIZE	(256 * 1024)
#endif

#define CONFIG_ENV_SIZE		CONFIG_ENV_SECT_SIZE
#define CONFIG_ENV_ADDR		(CONFIG_SYS_FLASH_BASE + CONFIG_ENV_OFFSET)
#define CONFIG_ENV_OVERWRITE	1

#define __io

/* Spi-Flash configuration */
#define CONFIG_RZ_SPI
#define CONFIG_SPI_FLASH
#define CONFIG_SPI_FLASH_SPANSION
#define CONFIG_RZA1_BASE_QSPI0		0x3FEFA000

/* I2C configuration */
#define CONFIG_SH_RIIC
#define CONFIG_HARD_I2C
#define CONFIG_I2C_MULTI_BUS
#define CONFIG_SYS_MAX_I2C_BUS		4
#define CONFIG_SYS_I2C_SPEED		100000 /* 100 kHz */
#define CONFIG_SYS_I2C_EEPROM_ADDR	0x50
#define CONFIG_SYS_I2C_EEPROM_ADDR_LEN	2
#define CONFIG_SYS_I2C_MODULE		2
#define CONFIG_SH_I2C_BASE0		0xFCFEE000
#define CONFIG_SH_I2C_BASE1		0xFCFEE400
#define CONFIG_SH_I2C_BASE2		0xFCFEE800
#define CONFIG_SH_I2C_BASE3		0xFCFEEc00

/* RTC configuration */
#define CONFIG_RTC_RZA1
#define CONFIG_RTC_RZA1_BASE_ADDR	0xFCFF1000

/* Board Clock */
#define CONFIG_SYS_CLK_FREQ	66666666 /* P1 clock. */
#define CONFIG_SYS_HZ		1000

/* Network interface */
#define CONFIG_SH_ETHER
#define CONFIG_SH_ETHER_USE_PORT	0
#define CONFIG_SH_ETHER_PHY_ADDR	0
#define CONFIG_SH_ETHER_PHY_MODE PHY_INTERFACE_MODE_MII
#define CONFIG_SH_ETHER_EEPROM_ADDR	2 /* MAC address offset in EEPROM */
#define CONFIG_PHYLIB
#define CONFIG_BITBANGMII
#define CONFIG_BITBANGMII_MULTI

/* USB host controller */
#define CONFIG_USB_R8A66597_HCD
#define CONFIG_R8A66597_BASE_ADDR	0xE8010000
#define CONFIG_R8A66597_XTAL		0x0000	/* 48MHz */
#define CONFIG_R8A66597_ENDIAN		0x0000	/* little */

/*
 * Lowlevel configuration
 */
/* Disable WDT */
#define WTCSR_D		0xA518
#define WTCNT_D		0x5A00

/* Set clocks based on 13.3333MHz xtal */
#define FRQCR_D		0x1035	/* CPU= 300-400 MHz */

/* Disable on-chip data-retention RAM */
#define SYSCR3_D	0x0000000f

/* Enable all peripherals */
#define STBCR3_D	0x00000000
#define STBCR4_D	0x00000000
#define STBCR5_D	0x00000000
#define STBCR6_D	0x00000000
#define STBCR7_D	0x00000024
#define STBCR8_D	0x00000005
#define STBCR9_D	0x00000000
#define STBCR10_D	0x00000000
#define STBCR11_D	0x000000c0
#define STBCR12_D	0x000000f0

/* Port Control register */
/* Port1 Control register Reset */
#define PM1_D		0x40df	/* SCL2, SDA2, ET_COL, P15 */
#define PMC1_D		0x4000
#define PFC1_D		0x4000
#define PFCE1_D		0x4000
#define PFCAE1_D	0x0000
#define PIBC1_D		0x0000
#define PBDC1_D		0x0000
#define PIPC1_D		0x0000

/* Port1 Control register Set */
#define PMC1_S		0x40df
#define PBDC1_S		0x00ff
#define PIPC1_S		0x00ff

/* Port2 Control register Reset */
#define PM2_D		0xff08	/* ET_xxx */
#define PMC2_D		0x0fff	/* SPBIO01_0, SPBIO11_0, SPBIO21_0, SPBIO31_0 */
#define PFC2_D		0xffff
#define PFCE2_D		0xf000
#define PFCAE2_D	0x0000
#define PIBC2_D		0x0000
#define PBDC2_D		0x0000
#define PIPC2_D		0x0fff

/* Port2 Control register Set */
#define PMC2_S		0xffff
#define PBDC2_S		0xf000
#define PIPC2_S		0xffff

/* Port3 Control register Reset */
#define PM3_D		0x007c	/* CS1, TxD2, RxD2, ET_MDIO, ET_RXCCLK
				   ET_RXER ET_RXDV */
#define PMC3_D		0x00f5
#define PFC3_D		0x007d
#define PFCE3_D		0x0084
#define PFCAE3_D	0x0081
#define PIBC3_D		0x0000
#define PBDC3_D		0x0000
#define PIPC3_D		0x00f7

/* Port3 Control register Set */
#define PMC3_S		0x00fd
#define PBDC3_S		0x0008
#define PIPC3_S		0x00ff

/* Port5 Control register Set */
#define PM5_D		0x00ff	/* CS2, ET_MDC */
#define PMC5_D		0x0300
#define PFC5_D		0x0300
#define PFCE5_D		0x0000
#define PFCAE5_D	0x0100

/* Port6 Control register Set */
#define PMC6_D		0xffff	/* D1 - D15 */
#define PIPC6_D		0xffff

/* Port7 Control register Set */
#define PM7_D		0x0000	/* WE0/DQMLL, RD/WR, RD, CS0 */
#define PMC7_D		0xffff	/* CS3, CKE, CAS, RAS, WE1/DQMLL, A7-A1 */
#define PFC7_D		0x0000
#define PFCE7_D		0x0000
#define PFCAE7_D	0x0000
#define PIPC7_D		0xffff

/* Port8 Control register Set */
#define PM8_D		0x0000	/* A23-A8 */
#define PMC8_D		0xffff
#define PFC8_D		0x0000
#define PFCE8_D		0x0300
#define PFCAE8_D	0x0300
#define PIPC8_D		0xffff  /* A23-A8 NOR, A15-A8 SDRAM */

/* Port9 Control register Set */
#define PM9_D		0xfffc	/* A25,A24 NOR, P9_2-P9_7(SPBxxx) SPI Flash */
#define PMC9_D		0x00ff	/* SPBIO00_0, SPBIO10_0, SPBIO20_0, SPBIO20_0 */
#define PFC9_D		0x00fc
#define PFCE9_D		0x0000
#define PFCAE9_D	0x0000
#define PIPC9_D		0x00ff

/* Configure NOR Flash (CS0, CS1) */
#define CS0WCR_D	0x00000b40
#define CS0BCR_D	0x10000C00
#define CS1WCR_D	0x00000b40
#define CS1BCR_D	0x10000C00

/* Configure SDRAM (CS2, CS3) */
#define CS2BCR_D	0x00004C00
#define CS2WCR_D	0x00000080
#define CS3BCR_D	0x00004C00
#define CS3WCR_D	0x00002492
#define SDCR_D		0x00120812
#define RTCOR_D		0xA55A0020
#define RTCSR_D		0xA55A0010

#endif	/* __HACHIKO_H */
