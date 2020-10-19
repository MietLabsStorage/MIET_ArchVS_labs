.data
    a: .int 3
    b: .int 4
    c: .int 5

.global _func
_func:
    mov b, %eax
    imul c, %eax
    mov %eax, %ebp      #bc
    sub a, %eax
    neg %eax
    mov %ebp, %ebx
    add a, %ebx

ret


