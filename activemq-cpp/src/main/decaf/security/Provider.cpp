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

#include "Provider.h"

#include <decaf/util/StlSet.h>
#include <decaf/lang/Pointer.h>

#include <decaf/security/ProviderService.h>

using namespace decaf;
using namespace decaf::security;
using namespace decaf::util;
using namespace decaf::lang;

////////////////////////////////////////////////////////////////////////////////
namespace decaf {
namespace security {

    class ProviderImpl {
    public:

        StlSet<ProviderService*> services;

        ~ProviderImpl() {
            try {
                Pointer< Iterator<ProviderService*> > iter(services.iterator());
                while (iter->hasNext()) {
                    delete iter->next();
                }
                services.clear();
            }
            DECAF_CATCHALL_NOTHROW()
        }

    };

}}

////////////////////////////////////////////////////////////////////////////////
Provider::Provider(const std::string& name, double version, const std::string& info) :
    name(name), version(version), info(info), impl(new ProviderImpl) {
}

////////////////////////////////////////////////////////////////////////////////
Provider::~Provider() {
    try {
        delete this->impl;
    }
    DECAF_CATCHALL_NOTHROW()
}

////////////////////////////////////////////////////////////////////////////////
const Set<ProviderService*>& Provider::getServices() const {
    return this->impl->services;
}

////////////////////////////////////////////////////////////////////////////////
void Provider::addService(ProviderService* service) {
    if (service != NULL) {
        this->impl->services.add(service);
    }
}
