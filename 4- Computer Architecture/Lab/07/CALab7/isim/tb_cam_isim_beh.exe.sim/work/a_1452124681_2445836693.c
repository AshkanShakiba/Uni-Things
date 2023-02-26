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
static const char *ng0 = "D:/lectures/lab/az7/cam.vhd";
extern char *IEEE_P_2592010699;

unsigned char ieee_p_2592010699_sub_1744673427_503743352(char *, char *, unsigned int , unsigned int );


static void work_a_1452124681_2445836693_p_0(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    unsigned char t4;
    int t5;
    char *t6;
    int t7;
    int t8;
    char *t9;
    char *t10;
    int t11;
    int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    unsigned char t21;
    unsigned int t22;
    char *t23;
    char *t24;
    char *t25;
    int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;

LAB0:    xsi_set_current_line(52, ng0);
    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)2);
    if (t4 != 0)
        goto LAB2;

LAB4:    t1 = (t0 + 1472U);
    t3 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t3 != 0)
        goto LAB10;

LAB11:
LAB3:    t1 = (t0 + 3952);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(53, ng0);
    t5 = (16 - 1);
    t1 = (t0 + 6384);
    *((int *)t1) = 0;
    t6 = (t0 + 6388);
    *((int *)t6) = t5;
    t7 = 0;
    t8 = t5;

LAB5:    if (t7 <= t8)
        goto LAB6;

LAB8:    xsi_set_current_line(56, ng0);
    t1 = (t0 + 4096);
    t2 = (t1 + 56U);
    t6 = *((char **)t2);
    t9 = (t6 + 56U);
    t10 = *((char **)t9);
    *((unsigned char *)t10) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    goto LAB3;

LAB6:    xsi_set_current_line(54, ng0);
    t9 = (t0 + 2648U);
    t10 = *((char **)t9);
    t9 = (t0 + 6384);
    t11 = *((int *)t9);
    t12 = (t11 - 15);
    t13 = (t12 * -1);
    t14 = (4U * t13);
    t15 = (0U + t14);
    t16 = (t0 + 4032);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    t19 = (t18 + 56U);
    t20 = *((char **)t19);
    memcpy(t20, t10, 4U);
    xsi_driver_first_trans_delta(t16, t15, 4U, 0LL);

LAB7:    t1 = (t0 + 6384);
    t7 = *((int *)t1);
    t2 = (t0 + 6388);
    t8 = *((int *)t2);
    if (t7 == t8)
        goto LAB8;

LAB9:    t5 = (t7 + 1);
    t7 = t5;
    t6 = (t0 + 6384);
    *((int *)t6) = t7;
    goto LAB5;

LAB10:    xsi_set_current_line(59, ng0);
    t2 = (t0 + 1032U);
    t6 = *((char **)t2);
    t4 = *((unsigned char *)t6);
    t21 = (t4 == (unsigned char)3);
    if (t21 != 0)
        goto LAB12;

LAB14:    t1 = (t0 + 1192U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB30;

LAB31:
LAB13:    goto LAB3;

LAB12:    xsi_set_current_line(60, ng0);
    t2 = (t0 + 4096);
    t9 = (t2 + 56U);
    t10 = *((char **)t9);
    t16 = (t10 + 56U);
    t17 = *((char **)t16);
    *((unsigned char *)t17) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t2);
    xsi_set_current_line(61, ng0);
    t5 = (16 - 1);
    t1 = (t0 + 6392);
    *((int *)t1) = 0;
    t2 = (t0 + 6396);
    *((int *)t2) = t5;
    t7 = 0;
    t8 = t5;

LAB15:    if (t7 <= t8)
        goto LAB16;

LAB18:    goto LAB13;

LAB16:    xsi_set_current_line(62, ng0);
    t6 = (t0 + 1832U);
    t9 = *((char **)t6);
    t6 = (t0 + 1992U);
    t10 = *((char **)t6);
    t6 = (t0 + 6392);
    t11 = *((int *)t6);
    t12 = (t11 - 15);
    t13 = (t12 * -1);
    xsi_vhdl_check_range_of_index(15, 0, -1, *((int *)t6));
    t14 = (4U * t13);
    t15 = (0 + t14);
    t16 = (t10 + t15);
    t3 = 1;
    if (4U == 4U)
        goto LAB22;

LAB23:    t3 = 0;

LAB24:    if (t3 != 0)
        goto LAB19;

LAB21:
LAB20:
LAB17:    t1 = (t0 + 6392);
    t7 = *((int *)t1);
    t2 = (t0 + 6396);
    t8 = *((int *)t2);
    if (t7 == t8)
        goto LAB18;

LAB29:    t5 = (t7 + 1);
    t7 = t5;
    t6 = (t0 + 6392);
    *((int *)t6) = t7;
    goto LAB15;

