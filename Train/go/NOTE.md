1. slice 比较：go 不能重载运算符，也没有提供默认的比较函数，因此需要自己手动编写比较函数，或者使用reflect.Equal 进行底层比较
2. 