/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <activemq/wireformat/openwire/marshal/generated/MessageMarshaller.h>

#include <activemq/commands/Message.h>
#include <activemq/exceptions/ActiveMQException.h>
#include <decaf/lang/Pointer.h>

//
//     NOTE!: This file is autogenerated - do not modify!
//            if you need to make a change, please see the Java Classes in the
//            activemq-core module
//

using namespace std;
using namespace activemq;
using namespace activemq::exceptions;
using namespace activemq::commands;
using namespace activemq::wireformat;
using namespace activemq::wireformat::openwire;
using namespace activemq::wireformat::openwire::marshal;
using namespace activemq::wireformat::openwire::utils;
using namespace activemq::wireformat::openwire::marshal::generated;
using namespace decaf;
using namespace decaf::io;
using namespace decaf::lang;

///////////////////////////////////////////////////////////////////////////////
void MessageMarshaller::tightUnmarshal(OpenWireFormat* wireFormat, DataStructure* dataStructure, DataInputStream* dataIn, BooleanStream* bs) {

    try {

        BaseCommandMarshaller::tightUnmarshal(wireFormat, dataStructure, dataIn, bs);

        Message* info =
            dynamic_cast<Message*>(dataStructure);

        int wireVersion = wireFormat->getVersion();

        info->setProducerId(Pointer<ProducerId>(dynamic_cast<ProducerId* >(
            tightUnmarshalCachedObject(wireFormat, dataIn, bs))));
        info->setDestination(Pointer<ActiveMQDestination>(dynamic_cast<ActiveMQDestination* >(
            tightUnmarshalCachedObject(wireFormat, dataIn, bs))));
        info->setTransactionId(Pointer<TransactionId>(dynamic_cast<TransactionId* >(
            tightUnmarshalCachedObject(wireFormat, dataIn, bs))));
        info->setOriginalDestination(Pointer<ActiveMQDestination>(dynamic_cast<ActiveMQDestination* >(
            tightUnmarshalCachedObject(wireFormat, dataIn, bs))));
        info->setMessageId(Pointer<MessageId>(dynamic_cast<MessageId* >(
            tightUnmarshalNestedObject(wireFormat, dataIn, bs))));
        info->setOriginalTransactionId(Pointer<TransactionId>(dynamic_cast<TransactionId* >(
            tightUnmarshalCachedObject(wireFormat, dataIn, bs))));
        info->setGroupID(tightUnmarshalString(dataIn, bs));
        info->setGroupSequence(dataIn->readInt());
        info->setCorrelationId(tightUnmarshalString(dataIn, bs));
        info->setPersistent(bs->readBoolean());
        info->setExpiration(tightUnmarshalLong(wireFormat, dataIn, bs));
        info->setPriority(dataIn->readByte());
        info->setReplyTo(Pointer<ActiveMQDestination>(dynamic_cast<ActiveMQDestination* >(
            tightUnmarshalNestedObject(wireFormat, dataIn, bs))));
        info->setTimestamp(tightUnmarshalLong(wireFormat, dataIn, bs));
        info->setType(tightUnmarshalString(dataIn, bs));
        info->setContent(tightUnmarshalByteArray(dataIn, bs));
        info->setMarshalledProperties(tightUnmarshalByteArray(dataIn, bs));
        info->setDataStructure(Pointer<DataStructure>(dynamic_cast<DataStructure* >(
            tightUnmarshalNestedObject(wireFormat, dataIn, bs))));
        info->setTargetConsumerId(Pointer<ConsumerId>(dynamic_cast<ConsumerId* >(
            tightUnmarshalCachedObject(wireFormat, dataIn, bs))));
        info->setCompressed(bs->readBoolean());
        info->setRedeliveryCounter(dataIn->readInt());

        if (bs->readBoolean()) {
            short size = dataIn->readShort();
            info->getBrokerPath().reserve(size);
            for (int i = 0; i < size; i++) {
                info->getBrokerPath().push_back(Pointer<BrokerId>(dynamic_cast<BrokerId*>(
                    tightUnmarshalNestedObject(wireFormat, dataIn, bs))));
            }
        } else {
            info->getBrokerPath().clear();
        }
        info->setArrival(tightUnmarshalLong(wireFormat, dataIn, bs));
        info->setUserID(tightUnmarshalString(dataIn, bs));
        info->setRecievedByDFBridge(bs->readBoolean());
        if (wireVersion >= 2) {
            info->setDroppable(bs->readBoolean());
        }
        if (wireVersion >= 3) {

            if (bs->readBoolean()) {
                short size = dataIn->readShort();
                info->getCluster().reserve(size);
                for (int i = 0; i < size; i++) {
                    info->getCluster().push_back(Pointer<BrokerId>(dynamic_cast<BrokerId*>(
                        tightUnmarshalNestedObject(wireFormat, dataIn, bs))));
                }
            } else {
                info->getCluster().clear();
            }
        }
        if (wireVersion >= 3) {
            info->setBrokerInTime(tightUnmarshalLong(wireFormat, dataIn, bs));
        }
        if (wireVersion >= 3) {
            info->setBrokerOutTime(tightUnmarshalLong(wireFormat, dataIn, bs));
        }
        if (wireVersion >= 10) {
            info->setJMSXGroupFirstForConsumer(bs->readBoolean());
        }
    }
    AMQ_CATCH_RETHROW(decaf::io::IOException)
    AMQ_CATCH_EXCEPTION_CONVERT(exceptions::ActiveMQException, decaf::io::IOException)
    AMQ_CATCHALL_THROW(decaf::io::IOException)
}

