#pragma once

#include <iostream>

#include <boost/asio.hpp> 
void handler(const boost::system::error_code& ec);
void boost_asio();

void handler1(const boost::system::error_code& ec);
void handler2(const boost::system::error_code& ec);
void boost_asio1();


#include <boost/thread.hpp> 
void asio_thread_single_service_run();
void boost_asio_thread_single_service();


void asio_thread_more_service_run1();
void asio_thread_more_service_run2();
void boost_asio_thread_more_service();

#include <boost/array.hpp> 
#include <string> 
void asio_intrnet_read_handler(const boost::system::error_code& ec, std::size_t bytes_transferred);
void asio_intrnet_connect_handler(const boost::system::error_code& ec);
void asio_intrnet_resolve_handler(const boost::system::error_code& ec, boost::asio::ip::tcp::resolver::iterator it);
void boost_asio_intrnet();