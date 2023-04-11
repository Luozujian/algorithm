# 环境搭建
1. 安装MinGw，https://sourceforge.net/projects/mingw-w64/
2. 将MingGw的bin目录加入到环境变量
3. 修改c_cpp_properties.json，使用gcc -v -E -x c++ - 命令，把includePath和path替换成下图的地址
4. 修改launch.json，把miDebuggerPath地址修改成mingw地址





![Alt](https://img-blog.csdnimg.cn/76f83e87d85f4f8e863fa322f3b05d9b.png)







参考资料：https://blog.csdn.net/Zhouzi_heng/article/details/115014059