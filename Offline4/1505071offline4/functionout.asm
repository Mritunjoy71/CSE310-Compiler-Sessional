.MODEL SMALL
.STACK 100h

.DATA
return DW ?
a2 DW ?
t0 DW ?
a3 DW ?
b3 DW ?
x3 DW ?
t1 DW ?
t2 DW ?
t3 DW ?
a4 DW ?
b4 DW ?
t4 DW ?
.CODE
main PROC
	MOV AX ,1
	MOV a4, AX
	MOV AX ,2
	MOV b4, AX
	MOV a2, 2
	MOV AX, a2
	MOV a4, AX
	CALL f
	MOV AX, return
	MOV t4, AX
	MOV AX ,t4
	MOV a4, AX
	MOV AX, a4
	call DECIMAL_OUT
	MOV AX,0
	MOV return, AX
	MOV AH,4CH
	INT 21H
main ENDP

f PROC
	MOV AX, 2
	MOV BX, a2
	MUL BX
	MOV t0, AX
	MOV AX,t0
	MOV return, AX
	MOV AX ,9
	MOV a2, AX
	RET
f ENDP

g PROC
	MOV AX, a2
	MOV a3, AX
	CALL f
	MOV AX, return
	MOV t1, AX
	MOV AX, t1
	MOV BX, a3
	ADD AX,BX
	MOV t2, AX
	MOV AX, t2
	MOV BX, b3
	ADD AX,BX
	MOV t3, AX
	MOV AX ,t3
	MOV x3, AX
	MOV AX,x3
	MOV return, AX
	RET
g ENDP



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
