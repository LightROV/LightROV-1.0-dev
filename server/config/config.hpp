/**
 * Created by itsl on 18-3-8.
 *
 * #说明#
 * 1. 每个控制指令为32位长
 * 2. 结束标志占4位，同时作为高28位的摘要，摘要计算方法：flag=min(#1, #0)
 * 3. 前8位为标识位，用以区分指令
 * 4. 中间20位(9-28)为数据位，根据不同情况代表意义不同
 *
 */

#ifndef LIGHTRO_1_0_SERVER_CONFIG_HPP
#define LIGHTRO_1_0_SERVER_CONFIG_HPP

namespace ltrov{
namespace config{

typedef unsigned char uchar;

class Event {
public:
    /**
     * video-stream control signal
     */
    // 开启视频流
    static uchar REQUEST_VIDEO_OPEN;
    static uchar REQUEST_VIDEO_CLOSE;

    /**
     * rov motion control signal
     */
    static uchar MOTION_FORWARD;
    static uchar MOTION_BACK;
    static uchar MOTION_UP;
    static uchar MOTION_DOWN;
    // 原地转弯
    static uchar MOTION_ROUND;
    // 速度调节
    static uchar CONFIG_SPEED;
};

}   // namespace config
}   // namespace ltrov

#endif //LIGHTRO_1_0_SERVER_CONFIG_HPP
