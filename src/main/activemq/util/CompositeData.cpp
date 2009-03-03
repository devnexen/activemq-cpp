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

#include "CompositeData.h"

#include <sstream>
#include <activemq/util/URISupport.h>

using namespace std;
using namespace activemq;
using namespace activemq::util;
using namespace decaf;
using namespace decaf::net;

////////////////////////////////////////////////////////////////////////////////
CompositeData::CompositeData() {
}

////////////////////////////////////////////////////////////////////////////////
CompositeData::~CompositeData() {
}

////////////////////////////////////////////////////////////////////////////////
URI CompositeData::toURI() const throw( decaf::net::URISyntaxException ) {

    ostringstream sb;

    if( scheme != "" ) {
        sb << scheme << ":";
    }

    if( host.size() != 0) {
        sb << host;
    } else {
        sb << "(";

        for( std::size_t i = 0; i < components.size(); i++ ) {
            if( i != 0 ) {
                sb << ",";
            }
            sb << components[i].toString();
        }

        sb << ")";
    }

    if( path != "") {
        sb << "/" << path;
    }

    if( !parameters.isEmpty() ) {
        sb << "?" << URISupport::createQueryString( parameters );
    }

    if( fragment != "" ) {
        sb << "#" << fragment;
    }

    return URI( sb.str() );
}
