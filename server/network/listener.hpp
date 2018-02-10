/* 
 * 端口监听
 * 实现绑定监听端口并返回数据到相对应的回调函数
 * 
 * Created by itsl<itsl@foxmail.com>
 * 2018-2-10
 */

#ifndef LTROV_SERVER_NETWORK_LISTENER_HPP_
#define LTROV_SERVER_NETWORK_LISTENER_HPP_

#include <boost/asio.hpp>

#include "callback_interface.hpp"

using ltrov::network::CallBackInterface;

namespace ltrov{
namespace network{
namespace tcp{

class Listener 
{
protected:
    boost::asio::io_service io;
    boost::asio::ip::tcp::socket socket;
    boost::asio::ip::tcp::acceptor acceptor;
    CallBackInterface* dataHandler;
    int port;

public:
    /* 
     * 构造函数
     * 
     * @param   (int)port   要监听的端口号
     */
    Listener(int port);

    /* 
     * 绑定回调函数
     * 
     * @param   callback    回调函数指针
     * @return  void
     */
    void bind(CallBackInterface* dataHandler);

    /* 
     * 开始监听
     */
    void start();

    void onAccept(const boost::system::error_code& error);
};

}   // namespace udp
}   // namespace network
}   // namespace ltrov

#endif