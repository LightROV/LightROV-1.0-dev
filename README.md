# LightROV-1.0-dev
第一版测试repo

## 假的架构图
!["假的架构图"](./images/架构图.png)

## namespace
| namespace       | 用途 |
| :------------   | :----- |
| ltrov           | 根命名空间 |
| ltrov::control  | 电机的控制 |
| ltrov::network  | 潜水器的通信 |
| ltrov::sensor   | 传感器的数据获取及其数据解算 |
| ltrov::scheduler| 整个"系统"的调度器 |

## 如何绑定新的事件
1. 在 events.hpp 中 ltrov::scheduler::Events 下添加事件名称并设定对应的标识代码
2. 绑定事件回调函数
```

```