///////////////////////////////////////////////////////////////////////////////
int MessageMarshaller::tightMarshal1(OpenWireFormat* wireFormat, DataStructure* dataStructure, BooleanStream* bs) {

    try {

        Message* info =
            dynamic_cast<Message*>(dataStructure);

        int rc = BaseCommandMarshaller::tightMarshal1(wireFormat, dataStructure, bs);

        int wireVersion = wireFormat->getVersion();

        rc += tightMarshalCachedObject1(wireFormat, info->getProducerId().get(), bs);
        rc += tightMarshalCachedObject1(wireFormat, info->getDestination().get(), bs);
        rc += tightMarshalCachedObject1(wireFormat, info->getTransactionId().get(), bs);
        rc += tightMarshalCachedObject1(wireFormat, info->getOriginalDestination().get(), bs);
        rc += tightMarshalNestedObject1(wireFormat, info->getMessageId().get(), bs);
        rc += tightMarshalCachedObject1(wireFormat, info->getOriginalTransactionId().get(), bs);
        rc += tightMarshalString1(info->getGroupID(), bs);
        rc += tightMarshalString1(info->getCorrelationId(), bs);
        bs->writeBoolean(info->isPersistent());
        rc += tightMarshalLong1(wireFormat, info->getExpiration(), bs);
        rc += tightMarshalNestedObject1(wireFormat, info->getReplyTo().get(), bs);
        rc += tightMarshalLong1(wireFormat, info->getTimestamp(), bs);
        rc += tightMarshalString1(info->getType(), bs);
        bs->writeBoolean(info->getContent().size() != 0);
        rc += info->getContent().size() == 0 ? 0 : (int)info->getContent().size() + 4;
        bs->writeBoolean(info->getMarshalledProperties().size() != 0);
        rc += info->getMarshalledProperties().size() == 0 ? 0 : (int)info->getMarshalledProperties().size() + 4;
        rc += tightMarshalNestedObject1(wireFormat, info->getDataStructure().get(), bs);
        rc += tightMarshalCachedObject1(wireFormat, info->getTargetConsumerId().get(), bs);
        bs->writeBoolean(info->isCompressed());
        rc += tightMarshalObjectArray1(wireFormat, info->getBrokerPath(), bs);
        rc += tightMarshalLong1(wireFormat, info->getArrival(), bs);
        rc += tightMarshalString1(info->getUserID(), bs);
        bs->writeBoolean(info->isRecievedByDFBridge());
        if (wireVersion >= 2) {
            bs->writeBoolean(info->isDroppable());
        }
        if (wireVersion >= 3) {
            rc += tightMarshalObjectArray1(wireFormat, info->getCluster(), bs);
        }
        if (wireVersion >= 3) {
            rc += tightMarshalLong1(wireFormat, info->getBrokerInTime(), bs);
        }
        if (wireVersion >= 3) {
            rc += tightMarshalLong1(wireFormat, info->getBrokerOutTime(), bs);
        }
        if (wireVersion >= 10) {
            bs->writeBoolean(info->isJMSXGroupFirstForConsumer());
        }

        return rc + 9;
    }
    AMQ_CATCH_RETHROW(decaf::io::IOException)
    AMQ_CATCH_EXCEPTION_CONVERT(exceptions::ActiveMQException, decaf::io::IOException)
    AMQ_CATCHALL_THROW(decaf::io::IOException)
}

