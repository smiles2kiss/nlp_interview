1. 网络梯度回传的过程

  * optimizer.zero_grad() // 梯度清零，清空上一个计算过程中的梯度

  * loss.backward()          // 反向传播计算本轮中每个参数的梯度

  * Optimizer.step()        //  通过梯度下降执行依次通过梯度来更新网络中每个参数的值

    

2. Pytorch中的DataParallel

  * 数据并行，将模型复制到多张卡上，并将batch平均后复制到多张卡上，在forward阶段，每张卡独立拥有自己的data，在backward阶段，每张卡上的梯度会汇总到第一张卡的模型上，完成梯度回传的过程。
  * Multiprocessing
  * Python的多进程，每张卡运行一个进程，每个进程有一个自己的model和一份数据，求梯度时则将多张卡的梯度汇总，然后传播到每张卡上来实现并行。

  

3. model.train()与model.eval()的区别

   * model.train(): 启用 BatchNormalization 和 Dropout
   * model.eval(): 不启用 BatchNormalization 和 Dropout