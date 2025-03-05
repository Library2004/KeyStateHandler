# KeyStateHandler
对GetKeyState()的使用进行了同步化的封装，从而更便于使用

调用函数时，若传入的clk和已存储的clock不同，则认为进入下一周期，进行相关更新
