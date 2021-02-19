# 我的分布式存储之路

* sources/：一些pdf资源和常用工具
* examples/：学习一些框架或者其他知识时写的一些demo代码

## 文档目录

* [C/CPP](#ccpp)
   * [书籍文档](#书籍文档)
   * [代码框架](#代码框架)
* [基础知识](#基础知识)
   * [汇编语言](#汇编语言)
* [分布式存储](#分布式存储)
   * [单机引擎](#单机引擎)

## C/CPP

### 书籍文档

* [《现代C++教程》](https://changkun.de/modern-cpp/) - 国人写的一本关于现代C++语法的导读
* [Large Scale C++ Software Design](https://github.com/wonter/learning-distributed-storage/blob/master/sources/ebooks/Large%20Scale%20C%2B%2B%20Software%20Design.pdf) - 需要有一定的开发经验后才适合阅读，是一本很老的书了（96年出版的），不过里面有部分思想现在还可以学习，`物理设计概念`这一部分。中文名字叫《大规模c++程序设计》，但中文版翻译的据说非常烂，所以尽量还是看英文版吧
* [《代码大全》（第2版）](https://github.com/wonter/learning-distributed-storage/blob/master/sources/ebooks/%E3%80%8A%E4%BB%A3%E7%A0%81%E5%A4%A7%E5%85%A8%E3%80%8B(%E7%AC%AC2%E7%89%88).pdf) - 也需要有一定的开发经验后阅读才能有收获，主要是逻辑设计概念

### 代码框架

* [NanoLog](https://github.com/PlatformLab/NanoLog) - 一个纳秒级别的c++日志库，性能很极限，对原理感兴趣的话可以研究下它的[论文](https://www.usenix.org/conference/atc18/presentation/yang-stephen)
* [Asio](https://think-async.com/Asio/) - 比较主流的C++异步网络框架

## 基础知识

### 汇编语言

* [王爽《汇编语言》(第四版)](https://github.com/wonter/learning-distributed-storage/blob/master/sources/ebooks/%E3%80%8A%E6%B1%87%E7%BC%96%E8%AF%AD%E8%A8%80%E3%80%8B(%E7%AC%AC4%E7%89%88)%20.pdf) - 最好的汇编语言入门书之一，搭建实验环境可以参考我写的[这篇文章](http://blog.wonter.net/posts/2821c29c/)

## 分布式存储

### 分布式导论

* [《设计数据密集型应用》](https://github.com/Vonng/ddia) - 神书了，入门必看
* [MIT 6.824](https://pdos.csail.mit.edu/6.824/schedule.html) - 也是分布式系统入门必看，里面的实验课一定要做

### 单机引擎

* [Redis](https://redis.io/) - 应该是最常见的KV服务了，内部实现原理不算复杂，可以结合源码和[《Redis设计与实现》](https://github.com/wonter/learning-distributed-storage/blob/master/sources/ebooks/%E3%80%8ARedis%E8%AE%BE%E8%AE%A1%E4%B8%8E%E5%AE%9E%E7%8E%B0%E3%80%8B.pdf)一起看
* [LevelDB](https://github.com/google/leveldb) - 基于LSM树的引擎，出自Jeff Dean之手，**源码非常值得一读**，可以结合着[架构剖析](https://leveldb-handbook.readthedocs.io/zh/latest/basic.html)一起看
* [RocksDB](https://github.com/facebook/rocksdb/) - Facebook在LevelDB基础上优化出来的一个引擎，应该是业界最常用的单机KV引擎了吧
