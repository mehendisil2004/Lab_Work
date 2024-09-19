.model small
.stack 100h
.data
.code
main proc

mov ax, @data
mov ds, ax
mov ax, 2222h
mov bx, 0055h
div bx
mov si, 0060h
mov [si], ax
mov [si+2], dx

int 03h
mov ah, 4ch
int 21h
main endp
end main