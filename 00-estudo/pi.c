// Estudo para a pi

// Ordem parâmetros:
// 1. `%rdi`
// 2. `%rsi`
// 3. `%rdx`
// 4. `%rcx`
// 5. `%r8`
// 6. `%r9`

// Operação lea
// C + %R1 + (%R2 * S)

// Exemplo lea:
// lea    (%rsi,%rdi,2),%eax
void lea(long rdi, long rsi) {
    int eax = rsi + 2 * rdi; 
}

// Exemplo movsql:
// movslq %esi,%rsi
void movsql(int esi) {
    long rsi = esi;
}

// Exemplo shr:
// shr %0x3,%rsi
// rsi / 2 elevado a 3
void shr(int esi) {
    long rsi = rsi/ 8;
}

// Example imul:
// imul   %rdi,%rdi
void imul(long rdi) {
    rdi *= rdi;
}

// Example mov:
// mov    $0x0,%eax
// Isto é igual a mov    $0x0,%rax
void mov() {
    long rax = 0;
}

// Example idiv:
// idiv   %rsi
void idiv(long rsi, long rdx, long rcx) {

    // mov    %rcx,%rax
    long rax = rcx;

    // Divisão de %rax por %rsi
    rax = rax/rsi;

    // Divisão de %rax por %rsi
    rdx = rax % rsi;
}

// Exemplo while:

//    0x066a <+0>:	    mov    $0x0,%edx
//    0x066f <+5>:	    mov    $0x0,%eax
//    0x0674 <+10>:	jmp    0x67f <soma_n+21>
//    0x0676 <+12>:	movslq %edx,%rcx
//    0x0679 <+15>:	add    %rcx,%rax
//    0x067c <+18>:	add    $0x1,%edx
//    0x067f <+21>:	cmp    %edi,%edx
//    0x0681 <+23>:	jl     0x676 <soma_n+12>
//    0x0683 <+25>:	repz retq 

long while_example(int edi) {
    //  mov    $0x0,%eax
    long rax = 0;

    //  mov    $0x0,%edx
    long rdx = 0;

    // cmp    %edi,%edx
    while(edi > rdx){
        // jl     0x676 <soma_n+12>
        
        // movslq %edx,%rcx
        // add    %rcx,%rax
        rax+=rdx;

        // add    $0x1,%edx
        rdx++;
    }

    return rax;
}

// Exemplo for

// 0x1139 <+0>:     mov    $0x0,%ecx
// 0x113e <+5>:     mov    $0x0,%r8d
// 0x1144 <+11>:    jmp    0x114a <ex4+17>
// 0x1146 <+13>:    add    $0x1,%rcx
// 0x114a <+17>:    cmp    %rdi,%rcx
// 0x114d <+20>:    jge    0x1161 <ex4+40>
// 0x114f <+22>:    mov    %rcx,%rax
// 0x1152 <+25>:    cqto
// 0x1154 <+27>:    idiv   %rsi
// 0x1157 <+30>:    test   %rdx,%rdx
// 0x115a <+33>:    jne    0x1146 <ex4+13>
// 0x115c <+35>:    add    %rcx,%r8
// 0x115f <+38>:    jmp    0x1146 <ex4+13>
// 0x1161 <+40>:    mov    %r8,%rax
// 0x1164 <+43>:    retq

long for_example(long rdi, long rsi, long rdx){

    // mov    $0x0,%ecx
    long rcx = 0;
    // mov    $0x0,%r8d
    long r8d = 0;

    for(rcx; rcx >= rdi; rcx++) {
        
        // cmp    %rdi,%rcx
        if (rcx >= rdi) {
            
            // jge    0x1161 <ex4+40>
            // mov    %r8,%rax
            long rax = r8d;

            // retq
            return rax;
        } else {
            // mov    %rcx,%rax
            long rax = rcx;

            // cqto
            // Aumenta o registrador de %rax para um registrador de 128 bits
            // Nada em C

            // idiv   %rsi
            // Divisão de %rax por %rsi
            rax = rax/rsi;

            // Divisão de %rax por %rsi
            rdx = rax % rsi;

            // test   %rdx,%rdx
            // jne    0x1146 <ex4+13>
            if (rdx == 0) {
                r8d += rcx;
            }
        }
    }
}

// Example local variable scanf

