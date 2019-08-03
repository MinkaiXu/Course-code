;pce-ibmpc

stackseg segment
    db 128 dup(0)
stackseg ends

codeseg segment
    assume cs:codeseg,ds:codeseg,ss:stackseg
    org 100h
start: 
    jmp init
    old dd ?
    time dw 180
	flag dw 1 ;0时密码键盘,1时键盘无效

new proc far 
    assume cs:codeseg,ds:nothing,ss:stackseg
    sti
    cmp ah, 0     ;ah=0读取键盘信息,否则jmp到原中断              
    je  key0     
    jmp old
key0:   ;flag=0时改变al的值,flag=1时ax=0直接结束
    pushf
    call old       
    push bx  
    mov bx,flag
    cmp bx,0                
    je key1             
    mov ax,0
    jmp key_ret  
key1:   ;z则变a,a到y则加1,a以下或z以上则退出
    cmp al,"a"  ;a~y->+1               
    jb  key_ret
    cmp al,"z"                 
    ja  key_ret  
    cmp al,"z"  ;z->a
    jne key2              
    mov al,"a"
    jmp key_ret
key2:
    inc al     
key_ret:  
	cli
    pop bx
    iret
new endp

clock proc far  
	sti ;time从180数到0,到0则flag进行0-1转换
    push ax                    
    mov ax,time
    dec ax                                
    cmp ax,0
    jne time_not_zero
	je time_zero
time_not_zero:
	mov time,ax
	jmp clock_ret
time_zero:
    mov ax,180
	mov time,ax
	mov ax,flag
	cmp ax,0
	je zero_one
	mov ax, 0
	mov flag, ax
	jmp clock_ret
zero_one:
	mov ax, 1
	mov flag, ax
clock_ret:
    mov al,20h  ;8259中断结束指令
	out	20h, al	
	cli
	pop ax
	iret
clock endp      

init:
    assume cs:codeseg,ds:codeseg,ss:stackseg
	mov ax,128  ;sp:栈顶指针
	mov sp,ax
	mov bx,cs   ;ah=35h的21中断,获得old_16号中断的程序地址并存入old
    mov ds,bx
	mov al,16h                 
    mov ah,35h                 
    int 21h ;旧中断向量
    mov word ptr old,bx
    mov word ptr old[2],es 
    mov dx,offset new   ;ah=25h的21中断,设置new中断程序地址(08h号与16h号)
    mov al,16h                 
    mov ah,25h                 
    int 21h ;设置中断向量                      
    mov dx,offset clock
    mov al,08h                 
    mov ah,25h                 
    int 21h ;设置中断向量   
    mov dx,offset init ;27h中断,将init前的程序驻留在内存
    int 27h                    
codeseg ends       

end start
