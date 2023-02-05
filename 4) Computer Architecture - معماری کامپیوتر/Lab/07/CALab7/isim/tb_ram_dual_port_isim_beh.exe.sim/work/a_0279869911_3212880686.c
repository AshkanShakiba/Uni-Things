/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x7708f090 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "D:/lectures/lab/az7/ram_dual_port.vhd";
extern char *IEEE_P_1242562249;
extern char *IEEE_P_2592010699;

int ieee_p_1242562249_sub_1657552908_1035706684(char *, char *, char *);
char *ieee_p_1242562249_sub_180853171_1035706684(char *, char *, int , int );
unsigned char ieee_p_2592010699_sub_1744673427_503743352(char *, char *, unsigned int , unsigned int );


static void work_a_0279869911_3212880686_p_0(char *t0)
{
    char t9[16];
    char *t1;
    char *t2;
    unsigned char t3;
    unsigned char t4;
    int t5;
    char *t6;
    int t7;
    int t8;
    char *t10;
    char *t11;
    char *t12;
    int t13;
    int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    unsigned char t23;
    unsigned char t24;
    unsigned char t25;
    unsigned char t26;

LAB0:    xsi_set_current_line(66, ng0);
    t1 = (t0 + 1832U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)2);
    if (t4 != 0)
        goto LAB2;

LAB4:    t1 = (t0 + 1312U);
    t3 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t3 != 0)
        goto LAB10;

LAB11:
LAB3:    t1 = (t0 + 4312);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(68, ng0);
    t5 = (32 - 1);
    t1 = (t0 + 7179);
    *((int *)t1) = 0;
    t6 = (t0 + 7183);
    *((int *)t6) = t5;
    t7 = 0;
    t8 = t5;

LAB5:    if (t7 <= t8)
        goto LAB6;

LAB8:    xsi_set_current_line(71, ng0);
    t1 = (t0 + 4456);
    t2 = (t1 + 56U);
    t6 = *((char **)t2);
    t10 = (t6 + 56U);
    t11 = *((char **)t10);
    *((unsigned char *)t11) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    goto LAB3;

LAB6:    xsi_set_current_line(69, ng0);
    t10 = (t0 + 7179);
    t11 = ieee_p_1242562249_sub_180853171_1035706684(IEEE_P_1242562249, t9, *((int *)t10), 5);
    t12 = (t0 + 7179);
    t13 = *((int *)t12);
    t14 = (t13 - 31);
    t15 = (t14 * -1);
    t16 = (5U * t15);
    t17 = (0U + t16);
    t18 = (t0 + 4392);
    t19 = (t18 + 56U);
    t20 = *((char **)t19);
    t21 = (t20 + 56U);
    t22 = *((char **)t21);
    memcpy(t22, t11, 5U);
    xsi_driver_first_trans_delta(t18, t17, 5U, 0LL);

LAB7:    t1 = (t0 + 7179);
    t7 = *((int *)t1);
    t2 = (t0 + 7183);
    t8 = *((int *)t2);
    if (t7 == t8)
        goto LAB8;

LAB9:    t5 = (t7 + 1);
    t7 = t5;
    t6 = (t0 + 7179);
    *((int *)t6) = t7;
    goto LAB5;

LAB10:    xsi_set_current_line(74, ng0);
    t2 = (t0 + 1032U);
    t6 = *((char **)t2);
    t23 = *((unsigned char *)t6);
    t24 = (t23 == (unsigned char)3);
    if (t24 == 1)
        goto LAB15;

LAB16:    t4 = (unsigned char)0;

LAB17:    if (t4 != 0)
        goto LAB12;

LAB14:    t1 = (t0 + 1192U);
    t2 = *((char **)t1);
    t4 = *((unsigned char *)t2);
    t23 = (t4 == (unsigned char)3);
    if (t23 == 1)
        goto LAB20;

LAB21:    t3 = (unsigned char)0;

LAB22:    if (t3 != 0)
        goto LAB18;

LAB19:    t1 = (t0 + 1192U);
    t2 = *((char **)t1);
    t4 = *((unsigned char *)t2);
    t23 = (t4 == (unsigned char)3);
    if (t23 == 1)
        goto LAB25;

LAB26:    t3 = (unsigned char)0;

LAB27:    if (t3 != 0)
        goto LAB23;

LAB24:
LAB13:    goto LAB3;

LAB12:    xsi_set_current_line(75, ng0);
    t2 = (t0 + 1992U);
    t11 = *((char **)t2);
    t2 = (t0 + 1672U);
    t12 = *((char **)t2);
    t2 = (t0 + 6900U);
    t5 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t12, t2);
    t7 = (t5 - 31);
    t15 = (t7 * -1);
    t16 = (5U * t15);
    t17 = (0U + t16);
    t18 = (t0 + 4392);
    t19 = (t18 + 56U);
    t20 = *((char **)t19);
    t21 = (t20 + 56U);
    t22 = *((char **)t21);
    memcpy(t22, t11, 5U);
    xsi_driver_first_trans_delta(t18, t17, 5U, 0LL);
    goto LAB13;

