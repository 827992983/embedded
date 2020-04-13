本文件是按照index标号的工程逐步完成的，后面的工程会包含前面工程的代码（mini2440）
1.init_except_vector： 初始化异常向量
2.set_svc_mode：设置处理器工作模式为svc模式，同事额外屏蔽了中断和快速中断（通过cprs寄存器完成的）
