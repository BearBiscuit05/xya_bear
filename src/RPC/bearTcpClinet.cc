#pragma once
#include <jackson/Value.h>

#include "util.h"



typedef std::function<void(json::Value&,
                           bool isError,
                           bool isTimeout)> ResponseCallback;

class BaseClient
{
public:
    BaseClient(EventLoop* loop, const InetAddress& serverAddress):
            id_(0),
            client_(loop, serverAddress)
    {
        client_.setMessageCallback(std::bind(
                &BaseClient::onMessage, this, _1, _2));
    }

    void start() { client_.start(); }

    void setConnectionCallback(const ConnectionCallback& cb)
    {
        client_.setConnectionCallback(cb);
    }

    void sendCall(const TcpConnectionPtr& conn, json::Value& call,
                  const ResponseCallback& cb);

    void sendNotify(const TcpConnectionPtr& conn, json::Value& notify);

private:
    void onMessage(const TcpConnectionPtr& conn, Buffer& buffer);
    void handleMessage(Buffer& buffer);
    void handleResponse(std::string& json);
    void handleSingleResponse(json::Value& response);
    void validateResponse(json::Value& response);
    void sendRequest(const TcpConnectionPtr& conn, json::Value& request);

private:
    typedef std::unordered_map<int64_t, ResponseCallback> Callbacks;
    int64_t id_;
    Callbacks callbacks_;
    TcpClient client_;
};
