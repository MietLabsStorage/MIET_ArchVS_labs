.data
    a: .int 5
    b: .int 5
    c: .int 5
    x: .int 0
    y: .int 0

.global func
func:
    mov b, %rax
    imul c, %rax
    mov %rax, %rbp
    sub a, %rbp
    mov %rax, %rcx
    add a, %rbp
ret
