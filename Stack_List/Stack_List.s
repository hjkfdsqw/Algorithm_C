	.file	"Stack_List.c"
	.section .rdata,"dr"
LC0:
	.ascii "Memory allocation Error\0"
	.text
	.globl	_StackPush
	.def	_StackPush;	.scl	2;	.type	32;	.endef
_StackPush:
LFB14:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$8, (%esp)
	call	_malloc
	movl	%eax, -12(%ebp)
	cmpl	$0, -12(%ebp)
	jne	L2
	movl	$LC0, (%esp)
	call	_puts
	jmp	L1
L2:
	movl	-12(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%eax)
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%edx, 4(%eax)
	movl	8(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%eax)
L1:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE14:
	.section .rdata,"dr"
LC1:
	.ascii "Stack is Empty\0"
	.text
	.globl	_StackPop
	.def	_StackPop;	.scl	2;	.type	32;	.endef
_StackPop:
LFB15:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	je	L5
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	4(%eax), %edx
	movl	8(%ebp), %eax
	movl	%edx, (%eax)
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -16(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	_free
	movl	-16(%ebp), %eax
	jmp	L6
L5:
	movl	$LC1, (%esp)
	call	_puts
	movl	$-1, %eax
L6:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE15:
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC2:
	.ascii "Input Pop value : %d\12\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB16:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$32, %esp
	call	___main
	movl	$0, 24(%esp)
	movl	$1, 4(%esp)
	leal	24(%esp), %eax
	movl	%eax, (%esp)
	call	_StackPush
	movl	$2, 4(%esp)
	leal	24(%esp), %eax
	movl	%eax, (%esp)
	call	_StackPush
	movl	$3, 4(%esp)
	leal	24(%esp), %eax
	movl	%eax, (%esp)
	call	_StackPush
	movl	$4, 4(%esp)
	leal	24(%esp), %eax
	movl	%eax, (%esp)
	call	_StackPush
	movl	$5, 4(%esp)
	leal	24(%esp), %eax
	movl	%eax, (%esp)
	call	_StackPush
	movl	$0, 28(%esp)
	jmp	L8
L9:
	leal	24(%esp), %eax
	movl	%eax, (%esp)
	call	_StackPop
	movl	%eax, 4(%esp)
	movl	$LC2, (%esp)
	call	_printf
	addl	$1, 28(%esp)
L8:
	cmpl	$4, 28(%esp)
	jle	L9
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE16:
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_malloc;	.scl	2;	.type	32;	.endef
	.def	_puts;	.scl	2;	.type	32;	.endef
	.def	_free;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
