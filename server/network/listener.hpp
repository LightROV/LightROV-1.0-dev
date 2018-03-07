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

#include <iostream>

#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/thread.hpp>

#include "callback_interface.hpp"

using ltrov::network::CallBackInterface;

typedef boost::asio::ip::tcp boostTCP;

namespace ltrov{
namespace network{
namespace tcp{

class Listener 
{
protected:
    boost::asio::io_service io;
    boost::asio::ip::tcp::socket socket;
    boost::asio::ip::tcp::acceptor acceptor;
    boost::asio::io_service::work worker;
    boost::thread_group workerGroup;
    CallBackInterface* dataHandler;
    boost::array<char, 4096> buff;
    unsigned short port;
    bool LISTENING;
    short workers;

public:
    /**
     * 构造函数
     * 
     * @param int port 要监听的端口号
     */
    Listener(unsigned short port, short workers);

    /**
     * 虚析构函数
     * @return void
     */
    virtual ~Listener();

    /*
     * 绑定回调函数
     * 
     * @param callback 回调函数指针
     * @return void
     */
    void bind(CallBackInterface* dataHandler);

    /*
     * 
     */
    void workerStart();

    void registerNewAcceptor();

    /*
     * 开始监听
     */
    void start();

    /* 
     * 接收消息的回调
     */
    void onAccept(const boost::system::error_code& error, boostTCP::socket** sock);

    /*
     * 回调的封装
     */
    void onReceiveHandler(std::size_t length, boostTCP::socket** sock);
};

}   // namespace udp
}   // namespace network
}   // namespace ltrov

#endif