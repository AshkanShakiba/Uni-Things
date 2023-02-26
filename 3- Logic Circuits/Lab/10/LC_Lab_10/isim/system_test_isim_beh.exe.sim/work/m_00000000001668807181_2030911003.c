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
static const char *ng0 = "E:/University/LC Lab/Codes/LC_Lab_10/fsm.v";
static unsigned int ng1[] = {0U, 0U};
static unsigned int ng2[] = {1U, 0U};
static unsigned int ng3[] = {15U, 0U};
static unsigned int ng4[] = {5U, 0U};
static unsigned int ng5[] = {7U, 0U};
static unsigned int ng6[] = {6U, 0U};
static int ng7[] = {1, 0};
static int ng8[] = {0, 0};



static void Always_44_0(char *t0)
{
    char t4[8];
    char t40[8];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    char *t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    char *t13;
    char *t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    char *t29;
    char *t30;
    int t31;
    char *t32;
    char *t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    char *t38;
    char *t39;
    unsigned int t41;
    unsigned int t42;

LAB0:    t1 = (t0 + 4144U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(44, ng0);
    t2 = (t0 + 4464);
    *((int *)t2) = 1;
    t3 = (t0 + 4176);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(45, ng0);

LAB5:    xsi_set_current_line(46, ng0);
    t5 = (t0 + 1864U);
    t6 = *((char **)t5);
    memset(t4, 0, 8);
    t5 = (t6 + 4);
    t7 = *((unsigned int *)t5);
    t8 = (~(t7));
    t9 = *((unsigned int *)t6);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB9;

LAB7:    if (*((unsigned int *)t5) == 0)
        goto LAB6;

LAB8:    t12 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t12) = 1;

LAB9:    t13 = (t4 + 4);
    t14 = (t6 + 4);
    t15 = *((unsigned int *)t6);
    t16 = (~(t15));
    *((unsigned int *)t4) = t16;
    *((unsigned int *)t13) = 0;
    if (*((unsigned int *)t14) != 0)
        goto LAB11;

LAB10:    t21 = *((unsigned int *)t4);
    *((unsigned int *)t4) = (t21 & 1U);
    t22 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t22 & 1U);
    t23 = (t4 + 4);
    t24 = *((unsigned int *)t23);
    t25 = (~(t24));
    t26 = *((unsigned int *)t4);
    t27 = (t26 & t25);
    t28 = (t27 != 0);
    if (t28 > 0)
        goto LAB12;

LAB13:    xsi_set_current_line(50, ng0);
    t2 = (t0 + 3224);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);

LAB15:    t6 = ((char*)((ng2)));
    t31 = xsi_vlog_unsigned_case_compare(t5, 3, t6, 3);
    if (t31 == 1)
        goto LAB16;

LAB17:    t2 = ((char*)((ng1)));
    t31 = xsi_vlog_unsigned_case_compare(t5, 3, t2, 3);
    if (t31 == 1)
        goto LAB18;

LAB19:    t2 = ((char*)((ng6)));
    t31 = xsi_vlog_unsigned_case_compare(t5, 3, t2, 3);
    if (t31 == 1)
        goto LAB20;

LAB21:    t2 = ((char*)((ng5)));
    t31 = xsi_vlog_unsigned_case_compare(t5, 3, t2, 3);
    if (t31 == 1)
        goto LAB22;

LAB23:    t2 = ((char*)((ng4)));
    t31 = xsi_vlog_unsigned_case_compare(t5, 3, t2, 3);
    if (t31 == 1)
        goto LAB24;

LAB25:
LAB26:
LAB14:    goto LAB2;

LAB6:    *((unsigned int *)t4) = 1;
    goto LAB9;

LAB11:    t17 = *((unsigned int *)t4);
    t18 = *((unsigned int *)t14);
    *((unsigned int *)t4) = (t17 | t18);
    t19 = *((unsigned int *)t13);
    t20 = *((unsigned int *)t14);
    *((unsigned int *)t13) = (t19 | t20);
    goto LAB10;

LAB12:    xsi_set_current_line(47, ng0);
    t29 = ((char*)((ng1)));
    t30 = (t0 + 3224);
    xsi_vlogvar_assign_value(t30, t29, 0, 0, 3);
    goto LAB14;

LAB16:    xsi_set_current_line(52, ng0);

