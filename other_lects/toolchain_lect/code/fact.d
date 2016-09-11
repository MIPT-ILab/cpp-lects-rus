
fact.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <fact>:
   0:	83 ff 01             	cmp    $0x1,%edi
   3:	b8 01 00 00 00       	mov    $0x1,%eax
   8:	76 13                	jbe    1d <fact+0x1d>
   a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
  10:	0f af c7             	imul   %edi,%eax
  13:	83 ef 01             	sub    $0x1,%edi
  16:	83 ff 01             	cmp    $0x1,%edi
  19:	75 f5                	jne    10 <fact+0x10>
  1b:	f3 c3                	repz retq 
  1d:	f3 c3                	repz retq 
