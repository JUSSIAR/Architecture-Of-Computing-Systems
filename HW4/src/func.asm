SECTION .data
    res:    dq 0.0
    km:     dq 100.0

section .text
    global func

func:
    push rbp
    mov rbp, rsp

    mov rbx, rsi
    movsd xmm0, [res]
    cvtsi2sd xmm0, rbx
    mulsd xmm0, [km]
    movsd xmm1, [rdi]
    divsd xmm0, xmm1
    leave
    ret