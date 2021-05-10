#ifndef LOGGER_H
#define LOGGER_H

#include "simon_consts.h"
#include <Stream.h>

namespace simon
{
    
    #define __DEBUG_LOGGING__
    
    class logger
    {
    private:
        Stream& m_stream;
        
    public:
        logger( Stream& stream )
            : m_stream( stream )
        {
        }
    
        void print( const char* message );
        void print( const long num );
        void print( const uint8_t number );
        void println( const char* message );
        void println( const long num );
        void println( const uint8_t number );
    
    private:
        Stream& stream() { return this->m_stream; }
    
    private:
        logger();
        logger& operator=( const logger& );
        logger( const logger& );
    };
}

#endif 
