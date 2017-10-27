/*
 *  drivers/mtd/nand.c
 *
 *  Overview:
 *   This is the generic MTD driver for NAND flash devices. It should be
 *   capable of working with almost all NAND chips currently available.
 *   Basic support for AG-AND chips is provided.
 *
 *	Additional technical information is available on
 *	http://www.linux-mtd.infradead.org/doc/nand.html
 *
 *  Copyright (C) 2000 Steven J. Hill (sjhill@realitydiluted.com)
 *		  2002-2006 Thomas Gleixner (tglx@linutronix.de)
 *
 *  Credits:
 *	David Woodhouse for adding multichip support
 *
 *	Aleph One Ltd. and Toby Churchill Ltd. for supporting the
 *	rework for 2K page size chips
 *
 *  TODO:
 *	Enable cached programming for 2k page size chips
 *	Check, if mtd->ecctype should be set to MTD_ECC_HW
 *	if we have HW ecc support.
 *	The AG-AND chips have nice features for speed improvement,
 *	which are not supported yet. Read / program 4 pages in one go.
 *	BBT table is not serialized, has to be fixed
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 */

/* XXX U-BOOT XXX */
#if 0
#include <linux/module.h>
#include <linux/delay.h>
#include <linux/errno.h>
#include <linux/err.h>
#include <linux/sched.h>
#include <linux/slab.h>
#include <linux/types.h>
#include <linux/mtd/mtd.h>
#include <linux/mtd/nand.h>
#include <linux/mtd/nand_ecc.h>
#include <linux/mtd/compatmac.h>
#include <linux/interrupt.h>
#include <linux/bitops.h>
#include <linux/leds.h>
#include <asm/io.h>

#ifdef CONFIG_MTD_PARTITIONS
#include <linux/mtd/partitions.h>
#endif

#endif

#include <common.h>

#define ENOTSUPP	524	/* Operation is not supported */

#include <malloc.h>
#include <watchdog.h>
#include <linux/err.h>
#include <linux/mtd/compat.h>
#include <linux/mtd/mtd.h>
#include <linux/mtd/nand.h>
#include <linux/mtd/nand_ecc.h>
#include <linux/mtd/nand_bch.h>
#ifdef CONFIG_MTD_PARTITIONS
#include <linux/mtd/partitions.h>
#endif

#include <asm/io.h>
#include <asm/errno.h>

#ifdef CONFIG_JFFS2_NAND
#include <jffs2/jffs2.h>
#endif

/*
 * CONFIG_SYS_NAND_RESET_CNT is used as a timeout mechanism when resetting
 * a flash.  NAND flash is initialized prior to interrupts so standard timers
 * can't be used.  CONFIG_SYS_NAND_RESET_CNT should be set to a value
 * which is greater than (max NAND reset time / NAND status read time).
 * A conservative default of 200000 (500 us / 25 ns) is used as a default.
 */
#ifndef CONFIG_SYS_NAND_RESET_CNT
#define CONFIG_SYS_NAND_RESET_CNT 200000
#endif

/* Define default oob placement schemes for large and small page devices */
static struct nand_ecclayout nand_oob_8 = {
	.eccbytes = 3,
	.eccpos = {0, 1, 2},
	.oobfree = {
		{.offset = 3,
		 .length = 2},
		{.offset = 6,
		 .length = 2}}
};

static struct nand_ecclayout nand_oob_16 = {
	.eccbytes = 6,
	.eccpos = {0, 1, 2, 3, 6, 7},
	.oobfree = {
		{.offset = 8,
		 . length = 8}}
};

static struct nand_ecclayout nand_oob_64 = {
	.eccbytes = 24,
	.eccpos = {
		   40, 41, 42, 43, 44, 45, 46, 47,
		   48, 49, 50, 51, 52, 53, 54, 55,
		   56, 57, 58, 59, 60, 61, 62, 63},
	.oobfree = {
		{.offset = 2,
		 .length = 38}}
};

static struct nand_ecclayout nand_oob_128 = {
	.eccbytes = 48,
	.eccpos = {
		    80,  81,  82,  83,  84,  85,  86,  87,
		    88,  89,  90,  91,  92,  93,  94,  95,
		    96,  97,  98,  99, 100, 101, 102, 103,
		   104, 105, 106, 107, 108, 109, 110, 111,
		   112, 113, 114, 115, 116, 117, 118, 119,
		   120, 121, 122, 123, 124, 125, 126, 127},
	.oobfree = {
		{.offset = 2,
		 .length = 78}}
};
/*
static struct nand_ecclayout nand_oob_224 = {
        .eccbytes = 48,
	    .eccpos = {
		          176, 177, 178, 179, 180, 181, 182, 183,
				  184, 185, 186, 187, 188, 189, 190, 191,
				  192, 193, 194, 195, 196, 197, 198, 199,
				  200, 201, 202, 203, 204, 205, 206, 207,
				  208, 209, 210, 211, 212, 213, 214, 215,
				  216, 217, 218, 219, 220, 221, 222, 223,
		          },
		.oobfree = {
		        {.offset = 2,
			     .length = 174}}
};
*/


static struct nand_ecclayout nand_oob_224 = {
        .eccbytes = 96,
		.eccpos = {
                    128, 129, 130, 131, 132, 133, 134, 135,
					136, 137, 138, 139, 140, 141, 142, 143,
					144, 145, 146, 147, 148, 149, 150, 151,
					152, 153, 154, 155, 156, 157, 158, 159,
					160, 161, 162, 163, 164, 165, 166, 167,
					168, 169, 170, 171, 172, 173, 174, 175,
					176, 177, 178, 179, 180, 181, 182, 183,
					184, 185, 186, 187, 188, 189, 190, 191,
					192, 193, 194, 195, 196, 197, 198, 199,
					200, 201, 202, 203, 204, 205, 206, 207,
					208, 209, 210, 211, 212, 213, 214, 215,
					216, 217, 218, 219, 220, 221, 222, 223,
		           },
	     .oobfree = {
		         {.offset = 2,
		          .length = 126}}
};
													
				
static struct nand_ecclayout nand_oob_436 = {
	.eccbytes = 96,
	.eccpos = {
		    340, 341, 342, 343, 344, 345, 346, 347,
        348, 349, 350, 351, 352, 353, 354, 355,
        356, 357, 358, 359, 360, 361, 362, 363,
        364, 365, 366, 367, 368, 369, 370, 371,
        372, 373, 374, 375, 376, 377, 378, 379,
        380, 381, 382, 383, 384, 385, 386, 387,
        388, 389, 390, 391, 392, 393, 394, 395,
        396, 397, 398, 399, 400, 401, 402, 403,
        404, 405, 406, 407, 408, 409, 410, 411,
        412, 413, 414, 415, 416, 417, 418, 419,
        420, 421, 422, 423, 424, 425, 426, 427,
        428, 429, 430, 431, 432, 433, 434, 435,},
	.oobfree = {
		{.offset = 2,
		 .length = 338}}
};

static struct nand_ecclayout nand_oob_448 = {
	.eccbytes = 96,
	.eccpos = {
		    352, 353, 354, 355, 356, 357, 358, 359,
        360, 361, 362, 363, 364, 365, 366, 367,
        368, 369, 370, 371, 372, 373, 374, 375,
        376, 377, 378, 379, 380, 381, 382, 383,
        384, 385, 386, 387, 388, 389, 390, 391,
        392, 393, 394, 395, 396, 397, 398, 399,
        400, 401, 402, 403, 404, 405, 406, 407,
        408, 409, 410, 411, 412, 413, 414, 415,
        416, 417, 418, 419, 420, 421, 422, 423,
        424, 425, 426, 427, 428, 429, 430, 431,
        432, 433, 434, 435, 436, 437, 438, 439,
        440, 441, 442, 443, 444, 445, 446, 447,},
	.oobfree = {
		{.offset = 2,
		 .length = 350}}
};

static struct nand_ecclayout nand_oob_744 = {
	.eccbytes = 560,
	.eccpos = {
		212, 213, 214, 215, 216, 217, 218, 219,
		219, 220, 221, 222, 223, 224, 225, 226,
		226, 227, 228, 229, 230, 231, 232, 233,
		233, 234, 235, 236, 237, 238, 239, 240,
		240, 241, 242, 243, 244, 245, 246, 247,
		247, 248, 249, 250, 251, 252, 253,
		254, 255, 256, 257, 258, 259, 260, 261,
		261, 262, 263, 264, 265, 266, 267, 268,
		268, 269, 270, 271, 272, 273, 274, 275,
		275, 276, 277, 278, 279, 280, 281, 282,
		282, 283, 284, 285, 286, 287, 288, 289,
		289, 290, 291, 292, 293, 294, 295, 296,
		296, 297, 298, 299, 300, 301, 302, 303,
		303, 304, 305, 306, 307, 308, 309, 310,
		310, 311, 312, 313, 314, 315, 316, 317,
		317, 318, 319, 320, 321, 322, 323, 324,
		324, 325, 326, 327, 328, 329, 330, 331,
		331, 332, 333, 334, 335, 336, 337, 338,
		338, 339, 340, 341, 342, 343, 344, 345,
		345, 346, 347, 348, 349, 350, 351, 352,
		352, 353, 354, 355, 356, 357, 358, 359,
		359, 360, 361, 362, 363, 364, 365, 366,
		366, 367, 368, 369, 370, 371, 372, 373,
		373, 374, 375, 376, 377, 378, 379, 380,
		380, 381, 382, 383, 384, 385, 386, 387,
		387, 388, 389, 390, 391, 392, 393, 394,
		394, 395, 396, 397, 398, 399, 400, 401,
		401, 402, 403, 404, 405, 406, 407, 408,
		408, 409, 410, 411, 412, 413, 414, 415,
		415, 416, 417, 418, 419, 420, 421, 422,
		422, 423, 424, 425, 426, 427, 428, 429,
		429, 430, 431, 432, 433, 434, 435, 436,
		436, 437, 438, 439, 440, 441, 442, 443,
		443, 444, 445, 446, 447, 448, 449, 450,
		450, 451, 452, 453, 454, 455, 456, 457,
		457, 458, 459, 460, 461, 462, 463, 464,
		464, 465, 466, 467, 468, 469, 470, 471,
		471, 472, 473, 474, 475, 476, 477, 478,
		478, 479, 480, 481, 482, 483, 484, 485,
		485, 486, 487, 488, 489, 490, 491, 492,
		492, 493, 494, 495, 496, 497, 498, 499,
		499, 500, 501, 502, 503, 504, 505, 506,
		506, 507, 508, 509, 510, 511, 512, 513,
		513, 514, 515, 516, 517,
		518, 519, 520, 521, 522, 523, 524, 525,
		525, 526, 527, 528, 529, 530, 531, 532,
		532, 533, 534, 535, 536, 537, 538, 539,
		539, 540, 541, 542, 543, 544, 545, 546,
		546, 547, 548, 549, 550, 551, 552, 553,
		553, 554, 555, 556, 557, 558, 559, 560,
		560, 561, 562, 563, 564, 565, 566, 567,
		567, 568, 569, 570, 571, 572, 573, 574,
		574, 575, 576, 577, 578, 579, 580, 581,
		581, 582, 583, 584, 585, 586, 587, 588,
		588, 589, 590, 591, 592, 593, 594, 595,
		595, 596, 597, 598, 599, 600, 601, 602,
		602, 603, 604, 605, 606, 607, 608, 609,
		609, 610, 611, 612, 613, 614, 615, 616,
		616, 617, 618, 619, 620, 621, 622, 623,
		623, 624, 625, 626, 627, 628, 629, 630,
		630, 631, 632, 633, 634, 635, 636, 637,
		637, 638, 639, 640, 641, 642, 643, 644,
		644, 645, 646, 647, 648, 649, 650, 651,
		651, 652, 653, 654, 655, 656, 657, 658,
		658, 659, 660, 661, 662, 663, 664, 665,
		665, 666, 667, 668, 669, 670, 671, 672,
		672, 673, 674, 675, 676, 677, 678, 679,
		679, 680, 681, 682, 683, 684, 685, 686,
		686, 687, 688, 689, 690, 691, 692, 693,
		693, 694, 695, 696, 697, 698, 699, 700,
		700, 701, 702, 703, 704, 705, 706, 707,
		707, 708, 709, 710, 711, 712, 713, 714,
		714, 715, 716, 717, 718, 719, 720, 721,
		721, 722, 723, 724, 725, 726, 727, 728,
		728, 729, 730, 731, 732, 733, 734, 735,
		735, 736, 737, 738, 739, 740, 741, 742,
		742, 743, 744, 745, 746, 747, 748, 749,
		749, 750, 751, 752, 753, 754, 755, 756,
		756, 757, 758, 759, 760, 761, 762, 763,
		763, 764, 765, 766, 767, 768, 769, 770,
		770, 771, 772, 773},
	.oobfree = {
		{.offset = 2,
		 .length = 212}}
};

static struct nand_ecclayout nand_oob_1280 = {
    .eccbytes = 560,
    .eccpos = {
		720, 721, 722, 723, 724, 725, 726, 727,
		727, 728, 729, 730, 731, 732, 733, 734,
		734, 735, 736, 737, 738, 739, 740, 741,
		741, 742, 743, 744, 745, 746, 747, 748,
		748, 749, 750, 751, 752, 753, 754, 755,
		755, 756, 757, 758, 759, 760, 761, 762,
		762, 763, 764, 765, 766, 767, 768, 769,
		769, 770, 771, 772, 773, 774, 775, 776,
		776, 777, 778, 779, 780, 781, 782, 783,
		783, 784, 785, 786, 787, 788, 789, 790,
		790, 791, 792, 793, 794, 795, 796, 797,
		797, 798, 799, 800, 801, 802, 803, 804,
		804, 805, 806, 807, 808, 809, 810, 811,
		811, 812, 813, 814, 815, 816, 817, 818,
		818, 819, 820, 821, 822, 823, 824, 825,
		825, 826, 827, 828, 829, 830, 831, 832,
		832, 833, 834, 835, 836, 837, 838, 839,
		839, 840, 841, 842, 843, 844, 845, 846,
		846, 847, 848, 849, 850, 851, 852, 853,
		853, 854, 855, 856, 857, 858, 859, 860,
		860, 861, 862, 863, 864, 865, 866, 867,
		867, 868, 869, 870, 871, 872, 873, 874,
		874, 875, 876, 877, 878, 879, 880, 881,
		881, 882, 883, 884, 885, 886, 887, 888,
		888, 889, 890, 891, 892, 893, 894, 895,
		895, 896, 897, 898, 899, 900, 901, 902,
		902, 903, 904, 905, 906, 907, 908, 909,
		909, 910, 911, 912, 913, 914, 915, 916,
		916, 917, 918, 919, 920, 921, 922, 923,
		923, 924, 925, 926, 927, 928, 929, 930,
		930, 931, 932, 933, 934, 935, 936, 937,
		937, 938, 939, 940, 941, 942, 943, 944,
		944, 945, 946, 947, 948, 949, 950, 951,
		951, 952, 953, 954, 955, 956, 957, 958,
		958, 959, 960, 961, 962, 963, 964, 965,
		965, 966, 967, 968, 969, 970, 971, 972,
		972, 973, 974, 975, 976, 977, 978, 979,
		979, 980, 981, 982, 983, 984, 985, 986,
		986, 987, 988, 989, 990, 991, 992, 993,
		993, 994, 995, 996, 997, 998, 999, 1000,
		1000, 1001, 1002, 1003, 1004, 1005, 1006, 1007,
		1007, 1008, 1009, 1010, 1011, 1012, 1013, 1014,
		1014, 1015, 1016, 1017, 1018, 1019, 1020, 1021,
		1021, 1022, 1023, 1024, 1025, 1026, 1027, 1028,
		1028, 1029, 1030, 1031, 1032, 1033, 1034, 1035,
		1035, 1036, 1037, 1038, 1039, 1040, 1041, 1042,
		1042, 1043, 1044, 1045, 1046, 1047, 1048, 1049,
		1049, 1050, 1051, 1052, 1053, 1054, 1055, 1056,
		1056, 1057, 1058, 1059, 1060, 1061, 1062, 1063,
		1063, 1064, 1065, 1066, 1067, 1068, 1069, 1070,
		1070, 1071, 1072, 1073, 1074, 1075, 1076, 1077,
		1077, 1078, 1079, 1080, 1081, 1082, 1083, 1084,
		1084, 1085, 1086, 1087, 1088, 1089, 1090, 1091,
		1091, 1092, 1093, 1094, 1095, 1096, 1097, 1098,
		1098, 1099, 1100, 1101, 1102, 1103, 1104, 1105,
		1105, 1106, 1107, 1108, 1109, 1110, 1111, 1112,
		1112, 1113, 1114, 1115, 1116, 1117, 1118, 1119,
		1119, 1120, 1121, 1122, 1123, 1124, 1125, 1126,
		1126, 1127, 1128, 1129, 1130, 1131, 1132, 1133,
		1133, 1134, 1135, 1136, 1137, 1138, 1139, 1140,
		1140, 1141, 1142, 1143, 1144, 1145, 1146, 1147,
		1147, 1148, 1149, 1150, 1151, 1152, 1153, 1154,
		1154, 1155, 1156, 1157, 1158, 1159, 1160, 1161,
		1161, 1162, 1163, 1164, 1165, 1166, 1167, 1168,
		1168, 1169, 1170, 1171, 1172, 1173, 1174, 1175,
		1175, 1176, 1177, 1178, 1179, 1180, 1181, 1182,
		1182, 1183, 1184, 1185, 1186, 1187, 1188, 1189,
		1189, 1190, 1191, 1192, 1193, 1194, 1195, 1196,
		1196, 1197, 1198, 1199, 1200, 1201, 1202, 1203,
		1203, 1204, 1205, 1206, 1207, 1208, 1209, 1210,
		1210, 1211, 1212, 1213, 1214, 1215, 1216, 1217,
		1217, 1218, 1219, 1220, 1221, 1222, 1223, 1224,
		1224, 1225, 1226, 1227, 1228, 1229, 1230, 1231,
		1231, 1232, 1233, 1234, 1235, 1236, 1237, 1238,
		1238, 1239, 1240, 1241, 1242, 1243, 1244, 1245,
		1245, 1246, 1247, 1248, 1249, 1250, 1251, 1252,
		1252, 1253, 1254, 1255, 1256, 1257, 1258, 1259,
		1259, 1260, 1261, 1262, 1263, 1264, 1265, 1266,
		1266, 1267, 1268, 1269, 1270, 1271, 1272, 1273,
		1273, 1274, 1275, 1276, 1277, 1278, 1279},
    .oobfree = {
        {.offset = 2,
         .length = 718}}
};


