.model small
.stack 100h
.data
.code
main proc

mov ax, @data
mov ds, ax
mov ax, 0000h
mov si, 0040h
mov al, [si]
mov si, 0050h
mov bl, 00h
mov bl, [si]
mul bl
mov si, 0060h
mov [si], ax

int 03h
mov ah, 4ch
int 21h
main endp
end main