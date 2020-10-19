.data
    msg: .string "x=%d, y=%d\n"

.globl _main
_main:
    call _func
    push %ebx
    push %eax
    push $msg
    call _printf
    addl $3*4, %esp
ret


