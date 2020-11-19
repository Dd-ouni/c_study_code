	.file	"add.c"
	.text
	.globl	_add
	.def	_add;	.scl	2;	.type	32;	.endef
_add:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	movb	$10, -1(%ebp)
	movb	$10, -2(%ebp)
	movzbl	-1(%ebp), %edx
	movzbl	-2(%ebp), %eax
	addl	%edx, %eax
	movb	%al, -3(%ebp)
	leave
	ret
	.ident	"GCC: (i686-posix-sjlj, built by strawberryperl.com project) 4.9.2"
