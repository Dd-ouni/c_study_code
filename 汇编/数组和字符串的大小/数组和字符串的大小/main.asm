.386 ;32位程序
.model flat,stdcall ;内存模式flat, 子程序调用规范stdcall
.stack 4096 ;运行时堆栈空间保存4096字节
ExitProcess PROTO, dwExitCode:DWORD ;声明win退出进程函数原型,参数类型DWORD


.data
;声明变量
array DWORD 10,20,30,40
array_lisr = ($ - array) / 4
NUM EQU 10 * 10
NUM3 = 10 * 10
NUM3 = 10 * 5
NUM2 EQU <10 * 10>
NUM2 EQU <10 * 5>
NUM4 DWORD NUM2


.code
main PROC
   ;逻辑代码
  mov eax,NUM4
  mov eax,array_lisr
  INVOKE ExitProcess,0 ;成功退出程序调用ExitProcess，传入0
main ENDP
END main  