.model small
.stack 100h

.data
a2 DW 0
a3 DW 0
b3 DW 0
x3 DW 0
a4 DW 0
b4 DW 0
t0 DW 0
t1 DW 0
t2 DW 0
t3 DW 0

.code 
f proc 

	mov ax, 9
	mov a2, ax
	mov ax, 2
	mov bx, a2
	mul bx
	mov t0, ax
	mov ax,t0
	pop bp
	ret 

f endp

g proc 

	mov ax,a3
	push ax
	call f
	pop ax
	mov t1,ax
	mov ax, t1
	add ax, a3
	mov t2 , ax
	mov ax, t2
	add ax, b3
	mov t3 , ax
	mov ax, t3
	mov x3, ax
	mov ax,x3
	pop bp
	ret 

g endp

main PROC 

	mov ax, 1
	mov a4, ax
	mov ax, 2
	mov b4, ax
	mov ax,a4
	push ax
	mov ax,b4
	push ax
	call g
	pop ax
	mov t0,ax
	mov ax, t0
	mov a4, ax
	mov ax, a4
	call DECIMAL_OUT
	mov ax,0

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
