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
static const char *ng0 = "D:/lectures/lab/az7/tb_ram.vhd";
extern char *IEEE_P_3620187407;

char *ieee_p_3620187407_sub_767668596_3965413181(char *, char *, char *, char *, char *, char *);


static void work_a_0786852910_2372691052_p_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    int64 t7;
    int64 t8;

LAB0:    t1 = (t0 + 3512U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(91, ng0);
    t2 = (t0 + 4144);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(92, ng0);
    t2 = (t0 + 2528U);
    t3 = *((char **)t2);
    t7 = *((int64 *)t3);
    t8 = (t7 / 2);
    t2 = (t0 + 3320);
    xsi_process_wait(t2, t8);

LAB6:    *((char **)t1) = &&LAB7;

LAB1:    return;
LAB4:    xsi_set_current_line(93, ng0);
    t2 = (t0 + 4144);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(94, ng0);
    t2 = (t0 + 2528U);
    t3 = *((char **)t2);
    t7 = *((int64 *)t3);
    t8 = (t7 / 2);
    t2 = (t0 + 3320);
    xsi_process_wait(t2, t8);

LAB10:    *((char **)t1) = &&LAB11;
    goto LAB1;

LAB5:    goto LAB4;

LAB7:    goto LAB5;

LAB8:    goto LAB2;

LAB9:    goto LAB8;

LAB11:    goto LAB9;

}

