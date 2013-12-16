/*
 * Copyright (C) 2013 Renesas Solutions Corp.
*/

#ifndef _RZA1_REGS_H
#define _RZA1_REGS_H

/*
 *  Register bases.
 */
#define RZA1_WDT_BASE            (0xFCFE0000)
#define RZA1_FRQCR_BASE          (0xFCFE0010)
#define RZA1_STBCR_BASE          (0xFCFE0020)
#define RZA1_PCTR_BASE           (0xFCFE3000)
#define RZA1_OST_BASE            (0xFCFEC000)
#define RZA1_BCR_BASE            (0x3FFFC000)
#define RZA1_SDRAM_BASE          (0x3FFFC000)

/* Clock Registers */
#define FRQCR (RZA1_FRQCR_BASE + 0x00)
#define FRQCR2 (RZA1_FRQCR_BASE + 0x04)

/* Watchdog Registers */
#define WTCSR (RZA1_WDT_BASE + 0x00) /* Watchdog Timer Control Register */
#define WTCNT (RZA1_WDT_BASE + 0x02) /* Watchdog Timer Counter Register */
#define WRCSR (RZA1_WDT_BASE + 0x04) /* Watchdog Reset Control Register */

/* OSTimer Registers */
#define OSTM0CMP (RZA1_OST_BASE + 0x000)
#define OSTM0CNT (RZA1_OST_BASE + 0x004)
#define OSTM0TE  (RZA1_OST_BASE + 0x010)
#define OSTM0TS  (RZA1_OST_BASE + 0x014)
#define OSTM0TT  (RZA1_OST_BASE + 0x018)
#define OSTM0CTL (RZA1_OST_BASE + 0x020)
#define OSTM1CMP (RZA1_OST_BASE + 0x400)
#define OSTM1CNT (RZA1_OST_BASE + 0x404)
#define OSTM1TE  (RZA1_OST_BASE + 0x410)
#define OSTM1TS  (RZA1_OST_BASE + 0x414)
#define OSTM1TT  (RZA1_OST_BASE + 0x418)
#define OSTM1CTL (RZA1_OST_BASE + 0x420)

/* Standby controller registers */
#define STBCR1 (RZA1_STBCR_BASE + 0x00)
#define STBCR2 (RZA1_STBCR_BASE + 0x04)
#define STBCR3 (RZA1_STBCR_BASE + 0x400)
#define STBCR4 (RZA1_STBCR_BASE + 0x404)
#define STBCR5 (RZA1_STBCR_BASE + 0x408)
#define STBCR6 (RZA1_STBCR_BASE + 0x40c)
#define STBCR7 (RZA1_STBCR_BASE + 0x410)
#define STBCR8 (RZA1_STBCR_BASE + 0x414)
#define STBCR9 (RZA1_STBCR_BASE + 0x418)
#define STBCR10 (RZA1_STBCR_BASE + 0x41c)
#define STBCR11 (RZA1_STBCR_BASE + 0x420)
#define STBCR12 (RZA1_STBCR_BASE + 0x424)

