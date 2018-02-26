/*
 * 端口监听
 * 实现绑定监听端口并返回数据到相对应的回调函数
 * 
 * Created by itsl<itsl@foxmail.com>
 * 2018-2-10
 * 
 * -> 2018-2-22 "改异步实现为同步实现"
 */

#ifndef LTROV_SERVER_NETWORK_LISTENER_HPP_
#define LTROV_SERVER_NETWORK_LISTENER_HPP_

#include <string>

#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/thread.hpp>

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
    boost::thread* listenThread;
    CallBackInterface* dataHandler;
    boost::array<char, 4096> buff;
    bool LISTENING;
    int port;

public:
    /*
     * 构造函数
     * 
     * @param int port 要监听的端口号
     */
    Listener(int port);

    /*
     * 绑定回调函数
     * 
     * @param callback 回调函数指针
     * @return void
     */
    void bind(CallBackInterface* dataHandler);

    /*
     * 开始监听
     */
    void start();

    /* 
     * 接收消息的回调
     */
    void onAccept();

    /*
     * 回调的封装
     */
    void onRecieveHandler(std::size_t length);

    /* 
     * 监听器
     */
    void listenHandler();
};

}   // namespace udp
}   // namespace network
}   // namespace ltrov

#endif