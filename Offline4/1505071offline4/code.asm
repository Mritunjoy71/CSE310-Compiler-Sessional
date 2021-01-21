.MODEL SMALL
.STACK 100h

.DATA
return DW ?
a2 DW ?
b2 DW ?
t0 DW ?
t1 DW ?
t2 DW ?
t3 DW ?
t4 DW ?
t5 DW ?
c2 DW 6 DUP(?)
.CODE
main PROC
	MOV AX, 2
	MOV BX, 3
	ADD AX,BX
	MOV t0, AX
	MOV AX, 1
	MOV BX, t0
	MUL BX
	MOV t1, AX
	MOV AX, t1
	MOV BX, 3
	MOV DX , 0
	DIV BX
	MOV t2, DX
	MOV AX ,t2
	MOV a2, AX
	MOV AX, 1
	CMP AX, 5
	JL L0
	MOV t3, 0
	JMP L1
L0:
	MOV t3, 1
L1:
	MOV AX ,t3
	MOV b2, AX
	MOV BX, 0
	SHL BX, 1
	MOV AX ,2
	MOV c2[BX], AX
	MOV AX , a2
	CMP AX , 0
	JE L2
	MOV AX , b2
	CMP AX , 0
	JE L2
	MOV t4 , 1
	JMP L3
L2:
	MOV t4, 0
L3:
	MOV AX,t4
	CMP AX,0
	JE L4
	MOV BX, 0
	SHL BX, 1
	MOV AX , c2
	ADD AX , 1
	MOV c2 , AX
	JMP L5
L4:
	MOV BX, 0
	SHL BX, 1
	MOV AX, c2[BX]
	MOV t5, AX
	MOV BX, 1
	SHL BX, 1
	MOV AX ,t5
	MOV c2[BX], AX
L5:
	MOV AX, a2
	call DECIMAL_OUT
	MOV AX, b2
	call DECIMAL_OUT
	MOV AH,4CH
	INT 21H
main ENDP



DECIMAL_OUT PROC NEAR

	push ax
	push bx
	push cx
	push dx
	or ax,ax
 	jge enddif
	push ax
	mov dl,'-'
	mov ah,2
	int 21h
	pop ax
	neg ax
enddif:
	xor cx,cx
	mov bx,10d
repeat:
	xor dx,dx
	div bx
	 push dx
	inc cx
	or ax,ax
	jne repeat
	mov ah,2
print_loop:
	pop dx
	or dl,30h
	int 21h
	loop print_loop
	pop dx
	pop cx
	pop bx
	pop ax
	ret

DECIMAL_OUT ENDP