LAB27:    xsi_set_current_line(53, ng0);
    t12 = (t0 + 2184U);
    t13 = *((char **)t12);
    t12 = (t13 + 4);
    t7 = *((unsigned int *)t12);
    t8 = (~(t7));
    t9 = *((unsigned int *)t13);
    t10 = (t9 & t8);
    t11 = (t10 != 0);
    if (t11 > 0)
        goto LAB28;

LAB29:
LAB30:    xsi_set_current_line(58, ng0);
    t2 = (t0 + 2184U);
    t3 = *((char **)t2);
    memset(t4, 0, 8);
    t2 = (t3 + 4);
    t7 = *((unsigned int *)t2);
    t8 = (~(t7));
    t9 = *((unsigned int *)t3);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB49;

LAB47:    if (*((unsigned int *)t2) == 0)
        goto LAB46;

LAB48:    t6 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t6) = 1;

LAB49:    t12 = (t4 + 4);
    t13 = (t3 + 4);
    t15 = *((unsigned int *)t3);
    t16 = (~(t15));
    *((unsigned int *)t4) = t16;
    *((unsigned int *)t12) = 0;
    if (*((unsigned int *)t13) != 0)
        goto LAB51;

LAB50:    t21 = *((unsigned int *)t4);
    *((unsigned int *)t4) = (t21 & 1U);
    t22 = *((unsigned int *)t12);
    *((unsigned int *)t12) = (t22 & 1U);
    t14 = (t4 + 4);
    t24 = *((unsigned int *)t14);
    t25 = (~(t24));
    t26 = *((unsigned int *)t4);
    t27 = (t26 & t25);
    t28 = (t27 != 0);
    if (t28 > 0)
        goto LAB52;

LAB53:
LAB54:    goto LAB26;

LAB18:    xsi_set_current_line(61, ng0);
    t3 = ((char*)((ng2)));
    t6 = (t0 + 3224);
    xsi_vlogvar_assign_value(t6, t3, 0, 0, 3);
    goto LAB26;

LAB20:    xsi_set_current_line(63, ng0);
    t3 = ((char*)((ng6)));
    t6 = (t0 + 3224);
    xsi_vlogvar_assign_value(t6, t3, 0, 0, 3);
    goto LAB26;

LAB22:    xsi_set_current_line(65, ng0);
    t3 = ((char*)((ng5)));
    t6 = (t0 + 3224);
    xsi_vlogvar_assign_value(t6, t3, 0, 0, 3);
    goto LAB26;

LAB24:    xsi_set_current_line(68, ng0);

LAB55:    xsi_set_current_line(69, ng0);
    t3 = ((char*)((ng6)));
    t6 = (t0 + 3224);
    xsi_vlogvar_assign_value(t6, t3, 0, 0, 3);
    xsi_set_current_line(70, ng0);
    t2 = (t0 + 2184U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t7 = *((unsigned int *)t2);
    t8 = (~(t7));
    t9 = *((unsigned int *)t3);
    t10 = (t9 & t8);
    t11 = (t10 != 0);
    if (t11 > 0)
        goto LAB56;

LAB57:
LAB58:    xsi_set_current_line(85, ng0);
    t2 = (t0 + 2184U);
    t3 = *((char **)t2);
    memset(t4, 0, 8);
    t2 = (t3 + 4);
    t7 = *((unsigned int *)t2);
    t8 = (~(t7));
    t9 = *((unsigned int *)t3);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB77;

LAB75:    if (*((unsigned int *)t2) == 0)
        goto LAB74;

LAB76:    t6 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t6) = 1;

LAB77:    t12 = (t4 + 4);
    t13 = (t3 + 4);
    t15 = *((unsigned int *)t3);
    t16 = (~(t15));
    *((unsigned int *)t4) = t16;
    *((unsigned int *)t12) = 0;
    if (*((unsigned int *)t13) != 0)
        goto LAB79;

LAB78:    t21 = *((unsigned int *)t4);
    *((unsigned int *)t4) = (t21 & 1U);
    t22 = *((unsigned int *)t12);
    *((unsigned int *)t12) = (t22 & 1U);
    t14 = (t4 + 4);
    t24 = *((unsigned int *)t14);
    t25 = (~(t24));
    t26 = *((unsigned int *)t4);
    t27 = (t26 & t25);
    t28 = (t27 != 0);
    if (t28 > 0)
        goto LAB80;

LAB81:
LAB82:    goto LAB26;

LAB28:    xsi_set_current_line(54, ng0);

