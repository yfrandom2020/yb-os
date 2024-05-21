// This is a simple code file that declares the function stub for each different isr - there are 256
// This file also implements a function that enables the gate of each of them
#include "idt.h"
#include "../gdt/gdt.h"
#include "isrgen.h"

void ISR_InitializeGates()
{
    idt_set_gate(0, ISR0, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int); 
    idt_set_gate(1, ISR1, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(2, ISR2, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(3, ISR3, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(4, ISR4, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(5, ISR5, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(6, ISR6, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(7, ISR7, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(8, ISR8, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(9, ISR9, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(10, ISR10, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(11, ISR11, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(12, ISR12, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(13, ISR13, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(14, ISR14, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(15, ISR15, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(16, ISR16, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(17, ISR17, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(18, ISR18, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(19, ISR19, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(20, ISR20, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(21, ISR21, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(22, ISR22, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(23, ISR23, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(24, ISR24, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(25, ISR25, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(26, ISR26, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(27, ISR27, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(28, ISR28, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(29, ISR29, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(30, ISR30, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(31, ISR31, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(32, ISR32, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(33, ISR33, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(34, ISR34, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(35, ISR35, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(36, ISR36, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(37, ISR37, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(38, ISR38, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(39, ISR39, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(40, ISR40, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(41, ISR41, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(42, ISR42, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(43, ISR43, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(44, ISR44, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(45, ISR45, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(46, ISR46, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(47, ISR47, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(48, ISR48, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(49, ISR49, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(50, ISR50, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(51, ISR51, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(52, ISR52, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(53, ISR53, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(54, ISR54, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(55, ISR55, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(56, ISR56, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(57, ISR57, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(58, ISR58, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(59, ISR59, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(60, ISR60, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(61, ISR61, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(62, ISR62, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(63, ISR63, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(64, ISR64, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(65, ISR65, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(66, ISR66, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(67, ISR67, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(68, ISR68, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(69, ISR69, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(70, ISR70, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(71, ISR71, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(72, ISR72, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(73, ISR73, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(74, ISR74, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(75, ISR75, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(76, ISR76, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(77, ISR77, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(78, ISR78, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(79, ISR79, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(80, ISR80, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(81, ISR81, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(82, ISR82, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(83, ISR83, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(84, ISR84, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(85, ISR85, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(86, ISR86, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(87, ISR87, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(88, ISR88, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(89, ISR89, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(90, ISR90, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(91, ISR91, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(92, ISR92, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(93, ISR93, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(94, ISR94, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(95, ISR95, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(96, ISR96, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(97, ISR97, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(98, ISR98, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(99, ISR99, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(100, ISR100, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(101, ISR101, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(102, ISR102, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(103, ISR103, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(104, ISR104, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(105, ISR105, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(106, ISR106, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(107, ISR107, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(108, ISR108, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(109, ISR109, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(110, ISR110, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(111, ISR111, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(112, ISR112, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(113, ISR113, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(114, ISR114, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(115, ISR115, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(116, ISR116, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(117, ISR117, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(118, ISR118, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(119, ISR119, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(120, ISR120, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(121, ISR121, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(122, ISR122, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(123, ISR123, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(124, ISR124, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(125, ISR125, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(126, ISR126, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(127, ISR127, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(128, ISR128, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(129, ISR129, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(130, ISR130, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(131, ISR131, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(132, ISR132, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(133, ISR133, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(134, ISR134, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(135, ISR135, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(136, ISR136, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(137, ISR137, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(138, ISR138, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(139, ISR139, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(140, ISR140, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(141, ISR141, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(142, ISR142, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(143, ISR143, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(144, ISR144, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(145, ISR145, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(146, ISR146, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(147, ISR147, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(148, ISR148, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(149, ISR149, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(150, ISR150, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(151, ISR151, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(152, ISR152, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(153, ISR153, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(154, ISR154, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(155, ISR155, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(156, ISR156, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(157, ISR157, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(158, ISR158, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(159, ISR159, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(160, ISR160, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(161, ISR161, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(162, ISR162, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(163, ISR163, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(164, ISR164, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(165, ISR165, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(166, ISR166, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(167, ISR167, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(168, ISR168, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(169, ISR169, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(170, ISR170, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(171, ISR171, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(172, ISR172, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(173, ISR173, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(174, ISR174, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(175, ISR175, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(176, ISR176, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(177, ISR177, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(178, ISR178, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(179, ISR179, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(180, ISR180, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(181, ISR181, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(182, ISR182, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(183, ISR183, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(184, ISR184, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(185, ISR185, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(186, ISR186, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(187, ISR187, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(188, ISR188, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(189, ISR189, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(190, ISR190, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(191, ISR191, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(192, ISR192, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(193, ISR193, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(194, ISR194, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(195, ISR195, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(196, ISR196, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(197, ISR197, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(198, ISR198, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(199, ISR199, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(200, ISR200, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(201, ISR201, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(202, ISR202, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(203, ISR203, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(204, ISR204, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(205, ISR205, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(206, ISR206, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(207, ISR207, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(208, ISR208, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(209, ISR209, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(210, ISR210, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(211, ISR211, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(212, ISR212, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(213, ISR213, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(214, ISR214, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(215, ISR215, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(216, ISR216, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(217, ISR217, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(218, ISR218, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(219, ISR219, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(220, ISR220, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(221, ISR221, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(222, ISR222, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(223, ISR223, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(224, ISR224, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(225, ISR225, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(226, ISR226, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(227, ISR227, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(228, ISR228, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(229, ISR229, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(230, ISR230, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(231, ISR231, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(232, ISR232, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(233, ISR233, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(234, ISR234, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(235, ISR235, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(236, ISR236, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(237, ISR237, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(238, ISR238, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(239, ISR239, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(240, ISR240, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(241, ISR241, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(242, ISR242, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(243, ISR243, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(244, ISR244, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(245, ISR245, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(246, ISR246, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(247, ISR247, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(248, ISR248, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(249, ISR249, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(250, ISR250, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(251, ISR251, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(252, ISR252, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(253, ISR253, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(254, ISR254, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(255, ISR255, GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
}
