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
    mov $3, %rbx
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
    NOTFOUND:
    xor %rbx, %rbx
    FOUND:
    mov %rbx, %rax
    pop %rbx
    ret
    .cfi_endproc
)");
