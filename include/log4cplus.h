#ifndef LOG4CPLUS_H
#define LOG4CPLUS_H

#include <log4cplus/logger.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/configurator.h>
#include <log4cplus/layout.h>
#include <log4cplus/appender.h>
#include <memory>
#include <iostream>
#include <string>

using namespace log4cplus;
using namespace log4cplus::helpers;

class LoggerWrapper
{
public:
    // 单例模式获取Logger实例
    static LoggerWrapper &getInstance()
    {
        static LoggerWrapper instance;
        return instance;
    }

    // 日志记录函数
    void logInfo(const std::string &message, const char *functionName, int lineNumber)
    {
        LOG4CPLUS_INFO(logger_, LOG4CPLUS_TEXT(message) << " (" << functionName << ":" << lineNumber << ")");
    }

    void logDebug(const std::string &message, const char *functionName, int lineNumber)
    {
        LOG4CPLUS_DEBUG(logger_, LOG4CPLUS_TEXT(message) << " (" << functionName << ":" << lineNumber << ")");
    }

    void logWarn(const std::string &message, const char *functionName, int lineNumber)
    {
        LOG4CPLUS_WARN(logger_, LOG4CPLUS_TEXT(message) << " (" << functionName << ":" << lineNumber << ")");
    }

    void logError(const std::string &message, const char *functionName, int lineNumber)
    {
        LOG4CPLUS_ERROR(logger_, LOG4CPLUS_TEXT(message) << " (" << functionName << ":" << lineNumber << ")");
    }

private:
    LoggerWrapper()
    {
        // 初始化log4cplus配置
        try
        {
            PropertyConfigurator::doConfigure(LOG4CPLUS_TEXT("config/log4cplus.properties"));
        }
        catch (std::exception &e)
        {
            std::cerr << "Log4cplus initialization failed: " << e.what() << std::endl;
        }
        logger_ = Logger::getInstance(LOG4CPLUS_TEXT("AC977Logger"));
    }

    // 禁止拷贝和赋值
    LoggerWrapper(const LoggerWrapper &) = delete;
    LoggerWrapper &operator=(const LoggerWrapper &) = delete;

    Logger logger_;
};

// 宏定义方便日志调用
#define LOG_INFO(message) LoggerWrapper::getInstance().logInfo(message, __FUNCTION__, __LINE__)
#define LOG_DEBUG(message) LoggerWrapper::getInstance().logDebug(message, __FUNCTION__, __LINE__)
#define LOG_WARN(message) LoggerWrapper::getInstance().logWarn(message, __FUNCTION__, __LINE__)
#define LOG_ERROR(message) LoggerWrapper::getInstance().logError(message, __FUNCTION__, __LINE__)

#endif // LOG4CPLUS_H
