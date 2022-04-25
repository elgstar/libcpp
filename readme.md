# libcpp

`C++`程序库，使用`C++14`编写，程序库位于名称空间`slj`中。


## 一、命名规则

| 类型 | 命名规则 | 举例 |
| - | - | - |
| 类/结构体/枚举 | 每个单词的首字母大写 | `ErrorLogic` |
| 函数 | 第一个单词全部小写，其余单词首字母大写 | `getLine` |
| 宏 | 所有字母全部大写 | `ERRORLOGIC` |
| 变量 | 所有字母全部小写 | `id` |

文件的名称一律小写，头文件后缀为`.hpp`，源文件后缀为`.cpp`。计数器使用`i, j, k, x, y, z`等。


## 二、注释

+ 文件开始写入这个文件的整体性说明，如：

```c++
/*
 * exception classes
*/
```

+ 每一个类，说明类的作用，版权信息，数据成员含义，以`@`开头，如：

```c++
/*
 * @brief: the basic exception class
 * @info: written by Liangjin Song on 20220425 at Nanchang University
 * @value: filename -- the file that throws the exception
 * @value: function -- the function name that throws the exception
 * @value: linenumber -- the line number that throws the exception
 * @value: msg -- Supplementary notes on exception
 */
```

如果数据成员较多，在类内部、成员上方使用`//`说明数据成员含义。

+ 简单的类成员函数不用注释，通过函数名说明作用即可。复杂的类成员函数，和独立的函数，说明函数作用，版权信息，参数含义，返回值含义，以及使用的算法等，如：

```c++
/*
 * @brief: macro function to get the exception information
 * @info: written by Liangjin Song on 20220425 at Nanchang University
 * @param: msg -- exceptional supplementary information
 * @return: void
 * @note: algorithm description
*/
```

## 三、代码格式

一个缩进使用4个空格。

+ 名称空间

```c++
namespace slj {
code...
}
```

+ 类/结构体

```c++
class ClassName {
public:
    code...
protected:
    code...
private:
    code...
};
```

+ 类内部函数

```c++
class ClassName {
public:
    void Function() {
        code...
    }
};
```

+ 其它函数

```c++
void Function(parameters)
{
    code...
}
```

+ 循环

```c++
for(int i = 0; i < 10; ++i){
    code...
}



do {
    code...
}while(true);



while(true) {
    code...
}
```

### 四、目录说明

+ `doc`：存放说明文档
+ `example`：存放示例程序，各个组件的使用示例
+ `kits`：基本工具集

### 五、组件说明

+ [异常](doc/exception.md)