///////////////////////////////////////////////////////////////////////////////
void MessageMarshaller::tightMarshal2(OpenWireFormat* wireFormat, DataStructure* dataStructure, DataOutputStream* dataOut, BooleanStream* bs) {

    try {

        BaseCommandMarshaller::tightMarshal2(wireFormat, dataStructure, dataOut, bs );

        Message* info =
            dynamic_cast<Message*>(dataStructure);

        int wireVersion = wireFormat->getVersion();

        tightMarshalCachedObject2(wireFormat, info->getProducerId().get(), dataOut, bs);
        tightMarshalCachedObject2(wireFormat, info->getDestination().get(), dataOut, bs);
        tightMarshalCachedObject2(wireFormat, info->getTransactionId().get(), dataOut, bs);
        tightMarshalCachedObject2(wireFormat, info->getOriginalDestination().get(), dataOut, bs);
        tightMarshalNestedObject2(wireFormat, info->getMessageId().get(), dataOut, bs);
        tightMarshalCachedObject2(wireFormat, info->getOriginalTransactionId().get(), dataOut, bs);
        tightMarshalString2(info->getGroupID(), dataOut, bs);
        dataOut->writeInt(info->getGroupSequence());
        tightMarshalString2(info->getCorrelationId(), dataOut, bs);
        bs->readBoolean();
        tightMarshalLong2(wireFormat, info->getExpiration(), dataOut, bs);
        dataOut->write(info->getPriority());
        tightMarshalNestedObject2(wireFormat, info->getReplyTo().get(), dataOut, bs);
        tightMarshalLong2(wireFormat, info->getTimestamp(), dataOut, bs);
        tightMarshalString2(info->getType(), dataOut, bs);
        if (bs->readBoolean()) {
            dataOut->writeInt((int)info->getContent().size() );
            dataOut->write((const unsigned char*)(&info->getContent()[0]), (int)info->getContent().size(), 0, (int)info->getContent().size());
        }
        if (bs->readBoolean()) {
            dataOut->writeInt((int)info->getMarshalledProperties().size() );
            dataOut->write((const unsigned char*)(&info->getMarshalledProperties()[0]), (int)info->getMarshalledProperties().size(), 0, (int)info->getMarshalledProperties().size());
        }
        tightMarshalNestedObject2(wireFormat, info->getDataStructure().get(), dataOut, bs);
        tightMarshalCachedObject2(wireFormat, info->getTargetConsumerId().get(), dataOut, bs);
        bs->readBoolean();
        dataOut->writeInt(info->getRedeliveryCounter());
        tightMarshalObjectArray2(wireFormat, info->getBrokerPath(), dataOut, bs);
        tightMarshalLong2(wireFormat, info->getArrival(), dataOut, bs);
        tightMarshalString2(info->getUserID(), dataOut, bs);
        bs->readBoolean();
        if (wireVersion >= 2) {
            bs->readBoolean();
        }
        if (wireVersion >= 3) {
            tightMarshalObjectArray2(wireFormat, info->getCluster(), dataOut, bs);
        }
        if (wireVersion >= 3) {
            tightMarshalLong2(wireFormat, info->getBrokerInTime(), dataOut, bs);
        }
        if (wireVersion >= 3) {
            tightMarshalLong2(wireFormat, info->getBrokerOutTime(), dataOut, bs);
        }
        if (wireVersion >= 10) {
            bs->readBoolean();
        }
    }
    AMQ_CATCH_RETHROW(decaf::io::IOException)
    AMQ_CATCH_EXCEPTION_CONVERT( exceptions::ActiveMQException, decaf::io::IOException)
    AMQ_CATCHALL_THROW(decaf::io::IOException)
}