/* Port Control register */
#define JPPR0   (RZA1_PCTR_BASE + 0x000)
#define JPMC0   (RZA1_PCTR_BASE + 0x040)
#define JPMCSR0 (RZA1_PCTR_BASE + 0x090)
#define JPIBC0  (RZA1_PCTR_BASE + 0x400)
#define PPR0    (RZA1_PCTR_BASE + 0x200)
#define PMC0    (RZA1_PCTR_BASE + 0x400)
#define PMCSR0  (RZA1_PCTR_BASE + 0x900)
#define PIBC0   (RZA1_PCTR_BASE + 0x4000)
#define PIBC1   (RZA1_PCTR_BASE + 0x4004)
#define PBDC1   (RZA1_PCTR_BASE + 0x4104)
#define PM1     (RZA1_PCTR_BASE + 0x304)
#define PMC1    (RZA1_PCTR_BASE + 0x404)
#define PFC1    (RZA1_PCTR_BASE + 0x504)
#define PFCE1   (RZA1_PCTR_BASE + 0x604)
#define PFCAE1  (RZA1_PCTR_BASE + 0xa04)
#define PIPC1   (RZA1_PCTR_BASE + 0x4204)
#define PM2     (RZA1_PCTR_BASE + 0x308)
#define PMC2    (RZA1_PCTR_BASE + 0x408)
#define PFC2    (RZA1_PCTR_BASE + 0x508)
#define PFCE2   (RZA1_PCTR_BASE + 0x608)
#define PFCAE2  (RZA1_PCTR_BASE + 0xa08)
#define PIPC2   (RZA1_PCTR_BASE + 0x4208)
#define PM3     (RZA1_PCTR_BASE + 0x30c)
#define PMC3    (RZA1_PCTR_BASE + 0x40c)
#define PFC3    (RZA1_PCTR_BASE + 0x50c)
#define PFCE3   (RZA1_PCTR_BASE + 0x60c)
#define PFCAE3  (RZA1_PCTR_BASE + 0xa0c)
#define PIPC3   (RZA1_PCTR_BASE + 0x420c)
#define PM5     (RZA1_PCTR_BASE + 0x314)
#define PMC5    (RZA1_PCTR_BASE + 0x414)
#define PFC5    (RZA1_PCTR_BASE + 0x514)
#define PFCE5   (RZA1_PCTR_BASE + 0x614)
#define PFCAE5  (RZA1_PCTR_BASE + 0xa14)
#define PM6 (RZA1_PCTR_BASE + 0x318)
#define PMC6 (RZA1_PCTR_BASE + 0x418)
#define PFC6 (RZA1_PCTR_BASE + 0x518)
#define PFCE6 (RZA1_PCTR_BASE + 0x618)
#define PFCAE6 (RZA1_PCTR_BASE + 0xa18)
#define PIPC6   (RZA1_PCTR_BASE + 0x4218)
#define PM7     (RZA1_PCTR_BASE + 0x31c)
#define PMC7    (RZA1_PCTR_BASE + 0x41c)
#define PFC7    (RZA1_PCTR_BASE + 0x51c)
#define PFCE7   (RZA1_PCTR_BASE + 0x61c)
#define PFCAE7  (RZA1_PCTR_BASE + 0xa1c)
#define PIPC7 (RZA1_PCTR_BASE + 0x421c)
#define PM8     (RZA1_PCTR_BASE + 0x320)
#define PMC8    (RZA1_PCTR_BASE + 0x420)
#define PFC8    (RZA1_PCTR_BASE + 0x520)
#define PFCE8   (RZA1_PCTR_BASE + 0x620)
#define PFCAE8  (RZA1_PCTR_BASE + 0xa20)
#define PIPC8   (RZA1_PCTR_BASE + 0x4220)
#define PM9     (RZA1_PCTR_BASE + 0x324)
#define PMC9    (RZA1_PCTR_BASE + 0x424)
#define PFC9    (RZA1_PCTR_BASE + 0x524)
#define PFCE9   (RZA1_PCTR_BASE + 0x624)
#define PFCAE9  (RZA1_PCTR_BASE + 0xa24)
#define PIPC9   (RZA1_PCTR_BASE + 0x4224)

/* Bus State Contoller registers */
#define CMNCR  (RZA1_BCR_BASE + 0x00)
#define CS0BCR (RZA1_BCR_BASE + 0x04)
#define CS0WCR (RZA1_BCR_BASE + 0x28)
#define CS1BCR (RZA1_BCR_BASE + 0x08)
#define CS1WCR (RZA1_BCR_BASE + 0x2c)
#define CS2BCR (RZA1_BCR_BASE + 0x0c)
#define CS2WCR (RZA1_BCR_BASE + 0x30)
#define CS3BCR (RZA1_BCR_BASE + 0x10)
#define CS3WCR (RZA1_BCR_BASE + 0x34)

/* SDRAM controller registers */
#define SDCR   (RZA1_SDRAM_BASE + 0x4c)
#define RTCOR  (RZA1_SDRAM_BASE + 0x58)
#define RTCSR  (RZA1_SDRAM_BASE + 0x50)

#endif				/* _RZA1_REGS_H */
