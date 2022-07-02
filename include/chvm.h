#ifndef _CHVM_H
#define _CHVM_H

#define MEMORY_SIZE 65535 * 16 + 65535
static char memory[MEMORY_SIZE];

/**
 * --- ADD --- 
 * 0x00: ADD r/m8, reg8
 * 0x01: ADD r/m16, reg16
 * 0x02: ADD reg8, r/m8
 * 0x03: ADD reg16, r/m16
 * 0x04: ADD AL, imm8
 * 0x05: ADD AX, imm16
 * 0x06: ADD r/m8, imm8
 * 0x07: ADD r/m16, imm16
 * 0x08: ADD r/m16, imm8
 * 
 * --- NOTES ---
 * reg8 = 8-bit register
 * 		* AL = 0
 * 		* CL = 1
 * 		* DL = 2
 * 		* BL = 3
 * 		* AH = 4
 * 		* CH = 5
 * 		* DH = 6
 * 		* BH = 7
 * 
 * reg16 = 16-bit register
 * 		* AX = 0
 * 		* CX = 1
 * 		* DX = 2
 * 		* BX = 3
 * 		* SP = 4
 * 		* SI = 5
 * 		* DI = 6
 * 
 * sreg = segment/pointer register
 * 		* IP = 0
 * 		* SS = 1
 * 		* CS = 2
 * 
 * mem8 = memory byte (direct addressing only)
 * mem16 = memory word (direct addressing only)
 * r/m8 = reg8 or mem8
 * r/m16 = reg16 or mem16
 * imm8 = 8-bit immediate
 * imm16 = 16-bit immediate
 */
enum Instructions {
	ADD_RM8_REG8,
	ADD_RM16_REG16,
	ADD_REG8_RM8,
	ADD_REG16_RM16,
	ADD_AL_IMM8,
	ADD_AX_IMM16,
	ADD_RM8_IMM8,
	ADD_RM16_IMM16,
	ADD_RM16_IMM8
};

int vm_run(char*);

#endif