static void work_a_0786852910_2372691052_p_1(char *t0)
{
    char t13[16];
    char t14[16];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    int64 t9;
    int t10;
    int t11;
    int t12;
    char *t15;
    char *t16;
    int t17;
    unsigned int t18;
    char *t19;
    unsigned int t20;
    unsigned char t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    int64 t27;

LAB0:    t1 = (t0 + 3760U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(101, ng0);
    t2 = (t0 + 4208);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(103, ng0);
    t2 = (t0 + 4272);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(104, ng0);
    t2 = (t0 + 4336);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(105, ng0);
    t2 = (t0 + 6644);
    t4 = (t0 + 4400);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t2, 2U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(106, ng0);
    t2 = (t0 + 6646);
    t4 = (t0 + 4464);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t2, 8U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(108, ng0);
    t9 = (100 * 1000LL);
    t2 = (t0 + 3568);
    xsi_process_wait(t2, t9);

LAB6:    *((char **)t1) = &&LAB7;

LAB1:    return;
LAB4:    xsi_set_current_line(109, ng0);
    t2 = (t0 + 2408U);
    t3 = *((char **)t2);
    t10 = *((int *)t3);
    t2 = (t0 + 6654);
    *((int *)t2) = 0;
    t4 = (t0 + 6658);
    *((int *)t4) = t10;
    t11 = 0;
    t12 = t10;

LAB8:    if (t11 <= t12)
        goto LAB9;

LAB11:    xsi_set_current_line(117, ng0);
    t2 = (t0 + 4272);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(118, ng0);
    t2 = (t0 + 4336);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(119, ng0);
    t2 = (t0 + 6672);
    t4 = (t0 + 4400);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t2, 2U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(120, ng0);
    t9 = (100 * 1000LL);
    t2 = (t0 + 3568);
    xsi_process_wait(t2, t9);

LAB23:    *((char **)t1) = &&LAB24;
    goto LAB1;

LAB5:    goto LAB4;

LAB7:    goto LAB5;

LAB9:    xsi_set_current_line(110, ng0);
    t5 = (t0 + 1192U);
    t6 = *((char **)t5);
    t5 = (t0 + 6564U);
    t7 = (t0 + 6662);
    t15 = (t14 + 0U);
    t16 = (t15 + 0U);
    *((int *)t16) = 0;
    t16 = (t15 + 4U);
    *((int *)t16) = 1;
    t16 = (t15 + 8U);
    *((int *)t16) = 1;
    t17 = (1 - 0);
    t18 = (t17 * 1);
    t18 = (t18 + 1);
    t16 = (t15 + 12U);
    *((unsigned int *)t16) = t18;
    t16 = ieee_p_3620187407_sub_767668596_3965413181(IEEE_P_3620187407, t13, t6, t5, t7, t14);
    t19 = (t13 + 12U);
    t18 = *((unsigned int *)t19);
    t20 = (1U * t18);
    t21 = (2U != t20);
    if (t21 == 1)
        goto LAB12;

LAB13:    t22 = (t0 + 4400);
    t23 = (t22 + 56U);
    t24 = *((char **)t23);
    t25 = (t24 + 56U);
    t26 = *((char **)t25);
    memcpy(t26, t16, 2U);
    xsi_driver_first_trans_fast(t22);
    xsi_set_current_line(111, ng0);
    t2 = (t0 + 1032U);
    t3 = *((char **)t2);
    t2 = (t0 + 6548U);
    t4 = (t0 + 6664);
    t6 = (t14 + 0U);
    t7 = (t6 + 0U);
    *((int *)t7) = 0;
    t7 = (t6 + 4U);
    *((int *)t7) = 7;
    t7 = (t6 + 8U);
    *((int *)t7) = 1;
    t10 = (7 - 0);
    t18 = (t10 * 1);
    t18 = (t18 + 1);
    t7 = (t6 + 12U);
    *((unsigned int *)t7) = t18;
    t7 = ieee_p_3620187407_sub_767668596_3965413181(IEEE_P_3620187407, t13, t3, t2, t4, t14);
    t8 = (t13 + 12U);
    t18 = *((unsigned int *)t8);
    t20 = (1U * t18);
    t21 = (8U != t20);
    if (t21 == 1)
        goto LAB14;

LAB15:    t15 = (t0 + 4464);
    t16 = (t15 + 56U);
    t19 = *((char **)t16);
    t22 = (t19 + 56U);
    t23 = *((char **)t22);
    memcpy(t23, t7, 8U);
    xsi_driver_first_trans_fast(t15);
    xsi_set_current_line(112, ng0);
    t2 = (t0 + 2528U);
    t3 = *((char **)t2);
    t9 = *((int64 *)t3);
    t27 = (t9 * 5);
    t2 = (t0 + 3568);
    xsi_process_wait(t2, t27);

LAB18:    *((char **)t1) = &&LAB19;
    goto LAB1;

LAB10:    t2 = (t0 + 6654);
    t11 = *((int *)t2);
    t3 = (t0 + 6658);
    t12 = *((int *)t3);
    if (t11 == t12)
        goto LAB11;

LAB20:    t10 = (t11 + 1);
    t11 = t10;
    t4 = (t0 + 6654);
    *((int *)t4) = t11;
    goto LAB8;

LAB12:    xsi_size_not_matching(2U, t20, 0);
    goto LAB13;

LAB14:    xsi_size_not_matching(8U, t20, 0);
    goto LAB15;

LAB16:    goto LAB10;

LAB17:    goto LAB16;

LAB19:    goto LAB17;

LAB21:    xsi_set_current_line(121, ng0);
    t2 = (t0 + 2408U);
    t3 = *((char **)t2);
    t10 = *((int *)t3);
    t2 = (t0 + 6674);
    *((int *)t2) = 0;
    t4 = (t0 + 6678);
    *((int *)t4) = t10;
    t11 = 0;
    t12 = t10;

LAB25:    if (t11 <= t12)
        goto LAB26;

LAB28:    xsi_set_current_line(125, ng0);
    t9 = (100 * 1000LL);
    t2 = (t0 + 3568);
    xsi_process_wait(t2, t9);

LAB38:    *((char **)t1) = &&LAB39;
    goto LAB1;

LAB22:    goto LAB21;

LAB24:    goto LAB22;

LAB26:    xsi_set_current_line(122, ng0);
    t5 = (t0 + 1192U);
    t6 = *((char **)t5);
    t5 = (t0 + 6564U);
    t7 = (t0 + 6682);
    t15 = (t14 + 0U);
    t16 = (t15 + 0U);
    *((int *)t16) = 0;
    t16 = (t15 + 4U);
    *((int *)t16) = 1;
    t16 = (t15 + 8U);
    *((int *)t16) = 1;
    t17 = (1 - 0);
    t18 = (t17 * 1);
    t18 = (t18 + 1);
    t16 = (t15 + 12U);
    *((unsigned int *)t16) = t18;
    t16 = ieee_p_3620187407_sub_767668596_3965413181(IEEE_P_3620187407, t13, t6, t5, t7, t14);
    t19 = (t13 + 12U);
    t18 = *((unsigned int *)t19);
    t20 = (1U * t18);
    t21 = (2U != t20);
    if (t21 == 1)
        goto LAB29;

LAB30:    t22 = (t0 + 4400);
    t23 = (t22 + 56U);
    t24 = *((char **)t23);
    t25 = (t24 + 56U);
    t26 = *((char **)t25);
    memcpy(t26, t16, 2U);
    xsi_driver_first_trans_fast(t22);
    xsi_set_current_line(123, ng0);
    t2 = (t0 + 2528U);
    t3 = *((char **)t2);
    t9 = *((int64 *)t3);
    t27 = (t9 * 5);
    t2 = (t0 + 3568);
    xsi_process_wait(t2, t27);

LAB33:    *((char **)t1) = &&LAB34;
    goto LAB1;

LAB27:    t2 = (t0 + 6674);
    t11 = *((int *)t2);
    t3 = (t0 + 6678);
    t12 = *((int *)t3);
    if (t11 == t12)
        goto LAB28;

LAB35:    t10 = (t11 + 1);
    t11 = t10;
    t4 = (t0 + 6674);
    *((int *)t4) = t11;
    goto LAB25;

LAB29:    xsi_size_not_matching(2U, t20, 0);
    goto LAB30;

LAB31:    goto LAB27;

LAB32:    goto LAB31;

LAB34:    goto LAB32;

LAB36:    xsi_set_current_line(127, ng0);
    t2 = (t0 + 4208);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(128, ng0);
    t9 = (300 * 1000LL);
    t2 = (t0 + 3568);
    xsi_process_wait(t2, t9);

LAB42:    *((char **)t1) = &&LAB43;
    goto LAB1;

LAB37:    goto LAB36;

LAB39:    goto LAB37;

LAB40:    xsi_set_current_line(131, ng0);
    t2 = (t0 + 4208);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(133, ng0);
    t2 = (t0 + 4272);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(134, ng0);
    t2 = (t0 + 4336);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(135, ng0);
    t2 = (t0 + 6684);
    t4 = (t0 + 4400);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t2, 2U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(136, ng0);
    t9 = (100 * 1000LL);
    t2 = (t0 + 3568);
    xsi_process_wait(t2, t9);

LAB46:    *((char **)t1) = &&LAB47;
    goto LAB1;

LAB41:    goto LAB40;

LAB43:    goto LAB41;

LAB44:    xsi_set_current_line(137, ng0);
    t2 = (t0 + 2408U);
    t3 = *((char **)t2);
    t10 = *((int *)t3);
    t2 = (t0 + 6686);
    *((int *)t2) = 0;
    t4 = (t0 + 6690);
    *((int *)t4) = t10;
    t11 = 0;
    t12 = t10;

LAB48:    if (t11 <= t12)
        goto LAB49;

LAB51:    xsi_set_current_line(143, ng0);

LAB61:    *((char **)t1) = &&LAB62;
    goto LAB1;

LAB45:    goto LAB44;

LAB47:    goto LAB45;

LAB49:    xsi_set_current_line(138, ng0);
    t5 = (t0 + 1192U);
    t6 = *((char **)t5);
    t5 = (t0 + 6564U);
    t7 = (t0 + 6694);
    t15 = (t14 + 0U);
    t16 = (t15 + 0U);
    *((int *)t16) = 0;
    t16 = (t15 + 4U);
    *((int *)t16) = 1;
    t16 = (t15 + 8U);
    *((int *)t16) = 1;
    t17 = (1 - 0);
    t18 = (t17 * 1);
    t18 = (t18 + 1);
    t16 = (t15 + 12U);
    *((unsigned int *)t16) = t18;
    t16 = ieee_p_3620187407_sub_767668596_3965413181(IEEE_P_3620187407, t13, t6, t5, t7, t14);
    t19 = (t13 + 12U);
    t18 = *((unsigned int *)t19);
    t20 = (1U * t18);
    t21 = (2U != t20);
    if (t21 == 1)
        goto LAB52;

LAB53:    t22 = (t0 + 4400);
    t23 = (t22 + 56U);
    t24 = *((char **)t23);
    t25 = (t24 + 56U);
    t26 = *((char **)t25);
    memcpy(t26, t16, 2U);
    xsi_driver_first_trans_fast(t22);
    xsi_set_current_line(139, ng0);
    t2 = (t0 + 2528U);
    t3 = *((char **)t2);
    t9 = *((int64 *)t3);
    t27 = (t9 * 5);
    t2 = (t0 + 3568);
    xsi_process_wait(t2, t27);

LAB56:    *((char **)t1) = &&LAB57;
    goto LAB1;

LAB50:    t2 = (t0 + 6686);
    t11 = *((int *)t2);
    t3 = (t0 + 6690);
    t12 = *((int *)t3);
    if (t11 == t12)
        goto LAB51;

LAB58:    t10 = (t11 + 1);
    t11 = t10;
    t4 = (t0 + 6686);
    *((int *)t4) = t11;
    goto LAB48;

LAB52:    xsi_size_not_matching(2U, t20, 0);
    goto LAB53;

LAB54:    goto LAB50;

LAB55:    goto LAB54;

LAB57:    goto LAB55;

LAB59:    goto LAB2;

LAB60:    goto LAB59;

LAB62:    goto LAB60;

}


extern void work_a_0786852910_2372691052_init()
{
	static char *pe[] = {(void *)work_a_0786852910_2372691052_p_0,(void *)work_a_0786852910_2372691052_p_1};
	xsi_register_didat("work_a_0786852910_2372691052", "isim/tb_ram_isim_beh.exe.sim/work/a_0786852910_2372691052.didat");
	xsi_register_executes(pe);
}
