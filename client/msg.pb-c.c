/* Generated by the protocol buffer compiler.  DO NOT EDIT! */

/* Do not generate deprecated warnings for self */
#ifndef PROTOBUF_C_NO_DEPRECATED
#define PROTOBUF_C_NO_DEPRECATED
#endif

#include "msg.pb-c.h"
void   index__init
                     (Index         *message)
{
  static Index init_value = INDEX__INIT;
  *message = init_value;
}
size_t index__get_packed_size
                     (const Index *message)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &index__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t index__pack
                     (const Index *message,
                      uint8_t       *out)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &index__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t index__pack_to_buffer
                     (const Index *message,
                      ProtobufCBuffer *buffer)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &index__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Index *
       index__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Index *)
     protobuf_c_message_unpack (&index__descriptor,
                                allocator, len, data);
}
void   index__free_unpacked
                     (Index *message,
                      ProtobufCAllocator *allocator)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &index__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   login__init
                     (Login         *message)
{
  static Login init_value = LOGIN__INIT;
  *message = init_value;
}
size_t login__get_packed_size
                     (const Login *message)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &login__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t login__pack
                     (const Login *message,
                      uint8_t       *out)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &login__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t login__pack_to_buffer
                     (const Login *message,
                      ProtobufCBuffer *buffer)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &login__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Login *
       login__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Login *)
     protobuf_c_message_unpack (&login__descriptor,
                                allocator, len, data);
}
void   login__free_unpacked
                     (Login *message,
                      ProtobufCAllocator *allocator)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &login__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   chat__init
                     (Chat         *message)
{
  static Chat init_value = CHAT__INIT;
  *message = init_value;
}
size_t chat__get_packed_size
                     (const Chat *message)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &chat__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t chat__pack
                     (const Chat *message,
                      uint8_t       *out)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &chat__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t chat__pack_to_buffer
                     (const Chat *message,
                      ProtobufCBuffer *buffer)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &chat__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Chat *
       chat__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Chat *)
     protobuf_c_message_unpack (&chat__descriptor,
                                allocator, len, data);
}
void   chat__free_unpacked
                     (Chat *message,
                      ProtobufCAllocator *allocator)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &chat__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   query__init
                     (Query         *message)
{
  static Query init_value = QUERY__INIT;
  *message = init_value;
}
size_t query__get_packed_size
                     (const Query *message)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &query__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t query__pack
                     (const Query *message,
                      uint8_t       *out)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &query__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t query__pack_to_buffer
                     (const Query *message,
                      ProtobufCBuffer *buffer)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &query__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Query *
       query__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Query *)
     protobuf_c_message_unpack (&query__descriptor,
                                allocator, len, data);
}
void   query__free_unpacked
                     (Query *message,
                      ProtobufCAllocator *allocator)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &query__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   status__init
                     (Status         *message)
{
  static Status init_value = STATUS__INIT;
  *message = init_value;
}
size_t status__get_packed_size
                     (const Status *message)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &status__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t status__pack
                     (const Status *message,
                      uint8_t       *out)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &status__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t status__pack_to_buffer
                     (const Status *message,
                      ProtobufCBuffer *buffer)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &status__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Status *
       status__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Status *)
     protobuf_c_message_unpack (&status__descriptor,
                                allocator, len, data);
}
void   status__free_unpacked
                     (Status *message,
                      ProtobufCAllocator *allocator)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &status__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
