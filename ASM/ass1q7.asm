.model small
.stack 100h
.data
.code
main proc

mov ax, @data
mov ds, ax
mov si, 0030h
mov al, [si]
mov si, 0040h
sub al, [si]
das
mov dl, 00h
jnc l1

mov cl, al
mov al, 99h
sub al, cl
add al, 01h
daa
mov dl, 01h

l1:
mov si, 0050h
mov [si], al
inc si
mov [si], dl

int 03h
mov ah, 4ch
int 21h
main endp
end main