LAB19:    xsi_set_current_line(64, ng0);
    t19 = (t0 + 4096);
    t20 = (t19 + 56U);
    t23 = *((char **)t20);
    t24 = (t23 + 56U);
    t25 = *((char **)t24);
    *((unsigned char *)t25) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t19);
    xsi_set_current_line(65, ng0);
    goto LAB18;

LAB22:    t22 = 0;

LAB25:    if (t22 < 4U)
        goto LAB26;
    else
        goto LAB24;

LAB26:    t17 = (t9 + t22);
    t18 = (t16 + t22);
    if (*((unsigned char *)t17) != *((unsigned char *)t18))
        goto LAB23;

LAB27:    t22 = (t22 + 1);
    goto LAB25;

LAB28:    goto LAB20;

LAB30:    xsi_set_current_line(70, ng0);
    t5 = (16 - 1);
    t1 = (t0 + 6400);
    *((int *)t1) = 0;
    t6 = (t0 + 6404);
    *((int *)t6) = t5;
    t7 = 0;
    t8 = t5;

LAB32:    if (t7 <= t8)
        goto LAB33;

LAB35:    goto LAB13;

LAB33:    xsi_set_current_line(72, ng0);
    t9 = (t0 + 1832U);
    t10 = *((char **)t9);
    t9 = (t0 + 1992U);
    t16 = *((char **)t9);
    t9 = (t0 + 6400);
    t11 = *((int *)t9);
    t12 = (t11 - 15);
    t13 = (t12 * -1);
    xsi_vhdl_check_range_of_index(15, 0, -1, *((int *)t9));
    t14 = (4U * t13);
    t15 = (0 + t14);
    t17 = (t16 + t15);
    t21 = 1;
    if (4U == 4U)
        goto LAB39;

LAB40:    t21 = 0;

LAB41:    if (t21 != 0)
        goto LAB36;

LAB38:    t1 = (t0 + 2648U);
    t2 = *((char **)t1);
    t1 = (t0 + 1992U);
    t6 = *((char **)t1);
    t1 = (t0 + 6400);
    t5 = *((int *)t1);
    t11 = (t5 - 15);
    t13 = (t11 * -1);
    xsi_vhdl_check_range_of_index(15, 0, -1, *((int *)t1));
    t14 = (4U * t13);
    t15 = (0 + t14);
    t9 = (t6 + t15);
    t3 = 1;
    if (4U == 4U)
        goto LAB48;

LAB49:    t3 = 0;

LAB50:    if (t3 != 0)
        goto LAB46;

LAB47:
LAB37:
LAB34:    t1 = (t0 + 6400);
    t7 = *((int *)t1);
    t2 = (t0 + 6404);
    t8 = *((int *)t2);
    if (t7 == t8)
        goto LAB35;

LAB55:    t5 = (t7 + 1);
    t7 = t5;
    t6 = (t0 + 6400);
    *((int *)t6) = t7;
    goto LAB32;

LAB36:    xsi_set_current_line(73, ng0);
    goto LAB35;

LAB39:    t22 = 0;

LAB42:    if (t22 < 4U)
        goto LAB43;
    else
        goto LAB41;

LAB43:    t18 = (t10 + t22);
    t19 = (t17 + t22);
    if (*((unsigned char *)t18) != *((unsigned char *)t19))
        goto LAB40;

LAB44:    t22 = (t22 + 1);
    goto LAB42;

LAB45:    goto LAB37;

LAB46:    xsi_set_current_line(76, ng0);
    t17 = (t0 + 1832U);
    t18 = *((char **)t17);
    t17 = (t0 + 6400);
    t12 = *((int *)t17);
    t26 = (t12 - 15);
    t27 = (t26 * -1);
    t28 = (4U * t27);
    t29 = (0U + t28);
    t19 = (t0 + 4032);
    t20 = (t19 + 56U);
    t23 = *((char **)t20);
    t24 = (t23 + 56U);
    t25 = *((char **)t24);
    memcpy(t25, t18, 4U);
    xsi_driver_first_trans_delta(t19, t29, 4U, 0LL);
    xsi_set_current_line(77, ng0);
    goto LAB35;

LAB48:    t22 = 0;

LAB51:    if (t22 < 4U)
        goto LAB52;
    else
        goto LAB50;

LAB52:    t10 = (t2 + t22);
    t16 = (t9 + t22);
    if (*((unsigned char *)t10) != *((unsigned char *)t16))
        goto LAB49;

LAB53:    t22 = (t22 + 1);
    goto LAB51;

LAB54:    goto LAB37;

}


extern void work_a_1452124681_2445836693_init()
{
	static char *pe[] = {(void *)work_a_1452124681_2445836693_p_0};
	xsi_register_didat("work_a_1452124681_2445836693", "isim/tb_cam_isim_beh.exe.sim/work/a_1452124681_2445836693.didat");
	xsi_register_executes(pe);
}
