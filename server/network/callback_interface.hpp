/* 
 * 回调类接口
 * 
 * created by itsl<itsl@foxmail.com>
 * 2018-2-10
 */

#ifndef LTROV_SERVER_NETWORK_CALLBACKINTERFACE_HPP_
#define LTROV_SERVER_NETWORK_CALLBACKINTERFACE_HPP_

#include <iostream>

#include <boost/asio.hpp>

namespace ltrov{
namespace network{

class CallBackInterface
{
public:
    /**
     * 回调函数
     * @param data
     * @param sock
     */
    virtual void onDataReceived(std::string& data,
                                boost::asio::ip::tcp::socket** sock) = 0;
};

}   // namespace network
}   // namespace ltrov

#endif