static int nand_get_device(struct nand_chip *chip, struct mtd_info *mtd,
			   int new_state);

static int nand_do_write_oob(struct mtd_info *mtd, loff_t to,
			     struct mtd_oob_ops *ops);

static int nand_wait(struct mtd_info *mtd, struct nand_chip *this);

/*
 * For devices which display every fart in the system on a separate LED. Is
 * compiled away when LED support is disabled.
 */
/* XXX U-BOOT XXX */
#if 0
DEFINE_LED_TRIGGER(nand_led_trigger);
#endif

/**
 * nand_release_device - [GENERIC] release chip
 * @mtd:	MTD device structure
 *
 * Deselect, release chip lock and wake up anyone waiting on the device
 */
/* XXX U-BOOT XXX */
#if 0
static void nand_release_device(struct mtd_info *mtd)
{
	struct nand_chip *chip = mtd->priv;

	/* De-select the NAND device */
	chip->select_chip(mtd, -1);

	/* Release the controller and the chip */
	spin_lock(&chip->controller->lock);
	chip->controller->active = NULL;
	chip->state = FL_READY;
	wake_up(&chip->controller->wq);
	spin_unlock(&chip->controller->lock);
}
#else
static void nand_release_device (struct mtd_info *mtd)
{
	struct nand_chip *this = mtd->priv;
	this->select_chip(mtd, -1);	/* De-select the NAND device */
}
#endif

/**
 * nand_read_byte - [DEFAULT] read one byte from the chip
 * @mtd:	MTD device structure
 *
 * Default read function for 8bit buswith
 */
static uint8_t nand_read_byte(struct mtd_info *mtd)
{
	struct nand_chip *chip = mtd->priv;
	return readb(chip->IO_ADDR_R);
}

/**
 * nand_read_byte16 - [DEFAULT] read one byte endianess aware from the chip
 * @mtd:	MTD device structure
 *
 * Default read function for 16bit buswith with
 * endianess conversion
 */
static uint8_t nand_read_byte16(struct mtd_info *mtd)
{
	struct nand_chip *chip = mtd->priv;
	return (uint8_t) cpu_to_le16(readw(chip->IO_ADDR_R));
}

/**
 * nand_read_word - [DEFAULT] read one word from the chip
 * @mtd:	MTD device structure
 *
 * Default read function for 16bit buswith without
 * endianess conversion
 */
static u16 nand_read_word(struct mtd_info *mtd)
{
	struct nand_chip *chip = mtd->priv;
	return readw(chip->IO_ADDR_R);
}

/**
 * nand_select_chip - [DEFAULT] control CE line
 * @mtd:	MTD device structure
 * @chipnr:	chipnumber to select, -1 for deselect
 *
 * Default select function for 1 chip devices.
 */
static void nand_select_chip(struct mtd_info *mtd, int chipnr)
{
	struct nand_chip *chip = mtd->priv;

	switch (chipnr) {
	case -1:
		chip->cmd_ctrl(mtd, NAND_CMD_NONE, 0 | NAND_CTRL_CHANGE);
		break;
	case 0:
		break;

	default:
		BUG();
	}
}

/**
 * nand_write_buf - [DEFAULT] write buffer to chip
 * @mtd:	MTD device structure
 * @buf:	data buffer
 * @len:	number of bytes to write
 *
 * Default write function for 8bit buswith
 */
static void nand_write_buf(struct mtd_info *mtd, const uint8_t *buf, int len)
{
	int i;
	struct nand_chip *chip = mtd->priv;

	for (i = 0; i < len; i++)
		writeb(buf[i], chip->IO_ADDR_W);
}

/**
 * nand_read_buf - [DEFAULT] read chip data into buffer
 * @mtd:	MTD device structure
 * @buf:	buffer to store date
 * @len:	number of bytes to read
 *
 * Default read function for 8bit buswith
 */
static void nand_read_buf(struct mtd_info *mtd, uint8_t *buf, int len)
{
	int i;
	struct nand_chip *chip = mtd->priv;

	for (i = 0; i < len; i++)
		buf[i] = readb(chip->IO_ADDR_R);
}

/**
 * nand_verify_buf - [DEFAULT] Verify chip data against buffer
 * @mtd:	MTD device structure
 * @buf:	buffer containing the data to compare
 * @len:	number of bytes to compare
 *
 * Default verify function for 8bit buswith
 */
static int nand_verify_buf(struct mtd_info *mtd, const uint8_t *buf, int len)
{
	int i;
	struct nand_chip *chip = mtd->priv;

	for (i = 0; i < len; i++)
		if (buf[i] != readb(chip->IO_ADDR_R))
			return -EFAULT;
	return 0;
}

/**
 * nand_write_buf16 - [DEFAULT] write buffer to chip
 * @mtd:	MTD device structure
 * @buf:	data buffer
 * @len:	number of bytes to write
 *
 * Default write function for 16bit buswith
 */
static void nand_write_buf16(struct mtd_info *mtd, const uint8_t *buf, int len)
{
	int i;
	struct nand_chip *chip = mtd->priv;
	u16 *p = (u16 *) buf;
	len >>= 1;

	for (i = 0; i < len; i++)
		writew(p[i], chip->IO_ADDR_W);

}

/**
 * nand_read_buf16 - [DEFAULT] read chip data into buffer
 * @mtd:	MTD device structure
 * @buf:	buffer to store date
 * @len:	number of bytes to read
 *
 * Default read function for 16bit buswith
 */
static void nand_read_buf16(struct mtd_info *mtd, uint8_t *buf, int len)
{
	int i;
	struct nand_chip *chip = mtd->priv;
	u16 *p = (u16 *) buf;
	len >>= 1;

	for (i = 0; i < len; i++)
		p[i] = readw(chip->IO_ADDR_R);
}

/**
 * nand_verify_buf16 - [DEFAULT] Verify chip data against buffer
 * @mtd:	MTD device structure
 * @buf:	buffer containing the data to compare
 * @len:	number of bytes to compare
 *
 * Default verify function for 16bit buswith
 */
static int nand_verify_buf16(struct mtd_info *mtd, const uint8_t *buf, int len)
{
	int i;
	struct nand_chip *chip = mtd->priv;
	u16 *p = (u16 *) buf;
	len >>= 1;

	for (i = 0; i < len; i++)
		if (p[i] != readw(chip->IO_ADDR_R))
			return -EFAULT;

	return 0;
}

/**
 * nand_block_bad - [DEFAULT] Read bad block marker from the chip
 * @mtd:	MTD device structure
 * @ofs:	offset from device start
 * @getchip:	0, if the chip is already selected
 *
 * Check, if the block is bad.
 */
static int nand_block_bad(struct mtd_info *mtd, loff_t ofs, int getchip)
{
	int page, chipnr, res = 0;
	struct nand_chip *chip = mtd->priv;
	u16 bad;

	page = (int)(ofs >> chip->page_shift) & chip->pagemask;

	if (getchip) {
		chipnr = (int)(ofs >> chip->chip_shift);

		nand_get_device(chip, mtd, FL_READING);

		/* Select the NAND device */
		chip->select_chip(mtd, chipnr);
	}

	if (chip->options & NAND_BUSWIDTH_16) {
		chip->cmdfunc(mtd, NAND_CMD_READOOB, chip->badblockpos & 0xFE,
			      page);
		bad = cpu_to_le16(chip->read_word(mtd));
		if (chip->badblockpos & 0x1)
			bad >>= 8;
		if ((bad & 0xFF) != 0xff)
			res = 1;
	} else {
		chip->cmdfunc(mtd, NAND_CMD_READOOB, chip->badblockpos, page);
		if (chip->read_byte(mtd) != 0xff)
			res = 1;
	}

	if (getchip)
		nand_release_device(mtd);

	return res;
}

/**
 * nand_default_block_markbad - [DEFAULT] mark a block bad
 * @mtd:	MTD device structure
 * @ofs:	offset from device start
 *
 * This is the default implementation, which can be overridden by
 * a hardware specific driver.
*/
static int nand_default_block_markbad(struct mtd_info *mtd, loff_t ofs)
{
	struct nand_chip *chip = mtd->priv;
	uint8_t buf[2] = { 0, 0 };
	int block, ret;

	/* Get block number */
	block = (int)(ofs >> chip->bbt_erase_shift);
	if (chip->bbt)
		chip->bbt[block >> 2] |= 0x01 << ((block & 0x03) << 1);

	/* Do we have a flash based bad block table ? */
	if (chip->options & NAND_USE_FLASH_BBT)
		ret = nand_update_bbt(mtd, ofs);
	else {
		/* We write two bytes, so we dont have to mess with 16 bit
		 * access
		 */
		nand_get_device(chip, mtd, FL_WRITING);
		ofs += mtd->oobsize;
		chip->ops.len = chip->ops.ooblen = 2;
		chip->ops.datbuf = NULL;
		chip->ops.oobbuf = buf;
		chip->ops.ooboffs = chip->badblockpos & ~0x01;

		ret = nand_do_write_oob(mtd, ofs, &chip->ops);
		nand_release_device(mtd);
	}
	if (!ret)
		mtd->ecc_stats.badblocks++;

	return ret;
}

/**
 * nand_check_wp - [GENERIC] check if the chip is write protected
 * @mtd:	MTD device structure
 * Check, if the device is write protected
 *
 * The function expects, that the device is already selected
 */
static int nand_check_wp(struct mtd_info *mtd)
{
	struct nand_chip *chip = mtd->priv;
	/* Check the WP bit */
	chip->cmdfunc(mtd, NAND_CMD_STATUS, -1, -1);
	return (chip->read_byte(mtd) & NAND_STATUS_WP) ? 0 : 1;
}

/**
 * nand_block_checkbad - [GENERIC] Check if a block is marked bad
 * @mtd:	MTD device structure
 * @ofs:	offset from device start
 * @getchip:	0, if the chip is already selected
 * @allowbbt:	1, if its allowed to access the bbt area
 *
 * Check, if the block is bad. Either by reading the bad block table or
 * calling of the scan function.
 */
static int nand_block_checkbad(struct mtd_info *mtd, loff_t ofs, int getchip,
			       int allowbbt)
{
	struct nand_chip *chip = mtd->priv;

	if (!(chip->options & NAND_BBT_SCANNED)) {
		chip->options |= NAND_BBT_SCANNED;
		chip->scan_bbt(mtd);
	}

	if (!chip->bbt)
		return chip->block_bad(mtd, ofs, getchip);

	/* Return info from the table */
	return nand_isbad_bbt(mtd, ofs, allowbbt);
}

/*
 * Wait for the ready pin, after a command
 * The timeout is catched later.
 */
/* XXX U-BOOT XXX */
#if 0
void nand_wait_ready(struct mtd_info *mtd)
{
	struct nand_chip *chip = mtd->priv;
	unsigned long timeo = jiffies + 2;

	led_trigger_event(nand_led_trigger, LED_FULL);
	/* wait until command is processed or timeout occures */
	do {
		if (chip->dev_ready(mtd))
			break;
		touch_softlockup_watchdog();
	} while (time_before(jiffies, timeo));
	led_trigger_event(nand_led_trigger, LED_OFF);
}
EXPORT_SYMBOL_GPL(nand_wait_ready);
#else
void nand_wait_ready(struct mtd_info *mtd)
{
	struct nand_chip *chip = mtd->priv;
	u32 timeo = (CONFIG_SYS_HZ * 20) / 1000;

	reset_timer();

	/* wait until command is processed or timeout occures */
	while (get_timer(0) < timeo) {
		if (chip->dev_ready)
			if (chip->dev_ready(mtd))
				break;
	}
}
#endif

/**
 * nand_command - [DEFAULT] Send command to NAND device
 * @mtd:	MTD device structure
 * @command:	the command to be sent
 * @column:	the column address for this command, -1 if none
 * @page_addr:	the page address for this command, -1 if none
 *
 * Send command to NAND device. This function is used for small page
 * devices (256/512 Bytes per page)
 */
static void nand_command(struct mtd_info *mtd, unsigned int command,
			 int column, int page_addr)
{
	register struct nand_chip *chip = mtd->priv;
	int ctrl = NAND_CTRL_CLE | NAND_CTRL_CHANGE;
	uint32_t rst_sts_cnt = CONFIG_SYS_NAND_RESET_CNT;

	/*
	 * Write out the command to the device.
	 */
	if (command == NAND_CMD_SEQIN) {
		int readcmd;

		if (column >= mtd->writesize) {
			/* OOB area */
			column -= mtd->writesize;
			readcmd = NAND_CMD_READOOB;
		} else if (column < 256) {
			/* First 256 bytes --> READ0 */
			readcmd = NAND_CMD_READ0;
		} else {
			column -= 256;
			readcmd = NAND_CMD_READ1;
		}
		chip->cmd_ctrl(mtd, readcmd, ctrl);
		ctrl &= ~NAND_CTRL_CHANGE;
	}
	chip->cmd_ctrl(mtd, command, ctrl);

	/*
	 * Address cycle, when necessary
	 */
	ctrl = NAND_CTRL_ALE | NAND_CTRL_CHANGE;
	/* Serially input address */
	if (column != -1) {
		/* Adjust columns for 16 bit buswidth */
		if (chip->options & NAND_BUSWIDTH_16)
			column >>= 1;
		chip->cmd_ctrl(mtd, column, ctrl);
		ctrl &= ~NAND_CTRL_CHANGE;
	}
	if (page_addr != -1) {
		chip->cmd_ctrl(mtd, page_addr, ctrl);
		ctrl &= ~NAND_CTRL_CHANGE;
		chip->cmd_ctrl(mtd, page_addr >> 8, ctrl);
		/* One more address cycle for devices > 32MiB */
		if (chip->chipsize > (32 << 20))
			chip->cmd_ctrl(mtd, page_addr >> 16, ctrl);
	}
	chip->cmd_ctrl(mtd, NAND_CMD_NONE, NAND_NCE | NAND_CTRL_CHANGE);

	/*
	 * program and erase have their own busy handlers
	 * status and sequential in needs no delay
	 */
	switch (command) {

	case NAND_CMD_PAGEPROG:
	case NAND_CMD_ERASE1:
	case NAND_CMD_ERASE2:
	case NAND_CMD_SEQIN:
	case NAND_CMD_STATUS:
		return;

	case NAND_CMD_RESET:
		if (chip->dev_ready)
			break;
		udelay(chip->chip_delay);
		chip->cmd_ctrl(mtd, NAND_CMD_STATUS,
			       NAND_CTRL_CLE | NAND_CTRL_CHANGE);
		chip->cmd_ctrl(mtd,
			       NAND_CMD_NONE, NAND_NCE | NAND_CTRL_CHANGE);
		while (!(chip->read_byte(mtd) & NAND_STATUS_READY) &&
			(rst_sts_cnt--));
		return;

		/* This applies to read commands */
	default:
		/*
		 * If we don't have access to the busy pin, we apply the given
		 * command delay
		 */
		if (!chip->dev_ready) {
			udelay(chip->chip_delay);
			return;
		}
	}
	/* Apply this short delay always to ensure that we do wait tWB in
	 * any case on any machine. */
	ndelay(100);

	nand_wait_ready(mtd);
}

/**
 * nand_command_lp - [DEFAULT] Send command to NAND large page device
 * @mtd:	MTD device structure
 * @command:	the command to be sent
 * @column:	the column address for this command, -1 if none
 * @page_addr:	the page address for this command, -1 if none
 *
 * Send command to NAND device. This is the version for the new large page
 * devices We dont have the separate regions as we have in the small page
 * devices.  We must emulate NAND_CMD_READOOB to keep the code compatible.
 */