// 0x1149 <+0>:     push   %rbx
// 0x114a <+1>:     sub    $0x10,%rsp
// 0x114e <+5>:     mov    %edi,%ebx
// 0x1150 <+7>:     lea    0x8(%rsp),%rdx
// 0x1155 <+12>:    lea    0xc(%rsp),%rsi
// 0x115a <+17>:    lea    0xea3(%rip),%rdi        # 0x2004
// 0x1161 <+24>:    mov    $0x0,%eax
// 0x1166 <+29>:    callq  0x1040 <__isoc99_scanf@plt>
// 0x116b <+34>:    mov    0x8(%rsp),%edx
// 0x116f <+38>:    mov    0xc(%rsp),%eax
// 0x1173 <+42>:    lea    (%rax,%rdx,2),%eax
// 0x1176 <+45>:    add    %ebx,%eax
// 0x1178 <+47>:    add    $0x10,%rsp
// 0x117c <+51>:    pop    %rbx
// 0x117d <+52>:    retq

int scanf_example(int edi) {

    // sub    $0x10,%rsp
    // Reservando 16 espaços na pilha para criação de váriaveis locais.

    // mov    %edi,%ebx
    int ebx = edi;

    // lea    0x8(%rsp),%rdx
    int rdx;

    // lea    0xc(%rsp),%rsi
    int rsi;

    // lea    0xea3(%rip),%rdi
    // long rdi = 2004 + rip;
    
    // mov    $0x0,%eax
    int eax = 0;

    // callq  0x1040 <__isoc99_scanf@plt>
    scanf("%d %d", &rsi, &rdx);

    // mov    0x8(%rsp),%edx
    // int edx = &rsp + 8;

    // lea    (%rax,%rdx,2),%eax
    // `C + %R1 + (%R2 * S)`
    eax = rsi + rdx * 2 + ebx;

    return eax;
    
}

// Example local variable 2 scanf

// 0x06ca <+0>:	    push   %rbx
// 0x06cb <+1>:	    sub    $0x10,%rsp
// 0x06cf <+5>:	    movl   $0x1,0xc(%rsp)
// 0x06d7 <+13>:	mov    $0x0,%ebx
// 0x06dc <+18>:	cmpl   $0x0,0xc(%rsp)
// 0x06e1 <+23>:	jle    0x705 <ex5+59>
// 0x06e3 <+25>:	lea    0xc(%rsp),%rsi
// 0x06e8 <+30>:	lea    0xd5(%rip),%rdi        # 0x7c4
// 0x06ef <+37>:	mov    $0x0,%eax
// 0x06f4 <+42>:	callq  0x5a0 <__isoc99_scanf@plt>
// 0x06f9 <+47>:	mov    0xc(%rsp),%eax
// 0x06fd <+51>:	test   %eax,%eax
// 0x06ff <+53>:	jle    0x6dc <ex5+18>
// 0x0701 <+55>:	add    %eax,%ebx
// 0x0703 <+57>:	jmp    0x6dc <ex5+18>
// 0x0705 <+59>:	mov    %ebx,%eax
// 0x0707 <+61>:	add    $0x10,%rsp
// 0x070b <+65>:	pop    %rbx
// 0x070c <+66>:	retq   

int scanf_example_2() {

    int eax;

    // movl   $0x1,0xc(%rsp)
    int var = 1;

    // mov    $0x0,%ebx
    int ebx = 0;

    // cmpl   $0x0,0xc(%rsp)
    while (var > 0) {

        // jle    0x6dc <ex5+18>

        // jmp    0x6dc <ex5+18>

        // callq  0x5a0 <__isoc99_scanf@plt>
        scanf("%d", &var);

        // mov    0xc(%rsp),%eax
        eax = var;

        // test   %eax,%eax
        if (eax > 0) {
            ebx += eax;
            // jmp    0x6dc <ex5+18>
        }

        // jle    0x6dc <ex5+18>
    }

    // jle    0x705 <ex5+59>
    eax = ebx;

    // retq
    return eax;
}

// Example Aritmética e Expressões booleanas

// 0x05fa <+0>:	    lea    (%rdi,%rsi,1),%rax
// 0x05fe <+4>:	    lea    (%rax,%rdx,4),%rcx
// 0x0602 <+8>:	    imul   %rdi,%rdi
// 0x0606 <+12>:	lea    (%rdi,%rsi,2),%rax
// 0x060a <+16>:	add    %rax,%rdx
// 0x060d <+19>:	cmp    %rdx,%rcx
// 0x0610 <+22>:	setge  %al
// 0x0613 <+25>:	movzbl %al,%eax
// 0x0616 <+28>:	retq

