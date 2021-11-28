STRUCT: equ 8
INT: equ 4

SECTION .data
    buff:   db 0x00
    var1:   db 0
    var2:   db 0

SECTION .bss
    arr1:   resb 100
    arr2:   resb 100

SECTION .text
    global sort

sort:
    mov rax, [rdi + STRUCT*2+INT]
    ret

    mov rbx, 5
    mov rax, 0
    .loop:
        add rax, 2
        dec rbx
        cmp rbx, 0
        jnz .loop

    ;mov rdi, buff
    ;mov [rdi], ebp
    ;mov rax, [rdi]
    ret