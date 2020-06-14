1. 不要使用gets(),因为gets()不会做任何边界检查，会导致读入过长数据，使用fgets()
2. sizeof()不要用在函数的形参上，对于函数形参int a[]来说，a会被视为指针，导致sizeof(a)/sizeof(a[0])结尾为一个元素大小而不是整个数组大小,sizeof直接对数组名使用
3. 在VS2015上scanf被视为不安全的function，要使用它要在文件开头加入#define _CRT_SECURE_NO_WARNINGS,使用scanf读取字符串最好定义选取大小scanf("%10s"， &a)