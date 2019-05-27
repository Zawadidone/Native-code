# Assembly X86 - 64-bit version of the x86 instruction set

## Registers

### General-Purpose registers (GPR)

|General-Purpose registers (GPR)|16-bit naming conventions|
|---|---|
|Accumulator register (AX)|Used in arithmetic operations|
|Counter register (CX)|Used in shift/rotate instructions and loops|
|Data register (DX)|Used in arithmetic operations and I/O operations|
|Base register (BX)|Used as a pointer to data (located in segment register DS, when in segmented mode)|
|Stack Pointer register (SP)|Pointer to the top of the stack|
|Stack Base Pointer register (BP)|Used to point to the base of the stack|
|Source Index register (SI)|Used as a pointer to a source in stream operations|
|Destination Index register (DI)|Used as a pointer to a destination in stream operations|

![Identifiers to access registers and parts therof](identifiers-registers.png)

The EFLAGS is a 32-bit register used as a collection of bits representing Boolean values to store the results of operations and the state of the processor. 


|Bit|Flag|Name|Description|
|---|---|---|---|
|0|CF|Carry Flag|Set if the last arithmetic operation carried (addition) or borrowed (subtraction) a bit beyond the size of the register. This is then checked when the operation is followed with an add-with-carry or subtract-with-borrow to deal with values too large for just one register to contain.|
|||||
|||||
|||||
|||||
|||||
|||||
|||||
|||||
|||||
|||||
|||||
|||||

2. 	PF : Parity Flag. Set if the number of set bits in the least significant byte is a multiple of 2.
4. 	AF : Adjust Flag. Carry of Binary Code Decimal (BCD) numbers arithmetic operations.
6. 	ZF : Zero Flag. Set if the result of an operation is Zero (0).
7. 	SF : Sign Flag. Set if the result of an operation is negative.
8. 	TF : Trap Flag. Set if step by step debugging.
9. 	IF : Interruption Flag. Set if interrupts are enabled.
10. 	DF : Direction Flag. Stream direction. If set, string operations will decrement their pointer rather than incrementing it, reading memory backwards.
11. 	OF : Overflow Flag. Set if signed arithmetic operations result in a value too large for the register to contain.
12-13. 	IOPL : I/O Privilege Level field (2 bits). I/O Privilege Level of the current process.
14. 	NT : Nested Task flag. Controls chaining of interrupts. Set if the current process is linked to the next process.
16. 	RF : Resume Flag. Response to debug exceptions.
17. 	VM : Virtual-8086 Mode. Set if in 8086 compatibility mode.
18. 	AC : Alignment Check. Set if alignment checking of memory references is done.
19. 	VIF : Virtual Interrupt Flag. Virtual image of IF.
20. 	VIP : Virtual Interrupt Pending flag. Set if an interrupt is pending.
21. 	ID : Identification Flag. Support for CPUID instruction if can be set.

**Instruction Pointer (EIP)**
The EIP register contains the address of the next instruction to be executed if no branching is done. EIP can only be read trough the stack after a `call` instruction.

## Assembler instructions
Registers - accessible location in memory
Stack pointer = SP, ESP, RSP

### Data movement instructions
|Instruction|Description|
|---|---|
|mov|Copies the data time by referred its second operand into the location referred to by its first operand|
|push|Places its operand on the top of the hardware stack in memory| 
|pop|the value of an address wil be saved in the eax register|
|lea|Places the address specified by its second operand into the register specified by its first operand|

### Arithmetic and logic Instructions
|Instruction|Description|
|---|---|
|add||
|sub|Subtracts the value of its second operand from the value of its first operand|
|inc||
|dec||
|imul||
|idiv||
|and||
|or||
|xor||
|not||
|negate||
|shl||
|shr||
|jmp||

### Control flow instruction
|Instruction|Description|
|---|---|
|jmp||
|j||
|cmp||
|call||
|ret||
A Call is just an unconditional GOTO that pushes the next address  on the stack, so  RET instrutions can later pop it off and keep going where the Call left off.

https://www.cs.virginia.edu/~evans/cs216/guides/x86.html
