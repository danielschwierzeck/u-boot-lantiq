/******************************************************************************
     Copyright (c) 2006, Infineon Technologies.  All rights reserved.

                               No Warranty
   Because the program is licensed free of charge, there is no warranty for
   the program, to the extent permitted by applicable law.  Except when
   otherwise stated in writing the copyright holders and/or other parties
   provide the program "as is" without warranty of any kind, either
   expressed or implied, including, but not limited to, the implied
   warranties of merchantability and fitness for a particular purpose. The
   entire risk as to the quality and performance of the program is with
   you.  should the program prove defective, you assume the cost of all
   necessary servicing, repair or correction.

   In no event unless required by applicable law or agreed to in writing
   will any copyright holder, or any other party who may modify and/or
   redistribute the program as permitted above, be liable to you for
   damages, including any general, special, incidental or consequential
   damages arising out of the use or inability to use the program
   (including but not limited to loss of data or data being rendered
   inaccurate or losses sustained by you or third parties or a failure of
   the program to operate with any other programs), even if such holder or
   other party has been advised of the possibility of such damages.
 ******************************************************************************
   Module      : ifx_tantos.c
   Date        : 2006-08-15
   Description : Switch driver for TANTOS 
   Remarks: jeanson.hung@infineon.com

 *****************************************************************************/
#ifndef _IFX_TANTOS_H_
#define _IFX_TANTOS_H_

void tantos_reset(void); 
int tantos_chk_bndctl(int port, int txrx);
int tantos_get_bndwth(int port, int txrx);
void tantos_set_bndwth(int port, int txrx, int limit);
int tantos_get_bndwth_mode(int port);
int tantos_set_bndwth_mode(int port, int mode);
int tantos_get_egress_by_wfq(int port, int qno);
int tantos_set_egress_by_wfq(int port, int qno, int bndwth);
int tantos_get_egress_by_sq(int port, int qno);
int tantos_set_egress_by_sq(int port, int qno, int bndwth);
int tantos_get_tcpudp_filter(int filterno, int *port, int *queueno);
void tantos_set_tcpudp_filter(int filterno, int port, int queueno);
int tantos_get_tcpudp_filter_range(int filterno);
void tantos_set_tcpudp_filter_range(int filterno, int range);
void tantos_set_tcpudp_filter_mode(int filterno, int mode);
int tantos_get_qos_control(void);
void tantos_set_qos_control(int qos);
int tantos_get_queue_weight(int qno);
void tantos_set_queue_weight(int qno, int weight);
int tantos_getq(int port);
void tantos_setq(int port, int qno);
void tantos_dis_fc(int port);
void tantos_ena_fc(int port);
int tantos_get_igmp(void);
void tantos_set_igmp(int bit);
int tantos_get_igmpv3(void);
void tantos_set_igmpv3(int bit);
int tantos_get_igmp_proxy(void);
void tantos_set_igmp_proxy(int bit);

int tantos_get_additional_snoop_ctr(void);
void tantos_set_additional_snoop_ctr(int bit);

int tantos_get_igmp_table(unsigned int *portmap, unsigned int *gidh, unsigned int *gidl);
int tantos_set_igmp_table(unsigned int port, unsigned int gid, int valid);

int tantos_get_igmp_sip(unsigned int port, unsigned int gid, unsigned int *siph, unsigned int *sipl);
int tantos_set_igmp_sip(unsigned int port, unsigned int gid, int siph, int sipl, int valid);

void tantos_set_ppprmvl_status(int enable, int sid);
int tantos_get_ppprmvl_status(int *sid);



int tantos_get_vlanmode(void);
void tantos_set_vlanmode(int bit);
void tantos_set_mac_priority(char *mac, int addmac, int pri);
unsigned long long tantos_get_RXCNT(int port);
unsigned long long tantos_get_TXCNT(int port);
unsigned long long tantos_get_COLCNT(int port);
unsigned long long tantos_get_ERRCNT(int port);
int tantos_get_portsts(int port, int status); 
int tantos_get_cpu_port(void);
int tantos_set_cpu_port(int port);
int tantos_disable_cpu_port(void);

unsigned long tantos_get_rmon_by_off(int port, int off);
unsigned long tantos_get_rmon(int port, int off); 

void tantos_set_diffserv(int pq, int qno);
int tantos_get_diffserv(int pq);

int tantos_vlan_init(void);
int tantos_vlan_add(int port_base, int port, int fid);
int tantos_vlan_del(int port_base, int port);


#define IFX_TANTOS_MAX_PORT	7
#define IFX_TANTOS_MAX_RMON	0x28
#define IFX_TANTOS_PROD_CODE 0x2599

#define IFX_TANTOS_READRMON		0x1
#define IFX_TANTOS_CLRRMON		0x2
#define IFX_TANTOS_CLRRMON_ALL	0x3