static void nand_command_lp(struct mtd_info *mtd, unsigned int command,
			    int column, int page_addr)
{
	register struct nand_chip *chip = mtd->priv;
	uint32_t rst_sts_cnt = CONFIG_SYS_NAND_RESET_CNT;

	/* Emulate NAND_CMD_READOOB */
	if (command == NAND_CMD_READOOB) {
		column += mtd->writesize;
		command = NAND_CMD_READ0;
	}

	/* Command latch cycle */
	chip->cmd_ctrl(mtd, command & 0xff,
		       NAND_NCE | NAND_CLE | NAND_CTRL_CHANGE);

	if (column != -1 || page_addr != -1) {
		int ctrl = NAND_CTRL_CHANGE | NAND_NCE | NAND_ALE;

		/* Serially input address */
		if (column != -1) {
			/* Adjust columns for 16 bit buswidth */
			if (chip->options & NAND_BUSWIDTH_16)
				column >>= 1;
			chip->cmd_ctrl(mtd, column, ctrl);
			ctrl &= ~NAND_CTRL_CHANGE;
			chip->cmd_ctrl(mtd, column >> 8, ctrl);
		}
		if (page_addr != -1) {
			chip->cmd_ctrl(mtd, page_addr, ctrl);
			chip->cmd_ctrl(mtd, page_addr >> 8,
				       NAND_NCE | NAND_ALE);
			/* One more address cycle for devices > 128MiB */
			if (chip->chipsize > (128 << 20))
				chip->cmd_ctrl(mtd, page_addr >> 16,
					       NAND_NCE | NAND_ALE);
		}
	}
	chip->cmd_ctrl(mtd, NAND_CMD_NONE, NAND_NCE | NAND_CTRL_CHANGE);

	/*
	 * program and erase have their own busy handlers
	 * status, sequential in, and deplete1 need no delay
	 */
	switch (command) {

	case NAND_CMD_CACHEDPROG:
	case NAND_CMD_PAGEPROG:
	case NAND_CMD_ERASE1:
	case NAND_CMD_ERASE2:
	case NAND_CMD_SEQIN:
	case NAND_CMD_RNDIN:
	case NAND_CMD_STATUS:
	case NAND_CMD_DEPLETE1:
		return;

		/*
		 * read error status commands require only a short delay
		 */
	case NAND_CMD_STATUS_ERROR:
	case NAND_CMD_STATUS_ERROR0:
	case NAND_CMD_STATUS_ERROR1:
	case NAND_CMD_STATUS_ERROR2:
	case NAND_CMD_STATUS_ERROR3:
		udelay(chip->chip_delay);
		return;

	case NAND_CMD_RESET:
		if (chip->dev_ready)
			break;
		udelay(chip->chip_delay);
		chip->cmd_ctrl(mtd, NAND_CMD_STATUS,
			       NAND_NCE | NAND_CLE | NAND_CTRL_CHANGE);
		chip->cmd_ctrl(mtd, NAND_CMD_NONE,
			       NAND_NCE | NAND_CTRL_CHANGE);
		while (!(chip->read_byte(mtd) & NAND_STATUS_READY) &&
			(rst_sts_cnt--));
		return;

	case NAND_CMD_RNDOUT:
		/* No ready / busy check necessary */
		chip->cmd_ctrl(mtd, NAND_CMD_RNDOUTSTART,
			       NAND_NCE | NAND_CLE | NAND_CTRL_CHANGE);
		chip->cmd_ctrl(mtd, NAND_CMD_NONE,
			       NAND_NCE | NAND_CTRL_CHANGE);
		return;

	case NAND_CMD_READ0:
		chip->cmd_ctrl(mtd, NAND_CMD_READSTART,
			       NAND_NCE | NAND_CLE | NAND_CTRL_CHANGE);
		chip->cmd_ctrl(mtd, NAND_CMD_NONE,
			       NAND_NCE | NAND_CTRL_CHANGE);

		/* This applies to read commands */
	default:
		/*
		 * If we don't have access to the busy pin, we apply the given
		 * command delay
		 */
		if (!chip->dev_ready) {
			udelay(chip->chip_delay);
			return;
		}
	}

	/* Apply this short delay always to ensure that we do wait tWB in
	 * any case on any machine. */
	ndelay(100);

	nand_wait_ready(mtd);
}

static int nand_get_device (struct nand_chip *this, struct mtd_info *mtd, int new_state)
{
	this->state = new_state;
	return 0;
}

static int nand_wait(struct mtd_info *mtd, struct nand_chip *this)
{
	unsigned long	timeo;
	int state = this->state;

	if (state == FL_ERASING)
		timeo = (CONFIG_SYS_HZ * 400) / 1000;
	else
		timeo = (CONFIG_SYS_HZ * 20) / 1000;

	if ((state == FL_ERASING) && (this->options & NAND_IS_AND))
		this->cmdfunc(mtd, NAND_CMD_STATUS_MULTI, -1, -1);
	else
		this->cmdfunc(mtd, NAND_CMD_STATUS, -1, -1);

	reset_timer();

	while (1) {
		if (get_timer(0) > timeo) {
			printf("Timeout!");
			return 0x01;
		}

		if (this->dev_ready) {
			if (this->dev_ready(mtd))
				break;
		} else {
			if (this->read_byte(mtd) & NAND_STATUS_READY)
				break;
		}
	}
#ifdef PPCHAMELON_NAND_TIMER_HACK
	reset_timer();
	while (get_timer(0) < 10);
#endif /*  PPCHAMELON_NAND_TIMER_HACK */

	return this->read_byte(mtd);
}

/**
 * nand_read_page_raw - [Intern] read raw page data without ecc
 * @mtd:	mtd info structure
 * @chip:	nand chip info structure
 * @buf:	buffer to store read data
 * @page:	page number to read
 *
 * Not for syndrome calculating ecc controllers, which use a special oob layout
 */
static int nand_read_page_raw(struct mtd_info *mtd, struct nand_chip *chip,
			      uint8_t *buf, int page)
{
	chip->read_buf(mtd, buf, mtd->writesize);
	chip->read_buf(mtd, chip->oob_poi, mtd->oobsize);
	return 0;
}

/**
 * nand_read_page_raw_syndrome - [Intern] read raw page data without ecc
 * @mtd:	mtd info structure
 * @chip:	nand chip info structure
 * @buf:	buffer to store read data
 * @page:	page number to read
 *
 * We need a special oob layout and handling even when OOB isn't used.
 */
static int nand_read_page_raw_syndrome(struct mtd_info *mtd, struct nand_chip *chip,
			      uint8_t *buf, int page)
{
	int eccsize = chip->ecc.size;
	int eccbytes = chip->ecc.bytes;
	uint8_t *oob = chip->oob_poi;
	int steps, size;

	for (steps = chip->ecc.steps; steps > 0; steps--) {
		chip->read_buf(mtd, buf, eccsize);
		buf += eccsize;

		if (chip->ecc.prepad) {
			chip->read_buf(mtd, oob, chip->ecc.prepad);
			oob += chip->ecc.prepad;
		}

		chip->read_buf(mtd, oob, eccbytes);
		oob += eccbytes;

		if (chip->ecc.postpad) {
			chip->read_buf(mtd, oob, chip->ecc.postpad);
			oob += chip->ecc.postpad;
		}
	}

	size = mtd->oobsize - (oob - chip->oob_poi);
	if (size)
		chip->read_buf(mtd, oob, size);

	return 0;
}

/**
 * nand_read_page_swecc - [REPLACABLE] software ecc based page read function
 * @mtd:	mtd info structure
 * @chip:	nand chip info structure
 * @buf:	buffer to store read data
 * @page:	page number to read
 */
static int nand_read_page_swecc(struct mtd_info *mtd, struct nand_chip *chip,
				uint8_t *buf, int page)
{
	int i, eccsize = chip->ecc.size;
	int eccbytes = chip->ecc.bytes;
	int eccsteps = chip->ecc.steps;
	uint8_t *p = buf;
	uint8_t *ecc_calc = chip->buffers->ecccalc;
	uint8_t *ecc_code = chip->buffers->ecccode;
	uint32_t *eccpos = chip->ecc.layout->eccpos;

	chip->ecc.read_page_raw(mtd, chip, buf, page);

	for (i = 0; eccsteps; eccsteps--, i += eccbytes, p += eccsize)
		chip->ecc.calculate(mtd, p, &ecc_calc[i]);

	for (i = 0; i < chip->ecc.total; i++)
		ecc_code[i] = chip->oob_poi[eccpos[i]];

	eccsteps = chip->ecc.steps;
	p = buf;

	for (i = 0 ; eccsteps; eccsteps--, i += eccbytes, p += eccsize) {
		int stat;

		stat = chip->ecc.correct(mtd, p, &ecc_code[i], &ecc_calc[i]);
		if (stat < 0){
			mtd->ecc_stats.failed++;
			}
		else{
			mtd->ecc_stats.corrected += stat;
			}
	}
	return 0;
}

/**
 * nand_read_subpage - [REPLACABLE] software ecc based sub-page read function
 * @mtd:	mtd info structure
 * @chip:	nand chip info structure
 * @data_offs:	offset of requested data within the page
 * @readlen:	data length
 * @bufpoi:	buffer to store read data
 */
static int nand_read_subpage(struct mtd_info *mtd, struct nand_chip *chip, uint32_t data_offs, uint32_t readlen, uint8_t *bufpoi)
{
	int start_step, end_step, num_steps;
	uint32_t *eccpos = chip->ecc.layout->eccpos;
	uint8_t *p;
	int data_col_addr, i, gaps = 0;
	int datafrag_len, eccfrag_len, aligned_len, aligned_pos;
	int busw = (chip->options & NAND_BUSWIDTH_16) ? 2 : 1;

	/* Column address wihin the page aligned to ECC size (256bytes). */
	start_step = data_offs / chip->ecc.size;
	end_step = (data_offs + readlen - 1) / chip->ecc.size;
	num_steps = end_step - start_step + 1;

	/* Data size aligned to ECC ecc.size*/
	datafrag_len = num_steps * chip->ecc.size;
	eccfrag_len = num_steps * chip->ecc.bytes;

	data_col_addr = start_step * chip->ecc.size;
	/* If we read not a page aligned data */
	if (data_col_addr != 0)
		chip->cmdfunc(mtd, NAND_CMD_RNDOUT, data_col_addr, -1);

	p = bufpoi + data_col_addr;
	chip->read_buf(mtd, p, datafrag_len);

	/* Calculate  ECC */
	for (i = 0; i < eccfrag_len ; i += chip->ecc.bytes, p += chip->ecc.size)
		chip->ecc.calculate(mtd, p, &chip->buffers->ecccalc[i]);

	/* The performance is faster if to position offsets
	   according to ecc.pos. Let make sure here that
	   there are no gaps in ecc positions */
	for (i = 0; i < eccfrag_len - 1; i++) {
		if (eccpos[i + start_step * chip->ecc.bytes] + 1 !=
			eccpos[i + start_step * chip->ecc.bytes + 1]) {
			gaps = 1;
			break;
		}
	}
	if (gaps) {
		chip->cmdfunc(mtd, NAND_CMD_RNDOUT, mtd->writesize, -1);
		chip->read_buf(mtd, chip->oob_poi, mtd->oobsize);
	} else {
		/* send the command to read the particular ecc bytes */
		/* take care about buswidth alignment in read_buf */
		aligned_pos = eccpos[start_step * chip->ecc.bytes] & ~(busw - 1);
		aligned_len = eccfrag_len;
		if (eccpos[start_step * chip->ecc.bytes] & (busw - 1))
			aligned_len++;
		if (eccpos[(start_step + num_steps) * chip->ecc.bytes] & (busw - 1))
			aligned_len++;

		chip->cmdfunc(mtd, NAND_CMD_RNDOUT, mtd->writesize + aligned_pos, -1);
		chip->read_buf(mtd, &chip->oob_poi[aligned_pos], aligned_len);
	}

	for (i = 0; i < eccfrag_len; i++)
		chip->buffers->ecccode[i] = chip->oob_poi[eccpos[i + start_step * chip->ecc.bytes]];

	p = bufpoi + data_col_addr;
	for (i = 0; i < eccfrag_len ; i += chip->ecc.bytes, p += chip->ecc.size) {
		int stat;

		stat = chip->ecc.correct(mtd, p, &chip->buffers->ecccode[i], &chip->buffers->ecccalc[i]);
		if (stat == -1)
			mtd->ecc_stats.failed++;
		else
			mtd->ecc_stats.corrected += stat;
	}
	return 0;
}

/**
 * nand_read_page_hwecc - [REPLACABLE] hardware ecc based page read function
 * @mtd:	mtd info structure
 * @chip:	nand chip info structure
 * @buf:	buffer to store read data
 * @page:	page number to read
 *
 * Not for syndrome calculating ecc controllers which need a special oob layout
 */
static int nand_read_page_hwecc(struct mtd_info *mtd, struct nand_chip *chip,
				uint8_t *buf, int page)
{
	int i, eccsize = chip->ecc.size;
	int eccbytes = chip->ecc.bytes;
	int eccsteps = chip->ecc.steps;
	uint8_t *p = buf;
	uint8_t *ecc_calc = chip->buffers->ecccalc;
	uint8_t *ecc_code = chip->buffers->ecccode;
	uint32_t *eccpos = chip->ecc.layout->eccpos;

	for (i = 0; eccsteps; eccsteps--, i += eccbytes, p += eccsize) {
		chip->ecc.hwctl(mtd, NAND_ECC_READ);
		chip->read_buf(mtd, p, eccsize);
		chip->ecc.calculate(mtd, p, &ecc_calc[i]);
	}
	chip->read_buf(mtd, chip->oob_poi, mtd->oobsize);

	for (i = 0; i < chip->ecc.total; i++)
		ecc_code[i] = chip->oob_poi[eccpos[i]];

	eccsteps = chip->ecc.steps;
	p = buf;

	for (i = 0 ; eccsteps; eccsteps--, i += eccbytes, p += eccsize) {
		int stat;

		stat = chip->ecc.correct(mtd, p, &ecc_code[i], &ecc_calc[i]);
		if (stat < 0)
			mtd->ecc_stats.failed++;
		else
			mtd->ecc_stats.corrected += stat;
	}
	return 0;
}

/**
 * nand_read_page_hwecc_oob_first - [REPLACABLE] hw ecc, read oob first
 * @mtd:	mtd info structure
 * @chip:	nand chip info structure
 * @buf:	buffer to store read data
 * @page:	page number to read
 *
 * Hardware ECC for large page chips, require OOB to be read first.
 * For this ECC mode, the write_page method is re-used from ECC_HW.
 * These methods read/write ECC from the OOB area, unlike the
 * ECC_HW_SYNDROME support with multiple ECC steps, follows the
 * "infix ECC" scheme and reads/writes ECC from the data area, by
 * overwriting the NAND manufacturer bad block markings.
 */
static int nand_read_page_hwecc_oob_first(struct mtd_info *mtd,
	struct nand_chip *chip, uint8_t *buf, int page)
{
	int i, eccsize = chip->ecc.size;
	int eccbytes = chip->ecc.bytes;
	int eccsteps = chip->ecc.steps;
	uint8_t *p = buf;
	uint8_t *ecc_code = chip->buffers->ecccode;
	uint32_t *eccpos = chip->ecc.layout->eccpos;
	uint8_t *ecc_calc = chip->buffers->ecccalc;

	/* Read the OOB area first */
	chip->cmdfunc(mtd, NAND_CMD_READOOB, 0, page);
	chip->read_buf(mtd, chip->oob_poi, mtd->oobsize);
	chip->cmdfunc(mtd, NAND_CMD_READ0, 0, page);

	for (i = 0; i < chip->ecc.total; i++)
		ecc_code[i] = chip->oob_poi[eccpos[i]];

	for (i = 0; eccsteps; eccsteps--, i += eccbytes, p += eccsize) {
		int stat;

		chip->ecc.hwctl(mtd, NAND_ECC_READ);
		chip->read_buf(mtd, p, eccsize);
		chip->ecc.calculate(mtd, p, &ecc_calc[i]);

		stat = chip->ecc.correct(mtd, p, &ecc_code[i], NULL);
		if (stat < 0)
			mtd->ecc_stats.failed++;
		else
			mtd->ecc_stats.corrected += stat;
	}
	return 0;
}

/**
 * nand_read_page_syndrome - [REPLACABLE] hardware ecc syndrom based page read
 * @mtd:	mtd info structure
 * @chip:	nand chip info structure
 * @buf:	buffer to store read data
 * @page:	page number to read
 *
 * The hw generator calculates the error syndrome automatically. Therefor
 * we need a special oob layout and handling.
 */