int example_ari_bool(long rdi, long rsi, long rdx, long rcx) {
    // lea    (%rdi,%rsi,1),%rax
    long rax =  rdi + (rsi*1);

    // lea    (%rax,%rdx,4),%rcx
    rcx = rax + (rdx*4);

    // imul   %rdi,%rdi
    rdi *= rdi;

    // lea    (%rdi,%rsi,2),%rax
    rax = rdi + (rsi*2);

    // add    %rax,%rdx
    rdx += rax;

   // cmp    %rdx,%rcx
   // setge  %al
   int al = rcx >= rdx;

   return al;
}

// Example function call

// 0x05ff <+0>:	    push   %rbx
// 0x0600 <+1>:	    mov    %rdi,%rbx
// 0x0603 <+4>:	    mov    %rsi,%rdi
// 0x0606 <+7>:	    callq  0x5fa <vezes2>
// 0x060b <+12>:	cmp    %rbx,%rax
// 0x060e <+15>:	jle    0x613 <ex2+20>
// 0x0610 <+17>:	add    %rbx,%rbx
// 0x0613 <+20>:	add    %rbx,%rax
// 0x0616 <+23>:	pop    %rbx
// 0x0617 <+24>:	retq   

long call_function(long rdi, long rsi, long rbx) {

    // mov    %rdi,%rbx
    rbx = rdi;

    // mov    %rsi,%rdi
    rdi = rsi;

    // callq  0x5fa <vezes2>
    long rax =  vezes2(rdi);
     
    // cmp %rbx, %rax
    if (rax <= rbx) {

        // jle    0x613 <ex2+20>

        // add    %rbx,%rax
        rax += rbx;

        // retq
        return rax;

    } else {

        // add    %rbx,%rbx
        rbx += rbx;

        // add    %rbx,%rax
        rax += rbx;

        // retq
        return rax;
    }
}

// Example local variable and call function:

// 0x0616 <+0>:	    push   %rbx
// 0x0617 <+1>:	    mov    $0x0,%ebx
// 0x061c <+6>:	    jmp    0x62b <ex1+21>
// 0x061e <+8>:	    mov    $0x0,%eax
// 0x0623 <+13>:	callq  0x5fa <faz_algo>
// 0x0628 <+18>:	add    $0x1,%ebx
// 0x062b <+21>:	cmpq   $0x0,0x2009dd(%rip)        # 0x201010 <var1>
// 0x0633 <+29>:	jg     0x61e <ex1+8>
// 0x0635 <+31>:	mov    %ebx,%eax
// 0x0637 <+33>:	pop    %rbx
// 0x0638 <+34>:	retq   

extern long var1;

int local_var_function_example() {
    // mov    $0x0,%ebx
    int ebx = 0;

    // mov    $0x0,%eax
    int eax = 0;

    // cmpq   $0x0,0x2009dd(%rip)
    while (var1 > 0) {

        // jg     0x61e <ex1+8>

        // callq  0x5fa <faz_algo>
        faz_algo();

        // add    $0x1,%ebx
        ebx += 1;
    }

    // mov    %ebx,%eax
    eax = ebx;
    return eax;
} 

// Example pointer

// 0x05fa <+0>:	    mov    (%rdx),%rax
// 0x05fd <+3>:	    cmp    %rax,(%rdi)
// 0x0600 <+6>:	    jg     0x60d <ex2+19>
// 0x0602 <+8>:	    add    $0x8,%rdx
// 0x0606 <+12>:	add    (%rdx),%rsi
// 0x0609 <+15>:	mov    %rsi,(%rdi)
// 0x060c <+18>:	retq   
// 0x060d <+19>:	lea    (%rsi,%rsi,2),%rsi
// 0x0611 <+23>:	jmp    0x606 <ex2+12>

void pointer_example(long *rdi, long rsi, long *rdx) {
    // mov    (%rdx),%rax
    long rax = *rdx;

    // cmp    %rax,(%rdi)
    if (*rdi > rax) {

        // jg     0x60d <ex2+19>
        rsi = 3*rsi;

        // 0x0611 <+23>:	jmp    0x606 <ex2+12>
        // add    (%rdx),%rsi
        rsi += *rdx;

        // mov    %rsi,(%rdi)
        *rdi = rsi;

        return;
    } else {
        rax ++;
        *rdx = rax;
        rsi += *rdx;
        *rdi = rsi;
        return;
    }
}

// Example seteg
// cmp    %rdx,%rcx
// setge  %al

int al;
void setge(long rdx, long rcx) {
   if (rcx >= rdx) {
      al = 1;
   } else {
      al = 0;
   }
}
