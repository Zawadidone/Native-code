# Assembly X86 

[Guide to Assembly](https://www.timdbg.com/posts/fakers-guide-to-assembly/)

[x86 Instruction Set Reference](https://c9x.me/x86/)

[x86 Assembly Guide](https://www.cs.virginia.edu/~evans/cs216/guides/x86.html)

[x86 Assembly Wiki](https://en.wikibooks.org/wiki/X86_Assembly)

[x64 cheatsheet](https://cs.brown.edu/courses/cs033/docs/guides/x64_cheatsheet.pdf)

|Defintion|Description|
|---|---|
|Registers|Small areas of memory located on the CPU, where you can store and manipulate data|
|Memory|Where most of the state of an application will really be stored|
|Physical memory|RAM where the lowest address is 0x00000000 (0) and the highest is 0x03FFFFFF (67108863)|
|Virtual memory|An abstraction through which normal applications will access physical memory|
|Page table|Splits the address space of a process into a series of pages|
|Stack|Part of memory|
|Instructions|The basic unit of machine code. An instruction typically performs a single operation|
|Program counter (PC)|A register that tells the CPU which instruction to execute next|
|Calls|System calls are APIs for the interface between the user space and the kernel space|
|Syscalls|The fundamental interface between an application and the Linux Kernel|
|Shared libraries|Other binaries. These are DLLs in Windows, .so files on Linux, or dylibs on Mac|
|Disassembler|Turns machine code into readable text form (Assembly)|

## Memory

![Memory](Program_memory_layout.pdf.jpg)

### Text

The code segment also known as a **text segment**, is where a portion of an object file or the corresponding section of the program's virtual address space that contains executable instructions is stored and is generally read-only and fixed size.

### Data

The **.data segment** contains any global or static variables which have a pre-defined value and can be modified. That is any variables that are not defined within a function (and thus can be accessed from anywhere) or are defined in a function but are defined as static so they retain their address across subsequent calls. Examples, in C, include: 

```c
int val = 3;
char string[] = "Hello World";
```
The values for these variables are initially stored within the read-only memory (typically within .text) and are copied into the .data segment during the start-up routine of the program.

Note that in the above example, if these variables had been declared from within a function, they would default to being stored in the local stack frame. 

### BSS

The **BSS segment**, also known as uninitialized data, is usually adjacent to the data segment. The BSS segment contains all global variables and static variables that are initialized to zero or do not have explicit initialization in source code. For instance, a variable defined as static int i; would be contained in the BSS segment. 

### Heap

The **heap area** commonly begins at the end of the .bss and .data segments and grows to larger addresses from there. The heap area is managed by malloc, calloc, realloc, and free, which may use the brk and sbrk system calls to adjust its size (note that the use of brk/sbrk and a single "heap area" is not required to fulfill the contract of malloc/calloc/realloc/free; they may also be implemented using mmap/munmap to reserve/unreserve potentially non-contiguous regions of virtual memory into the process' virtual address space). The heap area is shared by all threads, shared libraries, and dynamically loaded modules in a process. 

### Stack

The **stack** area contains the program stack, a LIFO structure, typically located in the higher parts of memory. A "stack pointer" register tracks the top of the stack; it is adjusted each time a value is "pushed" onto the stack. The set of values pushed for one function call is termed a "stack frame". A stack frame consists at minimum of a return address. Automatic variables are also allocated on the stack.

The stack area traditionally adjoined the heap area and they grew towards each other; when the stack pointer met the heap pointer, free memory was exhausted. With large address spaces and virtual memory techniques they tend to be placed more freely, but they still typically grow in a converging direction. On the standard PC x86 architecture the stack grows toward address zero, meaning that more recent items, deeper in the call chain, are at numerically lower addresses and closer to the heap. On some other architectures it grows the opposite direction. 

[Where the top of the stack is on x86 ](https://eli.thegreenplace.net/2011/02/04/where-the-top-of-the-stack-is-on-x86/)
[The stack](https://revers.engineering/applied-re-the-stack/)

Every process has at least one thread and every thread has its own stack. And within the stack of every thread, each function has its own stack frame.

**Base pointer (EBP)**

The EBP is the beginning of a stack frame.

**Stack pointer (ESP)**

The ESP always points to the top of the stack. If something is added to the stack, the stack grows. This means the ESP needs to be corrected to the point the new "top" of the stack, which is done by decrementing the ESP.

**Instruction Pointer (EIP)**

The IP register contains the address of the next instruction to be executed if no branching is done. IP can only be read through the stack after a `call` instruction.

**Memory**

The x86 architecture is little-endian, meaning that multi-byte values are written least significant byte first. (This refers only to the ordering of the bytes, not to the bits.) 

## Registers

### General-Purpose registers (GPR)
Registers - accessible location in memory

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

### Status flag registers

The EFLAGS is a 32-bit register used as a collection of bits representing Boolean values to store the results of operations and the state of the processor. 

|Bit|Abbreviation|Flag|Description|
|---|---|---|---|
|0|CF|Carry Flag|Set if the last arithmetic operation carried (addition) or borrowed (subtraction) a bit beyond the size of the register. This is then checked when the operation is followed with an add-with-carry or subtract-with-borrow to deal with values too large for just one register to contain|
|2|PF|Parity Flag|Set if the number of set bits in the least significant byte is a multiple of 2|
|4|AF|Adjust Flag||Carry of Binary Code Decimal (BCD) numbers arithmetic operations|
|6|ZF|Zero Flag|Set if the result of an operation is Zero (0)|
|7|SF|Sign Flag|Set if the result of an operation is negative|
|8|TF|Trap Flag|Set if step by step debugging|
|9|IF|Interruption Flag|Set if interrupts are enabled|
|10|DF|Direction Flag|Stream direction. If set, string operations will decrement their pointer rather than incrementing it, reading memory backward |
|11|OF|Overflow Flag|Set if signed arithmetic operations result in value too large for the register to contain|
|12-13|IOPL|I/O Privilege Level field (2 bits)|I/O Privilege Level of the current process|
|14|NT|Nested Task flag|Controls chaining of interrupts. Set if the current process is linked to the next process|
|16|RF|Resume Flag|Response to debug exceptions|
|17|VM|Virtual-8086 Mode|Set if in 8086 compatibility mode|
|18|AC|Alignment Check|Set if alignment checking of memory references is done|
|19|VIF|Virtual Interrupt Flag|Virtual image of IF|
|20|VIP|Virtual Interrupt Pending flag|Set if an interrupt is pending|
|21|ID|Identification Flag|Support for CPUID instruction if can be set|

## Assembler instructions 

### Data movement instructions
Some of the most important and most frequently used instructions are those that move data. Without them, there would be no way for registers or memory to even have anything in them to operate on. 

|Instruction|Example|Description|
|---|---|---|
|mov|`mov dest, src`|The mov instruction copies the `src` operand into `the` dest operand|
|lea|lea `dest`, `src`|The `lea` instruction calculates the address of the `src` operand and loads it into the `dest` operand|
|xchg|xchg `dest`, `src`|The xchg instruction swaps the `src` operand with the `dest` operand. It's like doing three-move operations: from `dest` to a temporary (another register), then from `src` to `dest`, then from the temporary to `src`, except that no register needs to be reserved for temporary storage|
|cmpxchg|cmpxchg `arg1`, `arg2`|The instruction compares arg1 to AL/AX/EAX and if they are equal sets arg1 to arg2 and sets the zero flag, otherwise it sets AL/AX/EAX to arg1 and clears the zero flag|
|movzx|movzx `dest`, `src`|The movz instruction copies the `src` operand in the `dest` operand and pads the remaining bits not provided by src with zeros (0)|
|movsx|movsx `dest`, `src`|The movs instruction copies the `src` operand in the `dest` operand and pads the remaining bits not provided by `src` with the sign bit (the MSB) of `src`|
|movsb|movsb|The `movsb` instruction copies one byte from the memory location specified in `esi` to the location specified in `edi`. If the direction flag is cleared, then `esi` and `edi` are incremented after the operation. Otherwise, if the direction flag is set, then the pointers are decremented. In that case, the copy would happen in the reverse direction, starting at the highest address and moving toward lower addresses until `ecx` is zero.|
|movsw|movsw|The `movsw` instruction copies one word (two bytes) from the location specified in `esi` to the location specified in `edi`. It basically does the same thing as `movsb`, except with words instead of bytes. |



### Arithmetic and logic Instructions
Arithmetic instructions take two operands: a destination and a source. The destination must be a register or a memory location. The source may be either a memory location, a register or a constant value. Note that at least one of the two must be a register, because operations may not use a memory location as both a source and a destination. 

|Instruction|Example|Description|
|---|---|---|
|add|add `dest`, `src`|This adds `src` to `dest`|
|sub|sub `dest`, `src`|Like ADD, only it subtracts source from destination instead. In C: `dest -= src;`|
|mul|mul `arg`|This multiplies `arg` by the value of corresponding byte-length in the `AX` register|
|div|div `arg`|This divides the value in the dividend register(s) by `arg` and stores the result in the `EAX` and the rest in `EDX`.|
|idiv|idiv `arg`|As div, only signed|
|neg|neg `arg`|Arithmetically negates the argument (i.e. two's complement negation)|
|adc|adc `dest`, `src`|Add with carry. Adds `src` + `CF` to `dest`, storing result in `dest`. Usually follows a normal add instruction to deal with values twice as large as the size of the register. In the following example, `source` contains a 64-bit number which will be added to `destination`|
|sbb|sbb `dest`, `src`|Subtract with borrow. Subtracts `src` + `CF` from `dest`, storing result in `dest`|
|inc|inc `arg`|Increments the register value in the argument by 1. Performs much faster than `add arg, 1`|
|dec|dec `arg`|Decrements the register value in the argument by 1. Performs much faster than `sub arg, 1`|

### Control flow instruction
Almost all programming languages have the ability to change the order in which statements are evaluated, and assembly is no exception. The instruction pointer (EIP) register contains the address of the next instruction to be executed. To change the flow of control, the programmer must be able to modify the value of EIP. This is where control flow functions come in. 

|Instruction|Example|Description|
|---|---|---|
|test|test `arg1`, `arg0`|Performs a bit-wise logical `and` on `arg0` and `arg1` the result of which we will refer to as `commonBits` and sets the `ZF`(zero), `SF`(sign) and `PF` (parity) flags based on `commonBits`|
|cmp|cmp `minuend`, `subtrahend`|Performs a comparison operation between `minuend` and `subtrahend`. The comparison is performed by a (signed) subtraction of `subtrahend` from `minuend`, the results of which can be called `difference`. `Difference` is then discarded. If `subtrahend` is an immediate value it will be sign extended to the length of `minuend`. The `EFLAGS` register is set in the same manner as a `sub` instruction|
|jmp|jmp `loc`|Loads `EIP` with the specified address (i.e. the next instruction executed will be the one specified by `jmp`)|
|je|je `loc`|Loads `EIP` with the specified address, if operands of previous `cmp` instruction are equal: `ZF=1`|
|jne|jne `loc`|Loads `EIP` with the specified address, if operands of previous `cmp` instruction are not equal: `ZF=0`|
|jg|jg `loc`|Loads `EIP` with the specified address, if the `minuend` of the previous `cmp` instruction is greater than the second (performs signed comparison): `SF=0`, `ZF=0`|
|jge|jge `loc`|Loads `EIP` with the specified address, if the `minuend` of the of previous `cmp` instruction is greater than or equal to the `subtrahend` (performs signed comparison): `SF=OF`, `ZF=1`|
|ja|ja `loc`|Loads `EIP` with the specified address, if the `minuend` of the previous `cmp` instruction is greater than the `subtrahend`. `ja` is the same as `jg`, except that it performs an unsigned comparison: `CF=0`, `ZF=0`|
|jae|jae `loc`|Loads `EIP` with the specified address, if the `minuend` of previous `cmp` instruction is greater than or equal to the `subtrahend`. `jae` is the same as `jge`, except that it performs an unsigned comparison: `CF=0`, `ZF=1`|
|jl|jl `loc`|The criterion required for a `jl` is that `SF` ≠ `OF`. It loads `EIP` with the specified address if the criterion is met. So either `SF` or `OF` can be set, but not both in order to satisfy this criterion|
|jle|jle `loc`|Loads EIP with the specified address, if the minuend of previous cmp instruction is lesser than or equal to the subtrahend: `SF`≠`OF` or `ZF=1`|
|jb|jb `loc`|Loads `EIP` with the specified address, if first operand of previous CMP instruction is lesser than the second. `jb` is the same as `jl`, except that it performs an unsigned comparison: `CF=1`|
|jbe|jbe `loc`|Loads EIP with the specified address, if minuend of previous cmp instruction is lesser than or equal to the subtrahend. jbe is the same as jle, except that it performs an unsigned comparison: `CF=1` or `ZF=1`|
|jo|jo `loc`|Loads `EIP` with the specified address, if the overflow bit is set on a previous arithmetic expression: `OF=1`|
|jno|jno `loc`|Loads `EIP` with the specified address, if the overflow bit is not set on a previous arithmetic expression: `OF=0`|
|jz|jz `loc`|Loads `EIP` with the specified address, if the zero bit is set from a previous arithmetic expression. `jz` is identical to `je`: `ZF=1`|
|jnz|jnz `loc`|Loads `EIP` with the specified address, if the zero bit is not set from a previous arithmetic expression. `jnz` is identical to `jne`: `ZF=0`|
|js|js `loc`|Loads `EIP` with the specified address, if the sign bit is set from a previous arithmetic expression: `SF=1`|
|jns|jns `loc`|Loads `EIP` with the specified address, if the sign bit is not set from a previous arithmetic expression: `SF=0`|

### Other instructions

|Instruction|Example|Description|
|---|---|---|
|mov BYTE PTR|mov BYTE PTR `dest, src`|Move `src` into the single byte at the address stored in `dest`|
|mov WORD PTR|mov WORD PTR `dest, src`|Move the 16-bit integer representation of `src` into the 2 bytes starting at the address in `dest`|
|mov DWORD PTR|mov DWORD PTR `dest, src`|Move the 32-bit integer representation of `src` into the 4 bytes starting at the address in `dest`|
|call|call `proc`|Pushes the address of the instruction that follows the `call`, i.e. usually the next line in your source code, onto the top of the stack, and then jumps to the specified location|
|push|push `arg`|This instruction decrements the stack pointer and stores the data specified as the argument into the location pointed to by the stack pointer|
|pop|pop `arg`|This instruction loads the data stored in the location pointed to by the stack pointer into the argument specified and then increments the stack pointer|
|ret|ret `[val]`|Loads the next value on the stack into `EIP`, and then pops the specified number of bytes off the stack. If `val` is not supplied, the instruction will not pop any values off the stack after returning|
|loop|loop `arg`|The `loop` instruction decrements `ECX` and jumps to the address specified by `arg` unless decrementing `ECX` caused its value to become zero|
|loopcc|loopcc `arg`|These loop instructions decrement `ECX` and jump to the address specified by `arg` if their condition is satisfied (that is, a specific flag is set), unless decrementing `ECX` caused its value to become zero|
|enter||`enter` creates a stack frame with the specified amount of space allocated on the stack|
|leave||`leave` destroys the current stack frame, and restores the previous frame|
|hlt||Halts the processor. Execution will be resumed after processing next hardware interrupt, unless `IF` is cleared|
|nop||No operation. This instruction doesn't do anything, but wastes (an) instruction cycle(s) in the processor|
|lock||Asserts #LOCK prefix on next instruction|
|wait||Waits for the FPU to finish its last calculation|

### Calling convetions

**Call**

A Call is just an unconditional GOTO that pushes the next address on the stack, so  RET instructions can later pop it off and keep going where the Call left off.

|Convention|Description|
|---|---|
|stdcall|In the `stdcall`, function arguments are passed from right to left and the caleé is in charge of cleaning up the stack. Return values are stored in `EAX`. The `stdcall` is a combination of two other calling conventions, `pascal` and `cdecl`|
|cdecl|The `cdecl` (short for c declaration) is a calling convention that originates from the C programming language and is used by many C compilers for the x86 architecture. The main difference of `cdecl` and `stdcall` is that in a `cdecl`, the caller, not the calleé, is responsible for cleaning up the stack|
|pascal|The `pascal` calling convention origins from the Pascal programming language and the ain difference between it and `stcall` is that the parameters are pushed to the stack from left to right|
|fastcall|The `fastcall` is a non-standardized calling convention. It is usually recognized through the way it sends function arguments. While all the above conventions use the stack to store the function arguments, the fastcall convention tends to load them into registers. This results in less memory interaction and increases the performance of a call, hence the name|


## Bits

### Bitwise instructions
|Instruction|Example|Description|
|---|---|---|
|and|and `dest`, `src`|Performs a bit-wise `and` of the two operands, and stores the result in `dest`|
|or|or `dest`, `src`|Performs a bit-wise `or` of the two operands, and stores the result in `dest`|
|xor|xor `dest`, `src`|Performs a bit-wise `xor`of the two operands, and stores the result in `dest`|
|not|not `arg`|Performs a bit-wise inversion of `arg`|
|shr|shr `dest`, `src`|Logical shift `dest` to the right by `src` bits|
|shl|shl `dest`, `src`|Logical shift `dest` to the left by `src` bits|
|sar|sar `dest`, `src`|Arithmetic shift `dest` to the right by `src` bits. Spaces are filled with sign bit (to maintain sign of original value), which is the original highest bit|
|sal|sal `dest`, `src`|Arithmetic shift `dest` to the left by `src` bits. The bottom bits do not affect the sign, so the bottom bits are filled with zeros|
|shld|shld `dest`, `src`, `cnt`|The operation performed by `shld` is to shift the most significant `cnt` bits out of `dest`, but instead of filling up the least significant bits with zeros, they are filled with the most significant `cnt` bits of `src`|
|shrd|shrd `dest`, `src`, `cnt`|Likewise, the `shrd` operation shifts the least significant `cnt` bits out of `dest`, and fills up the most significant `cnt` bits with the least significant bits of the `src` operand|
|ror|ror `dest`, `src`|Rotate `dest` to the right by `src` bits|
|rol|ror `dest`, `src`|Rotate `dest` to the left by `src` bits|
|rcr|rcr `dest`, `src`|Rotate `dest` to the right by `src` bits with carry|
|rcl|rcl `dest`, `src`|Rotate `dest` to the left by `src` bits with carry|

### Data types

|Data type|Bits|Max value|
|---|---|---|
|bit|1-bit|0-1|
|byte|8-bit|0-255|
|word|16-bit|65535|
|dword|32-bit|4294967295|

### Bitwise operators

**NOT** - Bits that are 0 become 1 and those that are 1 become 1:
```
0111  (decimal 7)
1000  (decimal 8)
```

**And** - Perform the AND operation on each of corresponding bits by multiplying the corresponding bits:
```
0101 (decimal 5)
0011 (decimal 3)
0001
```

**OR** - Perform the OR operation on each of corresponding bits. The result is 0 if both bits are 0, while otherwise, the result is 1:
```
0101 (decimal 5)
0011 (decimal 3)
0111 (decimal 7)
```

**XOR** - Perform the OR operation on each pair of corresponding bits. The result in each position is 1 if only the first bit is 1 or only the second bit is, but will be 0 if both are 1. In this we perform the comparison of two bits, being 1 if the two bits are different, and 0 if they are the same:
```
0101 (decimal 5)
0011 (decimal 3)
0110 (decimal 6)
```

### Bit shifts
The bit shifts are sometimes considered bitwise operations because they treat a value as a series of bits rather than as a numerical quantity. In these operations, the digits are moved, or shifted, to the left or right. Registers in a computer processor have a fixed width, so some bits wil be "shifted out" of the register at one end, while the same number of bits are "shifted in" from the other end.

#### Arithmetic shift
In an arithmetic shift, the bits that are shifted out of either end are discarded.

**LEFT-SHIFT** - Zeros are shifted in on the right
```
00010111 (decimal +23)
00101110 (decimal +46)
```

**RIGHT-SHIFT** - Bits are shift to the right and the sign bit is shifted in on the left

``` 
10010111
11001011
```

#### Logical shift
In a logical shift, zeros are shifted in to replace the discarded bits. Therefore, logical and arithmetic left-shifts are exactly the same. However, as the logical right-shift insert value 0 bits into the most significant bit, instead of copying the sign bit.

**Left logical shift** - Bits are shifted to the left 
```
00010111
00101110
```

**Right logical shift** - Bits are shifted to the right 
``` 
00010111
00001011
```

#### Circular shift
Bitwise rotation orbit rotation

**Left circular shift** -  Bits are shifted to the left and the value shifted out is the sign bit
``` 
00010111
00101110
```

**Right circular shift** - Bits are shifted to the right and the sign bit is added to left
``` 
00010111
10001011
```

#### Rotate trough carry
Variant of the rotate operation, where the bit that is shifted in is the old value of the carry flag.

**Left rotate through carry** - Bits are shifted to the left and the value shifted out is the carry flag
```
00010111 C 1
00101111
```

**Right rotate through carry** - Bits are shifted to the right and the carry flag is added to the left 
``` 
00010111 C 1
10001011
```


