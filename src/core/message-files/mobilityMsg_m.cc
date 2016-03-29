//
// Generated file, do not edit! Created by nedtool 4.6 from core/message-files/mobilityMsg.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "mobilityMsg_m.h"

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
    cEnum *e = cEnum::find("MobilityType");
    if (!e) enums.getInstance()->add(e = new cEnum("MobilityType"));
    e->insert(MOB_DATA, "MOB_DATA");
    e->insert(MOB_ACK, "MOB_ACK");
    e->insert(MOB_NACK, "MOB_NACK");
    e->insert(MOB_EVENT, "MOB_EVENT");
    e->insert(MOB_PUBLISH, "MOB_PUBLISH");
    e->insert(MOB_UPDATE, "MOB_UPDATE");
    e->insert(MOB_KEEPALIVE, "MOB_KEEPALIVE");
    e->insert(MOB_UNKNOWN, "MOB_UNKNOWN");
);

Register_Class(MobilityPacket);

MobilityPacket::MobilityPacket(const char *name, int kind) : ::cPacket(name,kind)
{
    this->kind_var = 0;
    this->source_var = 0;
    this->destination_var = 0;
    this->seqno_var = 0;
    channelMap_arraysize = 0;
    this->channelMap_var = 0;
}

MobilityPacket::MobilityPacket(const MobilityPacket& other) : ::cPacket(other)
{
    channelMap_arraysize = 0;
    this->channelMap_var = 0;
    copy(other);
}

MobilityPacket::~MobilityPacket()
{
    delete [] channelMap_var;
}

MobilityPacket& MobilityPacket::operator=(const MobilityPacket& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void MobilityPacket::copy(const MobilityPacket& other)
{
    this->kind_var = other.kind_var;
    this->source_var = other.source_var;
    this->destination_var = other.destination_var;
    this->seqno_var = other.seqno_var;
    delete [] this->channelMap_var;
    this->channelMap_var = (other.channelMap_arraysize==0) ? NULL : new int[other.channelMap_arraysize];
    channelMap_arraysize = other.channelMap_arraysize;
    for (unsigned int i=0; i<channelMap_arraysize; i++)
        this->channelMap_var[i] = other.channelMap_var[i];
}

void MobilityPacket::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->kind_var);
    doPacking(b,this->source_var);
    doPacking(b,this->destination_var);
    doPacking(b,this->seqno_var);
    b->pack(channelMap_arraysize);
    doPacking(b,this->channelMap_var,channelMap_arraysize);
}

void MobilityPacket::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->kind_var);
    doUnpacking(b,this->source_var);
    doUnpacking(b,this->destination_var);
    doUnpacking(b,this->seqno_var);
    delete [] this->channelMap_var;
    b->unpack(channelMap_arraysize);
    if (channelMap_arraysize==0) {
        this->channelMap_var = 0;
    } else {
        this->channelMap_var = new int[channelMap_arraysize];
        doUnpacking(b,this->channelMap_var,channelMap_arraysize);
    }
}

int MobilityPacket::getKind() const
{
    return kind_var;
}

void MobilityPacket::setKind(int kind)
{
    this->kind_var = kind;
}

int MobilityPacket::getSource() const
{
    return source_var;
}

void MobilityPacket::setSource(int source)
{
    this->source_var = source;
}

int MobilityPacket::getDestination() const
{
    return destination_var;
}

void MobilityPacket::setDestination(int destination)
{
    this->destination_var = destination;
}

uint64_t MobilityPacket::getSeqno() const
{
    return seqno_var;
}

void MobilityPacket::setSeqno(uint64_t seqno)
{
    this->seqno_var = seqno;
}

void MobilityPacket::setChannelMapArraySize(unsigned int size)
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

unsigned int MobilityPacket::getChannelMapArraySize() const
{
    return channelMap_arraysize;
}

int MobilityPacket::getChannelMap(unsigned int k) const
{
    if (k>=channelMap_arraysize) throw cRuntimeError("Array of size %d indexed by %d", channelMap_arraysize, k);
    return channelMap_var[k];
}

void MobilityPacket::setChannelMap(unsigned int k, int channelMap)
{
    if (k>=channelMap_arraysize) throw cRuntimeError("Array of size %d indexed by %d", channelMap_arraysize, k);
    this->channelMap_var[k] = channelMap;
}

class MobilityPacketDescriptor : public cClassDescriptor
{
  public:
    MobilityPacketDescriptor();
    virtual ~MobilityPacketDescriptor();

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

Register_ClassDescriptor(MobilityPacketDescriptor);

MobilityPacketDescriptor::MobilityPacketDescriptor() : cClassDescriptor("MobilityPacket", "cPacket")
{
}

MobilityPacketDescriptor::~MobilityPacketDescriptor()
{
}

bool MobilityPacketDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<MobilityPacket *>(obj)!=NULL;
}

const char *MobilityPacketDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int MobilityPacketDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount(object) : 5;
}

unsigned int MobilityPacketDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISARRAY | FD_ISEDITABLE,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *MobilityPacketDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "kind",
        "source",
        "destination",
        "seqno",
        "channelMap",
    };
    return (field>=0 && field<5) ? fieldNames[field] : NULL;
}

int MobilityPacketDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='k' && strcmp(fieldName, "kind")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "source")==0) return base+1;
    if (fieldName[0]=='d' && strcmp(fieldName, "destination")==0) return base+2;
    if (fieldName[0]=='s' && strcmp(fieldName, "seqno")==0) return base+3;
    if (fieldName[0]=='c' && strcmp(fieldName, "channelMap")==0) return base+4;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *MobilityPacketDescriptor::getFieldTypeString(void *object, int field) const
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
        "uint64_t",
        "int",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : NULL;
}

const char *MobilityPacketDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "MobilityType";
            return NULL;
        default: return NULL;
    }
}

int MobilityPacketDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    MobilityPacket *pp = (MobilityPacket *)object; (void)pp;
    switch (field) {
        case 4: return pp->getChannelMapArraySize();
        default: return 0;
    }
}

std::string MobilityPacketDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    MobilityPacket *pp = (MobilityPacket *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getKind());
        case 1: return long2string(pp->getSource());
        case 2: return long2string(pp->getDestination());
        case 3: return uint642string(pp->getSeqno());
        case 4: return long2string(pp->getChannelMap(i));
        default: return "";
    }
}

bool MobilityPacketDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    MobilityPacket *pp = (MobilityPacket *)object; (void)pp;
    switch (field) {
        case 0: pp->setKind(string2long(value)); return true;
        case 1: pp->setSource(string2long(value)); return true;
        case 2: pp->setDestination(string2long(value)); return true;
        case 3: pp->setSeqno(string2uint64(value)); return true;
        case 4: pp->setChannelMap(i,string2long(value)); return true;
        default: return false;
    }
}

const char *MobilityPacketDescriptor::getFieldStructName(void *object, int field) const
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

void *MobilityPacketDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    MobilityPacket *pp = (MobilityPacket *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


