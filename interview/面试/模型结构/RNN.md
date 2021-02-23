1. LSTM如何解决梯度消失和梯度爆炸
2. LSTM长短期记忆如何实现
3. LSTM的结构与公式推导
4. LSTM相比于传统RNN解决了什么问题？怎么解决的？
5. RNN 为何引出LSTM，其优缺点，解决的问题时？
6. BiLSTM的网络结构
7. LSTM如何调参
8. LSTM和GRU区别
9. 关于LSTM、GRU、RNN的区别，梯度下降的过程，如何改善梯度下降的缺点。LSTM解决梯度爆炸或者梯度消失的数学逻辑。
10. RNN的参数量计算，非常细节，给定输入输出，计算参数量
11. 手写LSTM并实现反向传播
12. LSTM中存在Normalization么，请说明理由
13. LSTM的改进点有哪些？
14. 画出LSTM网络的结构图，并说出里面涉及到的每一个公式
15. LSTM为什么能够解决梯度消失问题
        在RNN中，前后两个step的hidden state中间经过了一层sigmoid，反向传播时梯度会乘以sigmoid的导数值；在LSTM中，前后两个step的hidden state中间没有经过一层sigmoid，乘了一个sigmoid的函数值 / 激活值（即LSTM的forget gate），所以后向传播的时候梯度也会乘上一个sigmoid的函数值。
        RNN在反向传播时，梯度会不断乘上sigmoid的导数值，而LSTM在反向传播时，梯度会不断乘上sigmoid的函数值，两者的数据分布存在差异。
        LSTM中的梯度范围由sigmoid函数的导数变成了sigmoid函数，范围在[0,1]之间，在实际参数更新中，可控制使其接近于1，因此多次连乘操作依然不会产生梯度消失。
