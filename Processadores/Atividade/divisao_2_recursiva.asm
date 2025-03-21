#
#	Faça um programa que chama uma rotina recursiva em linguagem de montagem 
#	para o processador MIPS que tem por função dividir um número
#	natural por dois.
#
#	O código em linguagem C é 
#	1.  main(){
#	2. 	int n = 10;
#	3.	int result = 0;
#	4.	result = div2(n);
#	5.  }
#	6.
#	7.  div2(int a){
#	8. 	if(a < 2) return 0;
#	9. 	if(a = 2) return 1;
#	10. 	return (1 + div2(a - 2));
#	11. }
	.data
n:	    .word 	10		# Número cujo fatorial se quer calcular
result:	.word 	0		# variável para guardar o fact(num)

	.text
	.globl	main

# main
main:
    la      $t0, n
	lw	    $t0, 0($t0)
	addiu	$sp, $sp, -8
	sw	    $t0, 4($sp)
    sw	    $ra, 0($sp)
    jal     div2

    lw      $ra, 0($sp) # recupera o endereço

# div2
div2:
    lw      $a0, 4($sp)
	sltiu	$t0, $a0,3
    beq     $t0, $zero, rec
    addiu   $v0, $zero, 1

# ret
ret:
    jr $ra

# rec
rec:
    # addiu	$a0,$a0,-1 ?? 
	addiu 	$sp,$sp,-8