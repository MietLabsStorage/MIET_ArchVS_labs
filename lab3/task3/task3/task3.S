.data
    a: .int 13
    b: .int 21
.global main
main:
    push a
    push b
    call func

    mov $0, %eax
ret


