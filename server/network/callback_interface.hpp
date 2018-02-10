/* 
 * 回调类接口
 * 
 * created by itsl<itsl@foxmail.com>
 * 2018-2-10
 */

#ifndef LTROV_SERVER_NETWORK_CALLBACKINTERFACE_HPP_
#define LTROV_SERVER_NETWORK_CALLBACKINTERFACE_HPP_

#include <iostream>

namespace ltrov{
namespace network{

class CallBackInterface
{
public:
    virtual void onDataReceived(std::string& data) = 0;
};

}   // namespace network
}   // namespace ltrov

#endif