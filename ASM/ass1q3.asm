.model small
.stack 100h
.data
.code
main proc
mov ax, @data
mov ds, ax
mov es, ax
mov si, 0030h
mov di, 0040h
mov cx, 0008h
cld
l1:movsb
loop l1

int 03h
mov ah, 4ch
int 21h
main endp
end main