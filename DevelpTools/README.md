## 参考资源
* https://e2echina.ti.com/question_answer/microcontrollers/msp430/f/55/t/67051
  * /usr/lib/gcc/msp430/4.6.3/../../../../msp430/bin/ld: cannot open linker script file memory.x: No such file or directory  * collect2: ld returned 1 exit status
  *
* https://mycontraption.com/programming-the-msp430-launchpad-on-ubuntu/
  * 成功debug 能够查看rom
  * 不知道如何c编程
* https://www.linuxidc.com/Linux/2013-12/93715p2.htm
* https://www.linuxidc.com/Linux/2013-12/93715.htm
  * cc1: error: argument to ‘-O’ should be a non-negative integer
    * http://blog.csdn.net/u013209302/article/details/52749889
    * http://blog.csdn.net/qianlong4526888/article/details/8591146
* https://43oh.com/2010/11/a-step-by-step-guide-msp430-programming-under-linux/
* http://blog.sina.com.cn/s/blog_4ce016230101ha2l.html

##### 收获
* 编译：msp430-gcc -Os -mmcu=msp430g2553 -o led.elf led.c
* 运行：mspdebug rf2500
  * prog lef.elf
  * run
* 所有的工具都是通过apt-get 和aptitude安装的
* 可以通过C的typedef 来定义变量：`typedef unsigned int unsignedint`
