.model small
.stack 100h

.data
a2 DW 0
b2 DW 0
c2 DW 6 dup(0)
t0 DW 0
t1 DW 0
t2 DW 0
p0 DW 0
p1 DW 0

.code 
main PROC 

	mov ax, 2
	add ax, 3
	mov t0 , ax
	mov ax, 1
	mov bx, t0
	mul bx
	mov t1, ax
	mov ax, t1
	mov bx, 3
	xor dx , dx
	div bx
	mov t2 , dx
	mov ax, t2
	mov a2, ax
	mov ax, 1
	cmp ax, 5
	jl L0
	mov p0, 0
	jmp L1
L0:
	mov p0, 1
L1:
	mov ax, p0
	mov b2, ax
	mov bx, 0
	add bx, bx
	mov ax, 2
	mov  c2[bx], ax
	mov ax , a2
	cmp ax , 0
	je L2
	mov ax , b2
	cmp ax , 0
	je L2
	mov p1 , 1
	jmp L3
L2:
	mov p1, 0
L3:
	mov ax,p1
	cmp ax,0
	je L4
	mov bx, 0
	add bx, bx
	mov ax,c2[bx]
	mov t0,ax
	inc ax
	mov c2[bx], ax
	jmp L5
L4:
	mov bx, 0
	add bx, bx
	mov ax, c2[bx]
	mov t0, ax
	mov bx, 1
	add bx, bx
	mov ax, t0
	mov  c2[bx], ax
L5:
	mov ax, a
	call DECIMAL_OUT
	mov ax, b
	call DECIMAL_OUT

	mov ah,4ch
	int 21h

main ENDP



DECIMAL_OUT PROC 

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
end main
