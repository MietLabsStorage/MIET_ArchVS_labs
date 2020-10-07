.data
    msg: .string "%d mod 4 - 4 = %d\n"
    x: .int 13

.global main
main:
    mov x, %rax
    shr $2, %rax
    shl $2, %rax
    imul $-1, %rax

    push x
    push %rax
    push $msg
    call printf

    addl $3*4, %esp
    xor %rax, %rax
ret

