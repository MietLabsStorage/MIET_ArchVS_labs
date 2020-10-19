.data
    a: .int 13
    b: .int 21
.global _main
_main:
    push b
    push a

    call _func

    addl $2*4, %esp
    xorl %eax, %eax
ret




