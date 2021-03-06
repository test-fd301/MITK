/*===================================================================

The Medical Imaging Interaction Toolkit (MITK)

Copyright (c) German Cancer Research Center, 
Division of Medical and Biological Informatics.
All rights reserved.

This software is distributed WITHOUT ANY WARRANTY; without 
even the implied warranty of MERCHANTABILITY or FITNESS FOR 
A PARTICULAR PURPOSE.

See LICENSE.txt or http://www.mitk.org for details.

===================================================================*/
# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Paul Mensonides 2002.
#  *     Distributed under the Boost Software License, Version 1.0. (See
#  *     accompanying file LICENSE_1_0.txt or copy at
#  *     http://www.boost.org/LICENSE_1_0.txt)
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.boost.org for most recent version. */
#
# include "mitkPPConfig.h"
#
# if MITK_PP_CONFIG_FLAGS() & MITK_PP_CONFIG_DMC()
#     include "mitkPPDetailDMCAutoRec.h"
# else
#
# ifndef MITK_PREPROCESSOR_DETAIL_AUTO_REC_HPP
# define MITK_PREPROCESSOR_DETAIL_AUTO_REC_HPP
#
# include "mitkPPControlIIf.h"
#
# /* MITK_PP_AUTO_REC */
#
# define MITK_PP_AUTO_REC(pred, n) MITK_PP_NODE_ENTRY_ ## n(pred)
#
# define MITK_PP_NODE_ENTRY_256(p) MITK_PP_NODE_128(p)(p)(p)(p)(p)(p)(p)(p)
# define MITK_PP_NODE_ENTRY_128(p) MITK_PP_NODE_64(p)(p)(p)(p)(p)(p)(p)
# define MITK_PP_NODE_ENTRY_64(p) MITK_PP_NODE_32(p)(p)(p)(p)(p)(p)
# define MITK_PP_NODE_ENTRY_32(p) MITK_PP_NODE_16(p)(p)(p)(p)(p)
# define MITK_PP_NODE_ENTRY_16(p) MITK_PP_NODE_8(p)(p)(p)(p)
# define MITK_PP_NODE_ENTRY_8(p) MITK_PP_NODE_4(p)(p)(p)
# define MITK_PP_NODE_ENTRY_4(p) MITK_PP_NODE_2(p)(p)
# define MITK_PP_NODE_ENTRY_2(p) MITK_PP_NODE_1(p)
#
# define MITK_PP_NODE_128(p) MITK_PP_IIF(p(128), MITK_PP_NODE_64, MITK_PP_NODE_192)
#    define MITK_PP_NODE_64(p) MITK_PP_IIF(p(64), MITK_PP_NODE_32, MITK_PP_NODE_96)
#        define MITK_PP_NODE_32(p) MITK_PP_IIF(p(32), MITK_PP_NODE_16, MITK_PP_NODE_48)
#            define MITK_PP_NODE_16(p) MITK_PP_IIF(p(16), MITK_PP_NODE_8, MITK_PP_NODE_24)
#                define MITK_PP_NODE_8(p) MITK_PP_IIF(p(8), MITK_PP_NODE_4, MITK_PP_NODE_12)
#                    define MITK_PP_NODE_4(p) MITK_PP_IIF(p(4), MITK_PP_NODE_2, MITK_PP_NODE_6)
#                        define MITK_PP_NODE_2(p) MITK_PP_IIF(p(2), MITK_PP_NODE_1, MITK_PP_NODE_3)
#                            define MITK_PP_NODE_1(p) MITK_PP_IIF(p(1), 1, 2)
#                            define MITK_PP_NODE_3(p) MITK_PP_IIF(p(3), 3, 4)
#                        define MITK_PP_NODE_6(p) MITK_PP_IIF(p(6), MITK_PP_NODE_5, MITK_PP_NODE_7)
#                            define MITK_PP_NODE_5(p) MITK_PP_IIF(p(5), 5, 6)
#                            define MITK_PP_NODE_7(p) MITK_PP_IIF(p(7), 7, 8)
#                    define MITK_PP_NODE_12(p) MITK_PP_IIF(p(12), MITK_PP_NODE_10, MITK_PP_NODE_14)
#                        define MITK_PP_NODE_10(p) MITK_PP_IIF(p(10), MITK_PP_NODE_9, MITK_PP_NODE_11)
#                            define MITK_PP_NODE_9(p) MITK_PP_IIF(p(9), 9, 10)
#                            define MITK_PP_NODE_11(p) MITK_PP_IIF(p(11), 11, 12)
#                        define MITK_PP_NODE_14(p) MITK_PP_IIF(p(14), MITK_PP_NODE_13, MITK_PP_NODE_15)
#                            define MITK_PP_NODE_13(p) MITK_PP_IIF(p(13), 13, 14)
#                            define MITK_PP_NODE_15(p) MITK_PP_IIF(p(15), 15, 16)
#                define MITK_PP_NODE_24(p) MITK_PP_IIF(p(24), MITK_PP_NODE_20, MITK_PP_NODE_28)
#                    define MITK_PP_NODE_20(p) MITK_PP_IIF(p(20), MITK_PP_NODE_18, MITK_PP_NODE_22)
#                        define MITK_PP_NODE_18(p) MITK_PP_IIF(p(18), MITK_PP_NODE_17, MITK_PP_NODE_19)
#                            define MITK_PP_NODE_17(p) MITK_PP_IIF(p(17), 17, 18)
#                            define MITK_PP_NODE_19(p) MITK_PP_IIF(p(19), 19, 20)
#                        define MITK_PP_NODE_22(p) MITK_PP_IIF(p(22), MITK_PP_NODE_21, MITK_PP_NODE_23)
#                            define MITK_PP_NODE_21(p) MITK_PP_IIF(p(21), 21, 22)
#                            define MITK_PP_NODE_23(p) MITK_PP_IIF(p(23), 23, 24)
#                    define MITK_PP_NODE_28(p) MITK_PP_IIF(p(28), MITK_PP_NODE_26, MITK_PP_NODE_30)
#                        define MITK_PP_NODE_26(p) MITK_PP_IIF(p(26), MITK_PP_NODE_25, MITK_PP_NODE_27)
#                            define MITK_PP_NODE_25(p) MITK_PP_IIF(p(25), 25, 26)
#                            define MITK_PP_NODE_27(p) MITK_PP_IIF(p(27), 27, 28)
#                        define MITK_PP_NODE_30(p) MITK_PP_IIF(p(30), MITK_PP_NODE_29, MITK_PP_NODE_31)
#                            define MITK_PP_NODE_29(p) MITK_PP_IIF(p(29), 29, 30)
#                            define MITK_PP_NODE_31(p) MITK_PP_IIF(p(31), 31, 32)
#            define MITK_PP_NODE_48(p) MITK_PP_IIF(p(48), MITK_PP_NODE_40, MITK_PP_NODE_56)
#                define MITK_PP_NODE_40(p) MITK_PP_IIF(p(40), MITK_PP_NODE_36, MITK_PP_NODE_44)
#                    define MITK_PP_NODE_36(p) MITK_PP_IIF(p(36), MITK_PP_NODE_34, MITK_PP_NODE_38)
#                        define MITK_PP_NODE_34(p) MITK_PP_IIF(p(34), MITK_PP_NODE_33, MITK_PP_NODE_35)
#                            define MITK_PP_NODE_33(p) MITK_PP_IIF(p(33), 33, 34)
#                            define MITK_PP_NODE_35(p) MITK_PP_IIF(p(35), 35, 36)
#                        define MITK_PP_NODE_38(p) MITK_PP_IIF(p(38), MITK_PP_NODE_37, MITK_PP_NODE_39)
#                            define MITK_PP_NODE_37(p) MITK_PP_IIF(p(37), 37, 38)
#                            define MITK_PP_NODE_39(p) MITK_PP_IIF(p(39), 39, 40)
#                    define MITK_PP_NODE_44(p) MITK_PP_IIF(p(44), MITK_PP_NODE_42, MITK_PP_NODE_46)
#                        define MITK_PP_NODE_42(p) MITK_PP_IIF(p(42), MITK_PP_NODE_41, MITK_PP_NODE_43)
#                            define MITK_PP_NODE_41(p) MITK_PP_IIF(p(41), 41, 42)
#                            define MITK_PP_NODE_43(p) MITK_PP_IIF(p(43), 43, 44)
#                        define MITK_PP_NODE_46(p) MITK_PP_IIF(p(46), MITK_PP_NODE_45, MITK_PP_NODE_47)
#                            define MITK_PP_NODE_45(p) MITK_PP_IIF(p(45), 45, 46)
#                            define MITK_PP_NODE_47(p) MITK_PP_IIF(p(47), 47, 48)
#                define MITK_PP_NODE_56(p) MITK_PP_IIF(p(56), MITK_PP_NODE_52, MITK_PP_NODE_60)
#                    define MITK_PP_NODE_52(p) MITK_PP_IIF(p(52), MITK_PP_NODE_50, MITK_PP_NODE_54)
#                        define MITK_PP_NODE_50(p) MITK_PP_IIF(p(50), MITK_PP_NODE_49, MITK_PP_NODE_51)
#                            define MITK_PP_NODE_49(p) MITK_PP_IIF(p(49), 49, 50)
#                            define MITK_PP_NODE_51(p) MITK_PP_IIF(p(51), 51, 52)
#                        define MITK_PP_NODE_54(p) MITK_PP_IIF(p(54), MITK_PP_NODE_53, MITK_PP_NODE_55)
#                            define MITK_PP_NODE_53(p) MITK_PP_IIF(p(53), 53, 54)
#                            define MITK_PP_NODE_55(p) MITK_PP_IIF(p(55), 55, 56)
#                    define MITK_PP_NODE_60(p) MITK_PP_IIF(p(60), MITK_PP_NODE_58, MITK_PP_NODE_62)
#                        define MITK_PP_NODE_58(p) MITK_PP_IIF(p(58), MITK_PP_NODE_57, MITK_PP_NODE_59)
#                            define MITK_PP_NODE_57(p) MITK_PP_IIF(p(57), 57, 58)
#                            define MITK_PP_NODE_59(p) MITK_PP_IIF(p(59), 59, 60)
#                        define MITK_PP_NODE_62(p) MITK_PP_IIF(p(62), MITK_PP_NODE_61, MITK_PP_NODE_63)
#                            define MITK_PP_NODE_61(p) MITK_PP_IIF(p(61), 61, 62)
#                            define MITK_PP_NODE_63(p) MITK_PP_IIF(p(63), 63, 64)
#        define MITK_PP_NODE_96(p) MITK_PP_IIF(p(96), MITK_PP_NODE_80, MITK_PP_NODE_112)
#            define MITK_PP_NODE_80(p) MITK_PP_IIF(p(80), MITK_PP_NODE_72, MITK_PP_NODE_88)
#                define MITK_PP_NODE_72(p) MITK_PP_IIF(p(72), MITK_PP_NODE_68, MITK_PP_NODE_76)
#                    define MITK_PP_NODE_68(p) MITK_PP_IIF(p(68), MITK_PP_NODE_66, MITK_PP_NODE_70)
#                        define MITK_PP_NODE_66(p) MITK_PP_IIF(p(66), MITK_PP_NODE_65, MITK_PP_NODE_67)
#                            define MITK_PP_NODE_65(p) MITK_PP_IIF(p(65), 65, 66)
#                            define MITK_PP_NODE_67(p) MITK_PP_IIF(p(67), 67, 68)
#                        define MITK_PP_NODE_70(p) MITK_PP_IIF(p(70), MITK_PP_NODE_69, MITK_PP_NODE_71)
#                            define MITK_PP_NODE_69(p) MITK_PP_IIF(p(69), 69, 70)
#                            define MITK_PP_NODE_71(p) MITK_PP_IIF(p(71), 71, 72)
#                    define MITK_PP_NODE_76(p) MITK_PP_IIF(p(76), MITK_PP_NODE_74, MITK_PP_NODE_78)
#                        define MITK_PP_NODE_74(p) MITK_PP_IIF(p(74), MITK_PP_NODE_73, MITK_PP_NODE_75)
#                            define MITK_PP_NODE_73(p) MITK_PP_IIF(p(73), 73, 74)
#                            define MITK_PP_NODE_75(p) MITK_PP_IIF(p(75), 75, 76)
#                        define MITK_PP_NODE_78(p) MITK_PP_IIF(p(78), MITK_PP_NODE_77, MITK_PP_NODE_79)
#                            define MITK_PP_NODE_77(p) MITK_PP_IIF(p(77), 77, 78)
#                            define MITK_PP_NODE_79(p) MITK_PP_IIF(p(79), 79, 80)
#                define MITK_PP_NODE_88(p) MITK_PP_IIF(p(88), MITK_PP_NODE_84, MITK_PP_NODE_92)
#                    define MITK_PP_NODE_84(p) MITK_PP_IIF(p(84), MITK_PP_NODE_82, MITK_PP_NODE_86)
#                        define MITK_PP_NODE_82(p) MITK_PP_IIF(p(82), MITK_PP_NODE_81, MITK_PP_NODE_83)
#                            define MITK_PP_NODE_81(p) MITK_PP_IIF(p(81), 81, 82)
#                            define MITK_PP_NODE_83(p) MITK_PP_IIF(p(83), 83, 84)
#                        define MITK_PP_NODE_86(p) MITK_PP_IIF(p(86), MITK_PP_NODE_85, MITK_PP_NODE_87)
#                            define MITK_PP_NODE_85(p) MITK_PP_IIF(p(85), 85, 86)
#                            define MITK_PP_NODE_87(p) MITK_PP_IIF(p(87), 87, 88)
#                    define MITK_PP_NODE_92(p) MITK_PP_IIF(p(92), MITK_PP_NODE_90, MITK_PP_NODE_94)
#                        define MITK_PP_NODE_90(p) MITK_PP_IIF(p(90), MITK_PP_NODE_89, MITK_PP_NODE_91)
#                            define MITK_PP_NODE_89(p) MITK_PP_IIF(p(89), 89, 90)
#                            define MITK_PP_NODE_91(p) MITK_PP_IIF(p(91), 91, 92)
#                        define MITK_PP_NODE_94(p) MITK_PP_IIF(p(94), MITK_PP_NODE_93, MITK_PP_NODE_95)
#                            define MITK_PP_NODE_93(p) MITK_PP_IIF(p(93), 93, 94)
#                            define MITK_PP_NODE_95(p) MITK_PP_IIF(p(95), 95, 96)
#            define MITK_PP_NODE_112(p) MITK_PP_IIF(p(112), MITK_PP_NODE_104, MITK_PP_NODE_120)
#                define MITK_PP_NODE_104(p) MITK_PP_IIF(p(104), MITK_PP_NODE_100, MITK_PP_NODE_108)
#                    define MITK_PP_NODE_100(p) MITK_PP_IIF(p(100), MITK_PP_NODE_98, MITK_PP_NODE_102)
#                        define MITK_PP_NODE_98(p) MITK_PP_IIF(p(98), MITK_PP_NODE_97, MITK_PP_NODE_99)
#                            define MITK_PP_NODE_97(p) MITK_PP_IIF(p(97), 97, 98)
#                            define MITK_PP_NODE_99(p) MITK_PP_IIF(p(99), 99, 100)
#                        define MITK_PP_NODE_102(p) MITK_PP_IIF(p(102), MITK_PP_NODE_101, MITK_PP_NODE_103)
#                            define MITK_PP_NODE_101(p) MITK_PP_IIF(p(101), 101, 102)
#                            define MITK_PP_NODE_103(p) MITK_PP_IIF(p(103), 103, 104)
#                    define MITK_PP_NODE_108(p) MITK_PP_IIF(p(108), MITK_PP_NODE_106, MITK_PP_NODE_110)
#                        define MITK_PP_NODE_106(p) MITK_PP_IIF(p(106), MITK_PP_NODE_105, MITK_PP_NODE_107)
#                            define MITK_PP_NODE_105(p) MITK_PP_IIF(p(105), 105, 106)
#                            define MITK_PP_NODE_107(p) MITK_PP_IIF(p(107), 107, 108)
#                        define MITK_PP_NODE_110(p) MITK_PP_IIF(p(110), MITK_PP_NODE_109, MITK_PP_NODE_111)
#                            define MITK_PP_NODE_109(p) MITK_PP_IIF(p(109), 109, 110)
#                            define MITK_PP_NODE_111(p) MITK_PP_IIF(p(111), 111, 112)
#                define MITK_PP_NODE_120(p) MITK_PP_IIF(p(120), MITK_PP_NODE_116, MITK_PP_NODE_124)
#                    define MITK_PP_NODE_116(p) MITK_PP_IIF(p(116), MITK_PP_NODE_114, MITK_PP_NODE_118)
#                        define MITK_PP_NODE_114(p) MITK_PP_IIF(p(114), MITK_PP_NODE_113, MITK_PP_NODE_115)
#                            define MITK_PP_NODE_113(p) MITK_PP_IIF(p(113), 113, 114)
#                            define MITK_PP_NODE_115(p) MITK_PP_IIF(p(115), 115, 116)
#                        define MITK_PP_NODE_118(p) MITK_PP_IIF(p(118), MITK_PP_NODE_117, MITK_PP_NODE_119)
#                            define MITK_PP_NODE_117(p) MITK_PP_IIF(p(117), 117, 118)
#                            define MITK_PP_NODE_119(p) MITK_PP_IIF(p(119), 119, 120)
#                    define MITK_PP_NODE_124(p) MITK_PP_IIF(p(124), MITK_PP_NODE_122, MITK_PP_NODE_126)
#                        define MITK_PP_NODE_122(p) MITK_PP_IIF(p(122), MITK_PP_NODE_121, MITK_PP_NODE_123)
#                            define MITK_PP_NODE_121(p) MITK_PP_IIF(p(121), 121, 122)
#                            define MITK_PP_NODE_123(p) MITK_PP_IIF(p(123), 123, 124)
#                        define MITK_PP_NODE_126(p) MITK_PP_IIF(p(126), MITK_PP_NODE_125, MITK_PP_NODE_127)
#                            define MITK_PP_NODE_125(p) MITK_PP_IIF(p(125), 125, 126)
#                            define MITK_PP_NODE_127(p) MITK_PP_IIF(p(127), 127, 128)
#    define MITK_PP_NODE_192(p) MITK_PP_IIF(p(192), MITK_PP_NODE_160, MITK_PP_NODE_224)
#        define MITK_PP_NODE_160(p) MITK_PP_IIF(p(160), MITK_PP_NODE_144, MITK_PP_NODE_176)
#            define MITK_PP_NODE_144(p) MITK_PP_IIF(p(144), MITK_PP_NODE_136, MITK_PP_NODE_152)
#                define MITK_PP_NODE_136(p) MITK_PP_IIF(p(136), MITK_PP_NODE_132, MITK_PP_NODE_140)
#                    define MITK_PP_NODE_132(p) MITK_PP_IIF(p(132), MITK_PP_NODE_130, MITK_PP_NODE_134)
#                        define MITK_PP_NODE_130(p) MITK_PP_IIF(p(130), MITK_PP_NODE_129, MITK_PP_NODE_131)
#                            define MITK_PP_NODE_129(p) MITK_PP_IIF(p(129), 129, 130)
#                            define MITK_PP_NODE_131(p) MITK_PP_IIF(p(131), 131, 132)
#                        define MITK_PP_NODE_134(p) MITK_PP_IIF(p(134), MITK_PP_NODE_133, MITK_PP_NODE_135)
#                            define MITK_PP_NODE_133(p) MITK_PP_IIF(p(133), 133, 134)
#                            define MITK_PP_NODE_135(p) MITK_PP_IIF(p(135), 135, 136)
#                    define MITK_PP_NODE_140(p) MITK_PP_IIF(p(140), MITK_PP_NODE_138, MITK_PP_NODE_142)
#                        define MITK_PP_NODE_138(p) MITK_PP_IIF(p(138), MITK_PP_NODE_137, MITK_PP_NODE_139)
#                            define MITK_PP_NODE_137(p) MITK_PP_IIF(p(137), 137, 138)
#                            define MITK_PP_NODE_139(p) MITK_PP_IIF(p(139), 139, 140)
#                        define MITK_PP_NODE_142(p) MITK_PP_IIF(p(142), MITK_PP_NODE_141, MITK_PP_NODE_143)
#                            define MITK_PP_NODE_141(p) MITK_PP_IIF(p(141), 141, 142)
#                            define MITK_PP_NODE_143(p) MITK_PP_IIF(p(143), 143, 144)
#                define MITK_PP_NODE_152(p) MITK_PP_IIF(p(152), MITK_PP_NODE_148, MITK_PP_NODE_156)
#                    define MITK_PP_NODE_148(p) MITK_PP_IIF(p(148), MITK_PP_NODE_146, MITK_PP_NODE_150)
#                        define MITK_PP_NODE_146(p) MITK_PP_IIF(p(146), MITK_PP_NODE_145, MITK_PP_NODE_147)
#                            define MITK_PP_NODE_145(p) MITK_PP_IIF(p(145), 145, 146)
#                            define MITK_PP_NODE_147(p) MITK_PP_IIF(p(147), 147, 148)
#                        define MITK_PP_NODE_150(p) MITK_PP_IIF(p(150), MITK_PP_NODE_149, MITK_PP_NODE_151)
#                            define MITK_PP_NODE_149(p) MITK_PP_IIF(p(149), 149, 150)
#                            define MITK_PP_NODE_151(p) MITK_PP_IIF(p(151), 151, 152)
#                    define MITK_PP_NODE_156(p) MITK_PP_IIF(p(156), MITK_PP_NODE_154, MITK_PP_NODE_158)
#                        define MITK_PP_NODE_154(p) MITK_PP_IIF(p(154), MITK_PP_NODE_153, MITK_PP_NODE_155)
#                            define MITK_PP_NODE_153(p) MITK_PP_IIF(p(153), 153, 154)
#                            define MITK_PP_NODE_155(p) MITK_PP_IIF(p(155), 155, 156)
#                        define MITK_PP_NODE_158(p) MITK_PP_IIF(p(158), MITK_PP_NODE_157, MITK_PP_NODE_159)
#                            define MITK_PP_NODE_157(p) MITK_PP_IIF(p(157), 157, 158)
#                            define MITK_PP_NODE_159(p) MITK_PP_IIF(p(159), 159, 160)
#            define MITK_PP_NODE_176(p) MITK_PP_IIF(p(176), MITK_PP_NODE_168, MITK_PP_NODE_184)
#                define MITK_PP_NODE_168(p) MITK_PP_IIF(p(168), MITK_PP_NODE_164, MITK_PP_NODE_172)
#                    define MITK_PP_NODE_164(p) MITK_PP_IIF(p(164), MITK_PP_NODE_162, MITK_PP_NODE_166)
#                        define MITK_PP_NODE_162(p) MITK_PP_IIF(p(162), MITK_PP_NODE_161, MITK_PP_NODE_163)
#                            define MITK_PP_NODE_161(p) MITK_PP_IIF(p(161), 161, 162)
#                            define MITK_PP_NODE_163(p) MITK_PP_IIF(p(163), 163, 164)
#                        define MITK_PP_NODE_166(p) MITK_PP_IIF(p(166), MITK_PP_NODE_165, MITK_PP_NODE_167)
#                            define MITK_PP_NODE_165(p) MITK_PP_IIF(p(165), 165, 166)
#                            define MITK_PP_NODE_167(p) MITK_PP_IIF(p(167), 167, 168)
#                    define MITK_PP_NODE_172(p) MITK_PP_IIF(p(172), MITK_PP_NODE_170, MITK_PP_NODE_174)
#                        define MITK_PP_NODE_170(p) MITK_PP_IIF(p(170), MITK_PP_NODE_169, MITK_PP_NODE_171)
#                            define MITK_PP_NODE_169(p) MITK_PP_IIF(p(169), 169, 170)
#                            define MITK_PP_NODE_171(p) MITK_PP_IIF(p(171), 171, 172)
#                        define MITK_PP_NODE_174(p) MITK_PP_IIF(p(174), MITK_PP_NODE_173, MITK_PP_NODE_175)
#                            define MITK_PP_NODE_173(p) MITK_PP_IIF(p(173), 173, 174)
#                            define MITK_PP_NODE_175(p) MITK_PP_IIF(p(175), 175, 176)
#                define MITK_PP_NODE_184(p) MITK_PP_IIF(p(184), MITK_PP_NODE_180, MITK_PP_NODE_188)
#                    define MITK_PP_NODE_180(p) MITK_PP_IIF(p(180), MITK_PP_NODE_178, MITK_PP_NODE_182)
#                        define MITK_PP_NODE_178(p) MITK_PP_IIF(p(178), MITK_PP_NODE_177, MITK_PP_NODE_179)
#                            define MITK_PP_NODE_177(p) MITK_PP_IIF(p(177), 177, 178)
#                            define MITK_PP_NODE_179(p) MITK_PP_IIF(p(179), 179, 180)
#                        define MITK_PP_NODE_182(p) MITK_PP_IIF(p(182), MITK_PP_NODE_181, MITK_PP_NODE_183)
#                            define MITK_PP_NODE_181(p) MITK_PP_IIF(p(181), 181, 182)
#                            define MITK_PP_NODE_183(p) MITK_PP_IIF(p(183), 183, 184)
#                    define MITK_PP_NODE_188(p) MITK_PP_IIF(p(188), MITK_PP_NODE_186, MITK_PP_NODE_190)
#                        define MITK_PP_NODE_186(p) MITK_PP_IIF(p(186), MITK_PP_NODE_185, MITK_PP_NODE_187)
#                            define MITK_PP_NODE_185(p) MITK_PP_IIF(p(185), 185, 186)
#                            define MITK_PP_NODE_187(p) MITK_PP_IIF(p(187), 187, 188)
#                        define MITK_PP_NODE_190(p) MITK_PP_IIF(p(190), MITK_PP_NODE_189, MITK_PP_NODE_191)
#                            define MITK_PP_NODE_189(p) MITK_PP_IIF(p(189), 189, 190)
#                            define MITK_PP_NODE_191(p) MITK_PP_IIF(p(191), 191, 192)
#        define MITK_PP_NODE_224(p) MITK_PP_IIF(p(224), MITK_PP_NODE_208, MITK_PP_NODE_240)
#            define MITK_PP_NODE_208(p) MITK_PP_IIF(p(208), MITK_PP_NODE_200, MITK_PP_NODE_216)
#                define MITK_PP_NODE_200(p) MITK_PP_IIF(p(200), MITK_PP_NODE_196, MITK_PP_NODE_204)
#                    define MITK_PP_NODE_196(p) MITK_PP_IIF(p(196), MITK_PP_NODE_194, MITK_PP_NODE_198)
#                        define MITK_PP_NODE_194(p) MITK_PP_IIF(p(194), MITK_PP_NODE_193, MITK_PP_NODE_195)
#                            define MITK_PP_NODE_193(p) MITK_PP_IIF(p(193), 193, 194)
#                            define MITK_PP_NODE_195(p) MITK_PP_IIF(p(195), 195, 196)
#                        define MITK_PP_NODE_198(p) MITK_PP_IIF(p(198), MITK_PP_NODE_197, MITK_PP_NODE_199)
#                            define MITK_PP_NODE_197(p) MITK_PP_IIF(p(197), 197, 198)
#                            define MITK_PP_NODE_199(p) MITK_PP_IIF(p(199), 199, 200)
#                    define MITK_PP_NODE_204(p) MITK_PP_IIF(p(204), MITK_PP_NODE_202, MITK_PP_NODE_206)
#                        define MITK_PP_NODE_202(p) MITK_PP_IIF(p(202), MITK_PP_NODE_201, MITK_PP_NODE_203)
#                            define MITK_PP_NODE_201(p) MITK_PP_IIF(p(201), 201, 202)
#                            define MITK_PP_NODE_203(p) MITK_PP_IIF(p(203), 203, 204)
#                        define MITK_PP_NODE_206(p) MITK_PP_IIF(p(206), MITK_PP_NODE_205, MITK_PP_NODE_207)
#                            define MITK_PP_NODE_205(p) MITK_PP_IIF(p(205), 205, 206)
#                            define MITK_PP_NODE_207(p) MITK_PP_IIF(p(207), 207, 208)
#                define MITK_PP_NODE_216(p) MITK_PP_IIF(p(216), MITK_PP_NODE_212, MITK_PP_NODE_220)
#                    define MITK_PP_NODE_212(p) MITK_PP_IIF(p(212), MITK_PP_NODE_210, MITK_PP_NODE_214)
#                        define MITK_PP_NODE_210(p) MITK_PP_IIF(p(210), MITK_PP_NODE_209, MITK_PP_NODE_211)
#                            define MITK_PP_NODE_209(p) MITK_PP_IIF(p(209), 209, 210)
#                            define MITK_PP_NODE_211(p) MITK_PP_IIF(p(211), 211, 212)
#                        define MITK_PP_NODE_214(p) MITK_PP_IIF(p(214), MITK_PP_NODE_213, MITK_PP_NODE_215)
#                            define MITK_PP_NODE_213(p) MITK_PP_IIF(p(213), 213, 214)
#                            define MITK_PP_NODE_215(p) MITK_PP_IIF(p(215), 215, 216)
#                    define MITK_PP_NODE_220(p) MITK_PP_IIF(p(220), MITK_PP_NODE_218, MITK_PP_NODE_222)
#                        define MITK_PP_NODE_218(p) MITK_PP_IIF(p(218), MITK_PP_NODE_217, MITK_PP_NODE_219)
#                            define MITK_PP_NODE_217(p) MITK_PP_IIF(p(217), 217, 218)
#                            define MITK_PP_NODE_219(p) MITK_PP_IIF(p(219), 219, 220)
#                        define MITK_PP_NODE_222(p) MITK_PP_IIF(p(222), MITK_PP_NODE_221, MITK_PP_NODE_223)
#                            define MITK_PP_NODE_221(p) MITK_PP_IIF(p(221), 221, 222)
#                            define MITK_PP_NODE_223(p) MITK_PP_IIF(p(223), 223, 224)
#            define MITK_PP_NODE_240(p) MITK_PP_IIF(p(240), MITK_PP_NODE_232, MITK_PP_NODE_248)
#                define MITK_PP_NODE_232(p) MITK_PP_IIF(p(232), MITK_PP_NODE_228, MITK_PP_NODE_236)
#                    define MITK_PP_NODE_228(p) MITK_PP_IIF(p(228), MITK_PP_NODE_226, MITK_PP_NODE_230)
#                        define MITK_PP_NODE_226(p) MITK_PP_IIF(p(226), MITK_PP_NODE_225, MITK_PP_NODE_227)
#                            define MITK_PP_NODE_225(p) MITK_PP_IIF(p(225), 225, 226)
#                            define MITK_PP_NODE_227(p) MITK_PP_IIF(p(227), 227, 228)
#                        define MITK_PP_NODE_230(p) MITK_PP_IIF(p(230), MITK_PP_NODE_229, MITK_PP_NODE_231)
#                            define MITK_PP_NODE_229(p) MITK_PP_IIF(p(229), 229, 230)
#                            define MITK_PP_NODE_231(p) MITK_PP_IIF(p(231), 231, 232)
#                    define MITK_PP_NODE_236(p) MITK_PP_IIF(p(236), MITK_PP_NODE_234, MITK_PP_NODE_238)
#                        define MITK_PP_NODE_234(p) MITK_PP_IIF(p(234), MITK_PP_NODE_233, MITK_PP_NODE_235)
#                            define MITK_PP_NODE_233(p) MITK_PP_IIF(p(233), 233, 234)
#                            define MITK_PP_NODE_235(p) MITK_PP_IIF(p(235), 235, 236)
#                        define MITK_PP_NODE_238(p) MITK_PP_IIF(p(238), MITK_PP_NODE_237, MITK_PP_NODE_239)
#                            define MITK_PP_NODE_237(p) MITK_PP_IIF(p(237), 237, 238)
#                            define MITK_PP_NODE_239(p) MITK_PP_IIF(p(239), 239, 240)
#                define MITK_PP_NODE_248(p) MITK_PP_IIF(p(248), MITK_PP_NODE_244, MITK_PP_NODE_252)
#                    define MITK_PP_NODE_244(p) MITK_PP_IIF(p(244), MITK_PP_NODE_242, MITK_PP_NODE_246)
#                        define MITK_PP_NODE_242(p) MITK_PP_IIF(p(242), MITK_PP_NODE_241, MITK_PP_NODE_243)
#                            define MITK_PP_NODE_241(p) MITK_PP_IIF(p(241), 241, 242)
#                            define MITK_PP_NODE_243(p) MITK_PP_IIF(p(243), 243, 244)
#                        define MITK_PP_NODE_246(p) MITK_PP_IIF(p(246), MITK_PP_NODE_245, MITK_PP_NODE_247)
#                            define MITK_PP_NODE_245(p) MITK_PP_IIF(p(245), 245, 246)
#                            define MITK_PP_NODE_247(p) MITK_PP_IIF(p(247), 247, 248)
#                    define MITK_PP_NODE_252(p) MITK_PP_IIF(p(252), MITK_PP_NODE_250, MITK_PP_NODE_254)
#                        define MITK_PP_NODE_250(p) MITK_PP_IIF(p(250), MITK_PP_NODE_249, MITK_PP_NODE_251)
#                            define MITK_PP_NODE_249(p) MITK_PP_IIF(p(249), 249, 250)
#                            define MITK_PP_NODE_251(p) MITK_PP_IIF(p(251), 251, 252)
#                        define MITK_PP_NODE_254(p) MITK_PP_IIF(p(254), MITK_PP_NODE_253, MITK_PP_NODE_255)
#                            define MITK_PP_NODE_253(p) MITK_PP_IIF(p(253), 253, 254)
#                            define MITK_PP_NODE_255(p) MITK_PP_IIF(p(255), 255, 256)
#
# endif
# endif