static int nand_read_page_syndrome(struct mtd_info *mtd, struct nand_chip *chip,
				   uint8_t *buf, int page)
{
	int i, eccsize = chip->ecc.size;
	int eccbytes = chip->ecc.bytes;
	int eccsteps = chip->ecc.steps;
	uint8_t *p = buf;
	uint8_t *oob = chip->oob_poi;

	for (i = 0; eccsteps; eccsteps--, i += eccbytes, p += eccsize) {
		int stat;

		chip->ecc.hwctl(mtd, NAND_ECC_READ);
		chip->read_buf(mtd, p, eccsize);

		if (chip->ecc.prepad) {
			chip->read_buf(mtd, oob, chip->ecc.prepad);
			oob += chip->ecc.prepad;
		}

		chip->ecc.hwctl(mtd, NAND_ECC_READSYN);
		chip->read_buf(mtd, oob, eccbytes);
		stat = chip->ecc.correct(mtd, p, oob, NULL);

		if (stat < 0)
			mtd->ecc_stats.failed++;
		else
			mtd->ecc_stats.corrected += stat;

		oob += eccbytes;

		if (chip->ecc.postpad) {
			chip->read_buf(mtd, oob, chip->ecc.postpad);
			oob += chip->ecc.postpad;
		}
	}

	/* Calculate remaining oob bytes */
	i = mtd->oobsize - (oob - chip->oob_poi);
	if (i)
		chip->read_buf(mtd, oob, i);

	return 0;
}

/**
 * nand_transfer_oob - [Internal] Transfer oob to client buffer
 * @chip:	nand chip structure
 * @oob:	oob destination address
 * @ops:	oob ops structure
 * @len:	size of oob to transfer
 */
static uint8_t *nand_transfer_oob(struct nand_chip *chip, uint8_t *oob,
				  struct mtd_oob_ops *ops, size_t len)
{
	switch(ops->mode) {

	case MTD_OOB_PLACE:
	case MTD_OOB_RAW:
		memcpy(oob, chip->oob_poi + ops->ooboffs, len);
		return oob + len;

	case MTD_OOB_AUTO: {
		struct nand_oobfree *free = chip->ecc.layout->oobfree;
		uint32_t boffs = 0, roffs = ops->ooboffs;
		size_t bytes = 0;

		for(; free->length && len; free++, len -= bytes) {
			/* Read request not from offset 0 ? */
			if (unlikely(roffs)) {
				if (roffs >= free->length) {
					roffs -= free->length;
					continue;
				}
				boffs = free->offset + roffs;
				bytes = min_t(size_t, len,
					      (free->length - roffs));
				roffs = 0;
			} else {
				bytes = min_t(size_t, len, free->length);
				boffs = free->offset;
			}
			memcpy(oob, chip->oob_poi + boffs, bytes);
			oob += bytes;
		}
		return oob;
	}
	default:
		BUG();
	}
	return NULL;
}

/**
 * nand_do_read_ops - [Internal] Read data with ECC
 *
 * @mtd:	MTD device structure
 * @from:	offset to read from
 * @ops:	oob ops structure
 *
 * Internal function. Called with chip held.
 */
static int nand_do_read_ops(struct mtd_info *mtd, loff_t from,
			    struct mtd_oob_ops *ops)
{
	int chipnr, page, realpage, col, bytes, aligned;
	struct nand_chip *chip = mtd->priv;
	struct mtd_ecc_stats stats;
	int blkcheck = (1 << (chip->phys_erase_shift - chip->page_shift)) - 1;
	int sndcmd = 1;
	int ret = 0;
	uint32_t readlen = ops->len;
	uint32_t oobreadlen = ops->ooblen;
	uint8_t *bufpoi, *oob, *buf;

	stats = mtd->ecc_stats;

	chipnr = (int)(from >> chip->chip_shift);
	chip->select_chip(mtd, chipnr);

	realpage = (int)(from >> chip->page_shift);
	page = realpage & chip->pagemask;

	col = (int)(from & (mtd->writesize - 1));

	buf = ops->datbuf;
	oob = ops->oobbuf;

	while(1) {
		bytes = min(mtd->writesize - col, readlen);
		aligned = (bytes == mtd->writesize);

		/* Is the current page in the buffer ? */
		if (realpage != chip->pagebuf || oob) {
			bufpoi = aligned ? buf : chip->buffers->databuf;

			if (likely(sndcmd)) {
				chip->cmdfunc(mtd, NAND_CMD_READ0, 0x00, page);
				sndcmd = 0;
			}

			/* Now read the page into the buffer */
			if (unlikely(ops->mode == MTD_OOB_RAW))
				ret = chip->ecc.read_page_raw(mtd, chip,
						bufpoi, page);
			else if (!aligned && NAND_SUBPAGE_READ(chip) && !oob)
				ret = chip->ecc.read_subpage(mtd, chip, col, bytes, bufpoi);
			else
				ret = chip->ecc.read_page(mtd, chip, bufpoi,
						page);
			if (ret < 0)
				break;

			/* Transfer not aligned data */
			if (!aligned) {
				if (!NAND_SUBPAGE_READ(chip) && !oob)
					chip->pagebuf = realpage;
				memcpy(buf, chip->buffers->databuf + col, bytes);
			}

			buf += bytes;

			if (unlikely(oob)) {
				/* Raw mode does data:oob:data:oob */
				if (ops->mode != MTD_OOB_RAW) {
					int toread = min(oobreadlen,
						chip->ecc.layout->oobavail);
					if (toread) {
						oob = nand_transfer_oob(chip,
							oob, ops, toread);
						oobreadlen -= toread;
					}
				} else
					buf = nand_transfer_oob(chip,
						buf, ops, mtd->oobsize);
			}

			if (!(chip->options & NAND_NO_READRDY)) {
				/*
				 * Apply delay or wait for ready/busy pin. Do
				 * this before the AUTOINCR check, so no
				 * problems arise if a chip which does auto
				 * increment is marked as NOAUTOINCR by the
				 * board driver.
				 */
				if (!chip->dev_ready)
					udelay(chip->chip_delay);
				else
					nand_wait_ready(mtd);
			}
		} else {
			memcpy(buf, chip->buffers->databuf + col, bytes);
			buf += bytes;
		}

		readlen -= bytes;

		if (!readlen)
			break;

		/* For subsequent reads align to page boundary. */
		col = 0;
		/* Increment page address */
		realpage++;

		page = realpage & chip->pagemask;
		/* Check, if we cross a chip boundary */
		if (!page) {
			chipnr++;
			chip->select_chip(mtd, -1);
			chip->select_chip(mtd, chipnr);
		}

		/* Check, if the chip supports auto page increment
		 * or if we have hit a block boundary.
		 */
		if (!NAND_CANAUTOINCR(chip) || !(page & blkcheck))
			sndcmd = 1;
	}

	ops->retlen = ops->len - (size_t) readlen;
	if (oob)
		ops->oobretlen = ops->ooblen - oobreadlen;

	if (ret)
		return ret;

	if (mtd->ecc_stats.failed - stats.failed)
		return -EBADMSG;

	return  mtd->ecc_stats.corrected - stats.corrected ? -EUCLEAN : 0;
}

/**
 * nand_read - [MTD Interface] MTD compability function for nand_do_read_ecc
 * @mtd:	MTD device structure
 * @from:	offset to read from
 * @len:	number of bytes to read
 * @retlen:	pointer to variable to store the number of read bytes
 * @buf:	the databuffer to put data
 *
 * Get hold of the chip and call nand_do_read
 */
static int nand_read(struct mtd_info *mtd, loff_t from, u64 len,
		     u64 *retlen, uint8_t *buf)
{
	struct nand_chip *chip = mtd->priv;
	int ret;

	/* Do not allow reads past end of device */
	if ((from + len) > mtd->size)
		return -EINVAL;
	if (!len)
		return 0;

	nand_get_device(chip, mtd, FL_READING);

	chip->ops.len = len;
	chip->ops.datbuf = buf;
	chip->ops.oobbuf = NULL;

	ret = nand_do_read_ops(mtd, from, &chip->ops);

	*retlen = chip->ops.retlen;

	nand_release_device(mtd);

	return ret;
}

/**
 * nand_read_oob_std - [REPLACABLE] the most common OOB data read function
 * @mtd:	mtd info structure
 * @chip:	nand chip info structure
 * @page:	page number to read
 * @sndcmd:	flag whether to issue read command or not
 */
static int nand_read_oob_std(struct mtd_info *mtd, struct nand_chip *chip,
			     int page, int sndcmd)
{
	if (sndcmd) {
		chip->cmdfunc(mtd, NAND_CMD_READOOB, 0, page);
		sndcmd = 0;
	}
	chip->read_buf(mtd, chip->oob_poi, mtd->oobsize);
	return sndcmd;
}

/**
 * nand_read_oob_syndrome - [REPLACABLE] OOB data read function for HW ECC
 *			    with syndromes
 * @mtd:	mtd info structure
 * @chip:	nand chip info structure
 * @page:	page number to read
 * @sndcmd:	flag whether to issue read command or not
 */
static int nand_read_oob_syndrome(struct mtd_info *mtd, struct nand_chip *chip,
				  int page, int sndcmd)
{
	uint8_t *buf = chip->oob_poi;
	int length = mtd->oobsize;
	int chunk = chip->ecc.bytes + chip->ecc.prepad + chip->ecc.postpad;
	int eccsize = chip->ecc.size;
	uint8_t *bufpoi = buf;
	int i, toread, sndrnd = 0, pos;

	chip->cmdfunc(mtd, NAND_CMD_READ0, chip->ecc.size, page);
	for (i = 0; i < chip->ecc.steps; i++) {
		if (sndrnd) {
			pos = eccsize + i * (eccsize + chunk);
			if (mtd->writesize > 512)
				chip->cmdfunc(mtd, NAND_CMD_RNDOUT, pos, -1);
			else
				chip->cmdfunc(mtd, NAND_CMD_READ0, pos, page);
		} else
			sndrnd = 1;
		toread = min_t(int, length, chunk);
		chip->read_buf(mtd, bufpoi, toread);
		bufpoi += toread;
		length -= toread;
	}
	if (length > 0)
		chip->read_buf(mtd, bufpoi, length);

	return 1;
}

/**
 * nand_write_oob_std - [REPLACABLE] the most common OOB data write function
 * @mtd:	mtd info structure
 * @chip:	nand chip info structure
 * @page:	page number to write
 */
static int nand_write_oob_std(struct mtd_info *mtd, struct nand_chip *chip,
			      int page)
{
	int status = 0;
	const uint8_t *buf = chip->oob_poi;
	int length = mtd->oobsize;
	
	chip->cmdfunc(mtd, NAND_CMD_SEQIN, mtd->writesize, page);
	chip->write_buf(mtd, buf, length);
	
	/* Send command to program the OOB data */
	chip->cmdfunc(mtd, NAND_CMD_PAGEPROG, -1, -1);

	status = chip->waitfunc(mtd, chip);
	return status & NAND_STATUS_FAIL ? -EIO : 0;
}

/**
 * nand_write_oob_syndrome - [REPLACABLE] OOB data write function for HW ECC
 *			     with syndrome - only for large page flash !
 * @mtd:	mtd info structure
 * @chip:	nand chip info structure
 * @page:	page number to write
 */
static int nand_write_oob_syndrome(struct mtd_info *mtd,
				   struct nand_chip *chip, int page)
{
	int chunk = chip->ecc.bytes + chip->ecc.prepad + chip->ecc.postpad;
	int eccsize = chip->ecc.size, length = mtd->oobsize;
	int i, len, pos, status = 0, sndcmd = 0, steps = chip->ecc.steps;
	const uint8_t *bufpoi = chip->oob_poi;

	/*
	 * data-ecc-data-ecc ... ecc-oob
	 * or
	 * data-pad-ecc-pad-data-pad .... ecc-pad-oob
	 */
	if (!chip->ecc.prepad && !chip->ecc.postpad) {
		pos = steps * (eccsize + chunk);
		steps = 0;
	} else
		pos = eccsize;

	chip->cmdfunc(mtd, NAND_CMD_SEQIN, pos, page);
	for (i = 0; i < steps; i++) {
		if (sndcmd) {
			if (mtd->writesize <= 512) {
				uint32_t fill = 0xFFFFFFFF;

				len = eccsize;
				while (len > 0) {
					int num = min_t(int, len, 4);
					chip->write_buf(mtd, (uint8_t *)&fill,
							num);
					len -= num;
				}
			} else {
				pos = eccsize + i * (eccsize + chunk);
				chip->cmdfunc(mtd, NAND_CMD_RNDIN, pos, -1);
			}
		} else
			sndcmd = 1;
		len = min_t(int, length, chunk);
		chip->write_buf(mtd, bufpoi, len);
		bufpoi += len;
		length -= len;
	}
	if (length > 0)
		chip->write_buf(mtd, bufpoi, length);

	chip->cmdfunc(mtd, NAND_CMD_PAGEPROG, -1, -1);
	status = chip->waitfunc(mtd, chip);

	return status & NAND_STATUS_FAIL ? -EIO : 0;
}

/**
 * nand_do_read_oob - [Intern] NAND read out-of-band
 * @mtd:	MTD device structure
 * @from:	offset to read from
 * @ops:	oob operations description structure
 *
 * NAND read out-of-band data from the spare area
 */
static int nand_do_read_oob(struct mtd_info *mtd, loff_t from,
			    struct mtd_oob_ops *ops)
{
	int page, realpage, chipnr, sndcmd = 1;
	struct nand_chip *chip = mtd->priv;
	int blkcheck = (1 << (chip->phys_erase_shift - chip->page_shift)) - 1;
	int readlen = ops->ooblen;
	int len;
	uint8_t *buf = ops->oobbuf;

	MTDDEBUG (MTD_DEBUG_LEVEL3, "nand_read_oob: from = 0x%08Lx, len = %i\n",
	          (unsigned long long)from, readlen);

	if (ops->mode == MTD_OOB_AUTO)
		len = chip->ecc.layout->oobavail;
	else
		len = mtd->oobsize;

	if (unlikely(ops->ooboffs >= len)) {
		MTDDEBUG (MTD_DEBUG_LEVEL0, "nand_read_oob: "
		          "Attempt to start read outside oob\n");
		return -EINVAL;
	}

	/* Do not allow reads past end of device */
	if (unlikely(from >= mtd->size ||
		     ops->ooboffs + readlen > ((mtd->size >> chip->page_shift) -
					(from >> chip->page_shift)) * len)) {
		MTDDEBUG (MTD_DEBUG_LEVEL0, "nand_read_oob: "
		          "Attempt read beyond end of device\n");
		return -EINVAL;
	}

	chipnr = (int)(from >> chip->chip_shift);
	chip->select_chip(mtd, chipnr);

	/* Shift to get page */
	realpage = (int)(from >> chip->page_shift);
	page = realpage & chip->pagemask;

	while(1) {
		sndcmd = chip->ecc.read_oob(mtd, chip, page, sndcmd);

		len = min(len, readlen);
		buf = nand_transfer_oob(chip, buf, ops, len);

		if (!(chip->options & NAND_NO_READRDY)) {
			/*
			 * Apply delay or wait for ready/busy pin. Do this
			 * before the AUTOINCR check, so no problems arise if a
			 * chip which does auto increment is marked as
			 * NOAUTOINCR by the board driver.
			 */
			if (!chip->dev_ready)
				udelay(chip->chip_delay);
			else
				nand_wait_ready(mtd);
		}

		readlen -= len;
		if (!readlen)
			break;

		/* Increment page address */
		realpage++;

		page = realpage & chip->pagemask;
		/* Check, if we cross a chip boundary */
		if (!page) {
			chipnr++;
			chip->select_chip(mtd, -1);
			chip->select_chip(mtd, chipnr);
		}

		/* Check, if the chip supports auto page increment
		 * or if we have hit a block boundary.
		 */
		if (!NAND_CANAUTOINCR(chip) || !(page & blkcheck))
			sndcmd = 1;
	}

	ops->oobretlen = ops->ooblen;
	return 0;
}

/**
 * nand_read_oob - [MTD Interface] NAND read data and/or out-of-band
 * @mtd:	MTD device structure
 * @from:	offset to read from
 * @ops:	oob operation description structure
 *
 * NAND read data and/or out-of-band data
 */
static int nand_read_oob(struct mtd_info *mtd, loff_t from,
			 struct mtd_oob_ops *ops)
{
	struct nand_chip *chip = mtd->priv;
	int ret = -ENOTSUPP;

	ops->retlen = 0;

	/* Do not allow reads past end of device */
	if (ops->datbuf && (from + ops->len) > mtd->size) {
		MTDDEBUG (MTD_DEBUG_LEVEL0, "nand_read_oob: "
		          "Attempt read beyond end of device\n");
		return -EINVAL;
	}

	nand_get_device(chip, mtd, FL_READING);

	switch(ops->mode) {
	case MTD_OOB_PLACE:
	case MTD_OOB_AUTO:
	case MTD_OOB_RAW:
		break;

	default:
		goto out;
	}

	if (!ops->datbuf)
		ret = nand_do_read_oob(mtd, from, ops);
	else
		ret = nand_do_read_ops(mtd, from, ops);

 out:
	nand_release_device(mtd);
	return ret;
}


/**
 * nand_write_page_raw - [Intern] raw page write function
 * @mtd:	mtd info structure
 * @chip:	nand chip info structure
 * @buf:	data buffer
 *
 * Not for syndrome calculating ecc controllers, which use a special oob layout
 */
