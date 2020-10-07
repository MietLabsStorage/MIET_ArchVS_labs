.data
    msg: .string "x=%d, y=%d\n"
.globl main
main:
    call func
    push %rax
    push %rcx
    call printf
ret