/* TCP/UDP control */
#define IFX_TANTOS_TCPUDP_MAX	0x8	/* max TCP/UDP filter number */
/* DiffServ */
#define IFX_TANTOS_MAX_IPTOS	0x40	/* 6 bits, 2^7 - 1 */
/* VLAN */
#define IFX_TANTOS_MAX_VLAN_NUM	15

/* registers */
/* for Port 0 */
#define TANTOS_REG_P0STS	0x00
#define TANTOS_REG_P0BCTL	0x01
#define TANTOS_REG_P0ECTL	0x02
#define TANTOS_REG_P0PBVM	0x03
#define TANTOS_REG_P0DVID	0x04
#define TANTOS_REG_P0ECSQ3	0x05
#define TANTOS_REG_P0ECSQ2	0x06
#define TANTOS_REG_P0ECSQ1	0x07
#define TANTOS_REG_P0ECSQ0	0x08
#define TANTOS_REG_P0ECWQ3	0x09
#define TANTOS_REG_P0ECWQ2	0x0A
#define TANTOS_REG_P0ECWQ1	0x0B
#define TANTOS_REG_P0ECWQ0	0x0C
#define TANTOS_REG_P0ICR	0x0D

/* for Port 1 */
#define TANTOS_REG_P1STS	0x20
#define TANTOS_REG_P1BCTL	0x21
#define TANTOS_REG_P1ECTL	0x22
#define TANTOS_REG_P1PBVM	0x23
#define TANTOS_REG_P1DVID	0x24
#define TANTOS_REG_P1ECSQ3	0x25
#define TANTOS_REG_P1ECSQ2	0x26
#define TANTOS_REG_P1ECSQ1	0x27
#define TANTOS_REG_P1ECSQ0	0x28
#define TANTOS_REG_P1ECWQ3	0x29
#define TANTOS_REG_P1ECWQ2	0x2A
#define TANTOS_REG_P1ECWQ1	0x2B
#define TANTOS_REG_P1ECWQ0	0x2C
#define TANTOS_REG_P1ICR	0x2D

/* for Port 2 */
#define TANTOS_REG_P2STS	0x40
#define TANTOS_REG_P2BCTL	0x41
#define TANTOS_REG_P2ECTL	0x42
#define TANTOS_REG_P2PBVM	0x43
#define TANTOS_REG_P2DVID	0x44
#define TANTOS_REG_P2ECSQ3	0x45
#define TANTOS_REG_P2ECSQ2	0x46
#define TANTOS_REG_P2ECSQ1	0x47
#define TANTOS_REG_P2ECSQ0	0x48
#define TANTOS_REG_P2ECWQ3	0x49
#define TANTOS_REG_P2ECWQ2	0x4A
#define TANTOS_REG_P2ECWQ1	0x4B
#define TANTOS_REG_P2ECWQ0	0x4C
#define TANTOS_REG_P2ICR	0x4D

/* for Port 3 */
#define TANTOS_REG_P3STS	0x60
#define TANTOS_REG_P3BCTL	0x61
#define TANTOS_REG_P3ECTL	0x62
#define TANTOS_REG_P3PBVM	0x63
#define TANTOS_REG_P3DVID	0x64
#define TANTOS_REG_P3ECSQ3	0x65
#define TANTOS_REG_P3ECSQ2	0x66
#define TANTOS_REG_P3ECSQ1	0x67
#define TANTOS_REG_P3ECSQ0	0x68
#define TANTOS_REG_P3ECWQ3	0x69
#define TANTOS_REG_P3ECWQ2	0x6A
#define TANTOS_REG_P3ECWQ1	0x6B
#define TANTOS_REG_P3ECWQ0	0x6C
#define TANTOS_REG_P3ICR	0x6D

/* for port 4 */
#define TANTOS_REG_P4STS	0x80
#define TANTOS_REG_P4BCTL	0x81
#define TANTOS_REG_P4ECTL	0x82
#define TANTOS_REG_P4PBVM	0x83
#define TANTOS_REG_P4DVID	0x84
#define TANTOS_REG_P4ECSQ3	0x85
#define TANTOS_REG_P4ECSQ2	0x86
#define TANTOS_REG_P4ECSQ1	0x87
#define TANTOS_REG_P4ECSQ0	0x88
#define TANTOS_REG_P4ECWQ3	0x89
#define TANTOS_REG_P4ECWQ2	0x8A
#define TANTOS_REG_P4ECWQ1	0x8B
#define TANTOS_REG_P4ECWQ0	0x8C
#define TANTOS_REG_P4ICR	0x8D

