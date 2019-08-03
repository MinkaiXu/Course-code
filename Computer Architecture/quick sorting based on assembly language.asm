data_seg segment 
    a dw 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1
    num dw 0032H
data_seg ends


stack_seg segment
    ST DB 100 DUP(0)
    TOP EQU 100
stack_seg ends


code_seg segment
    assume cs:code_seg,ds:data_seg,ss:stack_seg
    MAIN PROC FAR
    START:
        MOV AX,data_seg
        MOV DS,AX
        MOV AX,stack_seg
        MOV SS,AX
        MOV SP,TOP  ;栈顶
        MOV SI,a offset ;表a的首地址
        MOV DI,num 
        ADD DI,num
        SUB DI,2    ;表a最后一个数的地址
        PUSH SI
        PUSH DI
        CALL Quick_Sort
        PUSH DI
        PUSH SI
        MOV AX, 4C00h
        INT 21h 
    MAIN ENDP  


    ;快速排序的实现
    Quick_Sort PROC NEAR  
        
        PUSH AX
        PUSH SI ;表a的首地址
        PUSH DI ;表a最后一个数的地址
         
        MOV SI,SP   ;SI 栈顶
        MOV DI,SS:[SI+8]
        MOV SI,SS:[SI+10]

        CMP SI,DI   ;待分段元素只有1或0个
        JNL EndSort ;(Jump if not less,or greater or equal)不小于,或者大于或者等于则转移

        PUSH SI
        PUSH DI 
        CALL divide
        
        POP DI  ;表a最后一个数的地址
        POP SI  ;表a的首地址
        PUSH SI
        SUB AX,2
        PUSH AX
        CALL Quick_Sort       

        POP AX
        POP SI
        ADD AX,4
        PUSH AX
        PUSH DI
        CALL Quick_Sort
        
        POP DI
        POP AX
        JMP EndSort
        
        EndSort:  
            POP DI
            POP SI
            POP AX 
            RET    
    Quick_Sort ENDP


    ;划分函数的实现
    divide PROC NEAR
        
        PUSH SI
        PUSH DI
        PUSH BX
        PUSH CX
        PUSH DX
        
        MOV SI,SP   ;SI 栈顶
        MOV DI,SS:[SI+12]
        MOV SI,SS:[SI+14]

        MOV BX,SI   ;SI 表a的首地址
        SUB BX,2
        
    Loop_1: 
        MOV DX,[SI]
        CMP DX,[DI]
        JNG If_1    ;(Jump if less or equal,or not greater) 小于或等于,或者不大于则转移
        JG  If_2    ;(Jump if not less or equal,or greater) 不小于或等于,或者大于则转移

    If_1:     
        ADD BX,2
        MOV AX,[BX] 
        MOV DX,[SI]
        MOV [BX],DX
        MOV [SI],AX  
        JMP If_2

    If_2: 
        ADD SI,2
        CMP SI,DI
        JL Loop_1   ;(Jump if less,or not greater or equal) 小于,或者不大于或者等于则转移
        JNL Loop_2  ;(Jump if not less,or greater or equal)不小于,或者大于或者等于则转移

    Loop_2:    
        ADD BX,2
        MOV AX,[BX] 
        MOV DX,[DI]
        MOV [BX],DX
        MOV [DI],AX
        MOV AX,BX
        
        POP DX
        POP CX
        POP BX
        POP DI
        POP SI

        RET           
    divide ENDP

code_seg ENDS

end start