static void nand_write_page_raw(struct mtd_info *mtd, struct nand_chip *chip,
				const uint8_t *buf)
{
	chip->write_buf(mtd, buf, mtd->writesize);
	chip->write_buf(mtd, chip->oob_poi, mtd->oobsize);
}

/**
 * nand_write_page_raw_syndrome - [Intern] raw page write function
 * @mtd:	mtd info structure
 * @chip:	nand chip info structure
 * @buf:	data buffer
 *
 * We need a special oob layout and handling even when ECC isn't checked.
 */
static void nand_write_page_raw_syndrome(struct mtd_info *mtd, struct nand_chip *chip,
				const uint8_t *buf)
{
	int eccsize = chip->ecc.size;
	int eccbytes = chip->ecc.bytes;
	uint8_t *oob = chip->oob_poi;
	int steps, size;

	for (steps = chip->ecc.steps; steps > 0; steps--) {
		chip->write_buf(mtd, buf, eccsize);
		buf += eccsize;

		if (chip->ecc.prepad) {
			chip->write_buf(mtd, oob, chip->ecc.prepad);
			oob += chip->ecc.prepad;
		}

		chip->read_buf(mtd, oob, eccbytes);
		oob += eccbytes;

		if (chip->ecc.postpad) {
			chip->write_buf(mtd, oob, chip->ecc.postpad);
			oob += chip->ecc.postpad;
		}
	}

	size = mtd->oobsize - (oob - chip->oob_poi);
	if (size)
		chip->write_buf(mtd, oob, size);
}
/**
 * nand_write_page_swecc - [REPLACABLE] software ecc based page write function
 * @mtd:	mtd info structure
 * @chip:	nand chip info structure
 * @buf:	data buffer
 */
static void nand_write_page_swecc(struct mtd_info *mtd, struct nand_chip *chip,
				  const uint8_t *buf)
{
	int i, eccsize = chip->ecc.size;
	int eccbytes = chip->ecc.bytes;
	int eccsteps = chip->ecc.steps;
	uint8_t *ecc_calc = chip->buffers->ecccalc;
	const uint8_t *p = buf;
	uint32_t *eccpos = chip->ecc.layout->eccpos;

	/* Software ecc calculation */
	for (i = 0; eccsteps; eccsteps--, i += eccbytes, p += eccsize)
		chip->ecc.calculate(mtd, p, &ecc_calc[i]);

	for (i = 0; i < chip->ecc.total; i++)
		chip->oob_poi[eccpos[i]] = ecc_calc[i];

	chip->ecc.write_page_raw(mtd, chip, buf);
}

/**
 * nand_write_page_hwecc - [REPLACABLE] hardware ecc based page write function
 * @mtd:	mtd info structure
 * @chip:	nand chip info structure
 * @buf:	data buffer
 */
static void nand_write_page_hwecc(struct mtd_info *mtd, struct nand_chip *chip,
				  const uint8_t *buf)
{
	int i, eccsize = chip->ecc.size;
	int eccbytes = chip->ecc.bytes;
	int eccsteps = chip->ecc.steps;
	uint8_t *ecc_calc = chip->buffers->ecccalc;
	const uint8_t *p = buf;
	uint32_t *eccpos = chip->ecc.layout->eccpos;

	for (i = 0; eccsteps; eccsteps--, i += eccbytes, p += eccsize) {
		chip->ecc.hwctl(mtd, NAND_ECC_WRITE);
		chip->write_buf(mtd, p, eccsize);
		chip->ecc.calculate(mtd, p, &ecc_calc[i]);
	}

	for (i = 0; i < chip->ecc.total; i++)
		chip->oob_poi[eccpos[i]] = ecc_calc[i];

	chip->write_buf(mtd, chip->oob_poi, mtd->oobsize);
}

/**
 * nand_write_page_syndrome - [REPLACABLE] hardware ecc syndrom based page write
 * @mtd:	mtd info structure
 * @chip:	nand chip info structure
 * @buf:	data buffer
 *
 * The hw generator calculates the error syndrome automatically. Therefor
 * we need a special oob layout and handling.
 */
static void nand_write_page_syndrome(struct mtd_info *mtd,
				    struct nand_chip *chip, const uint8_t *buf)
{
	int i, eccsize = chip->ecc.size;
	int eccbytes = chip->ecc.bytes;
	int eccsteps = chip->ecc.steps;
	const uint8_t *p = buf;
	uint8_t *oob = chip->oob_poi;

	for (i = 0; eccsteps; eccsteps--, i += eccbytes, p += eccsize) {

		chip->ecc.hwctl(mtd, NAND_ECC_WRITE);
		chip->write_buf(mtd, p, eccsize);

		if (chip->ecc.prepad) {
			chip->write_buf(mtd, oob, chip->ecc.prepad);
			oob += chip->ecc.prepad;
		}

		chip->ecc.calculate(mtd, p, oob);
		chip->write_buf(mtd, oob, eccbytes);
		oob += eccbytes;

		if (chip->ecc.postpad) {
			chip->write_buf(mtd, oob, chip->ecc.postpad);
			oob += chip->ecc.postpad;
		}
	}

	/* Calculate remaining oob bytes */
	i = mtd->oobsize - (oob - chip->oob_poi);
	if (i)
		chip->write_buf(mtd, oob, i);
}

/**
 * nand_write_page - [REPLACEABLE] write one page
 * @mtd:	MTD device structure
 * @chip:	NAND chip descriptor
 * @buf:	the data to write
 * @page:	page number to write
 * @cached:	cached programming
 * @raw:	use _raw version of write_page
 */
static int nand_write_page(struct mtd_info *mtd, struct nand_chip *chip,
			   const uint8_t *buf, int page, int cached, int raw)
{
	int status;

	chip->cmdfunc(mtd, NAND_CMD_SEQIN, 0x00, page);

	if (unlikely(raw))
		chip->ecc.write_page_raw(mtd, chip, buf);
	else
		chip->ecc.write_page(mtd, chip, buf);

	/*
	 * Cached progamming disabled for now, Not sure if its worth the
	 * trouble. The speed gain is not very impressive. (2.3->2.6Mib/s)
	 */
	cached = 0;

	if (!cached || !(chip->options & NAND_CACHEPRG)) {

		chip->cmdfunc(mtd, NAND_CMD_PAGEPROG, -1, -1);
		status = chip->waitfunc(mtd, chip);
		/*
		 * See if operation failed and additional status checks are
		 * available
		 */
		if ((status & NAND_STATUS_FAIL) && (chip->errstat))
			status = chip->errstat(mtd, chip, FL_WRITING, status,
					       page);

		if (status & NAND_STATUS_FAIL)
			return -EIO;
	} else {
		chip->cmdfunc(mtd, NAND_CMD_CACHEDPROG, -1, -1);
		status = chip->waitfunc(mtd, chip);
	}

#ifdef CONFIG_MTD_NAND_VERIFY_WRITE
	/* Send command to read back the data */
	chip->cmdfunc(mtd, NAND_CMD_READ0, 0, page);

	if (chip->verify_buf(mtd, buf, mtd->writesize))
		return -EIO;
#endif
	return 0;
}

/**
 * nand_fill_oob - [Internal] Transfer client buffer to oob
 * @chip:	nand chip structure
 * @oob:	oob data buffer
 * @ops:	oob ops structure
 */
static uint8_t *nand_fill_oob(struct nand_chip *chip, uint8_t *oob,
				  struct mtd_oob_ops *ops)
{
	size_t len = ops->ooblen;

	switch(ops->mode) {

	case MTD_OOB_PLACE:
	case MTD_OOB_RAW:
		memcpy(chip->oob_poi + ops->ooboffs, oob, len);
		return oob + len;

	case MTD_OOB_AUTO: {
		struct nand_oobfree *free = chip->ecc.layout->oobfree;
		uint32_t boffs = 0, woffs = ops->ooboffs;
		size_t bytes = 0;

		for(; free->length && len; free++, len -= bytes) {
			/* Write request not from offset 0 ? */
			if (unlikely(woffs)) {
				if (woffs >= free->length) {
					woffs -= free->length;
					continue;
				}
				boffs = free->offset + woffs;
				bytes = min_t(size_t, len,
					      (free->length - woffs));
				woffs = 0;
			} else {
				bytes = min_t(size_t, len, free->length);
				boffs = free->offset;
			}
			memcpy(chip->oob_poi + boffs, oob, bytes);
			oob += bytes;
		}
		return oob;
	}
	default:
		BUG();
	}
	return NULL;
}

#define NOTALIGNED(x)	(x & (chip->subpagesize - 1)) != 0

/**
 * nand_do_write_ops - [Internal] NAND write with ECC
 * @mtd:	MTD device structure
 * @to:		offset to write to
 * @ops:	oob operations description structure
 *
 * NAND write with ECC
 */
static int nand_do_write_ops(struct mtd_info *mtd, loff_t to,
			     struct mtd_oob_ops *ops)
{
	int chipnr, realpage, page, blockmask, column;
	struct nand_chip *chip = mtd->priv;
	uint32_t writelen = ops->len;
	uint8_t *oob = ops->oobbuf;
	uint8_t *buf = ops->datbuf;
	int ret, subpage;

	ops->retlen = 0;
	if (!writelen)
		return 0;

	/* reject writes, which are not page aligned */
	if (NOTALIGNED(to) || NOTALIGNED(ops->len)) {
		printk(KERN_NOTICE "nand_write: "
		       "Attempt to write not page aligned data\n");
		return -EINVAL;
	}

	column = to & (mtd->writesize - 1);
	subpage = column || (writelen & (mtd->writesize - 1));

	if (subpage && oob)
		return -EINVAL;

	chipnr = (int)(to >> chip->chip_shift);
	chip->select_chip(mtd, chipnr);

	/* Check, if it is write protected */
	if (nand_check_wp(mtd)) {
		printk (KERN_NOTICE "nand_do_write_ops: Device is write protected\n");
		return -EIO;
	}

	realpage = (int)(to >> chip->page_shift);
	page = realpage & chip->pagemask;
	blockmask = (1 << (chip->phys_erase_shift - chip->page_shift)) - 1;

	/* Invalidate the page cache, when we write to the cached page */
	if (to <= (chip->pagebuf << chip->page_shift) &&
	    (chip->pagebuf << chip->page_shift) < (to + ops->len))
		chip->pagebuf = -1;

	/* If we're not given explicit OOB data, let it be 0xFF */
	if (likely(!oob))
		memset(chip->oob_poi, 0xff, mtd->oobsize);

	while(1) {
		int bytes = mtd->writesize;
		int cached = writelen > bytes && page != blockmask;
		uint8_t *wbuf = buf;

		/* Partial page write ? */
		if (unlikely(column || writelen < (mtd->writesize - 1))) {
			cached = 0;
			bytes = min_t(int, bytes - column, (int) writelen);
			chip->pagebuf = -1;
			memset(chip->buffers->databuf, 0xff, mtd->writesize);
			memcpy(&chip->buffers->databuf[column], buf, bytes);
			wbuf = chip->buffers->databuf;
		}

		if (unlikely(oob))
			oob = nand_fill_oob(chip, oob, ops);
#ifdef CONFIG_NAND_ECC_HW_REED_SOLOMON
        ret = chip->write_page(mtd, chip, wbuf, page, cached, (ops->mode == MTD_OOB_RAW) || (oob && (ops->mode == MTD_OOB_PLACE)));
#else
		ret = chip->write_page(mtd, chip, wbuf, page, cached,
				       (ops->mode == MTD_OOB_RAW));
#endif
        if (ret)
			break;

		writelen -= bytes;
		if (!writelen){
			  break;
            }
		column = 0;
		buf += bytes;
		realpage++;

		page = realpage & chip->pagemask;
		/* Check, if we cross a chip boundary */
		if (!page) {
			chipnr++;
			chip->select_chip(mtd, -1);
			chip->select_chip(mtd, chipnr);
		}
	}
	asm("sync");
	ops->retlen = ops->len - writelen;
	if (unlikely(oob))
		ops->oobretlen = ops->ooblen;
	return ret;
}

/**
 * nand_write - [MTD Interface] NAND write with ECC
 * @mtd:	MTD device structure
 * @to:		offset to write to
 * @len:	number of bytes to write
 * @retlen:	pointer to variable to store the number of written bytes
 * @buf:	the data to write
 *
 * NAND write with ECC
 */
static int nand_write(struct mtd_info *mtd, loff_t to, u64 len,
			  u64 *retlen, const uint8_t *buf)
{
	struct nand_chip *chip = mtd->priv;
	int ret;

	/* Do not allow reads past end of device */
	if ((to + len) > mtd->size)
		return -EINVAL;
	if (!len)
		return 0;

	nand_get_device(chip, mtd, FL_WRITING);

	chip->ops.len = len;
	chip->ops.datbuf = (uint8_t *)buf;
	chip->ops.oobbuf = NULL;

	ret = nand_do_write_ops(mtd, to, &chip->ops);

	*retlen = chip->ops.retlen;

	nand_release_device(mtd);

	return ret;
}

static int nand_write_partial (struct mtd_info *mtd, loff_t offset, u64 len, u64 * retlen, const u_char * buf)
{
      size_t chunk_len;
    size_t actual;
    int ret;
    unsigned long sect_addr;
    unsigned long sector_size;
    unsigned char *sect_buf = NULL;
    int f_start_partial=0;
    int f_end_partial=0;
    int f_malloc=0;
    int total_sect_num=0;
    struct erase_info erase;
    int i;
    sector_size = mtd->erasesize;
    
	if( (offset % sector_size)!=0 ) f_start_partial = 1;
    if( ( (offset + len ) % sector_size)!=0 ) f_end_partial = 1;

    total_sect_num = (offset + len -1) / sector_size - offset / sector_size + 1;
    sect_addr = offset / sector_size;
    sect_buf = buf;
    for(i=0; i<total_sect_num; i++){
             if((f_start_partial && i==0) || (f_end_partial && total_sect_num ==1)) {
				 sect_buf=(uchar *)memalign(32, sector_size);
				 asm("sync");
				 nand_read(mtd, (sect_addr + i) * sector_size, (u64)sector_size, retlen, sect_buf);
				 asm("sync");
				 memcpy(sect_buf + (offset % (u32)sector_size), buf, \
                        min((sector_size-(offset % sector_size)),len));
                 f_malloc = 1;
              }
              else if(f_end_partial && i == total_sect_num -1 && i!=0){
                 sect_buf=(uchar *)memalign(32, sector_size);;
                 nand_read(mtd, (sect_addr + i) * sector_size, (u64)sector_size, retlen, sect_buf);
                 memcpy(sect_buf,buf+i*sector_size-(offset % sector_size), (offset+len) % sector_size);
                 f_malloc=1;
              }

											   
             memset(&erase, 0, sizeof(erase));
             erase.mtd  = mtd;
             erase.addr = (sect_addr + i) * sector_size;
             erase.len  = sector_size;
             erase.state = 0;
             if (nand_block_checkbad( mtd, erase.addr, 1, 1)){
                   printf("block bad, partial write failed..\n");
				   *retlen = 0;
				   return 0;
			 }
			 
			 nand_erase_nand (mtd, &erase,0);

             nand_write(mtd, (sect_addr + i) * sector_size, (u64)sector_size, retlen, sect_buf);
             if(f_malloc) {
                 free(sect_buf);
				 f_malloc=0;
               }
             sect_buf = buf + (i+1)*sector_size - (offset % sector_size);
        }
      *retlen = (u64)len;		
	  return 0;
}



/**
 * nand_do_write_oob - [MTD Interface] NAND write out-of-band
 * @mtd:	MTD device structure
 * @to:		offset to write to
 * @ops:	oob operation description structure
 *
 * NAND write out-of-band
 */
static int nand_do_write_oob(struct mtd_info *mtd, loff_t to,
			     struct mtd_oob_ops *ops)
{
	int chipnr, page, status, len;
	struct nand_chip *chip = mtd->priv;

	MTDDEBUG (MTD_DEBUG_LEVEL3, "nand_write_oob: to = 0x%08x, len = %i\n",
	          (unsigned int)to, (int)ops->ooblen);

	if (ops->mode == MTD_OOB_AUTO)
		len = chip->ecc.layout->oobavail;
	else
		len = mtd->oobsize;

	/* Do not allow write past end of page */
	if ((ops->ooboffs + ops->ooblen) > len) {
		MTDDEBUG (MTD_DEBUG_LEVEL0, "nand_write_oob: "
		          "Attempt to write past end of page\n");
		return -EINVAL;
	}

	if (unlikely(ops->ooboffs >= len)) {
		MTDDEBUG (MTD_DEBUG_LEVEL0, "nand_read_oob: "
		          "Attempt to start write outside oob\n");
		return -EINVAL;
	}

	/* Do not allow reads past end of device */
	if (unlikely(to >= mtd->size ||
		     ops->ooboffs + ops->ooblen >
			((mtd->size >> chip->page_shift) -
			 (to >> chip->page_shift)) * len)) {
		MTDDEBUG (MTD_DEBUG_LEVEL0, "nand_read_oob: "
		          "Attempt write beyond end of device\n");
		return -EINVAL;
	}

