.model small
.stack 100h
.data
.code
main proc

mov ax, 3000h
mov ds, ax
mov si, 0030h
mov di, 0040h

mov al , 55h

mov dl, 00h
mov cx, 0008h

looping:
cmp [si], al
jnz l1
inc dl
l1:
inc si
loop looping
mov [di], dl

int 03h
mov ah, 4ch
int 21h
main endp
end main
