.model small
.stack 100h
.data
.code
main proc

mov ax, @data
mov ds, ax
mov ax, 0000h
mov si, 0030h
mov cx, 0005h

l1:
add al, [si]
daa
adc ah, 00h
inc si
loop l1

mov si, 0040h
mov [si], ax

int 03h
mov ah, 4ch
int 21h
main endp
end main