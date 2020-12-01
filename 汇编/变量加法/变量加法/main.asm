.386 ;32位程序
.model flat,stdcall ;内存模式flat, 子程序调用规范stdcall
.stack 4096 ;运行时堆栈空间保存4096字节
ExitProcess PROTO, dwExitCode:DWORD ;声明win退出进程函数原型,参数类型DWORD

.data
;声明变量
firstval DWORD 20002000h
secondval DWORD 11111111h
thirdval DWORD 22222222h
sum DWORD 0
psum DWORD sum
pself DWORD $
COUNT = 600
array DWORD COUNT DUP(0)

.code
main PROC
   ;逻辑代码
  mov eax, firstval
  add eax, secondval
  add eax, thirdval
  mov sum, eax
  INVOKE ExitProcess,0 ;成功退出程序调用ExitProcess，传入0
main ENDP
END main  

