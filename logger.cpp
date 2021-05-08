#include "logger.h"

void
logger::print( const char* message )
{
#ifdef __DEBUG_LOGGING__
    this->stream().print( message );
#endif
}

void
logger::println( const char* message )
{
#ifdef __DEBUG_LOGGING__
    this->stream().println( message );
#endif
}

void 
logger::print( const uint8_t number )
{
    this->print( number );
}

void
logger::print( const long number )
{
    this->print( number );
}

void
logger::println( const long number )
{
    this->println( number );
}

void 
logger::println( const uint8_t number )
{

    this->println( number );
}
