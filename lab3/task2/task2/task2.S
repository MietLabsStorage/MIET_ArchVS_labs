.data
    msg: .string "%d %% 4 - %d  = %d\n"
    x: .int 13

.global _main
_main:
    mov x, %eax
    shr $2, %eax
    shl $2, %eax
    imul $-1, %eax

    push %eax
    push x
    push x
    push $msg
    call _printf

    addl $4*4, %esp
    xor %eax, %eax
ret



