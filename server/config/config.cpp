/**
 * 这里是定义标识符的文件
 * 编译时本文件生成被编译成静态链接库 libconfig.a
 *
 * Created by itsl on 18-3-8.
 */

#include "config.hpp"

using ltrov::config::Event;

// 标识位占8位长度
typedef unsigned char uchar;

uchar Event::REQUEST_VIDEO_OPEN     = 0x01;
uchar Event::REQUEST_VIDEO_CLOSE    = 0x02;

uchar Event::MOTION_FORWARD         = 0x10;
uchar Event::MOTION_BACK            = 0x11;
uchar Event::MOTION_UP              = 0x12;
uchar Event::MOTION_DOWN            = 0x13;
uchar Event::MOTION_ROUND           = 0x14;
uchar Event::CONFIG_SPEED           = 0x15;