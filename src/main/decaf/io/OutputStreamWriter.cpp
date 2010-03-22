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

#include "OutputStreamWriter.h"

#include <decaf/io/OutputStream.h>
#include <decaf/lang/exceptions/NullPointerException.h>

using namespace decaf;
using namespace decaf::io;
using namespace decaf::lang;
using namespace decaf::lang::exceptions;

////////////////////////////////////////////////////////////////////////////////
OutputStreamWriter::OutputStreamWriter( OutputStream* stream, bool own ) : own( own ) {

    if( stream == NULL ) {
        throw NullPointerException(
            __FILE__, __LINE__, "OutputStream pointer cannot be NULL" );
    }

    this->stream = stream;
    this->closed = false;
}

////////////////////////////////////////////////////////////////////////////////
OutputStreamWriter::~OutputStreamWriter() {

    try{

        this->close();

        if( this->own ) {
            delete this->stream;
        }

        this->stream = NULL;
    }
    DECAF_CATCH_NOTHROW( Exception )
    DECAF_CATCHALL_NOTHROW()
}

////////////////////////////////////////////////////////////////////////////////
void OutputStreamWriter::close() throw( decaf::io::IOException ) {

    try{

        if( !closed ) {
            this->stream->close();
            this->closed = true;
        }
    }
    DECAF_CATCH_RETHROW( IOException )
    DECAF_CATCHALL_THROW( IOException )
}

////////////////////////////////////////////////////////////////////////////////
void OutputStreamWriter::flush() throw( decaf::io::IOException ) {

    try{
        checkClosed();
        this->stream->flush();
    }
    DECAF_CATCH_RETHROW( IOException )
    DECAF_CATCHALL_THROW( IOException )
}

////////////////////////////////////////////////////////////////////////////////
void OutputStreamWriter::doWriteArrayBounded( const char* buffer, int size, int offset, int length )
    throw( decaf::io::IOException,
           decaf::lang::exceptions::NullPointerException,
           decaf::lang::exceptions::IndexOutOfBoundsException ) {

    try{
        checkClosed();

        if( buffer == NULL ) {
            throw NullPointerException(
                __FILE__, __LINE__, "Given buffer was NULL." );
        }

        this->stream->write( (const unsigned char*)buffer, size, offset, length );
    }
    DECAF_CATCH_RETHROW( IOException )
    DECAF_CATCH_RETHROW( NullPointerException )
    DECAF_CATCHALL_THROW( IOException )
}

////////////////////////////////////////////////////////////////////////////////
void OutputStreamWriter::checkClosed() const throw( decaf::io::IOException ) {
    if( closed ) {
        throw IOException( __FILE__, __LINE__, "This Writer is Closed" );
    }
}