	chipnr = (int)(to >> chip->chip_shift);
	chip->select_chip(mtd, chipnr);

	/* Shift to get page */
	page = (int)(to >> chip->page_shift);

	/*
	 * Reset the chip. Some chips (like the Toshiba TC5832DC found in one
	 * of my DiskOnChip 2000 test units) will clear the whole data page too
	 * if we don't do this. I have no clue why, but I seem to have 'fixed'
	 * it in the doc2000 driver in August 1999.  dwmw2.
	 */
	chip->cmdfunc(mtd, NAND_CMD_RESET, -1, -1);

	/* Check, if it is write protected */
	if (nand_check_wp(mtd))
		return -EROFS;

	/* Invalidate the page cache, if we write to the cached page */
	if (page == chip->pagebuf)
		chip->pagebuf = -1;

	memset(chip->oob_poi, 0xff, mtd->oobsize);
	nand_fill_oob(chip, ops->oobbuf, ops);
	status = chip->ecc.write_oob(mtd, chip, page & chip->pagemask);
	memset(chip->oob_poi, 0xff, mtd->oobsize);

	if (status)
		return status;

	ops->oobretlen = ops->ooblen;

	return 0;
}

/**
 * nand_write_oob - [MTD Interface] NAND write data and/or out-of-band
 * @mtd:	MTD device structure
 * @to:		offset to write to
 * @ops:	oob operation description structure
 */
static int nand_write_oob(struct mtd_info *mtd, loff_t to,
			  struct mtd_oob_ops *ops)
{
	struct nand_chip *chip = mtd->priv;
	int ret = -ENOTSUPP;

	ops->retlen = 0;

	/* Do not allow writes past end of device */
	if (ops->datbuf && (to + ops->len) > mtd->size) {
		MTDDEBUG (MTD_DEBUG_LEVEL0, "nand_read_oob: "
		          "Attempt read beyond end of device\n");
		return -EINVAL;
	}

	nand_get_device(chip, mtd, FL_WRITING);

	switch(ops->mode) {
	case MTD_OOB_PLACE:
	case MTD_OOB_AUTO:
	case MTD_OOB_RAW:
		break;

	default:
		goto out;
	}

	if (!ops->datbuf)
		ret = nand_do_write_oob(mtd, to, ops);
	else
		ret = nand_do_write_ops(mtd, to, ops);

 out:
	nand_release_device(mtd);
	return ret;
}

/**
 * single_erease_cmd - [GENERIC] NAND standard block erase command function
 * @mtd:	MTD device structure
 * @page:	the page address of the block which will be erased
 *
 * Standard erase command for NAND chips
 */
static void single_erase_cmd(struct mtd_info *mtd, int page)
{
	struct nand_chip *chip = mtd->priv;
	/* Send commands to erase a block */
	chip->cmdfunc(mtd, NAND_CMD_ERASE1, -1, page);
	chip->cmdfunc(mtd, NAND_CMD_ERASE2, -1, -1);
}

/**
 * multi_erease_cmd - [GENERIC] AND specific block erase command function
 * @mtd:	MTD device structure
 * @page:	the page address of the block which will be erased
 *
 * AND multi block erase command function
 * Erase 4 consecutive blocks
 */
static void multi_erase_cmd(struct mtd_info *mtd, int page)
{
	struct nand_chip *chip = mtd->priv;
	/* Send commands to erase a block */
	chip->cmdfunc(mtd, NAND_CMD_ERASE1, -1, page++);
	chip->cmdfunc(mtd, NAND_CMD_ERASE1, -1, page++);
	chip->cmdfunc(mtd, NAND_CMD_ERASE1, -1, page++);
	chip->cmdfunc(mtd, NAND_CMD_ERASE1, -1, page);
	chip->cmdfunc(mtd, NAND_CMD_ERASE2, -1, -1);
}

/**
 * nand_erase - [MTD Interface] erase block(s)
 * @mtd:	MTD device structure
 * @instr:	erase instruction
 *
 * Erase one ore more blocks
 */
static int nand_erase(struct mtd_info *mtd, struct erase_info *instr)
{
	return nand_erase_nand(mtd, instr, 0);
}

#define BBT_PAGE_MASK	0xffffff3f
/**
 * nand_erase_nand - [Internal] erase block(s)
 * @mtd:	MTD device structure
 * @instr:	erase instruction
 * @allowbbt:	allow erasing the bbt area
 *
 * Erase one ore more blocks
 */
int nand_erase_nand(struct mtd_info *mtd, struct erase_info *instr,
		    int allowbbt)
{
	int page, status, pages_per_block, ret, chipnr;
	struct nand_chip *chip = mtd->priv;
	loff_t rewrite_bbt[CONFIG_SYS_NAND_MAX_CHIPS] = {0};
	unsigned int bbt_masked_page = 0xffffffff;
	loff_t len;

	MTDDEBUG(MTD_DEBUG_LEVEL3, "nand_erase: start = 0x%012llx, "
		 "len = %llu\n", (unsigned long long) instr->addr,
		 (unsigned long long) instr->len);

	/* Start address must align on block boundary */
	if (instr->addr & ((1 << chip->phys_erase_shift) - 1)) {
		MTDDEBUG (MTD_DEBUG_LEVEL0, "nand_erase: Unaligned address\n");
		return -EINVAL;
	}

	/* Length must align on block boundary */
	if (instr->len & ((1 << chip->phys_erase_shift) - 1)) {
		MTDDEBUG (MTD_DEBUG_LEVEL0,
		          "nand_erase: Length not block aligned\n");
		return -EINVAL;
	}

	/* Do not allow erase past end of device */
	if ((instr->len + instr->addr) > mtd->size) {
		MTDDEBUG (MTD_DEBUG_LEVEL0,
		          "nand_erase: Erase past end of device\n");
		return -EINVAL;
	}

	instr->fail_addr = 0xffffffff;

	/* Grab the lock and see if the device is available */
	nand_get_device(chip, mtd, FL_ERASING);

	/* Shift to get first page */
	page = (int)(instr->addr >> chip->page_shift);
	chipnr = (int)(instr->addr >> chip->chip_shift);

	/* Calculate pages in each block */
	pages_per_block = 1 << (chip->phys_erase_shift - chip->page_shift);

	/* Select the NAND device */
	chip->select_chip(mtd, chipnr);

	/* Check, if it is write protected */
	if (nand_check_wp(mtd)) {
		MTDDEBUG (MTD_DEBUG_LEVEL0,
		          "nand_erase: Device is write protected!!!\n");
		instr->state = MTD_ERASE_FAILED;
		goto erase_exit;
	}

	/*
	 * If BBT requires refresh, set the BBT page mask to see if the BBT
	 * should be rewritten. Otherwise the mask is set to 0xffffffff which
	 * can not be matched. This is also done when the bbt is actually
	 * erased to avoid recusrsive updates
	 */
	if (chip->options & BBT_AUTO_REFRESH && !allowbbt)
		bbt_masked_page = chip->bbt_td->pages[chipnr] & BBT_PAGE_MASK;

	/* Loop through the pages */
	len = instr->len;

	instr->state = MTD_ERASING;

	while (len) {
		/*
		 * heck if we have a bad block, we do not erase bad blocks !
		 */
		if (nand_block_checkbad(mtd, ((loff_t) page) <<
					chip->page_shift, 0, allowbbt)) {
			printk(KERN_WARNING "nand_erase: attempt to erase a "
			       "bad block at page 0x%08x\n", page);
			instr->state = MTD_ERASE_FAILED;
			goto erase_exit;
		}

		/*
		 * Invalidate the page cache, if we erase the block which
		 * contains the current cached page
		 */
		if (page <= chip->pagebuf && chip->pagebuf <
		    (page + pages_per_block))
			chip->pagebuf = -1;

		chip->erase_cmd(mtd, page & chip->pagemask);

		status = chip->waitfunc(mtd, chip);

		/*
		 * See if operation failed and additional status checks are
		 * available
		 */
		if ((status & NAND_STATUS_FAIL) && (chip->errstat))
			status = chip->errstat(mtd, chip, FL_ERASING,
					       status, page);

		/* See if block erase succeeded */
		if (status & NAND_STATUS_FAIL) {
			MTDDEBUG (MTD_DEBUG_LEVEL0, "nand_erase: "
			          "Failed erase, page 0x%08x\n", page);
			instr->state = MTD_ERASE_FAILED;
			instr->fail_addr = ((loff_t)page << chip->page_shift);
			goto erase_exit;
		}

		/*
		 * If BBT requires refresh, set the BBT rewrite flag to the
		 * page being erased
		 */
		if (bbt_masked_page != 0xffffffff &&
		    (page & BBT_PAGE_MASK) == bbt_masked_page)
			rewrite_bbt[chipnr] =
				((loff_t)page << chip->page_shift);

		/* Increment page address and decrement length */
		len -= (1 << chip->phys_erase_shift);
		page += pages_per_block;

		/* Check, if we cross a chip boundary */
		if (len && !(page & chip->pagemask)) {
			chipnr++;
			chip->select_chip(mtd, -1);
			chip->select_chip(mtd, chipnr);

			/*
			 * If BBT requires refresh and BBT-PERCHIP, set the BBT
			 * page mask to see if this BBT should be rewritten
			 */
			if (bbt_masked_page != 0xffffffff &&
			    (chip->bbt_td->options & NAND_BBT_PERCHIP))
				bbt_masked_page = chip->bbt_td->pages[chipnr] &
					BBT_PAGE_MASK;
		}
	}
	instr->state = MTD_ERASE_DONE;

 erase_exit:

	ret = instr->state == MTD_ERASE_DONE ? 0 : -EIO;

	/* Deselect and wake up anyone waiting on the device */
	nand_release_device(mtd);

	/* Do call back function */
	if (!ret)
		mtd_erase_callback(instr);

	/*
	 * If BBT requires refresh and erase was successful, rewrite any
	 * selected bad block tables
	 */
	if (bbt_masked_page == 0xffffffff || ret)
		return ret;

	for (chipnr = 0; chipnr < chip->numchips; chipnr++) {
		if (!rewrite_bbt[chipnr])
			continue;
		/* update the BBT for chip */
		MTDDEBUG (MTD_DEBUG_LEVEL0, "nand_erase_nand: nand_update_bbt "
			  "(%d:0x%0llx 0x%0x)\n", chipnr, rewrite_bbt[chipnr],
			  chip->bbt_td->pages[chipnr]);
		nand_update_bbt(mtd, rewrite_bbt[chipnr]);
	}

	/* Return more or less happy */
	return ret;
}

/**
 * nand_sync - [MTD Interface] sync
 * @mtd:	MTD device structure
 *
 * Sync is actually a wait for chip ready function
 */
static void nand_sync(struct mtd_info *mtd)
{
	struct nand_chip *chip = mtd->priv;

	MTDDEBUG (MTD_DEBUG_LEVEL3, "nand_sync: called\n");

	/* Grab the lock and see if the device is available */
	nand_get_device(chip, mtd, FL_SYNCING);
	/* Release it and go back */
	nand_release_device(mtd);
}

/**
 * nand_block_isbad - [MTD Interface] Check if block at offset is bad
 * @mtd:	MTD device structure
 * @offs:	offset relative to mtd start
 */
static int nand_block_isbad(struct mtd_info *mtd, loff_t offs)
{
	/* Check for invalid offset */
	if (offs > mtd->size)
		return -EINVAL;

	return nand_block_checkbad(mtd, offs, 1, 0);
}

/**
 * nand_block_markbad - [MTD Interface] Mark block at the given offset as bad
 * @mtd:	MTD device structure
 * @ofs:	offset relative to mtd start
 */
static int nand_block_markbad(struct mtd_info *mtd, loff_t ofs)
{
	struct nand_chip *chip = mtd->priv;
	int ret;

	if ((ret = nand_block_isbad(mtd, ofs))) {
		/* If it was bad already, return success and do nothing. */
		if (ret > 0)
			return 0;
		return ret;
	}

	return chip->block_markbad(mtd, ofs);
}

/**
 * nand_suspend - [MTD Interface] Suspend the NAND flash
 * @mtd:	MTD device structure
 */
static int nand_suspend(struct mtd_info *mtd)
{
	struct nand_chip *chip = mtd->priv;

	return nand_get_device(chip, mtd, FL_PM_SUSPENDED);
}

/**
 * nand_resume - [MTD Interface] Resume the NAND flash
 * @mtd:	MTD device structure
 */
static void nand_resume(struct mtd_info *mtd)
{
	struct nand_chip *chip = mtd->priv;

	if (chip->state == FL_PM_SUSPENDED)
		nand_release_device(mtd);
	else
		printk(KERN_ERR "nand_resume() called for a chip which is not "
		       "in suspended state\n");
}

/*
 * Set default functions
 */
static void nand_set_defaults(struct nand_chip *chip, int busw)
{
	/* check for proper chip_delay setup, set 20us if not */
	if (!chip->chip_delay)
		chip->chip_delay = 20;

	/* check, if a user supplied command function given */
	if (chip->cmdfunc == NULL)
		chip->cmdfunc = nand_command;

	/* check, if a user supplied wait function given */
	if (chip->waitfunc == NULL)
		chip->waitfunc = nand_wait;

	if (!chip->select_chip)
		chip->select_chip = nand_select_chip;
	if (!chip->read_byte)
		chip->read_byte = busw ? nand_read_byte16 : nand_read_byte;
	if (!chip->read_word)
		chip->read_word = nand_read_word;
	if (!chip->block_bad)
		chip->block_bad = nand_block_bad;
	if (!chip->block_markbad)
		chip->block_markbad = nand_default_block_markbad;
	if (!chip->write_buf)
		chip->write_buf = busw ? nand_write_buf16 : nand_write_buf;
	if (!chip->read_buf)
		chip->read_buf = busw ? nand_read_buf16 : nand_read_buf;
	if (!chip->verify_buf)
		chip->verify_buf = busw ? nand_verify_buf16 : nand_verify_buf;
	if (!chip->scan_bbt)
		chip->scan_bbt = nand_default_bbt;

	if (!chip->controller) {
		chip->controller = &chip->hwcontrol;

		/* XXX U-BOOT XXX */
#if 0
		spin_lock_init(&chip->controller->lock);
		init_waitqueue_head(&chip->controller->wq);
#endif
	}

}

/*
 * sanitize ONFI strings so we can safely print them
 */
static void sanitize_string(uint8_t *s, size_t len)
{
	ssize_t i;

	/* null terminate */
	s[len - 1] = 0;

	/* remove non printable chars */
	for (i = 0; i < len - 1; i++) {
		if (s[i] < ' ' || s[i] > 127)
			s[i] = '?';
	}

	/* remove trailing spaces */
	strim(s);
}

static u16 onfi_crc16(u16 crc, u8 const *p, size_t len)
{
	int i;
	while (len--) {
		crc ^= *p++ << 8;
		for (i = 0; i < 8; i++)
			crc = (crc << 1) ^ ((crc & 0x8000) ? 0x8005 : 0);
	}

	return crc;
}

/*
 * Check if the NAND chip is ONFI compliant, returns 1 if it is, 0 otherwise
 */
static int nand_flash_detect_onfi(struct mtd_info *mtd, struct nand_chip *chip,
					int busw)
{
	struct nand_onfi_params *p = &chip->onfi_params;
	int i,j;
	int val;

	/* try ONFI for unknow chip or LP */
	chip->cmdfunc(mtd, NAND_CMD_READID, 0x20, -1);
	if (chip->read_byte(mtd) != 'O' || chip->read_byte(mtd) != 'N' ||
		chip->read_byte(mtd) != 'F' || chip->read_byte(mtd) != 'I')
		return 0;

	printk(KERN_INFO "ONFI flash detected\n");
	chip->cmdfunc(mtd, NAND_CMD_PARAM, 0, -1);
	for (i = 0; i < 3; i++) {
		chip->read_buf(mtd, (uint8_t *)p, sizeof(*p));
		if (onfi_crc16(ONFI_CRC_BASE, (uint8_t *)p, 254) ==
				le16_to_cpu(p->crc)) {
			printk(KERN_INFO "ONFI param page %d valid\n", i);
			break;
		}
	}
    /* 
    for(j=0;j<sizeof(*p);j++){
        printf("%02x ",*((uint8_t *)p+j));
        if((j+1)%16==0) printf("\n");
	}
    */
	if (i == 3)
		return 0;

	/* check version */
	val = le16_to_cpu(p->revision) & 0xf;
	if (val == 1 || val > (1 << 4)) {
		printk(KERN_INFO "%s: unsupported ONFI version: %d\n",
								__func__, val);
		return 0;
	}

	if (val & (1 << 4))
		chip->onfi_version = 22;
	else if (val & (1 << 3))
		chip->onfi_version = 21;
	else if (val & (1 << 2))
		chip->onfi_version = 20;
	else
		chip->onfi_version = 10;

	sanitize_string(p->manufacturer, sizeof(p->manufacturer));
	sanitize_string(p->model, sizeof(p->model));
	if (!mtd->name)
		mtd->name = p->model;
	mtd->writesize = le32_to_cpu(p->byte_per_page);
	mtd->erasesize = le32_to_cpu(p->pages_per_block) * mtd->writesize;
	mtd->oobsize = le16_to_cpu(p->spare_bytes_per_page);
	chip->chipsize = (u64)le32_to_cpu(p->blocks_per_lun)*(u64)(p->lun_count)*(u64)(mtd->erasesize);
	/*fix me, seems no way to differenciate between Micron MLC 64,128,256,512G based on the above calculation*/
	if (strcmp(mtd->name,"MT29F128G08CFAAAWP")==0){
		chip->chipsize *= 2; 
	}else if(strcmp(mtd->name,"MT29F256G08CJAAAWP")==0){	
	    chip->chipsize *= 2;
	}
	
	busw = 0;
	if (le16_to_cpu(p->features) & 1)
		busw = NAND_BUSWIDTH_16;

	chip->options &= ~NAND_CHIPOPTIONS_MSK;
	chip->options |= (NAND_NO_READRDY |
			NAND_NO_AUTOINCR) & NAND_CHIPOPTIONS_MSK;

	return 1;
}

