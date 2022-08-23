# XFce4 Speed plugin

一个显示当前网速的小插件, `fork`于 [xfce4-speed-plugin](https://gitlab.xfce.org/panel-plugins/xfce4-speed-plugin.git)。


### 与原版的区别有:

1. 样式调整
2. 删除鼠标悬浮信息中的流量统计
3. 移除非linux的适配代码
4. 移除`en_GB, zh_CN, zh_TW`以外的语言包
5. 默认显示网速, 不显示柱形图, 不显示LABEL, 默认使用颜色样式
6. 默认更新频率调整为1秒


## 包管理器安装

```bash
apt install xfce4-speed-plugin
```

### 编译安装

```bash
./autogen.sh
make
make install

```
