extern "C" unsigned long long isprime(unsigned long long x);

asm(R"(
.globl isprime
    .type isprime, @function
    isprime:
    .cfi_startproc
    mov %rdi, %rcx
    push %rbx
    mov $2, %rbx
    test $1, %rcx
    jz FOUND
    inc %rbx
    CYCLE:
    xor %rdx, %rdx
    mov %rcx, %rax
    div %rbx
    cmp %rbx, %rax
    jl NOTFOUND
    cmp $0, %rdx
    je FOUND
    add $2, %rbx
    jmp CYCLE
    FOUND:
    cmp $2, %rcx
    jne GET
    NOTFOUND:
    xor %rbx, %rbx
    GET:
    mov %rbx, %rax
    pop %rbx
    ret
    .cfi_endproc
)");
