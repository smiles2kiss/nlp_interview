1. BERT细节介绍，与GPT、ElMo比较；词向量 onehot的缺点 word2vec，glove，elmo，bert区别
2. Bert中两个预训练任务: Mask机制，Next Sentence预测
  Bert中的Mask Language Model任务具体是如何实现的？
  随机遮住句子中部分的Token，模型再去通过上下文语义来预测被Mask掉的词，通过调整模型的参数使得模型预测正确率尽可能大。
  在一句话中随机选择 15% 的词汇用于预测。
  对于在原句中被抹去的词汇， 80% 情况下采用一个特殊符号 [MASK] 替换， 10% 情况下采用一个任意词替换，剩余 10% 情况下保持原词汇不变。
  与 masked token 对应的最终隐藏向量被输入到词汇表上的 softmax 层中。
  加上 10% 的随机词和 10% 的真实值是让模型知道，每个词都有意义，除了要学习上下文信息，还需要提防每个词，因为每个词都不一定是对的，对于 Bert 来说，每个词都需要很好的理解和预测。
3. Bert, XLNet, Roberta, AlBert，ELECTRA的区别
4. Bert mask，cls等比较详细的
5. 分类损失函数都有哪些
6. Word2vec和bert区别，然后损失函数（负采样，哈夫曼softmax）
7. Bert的两种输出
8. Bert掩码如何实现
9. BERT为什么只用Transformer的Encoder而不用Decoder
10. 能否描述下Bert的分词方法，如何实现WordPiece
  WordPiece目的在于权衡词典大小和ovv单词的个数，将整个单词分为子词后，可减少oov的词语的个数
11. 为什么Bert中的三个Embedding能够相加
   Embedding的本质是one-hot编码向量输入一个全连接层得到的输出。
   三个one-hot编码按特征维度拼接起来，再过一个全连接层，其输出等价于对三个编码分别作Embedding再求和。
