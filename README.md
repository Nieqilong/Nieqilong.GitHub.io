# The purpose of this project is to store some code used in the homework of "Software and Hardware Co-design" 

目前所存放的代码主要是多模块划分方法里面涉及到的一些算法的C++代码；

考虑到代码的通读性，会附有详细的注释和算法思路。

1. **单链接算法（Single Link）**：根据课本上的定义，簇间元素中的最大通信代价大于等于通信代价阈值，即有一对元素的通信代价大于等于通信代价阈值；

   根据定义以及课本中给出的伪代码,在写程序之前需要考虑到如下问题:

   (1) 首先需要确定好存储输入输出的数据结构,考虑到算法中涉及到大量的合并操作,考虑使用vector存储划分的簇结果;

   (2) 在使用C++编写程序的时候,会发现单链接算法的思路比较简单,主要是通过判断两个簇之间是否存在通信代价大于阈值的节点,若存在则可以将两个簇合并;但是在具体实现的时候会发现,簇的合并和删除操作较为复杂,也建议大家好好自己动手实现这一步.

   (3) 在具体实现簇的合并和操作的时候,考虑到一种情况,若簇A已经和簇B合并了,在后续又发现簇B能够和簇C合并,那么此时应该直接将C合并到A存在的那个簇,这里考虑到使用并查集来实现;并且在合并后需要将簇B和簇C删除,只保留合并后的{A,B,C}这一个簇.
   
   **对于课本上的例题7.2.1，SAA程序运行实现结果如下所示**：
    ![Image text](https://github.com/Nieqilong/Nieqilong.GitHub.io/blob/main/result_pictures/Single_Agglomerative_Algorithm.jpg)

2. **全连接算法（Complete Link）**：簇间元素中的最小通信代价大于等于通信代价阈值，即簇间所有元素对的通信代价都大于等于通信代价阈值；

   全连接算法和单链接算法实现过程大体相似,主要是将合并判断函数进行了一些修改,主要是通过判断两个簇之间是否所有节点之间的通信代价都大于阈值,若是,则可以将两个簇合并;其余部分未进行修改.
   
   **对于课本上的例题7.2.1，CAA程序运行实现结果如下所示**： 
  ![Image text](https://github.com/Nieqilong/Nieqilong.GitHub.io/blob/main/result_pictures/Complete_Agglomerative_Algorithm.jpg)
  
3. **均连接算法（Average Link）**：簇间元素中的平均通信代价大于等于通信代价阈值，此时有一部分元素对的通信代价大于等于阈值，而另外一部分元素对的通信代价小于阈值。

   均链接算法如上,只对合并判断函数进行了修改,其余不变.
   
   **对于课本上的例题7.2.1，AAA程序运行实现结果如下所示**：
   
 ![Image text](https://github.com/Nieqilong/Nieqilong.GitHub.io/blob/main/result_pictures/Average_Agglomerative_Algorithm.jpg)
