# [Native-code](https://www.hacker101.com/sessions/native_code_crash_course)
Any code that is compiled to machine code.

[x86 Assembly Guide](https://www.cs.virginia.edu/~evans/cs216/guides/x86.html)

[x86 Assembly Wiki](https://en.wikibooks.org/wiki/X86_Assembly)

[Writing Secure Code](https://www.cprogramming.com/tutorial/secure.html)


|||
|---|---|
|Registers|Small areas of memory located in the CPU, where you can store and manipulate data|
|Memory|Where most of the state of an application will really be stored|
|Physical memory|RAM where the lowest address is 0x00000000 (0) and the highest is 0x03FFFFFF (67108863)|
|Virtual memory|An abstraction through which normal applications will access physical memory|
|Page table|Splits the address space of a process into a series of pages|
|Stack|Part of memory|
|Instructions|The basic unit of machine code. An instruction typically performs a single operation|
|Program counter (PC)|A register that tells the CPU which instruction to execute next|
|Calls||
|Syscalls|The fundamental interface between an application and the Linux Kernel|
|Shared libraries|Other binaries. These are DLLs in Windows, .so files on Linux, or dylibs on Mac|
|Disassembler|Turns machine code into readable text form (Assembly)|
|||
|||
|||
|||

Make your own operating system
* [Linux from scratch](http://www.linuxfromscratch.org/)
* [OSDev](https://wiki.osdev.org/Main_Page)
* [How to Make a Computer Operating System in C++](https://github.com/SamyPesse/How-to-Make-a-Computer-Operating-System)

Interactive Disassemblers
* IDA Pro - Gold standard
* Hopper - Good for MacOS and iOS apps particularly
* Ghidra - NSA's open source tool

Non-Interactive Disassemblers
* objdump - Comes with GNU binutils, works wel for binaries from Unix-like systems
* ODA - Online disassembler, good for small bits of shellcode
* Radare2 - Fully featured reverse-engineering framework, great disassembler

Decompilers
Allow you to turn machine code back into something resembling C.

Debuggers
Allow you to look at a running application and see what the state of its registers, memory, etc are at any point.

* GDB
* LLDB
* WinDb
* OllyDg

Hex Editors (0xED, HxD, Ghex)
Allow you to easy manipulate values or machine code inside a binary.

Assemblers 
Takes assembly code and convert it to machine code.
* Shell storm
* GNU Assembler 
* Netwide Assembler

## Bits

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

**OR** - Perform the OR operation on each of corresponding bits. The result is 0 if both bits are 0, while otherwise the result is 1:
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
The bit shifts are sometimes considered bitwise operations, because they treat a value as a series of bits rather than as a numerical quantity. In these operations the digits are moved, or shifted, to the left or right. Registers in a computer processor have a fixed width, so some bits wil be "shifted out" of the register at one end, while the same number of bits are "shifted in" from the other end.

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
In a logical shift, zeros are shifted in to replace the discarded bits. Therefore, the logical and arithmetic left-shifts are exactly the same. However, as the logical right-shift insert value 0 bits into the most significant bit, instead of copying the sign bit.

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
Bitwise rotation or bit rotation

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
