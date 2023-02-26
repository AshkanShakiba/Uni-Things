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
static const char *ng0 = "D:/lectures/lab/az7/ram.vhd";
extern char *IEEE_P_2592010699;
extern char *IEEE_P_1242562249;

int ieee_p_1242562249_sub_1657552908_1035706684(char *, char *, char *);
char *ieee_p_1242562249_sub_180853171_1035706684(char *, char *, int , int );
unsigned char ieee_p_2592010699_sub_1744673427_503743352(char *, char *, unsigned int , unsigned int );


static void work_a_0222381836_3212880686_p_0(char *t0)
{
    char t28[16];
    char *t1;
    char *t2;
    unsigned char t3;
    unsigned char t4;
    unsigned char t5;
    unsigned char t6;
    char *t7;
    char *t8;
    unsigned char t9;
    unsigned char t10;
    char *t11;
    unsigned char t12;
    unsigned char t13;
    char *t14;
    char *t15;
    int t16;
    int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    int t26;
    int t27;
    int t29;
    int t30;

LAB0:    xsi_set_current_line(58, ng0);
    t1 = (t0 + 1832U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB2;

LAB4:    t1 = (t0 + 1832U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)2);
    if (t4 != 0)
        goto LAB19;

LAB20:
LAB3:    t1 = (t0 + 3872);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(59, ng0);
    t1 = (t0 + 1312U);
    t5 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t5 != 0)
        goto LAB5;

LAB7:
LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(60, ng0);
    t7 = (t0 + 1512U);
    t8 = *((char **)t7);
    t9 = *((unsigned char *)t8);
    t10 = (t9 == (unsigned char)3);
    if (t10 == 1)
        goto LAB11;

LAB12:    t6 = (unsigned char)0;

LAB13:    if (t6 != 0)
        goto LAB8;

LAB10:    t1 = (t0 + 1672U);
    t2 = *((char **)t1);
    t4 = *((unsigned char *)t2);
    t5 = (t4 == (unsigned char)3);
    if (t5 == 1)
        goto LAB16;

LAB17:    t3 = (unsigned char)0;

LAB18:    if (t3 != 0)
        goto LAB14;

LAB15:
LAB9:    goto LAB6;

LAB8:    xsi_set_current_line(61, ng0);
    t7 = (t0 + 1032U);
    t14 = *((char **)t7);
    t7 = (t0 + 1192U);
    t15 = *((char **)t7);
    t7 = (t0 + 6116U);
    t16 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t15, t7);
    t17 = (t16 - 3);
    t18 = (t17 * -1);
    t19 = (8U * t18);
    t20 = (0U + t19);
    t21 = (t0 + 3952);
    t22 = (t21 + 56U);
    t23 = *((char **)t22);
    t24 = (t23 + 56U);
    t25 = *((char **)t24);
    memcpy(t25, t14, 8U);
    xsi_driver_first_trans_delta(t21, t20, 8U, 0LL);
    goto LAB9;

LAB11:    t7 = (t0 + 1672U);
    t11 = *((char **)t7);
    t12 = *((unsigned char *)t11);
    t13 = (t12 == (unsigned char)2);
    t6 = t13;
    goto LAB13;

LAB14:    xsi_set_current_line(63, ng0);
    t1 = (t0 + 2152U);
    t8 = *((char **)t1);
    t1 = (t0 + 1192U);
    t11 = *((char **)t1);
    t1 = (t0 + 6116U);
    t16 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t11, t1);
    t17 = (t16 - 3);
    t18 = (t17 * -1);
    xsi_vhdl_check_range_of_index(3, 0, -1, t16);
    t19 = (8U * t18);
    t20 = (0 + t19);
    t14 = (t8 + t20);
    t15 = (t0 + 4016);
    t21 = (t15 + 56U);
    t22 = *((char **)t21);
    t23 = (t22 + 56U);
    t24 = *((char **)t23);
    memcpy(t24, t14, 8U);
    xsi_driver_first_trans_fast_port(t15);
    goto LAB9;

LAB16:    t1 = (t0 + 1512U);
    t7 = *((char **)t1);
    t6 = *((unsigned char *)t7);
    t9 = (t6 == (unsigned char)2);
    t3 = t9;
    goto LAB18;

LAB19:    xsi_set_current_line(67, ng0);
    t16 = xsi_vhdl_pow(2, 2);
    t17 = (t16 - 1);
    t1 = (t0 + 6242);
    *((int *)t1) = 0;
    t7 = (t0 + 6246);
    *((int *)t7) = t17;
    t26 = 0;
    t27 = t17;

LAB21:    if (t26 <= t27)
        goto LAB22;

LAB24:    goto LAB3;

LAB22:    xsi_set_current_line(68, ng0);
    t8 = (t0 + 6242);
    t11 = ieee_p_1242562249_sub_180853171_1035706684(IEEE_P_1242562249, t28, *((int *)t8), 8);
    t14 = (t0 + 6242);
    t29 = *((int *)t14);
    t30 = (t29 - 3);
    t18 = (t30 * -1);
    t19 = (8U * t18);
    t20 = (0U + t19);
    t15 = (t0 + 3952);
    t21 = (t15 + 56U);
    t22 = *((char **)t21);
    t23 = (t22 + 56U);
    t24 = *((char **)t23);
    memcpy(t24, t11, 8U);
    xsi_driver_first_trans_delta(t15, t20, 8U, 0LL);

LAB23:    t1 = (t0 + 6242);
    t26 = *((int *)t1);
    t2 = (t0 + 6246);
    t27 = *((int *)t2);
    if (t26 == t27)
        goto LAB24;

LAB25:    t16 = (t26 + 1);
    t26 = t16;
    t7 = (t0 + 6242);
    *((int *)t7) = t26;
    goto LAB21;

}


extern void work_a_0222381836_3212880686_init()
{
	static char *pe[] = {(void *)work_a_0222381836_3212880686_p_0};
	xsi_register_didat("work_a_0222381836_3212880686", "isim/tb_ram_isim_beh.exe.sim/work/a_0222381836_3212880686.didat");
	xsi_register_executes(pe);
}
