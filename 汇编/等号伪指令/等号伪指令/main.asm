.386 ;32位程序
.model flat,stdcall ;内存模式flat, 子程序调用规范stdcall
.stack 4096 ;运行时堆栈空间保存4096字节
ExitProcess PROTO, dwExitCode:DWORD ;声明win退出进程函数原型,参数类型DWORD

.data
;声明变量
dword1 DWORD 20;

; 等号伪指令之初始化列表数量
NUM = 5 ;表达式5
array DWORD NUM DUP(20)
; 定义 DWORD 数组长度5 默认值20
parray DWORD array
; 获取array 地址便于观察


.code
main PROC
  mov eax, dword1
  add eax, dword1
  INVOKE ExitProcess,0 ;成功退出程序调用ExitProcess，传入0
main ENDP
END main