#pragma once


#define u32				unsigned long
#define portA			0x40004000
#define portB			0x40005000
#define portC			0x40006000
#define portD			0x40007000
#define portE			0x40024000
#define portF			0x40025000

#define DATA_Offset		0x3FC 
#define DIR_Offset		0x400
#define AFSEL_Offset	0x420
#define PCTL_Offset		0x52C
#define DEN_Offset		0x51C


#define AFSEL_A (*((volatile u32*)(portA + AFSEL_Offset)))
#define DIR_A (*((volatile u32*)(portA + DIR_Offset)))
#define DIR_B (*((volatile u32*)(portB + DIR_Offset)))
#define DIR_C (*((volatile u32*)(portC + DIR_Offset)))
#define DIR_D (*((volatile u32*)(portD + DIR_Offset)))
#define DIR_E (*((volatile u32*)(portE + DIR_Offset)))
#define DIR_F (*((volatile u32*)(portF + DIR_Offset)))
#define DATA_A (*((volatile u32*)(portA + DATA_Offset)))
#define DATA_B (*((volatile u32*)(portB + DATA_Offset)))
#define DATA_C (*((volatile u32*)(portC + DATA_Offset)))
#define DATA_D (*((volatile u32*)(portD + DATA_Offset)))
#define DATA_E (*((volatile u32*)(portE + DATA_Offset)))
#define DATA_F (*((volatile u32*)(portF + DATA_Offset)))
#define DEN_A (*((volatile u32*)(portA + DEN_Offset)))


void GPIO(char PORT, uint32_t PIN, uint32_t DIR)
{
   uint32_t x;
   if (PORT == 'A')
   {
       x = DATA_A;
   }
   if (PORT == 'B')
   {
       x = DATA_B;
   }
   if (PORT == 'C')
   {
       x = DATA_C;
   }
   if (PORT == 'D')
   {
       x = DATA_D;
   }
   if (PORT == 'E')
   {
       x = DATA_E;
   }
   if (PORT == 'F')
   {
       x = DATA_F;
   }
   switch (PIN)
   {
   case 0: x |= (1 << 0); break;
   case 1: x |= (1 << 1); break;
   case 2: x |= (1 << 2); break;
   case 3: x |= (1 << 3); break;
   case 4: x |= (1 << 4); break;
   case 5: x |= (1 << 5); break;
   case 6: x |= (1 << 6); break;
   case 7: x |= (1 << 7); break;
   }

   if (DIR == 0)
   {
       switch (PORT)
       {
       case 'A': DIR_A &= (0 << PIN); break;
       case 'B': DIR_B &= (0 << PIN); break;
       case 'C': DIR_C &= (0 << PIN); break;
       case 'D': DIR_D &= (0 << PIN); break;
       case 'E': DIR_E &= (0 << PIN); break;
       case 'F': DIR_F &= (0 << PIN); break;
       }
   }
   if (DIR == 1)
   {
       switch (PORT)
       {
       case 'A': DIR_A |= (1 << PIN); break;
       case 'B': DIR_B |= (1 << PIN); break;
       case 'C': DIR_C |= (1 << PIN); break;
       case 'D': DIR_D |= (1 << PIN); break;
       case 'E': DIR_E |= (1 << PIN); break;
       case 'F': DIR_F |= (1 << PIN); break;
       }