LAB15:    t2 = (t0 + 1192U);
    t10 = *((char **)t2);
    t25 = *((unsigned char *)t10);
    t26 = (t25 == (unsigned char)2);
    t4 = t26;
    goto LAB17;

LAB18:    xsi_set_current_line(78, ng0);
    t1 = (t0 + 2472U);
    t10 = *((char **)t1);
    t1 = (t0 + 1512U);
    t11 = *((char **)t1);
    t1 = (t0 + 6884U);
    t5 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t11, t1);
    t7 = (t5 - 31);
    t15 = (t7 * -1);
    xsi_vhdl_check_range_of_index(31, 0, -1, t5);
    t16 = (5U * t15);
    t17 = (0 + t16);
    t12 = (t10 + t17);
    t18 = (t0 + 4520);
    t19 = (t18 + 56U);
    t20 = *((char **)t19);
    t21 = (t20 + 56U);
    t22 = *((char **)t21);
    memcpy(t22, t12, 5U);
    xsi_driver_first_trans_fast_port(t18);
    goto LAB13;

LAB20:    t1 = (t0 + 1032U);
    t6 = *((char **)t1);
    t24 = *((unsigned char *)t6);
    t25 = (t24 == (unsigned char)2);
    t3 = t25;
    goto LAB22;

LAB23:    xsi_set_current_line(80, ng0);
    t1 = (t0 + 1512U);
    t10 = *((char **)t1);
    t1 = (t0 + 1672U);
    t11 = *((char **)t1);
    t26 = 1;
    if (5U == 5U)
        goto LAB31;

LAB32:    t26 = 0;

LAB33:    if (t26 != 0)
        goto LAB28;

LAB30:    xsi_set_current_line(83, ng0);
    t1 = (t0 + 1992U);
    t2 = *((char **)t1);
    t1 = (t0 + 1672U);
    t6 = *((char **)t1);
    t1 = (t0 + 6900U);
    t5 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t6, t1);
    t7 = (t5 - 31);
    t15 = (t7 * -1);
    t16 = (5U * t15);
    t17 = (0U + t16);
    t10 = (t0 + 4392);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    t18 = (t12 + 56U);
    t19 = *((char **)t18);
    memcpy(t19, t2, 5U);
    xsi_driver_first_trans_delta(t10, t17, 5U, 0LL);
    xsi_set_current_line(84, ng0);
    t1 = (t0 + 2472U);
    t2 = *((char **)t1);
    t1 = (t0 + 1512U);
    t6 = *((char **)t1);
    t1 = (t0 + 6884U);
    t5 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t6, t1);
    t7 = (t5 - 31);
    t15 = (t7 * -1);
    xsi_vhdl_check_range_of_index(31, 0, -1, t5);
    t16 = (5U * t15);
    t17 = (0 + t16);
    t10 = (t2 + t17);
    t11 = (t0 + 4520);
    t12 = (t11 + 56U);
    t18 = *((char **)t12);
    t19 = (t18 + 56U);
    t20 = *((char **)t19);
    memcpy(t20, t10, 5U);
    xsi_driver_first_trans_fast_port(t11);

LAB29:    goto LAB13;

LAB25:    t1 = (t0 + 1032U);
    t6 = *((char **)t1);
    t24 = *((unsigned char *)t6);
    t25 = (t24 == (unsigned char)3);
    t3 = t25;
    goto LAB27;

LAB28:    xsi_set_current_line(81, ng0);
    t18 = (t0 + 4456);
    t19 = (t18 + 56U);
    t20 = *((char **)t19);
    t21 = (t20 + 56U);
    t22 = *((char **)t21);
    *((unsigned char *)t22) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t18);
    goto LAB29;

LAB31:    t15 = 0;

LAB34:    if (t15 < 5U)
        goto LAB35;
    else
        goto LAB33;

LAB35:    t1 = (t10 + t15);
    t12 = (t11 + t15);
    if (*((unsigned char *)t1) != *((unsigned char *)t12))
        goto LAB32;

LAB36:    t15 = (t15 + 1);
    goto LAB34;

}


extern void work_a_0279869911_3212880686_init()
{
	static char *pe[] = {(void *)work_a_0279869911_3212880686_p_0};
	xsi_register_didat("work_a_0279869911_3212880686", "isim/tb_ram_dual_port_isim_beh.exe.sim/work/a_0279869911_3212880686.didat");
	xsi_register_executes(pe);
}
