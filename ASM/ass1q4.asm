.model small
.stack 100h
.data
.code
main proc

mov ax, @data
mov ds, ax
mov al, 00h
mov cl, 07h
mov ah, 00h
mov si, 0030h

l1:
add al, [si]
adc ah, 00h
inc si
loop l1

mov si, 0050h
mov [si], al
inc si
mov [si], ah

int 03h
mov ah, 4ch
int 21h
main endp
end main