static const ProtobufCFieldDescriptor index__field_descriptors[4] =
{
  {
    "choice",
    1,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_ENUM,
    0,   /* quantifier_offset */
    PROTOBUF_C_OFFSETOF(Index, choice),
    &choice_type__descriptor,
    NULL,
    0,            /* packed */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "login_info",
    8,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_MESSAGE,
    0,   /* quantifier_offset */
    PROTOBUF_C_OFFSETOF(Index, login_info),
    &login__descriptor,
    NULL,
    0,            /* packed */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "chat_data",
    9,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_MESSAGE,
    0,   /* quantifier_offset */
    PROTOBUF_C_OFFSETOF(Index, chat_data),
    &chat__descriptor,
    NULL,
    0,            /* packed */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "query_limits",
    10,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_MESSAGE,
    0,   /* quantifier_offset */
    PROTOBUF_C_OFFSETOF(Index, query_limits),
    &query__descriptor,
    NULL,
    0,            /* packed */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned index__field_indices_by_name[] = {
  2,   /* field[2] = chat_data */
  0,   /* field[0] = choice */
  1,   /* field[1] = login_info */
  3,   /* field[3] = query_limits */
};
static const ProtobufCIntRange index__number_ranges[2 + 1] =
{
  { 1, 0 },
  { 8, 1 },
  { 0, 4 }
};
const ProtobufCMessageDescriptor index__descriptor =
{
  PROTOBUF_C_MESSAGE_DESCRIPTOR_MAGIC,
  "index",
  "Index",
  "Index",
  "",
  sizeof(Index),
  4,
  index__field_descriptors,
  index__field_indices_by_name,
  2,  index__number_ranges,
  (ProtobufCMessageInit) index__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor login__field_descriptors[1] =
{
  {
    "username",
    2,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    PROTOBUF_C_OFFSETOF(Login, username),
    NULL,
    NULL,
    0,            /* packed */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned login__field_indices_by_name[] = {
  0,   /* field[0] = username */
};
static const ProtobufCIntRange login__number_ranges[1 + 1] =
{
  { 2, 0 },
  { 0, 1 }
};
const ProtobufCMessageDescriptor login__descriptor =
{
  PROTOBUF_C_MESSAGE_DESCRIPTOR_MAGIC,
  "login",
  "Login",
  "Login",
  "",
  sizeof(Login),
  1,
  login__field_descriptors,
  login__field_indices_by_name,
  1,  login__number_ranges,
  (ProtobufCMessageInit) login__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor chat__field_descriptors[2] =
{
  {
    "text",
    3,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    PROTOBUF_C_OFFSETOF(Chat, text),
    NULL,
    NULL,
    0,            /* packed */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "id",
    14,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_INT32,
    PROTOBUF_C_OFFSETOF(Chat, has_id),
    PROTOBUF_C_OFFSETOF(Chat, id),
    NULL,
    NULL,
    0,            /* packed */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned chat__field_indices_by_name[] = {
  1,   /* field[1] = id */
  0,   /* field[0] = text */
};
static const ProtobufCIntRange chat__number_ranges[2 + 1] =
{
  { 3, 0 },
  { 14, 1 },
  { 0, 2 }
};
const ProtobufCMessageDescriptor chat__descriptor =
{
  PROTOBUF_C_MESSAGE_DESCRIPTOR_MAGIC,
  "chat",
  "Chat",
  "Chat",
  "",
  sizeof(Chat),
  2,
  chat__field_descriptors,
  chat__field_indices_by_name,
  2,  chat__number_ranges,
  (ProtobufCMessageInit) chat__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor query__field_descriptors[3] =
{
  {
    "idmin",
    4,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_INT32,
    PROTOBUF_C_OFFSETOF(Query, has_idmin),
    PROTOBUF_C_OFFSETOF(Query, idmin),
    NULL,
    NULL,
    0,            /* packed */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "idmax",
    5,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_INT32,
    PROTOBUF_C_OFFSETOF(Query, has_idmax),
    PROTOBUF_C_OFFSETOF(Query, idmax),
    NULL,
    NULL,
    0,            /* packed */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "query_data",
    15,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_MESSAGE,
    PROTOBUF_C_OFFSETOF(Query, n_query_data),
    PROTOBUF_C_OFFSETOF(Query, query_data),
    &chat__descriptor,
    NULL,
    0,            /* packed */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned query__field_indices_by_name[] = {
  1,   /* field[1] = idmax */
  0,   /* field[0] = idmin */
  2,   /* field[2] = query_data */
};
static const ProtobufCIntRange query__number_ranges[2 + 1] =
{
  { 4, 0 },
  { 15, 2 },
  { 0, 3 }
};
const ProtobufCMessageDescriptor query__descriptor =
{
  PROTOBUF_C_MESSAGE_DESCRIPTOR_MAGIC,
  "query",
  "Query",
  "Query",
  "",
  sizeof(Query),
  3,
  query__field_descriptors,
  query__field_indices_by_name,
  2,  query__number_ranges,
  (ProtobufCMessageInit) query__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor status__field_descriptors[1] =
{
  {
    "value",
    6,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_INT32,
    0,   /* quantifier_offset */
    PROTOBUF_C_OFFSETOF(Status, value),
    NULL,
    NULL,
    0,            /* packed */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned status__field_indices_by_name[] = {
  0,   /* field[0] = value */
};
static const ProtobufCIntRange status__number_ranges[1 + 1] =
{
  { 6, 0 },
  { 0, 1 }
};
const ProtobufCMessageDescriptor status__descriptor =
{
  PROTOBUF_C_MESSAGE_DESCRIPTOR_MAGIC,
  "status",
  "Status",
  "Status",
  "",
  sizeof(Status),
  1,
  status__field_descriptors,
  status__field_indices_by_name,
  1,  status__number_ranges,
  (ProtobufCMessageInit) status__init,
  NULL,NULL,NULL    /* reserved[123] */
};
const ProtobufCEnumValue choice_type__enum_values_by_number[3] =
{
  { "LOGIN", "CHOICE_TYPE__LOGIN", 11 },
  { "CHAT", "CHOICE_TYPE__CHAT", 12 },
  { "QUERY", "CHOICE_TYPE__QUERY", 13 },
};
static const ProtobufCIntRange choice_type__value_ranges[] = {
{11, 0},{0, 3}
};
const ProtobufCEnumValueIndex choice_type__enum_values_by_name[3] =
{
  { "CHAT", 1 },
  { "LOGIN", 0 },
  { "QUERY", 2 },
};
const ProtobufCEnumDescriptor choice_type__descriptor =
{
  PROTOBUF_C_ENUM_DESCRIPTOR_MAGIC,
  "choice_type",
  "choice_type",
  "ChoiceType",
  "",
  3,
  choice_type__enum_values_by_number,
  3,
  choice_type__enum_values_by_name,
  1,
  choice_type__value_ranges,
  NULL,NULL,NULL,NULL   /* reserved[1234] */
};