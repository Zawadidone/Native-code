https://maxkersten.nl/binary-analysis-course/

**Patch Me 0x01**

```assembly
(gdb) disas main
Dump of assembler code for function main:
   0x000000000800064d <+0>:     push   rbp
   0x000000000800064e <+1>:     mov    rbp,rsp
   0x0000000008000651 <+4>:     sub    rsp,0x20
   0x0000000008000655 <+8>:     mov    DWORD PTR [rbp-0x14],edi
   0x0000000008000658 <+11>:    mov    QWORD PTR [rbp-0x20],rsi
=> 0x000000000800065c <+15>:    cmp    DWORD PTR [rbp-0x14],0x0 # compares 1 to 0
   0x0000000008000660 <+19>:    jne    0x8000689 <main+60>
   0x0000000008000662 <+21>:    mov    DWORD PTR [rbp-0x4],0x1
   0x0000000008000669 <+28>:    cmp    DWORD PTR [rbp-0x4],0x2
   0x000000000800066d <+32>:    jne    0x800067d <main+48> # compares 1 to 2
   0x000000000800066f <+34>:    lea    rdi,[rip+0xb9]        # 0x800072f
   0x0000000008000676 <+41>:    call   0x8000510 <puts@plt> # Win
   0x000000000800067b <+46>:    jmp    0x8000693 <main+70>
   0x000000000800067d <+48>:    mov    eax,0x0
   0x0000000008000682 <+53>:    call   0x800063a <fail>
   0x0000000008000687 <+58>:    jmp    0x8000693 <main+70>
   0x0000000008000689 <+60>:    mov    eax,0x0
   0x000000000800068e <+65>:    call   0x800063a <fail>
   0x0000000008000693 <+70>:    mov    eax,0x0
   0x0000000008000698 <+75>:    leave
   0x0000000008000699 <+76>:    ret
End of assembler dump.
(gdb) x/x 0x7ffffffee2dc                                                                                     0x7ffffffee2dc: 0x01 
(gdb) set {int}0x7ffffffee2dc=0                                                                         (gdb)  x/x $rbp-0x14                                                                                         0x7ffffffee2dc: 0x00 
(gdb) x/x $rbp-0x4
0x7ffffffee2ec: 0x01
(gdb) set {int}0x7ffffffee2ec=2
[...]
Win!
(gdb) c
Continuing.
[Inferior 1 (process 455) exited normally]
```

Source C:

```c
#include <stdio.h>
#include <stdlib.h>
 
void fail() {
    printf("Try again!\n");
}
 
int main(int argc, char** argv) {
    if (argc == 0) {
        int x = 1;
        if (x == 2) {
            printf("Win!\n");
        } else {
            fail();
        }
    } else {
        fail();
    }
    return 0;
```