LAB31:    xsi_set_current_line(55, ng0);
    t14 = ((char*)((ng3)));
    t23 = (t0 + 2344U);
    t29 = *((char **)t23);
    memset(t4, 0, 8);
    t23 = (t14 + 4);
    t30 = (t29 + 4);
    t15 = *((unsigned int *)t14);
    t16 = *((unsigned int *)t29);
    t17 = (t15 ^ t16);
    t18 = *((unsigned int *)t23);
    t19 = *((unsigned int *)t30);
    t20 = (t18 ^ t19);
    t21 = (t17 | t20);
    t22 = *((unsigned int *)t23);
    t24 = *((unsigned int *)t30);
    t25 = (t22 | t24);
    t26 = (~(t25));
    t27 = (t21 & t26);
    if (t27 != 0)
        goto LAB35;

LAB32:    if (t25 != 0)
        goto LAB34;

LAB33:    *((unsigned int *)t4) = 1;

LAB35:    t33 = (t4 + 4);
    t28 = *((unsigned int *)t33);
    t34 = (~(t28));
    t35 = *((unsigned int *)t4);
    t36 = (t35 & t34);
    t37 = (t36 != 0);
    if (t37 > 0)
        goto LAB36;

LAB37:
LAB38:    xsi_set_current_line(56, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 2344U);
    t6 = *((char **)t3);
    memset(t4, 0, 8);
    t3 = (t2 + 4);
    t12 = (t6 + 4);
    t7 = *((unsigned int *)t2);
    t8 = *((unsigned int *)t6);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t3);
    t11 = *((unsigned int *)t12);
    t15 = (t10 ^ t11);
    t16 = (t9 | t15);
    t17 = *((unsigned int *)t3);
    t18 = *((unsigned int *)t12);
    t19 = (t17 | t18);
    t20 = (~(t19));
    t21 = (t16 & t20);
    if (t21 != 0)
        goto LAB40;

LAB39:    if (t19 != 0)
        goto LAB41;

LAB42:    t14 = (t4 + 4);
    t22 = *((unsigned int *)t14);
    t24 = (~(t22));
    t25 = *((unsigned int *)t4);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB43;

LAB44:
LAB45:    goto LAB30;

LAB34:    t32 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t32) = 1;
    goto LAB35;

LAB36:    xsi_set_current_line(55, ng0);
    t38 = ((char*)((ng4)));
    t39 = (t0 + 3224);
    xsi_vlogvar_assign_value(t39, t38, 0, 0, 3);
    goto LAB38;

LAB40:    *((unsigned int *)t4) = 1;
    goto LAB42;

LAB41:    t13 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t13) = 1;
    goto LAB42;

LAB43:    xsi_set_current_line(56, ng0);
    t23 = ((char*)((ng5)));
    t29 = (t0 + 3224);
    xsi_vlogvar_assign_value(t29, t23, 0, 0, 3);
    goto LAB45;

LAB46:    *((unsigned int *)t4) = 1;
    goto LAB49;

LAB51:    t17 = *((unsigned int *)t4);
    t18 = *((unsigned int *)t13);
    *((unsigned int *)t4) = (t17 | t18);
    t19 = *((unsigned int *)t12);
    t20 = *((unsigned int *)t13);
    *((unsigned int *)t12) = (t19 | t20);
    goto LAB50;

LAB52:    xsi_set_current_line(58, ng0);
    t23 = ((char*)((ng2)));
    t29 = (t0 + 3224);
    xsi_vlogvar_assign_value(t29, t23, 0, 0, 3);
    goto LAB54;

LAB56:    xsi_set_current_line(71, ng0);

LAB59:    xsi_set_current_line(72, ng0);
    t6 = (t0 + 2344U);
    t12 = *((char **)t6);
    memset(t4, 0, 8);
    t6 = (t4 + 4);
    t13 = (t12 + 4);
    t15 = *((unsigned int *)t12);
    t16 = (t15 >> 0);
    t17 = (t16 & 1);
    *((unsigned int *)t4) = t17;
    t18 = *((unsigned int *)t13);
    t19 = (t18 >> 0);
    t20 = (t19 & 1);
    *((unsigned int *)t6) = t20;
    t14 = (t4 + 4);
    t21 = *((unsigned int *)t14);
    t22 = (~(t21));
    t24 = *((unsigned int *)t4);
    t25 = (t24 & t22);
    t26 = (t25 != 0);
    if (t26 > 0)
        goto LAB60;

