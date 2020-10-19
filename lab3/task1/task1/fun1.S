
.global _fun1 // точка входа в программу
_fun1:
    mov -4(%esp), %eax
    shr $2, %eax
    shl $2, %eax
    imul $-1, %eax
ret