///////////////////////////////////////////////////////////////////////////////
void MessageMarshaller::looseUnmarshal(OpenWireFormat* wireFormat, DataStructure* dataStructure, DataInputStream* dataIn) {

    try {

        BaseCommandMarshaller::looseUnmarshal(wireFormat, dataStructure, dataIn);
        Message* info =
            dynamic_cast<Message*>(dataStructure);

        int wireVersion = wireFormat->getVersion();

        info->setProducerId(Pointer<ProducerId>(dynamic_cast<ProducerId*>(
            looseUnmarshalCachedObject(wireFormat, dataIn))));
        info->setDestination(Pointer<ActiveMQDestination>(dynamic_cast<ActiveMQDestination*>(
            looseUnmarshalCachedObject(wireFormat, dataIn))));
        info->setTransactionId(Pointer<TransactionId>(dynamic_cast<TransactionId*>(
            looseUnmarshalCachedObject(wireFormat, dataIn))));
        info->setOriginalDestination(Pointer<ActiveMQDestination>(dynamic_cast<ActiveMQDestination*>(
            looseUnmarshalCachedObject(wireFormat, dataIn))));
        info->setMessageId(Pointer<MessageId>(dynamic_cast<MessageId*>(
            looseUnmarshalNestedObject(wireFormat, dataIn))));
        info->setOriginalTransactionId(Pointer<TransactionId>(dynamic_cast<TransactionId*>(
            looseUnmarshalCachedObject(wireFormat, dataIn))));
        info->setGroupID(looseUnmarshalString(dataIn));
        info->setGroupSequence(dataIn->readInt());
        info->setCorrelationId(looseUnmarshalString(dataIn));
        info->setPersistent(dataIn->readBoolean());
        info->setExpiration(looseUnmarshalLong(wireFormat, dataIn));
        info->setPriority(dataIn->readByte());
        info->setReplyTo(Pointer<ActiveMQDestination>(dynamic_cast<ActiveMQDestination*>(
            looseUnmarshalNestedObject(wireFormat, dataIn))));
        info->setTimestamp(looseUnmarshalLong(wireFormat, dataIn));
        info->setType(looseUnmarshalString(dataIn));
        info->setContent(looseUnmarshalByteArray(dataIn));
        info->setMarshalledProperties(looseUnmarshalByteArray(dataIn));
        info->setDataStructure(Pointer<DataStructure>(dynamic_cast<DataStructure*>(
            looseUnmarshalNestedObject(wireFormat, dataIn))));
        info->setTargetConsumerId(Pointer<ConsumerId>(dynamic_cast<ConsumerId*>(
            looseUnmarshalCachedObject(wireFormat, dataIn))));
        info->setCompressed(dataIn->readBoolean());
        info->setRedeliveryCounter(dataIn->readInt());

        if (dataIn->readBoolean()) {
            short size = dataIn->readShort();
            info->getBrokerPath().reserve(size);
            for (int i = 0; i < size; i++) {
                info->getBrokerPath().push_back( Pointer<BrokerId>(dynamic_cast<BrokerId*>(
                    looseUnmarshalNestedObject(wireFormat, dataIn))));
            }
        } else {
            info->getBrokerPath().clear();
        }
        info->setArrival(looseUnmarshalLong(wireFormat, dataIn));
        info->setUserID(looseUnmarshalString(dataIn));
        info->setRecievedByDFBridge(dataIn->readBoolean());
        if (wireVersion >= 2) {
            info->setDroppable(dataIn->readBoolean());
        }
        if (wireVersion >= 3) {

            if (dataIn->readBoolean()) {
                short size = dataIn->readShort();
                info->getCluster().reserve(size);
                for (int i = 0; i < size; i++) {
                    info->getCluster().push_back( Pointer<BrokerId>(dynamic_cast<BrokerId*>(
                        looseUnmarshalNestedObject(wireFormat, dataIn))));
                }
            } else {
                info->getCluster().clear();
            }
        }
        if (wireVersion >= 3) {
            info->setBrokerInTime(looseUnmarshalLong(wireFormat, dataIn));
        }
        if (wireVersion >= 3) {
            info->setBrokerOutTime(looseUnmarshalLong(wireFormat, dataIn));
        }
        if (wireVersion >= 10) {
            info->setJMSXGroupFirstForConsumer(dataIn->readBoolean());
        }
    }
    AMQ_CATCH_RETHROW(decaf::io::IOException)
    AMQ_CATCH_EXCEPTION_CONVERT(exceptions::ActiveMQException, decaf::io::IOException)
    AMQ_CATCHALL_THROW(decaf::io::IOException)
}

