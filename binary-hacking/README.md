# binary-hacking



## Assembler instructions
X

### Functions 
|||
|---|---|
|add|adds a value to an address| 
|push|adds a value to the next address | 
|move|moves a value to an address|
|sub|subtract an address to address|
|pop|the value of an address wil be saved in the eax register|


A Call is just an unconditional GOTO that pushes the next address  on the stack, so  RET instrutions can later pop it off and keep going where the Call left off.

