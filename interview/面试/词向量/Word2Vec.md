1. 分布编码: 将词语映射为固定长度的向量，即N维空间中的一点。理想情况下，两个对象越相似，词向量的相似度越高，空间中的两点的距离越近。

2. 稀疏词向量用skip-gram还是cbow训练好？两种编码方式哪一种对稀疏词处理更好？
     Skip Gram模型相对来说对于稀疏词的处理效果更好，当语料中存在大量低频词时，选用Skip-gram模型更合适。假设预测两个词的词向量，飞船和飞机，用一个词预测多个词，每个词都会被单独得训练，较少受其他高频的干扰。所以对于生僻词Skip-Gram的word2vec更占优。
     
     
     
3. 语言模型
  统计语言模型：计算语料库中某个句子出现的概率。
  N-Gram模型: 语句出现的概率是各单词出现的联合概率，不过只考虑到前n个词。
  神经概率语言模型: 使用向量表示词语，在已知语句W出现概率的情况下，预测最可能出现在k位置的单词wk。随机初始化词典中所有单词的词向量，然后将语料库中的所有语句输入网络得到预测的词向量，然后与库中的词向量对比修正单词w的词向量，或者上下文的词向量。经过充分迭代，就可较好地表示语义地词向量。

  

4. word2vec的训练过程，word2vec是有监督的还是无监督的？讲了word2vec，层级softmax和负采样这些

5. Word2vec的训练方式，那种更好，CBOW模型和skipgram模型，霍夫曼树，负采样等等

6. LDA的词表示和word2vec的词表示有什么区别，word2vec 负采样如何做到的

7. 你了解哪些词向量生成方式，每一种是怎样做的，Word2vec，tf-idf，n_gram，Glove，Fasttext
