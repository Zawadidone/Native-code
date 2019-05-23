# binary-hacking



## Assembler instructions
Registers - accessible location in memory
Stack pointer = SP, ESP, RSP

### Data movement instructions
|Instruction|Description|
|---|---|
|mov|Copies the data time by referred its second operand into the location referred to by its first operand|
|push|Places its operand on the top of the hardware stack in memory| 
|pop|the value of an address wil be saved in the eax register|
|lea|places the address specified by its second operand into the register specified by its first operand|

### Arithmetic and logic Instructions
|Instruction|Description|
|---|---|
|add||
|sub|subtracting the value of its second operand from the value of its first operand|
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