/* return the supported JEDEC features. */
static inline int jedec_feature(struct nand_chip *chip)
{
    return chip->jedec_version ? le16_to_cpu(chip->jedec_params.features)
        : 0;
}

/*
 * Check if the NAND chip is JEDEC compliant, returns 1 if it is, 0 otherwise.
 */
static int nand_flash_detect_jedec(struct mtd_info *mtd, struct nand_chip *chip,
                    int *busw)
{
    struct nand_jedec_params *p = &chip->jedec_params;
    struct jedec_ecc_info *ecc;
    int val;
    int i, j;

    /* Try JEDEC for unknown chip or LP */
    chip->cmdfunc(mtd, NAND_CMD_READID, 0x40, -1);
    if (chip->read_byte(mtd) != 'J' || chip->read_byte(mtd) != 'E' ||
        chip->read_byte(mtd) != 'D' || chip->read_byte(mtd) != 'E' ||
        chip->read_byte(mtd) != 'C')
        return 0;

    chip->cmdfunc(mtd, NAND_CMD_PARAM, 0x40, -1);
    for (i = 0; i < 3; i++) {
        for (j = 0; j < sizeof(*p); j++)
            ((uint8_t *)p)[j] = chip->read_byte(mtd);

        if (onfi_crc16(ONFI_CRC_BASE, (uint8_t *)p, 510) ==
                le16_to_cpu(p->crc))
            break;
    }

    if (i == 3) {
        printk(KERN_ERR "Could not find valid JEDEC parameter page; aborting\n");
        return 0;
    }

    /* Check version */
    val = le16_to_cpu(p->revision);
    if (val & (1 << 2))
        chip->jedec_version = 10;
    else if (val & (1 << 1))
        chip->jedec_version = 1; /* vendor specific version */
    if (!chip->jedec_version) {
        printk(KERN_INFO "unsupported JEDEC version: %d\n", val);
        return 0;
    }

    sanitize_string(p->manufacturer, sizeof(p->manufacturer));
    sanitize_string(p->model, sizeof(p->model));
    if (!mtd->name)
        mtd->name = p->model;

    mtd->writesize = le32_to_cpu(p->byte_per_page);

    /* Please reference to the comment for nand_flash_detect_onfi. */
    mtd->erasesize = 1 << (fls(le32_to_cpu(p->pages_per_block)) - 1);
    mtd->erasesize *= mtd->writesize;

    mtd->oobsize = le16_to_cpu(p->spare_bytes_per_page);

    /* Please reference to the comment for nand_flash_detect_onfi. */
    chip->chipsize = 1 << (fls(le32_to_cpu(p->blocks_per_lun)) - 1);
    chip->chipsize *= (uint64_t)mtd->erasesize * p->lun_count;
    //chip->bits_per_cell = p->bits_per_cell;

    if (jedec_feature(chip) & JEDEC_FEATURE_16_BIT_BUS)
        *busw = NAND_BUSWIDTH_16;
    else
        *busw = 0;

    /* ECC info */
    ecc = &p->ecc_info[0];

	/* 
	* TODO:
	* do we need to know the ecc density now? 
	* or should we just enforce HW/SW correctibility meets spec?
    if (ecc->codeword_size >= 9) {
        chip->ecc_strength_ds = ecc->ecc_bits;
        chip->ecc_step_ds = 1 << ecc->codeword_size;
    } else {
        printk(KERN_WARNING, "Invalid codeword size\n");
    }
	*/

    return 1;
}

/*
 * Check if the NAND chip is SPI NAND flash, returns 1 if it is, 0 otherwise.
 */
static int spinand_flash_detect(struct mtd_info *mtd,struct nand_chip *chip)
{
       int retval=0;
       u8 id_data[8];
       int i;
       struct spinand_flash_dev *type = NULL;
       
       chip->cmdfunc(mtd, NAND_CMD_READID, 0x00, -1);
       for (i = 0; i < 3; i++)
                id_data[i] = chip->read_byte(mtd);

        if (!type)
                type = spinand_flash_ids;

        for (; type->name != NULL; type++)
                if ((id_data[0] == type->mf_id) && (id_data[1] == type->dev_id))
                        break;

        if (!type->name)
                goto probe_done;

        mtd->name = type->name;

        mtd->erasesize = type->erasesize;
        mtd->writesize = type->pagesize;
        mtd->oobsize = type->oobsize;

        chip->chipsize = (type->chipsize)<<20;

        if (mtd->oobsize == 128) {
                        chip->ecc.bytes = 9;            /* 9B * (4096B/512B) */
                        chip->ecc.size = 512;   /* 4b * (4096B/512B) */
                } else if (mtd->oobsize == 64) { /* 64B oob */
                        chip->ecc.bytes = 9;
                        chip->ecc.size = 512;
                } else {
                        printk(KERN_WARNING "%d unsupported oobsize\n",
                                        mtd->oobsize);
                        return -EINVAL;
                }


        chip->options &= ~NAND_CHIPOPTIONS_MSK;

        retval = 1;
probe_done:
        return retval;

}


/*
 * Get the flash and manufacturer id and lookup if the type is supported
 */
static struct nand_flash_dev *nand_get_flash_type(struct mtd_info *mtd,
						  struct nand_chip *chip,
						  int busw, int *maf_id)
{
	int i, maf_idx,dev_id_value; 
	int *dev_id;
	u8 id_data[8];
	int ret;
  struct nand_flash_dev *type = NULL;


  dev_id = &dev_id_value;
	
	
	/* Select the device */
	chip->select_chip(mtd, 0);

	/*
	 * Reset the chip, required by some chips (e.g. Micron MT29FxGxxxxx)
	 * after power-up
	 */
	chip->cmdfunc(mtd, NAND_CMD_RESET, -1, -1);

	/* Send the command for reading device ID */
	chip->cmdfunc(mtd, NAND_CMD_READID, 0x00, -1);

	/* Read manufacturer and device IDs */
	*maf_id = chip->read_byte(mtd);
	*dev_id = chip->read_byte(mtd);


    //printf("%02x, %02x\n",*maf_id,*dev_id);
	/* Try again to make sure, as some systems the bus-hold or other
	 * interface concerns can cause random data which looks like a
	 * possibly credible NAND flash to appear. If the two results do
	 * not match, ignore the device completely.
	 */

	chip->cmdfunc(mtd, NAND_CMD_READID, 0x00, -1);

	for (i = 0; i < 2; i++)
		id_data[i] = chip->read_byte(mtd);

	if (id_data[0] != *maf_id || id_data[1] != *dev_id) {
		printk(KERN_INFO "%s: second ID read did not match "
		       "%02x,%02x against %02x,%02x\n", __func__,
		       *maf_id, *dev_id, id_data[0], id_data[1]);
		return ERR_PTR(-ENODEV);
	}

	if (!type)
		type = nand_flash_ids;

	for (; type->name != NULL; type++)
		if (*dev_id == type->id)
			break;

	chip->onfi_version = 0;
	if (!type->name || !type->pagesize) {
		/* Check is chip is ONFI compliant */
		ret = nand_flash_detect_onfi(mtd, chip, busw);
		if (ret)
			goto ident_done;
		ret = nand_flash_detect_jedec(mtd, chip, &busw);
		if (ret)
			goto ident_done;
                ret = spinand_flash_detect(mtd, chip);
                if (ret)
                        goto ident_done;
	}
	

	chip->cmdfunc(mtd, NAND_CMD_READID, 0x00, -1);

	/* Read entire ID string */

	for (i = 0; i < 8; i++)
		id_data[i] = chip->read_byte(mtd);

	if (!type->name)
		return ERR_PTR(-ENODEV);

	if (!mtd->name)
		mtd->name = type->name;

	chip->chipsize = (uint64_t)type->chipsize << 20;

	if (!type->pagesize && chip->init_size) {
		/* set the pagesize, oobsize, erasesize by the driver*/
		busw = chip->init_size(mtd, chip, id_data);
	} else if (!type->pagesize) {
		int extid;
		/* The 3rd id byte holds MLC / multichip data */
		chip->cellinfo = id_data[2];
		/* The 4th id byte is the important one */
		extid = id_data[3];

		/*
		 * Field definitions are in the following datasheets:
		 * Old style (4,5 byte ID): Samsung K9GAG08U0M (p.32)
		 * New style   (6 byte ID): Samsung K9GBG08U0M (p.40)
		 *
		 * Check for wraparound + Samsung ID + nonzero 6th byte
		 * to decide what to do.
		 */
		if (id_data[0] == id_data[6] && id_data[1] == id_data[7] &&
				id_data[0] == NAND_MFR_SAMSUNG &&
				(chip->cellinfo & NAND_CI_CELLTYPE_MSK) &&
				id_data[5] != 0x00) {
			/* Calc pagesize */
			mtd->writesize = 2048 << (extid & 0x03);
			extid >>= 2;
			/* Calc oobsize */
			switch (extid & 0x03) {
			case 1:
				mtd->oobsize = 128;
				break;
			case 2:
				mtd->oobsize = 218;
				break;
			case 3:
				mtd->oobsize = 400;
				break;
			default:
				mtd->oobsize = 436;
				break;
			}
			extid >>= 2;
			/* Calc blocksize */
			mtd->erasesize = (128 * 1024) <<
				(((extid >> 1) & 0x04) | (extid & 0x03));
			busw = 0;
		} 
		else if (id_data[0] == id_data[6] && id_data[1] == id_data[7] &&
				id_data[0] == NAND_MFR_HYNIX &&
				(chip->cellinfo & NAND_CI_CELLTYPE_MSK) &&
				id_data[5] != 0x00) {
			/* Calc pagesize */
			mtd->writesize = 2048 << (extid & 0x03);
			extid >>= 2;
			/* Calc oobsize */
			switch (extid & 0x03) {
			case 0:
				mtd->oobsize = 128;
				break;
			case 1:
				mtd->oobsize = 224;
				break;
			case 2:
				mtd->oobsize = 448;
				break;
			}
			extid >>= 2;
			/* Calc blocksize */
			mtd->erasesize = (extid & 0x8) ? (1024 * 1024)<< ( extid & 0x1 ) :(128 * 1024) * (extid & 0x03)* 2;
			busw = 0;
		} 
	
		else {
			/* Calc pagesize */
			mtd->writesize = 1024 << (extid & 0x03);
			extid >>= 2;
			/* Calc oobsize */
			mtd->oobsize = (8 << (extid & 0x01)) *
				(mtd->writesize >> 9);
			extid >>= 2;
			/* Calc blocksize. Blocksize is multiples of 64KiB */
			mtd->erasesize = (64 * 1024) << (extid & 0x03);
			extid >>= 2;
			/* Get buswidth information */
			busw = (extid & 0x01) ? NAND_BUSWIDTH_16 : 0;
		}
	} else {
		/*
		 * Old devices have chip data hardcoded in the device id table
		 */
		mtd->erasesize = type->erasesize;
		mtd->writesize = type->pagesize;
		mtd->oobsize = mtd->writesize / 32;
		busw = type->options & NAND_BUSWIDTH_16;

		/*
		 * Check for Spansion/AMD ID + repeating 5th, 6th byte since
		 * some Spansion chips have erasesize that conflicts with size
		 * listed in nand_ids table
		 * Data sheet (5 byte ID): Spansion S30ML-P ORNAND (p.39)
		 */
		if (*maf_id == NAND_MFR_AMD && id_data[4] != 0x00 &&
				id_data[5] == 0x00 && id_data[6] == 0x00 &&
				id_data[7] == 0x00 && mtd->writesize == 512) {
			mtd->erasesize = 128 * 1024;
			mtd->erasesize <<= ((id_data[3] & 0x03) << 1);
		}
	}
	/* Get chip options, preserve non chip based options */
	chip->options &= ~NAND_CHIPOPTIONS_MSK;
	chip->options |= type->options & NAND_CHIPOPTIONS_MSK;

	/* Check if chip is a not a samsung device. Do not clear the
	 * options for chips which are not having an extended id.
	 */
	if (*maf_id != NAND_MFR_SAMSUNG && !type->pagesize)
		chip->options &= ~NAND_SAMSUNG_LP_OPTIONS;
ident_done:

	/*
	 * Set chip as a default. Board drivers can override it, if necessary
	 */
	chip->options |= NAND_NO_AUTOINCR;

	/* Try to identify manufacturer */
	for (maf_idx = 0; nand_manuf_ids[maf_idx].id != 0x0; maf_idx++) {
		if (nand_manuf_ids[maf_idx].id == *maf_id)
			break;
	}

	/*
	 * Check, if buswidth is correct. Hardware drivers should set
	 * chip correct !
	 */
	if (busw != (chip->options & NAND_BUSWIDTH_16)) {
		printk(KERN_INFO "NAND device: Manufacturer ID:"
		       " 0x%02x, Chip ID: 0x%02x (%s %s)\n", *maf_id,
		       *dev_id, nand_manuf_ids[maf_idx].name, mtd->name);
		printk(KERN_WARNING "NAND bus width %d instead %d bit\n",
		       (chip->options & NAND_BUSWIDTH_16) ? 16 : 8,
		       busw ? 16 : 8);
		return ERR_PTR(-EINVAL);
	}

	/* Calculate the address shift from the page size */
	chip->page_shift = ffs(mtd->writesize) - 1;
	/* Convert chipsize to number of pages per chip -1. */
	chip->pagemask = (chip->chipsize >> chip->page_shift) - 1;

	chip->bbt_erase_shift = chip->phys_erase_shift =
		ffs(mtd->erasesize) - 1;
	if (chip->chipsize & 0xffffffff)
		chip->chip_shift = ffs((unsigned)chip->chipsize) - 1;
	else {
		chip->chip_shift = ffs((unsigned)(chip->chipsize >> 32));
		chip->chip_shift += 32 - 1;
	}

	/* Set the bad block position */
	if (mtd->writesize > 512 || (busw & NAND_BUSWIDTH_16))
		chip->badblockpos = NAND_LARGE_BADBLOCK_POS;
	else
		chip->badblockpos = NAND_SMALL_BADBLOCK_POS;

	/*
	 * Bad block marker is stored in the last page of each block
	 * on Samsung and Hynix MLC devices; stored in first two pages
	 * of each block on Micron devices with 2KiB pages and on
	 * SLC Samsung, Hynix, Toshiba and AMD/Spansion. All others scan
	 * only the first page.
	 */
	if ((chip->cellinfo & NAND_CI_CELLTYPE_MSK) &&
			(*maf_id == NAND_MFR_SAMSUNG ||
			 *maf_id == NAND_MFR_HYNIX))
		chip->options |= NAND_BBT_SCANLASTPAGE;
	else if ((!(chip->cellinfo & NAND_CI_CELLTYPE_MSK) &&
				(*maf_id == NAND_MFR_SAMSUNG ||
				 *maf_id == NAND_MFR_HYNIX ||
				 *maf_id == NAND_MFR_TOSHIBA ||
				 *maf_id == NAND_MFR_AMD)) ||
			(mtd->writesize == 2048 &&
			 *maf_id == NAND_MFR_MICRON))
		chip->options |= NAND_BBT_SCAN2NDPAGE;

	if (id_data[0] == NAND_MFR_TOSHIBA &&
			!(chip->cellinfo & NAND_CI_CELLTYPE_MSK) &&
			(id_data[5] & 0x7) == 0x6) {

		if (id_data[4] & 0x80) /* BENAND */
			chip->ecc.mode = NAND_ECC_BENAND;
		else
			mtd->oobsize = 32 * mtd->writesize >> 9; /* !BENAND */
	}

	/*
	 * Numonyx/ST 2K pages, x8 bus use BOTH byte 1 and 6
	 */
	if (!(busw & NAND_BUSWIDTH_16) &&
			*maf_id == NAND_MFR_STMICRO &&
			mtd->writesize == 2048) {
		chip->options |= NAND_BBT_SCANBYTE1AND6;
		chip->badblockpos = 0;
	}

	/* Check for AND chips with 4 page planes */
	if (chip->options & NAND_4PAGE_ARRAY)
		chip->erase_cmd = multi_erase_cmd;
	else
		chip->erase_cmd = single_erase_cmd;

	/* Do not replace user supplied command function ! */
	if (mtd->writesize > 512 && chip->cmdfunc == nand_command)
		chip->cmdfunc = nand_command_lp;

	/* TODO onfi flash name */
    printk(KERN_INFO "NAND device: Manufacturer ID:"
        " 0x%02x, Chip ID: 0x%02x ", *maf_id, *dev_id);	
	if (chip->onfi_version)
		printk("(%s %s)\n", nand_manuf_ids[maf_idx].name, chip->onfi_params.model);
	else if (chip->jedec_version)
		printk("(%s %s)\n", nand_manuf_ids[maf_idx].name, chip->jedec_params.model);
	else
		printk("(%s %s)\n", nand_manuf_ids[maf_idx].name, mtd->name);
		
		return type;

}

