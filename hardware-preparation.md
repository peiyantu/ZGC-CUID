# 项目硬件准备

这是项目开源前的第一批硬件清单，先用于记录采购入口和基础硬件组成。

> 说明：淘宝短链可能需要在淘宝客户端或浏览器中打开。表格中的商品图用于硬件识别参考，链接仍保留为对应的淘宝商品链接；实际规格、库存和价格请以商品页当前信息为准。

| 序号 | 硬件用途 | 商品编号 | 商品名称 | 淘宝链接 | 商品图 | 备注 |
| --- | --- | --- | --- | --- | --- | --- |
| 1 | NFC / 门禁卡介质 | HU926 | 超薄 NFC 手机门禁卡贴 IC 滴胶卡复刻卡 CUID 空白卡复制卡电梯卡门卡 | [打开淘宝商品](https://e.tb.cn/h.8HiPHEIW1Ie9Se2?tk=F1EXTQQ5aES) | ![NFC CUID 卡片](https://ae01.alicdn.com/kf/Sc13f2a91bbe546d18a80f4100ab0c493R/NFC-Smart-Chip-Card-CUID-Gen2-Rewritable-Key-13-56Mhz-1K-S50-Clone-Badge-RFID-Changeable.png) | 用于 NFC / RFID 卡片读写与测试 |
| 2 | 模块与开发板接线 | CZ005 | 杜邦线 母对母 / 公对公 / 公对母 10 / 15 / 20 / 30 / 40 cm 连接线 40P 彩色排线 | [打开淘宝商品](https://e.tb.cn/h.8sSKBskwkLz95sS?tk=d1B4TQQ56KV) | ![40P 彩色杜邦线](https://down-tw.img.susercontent.com/file/4805445652e8c7f4d52a4371bdf7f996) | 建议根据模块接口准备不同长度和端子组合 |
| 3 | USB 外设数据连接 | CZ001 | USB2.0 打印机数据线高速方口连接转接线 A 公对 B 公，带屏蔽磁环 zave | [打开淘宝商品](https://e.tb.cn/h.8HiOXiK4CpNORCg?tk=AUx9TQQgcum) | ![USB A 转 B 数据线](https://pics.xprice.co.jp/i/9034/4953103499034L.jpg) | 用于 USB Type-A 与 USB Type-B 设备之间的数据连接 |
| 4 | 13.56 MHz RFID 读卡 | CZ321 | MFRC-522 RC522 RFID 射频 IC 卡感应模块读卡刷卡，送 S50 复旦卡 PN532 | [打开淘宝商品](https://e.tb.cn/h.8sSJT6o17CTNK5y?tk=o3lXTQQTpKy) | ![RC522 RFID 读卡模块](https://i5.walmartimages.com/asr/4ea8a7a9-ca5c-421a-b58f-6b036af36389.659500a3dea43b0f21770f24f553c7b4.jpeg?odnBg=FFFFFF&odnHeight=612&odnWidth=612) | 常见 SPI 接口 RFID 读卡模块，适合与 Arduino 配合测试 |
| 5 | 项目主控开发板 | CZ007 | zave 适用 Arduino Nano UNO 开发板套件 R3 改进版 ATmega328P 单片机 | [打开淘宝商品](https://e.tb.cn/h.8udbibh7TAbVOjM?tk=TewSTQQTAGj) | ![Arduino Nano ATmega328P 开发板](https://cdn-cloudflare.meidianbang.cn/comdata/51404/product/20180605152111759825D35AA31156_b.jpg) | 用于运行项目固件并控制 RFID / NFC 相关模块 |

## 硬件准备检查

- [ ] NFC / CUID 卡片或卡贴
- [ ] 40P 杜邦线
- [ ] USB A 公对 B 公数据线
- [ ] RC522 RFID 读卡模块
- [ ] Arduino Nano / ATmega328P 开发板
- [ ] 确认开发板电压、接口定义和模块接线方式
- [ ] 确认项目涉及的卡片读写行为符合当地法律、设备管理规定和授权范围

