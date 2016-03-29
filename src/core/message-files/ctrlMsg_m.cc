//
// Generated file, do not edit! Created by nedtool 4.6 from core/message-files/ctrlMsg.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "ctrlMsg_m.h"

USING_NAMESPACE


// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}




// Template rule for outputting std::vector<T> types
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

EXECUTE_ON_STARTUP(
    cEnum *e = cEnum::find("CtrlType");
    if (!e) enums.getInstance()->add(e = new cEnum("CtrlType"));
    e->insert(AppREQUEST, "AppREQUEST");
    e->insert(AppCONFIRMATION, "AppCONFIRMATION");
    e->insert(SenseFreeCHANNEL, "SenseFreeCHANNEL");
    e->insert(SenseDataCHANNEL, "SenseDataCHANNEL");
    e->insert(SenseProposedCHANNEL, "SenseProposedCHANNEL");
    e->insert(SenseFreeREPLY, "SenseFreeREPLY");
    e->insert(SenseDataREPLY, "SenseDataREPLY");
    e->insert(SenseProposedREPLY, "SenseProposedREPLY");
    e->insert(TxSUCCESS, "TxSUCCESS");
    e->insert(TxFAIL, "TxFAIL");
    e->insert(SensingRESULT, "SensingRESULT");
    e->insert(SenseDrmCHANNEL, "SenseDrmCHANNEL");
    e->insert(SenseDrmREPLY, "SenseDrmREPLY");
    e->insert(SenseChannelMap, "SenseChannelMap");
    e->insert(SenseChannelMapReply, "SenseChannelMapReply");
    e->insert(RendezvousSuccess, "RendezvousSuccess");
    e->insert(RendezvousFail, "RendezvousFail");
    e->insert(AppReqReady, "AppReqReady");
);

Register_Class(ctrlMsg);

ctrlMsg::ctrlMsg(const char *name, int kind) : ::cMessage(name,kind)
{
    this->kind_var = 0;
    this->numberOfPackets_var = 0;
    this->destination_var = 0;
    this->channelID_var = 0;
    this->channelState_var = 0;
    this->SensingChannel_var = 0;
    sensingResult_arraysize = 0;
    this->sensingResult_var = 0;
    channelMap_arraysize = 0;
    this->channelMap_var = 0;
}

ctrlMsg::ctrlMsg(const ctrlMsg& other) : ::cMessage(other)
{
    sensingResult_arraysize = 0;
    this->sensingResult_var = 0;
    channelMap_arraysize = 0;
    this->channelMap_var = 0;
    copy(other);
}

ctrlMsg::~ctrlMsg()
{
    delete [] sensingResult_var;
    delete [] channelMap_var;
}

ctrlMsg& ctrlMsg::operator=(const ctrlMsg& other)
{
    if (this==&other) return *this;
    ::cMessage::operator=(other);
    copy(other);
    return *this;
}

void ctrlMsg::copy(const ctrlMsg& other)
{
    this->kind_var = other.kind_var;
    this->numberOfPackets_var = other.numberOfPackets_var;
    this->destination_var = other.destination_var;
    this->channelID_var = other.channelID_var;
    this->channelState_var = other.channelState_var;
    this->SensingChannel_var = other.SensingChannel_var;
    delete [] this->sensingResult_var;
    this->sensingResult_var = (other.sensingResult_arraysize==0) ? NULL : new int[other.sensingResult_arraysize];
    sensingResult_arraysize = other.sensingResult_arraysize;
    for (unsigned int i=0; i<sensingResult_arraysize; i++)
        this->sensingResult_var[i] = other.sensingResult_var[i];
    delete [] this->channelMap_var;
    this->channelMap_var = (other.channelMap_arraysize==0) ? NULL : new int[other.channelMap_arraysize];
    channelMap_arraysize = other.channelMap_arraysize;
    for (unsigned int i=0; i<channelMap_arraysize; i++)
        this->channelMap_var[i] = other.channelMap_var[i];
}