/* for port 5 */
#define TANTOS_REG_P5STS	0xA0
#define TANTOS_REG_P5BCTL	0xA1
#define TANTOS_REG_P5ECTL	0xA2
#define TANTOS_REG_P5PBVM	0xA3
#define TANTOS_REG_P5DVID	0xA4
#define TANTOS_REG_P5ECSQ3	0xA5
#define TANTOS_REG_P5ECSQ2	0xA6
#define TANTOS_REG_P5ECSQ1	0xA7
#define TANTOS_REG_P5ECSQ0	0xA8
#define TANTOS_REG_P5ECWQ3	0xA9
#define TANTOS_REG_P5ECWQ2	0xAA
#define TANTOS_REG_P5ECWQ1	0xAB
#define TANTOS_REG_P5ECWQ0	0xAC
#define TANTOS_REG_P5ICR	0xAD

/* for port 6 */
#define TANTOS_REG_P6STS	0xC0
#define TANTOS_REG_P6BCTL	0xC1
#define TANTOS_REG_P6ECTL	0xC2
#define TANTOS_REG_P6PBVM	0xC3
#define TANTOS_REG_P6DVID	0xC4
#define TANTOS_REG_P6ECSQ3	0xC5
#define TANTOS_REG_P6ECSQ2	0xC6
#define TANTOS_REG_P6ECSQ1	0xC7
#define TANTOS_REG_P6ECSQ0	0xC8
#define TANTOS_REG_P6ECWQ3	0xC9
#define TANTOS_REG_P6ECWQ2	0xCA
#define TANTOS_REG_P6ECWQ1	0xCB
#define TANTOS_REG_P6ECWQ0	0xCC
#define TANTOS_REG_P6ICR	0xCD

/* VLAN filters */
#define TANTOS_REG_VF0L		0x10
#define TANTOS_REG_VF0H		0x11
#define TANTOS_REG_VF1L		0x12
#define TANTOS_REG_VF1H		0x13
#define TANTOS_REG_VF2L		0x14
#define TANTOS_REG_VF2H		0x15
#define TANTOS_REG_VF3L		0x16
#define TANTOS_REG_VF3H		0x17
#define TANTOS_REG_VF4L		0x18
#define TANTOS_REG_VF4H		0x19
#define TANTOS_REG_VF5L		0x1A
#define TANTOS_REG_VF5H		0x1B
#define TANTOS_REG_VF6L		0x1C
#define TANTOS_REG_VF6H		0x1D
#define TANTOS_REG_VF7L		0x1E
#define TANTOS_REG_VF7H		0x1F
#define TANTOS_REG_VF8L		0x30
#define TANTOS_REG_VF8H		0x31
#define TANTOS_REG_VF9L		0x32
#define TANTOS_REG_VF9H		0x33
#define TANTOS_REG_VF10L	0x34
#define TANTOS_REG_VF10H	0x35
#define TANTOS_REG_VF11L	0x36
#define TANTOS_REG_VF11H	0x37
#define TANTOS_REG_VF12L	0x38
#define TANTOS_REG_VF12H	0x39
#define TANTOS_REG_VF13L	0x3A
#define TANTOS_REG_VF13H	0x3B
#define TANTOS_REG_VF14L	0x3C
#define TANTOS_REG_VF14H	0x3D
#define TANTOS_REG_VF15L	0x3E
#define TANTOS_REG_VF15H	0x3F

/* type filters */
#define TANTOS_REG_TF0		0x50
#define TANTOS_REG_TF1		0x51
#define TANTOS_REG_TF2		0x52
#define TANTOS_REG_TF3		0x53
#define TANTOS_REG_TF4		0x54
#define TANTOS_REG_TF5		0x55
#define TANTOS_REG_TF6		0x56
#define TANTOS_REG_TF7		0x57

/* diffserv mapping */
#define TANTOS_REG_DM0		0x58
#define TANTOS_REG_DM1		0x59
#define TANTOS_REG_DM2		0x5A
#define TANTOS_REG_DM3		0x5B
#define TANTOS_REG_DM4		0x5C
#define TANTOS_REG_DM5		0x5D
#define TANTOS_REG_DM6		0x5E
#define TANTOS_REG_DM7		0x5F

/* TCP/UDP filter */
#define TANTOS_REG_TUPF0	0x70
#define TANTOS_REG_TUPR0	0x71
#define TANTOS_REG_TUPF1	0x72
#define TANTOS_REG_TUPR1	0x73
#define TANTOS_REG_TUPF2	0x74
#define TANTOS_REG_TUPR2	0x75
#define TANTOS_REG_TUPF3	0x76
#define TANTOS_REG_TUPR3	0x77
#define TANTOS_REG_TUPF4	0x78
#define TANTOS_REG_TUPR4	0x79
#define TANTOS_REG_TUPF5	0x7A
#define TANTOS_REG_TUPR5	0x7B
#define TANTOS_REG_TUPF6	0x7C
#define TANTOS_REG_TUPR6	0x7D
#define TANTOS_REG_TUPF7	0x7E
#define TANTOS_REG_TUPR7	0x7F