/**
 * nand_scan_ident - [NAND Interface] Scan for the NAND device
 * @mtd:	     MTD device structure
 * @maxchips:	     Number of chips to scan for
 *
 * This is the first phase of the normal nand_scan() function. It
 * reads the flash ID and sets up MTD fields accordingly.
 *
 * The mtd->owner field must be set to the module of the caller.
 */
int nand_scan_ident(struct mtd_info *mtd, int maxchips)
{
	int i, busw, nand_maf_id;
	struct nand_chip *chip = mtd->priv;
	struct nand_flash_dev *type;

	/* Get buswidth to select the correct functions */
	busw = chip->options & NAND_BUSWIDTH_16;
	/* Set the default functions */
	nand_set_defaults(chip, busw);

	/* Read the flash type */
	type = nand_get_flash_type(mtd, chip, busw, &nand_maf_id);

	if (IS_ERR(type)) {
#ifndef CONFIG_SYS_NAND_QUIET_TEST
		printk(KERN_WARNING "No NAND device found!!!\n");
#endif
		chip->select_chip(mtd, -1);
		return PTR_ERR(type);
	}

	/* Check for a chip array */
	for (i = 1; i < maxchips; i++) {
		chip->select_chip(mtd, i);
		/* See comment in nand_get_flash_type for reset */
		chip->cmdfunc(mtd, NAND_CMD_RESET, -1, -1);
		/* Send the command for reading device ID */
		chip->cmdfunc(mtd, NAND_CMD_READID, 0x00, -1);
		/* Read manufacturer and device IDs */
		if (nand_maf_id != chip->read_byte(mtd) ||
		    type->id != chip->read_byte(mtd))
			break;
	}
#ifdef DEBUG
	if (i > 1)
		printk(KERN_INFO "%d NAND chips detected\n", i);
#endif

	/* Store the number of chips and calc total size for mtd */
	chip->numchips = i;
	mtd->size = i * chip->chipsize;

	return 0;
}


/**
 * nand_scan_tail - [NAND Interface] Scan for the NAND device
 * @mtd:	    MTD device structure
 *
 * This is the second phase of the normal nand_scan() function. It
 * fills out all the uninitialized function pointers with the defaults
 * and scans for a bad block table if appropriate.
 */
int nand_scan_tail(struct mtd_info *mtd)
{
	int i;
	struct nand_chip *chip = mtd->priv;

	if (!(chip->options & NAND_OWN_BUFFERS))
		chip->buffers = kmalloc(sizeof(*chip->buffers), GFP_KERNEL);
	if (!chip->buffers)
		return -ENOMEM;

	/* Set the internal oob buffer location, just after the page data */
	chip->oob_poi = chip->buffers->databuf + mtd->writesize;

	/*
	 * If no default placement scheme is given, select an appropriate one
	 */
	if (!chip->ecc.layout && (chip->ecc.mode != NAND_ECC_SOFT_BCH)) {
		switch (mtd->oobsize) {
		case 8:
			chip->ecc.layout = &nand_oob_8;
			break;
		case 16:
			chip->ecc.layout = &nand_oob_16;
			break;
		case 64:
			chip->ecc.layout = &nand_oob_64;
			break;
		case 128:
			chip->ecc.layout = &nand_oob_128;
			break;
		case 224:
		  chip->ecc.layout = &nand_oob_224;
			break;
		case 436:
			chip->ecc.layout = &nand_oob_436;
			break;	
		case 448:
			chip->ecc.layout = &nand_oob_448;
			break;
		case 744:
			chip->ecc.layout = &nand_oob_744;
			break;
		case 1280:
			chip->ecc.layout = &nand_oob_1280;
			break;
		default:
			printk(KERN_WARNING "No oob scheme defined for "
			       "oobsize %d\n", mtd->oobsize);
		}
	}

	if (!chip->write_page)
		chip->write_page = nand_write_page;

	/*
	 * check ECC mode, default to software if 3byte/512byte hardware ECC is
	 * selected and we have 256 byte pagesize fallback to software ECC
	 */

	switch (chip->ecc.mode) {
	case NAND_ECC_HW_OOB_FIRST:
		/* Similar to NAND_ECC_HW, but a separate read_page handle */
		if (!chip->ecc.calculate || !chip->ecc.correct ||
		     !chip->ecc.hwctl) {
			printk(KERN_WARNING "No ECC functions supplied, "
			       "Hardware ECC not possible\n");
			BUG();
		}
		if (!chip->ecc.read_page)
			chip->ecc.read_page = nand_read_page_hwecc_oob_first;
	
	case NAND_ECC_HW:
		/* Use standard hwecc read page function ? */
		if (!chip->ecc.read_page)
			chip->ecc.read_page = nand_read_page_hwecc;
		if (!chip->ecc.write_page)
			chip->ecc.write_page = nand_write_page_hwecc;
		if (!chip->ecc.read_page_raw)
			chip->ecc.read_page_raw = nand_read_page_raw;
		if (!chip->ecc.write_page_raw)
			chip->ecc.write_page_raw = nand_write_page_raw;
		if (!chip->ecc.read_oob)
			chip->ecc.read_oob = nand_read_oob_std;
		if (!chip->ecc.write_oob)
			chip->ecc.write_oob = nand_write_oob_std;
	
	case NAND_ECC_HW_SYNDROME:
		if ((!chip->ecc.calculate || !chip->ecc.correct ||
		     !chip->ecc.hwctl) &&
		    (!chip->ecc.read_page ||
		     chip->ecc.read_page == nand_read_page_hwecc ||
		     !chip->ecc.write_page ||
		     chip->ecc.write_page == nand_write_page_hwecc)) {
			printk(KERN_WARNING "No ECC functions supplied, "
			       "Hardware ECC not possible\n");
			BUG();
		}
		/* Use standard syndrome read/write page function ? */
		if (!chip->ecc.read_page)
			chip->ecc.read_page = nand_read_page_syndrome;
		if (!chip->ecc.write_page)
			chip->ecc.write_page = nand_write_page_syndrome;
		if (!chip->ecc.read_page_raw)
			chip->ecc.read_page_raw = nand_read_page_raw_syndrome;
		if (!chip->ecc.write_page_raw)
			chip->ecc.write_page_raw = nand_write_page_raw_syndrome;
		if (!chip->ecc.read_oob)
			chip->ecc.read_oob = nand_read_oob_syndrome;
		if (!chip->ecc.write_oob)
			chip->ecc.write_oob = nand_write_oob_syndrome;

		if (mtd->writesize >= chip->ecc.size)
			break;
		printk(KERN_WARNING "%d byte HW ECC not possible on "
		       "%d byte page size, fallback to SW ECC\n",
		       chip->ecc.size, mtd->writesize);
		chip->ecc.mode = NAND_ECC_SOFT;
	
	case NAND_ECC_SOFT:
		if(!chip->ecc.calculate) chip->ecc.calculate = nand_calculate_ecc;
		if(!chip->ecc.correct) chip->ecc.correct = nand_correct_data;
		chip->ecc.read_page = nand_read_page_swecc;
		chip->ecc.read_subpage = nand_read_subpage;
		chip->ecc.write_page = nand_write_page_swecc;
		chip->ecc.read_page_raw = nand_read_page_raw;
		chip->ecc.write_page_raw = nand_write_page_raw;
		chip->ecc.read_oob = nand_read_oob_std;
		chip->ecc.write_oob = nand_write_oob_std;
		if(!chip->ecc.size) chip->ecc.size = 256;
		if(!chip->ecc.bytes) chip->ecc.bytes = 3;
		break;

   case NAND_ECC_SOFT_BCH:
       if (!mtd_nand_has_bch()) {
           printk(KERN_WARNING "CONFIG_MTD_ECC_BCH not enabled\n");
           return -EINVAL;
       }
       chip->ecc.calculate = nand_bch_calculate_ecc;
       chip->ecc.correct = nand_bch_correct_data;
       chip->ecc.read_page = nand_read_page_swecc;
       chip->ecc.read_subpage = nand_read_subpage;
       chip->ecc.write_page = nand_write_page_swecc;
       chip->ecc.read_page_raw = nand_read_page_raw;
       chip->ecc.write_page_raw = nand_write_page_raw;
       chip->ecc.read_oob = nand_read_oob_std;
       chip->ecc.write_oob = nand_write_oob_std;
       /*
        * Board driver should supply ecc.size and ecc.bytes values to
        * select how many bits are correctable; see nand_bch_init()
        * for details.
        * Otherwise, default to 4 bits for large page devices
        */
       if (!chip->ecc.size && (mtd->oobsize >= 64)) {
           chip->ecc.size = 512;
           chip->ecc.bytes = 7;
       }
       chip->ecc.priv = nand_bch_init(mtd,
                          chip->ecc.size,
                          chip->ecc.bytes,
                          &chip->ecc.layout);
       if (!chip->ecc.priv)
           printk(KERN_WARNING "BCH ECC initialization failed!\n");

       break;
	
	case NAND_ECC_BENAND:
		chip->ecc.calculate = NULL;
		chip->ecc.correct = NULL;
		if (!chip->ecc.read_page)
			chip->ecc.read_page = nand_read_page_raw;
		chip->ecc.write_page = nand_write_page_raw;
		chip->ecc.read_page_raw = nand_read_page_raw;
		chip->ecc.write_page_raw = nand_write_page_raw;
		chip->ecc.read_oob = nand_read_oob_std;
		chip->ecc.write_oob = nand_write_oob_std;
		chip->ecc.size = mtd->writesize;

		if (mtd->oobsize == 128) {
			chip->ecc.bytes = 9;		/* 9B * (4096B/512B) */
			chip->ecc.size = 512;	/* 4b * (4096B/512B) */
		} else if (mtd->oobsize == 64) { /* 64B oob */
			chip->ecc.bytes = 9;		
			chip->ecc.size = 512;
		} else {
			printk(KERN_WARNING "%d unsupported oobsize in benand_init\n",
					mtd->oobsize);
			return -EINVAL;
		}

		break;

	case NAND_ECC_NONE:
		printk(KERN_WARNING "NAND_ECC_NONE selected by board driver. "
		       "This is not recommended !!\n");
		chip->ecc.read_page = nand_read_page_raw;
		chip->ecc.write_page = nand_write_page_raw;
		chip->ecc.read_oob = nand_read_oob_std;
		chip->ecc.read_page_raw = nand_read_page_raw;
		chip->ecc.write_page_raw = nand_write_page_raw;
		chip->ecc.write_oob = nand_write_oob_std;
		chip->ecc.size = mtd->writesize;
		chip->ecc.bytes = 0;
		break;

	default:
		printk(KERN_WARNING "Invalid NAND_ECC_MODE %d\n",
		       chip->ecc.mode);
		BUG();
	}

	/*
	 * The number of bytes available for a client to place data into
	 * the out of band area
	 */
	chip->ecc.layout->oobavail = 0;
	for (i = 0; chip->ecc.layout->oobfree[i].length
			&& i < ARRAY_SIZE(chip->ecc.layout->oobfree); i++)
		chip->ecc.layout->oobavail +=
			chip->ecc.layout->oobfree[i].length;
	mtd->oobavail = chip->ecc.layout->oobavail;

	/*
	 * Set the number of read / write steps for one page depending on ECC
	 * mode
	 */
	chip->ecc.steps = mtd->writesize / chip->ecc.size;
	if(chip->ecc.steps * chip->ecc.size != mtd->writesize) {
		printk(KERN_WARNING "Invalid ecc parameters\n");
		BUG();
	}
	chip->ecc.total = chip->ecc.steps * chip->ecc.bytes;

	/*
	 * Allow subpage writes up to ecc.steps. Not possible for MLC
	 * FLASH.
	 */
	if (!(chip->options & NAND_NO_SUBPAGE_WRITE) &&
	    !(chip->cellinfo & NAND_CI_CELLTYPE_MSK)) {
		switch(chip->ecc.steps) {
		case 2:
			mtd->subpage_sft = 1;
			break;
		case 4:
		case 8:
		case 16:
			mtd->subpage_sft = 2;
			break;
		}
	}
	chip->subpagesize = mtd->writesize >> mtd->subpage_sft;

	/* Initialize state */
	chip->state = FL_READY;

	/* De-select the device */
	chip->select_chip(mtd, -1);

	/* Invalidate the pagebuffer reference */
	chip->pagebuf = -1;

	/* Fill in remaining MTD driver data */
	mtd->type = MTD_NANDFLASH;
	mtd->flags = MTD_CAP_NANDFLASH;
	mtd->erase = nand_erase;
	mtd->point = NULL;
	mtd->unpoint = NULL;
	mtd->read = nand_read;
	mtd->write = nand_write;
	mtd->write_partial = nand_write_partial;
	mtd->read_oob = nand_read_oob;
	mtd->write_oob = nand_write_oob;
	mtd->sync = nand_sync;
	mtd->lock = NULL;
	mtd->unlock = NULL;
	mtd->suspend = nand_suspend;
	mtd->resume = nand_resume;
	mtd->block_isbad = nand_block_isbad;
	mtd->block_markbad = nand_block_markbad;

	/* propagate ecc.layout to mtd_info */
	mtd->ecclayout = chip->ecc.layout;

	/* Check, if we should skip the bad block table scan */
	if (chip->options & NAND_SKIP_BBTSCAN)
		chip->options |= NAND_BBT_SCANNED;

	return 0;
}

/* module_text_address() isn't exported, and it's mostly a pointless
   test if this is a module _anyway_ -- they'd have to try _really_ hard
   to call us from in-kernel code if the core NAND support is modular. */
#ifdef MODULE
#define caller_is_module() (1)
#else
#define caller_is_module() \
	module_text_address((unsigned long)__builtin_return_address(0))
#endif

/**
 * nand_scan - [NAND Interface] Scan for the NAND device
 * @mtd:	MTD device structure
 * @maxchips:	Number of chips to scan for
 *
 * This fills out all the uninitialized function pointers
 * with the defaults.
 * The flash ID is read and the mtd/chip structures are
 * filled with the appropriate values.
 * The mtd->owner field must be set to the module of the caller
 *
 */
int nand_scan(struct mtd_info *mtd, int maxchips)
{
	int ret;

	/* Many callers got this wrong, so check for it for a while... */
	/* XXX U-BOOT XXX */
#if 0
	if (!mtd->owner && caller_is_module()) {
		printk(KERN_CRIT "nand_scan() called with NULL mtd->owner!\n");
		BUG();
	}
#endif

	ret = nand_scan_ident(mtd, maxchips);
	if (!ret)
		ret = nand_scan_tail(mtd);
	return ret;
}

/**
 * nand_release - [NAND Interface] Free resources held by the NAND device
 * @mtd:	MTD device structure
*/
void nand_release(struct mtd_info *mtd)
{
	struct nand_chip *chip = mtd->priv;

    if (chip->ecc.mode == NAND_ECC_SOFT_BCH)
	       nand_bch_free((struct nand_bch_control *)chip->ecc.priv);

#ifdef CONFIG_MTD_PARTITIONS
	/* Deregister partitions */
	del_mtd_partitions(mtd);
#endif
	/* Deregister the device */
	/* XXX U-BOOT XXX */
#if 0
	del_mtd_device(mtd);
#endif

	/* Free bad block table memory */
	kfree(chip->bbt);
	if (!(chip->options & NAND_OWN_BUFFERS))
		kfree(chip->buffers);
}

/* XXX U-BOOT XXX */
#if 0
EXPORT_SYMBOL_GPL(nand_scan);
EXPORT_SYMBOL_GPL(nand_scan_ident);
EXPORT_SYMBOL_GPL(nand_scan_tail);
EXPORT_SYMBOL_GPL(nand_release);

static int __init nand_base_init(void)
{
	led_trigger_register_simple("nand-disk", &nand_led_trigger);
	return 0;
}

static void __exit nand_base_exit(void)
{
	led_trigger_unregister_simple(nand_led_trigger);
}

module_init(nand_base_init);
module_exit(nand_base_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Steven J. Hill <sjhill@realitydiluted.com>, Thomas Gleixner <tglx@linutronix.de>");
MODULE_DESCRIPTION("Generic NAND flash driver code");
#endif
