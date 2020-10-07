.global fun1 // точка входа в программу
fun1:
    mov %ecx, %eax
    shr $2, %eax
    shl $2, %eax
    imul $-1, %eax
ret