/* protocol filter */
#define TANTOS_REG_PF0		0xB8
#define TANTOS_REG_PF1		0xB9
#define TANTOS_REG_PF2		0xBA
#define TANTOS_REG_PF3		0xBB

/* Phy initial control */
#define TANTOS_REG_PHYIC0	0xD0
#define TANTOS_REG_PHYIC1	0xD2
#define TANTOS_REG_PHYIC2	0xD4
#define TANTOS_REG_PHYIC3	0xD6

/* Phy initial data */
#define TANTOS_REG_PHYID0	0xD1
#define TANTOS_REG_PHYID1	0xD3
#define TANTOS_REG_PHYID2	0xD5
#define TANTOS_REG_PHYID3	0xD7

/* interrupt related */
#define TANTOS_REG_IE		0xD8
#define TANTOS_REG_IS		0xD9

/* type filter actions */
#define TANTOS_REG_TFA0		0xDA
#define TANTOS_REG_TFA1		0xDB

#define TANTOS_REG_PIOFGPM  0xDD

#define TANTOS_REG_SGC1     0xE0
#define TANTOS_REG_SGC2     0xE1
#define TANTOS_REG_CHM      0xE2
#define TANTOS_REG_MS       0xE3

/* GMII related */
#define TANTOS_REG_RGMIICR	0xF5

/* for IGMP */
#define TANTOS_REG_HIOR		0xF6

/* PPPoE Removal Session ID */
#define TANTOS_REG_PSIDR    0xF7

#define TANTOS_REG_CI0		0x100
#define TANTOS_REG_CI1		0x101
#define TANTOS_REG_GSHS		0x102
#define TANTOS_REG_ATC0		0x104
#define TANTOS_REG_ATC1		0x105
#define TANTOS_REG_ATC2		0x106
#define TANTOS_REG_ATC3		0x107
#define TANTOS_REG_ATC4		0x108
#define TANTOS_REG_ATC5		0x109
#define TANTOS_REG_ATS0		0x10A
#define TANTOS_REG_ATS1		0x10B
#define TANTOS_REG_ATS2		0x10C
#define TANTOS_REG_ATS3		0x10D
#define TANTOS_REG_ATS4		0x10E
#define TANTOS_REG_ATS5		0x10F
#define TANTOS_REG_IGMPTC0	0x110
#define TANTOS_REG_IGMPTC1	0x111
#define TANTOS_REG_IGMPTC2	0x112
#define TANTOS_REG_IGMPTC3	0x113
#define TANTOS_REG_IGMPTC4	0x114
#define TANTOS_REG_IGMPTC5	0x115
#define TANTOS_REG_IGMPTS0	0x116
#define TANTOS_REG_IGMPTS1	0x117
#define TANTOS_REG_IGMPTS2	0x118
#define TANTOS_REG_IGMPTS3	0x119
#define TANTOS_REG_IGMPTS4	0x11a

#define	TANTOS_REG_RMONCTL	0x11B
#define TANTOS_REG_RMONLOW	0x11C
#define TANTOS_REG_RMONHIGH	0x11D

#define TANTOS_REG_MIIAC    0x120
#define TANTOS_REG_MIIWD    0x121
#define TANTOS_REG_MIIRD    0x122

#define IFX_TANTOS_MAX_REG_NUM TANTOS_REG_MIIRD



/* Bit offsets */
#ifndef BIT_0
#define BIT_0		0x1
#endif
#ifndef BIT_1
#define BIT_1		0x2
#endif
#ifndef BIT_2
#define BIT_2		0x4
#endif
#ifndef BIT_3
#define BIT_3		0x8
#endif
#ifndef BIT_4
#define BIT_4		0x10
#endif
#ifndef BIT_5
#define BIT_5		0x20
#endif
#ifndef BIT_6
#define BIT_6		0x40
#endif
#ifndef BIT_7
#define BIT_7		0x80
#endif
#ifndef BIT_8
#define BIT_8		0x100
#endif
#ifndef BIT_9
#define BIT_9		0x200
#endif
#ifndef BIT_10
#define BIT_10		0x400
#endif
#ifndef BIT_11
#define BIT_11		0x800
#endif
#ifndef BIT_12
#define BIT_12		0x1000
#endif
#ifndef BIT_13
#define BIT_13		0x2000
#endif
#ifndef BIT_14
#define BIT_14		0x4000
#endif
#ifndef BIT_15
#define BIT_15		0x8000
#endif
#ifndef BIT_16
#define BIT_16		0x10000
#endif


#endif	/* _IFX_TANTOS_H_ */
