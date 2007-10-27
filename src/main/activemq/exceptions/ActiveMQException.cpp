/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <stdio.h>
#include "ActiveMQException.h"
#include <activemq/logger/LoggerDefines.h>

using namespace activemq;
using namespace activemq::exceptions;
using namespace std;

// For supporting older versions of msvc (<=2003)
#if defined(_MSC_VER) && (_MSC_VER < 1400)
    #define vsnprintf _vsnprintf
#endif

////////////////////////////////////////////////////////////////////////////////
ActiveMQException::ActiveMQException() throw(){
}

////////////////////////////////////////////////////////////////////////////////
ActiveMQException::ActiveMQException( const ActiveMQException& ex ) throw()
: cms::CMSException()
{
    *this = ex;
}

////////////////////////////////////////////////////////////////////////////////
ActiveMQException::ActiveMQException( const char* file, const int lineNumber, 
                   const char* msg, ... ) throw()
{
    va_list vargs;
    va_start( vargs, msg ) ;
    buildMessage( msg, vargs );
    
    // Set the first mark for this exception.
    setMark( file, lineNumber );
}

////////////////////////////////////////////////////////////////////////////////
ActiveMQException::~ActiveMQException() throw(){
}

////////////////////////////////////////////////////////////////////////////////
void ActiveMQException::setMessage( const char* msg, ... ){
    va_list vargs;
    va_start(vargs, msg);
    buildMessage(msg, vargs);
}

////////////////////////////////////////////////////////////////////////////////
void ActiveMQException::buildMessage(const char* format, va_list& vargs)
{
    // Allocate buffer with a guess of it's size
    int size = 256;
    
    // Format string
    while( true ){
    	
    	// Allocate a buffer of the specified size.
    	char* buffer = new char[size];
    	
        int written = vsnprintf(buffer, size, format, vargs);
        if (written > -1 && written < size-1) {
            
            // Guessed size was enough. Assign the string.
            message.assign (buffer, written);
            
            // assign isn't passing ownership, just copying, delete
            // the allocated buffer.
            delete [] buffer;
            
            break;
        }
                
        // Our buffer wasn't big enough - destroy the old buffer,
        // double the size and try again.
        delete [] buffer;
        size *= 2;
    }
    
    //activemq::logger::SimpleLogger logger("com.yadda1");
    //logger.log( message );   
}

////////////////////////////////////////////////////////////////////////////////
void ActiveMQException::setMark( const char* file, const int lineNumber ){
    
    // Add this mark to the end of the stack trace.
    stackTrace.push_back( std::make_pair( (std::string)file, (int)lineNumber ) );
    
    ostringstream stream;
    stream << "\tFILE: " << stackTrace[stackTrace.size()-1].first;
    stream << ", LINE: " << stackTrace[stackTrace.size()-1].second;
                 
    //activemq::logger::SimpleLogger logger("com.yadda2");
    //logger.log( stream.str() );    
}

////////////////////////////////////////////////////////////////////////////////
ActiveMQException* ActiveMQException::clone() const{
    return new ActiveMQException( *this );
}

////////////////////////////////////////////////////////////////////////////////
std::vector< std::pair< std::string, int> > ActiveMQException::getStackTrace() const{ 
    return stackTrace; 
}

////////////////////////////////////////////////////////////////////////////////
void ActiveMQException::printStackTrace() const{
    printStackTrace( std::cerr );
}

////////////////////////////////////////////////////////////////////////////////
void ActiveMQException::printStackTrace( std::ostream& stream ) const{
    stream << getStackTraceString();
}

////////////////////////////////////////////////////////////////////////////////
std::string ActiveMQException::getStackTraceString() const{
    
    // Create the output stream.
    std::ostringstream stream;
    
    // Write the message and each stack entry.
    stream << message << std::endl;
    for( unsigned int ix=0; ix<stackTrace.size(); ++ix ){
        stream << "\tFILE: " << stackTrace[ix].first;
        stream << ", LINE: " << stackTrace[ix].second;
        stream << std::endl;                    
    }
    
    // Return the string from the output stream.
    return stream.str();
}

////////////////////////////////////////////////////////////////////////////////
ActiveMQException& ActiveMQException::operator =( const ActiveMQException& ex ){
    this->message = ex.message;
    this->stackTrace = ex.stackTrace;
    return *this;
}

