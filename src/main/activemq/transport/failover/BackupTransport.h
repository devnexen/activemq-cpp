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

#ifndef _ACTIVE_TRANSPORT_FAILOVER_BACKUPTRANSPORT_H_
#define _ACTIVE_TRANSPORT_FAILOVER_BACKUPTRANSPORT_H_

#include <activemq/util/Config.h>

#include <activemq/transport/Transport.h>
#include <activemq/transport/DefaultTransportListener.h>
#include <decaf/net/URI.h>
#include <memory>

namespace activemq {
namespace transport {
namespace failover {

    class FailoverTransport;

    class AMQCPP_API BackupTransport : public DefaultTransportListener {
    private:

        // The parent Failover Transport
        FailoverTransport* failover;

        // The Transport this one is managing.
        Transport* transport;

        // The URI of this Backup
        decaf::net::URI uri;

        // Indicates that the contained transport is not valid any longer.
        bool closed;

    public:

        BackupTransport( FailoverTransport* failover );

        virtual ~BackupTransport();

        /**
         * Gets the URI assigned to this Backup
         * @return the assigned URI
         */
        decaf::net::URI getURI() const {
            return this->uri;
        }

        /**
         * Sets the URI assigned to this Transport.
         */
        void setURI( const decaf::net::URI& uri ) {
            this->uri = uri;
        }

        /**
         * Gets the currently held transport
         * @returns pointer to the held transport or NULL if not set.
         */
        Transport* getTransport() {
            return transport;
        }

        /**
         * Sets the held transport, if not NULL then start to listen for exceptions
         * from the held transport.
         *
         * @param transport
         *        The transport to hold.
         */
        void setTransport( Transport* transport ) {
            this->transport = transport;

            if( this->transport != NULL ) {
                this->transport->setTransportListener( this );
            }
        }

        /**
         * Event handler for an exception from a command transport.
         * @param source The source of the exception
         * @param ex The exception.
         */
        virtual void onTransportException( transport::Transport* source,
                                           const decaf::lang::Exception& ex );

        /**
         * Has the Transport been shutdown and no longer usable.
         *
         * @returns true if the Transport
         */
        bool isClosed() const {
            return this->closed;
        }

    };

}}}

#endif /* _ACTIVE_TRANSPORT_FAILOVER_BACKUPTRANSPORT_H_ */