void ctrlMsg::parsimPack(cCommBuffer *b)
{
    ::cMessage::parsimPack(b);
    doPacking(b,this->kind_var);
    doPacking(b,this->numberOfPackets_var);
    doPacking(b,this->destination_var);
    doPacking(b,this->channelID_var);
    doPacking(b,this->channelState_var);
    doPacking(b,this->SensingChannel_var);
    b->pack(sensingResult_arraysize);
    doPacking(b,this->sensingResult_var,sensingResult_arraysize);
    b->pack(channelMap_arraysize);
    doPacking(b,this->channelMap_var,channelMap_arraysize);
}

void ctrlMsg::parsimUnpack(cCommBuffer *b)
{
    ::cMessage::parsimUnpack(b);
    doUnpacking(b,this->kind_var);
    doUnpacking(b,this->numberOfPackets_var);
    doUnpacking(b,this->destination_var);
    doUnpacking(b,this->channelID_var);
    doUnpacking(b,this->channelState_var);
    doUnpacking(b,this->SensingChannel_var);
    delete [] this->sensingResult_var;
    b->unpack(sensingResult_arraysize);
    if (sensingResult_arraysize==0) {
        this->sensingResult_var = 0;
    } else {
        this->sensingResult_var = new int[sensingResult_arraysize];
        doUnpacking(b,this->sensingResult_var,sensingResult_arraysize);
    }
    delete [] this->channelMap_var;
    b->unpack(channelMap_arraysize);
    if (channelMap_arraysize==0) {
        this->channelMap_var = 0;
    } else {
        this->channelMap_var = new int[channelMap_arraysize];
        doUnpacking(b,this->channelMap_var,channelMap_arraysize);
    }
}

int ctrlMsg::getKind() const
{
    return kind_var;
}

void ctrlMsg::setKind(int kind)
{
    this->kind_var = kind;
}

int ctrlMsg::getNumberOfPackets() const
{
    return numberOfPackets_var;
}

void ctrlMsg::setNumberOfPackets(int numberOfPackets)
{
    this->numberOfPackets_var = numberOfPackets;
}

int ctrlMsg::getDestination() const
{
    return destination_var;
}

void ctrlMsg::setDestination(int destination)
{
    this->destination_var = destination;
}

int ctrlMsg::getChannelID() const
{
    return channelID_var;
}

void ctrlMsg::setChannelID(int channelID)
{
    this->channelID_var = channelID;
}

bool ctrlMsg::getChannelState() const
{
    return channelState_var;
}

void ctrlMsg::setChannelState(bool channelState)
{
    this->channelState_var = channelState;
}

int ctrlMsg::getSensingChannel() const
{
    return SensingChannel_var;
}

void ctrlMsg::setSensingChannel(int SensingChannel)
{
    this->SensingChannel_var = SensingChannel;
}

void ctrlMsg::setSensingResultArraySize(unsigned int size)
{
    int *sensingResult_var2 = (size==0) ? NULL : new int[size];
    unsigned int sz = sensingResult_arraysize < size ? sensingResult_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        sensingResult_var2[i] = this->sensingResult_var[i];
    for (unsigned int i=sz; i<size; i++)
        sensingResult_var2[i] = 0;
    sensingResult_arraysize = size;
    delete [] this->sensingResult_var;
    this->sensingResult_var = sensingResult_var2;
}

unsigned int ctrlMsg::getSensingResultArraySize() const
{
    return sensingResult_arraysize;
}

int ctrlMsg::getSensingResult(unsigned int k) const
{
    if (k>=sensingResult_arraysize) throw cRuntimeError("Array of size %d indexed by %d", sensingResult_arraysize, k);
    return sensingResult_var[k];
}

void ctrlMsg::setSensingResult(unsigned int k, int sensingResult)
{
    if (k>=sensingResult_arraysize) throw cRuntimeError("Array of size %d indexed by %d", sensingResult_arraysize, k);
    this->sensingResult_var[k] = sensingResult;
}

void ctrlMsg::setChannelMapArraySize(unsigned int size)
{
    int *channelMap_var2 = (size==0) ? NULL : new int[size];
    unsigned int sz = channelMap_arraysize < size ? channelMap_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        channelMap_var2[i] = this->channelMap_var[i];
    for (unsigned int i=sz; i<size; i++)
        channelMap_var2[i] = 0;
    channelMap_arraysize = size;
    delete [] this->channelMap_var;
    this->channelMap_var = channelMap_var2;
}