LAB61:
LAB62:    xsi_set_current_line(78, ng0);
    t2 = (t0 + 2344U);
    t3 = *((char **)t2);
    memset(t40, 0, 8);
    t2 = (t40 + 4);
    t6 = (t3 + 4);
    t7 = *((unsigned int *)t3);
    t8 = (t7 >> 0);
    t9 = (t8 & 1);
    *((unsigned int *)t40) = t9;
    t10 = *((unsigned int *)t6);
    t11 = (t10 >> 0);
    t15 = (t11 & 1);
    *((unsigned int *)t2) = t15;
    memset(t4, 0, 8);
    t12 = (t40 + 4);
    t16 = *((unsigned int *)t12);
    t17 = (~(t16));
    t18 = *((unsigned int *)t40);
    t19 = (t18 & t17);
    t20 = (t19 & 1U);
    if (t20 != 0)
        goto LAB67;

LAB65:    if (*((unsigned int *)t12) == 0)
        goto LAB64;

LAB66:    t13 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t13) = 1;

LAB67:    t14 = (t4 + 4);
    t23 = (t40 + 4);
    t21 = *((unsigned int *)t40);
    t22 = (~(t21));
    *((unsigned int *)t4) = t22;
    *((unsigned int *)t14) = 0;
    if (*((unsigned int *)t23) != 0)
        goto LAB69;

LAB68:    t28 = *((unsigned int *)t4);
    *((unsigned int *)t4) = (t28 & 1U);
    t34 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t34 & 1U);
    t29 = (t4 + 4);
    t35 = *((unsigned int *)t29);
    t36 = (~(t35));
    t37 = *((unsigned int *)t4);
    t41 = (t37 & t36);
    t42 = (t41 != 0);
    if (t42 > 0)
        goto LAB70;

LAB71:
LAB72:    goto LAB58;

LAB60:    xsi_set_current_line(73, ng0);

LAB63:    xsi_set_current_line(74, ng0);
    t23 = ((char*)((ng7)));
    t29 = (t0 + 2744);
    xsi_vlogvar_assign_value(t29, t23, 0, 0, 1);
    xsi_set_current_line(75, ng0);
    t2 = ((char*)((ng8)));
    t3 = (t0 + 2904);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(76, ng0);
    t2 = (t0 + 2344U);
    t3 = *((char **)t2);
    t2 = (t0 + 3064);
    xsi_vlogvar_assign_value(t2, t3, 0, 0, 4);
    goto LAB62;

LAB64:    *((unsigned int *)t4) = 1;
    goto LAB67;

LAB69:    t24 = *((unsigned int *)t4);
    t25 = *((unsigned int *)t23);
    *((unsigned int *)t4) = (t24 | t25);
    t26 = *((unsigned int *)t14);
    t27 = *((unsigned int *)t23);
    *((unsigned int *)t14) = (t26 | t27);
    goto LAB68;

LAB70:    xsi_set_current_line(79, ng0);

LAB73:    xsi_set_current_line(80, ng0);
    t30 = ((char*)((ng8)));
    t32 = (t0 + 2744);
    xsi_vlogvar_assign_value(t32, t30, 0, 0, 1);
    xsi_set_current_line(81, ng0);
    t2 = ((char*)((ng7)));
    t3 = (t0 + 2904);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(82, ng0);
    t2 = (t0 + 2344U);
    t3 = *((char **)t2);
    t2 = (t0 + 3064);
    xsi_vlogvar_assign_value(t2, t3, 0, 0, 4);
    goto LAB72;

LAB74:    *((unsigned int *)t4) = 1;
    goto LAB77;

LAB79:    t17 = *((unsigned int *)t4);
    t18 = *((unsigned int *)t13);
    *((unsigned int *)t4) = (t17 | t18);
    t19 = *((unsigned int *)t12);
    t20 = *((unsigned int *)t13);
    *((unsigned int *)t12) = (t19 | t20);
    goto LAB78;

LAB80:    xsi_set_current_line(85, ng0);
    t23 = ((char*)((ng4)));
    t29 = (t0 + 3224);
    xsi_vlogvar_assign_value(t29, t23, 0, 0, 3);
    goto LAB82;

}


extern void work_m_00000000001668807181_2030911003_init()
{
	static char *pe[] = {(void *)Always_44_0};
	xsi_register_didat("work_m_00000000001668807181_2030911003", "isim/system_test_isim_beh.exe.sim/work/m_00000000001668807181_2030911003.didat");
	xsi_register_executes(pe);
}
