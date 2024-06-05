// This is a simple code file that declares the function stub for each different reinterpret_cast<void*>(ISR - there are 256
// This file also implements a function that enables the gate of each of them
#include "idt/idt.h"
#include "gdt/gdt.h"
#include "idt/isr/isrgen.h"

void ISR_InitializeGates()
{
    idt_set_gate(0, reinterpret_cast<void*>(ISR0), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int); // populate the idt with the stubs. The stubs will call reinterpret_cast<void*>(ISR_Handler - which is a general purpose handler
    idt_set_gate(1, reinterpret_cast<void*>(ISR1), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(2, reinterpret_cast<void*>(ISR2), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(3, reinterpret_cast<void*>(ISR3), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(4, reinterpret_cast<void*>(ISR4), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(5, reinterpret_cast<void*>(ISR5), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(6, reinterpret_cast<void*>(ISR6), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(7, reinterpret_cast<void*>(ISR7), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(8, reinterpret_cast<void*>(ISR8), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(9, reinterpret_cast<void*>(ISR9), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(10, reinterpret_cast<void*>(ISR10), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(11, reinterpret_cast<void*>(ISR11), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(12, reinterpret_cast<void*>(ISR12), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(13, reinterpret_cast<void*>(ISR13), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(14, reinterpret_cast<void*>(ISR14), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(15, reinterpret_cast<void*>(ISR15), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(16, reinterpret_cast<void*>(ISR16), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(17, reinterpret_cast<void*>(ISR17), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(18, reinterpret_cast<void*>(ISR18), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(19, reinterpret_cast<void*>(ISR19), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(20, reinterpret_cast<void*>(ISR20), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(21, reinterpret_cast<void*>(ISR21), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(22, reinterpret_cast<void*>(ISR22), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(23, reinterpret_cast<void*>(ISR23), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(24, reinterpret_cast<void*>(ISR24), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(25, reinterpret_cast<void*>(ISR25), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(26, reinterpret_cast<void*>(ISR26), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(27, reinterpret_cast<void*>(ISR27), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(28, reinterpret_cast<void*>(ISR28), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(29, reinterpret_cast<void*>(ISR29), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(30, reinterpret_cast<void*>(ISR30), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(31, reinterpret_cast<void*>(ISR31), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(32, reinterpret_cast<void*>(ISR32), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(33, reinterpret_cast<void*>(ISR33), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(34, reinterpret_cast<void*>(ISR34), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(35, reinterpret_cast<void*>(ISR35), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(36, reinterpret_cast<void*>(ISR36), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(37, reinterpret_cast<void*>(ISR37), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(38, reinterpret_cast<void*>(ISR38), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(39, reinterpret_cast<void*>(ISR39), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(40, reinterpret_cast<void*>(ISR40), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(41, reinterpret_cast<void*>(ISR41), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(42, reinterpret_cast<void*>(ISR42), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(43, reinterpret_cast<void*>(ISR43), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(44, reinterpret_cast<void*>(ISR44), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(45, reinterpret_cast<void*>(ISR45), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(46, reinterpret_cast<void*>(ISR46), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(47, reinterpret_cast<void*>(ISR47), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(48, reinterpret_cast<void*>(ISR48), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(49, reinterpret_cast<void*>(ISR49), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(50, reinterpret_cast<void*>(ISR50), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(51, reinterpret_cast<void*>(ISR51), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(52, reinterpret_cast<void*>(ISR52), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(53, reinterpret_cast<void*>(ISR53), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(54, reinterpret_cast<void*>(ISR54), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(55, reinterpret_cast<void*>(ISR55), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(56, reinterpret_cast<void*>(ISR56), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(57, reinterpret_cast<void*>(ISR57), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(58, reinterpret_cast<void*>(ISR58), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(59, reinterpret_cast<void*>(ISR59), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(60, reinterpret_cast<void*>(ISR60), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(61, reinterpret_cast<void*>(ISR61), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(62, reinterpret_cast<void*>(ISR62), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(63, reinterpret_cast<void*>(ISR63), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(64, reinterpret_cast<void*>(ISR64), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(65, reinterpret_cast<void*>(ISR65), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(66, reinterpret_cast<void*>(ISR66), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(67, reinterpret_cast<void*>(ISR67), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(68, reinterpret_cast<void*>(ISR68), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(69, reinterpret_cast<void*>(ISR69), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(70, reinterpret_cast<void*>(ISR70), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(71, reinterpret_cast<void*>(ISR71), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(72, reinterpret_cast<void*>(ISR72), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(73, reinterpret_cast<void*>(ISR73), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(74, reinterpret_cast<void*>(ISR74), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(75, reinterpret_cast<void*>(ISR75), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(76, reinterpret_cast<void*>(ISR76), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(77, reinterpret_cast<void*>(ISR77), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(78, reinterpret_cast<void*>(ISR78), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(79, reinterpret_cast<void*>(ISR79), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(80, reinterpret_cast<void*>(ISR80), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(81, reinterpret_cast<void*>(ISR81), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(82, reinterpret_cast<void*>(ISR82), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(83, reinterpret_cast<void*>(ISR83), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(84, reinterpret_cast<void*>(ISR84), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(85, reinterpret_cast<void*>(ISR85), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(86, reinterpret_cast<void*>(ISR86), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(87, reinterpret_cast<void*>(ISR87), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(88, reinterpret_cast<void*>(ISR88), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(89, reinterpret_cast<void*>(ISR89), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(90, reinterpret_cast<void*>(ISR90), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(91, reinterpret_cast<void*>(ISR91), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(92, reinterpret_cast<void*>(ISR92), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(93, reinterpret_cast<void*>(ISR93), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(94, reinterpret_cast<void*>(ISR94), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(95, reinterpret_cast<void*>(ISR95), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(96, reinterpret_cast<void*>(ISR96), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(97, reinterpret_cast<void*>(ISR97), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(98, reinterpret_cast<void*>(ISR98), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(99, reinterpret_cast<void*>(ISR99), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(100, reinterpret_cast<void*>(ISR100), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(101, reinterpret_cast<void*>(ISR101), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(102, reinterpret_cast<void*>(ISR102), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(103, reinterpret_cast<void*>(ISR103), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(104, reinterpret_cast<void*>(ISR104), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(105, reinterpret_cast<void*>(ISR105), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(106, reinterpret_cast<void*>(ISR106), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(107, reinterpret_cast<void*>(ISR107), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(108, reinterpret_cast<void*>(ISR108), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(109, reinterpret_cast<void*>(ISR109), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(110, reinterpret_cast<void*>(ISR110), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(111, reinterpret_cast<void*>(ISR111), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(112, reinterpret_cast<void*>(ISR112), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(113, reinterpret_cast<void*>(ISR113), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(114, reinterpret_cast<void*>(ISR114), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(115, reinterpret_cast<void*>(ISR115), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(116, reinterpret_cast<void*>(ISR116), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(117, reinterpret_cast<void*>(ISR117), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(118, reinterpret_cast<void*>(ISR118), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(119, reinterpret_cast<void*>(ISR119), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(120, reinterpret_cast<void*>(ISR120), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(121, reinterpret_cast<void*>(ISR121), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(122, reinterpret_cast<void*>(ISR122), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(123, reinterpret_cast<void*>(ISR123), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(124, reinterpret_cast<void*>(ISR124), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(125, reinterpret_cast<void*>(ISR125), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(126, reinterpret_cast<void*>(ISR126), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(127, reinterpret_cast<void*>(ISR127), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(128, reinterpret_cast<void*>(ISR128), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(129, reinterpret_cast<void*>(ISR129), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(130, reinterpret_cast<void*>(ISR130), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(131, reinterpret_cast<void*>(ISR131), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(132, reinterpret_cast<void*>(ISR132), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(133, reinterpret_cast<void*>(ISR133), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(134, reinterpret_cast<void*>(ISR134), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(135, reinterpret_cast<void*>(ISR135), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(136, reinterpret_cast<void*>(ISR136), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(137, reinterpret_cast<void*>(ISR137), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(138, reinterpret_cast<void*>(ISR138), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(139, reinterpret_cast<void*>(ISR139), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(140, reinterpret_cast<void*>(ISR140), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(141, reinterpret_cast<void*>(ISR141), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(142, reinterpret_cast<void*>(ISR142), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(143, reinterpret_cast<void*>(ISR143), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(144, reinterpret_cast<void*>(ISR144), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(145, reinterpret_cast<void*>(ISR145), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(146, reinterpret_cast<void*>(ISR146), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(147, reinterpret_cast<void*>(ISR147), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(148, reinterpret_cast<void*>(ISR148), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(149, reinterpret_cast<void*>(ISR149), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(150, reinterpret_cast<void*>(ISR150), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(151, reinterpret_cast<void*>(ISR151), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(152, reinterpret_cast<void*>(ISR152), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(153, reinterpret_cast<void*>(ISR153), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(154, reinterpret_cast<void*>(ISR154), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(155, reinterpret_cast<void*>(ISR155), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(156, reinterpret_cast<void*>(ISR156), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(157, reinterpret_cast<void*>(ISR157), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(158, reinterpret_cast<void*>(ISR158), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(159, reinterpret_cast<void*>(ISR159), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(160, reinterpret_cast<void*>(ISR160), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(161, reinterpret_cast<void*>(ISR161), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(162, reinterpret_cast<void*>(ISR162), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(163, reinterpret_cast<void*>(ISR163), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(164, reinterpret_cast<void*>(ISR164), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(165, reinterpret_cast<void*>(ISR165), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(166, reinterpret_cast<void*>(ISR166), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(167, reinterpret_cast<void*>(ISR167), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(168, reinterpret_cast<void*>(ISR168), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(169, reinterpret_cast<void*>(ISR169), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(170, reinterpret_cast<void*>(ISR170), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(171, reinterpret_cast<void*>(ISR171), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(172, reinterpret_cast<void*>(ISR172), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(173, reinterpret_cast<void*>(ISR173), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(174, reinterpret_cast<void*>(ISR174), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(175, reinterpret_cast<void*>(ISR175), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(176, reinterpret_cast<void*>(ISR176), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(177, reinterpret_cast<void*>(ISR177), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(178, reinterpret_cast<void*>(ISR178), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(179, reinterpret_cast<void*>(ISR179), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(180, reinterpret_cast<void*>(ISR180), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(181, reinterpret_cast<void*>(ISR181), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(182, reinterpret_cast<void*>(ISR182), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(183, reinterpret_cast<void*>(ISR183), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(184, reinterpret_cast<void*>(ISR184), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(185, reinterpret_cast<void*>(ISR185), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(186, reinterpret_cast<void*>(ISR186), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(187, reinterpret_cast<void*>(ISR187), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(188, reinterpret_cast<void*>(ISR188), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(189, reinterpret_cast<void*>(ISR189), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(190, reinterpret_cast<void*>(ISR190), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(191, reinterpret_cast<void*>(ISR191), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(192, reinterpret_cast<void*>(ISR192), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(193, reinterpret_cast<void*>(ISR193), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(194, reinterpret_cast<void*>(ISR194), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(195, reinterpret_cast<void*>(ISR195), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(196, reinterpret_cast<void*>(ISR196), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(197, reinterpret_cast<void*>(ISR197), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(198, reinterpret_cast<void*>(ISR198), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(199, reinterpret_cast<void*>(ISR199), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(200, reinterpret_cast<void*>(ISR200), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(201, reinterpret_cast<void*>(ISR201), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(202, reinterpret_cast<void*>(ISR202), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(203, reinterpret_cast<void*>(ISR203), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(204, reinterpret_cast<void*>(ISR204), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(205, reinterpret_cast<void*>(ISR205), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(206, reinterpret_cast<void*>(ISR206), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(207, reinterpret_cast<void*>(ISR207), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(208, reinterpret_cast<void*>(ISR208), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(209, reinterpret_cast<void*>(ISR209), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(210, reinterpret_cast<void*>(ISR210), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(211, reinterpret_cast<void*>(ISR211), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(212, reinterpret_cast<void*>(ISR212), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(213, reinterpret_cast<void*>(ISR213), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(214, reinterpret_cast<void*>(ISR214), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(215, reinterpret_cast<void*>(ISR215), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(216, reinterpret_cast<void*>(ISR216), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(217, reinterpret_cast<void*>(ISR217), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(218, reinterpret_cast<void*>(ISR218), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(219, reinterpret_cast<void*>(ISR219), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(220, reinterpret_cast<void*>(ISR220), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(221, reinterpret_cast<void*>(ISR221), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(222, reinterpret_cast<void*>(ISR222), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(223, reinterpret_cast<void*>(ISR223), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(224, reinterpret_cast<void*>(ISR224), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(225, reinterpret_cast<void*>(ISR225), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(226, reinterpret_cast<void*>(ISR226), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(227, reinterpret_cast<void*>(ISR227), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(228, reinterpret_cast<void*>(ISR228), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(229, reinterpret_cast<void*>(ISR229), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(230, reinterpret_cast<void*>(ISR230), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(231, reinterpret_cast<void*>(ISR231), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(232, reinterpret_cast<void*>(ISR232), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(233, reinterpret_cast<void*>(ISR233), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(234, reinterpret_cast<void*>(ISR234), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(235, reinterpret_cast<void*>(ISR235), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(236, reinterpret_cast<void*>(ISR236), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(237, reinterpret_cast<void*>(ISR237), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(238, reinterpret_cast<void*>(ISR238), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(239, reinterpret_cast<void*>(ISR239), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(240, reinterpret_cast<void*>(ISR240), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(241, reinterpret_cast<void*>(ISR241), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(242, reinterpret_cast<void*>(ISR242), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(243, reinterpret_cast<void*>(ISR243), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(244, reinterpret_cast<void*>(ISR244), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(245, reinterpret_cast<void*>(ISR245), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(246, reinterpret_cast<void*>(ISR246), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(247, reinterpret_cast<void*>(ISR247), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(248, reinterpret_cast<void*>(ISR248), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(249, reinterpret_cast<void*>(ISR249), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(250, reinterpret_cast<void*>(ISR250), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(251, reinterpret_cast<void*>(ISR251), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(252, reinterpret_cast<void*>(ISR252), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(253, reinterpret_cast<void*>(ISR253), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(254, reinterpret_cast<void*>(ISR254), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
    idt_set_gate(255, reinterpret_cast<void*>(ISR255), GDT_CODE_SEGMENT, idt_flag_ring0 | idt_flag_gate_32bit_int);
}
