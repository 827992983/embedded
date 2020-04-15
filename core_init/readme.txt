本文件是按照index标号的工程逐步完成的，后面的工程会包含前面工程的代码（mini2440）
1.init_except_vector： 初始化异常向量
2.set_svc_mode：设置处理器工作模式为svc模式，同事额外屏蔽了中断和快速中断（通过cprs寄存器完成的）
3.close_watchdog：关闭看门狗
4.disable_interrupt：关闭中断
5.close_cache_and_mmu：关闭MMU和i-cache和d-cache
6.light_led：点亮led，可烧写调试
7.set_cpu_time：设置cpu时钟频率