///////////////////////////////////////////////////////////////////////////////
void MessageMarshaller::looseMarshal(OpenWireFormat* wireFormat, DataStructure* dataStructure, DataOutputStream* dataOut) {

    try {

        Message* info =
            dynamic_cast<Message*>(dataStructure);
        BaseCommandMarshaller::looseMarshal(wireFormat, dataStructure, dataOut);

        int wireVersion = wireFormat->getVersion();

        looseMarshalCachedObject(wireFormat, info->getProducerId().get(), dataOut);
        looseMarshalCachedObject(wireFormat, info->getDestination().get(), dataOut);
        looseMarshalCachedObject(wireFormat, info->getTransactionId().get(), dataOut);
        looseMarshalCachedObject(wireFormat, info->getOriginalDestination().get(), dataOut);
        looseMarshalNestedObject(wireFormat, info->getMessageId().get(), dataOut);
        looseMarshalCachedObject(wireFormat, info->getOriginalTransactionId().get(), dataOut);
        looseMarshalString(info->getGroupID(), dataOut);
        dataOut->writeInt(info->getGroupSequence());
        looseMarshalString(info->getCorrelationId(), dataOut);
        dataOut->writeBoolean(info->isPersistent());
        looseMarshalLong(wireFormat, info->getExpiration(), dataOut);
        dataOut->write(info->getPriority());
        looseMarshalNestedObject(wireFormat, info->getReplyTo().get(), dataOut);
        looseMarshalLong(wireFormat, info->getTimestamp(), dataOut);
        looseMarshalString(info->getType(), dataOut);
        dataOut->write( info->getContent().size() != 0 );
        if( info->getContent().size() != 0 ) {
            dataOut->writeInt( (int)info->getContent().size() );
            dataOut->write((const unsigned char*)(&info->getContent()[0]), (int)info->getContent().size(), 0, (int)info->getContent().size());
        }
        dataOut->write( info->getMarshalledProperties().size() != 0 );
        if( info->getMarshalledProperties().size() != 0 ) {
            dataOut->writeInt( (int)info->getMarshalledProperties().size() );
            dataOut->write((const unsigned char*)(&info->getMarshalledProperties()[0]), (int)info->getMarshalledProperties().size(), 0, (int)info->getMarshalledProperties().size());
        }
        looseMarshalNestedObject(wireFormat, info->getDataStructure().get(), dataOut);
        looseMarshalCachedObject(wireFormat, info->getTargetConsumerId().get(), dataOut);
        dataOut->writeBoolean(info->isCompressed());
        dataOut->writeInt(info->getRedeliveryCounter());
        looseMarshalObjectArray(wireFormat, info->getBrokerPath(), dataOut);
        looseMarshalLong(wireFormat, info->getArrival(), dataOut);
        looseMarshalString(info->getUserID(), dataOut);
        dataOut->writeBoolean(info->isRecievedByDFBridge());
        if (wireVersion >= 2) {
            dataOut->writeBoolean(info->isDroppable());
        }
        if (wireVersion >= 3) {
            looseMarshalObjectArray(wireFormat, info->getCluster(), dataOut);
        }
        if (wireVersion >= 3) {
            looseMarshalLong(wireFormat, info->getBrokerInTime(), dataOut);
        }
        if (wireVersion >= 3) {
            looseMarshalLong(wireFormat, info->getBrokerOutTime(), dataOut);
        }
        if (wireVersion >= 10) {
            dataOut->writeBoolean(info->isJMSXGroupFirstForConsumer());
        }
    }
    AMQ_CATCH_RETHROW(decaf::io::IOException)
    AMQ_CATCH_EXCEPTION_CONVERT(exceptions::ActiveMQException, decaf::io::IOException)
    AMQ_CATCHALL_THROW(decaf::io::IOException)
}