unsigned int ctrlMsg::getChannelMapArraySize() const
{
    return channelMap_arraysize;
}

int ctrlMsg::getChannelMap(unsigned int k) const
{
    if (k>=channelMap_arraysize) throw cRuntimeError("Array of size %d indexed by %d", channelMap_arraysize, k);
    return channelMap_var[k];
}

void ctrlMsg::setChannelMap(unsigned int k, int channelMap)
{
    if (k>=channelMap_arraysize) throw cRuntimeError("Array of size %d indexed by %d", channelMap_arraysize, k);
    this->channelMap_var[k] = channelMap;
}

class ctrlMsgDescriptor : public cClassDescriptor
{
  public:
    ctrlMsgDescriptor();
    virtual ~ctrlMsgDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(ctrlMsgDescriptor);

ctrlMsgDescriptor::ctrlMsgDescriptor() : cClassDescriptor("ctrlMsg", "cMessage")
{
}

ctrlMsgDescriptor::~ctrlMsgDescriptor()
{
}

bool ctrlMsgDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<ctrlMsg *>(obj)!=NULL;
}

const char *ctrlMsgDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int ctrlMsgDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 8+basedesc->getFieldCount(object) : 8;
}

unsigned int ctrlMsgDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
    };
    return (field>=0 && field<8) ? fieldTypeFlags[field] : 0;
}

const char *ctrlMsgDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "kind",
        "numberOfPackets",
        "destination",
        "channelID",
        "channelState",
        "SensingChannel",
        "sensingResult",
        "channelMap",
    };
    return (field>=0 && field<8) ? fieldNames[field] : NULL;
}

int ctrlMsgDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='k' && strcmp(fieldName, "kind")==0) return base+0;
    if (fieldName[0]=='n' && strcmp(fieldName, "numberOfPackets")==0) return base+1;
    if (fieldName[0]=='d' && strcmp(fieldName, "destination")==0) return base+2;
    if (fieldName[0]=='c' && strcmp(fieldName, "channelID")==0) return base+3;
    if (fieldName[0]=='c' && strcmp(fieldName, "channelState")==0) return base+4;
    if (fieldName[0]=='S' && strcmp(fieldName, "SensingChannel")==0) return base+5;
    if (fieldName[0]=='s' && strcmp(fieldName, "sensingResult")==0) return base+6;
    if (fieldName[0]=='c' && strcmp(fieldName, "channelMap")==0) return base+7;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *ctrlMsgDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "int",
        "int",
        "bool",
        "int",
        "int",
        "int",
    };
    return (field>=0 && field<8) ? fieldTypeStrings[field] : NULL;
}

const char *ctrlMsgDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "CtrlType";
            return NULL;
        default: return NULL;
    }
}

int ctrlMsgDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    ctrlMsg *pp = (ctrlMsg *)object; (void)pp;
    switch (field) {
        case 6: return pp->getSensingResultArraySize();
        case 7: return pp->getChannelMapArraySize();
        default: return 0;
    }
}

std::string ctrlMsgDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    ctrlMsg *pp = (ctrlMsg *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getKind());
        case 1: return long2string(pp->getNumberOfPackets());
        case 2: return long2string(pp->getDestination());
        case 3: return long2string(pp->getChannelID());
        case 4: return bool2string(pp->getChannelState());
        case 5: return long2string(pp->getSensingChannel());
        case 6: return long2string(pp->getSensingResult(i));
        case 7: return long2string(pp->getChannelMap(i));
        default: return "";
    }
}

bool ctrlMsgDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    ctrlMsg *pp = (ctrlMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setKind(string2long(value)); return true;
        case 1: pp->setNumberOfPackets(string2long(value)); return true;
        case 2: pp->setDestination(string2long(value)); return true;
        case 3: pp->setChannelID(string2long(value)); return true;
        case 4: pp->setChannelState(string2bool(value)); return true;
        case 5: pp->setSensingChannel(string2long(value)); return true;
        case 6: pp->setSensingResult(i,string2long(value)); return true;
        case 7: pp->setChannelMap(i,string2long(value)); return true;
        default: return false;
    }
}

const char *ctrlMsgDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    };
}

void *ctrlMsgDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    ctrlMsg *pp = (ctrlMsg *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


